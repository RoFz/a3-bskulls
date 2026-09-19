/*
 * bskulls_fnc_autoCmOnIncomingMissile
 *
 * IncomingMissile EH handler: run the aircraft-specific, bounded
 * countermeasure program for AI-operated aircraft.
 *
 * Repeated warnings extend one worker instead of spawning competing loops.
 * Each worker has activation and elapsed-time caps, validates locality/control
 * before every firing, and exposes an expiry time so a later event can recover
 * from an unexpectedly terminated script.
 *
 * Ref: community.bistudio.com/wiki/Arma_3:_Event_Handlers (IncomingMissile)
 *      community.bistudio.com/wiki/forceWeaponFire
 *      community.bistudio.com/wiki/magazinesAllTurrets
 */

params [
    ["_target", objNull, [objNull]],
    ["_ammo", "", [""]],
    ["_firer", objNull, [objNull]],
    ["_instigator", objNull, [objNull]],
    ["_missile", objNull, [objNull]]
];

if (isNull _target || {!local _target} || {!alive _target}) exitWith {};
if !(_target getVariable ["BS_autoCMInit", false]) exitWith {};

private _launcher = _target getVariable ["BS_autoCM_launcher", ""];
private _mode = _target getVariable ["BS_autoCM_mode", ""];
if (_launcher isEqualTo "" || {_mode isEqualTo ""}) exitWith {};
if !(_target hasWeapon _launcher) exitWith {};

private _driver = driver _target;
if (isNull _driver || {!alive _driver}) exitWith {};
// Manned aircraft: player pilot keeps manual [C]. UAV terminal/driver stays auto-CM.
if (isPlayer _driver && {!unitIsUAV _target}) exitWith {};

// magazinesAllTurrets: [className, turretPath, ammoCount, id, creator]
private _countermeasureRounds = 0;
{
    if ((toLower (_x select 0)) find "cmflare" >= 0) then {
        _countermeasureRounds = _countermeasureRounds + ((_x select 2) max 0);
    };
} forEach (magazinesAllTurrets _target);
if (_countermeasureRounds <= 0) exitWith {};

private _now = time;
_target setVariable ["BS_autoCM_lastWarningAt", _now, false];
_target setVariable [
    "BS_autoCM_lastThreat",
    [
        _now,
        _ammo,
        if (isNull _firer) then { "" } else { typeOf _firer },
        if (isNull _instigator) then { "" } else { typeOf _instigator },
        if (isNull _missile) then { "" } else { typeOf _missile }
    ],
    false
];

private _activeToken = _target getVariable ["BS_autoCM_workerToken", 0];
private _activeExpiresAt = _target getVariable ["BS_autoCM_workerExpiresAt", -1];
private _activeHandle = _target getVariable ["BS_autoCM_workerHandle", scriptNull];
private _workerRunning = (
    _activeHandle isNotEqualTo scriptNull
    && {!scriptDone _activeHandle}
);
if (_activeToken > 0 && {_workerRunning} && {_now <= _activeExpiresAt}) exitWith {
    // The live worker reads lastWarningAt and extends its quiet tail.
};

if (_activeToken > 0) then {
    // Self-heal stale state left by any unexpected worker termination.
    _target setVariable ["BS_autoCM_workerToken", 0, false];
    _target setVariable ["BS_autoCM_workerHandle", scriptNull, false];
    _target setVariable ["BS_autoCM_workerExpiresAt", -1, false];
};

private _cooldownUntil = _target getVariable ["BS_autoCM_cooldownUntil", -1];
if (_now < _cooldownUntil) exitWith {};

private _profile = [_target] call bskulls_fnc_autoCmProfile;
_profile params [
    ["_profileName", "fallback", [""]],
    ["_interval", 0.5, [0]],
    ["_minimumActivations", 5, [0]],
    ["_maximumActivations", 9, [0]],
    ["_quietTail", 3, [0]],
    ["_hardDuration", 7, [0]],
    ["_cooldown", 0.75, [0]]
];

// Clamp every profile value before it enters a scheduled loop. This prevents
// a bad future override from creating a zero-delay loop or an unbounded worker.
_interval = _interval max 0.1;
_minimumActivations = (round _minimumActivations) max 1;
_maximumActivations = (round _maximumActivations) max _minimumActivations;
_quietTail = _quietTail max 0;
_hardDuration = _hardDuration max _interval;
_cooldown = _cooldown max 0;

private _launcherConfig = configFile >> "CfgWeapons" >> _launcher;
private _modeConfig = if (_mode isEqualTo _launcher) then {
    _launcherConfig
} else {
    _launcherConfig >> _mode
};
private _reloadTime = getNumber (_modeConfig >> "reloadTime");
_interval = _interval max (_reloadTime + 0.05);

private _token = (_target getVariable ["BS_autoCM_tokenSerial", 0]) + 1;
private _hardDeadline = _now + _hardDuration;
// Add one interval of grace so the handler can distinguish a scheduled worker
// from stale state while its final sleep/cleanup is pending.
private _workerExpiresAt = _hardDeadline + _interval + 0.5;

