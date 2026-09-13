/*
 * Run a controlled, non-gameplay Archangel-versus-vanilla-Titan AI test.
 * The test requires an otherwise-empty VR mission containing one on-foot
 * player. It creates a fresh hot, invulnerable T-100 for every trial and gives
 * fresh Hawkins units either the production Archangel or vanilla launchers.
 * Each weapon gets natural-acquisition and explicit radio-order trials. PCML
 * controls at 600 m and 900 m separately expose its documented/configured
 * range boundary without attributing that boundary to Archangel behavior.
 * Projectiles are deleted immediately and all temporary entities are removed.
 *
 * Run from Local Exec:
 *   [20, 2] call bskulls_fnc_titanTopAttackAcquisitionTest;
 *
 * The function moves scheduled work into spawn when called unscheduled. Do not
 * save during the roughly four-minute test. Results are logged, copied to the
 * clipboard, and retained in localNamespace for the normal debug report.
 *
 * Official command semantics used by the test:
 * https://community.bohemia.net/wiki/targetKnowledge
 * https://community.bohemia.net/wiki/commandTarget
 * https://community.bohemia.net/wiki/commandFire
 * https://community.bohemia.net/wiki/Arma_3:_Event_Handlers#FiredMan
 * https://community.bohemia.net/wiki/Combat_Modes
 * https://community.bohemia.net/wiki/setVehicleTiPars
 */

params [
    ["_trialDuration", 20, [0]],
    ["_repetitions", 2, [0]],
    ["_scheduledContinuation", false, [false]]
];

_trialDuration = (_trialDuration max 10) min 60;
_repetitions = (round _repetitions max 1) min 5;

private _prefix = "[BSKULLS][TITAN-TA] ACQUISITION_TEST";
private _announceFailure = {
    params ["_message"];
    diag_log format ["%1 ABORTED %2", _prefix, _message];
    if (hasInterface) then {
        systemChat format ["Archangel A/B test aborted: %1", _message];
    };
    false
};

if (!hasInterface || {isNull player}) exitWith {
    ["no local player interface"] call _announceFailure
};
if (!isServer) exitWith {
    ["run Local Exec as the host in a single-player or hosted VR mission"] call _announceFailure
};
if ((toLowerANSI worldName) isNotEqualTo "vr") exitWith {
    ["the controlled baseline is restricted to the VR terrain"] call _announceFailure
};
if ((vehicle player) isNotEqualTo player) exitWith {
    ["the player must be on foot"] call _announceFailure
};

private _requiredClasses = [
    ["CfgVehicles", "B_PTbskull_Veh_Unit_Hawkins_blackops_04"],
    ["CfgVehicles", "O_MBT_02_cannon_F"],
    ["CfgWeapons", "B_PTbskull_Wea_law_02_titantop"],
    ["CfgWeapons", "launch_B_Titan_short_F"],
    ["CfgWeapons", "launch_NLAW_F"],
    ["CfgMagazines", "Titan_AT_TOP_PLUS"],
    ["CfgMagazines", "Titan_AT"],
    ["CfgMagazines", "NLAW_F"]
];
private _missingClasses = _requiredClasses select {
    !isClass (configFile >> (_x select 0) >> (_x select 1))
};
if (_missingClasses isNotEqualTo []) exitWith {
    [format ["missing required classes %1", _missingClasses]] call _announceFailure
};

private _preExistingUnits = allUnits select {_x isNotEqualTo player};
private _preExistingVehicles = vehicles select {_x isNotEqualTo vehicle player};
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
        "bskulls_titanTopAttackAcquisitionTestRunning",
        false
    ]) then {
        ["a test is already running"] call _announceFailure;
    } else {
        [_trialDuration, _repetitions, true] spawn
            bskulls_fnc_titanTopAttackAcquisitionTest;
        systemChat "Archangel A/B test scheduled.";
    };
    true
};

