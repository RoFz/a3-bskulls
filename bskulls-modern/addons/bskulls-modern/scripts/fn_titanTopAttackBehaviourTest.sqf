/*
 * Measure whether a unit-level AWARE versus STEALTH setting changes natural
 * PCML engagement under otherwise identical conditions. Only Hawkins's
 * individual behaviour is varied. Group behaviour is observed but is not a
 * validity condition: the target-free isolation test established that every
 * tested group, including the vanilla control, promptly normalised from AWARE
 * to SAFE while each unit retained its requested individual behaviour.
 * This is an empirical test, not gameplay code or an automatic causal claim.
 *
 * The test requires an otherwise-empty VR mission containing one on-foot
 * player. Every trial creates a fresh Hawkins and hot, invulnerable T-100 at
 * 600 m. Odd/even repetitions reverse behaviour order. The target is absent
 * until Hawkins's asynchronous identity init has completed and the requested
 * behaviour has been applied and verified. AUTOCOMBAT is disabled identically
 * in both arms, and individual/effective behaviour compliance is checked
 * throughout the trial. A contaminated trial is retained and the test moves
 * on to the next fresh pair instead of aborting the entire experiment.
 *
 * Natural acquisition gets 45 seconds by default. If no natural shot occurs,
 * commandTarget/commandFire provide a same-unit, same-target positive control.
 * Projectiles are deleted immediately. The result is logged and copied to the
 * clipboard. Ten repetitions take at most roughly 22 minutes. Do not save or
 * load while the test is running.
 *
 * Run from Local Exec:
 *   [45, 10, 15] call bskulls_fnc_titanTopAttackBehaviourTest;
 *
 * Official semantics used by the test:
 * https://community.bohemia.net/wiki/execVM
 * https://community.bohemia.net/wiki/combatBehaviour
 * https://community.bohemia.net/wiki/setCombatBehaviour
 * https://community.bohemia.net/wiki/disableAI
 * https://community.bohemia.net/wiki/targetKnowledge
 * https://community.bohemia.net/wiki/commandTarget
 * https://community.bohemia.net/wiki/commandFire
 * https://community.bohemia.net/wiki/Combat_Modes
 */

params [
    ["_naturalDuration", 45, [0]],
    ["_repetitions", 10, [0]],
    ["_rescueDuration", 15, [0]],
    ["_scheduledContinuation", false, [false]]
];

_naturalDuration = (_naturalDuration max 20) min 90;
_repetitions = (round _repetitions max 2) min 20;
_rescueDuration = (_rescueDuration max 10) min 30;

private _prefix = "[BSKULLS][TITAN-TA] BEHAVIOUR_TEST";
private _announceFailure = {
    params ["_message"];
    diag_log format ["%1 ABORTED %2", _prefix, _message];
    if (hasInterface) then {
        systemChat format ["PCML behaviour test aborted: %1", _message];
    };
    false
};

if (!hasInterface || {isNull player}) exitWith {
    ["no local player interface"] call _announceFailure
};
if (!isServer) exitWith {
    ["run Local Exec as host in a single-player or hosted VR mission"] call
        _announceFailure
};
if ((toLowerANSI worldName) isNotEqualTo "vr") exitWith {
    ["the controlled test is restricted to the VR terrain"] call
        _announceFailure
};
if ((vehicle player) isNotEqualTo player) exitWith {
    ["the player must be on foot"] call _announceFailure
};

private _requiredClasses = [
    ["CfgVehicles", "B_PTbskull_Veh_Unit_Hawkins_blackops_04"],
    ["CfgVehicles", "O_MBT_02_cannon_F"],
    ["CfgWeapons", "launch_NLAW_F"],
    ["CfgMagazines", "NLAW_F"],
    ["CfgAmmo", "M_NLAW_AT_F"]
];
private _missingClasses = _requiredClasses select {
    !isClass (configFile >> (_x select 0) >> (_x select 1))
};
if (_missingClasses isNotEqualTo []) exitWith {
    [format ["missing required classes %1", _missingClasses]] call
        _announceFailure
};

private _preExistingUnits = allUnits select {_x isNotEqualTo player};
private _preExistingVehicles = vehicles select {
    _x isNotEqualTo vehicle player
};
if (
    _preExistingUnits isNotEqualTo []
    || {_preExistingVehicles isNotEqualTo []}
) exitWith {
    [format [
        "use an empty VR mission (found %1 other units and %2 vehicles)",
        count _preExistingUnits,
        count _preExistingVehicles
    ]] call _announceFailure
};

