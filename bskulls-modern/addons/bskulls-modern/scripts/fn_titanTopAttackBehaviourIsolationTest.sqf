/*
 * Isolate the unexplained group AWARE -> SAFE transition observed by the
 * PCML behaviour A/B test. This test creates no enemy and fires no weapon.
 * AUTOCOMBAT is disabled in every case so the documented autonomous switch
 * to COMBAT cannot contaminate the observation.
 *
 * Four cases separate the vanilla baseline, Hawkins identity setup,
 * unit-level STEALTH, and sole-leader/group coupling. A group
 * CombatModeChanged event handler records group behaviour changes; despite
 * its name, Bohemia documents this event as reporting AI behaviour changes.
 *
 * Requires an otherwise-empty VR mission containing one on-foot player.
 * Run from Local Exec:
 *   [10] call bskulls_fnc_titanTopAttackBehaviourIsolationTest;
 *
 * Official semantics:
 * https://community.bohemia.net/wiki/setCombatBehaviour
 * https://community.bohemia.net/wiki/combatBehaviour
 * https://community.bohemia.net/wiki/disableAI
 * https://community.bohemia.net/wiki/Arma_3:_Event_Handlers#CombatModeChanged
 */

params [
    ["_observationDuration", 10, [0]],
    ["_scheduledContinuation", false, [false]]
];

_observationDuration = (_observationDuration max 5) min 30;

private _prefix = "[BSKULLS][TITAN-TA] BEHAVIOUR_ISOLATION";
private _announceFailure = {
    params ["_message"];
    diag_log format ["%1 ABORTED %2", _prefix, _message];
    if (hasInterface) then {
        systemChat format ["Behaviour isolation test aborted: %1", _message];
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
    ["CfgVehicles", "B_Soldier_F"],
    ["CfgVehicles", "B_PTbskull_Veh_Unit_Hawkins_blackops_04"]
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
        "bskulls_titanTopAttackBehaviourIsolationTestRunning",
        false
    ]) then {
        ["a test is already running"] call _announceFailure;
    } else {
        [
            _observationDuration,
            true
        ] spawn bskulls_fnc_titanTopAttackBehaviourIsolationTest;
        systemChat "Behaviour isolation test scheduled.";
    };
    true
};

if (
    !_scheduledContinuation
    && {localNamespace getVariable [
        "bskulls_titanTopAttackBehaviourIsolationTestRunning",
        false
    ]}
) exitWith {
    ["a test is already running"] call _announceFailure
};

localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourIsolationTestRunning",
    true
];
localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourIsolationTestResult",
    []
];

private _testStartedAt = diag_tickTime;
private _bearing = getDir player;
private _playerPosition = getPosATL player;
private _casePosition = [
    (_playerPosition select 0) + (sin (_bearing + 90)) * 12,
    (_playerPosition select 1) + (cos (_bearing + 90)) * 12,
    0
];
private _controlLeaderPosition = [
    (_casePosition select 0) + (sin (_bearing + 90)) * 3,
    (_casePosition select 1) + (cos (_bearing + 90)) * 3,
    0
];

private _value = {
    params ["_record", "_name", "_default"];
    private _index = _record findIf {
        (_x param [0, "", [""]]) isEqualTo _name
    };
    if (_index < 0) exitWith {_default};
    (_record select _index) param [1, _default]
};

