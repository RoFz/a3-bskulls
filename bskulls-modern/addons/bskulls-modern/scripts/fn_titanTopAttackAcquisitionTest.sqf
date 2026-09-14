/*
 * Controlled launcher test with two contexts:
 *   ISOLATED:
 *     1. Hawkins + vanilla Titan AT at 1,200 m
 *     2. Hawkins + Archangel at 1,200 m
 *   PLAYER_LED:
 *     1. Hawkins + Archangel at 1,200 m
 *     2. Hawkins + PCML at 600 m
 *     3. Fox + PCML at 600 m
 *
 * Both contexts use AWARE individual behaviour, disabled AUTOCOMBAT, verified
 * YELLOW unit/group ROE, normalized one-round loadouts, and a fresh hot,
 * invulnerable T-100. A preflight guard verifies each arm's configured lock
 * and AI-use ranges before trial 1. Group behaviour is observed, not
 * constrained, following the target-free behaviour-isolation result.
 * PLAYER_LED creates every shooter directly in the local player's group and
 * requires the player to remain that group's leader. It deliberately sets
 * YELLOW after named-operator identity initialization has applied BLUE. This
 * isolates group leadership; it does not emulate the separate, engine-internal
 * player-radio Open Fire override, which Bohemia notes does not change the
 * value returned by combatMode/unitCombatMode.
 *
 * Acquisition and natural fire use separate deadlines. Once the shooter knows
 * the target, targets it, selects the loaded launcher, and still has a round,
 * the complete post-readiness fire window begins. If FiredMan occurs between
 * polling snapshots, the expected launcher event establishes that readiness
 * was reached no later than the shot; the report keeps that evidence distinct
 * from readiness observed before fire. A no-fire trial then receives
 * commandTarget/commandFire as a same-unit positive control. Projectiles are
 * deleted immediately. This diagnostic changes no production gameplay logic.
 *
 * Empty VR mission, one on-foot player, Local Exec:
 *   [60, 10, 15, 15] call bskulls_fnc_titanTopAttackAcquisitionTest;
 *   [60, 10, 15, 15, "PLAYER_LED"] call
 *       bskulls_fnc_titanTopAttackAcquisitionTest;
 *
 * Official semantics:
 * https://community.bohemia.net/wiki/targetKnowledge
 * https://community.bohemia.net/wiki/commandTarget
 * https://community.bohemia.net/wiki/commandFire
 * https://community.bohemia.net/wiki/disableAI
 * https://community.bohemia.net/wiki/Combat_Modes
 * https://community.bohemia.net/wiki/setVehicleTiPars
 * https://community.bohemia.net/wiki/Arma_3:_Event_Handlers#FiredMan
 * https://community.bohemia.net/wiki/A3_Targeting_config_reference
 * https://community.bohemia.net/wiki/CfgWeapons_Config_Reference
 * https://community.bohemia.net/wiki/addWeapon
 * https://community.bohemia.net/wiki/createUnit_group
 * https://community.bohemia.net/wiki/setUnitCombatMode
 * https://community.bohemia.net/wiki/setCombatMode
 */

params [
    ["_acquisitionDuration", 60, [0]],
    ["_repetitions", 10, [0]],
    ["_postReadinessDuration", 15, [0]],
    ["_rescueDuration", 15, [0]],
    ["_groupContext", "ISOLATED", [""]],
    ["_scheduledContinuation", false, [false]]
];

_acquisitionDuration = (_acquisitionDuration max 30) min 120;
_repetitions = (round _repetitions max 2) min 20;
_postReadinessDuration = (_postReadinessDuration max 10) min 30;
_rescueDuration = (_rescueDuration max 10) min 30;
_groupContext = toUpperANSI _groupContext;

private _validContexts = ["ISOLATED", "PLAYER_LED"];
private _playerLed = _groupContext isEqualTo "PLAYER_LED";

private _prefix = "[BSKULLS][TITAN-TA] ACQUISITION_TEST";
private _announceFailure = {
    params ["_message"];
    diag_log format ["%1 ABORTED %2", _prefix, _message];
    if (hasInterface) then {
        systemChat format ["Launcher acquisition test aborted: %1", _message];
    };
    false
};