if (!canSuspend) exitWith {
    if (localNamespace getVariable [
        "bskulls_titanTopAttackBehaviourTestRunning",
        false
    ]) then {
        ["a test is already running"] call _announceFailure;
    } else {
        [
            _naturalDuration,
            _repetitions,
            _rescueDuration,
            true
        ] spawn bskulls_fnc_titanTopAttackBehaviourTest;
        systemChat "PCML behaviour test scheduled.";
    };
    true
};

if (
    !_scheduledContinuation
    && {localNamespace getVariable [
        "bskulls_titanTopAttackBehaviourTestRunning",
        false
    ]}
) exitWith {
    ["a test is already running"] call _announceFailure
};

localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourTestRunning",
    true
];
localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourTestResult",
    []
];

private _testStartedAt = diag_tickTime;
private _bearing = getDir player;
private _playerPosition = getPosATL player;
private _shooterPosition = [
    (_playerPosition select 0) + (sin (_bearing + 90)) * 12,
    (_playerPosition select 1) + (cos (_bearing + 90)) * 12,
    0
];
private _targetDistance = 600;
private _targetPosition = [
    (_shooterPosition select 0) + (sin _bearing) * _targetDistance,
    (_shooterPosition select 1) + (cos _bearing) * _targetDistance,
    0
];
private _launcherClass = "launch_NLAW_F";
private _magazineClass = "NLAW_F";
private _ammoClass = "M_NLAW_AT_F";

private _value = {
    params ["_record", "_name", "_default"];
    private _index = _record findIf {
        (_x param [0, "", [""]]) isEqualTo _name
    };
    if (_index < 0) exitWith {_default};
    (_record select _index) param [1, _default]
};

private _describeSnapshot = {
    params ["_unit", "_target", "_caseStartedAt", "_phase"];
    private _knowledge = _unit targetKnowledge _target;
    private _eyePositionASL = eyePos _unit;
    private _targetPositionASL = aimPos _target;
    private _features = [
        "TARGET",
        "AUTOTARGET",
        "CHECKVISIBLE",
        "WEAPONAIM",
        "FSM",
        "AUTOCOMBAT",
        "FIREWEAPON",
        "MOVE",
        "PATH"
    ] apply {[_x, _unit checkAIFeature _x]};
    [
        ["elapsed", diag_tickTime - _caseStartedAt],
        ["phase", _phase],
        ["knownByGroup", _knowledge param [0, false, [false]]],
        ["knownByUnit", _knowledge param [1, false, [false]]],
        ["lastSeen", _knowledge param [2, -1, [0]]],
        ["lastThreat", _knowledge param [3, -1, [0]]],
        ["knowledgeSide", str (_knowledge param [4, sideUnknown])],
        ["knowledgeError", _knowledge param [5, -1, [0]]],
        ["targetIgnored", _knowledge param [7, false, [false]]],
        ["knowsAbout", _unit knowsAbout _target],
        ["assignedTarget", str assignedTarget _unit],
        ["attackTarget", str getAttackTarget _unit],
        ["currentCommand", currentCommand _unit],
        ["currentWeapon", currentWeapon _unit],
        ["currentMuzzle", currentMuzzle _unit],
        ["currentMode", currentWeaponMode _unit],
        ["weaponState", weaponState _unit],
        ["secondaryWeapon", secondaryWeapon _unit],
        ["secondaryMagazine", secondaryWeaponMagazine _unit],
        ["canFire", canFire _unit],
        ["unitReady", unitReady _unit],
        ["unitCombatMode", unitCombatMode _unit],
        ["groupCombatMode", combatMode group _unit],
        ["effectiveBehaviour", behaviour _unit],
        ["unitCombatBehaviour", combatBehaviour _unit],
        ["groupCombatBehaviour", combatBehaviour group _unit],
        ["suppression", getSuppression _unit],
        ["stance", stance _unit],
        ["animation", animationState _unit],
        ["speedKph", speed _unit],
        ["aiFeatures", _features],
        ["distance2D", _unit distance2D _target],
        ["viewVisibility", [_unit, "VIEW", _target] checkVisibility [
            _eyePositionASL,
            _targetPositionASL
        ]],
        ["fireVisibility", [_unit, "FIRE", _target] checkVisibility [
            _eyePositionASL,
            _targetPositionASL
        ]],
        ["terrainBlocked", terrainIntersectASL [
            _eyePositionASL,
            _targetPositionASL
        ]],
        ["targetEngineOn", isEngineOn _target],
        ["targetIrTarget", getNumber (configOf _target >> "irTarget")],
        ["targetDapsType", _target getVariable ["dapsType", ""]],
        ["targetDapsActive", _target getVariable ["dapsActive", false]]
    ]
};

