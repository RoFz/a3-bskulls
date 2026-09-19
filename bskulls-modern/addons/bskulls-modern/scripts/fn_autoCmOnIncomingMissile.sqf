/*
 * bskulls_fnc_autoCmOnIncomingMissile
 *
 * Register a missile with the aircraft's single bounded countermeasure worker.
 * The worker fires one prompt response against a compatible guided threat,
 * observes the live lock, and varies later attempts by recomputed relative
 * motion. It never issues flight-control commands.
 *
 * Threat entry layout:
 * [missile, ammo, first warning, last warning, previous range,
 *  last approaching time, firer type, instigator type, weaponLockSystem,
 *  cmImmunity, initial response attempted, serial, had projectile,
 *  non-threatening since]
 *
 * Ref: community.bistudio.com/wiki/Arma_3:_Event_Handlers (IncomingMissile)
 *      community.bistudio.com/wiki/Arma_3:_Countermeasures
 *      community.bistudio.com/wiki/A3_Targeting_config_reference
 *      community.bistudio.com/wiki/forceWeaponFire
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

private _inventory = [_target] call bskulls_fnc_autoCmInventory;
private _countermeasureRounds = _inventory select 0;
if (_countermeasureRounds <= 0) exitWith {};

private _now = time;
private _ammoConfig = configFile >> "CfgAmmo" >> _ammo;
private _lockSystemEntry = _ammoConfig >> "weaponLockSystem";
private _immunityEntry = _ammoConfig >> "cmImmunity";
private _lockSystem = [_lockSystemEntry] call bskulls_fnc_autoCmReadLockSystem;
private _cmImmunity = if (isNumber _immunityEntry) then {
    getNumber _immunityEntry
} else {
    -1
};

private _threats = _target getVariable ["BS_autoCM_threats", []];
private _hadProjectile = !isNull _missile;
private _existingIndex = if (_hadProjectile) then {
    _threats findIf {
        (_x param [12, false, [false]])
        && {(_x param [0, objNull, [objNull]]) isEqualTo _missile}
    }
} else {
    _threats findIf {
        !(_x param [12, true, [false]])
        && {(_x param [1, "", [""]]) isEqualTo _ammo}
    }
};

private _serial = -1;
if (_existingIndex >= 0) then {
    private _entry = _threats select _existingIndex;
    _serial = _entry param [11, -1, [0]];
    _entry set [3, _now];
    _entry set [6, if (isNull _firer) then { "" } else { typeOf _firer }];
    _entry set [7, if (isNull _instigator) then { "" } else { typeOf _instigator }];
    _entry set [8, _lockSystem];
    _entry set [9, _cmImmunity];
    _entry set [13, -1];
    _threats set [_existingIndex, _entry];
} else {
    _serial = (_target getVariable ["BS_autoCM_threatSerial", 0]) + 1;
    _target setVariable ["BS_autoCM_threatSerial", _serial, false];
    _threats pushBack [
        _missile,
        _ammo,
        _now,
        _now,
        -1,
        _now,
        if (isNull _firer) then { "" } else { typeOf _firer },
        if (isNull _instigator) then { "" } else { typeOf _instigator },
        _lockSystem,
        _cmImmunity,
        false,
        _serial,
        _hadProjectile,
        -1
    ];
};

_target setVariable ["BS_autoCM_threats", _threats, false];
_target setVariable ["BS_autoCM_lastWarningAt", _now, false];
_target setVariable [
    "BS_autoCM_lastThreat",
    [
        _now,
        _ammo,
        if (isNull _firer) then { "" } else { typeOf _firer },
        if (isNull _instigator) then { "" } else { typeOf _instigator },
        if (isNull _missile) then { "" } else { typeOf _missile },
        _lockSystem,
        _cmImmunity,
        _serial
    ],
    false
];

private _debug = missionNamespace getVariable ["BS_autoCMDebug", false];
if (_debug) then {
    diag_log format [
        "[BSKULLS][AUTO-CM] warning vehicle=%1 type=%2 serial=%3 ammo=%4 projectile=%5 lockSystem=%6 cmImmunity=%7",
        _target,
        typeOf _target,
        _serial,
        _ammo,
        if (isNull _missile) then { "none" } else { typeOf _missile },
        _lockSystem,
        _cmImmunity
    ];
};

private _profile = [_target] call bskulls_fnc_autoCmProfile;
private _requiredWorkerTime = if (_hadProjectile) then {
    private _profileTrackingDuration = (
        (_profile param [9, 45, [0]]) max 10
    ) min 75;
    private _configuredLifetime = getNumber (_ammoConfig >> "timeToLive");
    if (_configuredLifetime > 0) then {
        ((_configuredLifetime + 3) max 10) min _profileTrackingDuration
    } else {
        _profileTrackingDuration
    }
} else {
    private _profileFallbackDuration = (_profile param [5, 7, [0]]) max 0;
    private _profileQuietTail = (_profile param [4, 3, [0]]) max 0;
    (_profileFallbackDuration + _profileQuietTail + 1) min 30
};

private _activeToken = _target getVariable ["BS_autoCM_workerToken", 0];
private _activeExpiresAt = _target getVariable ["BS_autoCM_workerExpiresAt", -1];
private _activeHandle = _target getVariable ["BS_autoCM_workerHandle", scriptNull];
private _workerRunning = (
    _activeHandle isNotEqualTo scriptNull
    && {!scriptDone _activeHandle}
);
private _workerStopping = _target getVariable ["BS_autoCM_workerStopping", false];
private _workerHasTimeForThreat = (
    (_existingIndex >= 0 && {_hadProjectile})
    || {(_activeExpiresAt - _now) >= _requiredWorkerTime}
);
if (
    _activeToken > 0
    && {_workerRunning}
    && {!_workerStopping}
    && {_workerHasTimeForThreat}
    && {_now <= _activeExpiresAt}
) exitWith {
    // The worker reads the shared threat registry on its next sample.
};

if (_activeToken > 0) then {
    // Supersede stale or over-duration state. The old worker observes the token.
    _target setVariable ["BS_autoCM_workerToken", 0, false];
    _target setVariable ["BS_autoCM_workerHandle", scriptNull, false];
    _target setVariable ["BS_autoCM_workerExpiresAt", -1, false];
    _target setVariable ["BS_autoCM_workerStopping", false, false];
};

_profile params [
    ["_profileName", "fallback", [""]],
    ["_terminalInterval", 0.5, [0]],
    ["_fallbackMinimumAttempts", 5, [0]],
    ["_maximumAttemptsPerThreat", 9, [0]],
    ["_quietTail", 3, [0]],
    ["_fallbackDuration", 7, [0]],
    ["_cooldown", 0.75, [0]],
    ["_approachTime", 8, [0]],
    ["_terminalTime", 4, [0]],
    ["_trackingDuration", 45, [0]]
];

// Clamp every profile value before it enters a scheduled loop. This prevents
// future overrides from creating zero-delay or unbounded workers.
_terminalInterval = _terminalInterval max 0.1;
_fallbackMinimumAttempts = (round _fallbackMinimumAttempts) max 1;
_maximumAttemptsPerThreat = (
    (round _maximumAttemptsPerThreat) max _fallbackMinimumAttempts
);
_quietTail = (_quietTail max 0.5) min 10;
_fallbackDuration = (_fallbackDuration max _terminalInterval) min 20;
_cooldown = (_cooldown max 0) min 5;
_terminalTime = (_terminalTime max 1) min 10;
_approachTime = (_approachTime max _terminalTime) min 20;
_trackingDuration = (_trackingDuration max 10) min 75;

private _launcherConfig = configFile >> "CfgWeapons" >> _launcher;
private _modeConfig = if (_mode isEqualTo _launcher) then {
    _launcherConfig
} else {
    _launcherConfig >> _mode
};
private _reloadInterval = (getNumber (_modeConfig >> "reloadTime")) + 0.05;
_reloadInterval = _reloadInterval max 0.1;
_terminalInterval = _terminalInterval max _reloadInterval;

private _workerDuration = (
    (_trackingDuration + 15) max (_fallbackDuration + _quietTail + 2)
) min 90;
private _workerExpiresAt = _now + _workerDuration;
private _token = (_target getVariable ["BS_autoCM_tokenSerial", 0]) + 1;

_target setVariable ["BS_autoCM_tokenSerial", _token, false];
_target setVariable ["BS_autoCM_workerToken", _token, false];
_target setVariable ["BS_autoCM_workerExpiresAt", _workerExpiresAt, false];
_target setVariable ["BS_autoCM_workerStopping", false, false];

private _handle = [
    _target,
    _launcher,
    _mode,
    _profileName,
    _terminalInterval,
    _fallbackMinimumAttempts,
    _maximumAttemptsPerThreat,
    _quietTail,
    _fallbackDuration,
    _cooldown,
    _approachTime,
    _terminalTime,
    _trackingDuration,
    _workerExpiresAt,
    _token,
    _countermeasureRounds,
    _ammo
] spawn {
    params [
        "_vehicle",
        "_launcher",
        "_mode",
        "_profileName",
        "_terminalInterval",
        "_fallbackMinimumAttempts",
        "_maximumAttemptsPerThreat",
        "_quietTail",
        "_fallbackDuration",
        "_cooldown",
        "_approachTime",
        "_terminalTime",
        "_trackingDuration",
        "_hardDeadline",
        "_token",
        "_startingRounds",
        "_initialThreatAmmo"
    ];

    private _sampleInterval = 0.1;
    private _approachInterval = (_terminalInterval * 2) max _terminalInterval;
    private _farInterval = (_terminalInterval * 4) max 1.5;
    private _maximumWorkerAttempts = _maximumAttemptsPerThreat * 3;
    private _startedAt = time;
    private _attempts = 0;
    private _attemptBudget = 0;
    private _fallbackAttempts = 0;
    private _roundsReleased = 0;
    private _lastObservedRounds = _startingRounds;
    private _seenThreatSerials = [];
    private _respondedThreatSerials = [];
    private _stopReason = "complete";
    private _lastThreatAmmo = _initialThreatAmmo;
    private _noThreatSince = -1;
    private _skippedImmune = 0;
    private _skippedIncompatible = 0;
    private _skippedUnguided = 0;
    private _debug = missionNamespace getVariable ["BS_autoCMDebug", false];

    if (_debug) then {
        diag_log format [
            "[BSKULLS][AUTO-CM] start vehicle=%1 type=%2 profile=%3 launcher=%4 mode=%5 rounds=%6 token=%7 deadline=%8",
            _vehicle,
            typeOf _vehicle,
            _profileName,
            _launcher,
            _mode,
            _startingRounds,
            _token,
            _hardDeadline
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

        private _now = time;
        if (_now >= _hardDeadline) exitWith {
            _vehicle setVariable ["BS_autoCM_workerStopping", true, false];
            _stopReason = "duration-cap";
        };

        private _inventory = [_vehicle] call bskulls_fnc_autoCmInventory;
        _inventory params ["_remainingRounds", "_countermeasureSystems", "_systemsKnown"];
        if (_remainingRounds <= 0) exitWith { _stopReason = "ammunition-depleted"; };

        if (_remainingRounds < _lastObservedRounds) then {
            _roundsReleased = _roundsReleased + (_lastObservedRounds - _remainingRounds);
        };
        _lastObservedRounds = _remainingRounds;

        private _snapshotAt = _now;
        private _threats = _vehicle getVariable ["BS_autoCM_threats", []];
        private _keptThreats = [];
        private _responsiveSerials = [];
        private _desiredPriority = -1;
        private _desiredInterval = -1;
        private _desiredStage = "tracking";
        private _desiredAmmo = "";
        private _desiredRange = -1;
        private _desiredClosingSpeed = 0;
        private _desiredTimeToClosestApproach = -1;
        private _desiredClosestApproachDistance = -1;
        private _desiredMissileSpeed = 0;
        private _desiredAircraftSpeed = vectorMagnitude (velocity _vehicle);
        private _desiredEngineState = "";
        private _desiredLockState = "";
        private _desiredFlightState = "";

        {
            private _entry = +_x;
            _entry params [
                ["_threatMissile", objNull, [objNull]],
                ["_threatAmmo", "", [""]],
                ["_firstWarningAt", _now, [0]],
                ["_lastWarningAt", _now, [0]],
                ["_previousRange", -1, [0]],
                ["_lastApproachingAt", _now, [0]],
                ["_firerType", "", [""]],
                ["_instigatorType", "", [""]],
                ["_threatLockSystem", -1, [0]],
                ["_cmImmunity", -1, [0]],
                ["_entryInitialResponded", false, [false]],
                ["_threatSerial", -1, [0]],
                ["_hadProjectile", false, [false]],
                ["_nonThreatSince", -1, [0]]
            ];

            _lastThreatAmmo = _threatAmmo;

            if (!_hadProjectile) then {
                if (_now <= (_lastWarningAt + _fallbackDuration)) then {
                    if !(_threatSerial in _seenThreatSerials) then {
                        _seenThreatSerials pushBack _threatSerial;
                        _attemptBudget = (
                            _attemptBudget + _maximumAttemptsPerThreat
                        ) min _maximumWorkerAttempts;
                    };

                    _keptThreats pushBack _entry;
                    if (
                        _fallbackAttempts < _fallbackMinimumAttempts
                        && {_desiredPriority < 0}
                    ) then {
                        _desiredPriority = 0;
                        _desiredInterval = _terminalInterval;
                        _desiredStage = "fallback";
                        _desiredAmmo = _threatAmmo;
                    };
                };
            } else {
                if (!isNull _threatMissile) then {
                    private _ammoConfig = configFile >> "CfgAmmo" >> _threatAmmo;
                    private _configuredLifetime = getNumber (_ammoConfig >> "timeToLive");
                    private _threatLifetime = _trackingDuration;
                    if (_configuredLifetime > 0) then {
                        _threatLifetime = (
                            (_configuredLifetime + 3) max 10
                        ) min _trackingDuration;
                    };

                    if (_now <= (_firstWarningAt + _threatLifetime)) then {
                        private _metrics = [
                            _vehicle,
                            _threatMissile
                        ] call bskulls_fnc_autoCmThreatMetrics;
                        _metrics params [
                            "_metricsValid",
                            "_range",
                            "_closingSpeed",
                            "_timeToClosestApproach",
                            "_closestApproachDistance",
                            "_missileSpeed",
                            "_aircraftSpeed",
                            "_engineState",
                            "_lockState",
                            "_flightState",
                            "_guidanceTarget"
                        ];

                        if (_metricsValid) then {
                            private _lockStateUpper = toUpper _lockState;
                            private _targetedElsewhere = (
                                !isNull _guidanceTarget
                                && {_guidanceTarget isNotEqualTo _vehicle}
                            );
                            private _lockLost = (
                                _lockStateUpper isEqualTo "LOST"
                                || {_targetedElsewhere}
                            );

                            private _compatible = true;
                            if (_threatLockSystem isEqualTo 0) then {
                                _compatible = false;
                                _skippedUnguided = _skippedUnguided + 1;
                            };
                            if (
                                _compatible
                                && {_threatLockSystem > 0}
                                && {_systemsKnown}
                            ) then {
                                _compatible = false;
                                {
                                    if (([
                                        _threatLockSystem,
                                        _x
                                    ] call BIS_fnc_bitwiseAND) > 0) exitWith {
                                        _compatible = true;
                                    };
                                } forEach _countermeasureSystems;
                                if (!_compatible) then {
                                    _skippedIncompatible = _skippedIncompatible + 1;
                                };
                            };

                            private _immune = _cmImmunity >= 0.999;
                            if (_immune) then {
                                _skippedImmune = _skippedImmune + 1;
                            };

                            if (_compatible && {!_immune}) then {
                                if (
                                    _previousRange < 0
                                    || {_range < (_previousRange - 0.5)}
                                ) then {
                                    _lastApproachingAt = _now;
                                };
                                _entry set [4, _range];
                                _entry set [5, _lastApproachingAt];

                                if (_lockLost) then {
                                    if (_nonThreatSince < 0) then {
                                        _nonThreatSince = _now;
                                    };
                                } else {
                                    _nonThreatSince = -1;
                                };
                                _entry set [13, _nonThreatSince];

                                private _retainThreat = (
                                    _nonThreatSince < 0
                                    || {_now < (_nonThreatSince + 1.5)}
                                );
                                if (_retainThreat) then {
                                    _keptThreats pushBack _entry;

                                    private _explicitLock = _lockStateUpper in [
                                        "LOCKED",
                                        "SEEKING",
                                        "INITIAL",
                                        "MANUAL"
                                    ];
                                    private _approaching = (
                                        _closingSpeed > 1
                                        && {_timeToClosestApproach >= 0}
                                    );
                                    private _credibleGeometry = (
                                        _approaching
                                        && {
                                            _threatLockSystem > 0
                                            || {_threatLockSystem < 0 && {_closestApproachDistance <= 250}}
                                        }
                                    );
                                    private _credibleThreat = (
                                        !_lockLost
                                        && {
                                            _explicitLock
                                            || {_guidanceTarget isEqualTo _vehicle}
                                            || {_credibleGeometry}
                                            || {_now < (_firstWarningAt + 1.5)}
                                        }
                                    );

                                    if (_credibleThreat) then {
                                        private _initialResponded = (
                                            _entryInitialResponded
                                            || {_threatSerial in _respondedThreatSerials}
                                        );
                                        if !(_threatSerial in _seenThreatSerials) then {
                                            _seenThreatSerials pushBack _threatSerial;
                                            _attemptBudget = (
                                                _attemptBudget + _maximumAttemptsPerThreat
                                            ) min _maximumWorkerAttempts;
                                        };
                                        _responsiveSerials pushBackUnique _threatSerial;

                                        private _priority = 1;
                                        private _interval = _farInterval;
                                        private _stage = "far";

                                        if (_approaching) then {
                                            if (_timeToClosestApproach <= 1.5) then {
                                                _priority = 4;
                                                _interval = _terminalInterval;
                                                _stage = "critical";
                                            } else {
                                                if (_timeToClosestApproach <= _terminalTime) then {
                                                    _priority = 3;
                                                    _interval = _terminalInterval;
                                                    _stage = "terminal";
                                                } else {
                                                    if (_timeToClosestApproach <= _approachTime) then {
                                                        _priority = 2;
                                                        _interval = _approachInterval;
                                                        _stage = "approach";
                                                    };
                                                };
                                            };
                                        } else {
                                            private _terminalRange = (
                                                (_missileSpeed max 100) * _terminalTime
                                            );
                                            if (_range <= _terminalRange) then {
                                                _priority = 3;
                                                _interval = _terminalInterval;
                                                _stage = "terminal-range";
                                            };
                                        };

                                        if (!_initialResponded) then {
                                            _priority = 5;
                                            _stage = "initial";
                                        };

                                        if (
                                            _priority > _desiredPriority
                                            || {
                                                _priority isEqualTo _desiredPriority
                                                && {
                                                    _desiredTimeToClosestApproach < 0
                                                    || {
                                                        _timeToClosestApproach >= 0
                                                        && {_timeToClosestApproach < _desiredTimeToClosestApproach}
                                                    }
                                                }
                                            }
                                        ) then {
                                            _desiredPriority = _priority;
                                            _desiredInterval = _interval;
                                            _desiredStage = _stage;
                                            _desiredAmmo = _threatAmmo;
                                            _desiredRange = _range;
                                            _desiredClosingSpeed = _closingSpeed;
                                            _desiredTimeToClosestApproach = _timeToClosestApproach;
                                            _desiredClosestApproachDistance = _closestApproachDistance;
                                            _desiredMissileSpeed = _missileSpeed;
                                            _desiredAircraftSpeed = _aircraftSpeed;
                                            _desiredEngineState = _engineState;
                                            _desiredLockState = _lockStateUpper;
                                            _desiredFlightState = _flightState;
                                        };
                                    };
                                };
                            } else {
                                if (_debug) then {
                                    diag_log format [
                                        "[BSKULLS][AUTO-CM] ignore vehicle=%1 serial=%2 ammo=%3 reason=%4 lockSystem=%5 cmSystems=%6 cmImmunity=%7",
                                        _vehicle,
                                        _threatSerial,
                                        _threatAmmo,
                                        if (_immune) then { "immune" } else {
                                            [
                                                "incompatible",
                                                "unguided-or-undetectable"
                                            ] select (_threatLockSystem isEqualTo 0)
                                        },
                                        _threatLockSystem,
                                        _countermeasureSystems,
                                        _cmImmunity
                                    ];
                                };
                            };
                        };
                    };
                };
            };
        } forEach _threats;

        // Preserve a warning appended by an unscheduled EH while this sample
        // was evaluating its snapshot.
        private _latestThreats = _vehicle getVariable ["BS_autoCM_threats", []];
        {
            private _latestSerial = _x param [11, -1, [0]];
            private _latestWarningAt = _x param [3, -1, [0]];
            if (_latestWarningAt > _snapshotAt) then {
                private _keptIndex = _keptThreats findIf {
                    (_x param [11, -2, [0]]) isEqualTo _latestSerial
                };
                if (_keptIndex < 0) then {
                    _keptThreats pushBack _x;
                } else {
                    private _keptEntry = _keptThreats select _keptIndex;
                    _keptEntry set [3, _latestWarningAt];
                    _keptThreats set [_keptIndex, _keptEntry];
                };
            };
        } forEach _latestThreats;
        _vehicle setVariable ["BS_autoCM_threats", _keptThreats, false];

        if (_keptThreats isEqualTo []) then {
            if (_noThreatSince < 0) then {
                _noThreatSince = _now;
            };
        } else {
            _noThreatSince = -1;
        };
        if (
            _noThreatSince >= 0
            && {_now >= (_noThreatSince + _quietTail)}
        ) exitWith {
            _vehicle setVariable ["BS_autoCM_workerStopping", true, false];
            _stopReason = "threat-clear";
        };

        private _nextFireAt = _vehicle getVariable ["BS_autoCM_nextFireAt", -1];
        if (
            _desiredInterval > 0
            && {_now >= _nextFireAt}
            && {_attempts < _attemptBudget}
            && {local _vehicle}
            && {(_vehicle getVariable ["BS_autoCM_workerToken", 0]) isEqualTo _token}
        ) then {
            // forceWeaponFire has no success return. Magazine deltas on later
            // samples record actual rounds released separately from attempts.
            _operator forceWeaponFire [_launcher, _mode];
            _attempts = _attempts + 1;
            if (_desiredStage isEqualTo "fallback") then {
                _fallbackAttempts = _fallbackAttempts + 1;
            };
            _vehicle setVariable [
                "BS_autoCM_nextFireAt",
                _now + _desiredInterval,
                false
            ];

            {
                _respondedThreatSerials pushBackUnique _x;
            } forEach _responsiveSerials;

            _vehicle setVariable [
                "BS_autoCM_lastDecision",
                [
                    _now,
                    _desiredStage,
                    _desiredAmmo,
                    _desiredRange,
                    _desiredClosingSpeed,
                    _desiredTimeToClosestApproach,
                    _desiredClosestApproachDistance,
                    _desiredMissileSpeed,
                    _desiredAircraftSpeed,
                    _desiredEngineState,
                    _desiredLockState,
                    _desiredFlightState,
                    _attempts,
                    _attemptBudget,
                    _remainingRounds
                ],
                false
            ];

            if (_debug) then {
                diag_log format [
                    "[BSKULLS][AUTO-CM] fire vehicle=%1 stage=%2 ammo=%3 range=%4 closing=%5 tCPA=%6 dCPA=%7 missileSpeed=%8 aircraftSpeed=%9 engine=%10 lock=%11 flight=%12 attempts=%13/%14 rounds=%15",
                    _vehicle,
                    _desiredStage,
                    _desiredAmmo,
                    _desiredRange,
                    _desiredClosingSpeed,
                    _desiredTimeToClosestApproach,
                    _desiredClosestApproachDistance,
                    _desiredMissileSpeed,
                    _desiredAircraftSpeed,
                    _desiredEngineState,
                    _desiredLockState,
                    _desiredFlightState,
                    _attempts,
                    _attemptBudget,
                    _remainingRounds
                ];
            };
        };

        sleep _sampleInterval;
    };

    if (!isNull _vehicle) then {
        private _endingInventory = [_vehicle] call bskulls_fnc_autoCmInventory;
        private _endingRounds = _endingInventory select 0;
        if (_endingRounds < _lastObservedRounds) then {
            _roundsReleased = _roundsReleased + (_lastObservedRounds - _endingRounds);
        };

        if ((_vehicle getVariable ["BS_autoCM_workerToken", 0]) isEqualTo _token) then {
            _vehicle setVariable [
                "BS_autoCM_lastResult",
                [
                    _profileName,
                    _startedAt,
                    time,
                    _attempts,
                    _stopReason,
                    _startingRounds,
                    _endingRounds,
                    _lastThreatAmmo,
                    _roundsReleased,
                    count _seenThreatSerials,
                    _skippedImmune,
                    _skippedIncompatible,
                    _skippedUnguided
                ],
                false
            ];
            _vehicle setVariable ["BS_autoCM_threats", [], false];
            _vehicle setVariable ["BS_autoCM_workerToken", 0, false];
            _vehicle setVariable ["BS_autoCM_workerHandle", scriptNull, false];
            _vehicle setVariable ["BS_autoCM_workerExpiresAt", -1, false];
            _vehicle setVariable ["BS_autoCM_workerStopping", false, false];
            _vehicle setVariable ["BS_autoCM_cooldownUntil", time + _cooldown, false];
            _vehicle setVariable [
                "BS_autoCM_nextFireAt",
                (_vehicle getVariable ["BS_autoCM_nextFireAt", -1]) max (time + _cooldown),
                false
            ];
        };

        if (_debug) then {
            diag_log format [
                "[BSKULLS][AUTO-CM] stop vehicle=%1 type=%2 profile=%3 attempts=%4 actualRounds=%5 reason=%6 rounds=%7->%8 threats=%9 ignored=%10/%11/%12 token=%13",
                _vehicle,
                typeOf _vehicle,
                _profileName,
                _attempts,
                _roundsReleased,
                _stopReason,
                _startingRounds,
                _endingRounds,
                count _seenThreatSerials,
                _skippedImmune,
                _skippedIncompatible,
                _skippedUnguided,
                _token
            ];
        };
    };
};

if ((_target getVariable ["BS_autoCM_workerToken", 0]) isEqualTo _token) then {
    _target setVariable ["BS_autoCM_workerHandle", _handle, false];
};