private _snapshot = {
    params ["_unit", "_group", "_caseStartedAt", "_phase"];
    private _leader = leader _group;
    [
        ["elapsed", diag_tickTime - _caseStartedAt],
        ["phase", _phase],
        ["unit", str _unit],
        ["unitClass", typeOf _unit],
        ["unitIsGroupLeader", _leader isEqualTo _unit],
        ["groupLeader", str _leader],
        ["groupLeaderClass", if (isNull _leader) then {""} else {
            typeOf _leader
        }],
        ["groupUnitCount", count units _group],
        ["unitCombatBehaviour", combatBehaviour _unit],
        ["groupCombatBehaviour", combatBehaviour _group],
        ["unitEffectiveBehaviour", behaviour _unit],
        ["leaderCombatBehaviour", if (isNull _leader) then {"ERROR"} else {
            combatBehaviour _leader
        }],
        ["leaderEffectiveBehaviour", if (isNull _leader) then {"ERROR"} else {
            behaviour _leader
        }],
        ["unitCombatMode", unitCombatMode _unit],
        ["groupCombatMode", combatMode _group],
        ["unitCurrentCommand", currentCommand _unit],
        ["leaderCurrentCommand", if (isNull _leader) then {""} else {
            currentCommand _leader
        }],
        ["currentWaypoint", currentWaypoint _group],
        ["groupAttackEnabled", attackEnabled _group],
        ["unitAutocombat", _unit checkAIFeature "AUTOCOMBAT"],
        ["leaderAutocombat", if (isNull _leader) then {false} else {
            _leader checkAIFeature "AUTOCOMBAT"
        }]
    ]
};

private _cases = [
    [
        "vanilla-solo-aware",
        "B_Soldier_F",
        "AWARE",
        false
    ],
    [
        "hawkins-solo-aware",
        "B_PTbskull_Veh_Unit_Hawkins_blackops_04",
        "AWARE",
        false
    ],
    [
        "hawkins-solo-stealth",
        "B_PTbskull_Veh_Unit_Hawkins_blackops_04",
        "STEALTH",
        false
    ],
    [
        "hawkins-subordinate-stealth",
        "B_PTbskull_Veh_Unit_Hawkins_blackops_04",
        "STEALTH",
        true
    ]
];

private _results = [];