if !(_groupContext in _validContexts) exitWith {
    [format ["unknown group context %1", _groupContext]] call _announceFailure
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
if (_playerLed && {leader group player isNotEqualTo player}) exitWith {
    ["the local player must lead their group"] call _announceFailure
};
if (_playerLed && {!local group player}) exitWith {
    ["the local player's group must be local"] call _announceFailure
};

private _hawkinsClass = "B_PTbskull_Veh_Unit_Hawkins_blackops_04";
private _foxClass = "B_PTbskull_Veh_Unit_Fox_blackops_01";
private _targetClass = "O_MBT_02_cannon_F";
private _hawkinsPrimaryClass = "B_PTbskull_Wea_ar_06_spar17";
private _hawkinsPrimaryMagazine = "20Rnd_762x51_Mag";
private _foxPrimaryClass = "B_PTbskull_Wea_SMG_02_sting";
private _foxPrimaryMagazine = "30Rnd_9x21_Mag_SMG_02_Tracer_Green";
private _vanillaTitanClass = "launch_B_Titan_short_F";
private _vanillaTitanMagazine = "Titan_AT";
private _archangelClass = "B_PTbskull_Wea_law_02_titantop";
private _archangelMagazine = "Titan_AT_TOP_PLUS";
private _pcmlClass = "launch_NLAW_F";
private _pcmlMagazine = "NLAW_F";

// Arm fields: label, unit class, launcher, magazine, distance, primary,
// primary magazine, expected identity variable, production pairing.
private _arms = if (_playerLed) then {
    [
        [
            "hawkins-archangel",
            _hawkinsClass,
            _archangelClass,
            _archangelMagazine,
            1200,
            _hawkinsPrimaryClass,
            _hawkinsPrimaryMagazine,
            "BSkullHawkins",
            true
        ],
        [
            "hawkins-pcml-control",
            _hawkinsClass,
            _pcmlClass,
            _pcmlMagazine,
            600,
            _hawkinsPrimaryClass,
            _hawkinsPrimaryMagazine,
            "BSkullHawkins",
            false
        ],
        [
            "fox-pcml",
            _foxClass,
            _pcmlClass,
            _pcmlMagazine,
            600,
            _foxPrimaryClass,
            _foxPrimaryMagazine,
            "BSkullFox",
            true
        ]
    ]
} else {
    [
        [
            "hawkins-vanilla-titan",
            _hawkinsClass,
            _vanillaTitanClass,
            _vanillaTitanMagazine,
            1200,
            _hawkinsPrimaryClass,
            _hawkinsPrimaryMagazine,
            "BSkullHawkins",
            false
        ],
        [
            "hawkins-archangel",
            _hawkinsClass,
            _archangelClass,
            _archangelMagazine,
            1200,
            _hawkinsPrimaryClass,
            _hawkinsPrimaryMagazine,
            "BSkullHawkins",
            true
        ]
    ]
};

private _requiredClasses = [["CfgVehicles", _targetClass]];
{
    _x params [
        "_armLabel",
        "_unitClass",
        "_launcherClass",
        "_magazineClass",
        "_distance",
        "_primaryClass",
        "_primaryMagazine"
    ];
    _requiredClasses pushBackUnique ["CfgVehicles", _unitClass];
    _requiredClasses pushBackUnique ["CfgWeapons", _launcherClass];
    _requiredClasses pushBackUnique ["CfgMagazines", _magazineClass];
    _requiredClasses pushBackUnique ["CfgWeapons", _primaryClass];
    _requiredClasses pushBackUnique ["CfgMagazines", _primaryMagazine];
} forEach _arms;
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
    if (
        localNamespace getVariable [
            "bskulls_titanTopAttackAcquisitionTestRunning",
            false
        ]
        || {localNamespace getVariable [
            "bskulls_titanTopAttackRadioRoeTestRunning",
            false
        ]}
    ) then {
        ["a test is already running"] call _announceFailure;
    } else {
        [
            _acquisitionDuration,
            _repetitions,
            _postReadinessDuration,
            _rescueDuration,
            _groupContext,
            true
        ] spawn bskulls_fnc_titanTopAttackAcquisitionTest;
        systemChat format [
            "Launcher acquisition test scheduled: %1.",
            _groupContext
        ];
    };
    true
};

if (
    !_scheduledContinuation
    && {
        localNamespace getVariable [
            "bskulls_titanTopAttackAcquisitionTestRunning",
            false
        ]
        || {localNamespace getVariable [
            "bskulls_titanTopAttackRadioRoeTestRunning",
            false
        ]}
    }
) exitWith {
    ["a test is already running"] call _announceFailure
};

localNamespace setVariable [
    "bskulls_titanTopAttackAcquisitionTestRunning",
    true
];
localNamespace setVariable [
    "bskulls_titanTopAttackAcquisitionTestResult",
    []
];

private _testStartedAt = diag_tickTime;
private _bearing = getDir player;
private _playerPosition = getPosATL player;
private _playerGroup = group player;
private _originalPlayerGroupCombatMode = combatMode _playerGroup;
private _originalPlayerGroupAttackEnabled = attackEnabled _playerGroup;
private _shooterPosition = [
    (_playerPosition select 0) + (sin (_bearing + 90)) * 12,
    (_playerPosition select 1) + (cos (_bearing + 90)) * 12,
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
        ["unit", str _unit],
        ["unitClass", typeOf _unit],
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
        ["primaryWeapon", primaryWeapon _unit],
        ["primaryMagazine", primaryWeaponMagazine _unit],
        ["secondaryWeapon", secondaryWeapon _unit],
        ["secondaryMagazine", secondaryWeaponMagazine _unit],
        ["canFire", canFire _unit],
        ["unitReady", unitReady _unit],
        ["unitCombatMode", unitCombatMode _unit],
        ["groupCombatMode", combatMode group _unit],
        ["group", str group _unit],
        ["groupLeader", str leader group _unit],
        ["unitIsGroupLeader", leader group _unit isEqualTo _unit],
        ["groupHasPlayer", ((units group _unit) findIf {isPlayer _x}) >= 0],
        ["groupUnitCount", count units group _unit],
        ["isLocalPlayerGroup", group _unit isEqualTo _playerGroup],
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
    params ["_stateKey", "_launcherClass", "_ammoClass"];
    private _events = localNamespace getVariable [_stateKey, []];
    private _index = _events findIf {
        (_x param [1, "", [""]]) isEqualTo _launcherClass
        || {(_x param [4, "", [""]]) isEqualTo _ammoClass}
    };
    if (_index < 0) exitWith {-1};
    (_events select _index) param [0, -1, [0]]
};

private _armOrders = if (_playerLed) then {
    [
        [0, 1, 2],
        [1, 2, 0],
        [2, 0, 1],
        [2, 1, 0],
        [1, 0, 2],
        [0, 2, 1]
    ]
} else {
    [[0, 1], [1, 0]]
};