_target setVariable ["BS_autoCM_tokenSerial", _token, false];
_target setVariable ["BS_autoCM_workerToken", _token, false];
_target setVariable ["BS_autoCM_workerExpiresAt", _workerExpiresAt, false];

private _handle = [
    _target,
    _launcher,
    _mode,
    _profileName,
    _interval,
    _minimumActivations,
    _maximumActivations,
    _quietTail,
    _hardDeadline,
    _cooldown,
    _token,
    _countermeasureRounds,
    _ammo
] spawn {
    params [
        "_vehicle",
        "_launcher",
        "_mode",
        "_profileName",
        "_interval",
        "_minimumActivations",
        "_maximumActivations",
        "_quietTail",
        "_hardDeadline",
        "_cooldown",
        "_token",
        "_startingRounds",
        "_threatAmmo"
    ];

    private _startedAt = time;
    private _activations = 0;
    private _stopReason = "complete";
    private _debug = missionNamespace getVariable ["BS_autoCMDebug", false];

    if (_debug) then {
        diag_log format [
            "[BSKULLS][AUTO-CM] start vehicle=%1 type=%2 profile=%3 launcher=%4 mode=%5 threat=%6 rounds=%7 token=%8",
            _vehicle,
            typeOf _vehicle,
            _profileName,
            _launcher,
            _mode,
            _threatAmmo,
            _startingRounds,
            _token
        ];
    };

    while {true} do {
        if (isNull _vehicle) exitWith { _stopReason = "deleted"; };
        if (!alive _vehicle) exitWith { _stopReason = "destroyed"; };
        if (!local _vehicle) exitWith { _stopReason = "locality-lost"; };
        if ((_vehicle getVariable ["BS_autoCM_workerToken", 0]) isNotEqualTo _token) exitWith {
            _stopReason = "superseded";
        };
        if !(_vehicle hasWeapon _launcher) exitWith { _stopReason = "launcher-removed"; };

        private _operator = driver _vehicle;
        if (isNull _operator || {!alive _operator}) exitWith { _stopReason = "no-driver"; };
        if (isPlayer _operator && {!unitIsUAV _vehicle}) exitWith {
            _stopReason = "player-took-control";
        };

        private _remainingRounds = 0;
        {
            if ((toLower (_x select 0)) find "cmflare" >= 0) then {
                _remainingRounds = _remainingRounds + ((_x select 2) max 0);
            };
        } forEach (magazinesAllTurrets _vehicle);
        if (_remainingRounds <= 0) exitWith { _stopReason = "ammunition-depleted"; };

        private _now = time;
        if (_now >= _hardDeadline) exitWith { _stopReason = "duration-cap"; };
        if (_activations >= _maximumActivations) exitWith {
            _stopReason = "activation-cap";
        };

        private _lastWarningAt = _vehicle getVariable ["BS_autoCM_lastWarningAt", _startedAt];
        if (
            _activations >= _minimumActivations
            && {_now >= (_lastWarningAt + _quietTail)}
        ) exitWith {
            _stopReason = "threat-quiet";
        };

        // forceWeaponFire is local and does not replace the DAO/DRO-selected
        // attack weapon. The driver is the operator of the launcher found on
        // turret path [-1] during initialization.
        _operator forceWeaponFire [_launcher, _mode];
        _activations = _activations + 1;
        sleep _interval;
    };

    if (!isNull _vehicle) then {
        private _endingRounds = 0;
        {
            if ((toLower (_x select 0)) find "cmflare" >= 0) then {
                _endingRounds = _endingRounds + ((_x select 2) max 0);
            };
        } forEach (magazinesAllTurrets _vehicle);

        _vehicle setVariable [
            "BS_autoCM_lastResult",
            [
                _profileName,
                _startedAt,
                time,
                _activations,
                _stopReason,
                _startingRounds,
                _endingRounds,
                _threatAmmo
            ],
            false
        ];

        if ((_vehicle getVariable ["BS_autoCM_workerToken", 0]) isEqualTo _token) then {
            _vehicle setVariable ["BS_autoCM_workerToken", 0, false];
            _vehicle setVariable ["BS_autoCM_workerHandle", scriptNull, false];
            _vehicle setVariable ["BS_autoCM_workerExpiresAt", -1, false];
            _vehicle setVariable ["BS_autoCM_cooldownUntil", time + _cooldown, false];
        };

        if (_debug) then {
            diag_log format [
                "[BSKULLS][AUTO-CM] stop vehicle=%1 type=%2 profile=%3 activations=%4 reason=%5 rounds=%6->%7 token=%8",
                _vehicle,
                typeOf _vehicle,
                _profileName,
                _activations,
                _stopReason,
                _startingRounds,
                _endingRounds,
                _token
            ];
        };
    };
};

if ((_target getVariable ["BS_autoCM_workerToken", 0]) isEqualTo _token) then {
    _target setVariable ["BS_autoCM_workerHandle", _handle, false];
};