{
    _x params [
        "_label",
        "_unitClass",
        "_requestedUnitBehaviour",
        "_useControlLeader"
    ];
    private _caseNumber = _forEachIndex + 1;
    systemChat format [
        "Behaviour isolation %1/%2: %3.",
        _caseNumber,
        count _cases,
        _label
    ];

    private _group = createGroup [west, true];
    private _createdUnits = [];
    private _controlLeader = objNull;
    if (_useControlLeader) then {
        _controlLeader = _group createUnit [
            "B_Soldier_F",
            _controlLeaderPosition,
            [],
            0,
            "NONE"
        ];
        _createdUnits pushBack _controlLeader;
        _controlLeader setDir _bearing;
        removeAllWeapons _controlLeader;
        {
            _controlLeader disableAI _x;
        } forEach [
            "TARGET",
            "AUTOTARGET",
            "CHECKVISIBLE",
            "WEAPONAIM",
            "FSM",
            "AUTOCOMBAT",
            "FIREWEAPON",
            "MOVE",
            "PATH"
        ];
    };

    private _unit = _group createUnit [
        _unitClass,
        _casePosition,
        [],
        0,
        "NONE"
    ];
    _createdUnits pushBack _unit;
    _unit setDir _bearing;
    if (_useControlLeader) then {
        _group selectLeader _controlLeader;
    } else {
        _group selectLeader _unit;
    };

    private _identityRequired = _unitClass isEqualTo
        "B_PTbskull_Veh_Unit_Hawkins_blackops_04";
    private _identityDeadline = diag_tickTime + 15;
    waitUntil {
        uiSleep 0.05;
        !_identityRequired
        || {(vehicleVarName _unit) isEqualTo "BSkullHawkins"}
        || {diag_tickTime >= _identityDeadline}
        || {isNull _unit}
    };
    private _identityCompleted = !_identityRequired || {
        !isNull _unit
        && {(vehicleVarName _unit) isEqualTo "BSkullHawkins"}
    };

    private _stateKey = format [
        "bskulls_titanTopAttackBehaviourIsolationCase_%1_%2",
        round (_testStartedAt * 1000),
        _caseNumber
    ];
    localNamespace setVariable [_stateKey, []];
    _group setVariable [
        "bskulls_titanTopAttackBehaviourIsolationStateKey",
        _stateKey,
        false
    ];
    _group setVariable [
        "bskulls_titanTopAttackBehaviourIsolationStartedAt",
        diag_tickTime,
        false
    ];
    private _behaviourHandler = _group addEventHandler [
        "CombatModeChanged",
        {
            params ["_group", "_newBehaviour"];
            private _key = _group getVariable [
                "bskulls_titanTopAttackBehaviourIsolationStateKey",
                ""
            ];
            if (_key isEqualTo "") exitWith {};
            private _startedAt = _group getVariable [
                "bskulls_titanTopAttackBehaviourIsolationStartedAt",
                diag_tickTime
            ];
            private _events = localNamespace getVariable [_key, []];
            _events pushBack [
                diag_tickTime - _startedAt,
                _newBehaviour,
                combatBehaviour _group,
                str leader _group
            ];
            localNamespace setVariable [_key, _events];
        }
    ];

    _unit disableAI "AUTOCOMBAT";
    if (!isNull _controlLeader) then {
        _controlLeader setCombatBehaviour "AWARE";
        _controlLeader setUnitCombatMode "YELLOW";
    };
    _group setCombatBehaviour "AWARE";
    _unit setCombatBehaviour _requestedUnitBehaviour;
    _group setCombatMode "YELLOW";
    _unit setUnitCombatMode "YELLOW";

    private _caseStartedAt = diag_tickTime;
    _group setVariable [
        "bskulls_titanTopAttackBehaviourIsolationStartedAt",
        _caseStartedAt,
        false
    ];
    uiSleep 0.1;

    private _initialSnapshot = [
        _unit,
        _group,
        _caseStartedAt,
        "initial"
    ] call _snapshot;
    private _applied = _identityCompleted
        && {(combatBehaviour _unit) isEqualTo _requestedUnitBehaviour}
        && {(combatBehaviour _group) isEqualTo "AWARE"}
        && {!(_unit checkAIFeature "AUTOCOMBAT")}
        && {(unitCombatMode _unit) isEqualTo "YELLOW"}
        && {(combatMode _group) isEqualTo "YELLOW"};
    private _stable = _applied;
    private _transitions = [_initialSnapshot];
    private _lastSignature = [
        [_initialSnapshot, "unitCombatBehaviour", ""] call _value,
        [_initialSnapshot, "groupCombatBehaviour", ""] call _value,
        [_initialSnapshot, "unitEffectiveBehaviour", ""] call _value,
        [_initialSnapshot, "leaderCombatBehaviour", ""] call _value,
        [_initialSnapshot, "unitCombatMode", ""] call _value,
        [_initialSnapshot, "groupCombatMode", ""] call _value,
        [_initialSnapshot, "unitCurrentCommand", ""] call _value,
        [_initialSnapshot, "leaderCurrentCommand", ""] call _value
    ];
    private _lastPeriodicSampleAt = 0;
    private _deadline = diag_tickTime + _observationDuration;

    waitUntil {
        uiSleep 0.1;
        private _current = [
            _unit,
            _group,
            _caseStartedAt,
            "observation"
        ] call _snapshot;
        private _elapsed = [_current, "elapsed", 0] call _value;
        if (
            ([_current, "unitCombatBehaviour", ""] call _value)
                isNotEqualTo _requestedUnitBehaviour
            || {([_current, "groupCombatBehaviour", ""] call _value)
                isNotEqualTo "AWARE"}
            || {[_current, "unitAutocombat", true] call _value}
            || {([_current, "unitCombatMode", ""] call _value)
                isNotEqualTo "YELLOW"}
            || {([_current, "groupCombatMode", ""] call _value)
                isNotEqualTo "YELLOW"}
        ) then {
            _stable = false;
        };
        private _signature = [
            [_current, "unitCombatBehaviour", ""] call _value,
            [_current, "groupCombatBehaviour", ""] call _value,
            [_current, "unitEffectiveBehaviour", ""] call _value,
            [_current, "leaderCombatBehaviour", ""] call _value,
            [_current, "unitCombatMode", ""] call _value,
            [_current, "groupCombatMode", ""] call _value,
            [_current, "unitCurrentCommand", ""] call _value,
            [_current, "leaderCurrentCommand", ""] call _value
        ];
        if (
            _signature isNotEqualTo _lastSignature
            || {_elapsed - _lastPeriodicSampleAt >= 1}
        ) then {
            if ((count _transitions) < 80) then {
                _transitions pushBack _current;
            };
            _lastSignature = _signature;
            _lastPeriodicSampleAt = _elapsed;
        };
        diag_tickTime >= _deadline
        || {isNull _unit}
        || {!alive _unit}
    };

    private _finalSnapshot = if (isNull _unit) then {[]} else {
        [
            _unit,
            _group,
            _caseStartedAt,
            "final"
        ] call _snapshot
    };
    private _groupEvents = localNamespace getVariable [_stateKey, []];
    private _observedGroupBehaviours = [];
    {
        _observedGroupBehaviours pushBackUnique (
            [_x, "groupCombatBehaviour", ""] call _value
        );
    } forEach _transitions;

    private _caseResult = [
        ["case", _caseNumber],
        ["label", _label],
        ["unitClass", _unitClass],
        ["requestedUnitBehaviour", _requestedUnitBehaviour],
        ["requestedGroupBehaviour", "AWARE"],
        ["controlLeaderUsed", _useControlLeader],
        ["identityRequired", _identityRequired],
        ["identityCompleted", _identityCompleted],
        ["autocombatDisabled", !(_unit checkAIFeature "AUTOCOMBAT")],
        ["applied", _applied],
        ["stable", _stable],
        ["observedGroupBehaviours", _observedGroupBehaviours],
        ["groupBehaviourEvents", _groupEvents],
        ["initialSnapshot", _initialSnapshot],
        ["finalSnapshot", _finalSnapshot],
        ["transitionLimit", 80],
        ["transitionBufferFull", (count _transitions) >= 80],
        ["transitions", _transitions]
    ];
    _results pushBack _caseResult;
    diag_log format ["%1 CASE %2", _prefix, _caseResult];

    _group removeEventHandler ["CombatModeChanged", _behaviourHandler];
    localNamespace setVariable [_stateKey, nil];
    {
        if (!isNull _x) then {
            deleteVehicle _x;
        };
    } forEach _createdUnits;
    deleteGroup _group;
    uiSleep 0.5;
} forEach _cases;