private _rangePreflight = _arms apply {
    _x params [
        "_armLabel",
        "_unitClass",
        "_launcherClass",
        "_magazineClass",
        "_distance"
    ];
    private _launcherConfig = configFile >> "CfgWeapons" >> _launcherClass;
    private _magazineConfig = configFile >> "CfgMagazines" >> _magazineClass;
    private _ammoClass = getText (_magazineConfig >> "ammo");
    private _ammoConfig = configFile >> "CfgAmmo" >> _ammoClass;
    private _lockMin = getNumber (
        _ammoConfig >> "missileLockMinDistance"
    );
    private _lockMax = getNumber (
        _ammoConfig >> "missileLockMaxDistance"
    );
    private _modeChecks = (getArray (_launcherConfig >> "modes")) apply {
        private _modeName = _x;
        private _modeConfig = _launcherConfig >> _modeName;
        private _minRange = getNumber (_modeConfig >> "minRange");
        private _maxRange = getNumber (_modeConfig >> "maxRange");
        [
            ["mode", _modeName],
            ["present", isClass _modeConfig],
            ["minRange", _minRange],
            ["minRangeProbab", getNumber (
                _modeConfig >> "minRangeProbab"
            )],
            ["midRange", getNumber (_modeConfig >> "midRange")],
            ["midRangeProbab", getNumber (
                _modeConfig >> "midRangeProbab"
            )],
            ["maxRange", _maxRange],
            ["maxRangeProbab", getNumber (
                _modeConfig >> "maxRangeProbab"
            )],
            [
                "distanceInsideAiRange",
                isClass _modeConfig
                && {_distance >= _minRange}
                && {_distance <= _maxRange}
            ]
        ]
    };
    private _validModes = _modeChecks select {
        [_x, "distanceInsideAiRange", false] call _value
    };
    private _lockRangeValid = _distance >= _lockMin
        && {_distance <= _lockMax};
    private _valid = isClass _launcherConfig
        && {isClass _magazineConfig}
        && {_ammoClass isNotEqualTo ""}
        && {isClass _ammoConfig}
        && {_lockRangeValid}
        && {_validModes isNotEqualTo []};
    [
        ["arm", _armLabel],
        ["unitClass", _unitClass],
        ["launcher", _launcherClass],
        ["magazine", _magazineClass],
        ["ammo", _ammoClass],
        ["distance", _distance],
        ["missileLockMinDistance", _lockMin],
        ["missileLockMaxDistance", _lockMax],
        ["distanceInsideLockRange", _lockRangeValid],
        ["modeChecks", _modeChecks],
        ["validModes", _validModes apply {
            [_x, "mode", ""] call _value
        }],
        ["valid", _valid]
    ]
};

private _loadoutPreflight = [];
{
    _x params [
        "_armLabel",
        "_unitClass",
        "_launcherClass",
        "_magazineClass",
        "_distance",
        "_primaryClass",
        "_primaryMagazine",
        "_identityVariable"
    ];
    private _probeGroup = createGroup [west, true];
    private _probe = _probeGroup createUnit [
        _unitClass,
        _shooterPosition,
        [],
        0,
        "NONE"
    ];
    private _identityDeadline = diag_tickTime + 15;
    waitUntil {
        uiSleep 0.05;
        (vehicleVarName _probe) isEqualTo _identityVariable
        || {diag_tickTime >= _identityDeadline}
        || {isNull _probe}
    };
    private _identityCompleted = !isNull _probe
        && {(vehicleVarName _probe) isEqualTo _identityVariable};

    removeAllWeapons _probe;
    removeAllMagazines _probe;
    removeAllItems _probe;
    removeAllAssignedItems _probe;
    _probe addMagazine _primaryMagazine;
    _probe addWeapon _primaryClass;
    _probe addMagazine _magazineClass;
    _probe addWeapon _launcherClass;
    _probe selectWeapon _primaryClass;

    private _loadoutDeadline = diag_tickTime + 3;
    waitUntil {
        uiSleep 0.05;
        (
            (primaryWeapon _probe) isEqualTo _primaryClass
            && {(secondaryWeapon _probe) isEqualTo _launcherClass}
            && {_magazineClass in secondaryWeaponMagazine _probe}
        )
        || {diag_tickTime >= _loadoutDeadline}
        || {isNull _probe}
    };
    uiSleep 0.25;
    private _primaryObserved = primaryWeapon _probe;
    private _secondaryObserved = secondaryWeapon _probe;
    private _secondaryMagazinesObserved = secondaryWeaponMagazine _probe;
    private _valid = _identityCompleted
        && {_primaryObserved isEqualTo _primaryClass}
        && {_secondaryObserved isEqualTo _launcherClass}
        && {_magazineClass in _secondaryMagazinesObserved};
    _loadoutPreflight pushBack [
        ["arm", _armLabel],
        ["identityCompleted", _identityCompleted],
        ["expectedIdentityVariable", _identityVariable],
        ["observedIdentityVariable", vehicleVarName _probe],
        ["expectedPrimary", _primaryClass],
        ["observedPrimary", _primaryObserved],
        ["expectedLauncher", _launcherClass],
        ["observedLauncher", _secondaryObserved],
        ["expectedMagazine", _magazineClass],
        ["observedSecondaryMagazines", _secondaryMagazinesObserved],
        ["valid", _valid]
    ];
    deleteVehicle _probe;
    deleteGroup _probeGroup;
    uiSleep 0.1;
} forEach _arms;

private _invalidRangePreflight = _rangePreflight select {
    !([_x, "valid", false] call _value)
};
private _invalidLoadoutPreflight = _loadoutPreflight select {
    !([_x, "valid", false] call _value)
};
if (
    _invalidRangePreflight isNotEqualTo []
    || {_invalidLoadoutPreflight isNotEqualTo []}
) exitWith {
    private _preflightReport = [
        ["report", "Black Skulls controlled launcher acquisition preflight"],
        ["schemaVersion", 7],
        ["tick", diag_tickTime],
        ["world", worldName],
        ["groupContext", _groupContext],
        ["rangeChecks", _rangePreflight],
        ["loadoutChecks", _loadoutPreflight],
        ["valid", false]
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackAcquisitionTestResult",
        _preflightReport
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackAcquisitionTestRunning",
        false
    ];
    diag_log format ["%1 PREFLIGHT_FAILED %2", _prefix, _preflightReport];
    copyToClipboard str _preflightReport;
    systemChat "Launcher acquisition preflight failed; report copied.";
    _preflightReport
};

diag_log format [
    "%1 PREFLIGHT_PASSED ranges=%2 loadouts=%3",
    _prefix,
    _rangePreflight,
    _loadoutPreflight
];
private _trialPlan = [];
for "_repetition" from 1 to _repetitions do {
    private _armOrder = _armOrders select (
        (_repetition - 1) mod count _armOrders
    );
    {
        _trialPlan pushBack [
            _repetition,
            _forEachIndex + 1,
            _arms select _x
        ];
    } forEach _armOrder;
};