private _firstExpectedFire = {
    params ["_stateKey"];
    private _events = localNamespace getVariable [_stateKey, []];
    private _index = _events findIf {
        (_x param [1, "", [""]]) isEqualTo _launcherClass
        || {(_x param [4, "", [""]]) isEqualTo _ammoClass}
    };
    if (_index < 0) exitWith {-1};
    (_events select _index) param [0, -1, [0]]
};

private _trialPlan = [];
for "_repetition" from 1 to _repetitions do {
    private _behaviours = ["AWARE", "STEALTH"];
    if ((_repetition mod 2) isEqualTo 0) then {
        reverse _behaviours;
    };
    {
        _trialPlan pushBack [_repetition, _x];
    } forEach _behaviours;
};

private _results = [];
private _trialCount = count _trialPlan;

{
    _x params ["_repetition", "_requestedBehaviour"];
    private _trialNumber = _forEachIndex + 1;
    systemChat format [
        "Behaviour test %1/%2: PCML %3, repetition %4.",
        _trialNumber,
        _trialCount,
        _requestedBehaviour,
        _repetition
    ];

    private _group = createGroup [west, true];
    private _unit = _group createUnit [
        "B_PTbskull_Veh_Unit_Hawkins_blackops_04",
        _shooterPosition,
        [],
        0,
        "NONE"
    ];
    _unit setDir _bearing;

    // CfgVehicles starts 7_hawkins.sqf with execVM. Wait for its final
    // vehicleVarName assignment before this test writes the independent
    // variable. A timeout marks only this trial as contaminated; later trials
    // still run so one asynchronous setup failure cannot discard every pair.
    private _identityDeadline = diag_tickTime + 15;
    waitUntil {
        uiSleep 0.05;
        (vehicleVarName _unit) isEqualTo "BSkullHawkins"
        || {diag_tickTime >= _identityDeadline}
        || {isNull _unit}
    };
    private _identityCompleted = !isNull _unit
        && {(vehicleVarName _unit) isEqualTo "BSkullHawkins"};

    _unit setSkill 1;
    {
        _unit enableAI _x;
    } forEach [
        "TARGET",
        "AUTOTARGET",
        "CHECKVISIBLE",
        "WEAPONAIM",
        "FSM",
        "FIREWEAPON",
        "MOVE",
        "PATH"
    ];
    // Official disableAI semantics: AUTOCOMBAT is the autonomous switch to
    // COMBAT when endangered. Disable it equally in both arms so requested
    // AWARE/STEALTH remains the independent variable.
    _unit disableAI "AUTOCOMBAT";
    _group enableAttack true;
    // Match production identity ownership: fn_applyOperatorIdentity changes
    // the unit, not its group. Group behaviour is recorded as an observed
    // covariate and is not repeatedly forced by the harness.
    _unit setCombatBehaviour _requestedBehaviour;
    _group setCombatMode "YELLOW";
    _unit setUnitCombatMode "YELLOW";

    private _oldSecondary = secondaryWeapon _unit;
    if (_oldSecondary isNotEqualTo "") then {
        _unit removeWeapon _oldSecondary;
    };
    _unit removeMagazines "Titan_AT_TOP_PLUS";
    _unit removeMagazines "Titan_AT";
    _unit removeMagazines "NLAW_F";
    _unit addMagazine _magazineClass;
    _unit addWeapon _launcherClass;
    private _primary = primaryWeapon _unit;
    if (_primary isNotEqualTo "") then {
        _unit selectWeapon _primary;
    };

    private _behaviourDeadline = diag_tickTime + 3;
    waitUntil {
        uiSleep 0.05;
        (
            (combatBehaviour _unit) isEqualTo _requestedBehaviour
            && {(behaviour _unit) isEqualTo _requestedBehaviour}
            && {!(_unit checkAIFeature "AUTOCOMBAT")}
            && {(unitCombatMode _unit) isEqualTo "YELLOW"}
            && {(combatMode _group) isEqualTo "YELLOW"}
        )
        || {diag_tickTime >= _behaviourDeadline}
        || {isNull _unit}
    };
    private _behaviourApplied = !isNull _unit
        && {(combatBehaviour _unit) isEqualTo _requestedBehaviour}
        && {(behaviour _unit) isEqualTo _requestedBehaviour}
        && {!(_unit checkAIFeature "AUTOCOMBAT")}
        && {(unitCombatMode _unit) isEqualTo "YELLOW"}
        && {(combatMode _group) isEqualTo "YELLOW"};

    if (!_behaviourApplied) then {
        diag_log format [
            "%1 TRIAL %2 setup contaminated: requested %3/YELLOW; unit=%4/%5/%6, group=%7/%8",
            _prefix,
            _trialNumber,
            _requestedBehaviour,
            combatBehaviour _unit,
            behaviour _unit,
            unitCombatMode _unit,
            combatBehaviour _group,
            combatMode _group
        ];
    };

    private _stateKey = format [
        "bskulls_titanTopAttackBehaviourTrial_%1_%2",
        round (_testStartedAt * 1000),
        _trialNumber
    ];
    localNamespace setVariable [_stateKey, []];
    _unit setVariable [
        "bskulls_titanTopAttackBehaviourStateKey",
        _stateKey,
        false
    ];
    private _firedHandler = _unit addEventHandler ["FiredMan", {
        params [
            "_unit",
            "_weapon",
            "_muzzle",
            "_mode",
            "_ammo",
            "_magazine",
            "_projectile",
            "_vehicle"
        ];
        private _key = _unit getVariable [
            "bskulls_titanTopAttackBehaviourStateKey",
            ""
        ];
        private _events = localNamespace getVariable [_key, []];
        _events pushBack [
            diag_tickTime,
            _weapon,
            _muzzle,
            _mode,
            _ammo,
            _magazine,
            str _projectile,
            str _vehicle
        ];
        localNamespace setVariable [_key, _events];
        if (!isNull _projectile) then {
            deleteVehicle _projectile;
        };
    }];

    private _caseStartedAt = diag_tickTime;
    private _target = createVehicle [
        "O_MBT_02_cannon_F",
        _targetPosition,
        [],
        0,
        "NONE"
    ];
    _target setDir (_bearing + 180);
    _target setFuel 1;
    _target allowDamage false;
    _target engineOn true;
    _target setVehicleTIPars [1, 1, 1];
    _target setVariable ["dapsActive", false, true];
    private _targetGroup = createVehicleCrew _target;
    _targetGroup setCombatMode "BLUE";
    _targetGroup enableAttack false;
    {
        _x disableAI "TARGET";
        _x disableAI "AUTOTARGET";
        _x disableAI "AUTOCOMBAT";
        _x disableAI "WEAPONAIM";
        _x disableAI "FIREWEAPON";
        _x disableAI "MOVE";
        _x disableAI "PATH";
    } forEach crew _target;

    private _firstKnown = -1;
    private _firstAttackTarget = -1;
    private _firstAssigned = -1;
    private _firstSelected = -1;
    private _behaviourCompliant = _identityCompleted &&
        {_behaviourApplied};
    private _controlsCompliant = true;
    private _transitions = [];
    private _lastSignature = [];
    private _lastPeriodicSampleAt = -1e10;
    private _initialSnapshot = [];
    private _naturalDeadline = diag_tickTime + _naturalDuration;

    waitUntil {
        uiSleep 0.25;
        _target engineOn true;
        _target setVehicleTIPars [1, 1, 1];
        _target setVariable ["dapsActive", false, true];

        private _snapshot = [
            _unit,
            _target,
            _caseStartedAt,
            "natural"
        ] call _describeSnapshot;
        if (_initialSnapshot isEqualTo []) then {
            _initialSnapshot = _snapshot;
        };
        private _elapsed = [_snapshot, "elapsed", -1] call _value;
        private _known = [
            _snapshot,
            "knownByUnit",
            false
        ] call _value;
        private _attack = (
            [_snapshot, "attackTarget", ""] call _value
        ) isEqualTo str _target;
        private _assigned = (
            [_snapshot, "assignedTarget", ""] call _value
        ) isEqualTo str _target;
        private _selected = (
            [_snapshot, "currentWeapon", ""] call _value
        ) isEqualTo _launcherClass;
        private _unitBehaviour = [
            _snapshot,
            "unitCombatBehaviour",
            ""
        ] call _value;
        private _groupBehaviour = [
            _snapshot,
            "groupCombatBehaviour",
            ""
        ] call _value;
        private _effectiveBehaviour = [
            _snapshot,
            "effectiveBehaviour",
            ""
        ] call _value;
        if (
            _unitBehaviour isNotEqualTo _requestedBehaviour
            || {_effectiveBehaviour isNotEqualTo _requestedBehaviour}
        ) then {
            _behaviourCompliant = false;
        };
        private _aiFeatures = [
            _snapshot,
            "aiFeatures",
            []
        ] call _value;
        private _invalidAiFeature = _aiFeatures findIf {
            private _feature = _x param [0, "", [""]];
            private _enabled = _x param [1, false, [false]];
            if (_feature isEqualTo "AUTOCOMBAT") then {
                _enabled
            } else {
                !_enabled
            }
        };
        if (
            ([_snapshot, "unitCombatMode", ""] call _value)
                isNotEqualTo "YELLOW"
            || {([_snapshot, "groupCombatMode", ""] call _value)
                isNotEqualTo "YELLOW"}
            || {_invalidAiFeature >= 0}
            || {!([_snapshot, "targetEngineOn", false] call _value)}
            || {[_snapshot, "targetDapsActive", true] call _value}
            || {([_snapshot, "viewVisibility", 0] call _value) <= 0}
            || {([_snapshot, "fireVisibility", 0] call _value) <= 0}
            || {[_snapshot, "terrainBlocked", true] call _value}
        ) then {
            _controlsCompliant = false;
        };
        if (_firstKnown < 0 && {_known}) then {
            _firstKnown = _elapsed;
        };
        if (_firstAttackTarget < 0 && {_attack}) then {
            _firstAttackTarget = _elapsed;
        };
        if (_firstAssigned < 0 && {_assigned}) then {
            _firstAssigned = _elapsed;
        };
        if (_firstSelected < 0 && {_selected}) then {
            _firstSelected = _elapsed;
        };

        private _signature = [
            _known,
            _attack,
            _assigned,
            _selected,
            [_snapshot, "currentCommand", ""] call _value,
            _effectiveBehaviour,
            _unitBehaviour,
            _groupBehaviour,
            [_snapshot, "stance", ""] call _value
        ];
        if (
            _signature isNotEqualTo _lastSignature
            || {_elapsed - _lastPeriodicSampleAt >= 5}
        ) then {
            if ((count _transitions) < 80) then {
                _transitions pushBack _snapshot;
            };
            _lastSignature = _signature;
            _lastPeriodicSampleAt = _elapsed;
        };

        ([_stateKey] call _firstExpectedFire) >= 0
        || {diag_tickTime >= _naturalDeadline}
        || {isNull _unit}
        || {!alive _unit}
        || {isNull _target}
    };

    private _naturalFinalSnapshot = if (
        isNull _unit || {isNull _target}
    ) then {[]} else {
        [_unit, _target, _caseStartedAt, "natural-end"] call
            _describeSnapshot
    };
    private _naturalFireTick = [_stateKey] call _firstExpectedFire;
    private _naturalFired = _naturalFireTick >= 0;
    private _rescueOrderAt = -1;
    private _rescueFireTick = -1;
    private _rescueFinalSnapshot = [];

    if (!_naturalFired && {!isNull _unit} && {alive _unit}) then {
        // Recheck immediately before intervention so a boundary shot remains
        // classified as natural rather than ordered.
        _naturalFireTick = [_stateKey] call _firstExpectedFire;
        _naturalFired = _naturalFireTick >= 0;
    };

    if (!_naturalFired && {!isNull _unit} && {alive _unit}) then {
        _group reveal [_target, 4];
        _unit commandTarget _target;
        uiSleep 0.25;
        _rescueOrderAt = diag_tickTime;
        _unit commandFire _target;
        private _rescueDeadline = diag_tickTime + _rescueDuration;
        waitUntil {
            uiSleep 0.25;
            _target engineOn true;
            _target setVehicleTIPars [1, 1, 1];
            _target setVariable ["dapsActive", false, true];
            if (
                (combatBehaviour _unit) isNotEqualTo _requestedBehaviour
                || {(behaviour _unit) isNotEqualTo _requestedBehaviour}
            ) then {
                _behaviourCompliant = false;
            };
            if (
                (unitCombatMode _unit) isNotEqualTo "YELLOW"
                || {(combatMode _group) isNotEqualTo "YELLOW"}
                || {_unit checkAIFeature "AUTOCOMBAT"}
                || {!isEngineOn _target}
                || {_target getVariable ["dapsActive", true]}
            ) then {
                _controlsCompliant = false;
            };
            _rescueFireTick = [_stateKey] call _firstExpectedFire;
            _rescueFireTick >= 0
            || {diag_tickTime >= _rescueDeadline}
            || {isNull _unit}
            || {!alive _unit}
            || {isNull _target}
        };
        _rescueFinalSnapshot = if (
            isNull _unit || {isNull _target}
        ) then {[]} else {
            [_unit, _target, _caseStartedAt, "ordered-rescue-end"] call
                _describeSnapshot
        };
    };

    private _geometryValid = _initialSnapshot isNotEqualTo []
        && {([_initialSnapshot, "viewVisibility", 0] call _value) > 0}
        && {([_initialSnapshot, "fireVisibility", 0] call _value) > 0}
        && {!([_initialSnapshot, "terrainBlocked", true] call _value)};
    private _rescueFired = !_naturalFired && {_rescueFireTick >= 0};
    private _events = localNamespace getVariable [_stateKey, []];
    private _outcome = if (!_identityCompleted) then {
        "identity-not-completed"
    } else {
        if (!_behaviourApplied) then {
            "setup-not-applied"
        } else {
            if (!_geometryValid) then {
                "invalid-line-of-fire"
            } else {
                if (!_behaviourCompliant || {!_controlsCompliant}) then {
                    "control-contaminated"
                } else {
                    if (_naturalFired) then {
                        "natural-fired"
                    } else {
                        [
                            "no-fire",
                            "ordered-rescue-fired"
                        ] select _rescueFired
                    }
                }
            }
        }
    };

    private _trialResult = [
        ["trial", _trialNumber],
        ["repetition", _repetition],
        ["requestedBehaviour", _requestedBehaviour],
        ["identityCompleted", _identityCompleted],
        ["behaviourApplied", _behaviourApplied],
        ["behaviourCompliant", _behaviourCompliant],
        ["controlsCompliant", _controlsCompliant],
        ["weapon", "pcml"],
        ["launcher", _launcherClass],
        ["magazine", _magazineClass],
        ["ammo", _ammoClass],
        ["requestedDistance", _targetDistance],
        ["timings", [
            ["knownByUnit", _firstKnown],
            ["attackTarget", _firstAttackTarget],
            ["assigned", _firstAssigned],
            ["launcherSelected", _firstSelected],
            [
                "naturalFire",
                if (_naturalFireTick < 0) then {-1} else {
                    _naturalFireTick - _caseStartedAt
                }
            ],
            [
                "rescueOrder",
                if (_rescueOrderAt < 0) then {-1} else {
                    _rescueOrderAt - _caseStartedAt
                }
            ],
            [
                "rescueFire",
                if (_rescueFireTick < 0) then {-1} else {
                    _rescueFireTick - _caseStartedAt
                }
            ]
        ]],
        ["outcome", _outcome],
        ["naturalFired", _naturalFired],
        ["rescueFired", _rescueFired],
        ["geometryValid", _geometryValid],
        ["firedEvents", _events],
        ["initialSnapshot", _initialSnapshot],
        ["naturalFinalSnapshot", _naturalFinalSnapshot],
        ["rescueFinalSnapshot", _rescueFinalSnapshot],
        ["transitionLimit", 80],
        ["transitionBufferFull", (count _transitions) >= 80],
        ["transitions", _transitions]
    ];
    _results pushBack _trialResult;
    diag_log format ["%1 TRIAL %2", _prefix, _trialResult];

    if (!isNull _unit) then {
        _unit removeEventHandler ["FiredMan", _firedHandler];
    };
    localNamespace setVariable [_stateKey, nil];
    deleteVehicle _unit;
    deleteGroup _group;
    deleteVehicleCrew _target;
    deleteVehicle _target;
    deleteGroup _targetGroup;
    uiSleep 1;
} forEach _trialPlan;