private _stableCases = _results select {
    [_x, "stable", false] call _value
};
private _safeCases = _results select {
    "SAFE" in ([_x, "observedGroupBehaviours", []] call _value)
};
private _report = [
    ["report", "Black Skulls behaviour transition isolation test"],
    ["schemaVersion", 1],
    ["tick", diag_tickTime],
    ["world", worldName],
    ["machine", [clientOwner, isServer, hasInterface]],
    ["conditions", [
        ["targetPresent", false],
        ["weaponFiringPossible", false],
        ["autocombatDisabledAllCases", true],
        ["requestedGroupBehaviour", "AWARE"],
        ["combatMode", "YELLOW"],
        ["observationDurationPerCase", _observationDuration],
        ["caseCount", count _cases],
        ["preExistingOtherUnits", count _preExistingUnits],
        ["preExistingVehicles", count _preExistingVehicles]
    ]],
    ["summary", [
        ["completedCases", count _results],
        ["stableCases", _stableCases apply {
            [_x, "label", ""] call _value
        }],
        ["casesObservingSafe", _safeCases apply {
            [_x, "label", ""] call _value
        }]
    ]],
    ["elapsed", diag_tickTime - _testStartedAt],
    ["cases", _results]
];

localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourIsolationTestResult",
    _report
];
localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourIsolationTestRunning",
    false
];
diag_log format ["%1 FINAL %2", _prefix, _report];
copyToClipboard str _report;
systemChat format [
    "Behaviour isolation complete: %1/%2 stable. Report copied.",
    count _stableCases,
    count _results
];

_report