if (
    !_scheduledContinuation
    && {localNamespace getVariable [
        "bskulls_titanTopAttackAcquisitionTestRunning",
        false
    ]}
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
private _shooterPosition = [
    (_playerPosition select 0) + (sin (_bearing + 90)) * 12,
    (_playerPosition select 1) + (cos (_bearing + 90)) * 12,
    0
];
private _targetPositionForDistance = {
    params ["_distance"];
    [
        (_shooterPosition select 0) + (sin _bearing) * _distance,
        (_shooterPosition select 1) + (cos _bearing) * _distance,
        0
    ]
};

private _describeSnapshot = {
    params ["_unit", "_target", "_caseStartedAt"];

    private _knowledge = _unit targetKnowledge _target;
    private _weaponState = weaponState _unit;
    private _eyePositionASL = eyePos _unit;
    private _targetPositionASL = aimPos _target;
    [
        ["elapsed", diag_tickTime - _caseStartedAt],
        ["knownByGroup", _knowledge param [0, false, [false]]],
        ["knownByUnit", _knowledge param [1, false, [false]]],
        ["lastSeen", _knowledge param [2, -1, [0]]],
        ["knowledgeSide", str (_knowledge param [4, sideUnknown])],
        ["knowledgeError", _knowledge param [5, -1, [0]]],
        ["knowsAbout", _unit knowsAbout _target],
        ["assignedTarget", str assignedTarget _unit],
        ["attackTarget", str getAttackTarget _unit],
        ["currentCommand", currentCommand _unit],
        ["currentWeapon", currentWeapon _unit],
        ["currentMuzzle", currentMuzzle _unit],
        ["currentMode", currentWeaponMode _unit],
        ["weaponState", _weaponState],
        ["secondaryWeapon", secondaryWeapon _unit],
        ["secondaryMagazine", secondaryWeaponMagazine _unit],
        ["canFire", canFire _unit],
        ["unitReady", unitReady _unit],
        ["unitCombatMode", unitCombatMode _unit],
        ["groupCombatMode", combatMode group _unit],
        ["behaviour", behaviour _unit],
        ["combatBehaviour", combatBehaviour _unit],
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

private _snapshotValue = {
    params ["_snapshot", "_name", "_default"];
    private _index = _snapshot findIf {
        (_x param [0, "", [""]]) isEqualTo _name
    };
    if (_index < 0) exitWith {_default};
    (_snapshot select _index) param [1, _default]
};

private _weapons = [
    [
        "archangel",
        "B_PTbskull_Wea_law_02_titantop",
        "Titan_AT_TOP_PLUS",
        1200
    ],
    [
        "vanilla-titan",
        "launch_B_Titan_short_F",
        "Titan_AT",
        1200
    ]
];
private _pcmlControls = [
    ["pcml-600m", "launch_NLAW_F", "NLAW_F", 600],
    ["pcml-900m", "launch_NLAW_F", "NLAW_F", 900]
];
private _trialPlan = [];
for "_repetition" from 1 to _repetitions do {
    private _orderedWeapons = +_weapons;
    if ((_repetition mod 2) isEqualTo 0) then {
        reverse _orderedWeapons;
    };
    {
        _trialPlan pushBack [_repetition, "natural", _x];
    } forEach _orderedWeapons;
    {
        _trialPlan pushBack [_repetition, "radio-order", _x];
    } forEach _orderedWeapons;
};
{
    _trialPlan pushBack [1, "natural", _x];
    _trialPlan pushBack [1, "radio-order", _x];
} forEach _pcmlControls;

private _results = [];
private _trialCount = count _trialPlan;
{
    _x params ["_repetition", "_trialType", "_weaponSpec"];
    _weaponSpec params [
        "_weaponLabel",
        "_launcherClass",
        "_magazineClass",
        "_testDistance"
    ];
    private _trialNumber = _forEachIndex + 1;
    private _magazineConfig = configFile >> "CfgMagazines" >> _magazineClass;
    private _launcherConfig = configFile >> "CfgWeapons" >> _launcherClass;
    private _ammoClass = getText (_magazineConfig >> "ammo");
    private _ammoConfig = configFile >> "CfgAmmo" >> _ammoClass;

    systemChat format [
        "Archangel A/B test %1/%2: %3, %4, repetition %5.",
        _trialNumber,
        _trialCount,
        _weaponLabel,
        _trialType,
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
    _unit setSkill 1;
    {
        _unit enableAI _x;
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
    _group setCombatMode "YELLOW";
    _group enableAttack true;
    _unit setUnitCombatMode "YELLOW";
    _unit setCombatBehaviour "AWARE";

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
    _unit setVariable [
        "bskulls_titanTopAttackAcquisitionExpectedLauncher",
        _launcherClass,
        false
    ];
    _unit setVariable [
        "bskulls_titanTopAttackAcquisitionExpectedAmmo",
        _ammoClass,
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
        if ((count _events) > 20) then {
            _events deleteAt 0;
        };
        localNamespace setVariable [_key, _events];

        private _expectedLauncher = _unit getVariable [
            "bskulls_titanTopAttackAcquisitionExpectedLauncher",
            ""
        ];
        private _expectedAmmo = _unit getVariable [
            "bskulls_titanTopAttackAcquisitionExpectedAmmo",
            ""
        ];
        if (
            _weapon isEqualTo _expectedLauncher
            || {_ammo isEqualTo _expectedAmmo}
        ) then {
            (group _unit) setCombatMode "BLUE";
            _unit setUnitCombatMode "BLUE";
        };
        if (!isNull _projectile) then {
            deleteVehicle _projectile;
        };
    }];

    // The target does not exist while the shooter is initialized, preventing
    // pre-trial knowledge or a shot before timing begins. A full TI override
    // removes engine warm-up as a variable while the engine remains running.
    private _caseStartedAt = diag_tickTime;
    private _target = createVehicle [
        "O_MBT_02_cannon_F",
        [_testDistance] call _targetPositionForDistance,
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

    private _orderIssuedAt = -1;
    if (_trialType isEqualTo "radio-order") then {
        _group reveal [_target, 4];
        _unit commandTarget _target;
        uiSleep 0.25;
        _unit commandFire _target;
        _orderIssuedAt = diag_tickTime - _caseStartedAt;
    };

    private _firstKnownByGroup = -1;
    private _firstKnownByUnit = -1;
    private _firstAssigned = -1;
    private _firstAttackTarget = -1;
    private _firstLauncherSelected = -1;
    private _firstLauncherFired = -1;
    private _transitions = [];
    private _lastSignature = [];
    private _lastPeriodicSampleAt = -1e10;
    private _deadline = diag_tickTime + _trialDuration;

    waitUntil {
        uiSleep 0.25;
        _target engineOn true;
        _target setVehicleTIPars [1, 1, 1];
        _target setVariable ["dapsActive", false, true];

        private _snapshot = [_unit, _target, _caseStartedAt] call
            _describeSnapshot;
        private _elapsed = [_snapshot, "elapsed", -1] call _snapshotValue;
        private _knownByGroup = [
            _snapshot,
            "knownByGroup",
            false
        ] call _snapshotValue;
        private _knownByUnit = [
            _snapshot,
            "knownByUnit",
            false
        ] call _snapshotValue;
        private _assigned = (
            [_snapshot, "assignedTarget", ""] call _snapshotValue
        ) isEqualTo str _target;
        private _attack = (
            [_snapshot, "attackTarget", ""] call _snapshotValue
        ) isEqualTo str _target;
        private _launcherSelected = (
            [_snapshot, "currentWeapon", ""] call _snapshotValue
        ) isEqualTo _launcherClass;
        private _firedEvents = localNamespace getVariable [_stateKey, []];
        private _launcherFireIndex = _firedEvents findIf {
            (_x param [1, "", [""]]) isEqualTo _launcherClass
            || {(_x param [4, "", [""]]) isEqualTo _ammoClass}
        };

        if (_firstKnownByGroup < 0 && {_knownByGroup}) then {
            _firstKnownByGroup = _elapsed;
        };
        if (_firstKnownByUnit < 0 && {_knownByUnit}) then {
            _firstKnownByUnit = _elapsed;
        };
        if (_firstAssigned < 0 && {_assigned}) then {
            _firstAssigned = _elapsed;
        };
        if (_firstAttackTarget < 0 && {_attack}) then {
            _firstAttackTarget = _elapsed;
        };
        if (_firstLauncherSelected < 0 && {_launcherSelected}) then {
            _firstLauncherSelected = _elapsed;
        };
        if (_firstLauncherFired < 0 && {_launcherFireIndex >= 0}) then {
            _firstLauncherFired = (
                (_firedEvents select _launcherFireIndex) select 0
            ) - _caseStartedAt;
        };

        private _signature = [
            _knownByGroup,
            _knownByUnit,
            _assigned,
            _attack,
            [_snapshot, "currentCommand", ""] call _snapshotValue,
            [_snapshot, "currentWeapon", ""] call _snapshotValue,
            [_snapshot, "secondaryMagazine", []] call _snapshotValue,
            [_snapshot, "canFire", false] call _snapshotValue,
            [_snapshot, "unitCombatMode", ""] call _snapshotValue,
            [_snapshot, "groupCombatMode", ""] call _snapshotValue,
            [_snapshot, "targetEngineOn", false] call _snapshotValue,
            [_snapshot, "targetDapsActive", false] call _snapshotValue
        ];
        if (
            _signature isNotEqualTo _lastSignature
            || {_elapsed - _lastPeriodicSampleAt >= 5}
        ) then {
            if ((count _transitions) < 60) then {
                _transitions pushBack _snapshot;
            };
            _lastSignature = _signature;
            _lastPeriodicSampleAt = _elapsed;
        };

        _firstLauncherFired >= 0
        || {diag_tickTime >= _deadline}
        || {isNull _unit}
        || {!alive _unit}
        || {isNull _target}
    };

    private _firedEvents = localNamespace getVariable [_stateKey, []];
    private _finalSnapshot = if (isNull _unit || {isNull _target}) then {
        []
    } else {
        [_unit, _target, _caseStartedAt] call _describeSnapshot
    };
    private _initialSnapshot = _transitions param [0, []];
    private _geometryValid = _initialSnapshot isNotEqualTo []
        && {([_initialSnapshot, "viewVisibility", 0] call _snapshotValue) > 0}
        && {([_initialSnapshot, "fireVisibility", 0] call _snapshotValue) > 0}
        && {!([_initialSnapshot, "terrainBlocked", true] call _snapshotValue)};
    private _launcherFired = _firstLauncherFired >= 0;
    private _otherWeaponFired = (_firedEvents findIf {
        (_x param [1, "", [""]]) isNotEqualTo _launcherClass
        && {(_x param [4, "", [""]]) isNotEqualTo _ammoClass}
    }) >= 0;
    private _outcome = if (_launcherFired) then {
        "launcher-fired"
    } else {
        if (!_geometryValid) then {
            "invalid-line-of-fire"
        } else {
            if (_firstKnownByGroup < 0) then {
                "no-group-knowledge"
            } else {
                if (_firstAttackTarget < 0 && {_firstAssigned < 0}) then {
                    "known-but-not-targeted"
                } else {
                    [
                        "launcher-selected-but-not-fired",
                        "targeted-but-launcher-not-selected"
                    ] select (_firstLauncherSelected < 0)
                }
            }
        }
    };

    private _trialResult = [
        ["trial", _trialNumber],
        ["repetition", _repetition],
        ["trialType", _trialType],
        ["weapon", _weaponLabel],
        ["launcher", _launcherClass],
        ["magazine", _magazineClass],
        ["ammo", _ammoClass],
        ["requestedDistance", _testDistance],
        ["config", [
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
        ]],
        ["orderIssuedAt", _orderIssuedAt],
        ["timings", [
            ["knownByGroup", _firstKnownByGroup],
            ["knownByUnit", _firstKnownByUnit],
            ["assigned", _firstAssigned],
            ["attackTarget", _firstAttackTarget],
            ["launcherSelected", _firstLauncherSelected],
            ["launcherFired", _firstLauncherFired]
        ]],
        ["outcome", _outcome],
        ["launcherFired", _launcherFired],
        ["otherWeaponFired", _otherWeaponFired],
        ["geometryValid", _geometryValid],
        ["firedEvents", _firedEvents],
        ["transitionLimit", 60],
        ["transitionBufferFull", (count _transitions) >= 60],
        ["initialSnapshot", _initialSnapshot],
        ["finalSnapshot", _finalSnapshot],
        ["transitions", _transitions]
    ];
    _results pushBack _trialResult;
    diag_log format ["%1 TRIAL %2", _prefix, _trialResult];

    _unit removeEventHandler ["FiredMan", _firedHandler];
    localNamespace setVariable [_stateKey, nil];
    deleteVehicle _unit;
    deleteGroup _group;
    deleteVehicleCrew _target;
    deleteVehicle _target;
    deleteGroup _targetGroup;
    uiSleep 1;
} forEach _trialPlan;

private _report = [
    ["report", "Black Skulls Archangel AI acquisition A/B test"],
    ["schemaVersion", 1],
    ["tick", diag_tickTime],
    ["world", worldName],
    ["machine", [clientOwner, isServer, hasInterface]],
    ["conditions", [
        ["testDistances", [600, 900, 1200]],
        ["targetClass", "O_MBT_02_cannon_F"],
        ["freshTargetPerTrial", true],
        ["targetTiPars", [1, 1, 1]],
        ["trialDuration", _trialDuration],
        ["archangelTitanRepetitions", _repetitions],
        ["pcmlRepetitions", 1],
        ["combatMode", "YELLOW"],
        ["behaviour", "AWARE"],
        ["projectilesDeleted", true],
        ["targetDamageDisabled", true],
        ["dapsForcedInactive", true],
        ["preExistingOtherUnits", count _preExistingUnits],
        ["preExistingVehicles", count _preExistingVehicles]
    ]],
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
    "Archangel A/B test complete: %1 trials. Report copied.",
    count _results
];

_report