private _summaries = [];
{
    private _requestedBehaviour = _x;
    private _cases = _results select {
        ([_x, "requestedBehaviour", ""] call _value) isEqualTo
            _requestedBehaviour
    };
    private _cleanCases = _cases select {
        [_x, "identityCompleted", false] call _value
        && {[_x, "behaviourApplied", false] call _value}
        && {[_x, "behaviourCompliant", false] call _value}
        && {[_x, "controlsCompliant", false] call _value}
        && {[_x, "geometryValid", false] call _value}
    };
    private _naturalCases = _cleanCases select {
        [_x, "naturalFired", false] call _value
    };
    private _rescueCases = _cleanCases select {
        [_x, "rescueFired", false] call _value
    };
    private _knownCases = _cleanCases select {
        private _timings = [_x, "timings", []] call _value;
        ([_timings, "knownByUnit", -1] call _value) >= 0
    };
    private _selectedCases = _cleanCases select {
        private _timings = [_x, "timings", []] call _value;
        ([_timings, "launcherSelected", -1] call _value) >= 0
    };
    _summaries pushBack [
        ["requestedBehaviour", _requestedBehaviour],
        ["trials", count _cases],
        ["cleanTrials", count _cleanCases],
        ["excludedTrials", (count _cases) - (count _cleanCases)],
        [
            "setupInvalidTrials",
            count (_cases select {
                !([_x, "identityCompleted", false] call _value)
                || {!([_x, "behaviourApplied", false] call _value)}
            })
        ],
        [
            "behaviourContaminatedTrials",
            count (_cases select {
                !([_x, "behaviourCompliant", false] call _value)
            })
        ],
        [
            "otherControlContaminatedTrials",
            count (_cases select {
                !([_x, "controlsCompliant", false] call _value)
            })
        ],
        ["targetKnown", count _knownCases],
        ["launcherSelected", count _selectedCases],
        ["naturalFired", count _naturalCases],
        [
            "naturalFireRate",
            if (_cleanCases isEqualTo []) then {-1} else {
                (count _naturalCases) / (count _cleanCases)
            }
        ],
        ["orderedRescueFired", count _rescueCases],
        [
            "orderedRescueEligible",
            (count _cleanCases) - (count _naturalCases)
        ]
    ];
} forEach ["AWARE", "STEALTH"];