private _results = [];
private _trialCount = count _trialPlan;

{
    _x params ["_repetition", "_orderPosition", "_arm"];
    _arm params [
        "_armLabel",
        "_unitClass",
        "_launcherClass",
        "_magazineClass",
        "_testDistance",
        "_primaryClass",
        "_primaryMagazine",
        "_identityVariable",
        "_productionPairing"
    ];
    private _rangePreflightIndex = _rangePreflight findIf {
        ([_x, "arm", ""] call _value) isEqualTo _armLabel
    };
    private _loadoutPreflightIndex = _loadoutPreflight findIf {
        ([_x, "arm", ""] call _value) isEqualTo _armLabel
    };
    private _configurationValid = _rangePreflightIndex >= 0
        && {_loadoutPreflightIndex >= 0}
        && {[
            _rangePreflight select _rangePreflightIndex,
            "valid",
            false
        ] call _value}
        && {[
            _loadoutPreflight select _loadoutPreflightIndex,
            "valid",
            false
        ] call _value};
    private _trialNumber = _forEachIndex + 1;
    private _magazineConfig = configFile >> "CfgMagazines" >> _magazineClass;
    private _ammoClass = getText (_magazineConfig >> "ammo");
    systemChat format [
        "Launcher test %1/%2: %3, repetition %4 (%5).",
        _trialNumber,
        _trialCount,
        _armLabel,
        _repetition,
        _groupContext
    ];

    private _group = if (_playerLed) then {
        _playerGroup
    } else {
        createGroup [west, true]
    };
    private _unit = _group createUnit [
        _unitClass,
        _shooterPosition,
        [],
        0,
        "NONE"
    ];
    _unit setDir _bearing;

    private _identityDeadline = diag_tickTime + 15;
    waitUntil {
        uiSleep 0.05;
        (vehicleVarName _unit) isEqualTo _identityVariable
        || {diag_tickTime >= _identityDeadline}
        || {isNull _unit}
    };
    private _identityCompleted = !isNull _unit
        && {(vehicleVarName _unit) isEqualTo _identityVariable};
    private _postIdentityUnitCombatMode = if (isNull _unit) then {
        "ERROR"
    } else {
        unitCombatMode _unit
    };

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
    _unit disableAI "AUTOCOMBAT";
    _group enableAttack true;
    _unit setCombatBehaviour "AWARE";
    _group setCombatMode "YELLOW";
    _unit setUnitCombatMode "YELLOW";

    removeAllWeapons _unit;
    removeAllMagazines _unit;
    removeAllItems _unit;
    removeAllAssignedItems _unit;
    _unit addMagazine _primaryMagazine;
    _unit addWeapon _primaryClass;
    _unit addMagazine _magazineClass;
    _unit addWeapon _launcherClass;
    _unit selectWeapon _primaryClass;

    private _setupDeadline = diag_tickTime + 3;
    waitUntil {
        uiSleep 0.05;
        (
            (primaryWeapon _unit) isEqualTo _primaryClass
            && {(secondaryWeapon _unit) isEqualTo _launcherClass}
            && {_magazineClass in secondaryWeaponMagazine _unit}
            && {(combatBehaviour _unit) isEqualTo "AWARE"}
            && {(behaviour _unit) isEqualTo "AWARE"}
            && {!(_unit checkAIFeature "AUTOCOMBAT")}
            && {(unitCombatMode _unit) isEqualTo "YELLOW"}
            && {(combatMode _group) isEqualTo "YELLOW"}
            && {!_playerLed || {
                group _unit isEqualTo _playerGroup
                && {leader _group isEqualTo player}
            }}
        )
        || {diag_tickTime >= _setupDeadline}
        || {isNull _unit}
    };
    private _setupApplied = !isNull _unit
        && {(primaryWeapon _unit) isEqualTo _primaryClass}
        && {(secondaryWeapon _unit) isEqualTo _launcherClass}
        && {_magazineClass in secondaryWeaponMagazine _unit}
        && {(combatBehaviour _unit) isEqualTo "AWARE"}
        && {(behaviour _unit) isEqualTo "AWARE"}
        && {!(_unit checkAIFeature "AUTOCOMBAT")}
        && {(unitCombatMode _unit) isEqualTo "YELLOW"}
        && {(combatMode _group) isEqualTo "YELLOW"}
        && {!_playerLed || {
            group _unit isEqualTo _playerGroup
            && {leader _group isEqualTo player}
        }};

    private _stateKey = format [
        "bskulls_titanTopAttackAcquisitionTrial_%1_%2",
        round (_testStartedAt * 1000),
        _trialNumber
    ];
    localNamespace setVariable [_stateKey, []];
    _unit setVariable [
        "bskulls_titanTopAttackAcquisitionStateKey",
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
            "bskulls_titanTopAttackAcquisitionStateKey",
            ""
        ];
        private _events = localNamespace getVariable [_key, []];
        private _focusTarget = _unit getVariable [
            "bskulls_titanTopAttackAcquisitionTarget",
            objNull
        ];
        private _knowledge = if (isNull _focusTarget) then {[]} else {
            _unit targetKnowledge _focusTarget
        };
        _events pushBack [
            diag_tickTime,
            _weapon,
            _muzzle,
            _mode,
            _ammo,
            _magazine,
            str _projectile,
            str _vehicle,
            [
                ["target", str _focusTarget],
                [
                    "knownByUnit",
                    _knowledge param [1, false, [false]]
                ],
                ["knowsAbout", if (isNull _focusTarget) then {-1} else {
                    _unit knowsAbout _focusTarget
                }],
                ["assignedTarget", str assignedTarget _unit],
                ["attackTarget", str getAttackTarget _unit],
                ["currentWeapon", currentWeapon _unit],
                ["currentMode", currentWeaponMode _unit],
                ["weaponState", weaponState _unit],
                ["secondaryMagazine", secondaryWeaponMagazine _unit],
                ["unitCombatMode", unitCombatMode _unit],
                ["groupCombatMode", combatMode group _unit]
            ]
        ];
        if ((count _events) > 30) then {
            _events deleteAt 0;
        };
        localNamespace setVariable [_key, _events];
        if (!isNull _projectile) then {
            deleteVehicle _projectile;
        };
    }];

    private _caseStartedAt = diag_tickTime;
    private _targetPosition = [
        (_shooterPosition select 0) + (sin _bearing) * _testDistance,
        (_shooterPosition select 1) + (cos _bearing) * _testDistance,
        0
    ];
    private _target = createVehicle [
        _targetClass,
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
    _unit setVariable [
        "bskulls_titanTopAttackAcquisitionTarget",
        _target,
        false
    ];
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
    private _firstReadiness = -1;
    private _readinessAt = -1;
    private _readinessSnapshot = [];
    private _behaviourCompliant = _identityCompleted && {_setupApplied};
    private _controlsCompliant = true;
    private _transitions = [];
    private _lastSignature = [];
    private _lastPeriodicSampleAt = -1e10;
    private _initialSnapshot = [];
    private _acquisitionDeadline = diag_tickTime + _acquisitionDuration;
    private _naturalDeadline = -1;

    waitUntil {
        uiSleep 0.25;
        _target engineOn true;
        _target setVehicleTIPars [1, 1, 1];
        _target setVariable ["dapsActive", false, true];

        private _phase = [
            "acquisition",
            "post-readiness"
        ] select (_readinessAt >= 0);
        private _snapshot = [
            _unit,
            _target,
            _caseStartedAt,
            _phase
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
        private _launcherLoaded = _magazineClass in (
            [_snapshot, "secondaryMagazine", []] call _value
        );
        private _ready = _known
            && {_attack || {_assigned}}
            && {_selected}
            && {_launcherLoaded};
        private _effectiveBehaviour = [
            _snapshot,
            "effectiveBehaviour",
            ""
        ] call _value;
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
        if (
            _unitBehaviour isNotEqualTo "AWARE"
            || {_effectiveBehaviour isNotEqualTo "AWARE"}
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
            || {_playerLed && {
                group _unit isNotEqualTo _playerGroup
                || {leader _group isNotEqualTo player}
            }}
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
        if (_readinessAt < 0 && {_ready}) then {
            _firstReadiness = _elapsed;
            _readinessAt = diag_tickTime;
            _naturalDeadline = _readinessAt + _postReadinessDuration;
            _readinessSnapshot = [
                _unit,
                _target,
                _caseStartedAt,
                "readiness"
            ] call _describeSnapshot;
        };

        private _signature = [
            _known,
            _attack,
            _assigned,
            _selected,
            _launcherLoaded,
            _ready,
            [_snapshot, "currentCommand", ""] call _value,
            [_snapshot, "currentWeapon", ""] call _value,
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

        ([_stateKey, _launcherClass, _ammoClass] call
            _firstExpectedFire) >= 0
        || {
            _readinessAt < 0
            && {diag_tickTime >= _acquisitionDeadline}
        }
        || {
            _readinessAt >= 0
            && {diag_tickTime >= _naturalDeadline}
        }
        || {isNull _unit}
        || {!alive _unit}
        || {isNull _target}
    };

    private _naturalPhaseEndedAt = diag_tickTime;
    private _readinessObservedBeforeFire = _readinessAt >= 0;
    private _naturalFinalSnapshot = if (
        isNull _unit || {isNull _target}
    ) then {[]} else {
        [
            _unit,
            _target,
            _caseStartedAt,
            [
                "acquisition-end",
                "post-readiness-end"
            ] select _readinessObservedBeforeFire
        ] call _describeSnapshot
    };
    private _naturalFireTick = [
        _stateKey,
        _launcherClass,
        _ammoClass
    ] call _firstExpectedFire;
    private _naturalFired = _naturalFireTick >= 0;
    if (!_naturalFired && {!isNull _unit} && {alive _unit}) then {
        _naturalFireTick = [
            _stateKey,
            _launcherClass,
            _ammoClass
        ] call _firstExpectedFire;
        _naturalFired = _naturalFireTick >= 0;
    };
    private _readinessCompleted = _readinessObservedBeforeFire
        || {_naturalFired};
    private _readinessEvidence = if (_readinessObservedBeforeFire) then {
        "snapshot-before-fire"
    } else {
        ["none", "expected-fired-event"] select _naturalFired
    };
    private _acquisitionTimedOut = !_readinessCompleted
        && {_naturalPhaseEndedAt >= _acquisitionDeadline};
    private _postReadinessTimedOut = _readinessObservedBeforeFire
        && {_naturalPhaseEndedAt >= _naturalDeadline};
    private _rescueOrderAt = -1;
    private _rescueFireTick = -1;
    private _rescueFinalSnapshot = [];

    private _naturalPhaseEndReason = if (_naturalFired) then {
        "natural-fired"
    } else {
        if (
            isNull _unit
            || {!alive _unit}
            || {isNull _target}
        ) then {
            "entity-invalid"
        } else {
            if (_acquisitionTimedOut) then {
                "acquisition-timeout"
            } else {
                [
                    "unknown",
                    "post-readiness-timeout"
                ] select _postReadinessTimedOut
            }
        }
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
                (combatBehaviour _unit) isNotEqualTo "AWARE"
                || {(behaviour _unit) isNotEqualTo "AWARE"}
            ) then {
                _behaviourCompliant = false;
            };
            if (
                (unitCombatMode _unit) isNotEqualTo "YELLOW"
                || {(combatMode _group) isNotEqualTo "YELLOW"}
                || {_unit checkAIFeature "AUTOCOMBAT"}
                || {_playerLed && {
                    group _unit isNotEqualTo _playerGroup
                    || {leader _group isNotEqualTo player}
                }}
                || {!isEngineOn _target}
                || {_target getVariable ["dapsActive", true]}
            ) then {
                _controlsCompliant = false;
            };
            _rescueFireTick = [
                _stateKey,
                _launcherClass,
                _ammoClass
            ] call _firstExpectedFire;
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
    private _otherWeaponFired = (_events findIf {
        (_x param [1, "", [""]]) isNotEqualTo _launcherClass
        && {(_x param [4, "", [""]]) isNotEqualTo _ammoClass}
    }) >= 0;
    private _outcome = if (!_configurationValid) then {
        "configuration-invalid"
    } else {
        if (!_identityCompleted) then {
            "identity-not-completed"
        } else {
            if (!_setupApplied) then {
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
                            if (!_readinessCompleted) then {
                                [
                                    "acquisition-not-completed",
                                    "acquisition-not-completed-rescue-fired"
                                ] select _rescueFired
                            } else {
                                [
                                    "post-readiness-no-fire",
                                    "post-readiness-no-fire-rescue-fired"
                                ] select _rescueFired
                            }
                        }
                    }
                }
            }
        }
    };

    private _trialResult = [
        ["trial", _trialNumber],
        ["repetition", _repetition],
        ["orderPosition", _orderPosition],
        ["arm", _armLabel],
        ["unitClass", _unitClass],
        ["configurationValid", _configurationValid],
        ["identityRequired", true],
        ["identityCompleted", _identityCompleted],
        ["identityVariable", _identityVariable],
        ["postIdentityUnitCombatMode", _postIdentityUnitCombatMode],
        ["productionPairing", _productionPairing],
        ["groupContext", _groupContext],
        ["playerWasGroupLeader", leader _group isEqualTo player],
        ["setupApplied", _setupApplied],
        ["behaviourCompliant", _behaviourCompliant],
        ["controlsCompliant", _controlsCompliant],
        ["launcher", _launcherClass],
        ["magazine", _magazineClass],
        ["ammo", _ammoClass],
        ["requestedDistance", _testDistance],
        ["readinessCompleted", _readinessCompleted],
        [
            "readinessObservedBeforeFire",
            _readinessObservedBeforeFire
        ],
        ["readinessEvidence", _readinessEvidence],
        ["naturalFireEligible", _readinessCompleted],
        ["acquisitionTimedOut", _acquisitionTimedOut],
        ["postReadinessTimedOut", _postReadinessTimedOut],
        ["naturalPhaseEndReason", _naturalPhaseEndReason],
        ["timings", [
            ["knownByUnit", _firstKnown],
            ["attackTarget", _firstAttackTarget],
            ["assigned", _firstAssigned],
            ["launcherSelected", _firstSelected],
            ["readiness", _firstReadiness],
            [
                "readinessUpperBound",
                if (_readinessObservedBeforeFire) then {
                    _firstReadiness
                } else {
                    if (_naturalFireTick < 0) then {-1} else {
                        _naturalFireTick - _caseStartedAt
                    }
                }
            ],
            [
                "postReadinessDeadline",
                if (_naturalDeadline < 0) then {-1} else {
                    _naturalDeadline - _caseStartedAt
                }
            ],
            [
                "naturalFire",
                if (_naturalFireTick < 0) then {-1} else {
                    _naturalFireTick - _caseStartedAt
                }
            ],
            [
                "naturalFireAfterReadiness",
                if (
                    _naturalFireTick < 0
                    || {_readinessAt < 0}
                ) then {-1} else {
                    _naturalFireTick - _readinessAt
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
        ["otherWeaponFired", _otherWeaponFired],
        ["geometryValid", _geometryValid],
        ["firedEvents", _events],
        ["initialSnapshot", _initialSnapshot],
        ["readinessSnapshot", _readinessSnapshot],
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
        _unit setVariable [
            "bskulls_titanTopAttackAcquisitionTarget",
            nil,
            false
        ];
    };
    localNamespace setVariable [_stateKey, nil];
    deleteVehicle _unit;
    if (!_playerLed) then {
        deleteGroup _group;
    };
    deleteVehicleCrew _target;
    deleteVehicle _target;
    deleteGroup _targetGroup;
    uiSleep 1;
} forEach _trialPlan;

private _isClean = {
    params ["_case"];
    _case isNotEqualTo []
    && {[_case, "configurationValid", false] call _value}
    && {[_case, "identityCompleted", false] call _value}
    && {[_case, "setupApplied", false] call _value}
    && {[_case, "behaviourCompliant", false] call _value}
    && {[_case, "controlsCompliant", false] call _value}
    && {[_case, "geometryValid", false] call _value}
};

private _summaries = [];
{
    private _armLabel = _x select 0;
    private _cases = _results select {
        ([_x, "arm", ""] call _value) isEqualTo _armLabel
    };
    private _cleanCases = _cases select {[_x] call _isClean};
    private _knownCases = _cleanCases select {
        private _timings = [_x, "timings", []] call _value;
        ([_timings, "knownByUnit", -1] call _value) >= 0
    };
    private _selectedCases = _cleanCases select {
        private _timings = [_x, "timings", []] call _value;
        ([_timings, "launcherSelected", -1] call _value) >= 0
    };
    private _readyCases = _cleanCases select {
        [_x, "readinessCompleted", false] call _value
    };
    private _observedReadyCases = _cleanCases select {
        [_x, "readinessObservedBeforeFire", false] call _value
    };
    private _fireEventReadyCases = _cleanCases select {
        ([_x, "readinessEvidence", ""] call _value)
            isEqualTo "expected-fired-event"
    };
    private _naturalEligibleCases = _cleanCases select {
        [_x, "naturalFireEligible", false] call _value
    };
    private _acquisitionTimeoutCases = _cleanCases select {
        [_x, "acquisitionTimedOut", false] call _value
    };
    private _naturalCases = _naturalEligibleCases select {
        [_x, "naturalFired", false] call _value
    };
    private _rescueCases = _cleanCases select {
        [_x, "rescueFired", false] call _value
    };
    private _postReadinessNoFireCases = _naturalEligibleCases select {
        !([_x, "naturalFired", false] call _value)
    };
    _summaries pushBack [
        ["arm", _armLabel],
        ["trials", count _cases],
        ["cleanTrials", count _cleanCases],
        ["excludedTrials", (count _cases) - (count _cleanCases)],
        ["targetKnown", count _knownCases],
        ["launcherSelected", count _selectedCases],
        ["readinessCompleted", count _readyCases],
        [
            "readinessObservedBeforeFire",
            count _observedReadyCases
        ],
        [
            "readinessEstablishedByFireEvent",
            count _fireEventReadyCases
        ],
        ["acquisitionTimedOut", count _acquisitionTimeoutCases],
        ["naturalFireEligible", count _naturalEligibleCases],
        ["naturalFired", count _naturalCases],
        [
            "naturalFireRateAfterReadiness",
            if (_naturalEligibleCases isEqualTo []) then {-1} else {
                (count _naturalCases) / (count _naturalEligibleCases)
            }
        ],
        ["postReadinessNaturalNoFire", count _postReadinessNoFireCases],
        ["orderedRescueFired", count _rescueCases],
        [
            "orderedRescueEligible",
            (count _cleanCases) - (count _naturalCases)
        ]
    ];
} forEach _arms;

private _makeComparison = {
    params ["_name", "_leftLabel", "_rightLabel"];
    private _pairs = [];
    for "_repetition" from 1 to _repetitions do {
        private _leftIndex = _results findIf {
            ([_x, "repetition", -1] call _value) isEqualTo _repetition
            && {([_x, "arm", ""] call _value) isEqualTo _leftLabel}
        };
        private _rightIndex = _results findIf {
            ([_x, "repetition", -1] call _value) isEqualTo _repetition
            && {([_x, "arm", ""] call _value) isEqualTo _rightLabel}
        };
        private _leftCase = if (_leftIndex < 0) then {[]} else {
            _results select _leftIndex
        };
        private _rightCase = if (_rightIndex < 0) then {[]} else {
            _results select _rightIndex
        };
        private _leftClean = [_leftCase] call _isClean;
        private _rightClean = [_rightCase] call _isClean;
        private _leftReady = [
            _leftCase,
            "readinessCompleted",
            false
        ] call _value;
        private _rightReady = [
            _rightCase,
            "readinessCompleted",
            false
        ] call _value;
        private _leftReadyObserved = [
            _leftCase,
            "readinessObservedBeforeFire",
            false
        ] call _value;
        private _rightReadyObserved = [
            _rightCase,
            "readinessObservedBeforeFire",
            false
        ] call _value;
        private _leftEligible = [
            _leftCase,
            "naturalFireEligible",
            false
        ] call _value;
        private _rightEligible = [
            _rightCase,
            "naturalFireEligible",
            false
        ] call _value;
        _pairs pushBack [
            ["repetition", _repetition],
            ["clean", _leftClean && {_rightClean}],
            [
                "fireComparable",
                _leftClean
                && {_rightClean}
                && {_leftEligible}
                && {_rightEligible}
            ],
            ["leftTrial", [_leftCase, "trial", -1] call _value],
            ["rightTrial", [_rightCase, "trial", -1] call _value],
            ["leftReadinessCompleted", _leftReady],
            ["rightReadinessCompleted", _rightReady],
            ["leftReadinessObservedBeforeFire", _leftReadyObserved],
            ["rightReadinessObservedBeforeFire", _rightReadyObserved],
            [
                "leftReadinessEvidence",
                [_leftCase, "readinessEvidence", "none"] call _value
            ],
            [
                "rightReadinessEvidence",
                [_rightCase, "readinessEvidence", "none"] call _value
            ],
            ["leftNaturalFireEligible", _leftEligible],
            ["rightNaturalFireEligible", _rightEligible],
            [
                "leftNaturalFired",
                [_leftCase, "naturalFired", false] call _value
            ],
            [
                "rightNaturalFired",
                [_rightCase, "naturalFired", false] call _value
            ],
            ["leftOutcome", [_leftCase, "outcome", "missing"] call _value],
            [
                "rightOutcome",
                [_rightCase, "outcome", "missing"] call _value
            ]
        ];
    };
    private _cleanPairs = _pairs select {
        [_x, "clean", false] call _value
    };
    private _comparablePairs = _pairs select {
        [_x, "fireComparable", false] call _value
    };
    private _leftOnly = _comparablePairs select {
        [_x, "leftNaturalFired", false] call _value
        && {!([_x, "rightNaturalFired", false] call _value)}
    };
    private _rightOnly = _comparablePairs select {
        !([_x, "leftNaturalFired", false] call _value)
        && {[_x, "rightNaturalFired", false] call _value}
    };
    private _both = _comparablePairs select {
        [_x, "leftNaturalFired", false] call _value
        && {[_x, "rightNaturalFired", false] call _value}
    };
    private _neither = _comparablePairs select {
        !([_x, "leftNaturalFired", false] call _value)
        && {!([_x, "rightNaturalFired", false] call _value)}
    };
    [
        ["comparison", _name],
        ["leftArm", _leftLabel],
        ["rightArm", _rightLabel],
        ["pairs", count _pairs],
        ["cleanPairs", count _cleanPairs],
        ["fireComparablePairs", count _comparablePairs],
        ["leftOnlyFired", count _leftOnly],
        ["rightOnlyFired", count _rightOnly],
        ["bothFired", count _both],
        ["neitherFired", count _neither],
        ["pairDetails", _pairs]
    ]
};

private _comparisonSpecs = if (_playerLed) then {
    [[
        "pcml-operator",
        "hawkins-pcml-control",
        "fox-pcml"
    ]]
} else {
    [[
        "launcher",
        "hawkins-vanilla-titan",
        "hawkins-archangel"
    ]]
};
private _comparisons = _comparisonSpecs apply {
    _x call _makeComparison
};

private _armConfigs = _arms apply {
    _x params [
        "_armLabel",
        "_unitClass",
        "_launcherClass",
        "_magazineClass",
        "_distance",
        "_primaryClass",
        "_primaryMagazine",
        "_identityVariable",
        "_productionPairing"
    ];
    private _launcherConfig = configFile >> "CfgWeapons" >> _launcherClass;
    private _magazineConfig = configFile >> "CfgMagazines" >> _magazineClass;
    private _ammoClass = getText (_magazineConfig >> "ammo");
    private _ammoConfig = configFile >> "CfgAmmo" >> _ammoClass;
    [
        ["arm", _armLabel],
        ["unitClass", _unitClass],
        ["launcher", _launcherClass],
        ["magazine", _magazineClass],
        ["ammo", _ammoClass],
        ["distance", _distance],
        ["primaryWeapon", _primaryClass],
        ["primaryMagazine", _primaryMagazine],
        ["identityVariable", _identityVariable],
        ["productionPairing", _productionPairing],
        ["launcherPresent", isClass _launcherConfig],
        ["magazinePresent", isClass _magazineConfig],
        ["ammoPresent", isClass _ammoConfig],
        ["modes", getArray (_launcherConfig >> "modes")],
        ["canLock", getNumber (_launcherConfig >> "canLock")],
        ["weaponLockSystem", getNumber (
            _launcherConfig >> "weaponLockSystem"
        )],
        ["aiAmmoUsageFlags", getNumber (
            _ammoConfig >> "aiAmmoUsageFlags"
        )],
        ["irLock", getNumber (_ammoConfig >> "irLock")],
        ["airLock", getNumber (_ammoConfig >> "airLock")],
        ["missileLockMinDistance", getNumber (
            _ammoConfig >> "missileLockMinDistance"
        )],
        ["missileLockMaxDistance", getNumber (
            _ammoConfig >> "missileLockMaxDistance"
        )]
    ]
};

private _playerGroupBeforeRestore = [
    ["group", str _playerGroup],
    ["leader", str leader _playerGroup],
    ["unitCount", count units _playerGroup],
    ["combatMode", combatMode _playerGroup],
    ["attackEnabled", attackEnabled _playerGroup]
];
if (_playerLed) then {
    _playerGroup setCombatMode _originalPlayerGroupCombatMode;
    _playerGroup enableAttack _originalPlayerGroupAttackEnabled;
};
private _playerGroupAfterRestore = [
    ["group", str _playerGroup],
    ["leader", str leader _playerGroup],
    ["unitCount", count units _playerGroup],
    ["combatMode", combatMode _playerGroup],
    ["attackEnabled", attackEnabled _playerGroup]
];

private _report = [
    ["report", "Black Skulls controlled launcher acquisition test"],
    ["schemaVersion", 7],
    ["tick", diag_tickTime],
    ["world", worldName],
    ["machine", [clientOwner, isServer, hasInterface]],
    ["conditions", [
        ["arms", _arms apply {_x select 0}],
        ["comparisons", _comparisonSpecs],
        ["groupContext", _groupContext],
        ["playerLed", _playerLed],
        ["playerWasRequiredLeader", _playerLed],
        ["radioOpenFireEmulated", false],
        ["roeNormalization", "scripted unit/group YELLOW"],
        ["distancesByArm", _arms apply {[_x select 0, _x select 4]}],
        ["acquisitionDuration", _acquisitionDuration],
        ["postReadinessDuration", _postReadinessDuration],
        ["readinessRequires", [
            "known-by-unit",
            "assigned-or-attack-target",
            "launcher-selected",
            "launcher-magazine-loaded"
        ]],
        [
            "readinessEvidencePolicy",
            "snapshot-before-fire or expected FiredMan upper bound"
        ],
        ["repetitionsPerArm", _repetitions],
        ["rescueDuration", _rescueDuration],
        ["armOrderCounterbalanced", true],
        ["freshShooterPerTrial", true],
        ["freshTargetPerTrial", true],
        ["preflightRequired", true],
        ["preflightPassed", true],
        ["normalizedOneRoundLoadouts", true],
        ["individualBehaviour", "AWARE"],
        ["individualBehaviourVerifiedContinuously", true],
        ["effectiveBehaviourVerifiedContinuously", true],
        ["groupCombatBehaviour", "observed-not-constrained"],
        ["autocombatDisabled", true],
        ["combatMode", "YELLOW"],
        ["targetClass", _targetClass],
        ["targetTiPars", [1, 1, 1]],
        ["projectilesDeleted", true],
        ["targetDamageDisabled", true],
        ["dapsForcedInactive", true],
        ["preExistingOtherUnits", count _preExistingUnits],
        ["preExistingVehicles", count _preExistingVehicles]
    ]],
    ["playerGroup", [
        ["originalCombatMode", _originalPlayerGroupCombatMode],
        ["originalAttackEnabled", _originalPlayerGroupAttackEnabled],
        ["beforeRestore", _playerGroupBeforeRestore],
        ["afterRestore", _playerGroupAfterRestore]
    ]],
    ["rangePreflight", _rangePreflight],
    ["loadoutPreflight", _loadoutPreflight],
    ["armConfigs", _armConfigs],
    ["summary", _summaries],
    ["comparisons", _comparisons],
    ["trialCount", count _results],
    ["elapsed", diag_tickTime - _testStartedAt],
    ["trials", _results]
];

localNamespace setVariable [
    "bskulls_titanTopAttackAcquisitionTestResult",
    _report
];
localNamespace setVariable [
    "bskulls_titanTopAttackAcquisitionTestRunning",
    false
];
diag_log format ["%1 FINAL %2", _prefix, _report];
copyToClipboard str _report;
systemChat format [
    "Launcher acquisition test complete: %1 trials (%2). Report copied.",
    count _results,
    _groupContext
];

_report
