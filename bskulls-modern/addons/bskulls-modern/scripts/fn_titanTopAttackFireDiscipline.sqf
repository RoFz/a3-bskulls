/*
 * Prevent an AI operator from launching another Archangel while its previous
 * carrier is still in flight. setWeaponReloadingTime is local and applies to
 * the named launcher muzzle only; unlike disableAI "FIREWEAPON", it does not
 * suppress the operator's rifle or modify group combat mode.
 *
 * The terminal penetrator replaces the carrier at separation and exists for
 * at most one second. Retaining the hold briefly after the carrier disappears
 * covers that hand-off without coupling gameplay to optional diagnostics.
 *
 * https://community.bohemia.net/wiki/setWeaponReloadingTime
 * https://community.bohemia.net/wiki/weaponState
 * https://community.bohemia.net/wiki/disableAI
 * https://github.com/CBATeam/CBA_A3/blob/master/addons/common/init_perFrameHandler.sqf
 */

params [
    ["_unit", objNull, [objNull]],
    ["_weapon", "", [""]],
    ["_muzzle", "", [""]],
    ["_projectile", objNull, [objNull]],
    ["_target", objNull, [objNull]]
];

private _launcher = "B_PTbskull_Wea_law_02_titantop";
if (
    isNull _unit
    || {isNull _projectile}
    || {_weapon isNotEqualTo _launcher}
    || {!local _unit}
    || {isPlayer _unit}
    || {!alive _unit}
) exitWith {false};

// A phase of one means round reload just started; zero means ready. It is
// continuously renewed only while the shot is active and is cleared as soon as
// the target or flight resolves.
private _holdPhase = 1;
private _terminalGrace = 1.25;
private _reloadMuzzle = [_weapon, _muzzle] select (_muzzle isNotEqualTo "");
private _carrierTimeToLive = getNumber (configOf _projectile >> "timeToLive");
private _timeout = (_carrierTimeToLive max 40) + 2;
private _startedAt = time;
private _hadTarget = !isNull _target;
private _generation = 1 + ([
    _unit,
    "discipline-generation",
    0
] call bskulls_fnc_titanTopAttackRuntimeGet);
private _traceId = [
    _projectile,
    "trace-id",
    "untracked"
] call bskulls_fnc_titanTopAttackRuntimeGet;
private _reloadBefore = (_unit weaponState _reloadMuzzle) param [5, -1];

[
    _unit,
    "discipline-generation",
    _generation
] call bskulls_fnc_titanTopAttackRuntimeSet;
[
    _unit,
    "discipline-state",
    [_generation, _startedAt, _projectile, _target, _weapon, _reloadMuzzle]
] call bskulls_fnc_titanTopAttackRuntimeSet;
private _initialHoldApplied = _unit setWeaponReloadingTime [
    _unit,
    _reloadMuzzle,
    _holdPhase
];

if (localNamespace getVariable ["bskulls_titanTopAttackDebug", false]) then {
    [
        _projectile,
        "FIRE_DISCIPLINE_HOLD",
        [
            ["unit", str _unit],
            ["weapon", _weapon],
            ["muzzle", _reloadMuzzle],
            ["generation", _generation],
            ["target", str _target],
            ["targetClass", if (isNull _target) then {""} else {typeOf _target}],
            ["reloadBefore", _reloadBefore],
            ["reloadHeldAt", (
                _unit weaponState _reloadMuzzle
            ) param [5, -1]],
            ["initialHoldApplied", _initialHoldApplied],
            ["holdPhase", _holdPhase],
            ["terminalGrace", _terminalGrace],
            ["timeout", _timeout]
        ],
        _traceId
    ] call bskulls_fnc_titanTopAttackLog;
};