// Preserve the counterbalanced repetition pairing so the report distinguishes
// consistent behaviour effects from session-order drift. Statistical
// interpretation is deliberately left to analysis of the returned evidence.
private _pairs = [];
for "_repetition" from 1 to _repetitions do {
    private _awareIndex = _results findIf {
        ([_x, "repetition", -1] call _value) isEqualTo _repetition
        && {([_x, "requestedBehaviour", ""] call _value) isEqualTo
            "AWARE"}
    };
    private _stealthIndex = _results findIf {
        ([_x, "repetition", -1] call _value) isEqualTo _repetition
        && {([_x, "requestedBehaviour", ""] call _value) isEqualTo
            "STEALTH"}
    };
    private _awareCase = if (_awareIndex < 0) then {[]} else {
        _results select _awareIndex
    };
    private _stealthCase = if (_stealthIndex < 0) then {[]} else {
        _results select _stealthIndex
    };
    private _awareClean = _awareCase isNotEqualTo []
        && {[_awareCase, "identityCompleted", false] call _value}
        && {[_awareCase, "behaviourApplied", false] call _value}
        && {[_awareCase, "behaviourCompliant", false] call _value}
        && {[_awareCase, "controlsCompliant", false] call _value}
        && {[_awareCase, "geometryValid", false] call _value};
    private _stealthClean = _stealthCase isNotEqualTo []
        && {[_stealthCase, "identityCompleted", false] call _value}
        && {[_stealthCase, "behaviourApplied", false] call _value}
        && {[_stealthCase, "behaviourCompliant", false] call _value}
        && {[_stealthCase, "controlsCompliant", false] call _value}
        && {[_stealthCase, "geometryValid", false] call _value};
    _pairs pushBack [
        ["repetition", _repetition],
        ["clean", _awareClean && {_stealthClean}],
        ["awareTrial", [_awareCase, "trial", -1] call _value],
        ["stealthTrial", [_stealthCase, "trial", -1] call _value],
        [
            "awareNaturalFired",
            [_awareCase, "naturalFired", false] call _value
        ],
        [
            "stealthNaturalFired",
            [_stealthCase, "naturalFired", false] call _value
        ],
        ["awareOutcome", [_awareCase, "outcome", "missing"] call _value],
        [
            "stealthOutcome",
            [_stealthCase, "outcome", "missing"] call _value
        ]
    ];
};