private _handle = [{
    params ["_arguments", "_handle"];
    _arguments params [
        "_unit",
        "_weapon",
        "_reloadMuzzle",
        "_projectile",
        "_target",
        "_hadTarget",
        "_generation",
        "_traceId",
        "_startedAt",
        "_holdPhase",
        "_terminalGrace",
        "_timeout"
    ];

    private _state = [
        _unit,
        "discipline-monitor-state",
        [-1, 0]
    ] call bskulls_fnc_titanTopAttackRuntimeGet;
    private _carrierGoneAt = _state param [0, -1];
    private _refreshFailures = _state param [1, 0];
    private _reason = "timeout";
    private _finished = false;

    private _currentGeneration = [
        _unit,
        "discipline-generation",
        -1
    ] call bskulls_fnc_titanTopAttackRuntimeGet;
    if (_currentGeneration < 0 && {!isNull _unit}) then {
        // Reconstruct local-only runtime state when resuming a saved flight.
        [
            _unit,
            "discipline-generation",
            _generation
        ] call bskulls_fnc_titanTopAttackRuntimeSet;
        [
            _unit,
            "discipline-state",
            [_generation, _startedAt, _projectile, _target, _weapon, _reloadMuzzle]
        ] call bskulls_fnc_titanTopAttackRuntimeSet;
        _currentGeneration = _generation;
    };
    if (!isNull _unit) then {
        private _registeredHandle = [
            _unit,
            "discipline-pfh",
            -1
        ] call bskulls_fnc_titanTopAttackRuntimeGet;
        if (_registeredHandle < 0) then {
            [
                _unit,
                "discipline-pfh",
                _handle
            ] call bskulls_fnc_titanTopAttackRuntimeSet;
        };
    };

    if (isNull _unit || {!alive _unit}) then {
        _reason = "unit-unavailable";
        _finished = true;
    } else {
        if (!local _unit) then {
            _reason = "locality-lost";
            _finished = true;
        } else {
            if (_currentGeneration isNotEqualTo _generation) then {
                _reason = "superseded";
                _finished = true;
            } else {
                if (_hadTarget && {isNull _target || {!alive _target}}) then {
                    _reason = "target-resolved";
                    _finished = true;
                } else {
                    if (isNull _projectile) then {
                        if (_carrierGoneAt < 0) then {
                            _carrierGoneAt = time;
                        };
                        if (time - _carrierGoneAt >= _terminalGrace) then {
                            _reason = "flight-resolved";
                            _finished = true;
                        };
                    } else {
                        _carrierGoneAt = -1;
                    };

                    if (!_finished && {time - _startedAt >= _timeout}) then {
                        _reason = "timeout";
                        _finished = true;
                    };
                };
            };
        };
    };

    if (!_finished) exitWith {
        private _refreshApplied = _unit setWeaponReloadingTime [
            _unit,
            _reloadMuzzle,
            _holdPhase
        ];
        if (!_refreshApplied) then {
            _refreshFailures = _refreshFailures + 1;
        };
        [
            _unit,
            "discipline-monitor-state",
            [_carrierGoneAt, _refreshFailures]
        ] call bskulls_fnc_titanTopAttackRuntimeSet;
    };

    [_handle] call CBA_fnc_removePerFrameHandler;
    private _ownsState = !isNull _unit
        && {local _unit}
        && {_currentGeneration isEqualTo _generation};
    private _reloadBeforeRelease = if (_ownsState) then {
        (_unit weaponState _reloadMuzzle) param [5, -1]
    } else {
        -1
    };

    private _releaseApplied = false;
    if (_ownsState) then {
        _releaseApplied = _unit setWeaponReloadingTime [
            _unit,
            _reloadMuzzle,
            0
        ];
        [_unit, "discipline-state", []] call bskulls_fnc_titanTopAttackRuntimeSet;
        [
            _unit,
            "discipline-monitor-state",
            []
        ] call bskulls_fnc_titanTopAttackRuntimeSet;
    };
    private _registeredHandle = [
        _unit,
        "discipline-pfh",
        -1
    ] call bskulls_fnc_titanTopAttackRuntimeGet;
    if (_registeredHandle isEqualTo _handle) then {
        [_unit, "discipline-pfh", -1] call bskulls_fnc_titanTopAttackRuntimeSet;
    };

    if (localNamespace getVariable ["bskulls_titanTopAttackDebug", false]) then {
        [
            objNull,
            "FIRE_DISCIPLINE_RELEASE",
            [
                ["unit", str _unit],
                ["weapon", _weapon],
                ["muzzle", _reloadMuzzle],
                ["generation", _generation],
                ["reason", _reason],
                ["elapsed", time - _startedAt],
                ["target", str _target],
                ["targetAlive", !isNull _target && {alive _target}],
                ["carrierAlive", !isNull _projectile],
                ["ownedState", _ownsState],
                ["refreshFailures", _refreshFailures],
                ["releaseApplied", _releaseApplied],
                ["reloadBeforeRelease", _reloadBeforeRelease],
                ["reloadAfterRelease", if (_ownsState) then {
                    (_unit weaponState _reloadMuzzle) param [5, -1]
                } else {-1}]
            ],
            _traceId
        ] call bskulls_fnc_titanTopAttackLog;
    };
}, 0.05, [
    _unit,
    _weapon,
    _reloadMuzzle,
    _projectile,
    _target,
    _hadTarget,
    _generation,
    _traceId,
    _startedAt,
    _holdPhase,
    _terminalGrace,
    _timeout
]] call CBA_fnc_addPerFrameHandler;

[_unit, "discipline-pfh", _handle] call bskulls_fnc_titanTopAttackRuntimeSet;

true