private _cleanPairs = _pairs select {[_x, "clean", false] call _value};
private _awareOnlyPairs = _cleanPairs select {
    [_x, "awareNaturalFired", false] call _value
    && {!([_x, "stealthNaturalFired", false] call _value)}
};
private _stealthOnlyPairs = _cleanPairs select {
    !([_x, "awareNaturalFired", false] call _value)
    && {[_x, "stealthNaturalFired", false] call _value}
};
private _bothFiredPairs = _cleanPairs select {
    [_x, "awareNaturalFired", false] call _value
    && {[_x, "stealthNaturalFired", false] call _value}
};
private _neitherFiredPairs = _cleanPairs select {
    !([_x, "awareNaturalFired", false] call _value)
    && {!([_x, "stealthNaturalFired", false] call _value)}
};
private _pairedSummary = [
    ["pairs", count _pairs],
    ["cleanPairs", count _cleanPairs],
    ["awareOnlyFired", count _awareOnlyPairs],
    ["stealthOnlyFired", count _stealthOnlyPairs],
    ["bothFired", count _bothFiredPairs],
    ["neitherFired", count _neitherFiredPairs]
];

private _launcherConfig = configFile >> "CfgWeapons" >> _launcherClass;
private _magazineConfig = configFile >> "CfgMagazines" >> _magazineClass;
private _ammoConfig = configFile >> "CfgAmmo" >> _ammoClass;
private _overflyConfig = _launcherConfig >> "Overfly";
private _report = [
    ["report", "Black Skulls PCML behaviour A/B test"],
    ["schemaVersion", 2],
    ["tick", diag_tickTime],
    ["world", worldName],
    ["machine", [clientOwner, isServer, hasInterface]],
    ["aborted", false],
    ["abortReason", ""],
    ["conditions", [
        ["independentVariable", "combatBehaviour"],
        ["levels", ["AWARE", "STEALTH"]],
        ["groupCombatBehaviour", "observed-not-constrained"],
        ["weapon", "PCML"],
        ["launcher", _launcherClass],
        ["magazine", _magazineClass],
        ["ammo", _ammoClass],
        ["distance", _targetDistance],
        ["naturalDuration", _naturalDuration],
        ["repetitionsPerBehaviour", _repetitions],
        ["rescueDuration", _rescueDuration],
        ["behaviourOrderCounterbalanced", true],
        ["freshShooterPerTrial", true],
        ["freshTargetPerTrial", true],
        ["shooterIsSoleGroupLeader", true],
        ["identityCompletionRequired", true],
        ["individualBehaviourVerifiedContinuously", true],
        ["effectiveBehaviourVerifiedContinuously", true],
        ["autocombatDisabled", true],
        ["contaminatedTrialsContinue", true],
        ["combatMode", "YELLOW"],
        ["targetClass", "O_MBT_02_cannon_F"],
        ["targetTiPars", [1, 1, 1]],
        ["projectilesDeleted", true],
        ["targetDamageDisabled", true],
        ["dapsForcedInactive", true],
        ["preExistingOtherUnits", count _preExistingUnits],
        ["preExistingVehicles", count _preExistingVehicles]
    ]],
    ["config", [
        ["launcherPresent", isClass _launcherConfig],
        ["magazinePresent", isClass _magazineConfig],
        ["ammoPresent", isClass _ammoConfig],
        ["modes", getArray (_launcherConfig >> "modes")],
        ["canLock", getNumber (_launcherConfig >> "canLock")],
        ["weaponLockSystem", getNumber (
            _launcherConfig >> "weaponLockSystem"
        )],
        ["aiRateOfFire", getNumber (
            _overflyConfig >> "aiRateOfFire"
        )],
        ["aiRateOfFireDistance", getNumber (
            _overflyConfig >> "aiRateOfFireDistance"
        )],
        ["minRange", getNumber (_overflyConfig >> "minRange")],
        ["minRangeProbab", getNumber (
            _overflyConfig >> "minRangeProbab"
        )],
        ["midRange", getNumber (_overflyConfig >> "midRange")],
        ["midRangeProbab", getNumber (
            _overflyConfig >> "midRangeProbab"
        )],
        ["maxRange", getNumber (_overflyConfig >> "maxRange")],
        ["maxRangeProbab", getNumber (
            _overflyConfig >> "maxRangeProbab"
        )],
        ["aiAmmoUsageFlags", getNumber (
            _ammoConfig >> "aiAmmoUsageFlags"
        )],
        ["missileLockMinDistance", getNumber (
            _ammoConfig >> "missileLockMinDistance"
        )],
        ["missileLockMaxDistance", getNumber (
            _ammoConfig >> "missileLockMaxDistance"
        )]
    ]],
    ["summary", _summaries],
    ["pairedSummary", _pairedSummary],
    ["pairs", _pairs],
    ["trialCount", count _results],
    ["elapsed", diag_tickTime - _testStartedAt],
    ["trials", _results]
];

localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourTestResult",
    _report
];
localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourTestRunning",
    false
];
diag_log format ["%1 FINAL %2", _prefix, _report];
copyToClipboard str _report;

systemChat format [
    "PCML behaviour test complete: %1 trials. Report copied.",
    count _results
];

_report
