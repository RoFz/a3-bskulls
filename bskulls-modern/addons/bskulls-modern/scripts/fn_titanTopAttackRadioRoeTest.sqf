/*
 * Controlled, interactive test of player radio fire orders against the
 * intentional per-unit BLUE state applied to named Black Skulls operators.
 * This is diagnostic-only and changes no production gameplay logic.
 *
 * Each invocation tests one arm so a radio override from one shooter cannot
 * carry into the control. It creates Hawkins directly in the player's group
 * and records four sequential interventions:
 *   1. BLUE acquisition plus a no-command baseline.
 *   2. A real player-issued Open Fire radio command.
 *   3. Real player-issued target/Fire commands, if Open Fire did not fire.
 *   4. Scripted per-unit YELLOW, followed by a scripted commandTarget /
 *      commandFire rescue only if the natural YELLOW control did not fire.
 *
 * The engine does not expose the player's internal radio fire-status override.
 * The action-menu gates mark the start of each human intervention window; the
 * report records selected units and observable AI state without claiming that
 * these values directly expose that internal override.
 * The empty VR player group must already be in its default YELLOW state with
 * attacks enabled. The test never calls group setCombatMode or enableAttack:
 * either command could itself contaminate the radio-order intervention.
 *
 * Empty VR mission, one on-foot player who leads an otherwise-empty group.
 * Local Exec:
 *   [60, 30, 120, 20, "ARCHANGEL"] call
 *       bskulls_fnc_titanTopAttackRadioRoeTest;
 *
 * Restart the VR preview before the independent PCML control, then use:
 *   [60, 30, 120, 20, "PCML"] call
 *       bskulls_fnc_titanTopAttackRadioRoeTest;
 *
 * Follow the on-screen instructions. Do not manually fire a weapon and do not
 * save during the test. Projectiles are deleted immediately, targets cannot be
 * damaged, all telemetry is kept in localNamespace, and the final report is
 * copied to the clipboard.
 *
 * Official semantics used by the test:
 * https://community.bohemia.net/wiki/Combat_Modes
 * https://community.bohemia.net/wiki/setCombatMode
 * https://community.bohemia.net/wiki/setUnitCombatMode
 * https://community.bohemia.net/wiki/groupSelectedUnits
 * https://community.bohemia.net/wiki/addAction
 * https://community.bohemia.net/wiki/commandTarget
 * https://community.bohemia.net/wiki/commandFire
 * https://community.bohemia.net/wiki/Arma_3:_Event_Handlers#FiredMan
 */

params [
    ["_acquisitionDuration", 60, [0]],
    ["_observationDuration", 30, [0]],
    ["_interactionTimeout", 120, [0]],
    ["_rescueDuration", 20, [0]],
    ["_armSelector", "ARCHANGEL", [""]],
    ["_scheduledContinuation", false, [false]]
];

_acquisitionDuration = (_acquisitionDuration max 30) min 120;
_observationDuration = (_observationDuration max 15) min 60;
_interactionTimeout = (_interactionTimeout max 30) min 300;
_rescueDuration = (_rescueDuration max 10) min 60;
_armSelector = toUpperANSI _armSelector;

private _prefix = "[BSKULLS][TITAN-TA] RADIO_ROE_TEST";
private _runningKey = "bskulls_titanTopAttackRadioRoeTestRunning";
private _resultKey = "bskulls_titanTopAttackRadioRoeTestResult";
private _acquisitionRunningKey =
    "bskulls_titanTopAttackAcquisitionTestRunning";

private _announceFailure = {
    params ["_message"];
    diag_log format ["%1 ABORTED %2", _prefix, _message];
    if (hasInterface) then {
        systemChat format ["Launcher radio ROE test aborted: %1", _message];
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
if (leader group player isNotEqualTo player) exitWith {
    ["the local player must lead their group"] call _announceFailure
};
if (!local group player) exitWith {
    ["the local player's group must be local"] call _announceFailure
};
if !(_armSelector in ["ARCHANGEL", "PCML"]) exitWith {
    [format ["unknown arm selector %1", _armSelector]] call _announceFailure
};
if ((combatMode group player) isNotEqualTo "YELLOW") exitWith {
    [format [
        "restart the VR preview with the player group in default YELLOW (found %1)",
        combatMode group player
    ]] call _announceFailure
};
if !(attackEnabled group player) exitWith {
    ["restart the VR preview with player-group attacks enabled"] call
        _announceFailure
};

private _otherUnits = allUnits select {_x isNotEqualTo player};
private _otherVehicles = vehicles select {_x isNotEqualTo vehicle player};
if (_otherUnits isNotEqualTo [] || {_otherVehicles isNotEqualTo []}) exitWith {
    [format [
        "use an empty VR mission (found %1 other units and %2 vehicles)",
        count _otherUnits,
        count _otherVehicles
    ]] call _announceFailure
};

if (!canSuspend) exitWith {
    if (
        localNamespace getVariable [_runningKey, false]
        || {localNamespace getVariable [_acquisitionRunningKey, false]}
    ) then {
        ["another launcher test is already running"] call _announceFailure;
    } else {
        [
            _acquisitionDuration,
            _observationDuration,
            _interactionTimeout,
            _rescueDuration,
            _armSelector,
            true
        ] spawn bskulls_fnc_titanTopAttackRadioRoeTest;
        systemChat "Launcher radio ROE test scheduled.";
    };
    true
};

if (
    !_scheduledContinuation
    && {
        localNamespace getVariable [_runningKey, false]
        || {localNamespace getVariable [_acquisitionRunningKey, false]}
    }
) exitWith {
    ["another launcher test is already running"] call _announceFailure
};

private _hawkinsClass = "B_PTbskull_Veh_Unit_Hawkins_blackops_04";
private _targetClass = "O_MBT_02_cannon_F";
private _primaryClass = "B_PTbskull_Wea_ar_06_spar17";
private _primaryMagazine = "20Rnd_762x51_Mag";
private _archangelClass = "B_PTbskull_Wea_law_02_titantop";
private _archangelMagazine = "Titan_AT_TOP_PLUS";
private _pcmlClass = "launch_NLAW_F";
private _pcmlMagazine = "NLAW_F";

// Arm fields: label, launcher, magazine, distance.
private _arms = [[
    ["hawkins-archangel", _archangelClass, _archangelMagazine, 1200],
    ["hawkins-pcml-control", _pcmlClass, _pcmlMagazine, 600]
] select (_armSelector isEqualTo "PCML")];

private _requiredClasses = [
    ["CfgVehicles", _hawkinsClass],
    ["CfgVehicles", _targetClass],
    ["CfgWeapons", _primaryClass],
    ["CfgMagazines", _primaryMagazine]
];
{
    _requiredClasses pushBackUnique ["CfgWeapons", _x select 1];
    _requiredClasses pushBackUnique ["CfgMagazines", _x select 2];
} forEach _arms;
private _missingClasses = _requiredClasses select {
    !isClass (configFile >> (_x select 0) >> (_x select 1))
};
if (_missingClasses isNotEqualTo []) exitWith {
    [format ["missing required classes %1", _missingClasses]] call
        _announceFailure
};

localNamespace setVariable [_runningKey, true];
localNamespace setVariable [_resultKey, []];

private _testStartedAt = diag_tickTime;
private _playerGroup = group player;
private _originalGroupCombatMode = combatMode _playerGroup;
private _originalGroupAttackEnabled = attackEnabled _playerGroup;
private _bearing = getDir player;
private _origin = getPosATL player;
private _shooterPosition = [
    (_origin select 0) + (sin (_bearing + 90)) * 12,
    (_origin select 1) + (cos (_bearing + 90)) * 12,
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
        ["tick", diag_tickTime],
        ["elapsed", diag_tickTime - _caseStartedAt],
        ["phase", _phase],
        ["unit", str _unit],
        ["unitClass", typeOf _unit],
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
        ["weaponState", weaponState _unit],
        ["secondaryWeapon", secondaryWeapon _unit],
        ["secondaryMagazine", secondaryWeaponMagazine _unit],
        ["canFire", canFire _unit],
        ["unitReady", unitReady _unit],
        ["unitCombatMode", unitCombatMode _unit],
        ["groupCombatMode", combatMode group _unit],
        ["groupAttackEnabled", attackEnabled group _unit],
        ["groupLeader", str leader group _unit],
        ["groupUnitCount", count units group _unit],
        ["groupSelectedUnits", (groupSelectedUnits player) apply {str _x}],
        ["effectiveBehaviour", behaviour _unit],
        ["unitCombatBehaviour", combatBehaviour _unit],
        ["groupCombatBehaviour", combatBehaviour group _unit],
        ["suppression", getSuppression _unit],
        ["stance", stance _unit],
        ["animation", animationState _unit],
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

private _snapshotSignature = {
    params ["_snapshot"];
    [
        [_snapshot, "knownByUnit", false] call _value,
        [_snapshot, "assignedTarget", ""] call _value,
        [_snapshot, "attackTarget", ""] call _value,
        [_snapshot, "currentCommand", ""] call _value,
        [_snapshot, "currentWeapon", ""] call _value,
        [_snapshot, "currentMode", ""] call _value,
        [_snapshot, "secondaryMagazine", []] call _value,
        [_snapshot, "unitCombatMode", ""] call _value,
        [_snapshot, "groupCombatMode", ""] call _value,
        [_snapshot, "groupAttackEnabled", false] call _value,
        [_snapshot, "groupSelectedUnits", []] call _value,
        [_snapshot, "effectiveBehaviour", ""] call _value,
        [_snapshot, "unitCombatBehaviour", ""] call _value,
        [_snapshot, "groupCombatBehaviour", ""] call _value,
        [_snapshot, "stance", ""] call _value
    ]
};

private _findExpectedFireAfter = {
    params ["_stateKey", "_launcherClass", "_ammoClass", "_minimumTick"];
    private _events = localNamespace getVariable [_stateKey, []];
    private _index = _events findIf {
        ([_x, "tick", -1] call _value) >= _minimumTick
        && {
            ([_x, "weapon", ""] call _value) isEqualTo _launcherClass
            || {([_x, "ammo", ""] call _value) isEqualTo _ammoClass}
        }
    };
    if (_index < 0) exitWith {[]};
    _events select _index
};

private _appendTransition = {
    params ["_transitions", "_snapshot", "_trackingState"];
    _trackingState params ["_lastSignature", "_lastPeriodicAt"];
    private _signature = [_snapshot] call _snapshotSignature;
    private _elapsed = [_snapshot, "elapsed", -1] call _value;
    if (
        _signature isNotEqualTo _lastSignature
        || {_elapsed - _lastPeriodicAt >= 5}
    ) then {
        if ((count _transitions) < 160) then {
            _transitions pushBack _snapshot;
        };
        _trackingState set [0, _signature];
        _trackingState set [1, _elapsed];
    };
};

private _observeWindow = {
    params [
        "_unit",
        "_target",
        "_stateKey",
        "_launcherClass",
        "_ammoClass",
        "_caseStartedAt",
        "_phase",
        "_minimumFireTick",
        "_duration",
        "_transitions",
        "_trackingState"
    ];
    _unit setVariable ["bskulls_titanTopAttackRadioPhase", _phase, false];
    private _deadline = _minimumFireTick + _duration;
    private _fireEvent = [];
    waitUntil {
        uiSleep 0.1;
        if (!isNull _target) then {
            _target engineOn true;
            _target setVehicleTIPars [1, 1, 1];
            _target setVariable ["dapsActive", false, true];
        };
        if (!isNull _unit && {!isNull _target}) then {
            private _snapshot = [
                _unit,
                _target,
                _caseStartedAt,
                _phase
            ] call _describeSnapshot;
            [
                _transitions,
                _snapshot,
                _trackingState
            ] call _appendTransition;
        };
        _fireEvent = [
            _stateKey,
            _launcherClass,
            _ammoClass,
            _minimumFireTick
        ] call _findExpectedFireAfter;
        _fireEvent isNotEqualTo []
        || {diag_tickTime >= _deadline}
        || {isNull _unit}
        || {!alive _unit}
        || {isNull _target}
    };
    _fireEvent = [
        _stateKey,
        _launcherClass,
        _ammoClass,
        _minimumFireTick
    ] call _findExpectedFireAfter;
    [
        ["phase", _phase],
        ["startedAt", _minimumFireTick],
        ["endedAt", diag_tickTime],
        ["duration", diag_tickTime - _minimumFireTick],
        ["timedOut", _fireEvent isEqualTo [] && {diag_tickTime >= _deadline}],
        ["fired", _fireEvent isNotEqualTo []],
        ["fireEvent", _fireEvent]
    ]
};

private _waitForStartAction = {
    params [
        "_unit",
        "_target",
        "_stateKey",
        "_launcherClass",
        "_ammoClass",
        "_caseStartedAt",
        "_phase",
        "_title",
        "_instructions",
        "_timeout",
        "_transitions",
        "_trackingState"
    ];
    private _confirmationKey = format [
        "bskulls_titanTopAttackRadioAction_%1_%2",
        round (_caseStartedAt * 1000),
        _phase
    ];
    localNamespace setVariable [_confirmationKey, []];
    private _waitingPhase = format ["awaiting-%1", _phase];
    _unit setVariable [
        "bskulls_titanTopAttackRadioPhase",
        _waitingPhase,
        false
    ];
    private _promptAt = diag_tickTime;
    private _actionId = player addAction [
        format ["<t color='#FFD966'>TEST: %1</t>", _title],
        {
            params ["_target", "_caller", "_actionId", "_arguments"];
            _arguments params ["_key", "_shooter", "_phaseName"];
            private _selected = groupSelectedUnits _caller;
            localNamespace setVariable [_key, [
                ["activated", true],
                ["tick", diag_tickTime],
                ["phase", _phaseName],
                ["caller", str _caller],
                ["selectedUnitsAtGate", _selected apply {str _x}],
                ["shooterSelectedAtGate", _shooter in _selected],
                ["unitCombatMode", unitCombatMode _shooter],
                ["groupCombatMode", combatMode group _shooter],
                ["groupAttackEnabled", attackEnabled group _shooter]
            ]];
        },
        [_confirmationKey, _unit, _phase],
        6,
        true,
        true,
        "",
        "true",
        50,
        false,
        "",
        ""
    ];
    hint _instructions;
    systemChat format [
        "Radio ROE test: use the action-menu entry '%1' when ready.",
        _title
    ];
    private _deadline = diag_tickTime + _timeout;
    private _activation = [];
    private _preInterventionFire = [];
    waitUntil {
        uiSleep 0.1;
        if (!isNull _target) then {
            _target engineOn true;
            _target setVehicleTIPars [1, 1, 1];
            _target setVariable ["dapsActive", false, true];
        };
        if (!isNull _unit && {!isNull _target}) then {
            private _snapshot = [
                _unit,
                _target,
                _caseStartedAt,
                _waitingPhase
            ] call _describeSnapshot;
            [
                _transitions,
                _snapshot,
                _trackingState
            ] call _appendTransition;
        };
        _activation = localNamespace getVariable [_confirmationKey, []];
        _preInterventionFire = [
            _stateKey,
            _launcherClass,
            _ammoClass,
            _promptAt
        ] call _findExpectedFireAfter;
        _activation isNotEqualTo []
        || {_preInterventionFire isNotEqualTo []}
        || {diag_tickTime >= _deadline}
        || {isNull _unit}
        || {!alive _unit}
        || {isNull _target}
    };
    _activation = localNamespace getVariable [_confirmationKey, []];
    _preInterventionFire = [
        _stateKey,
        _launcherClass,
        _ammoClass,
        _promptAt
    ] call _findExpectedFireAfter;
    if (!isNull player) then {
        player removeAction _actionId;
    };
    hintSilent "";
    localNamespace setVariable [_confirmationKey, nil];
    [
        ["phase", _phase],
        ["promptAt", _promptAt],
        ["endedAt", diag_tickTime],
        ["activated", _activation isNotEqualTo []],
        ["activation", _activation],
        ["timedOut", _activation isEqualTo []
            && {_preInterventionFire isEqualTo []}
            && {diag_tickTime >= _deadline}],
        ["preInterventionFired", _preInterventionFire isNotEqualTo []],
        ["preInterventionFireEvent", _preInterventionFire]
    ]
};

private _rangePreflight = _arms apply {
    _x params ["_armLabel", "_launcherClass", "_magazineClass", "_distance"];
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
        private _modeConfig = _launcherConfig >> _x;
        private _minimum = getNumber (_modeConfig >> "minRange");
        private _maximum = getNumber (_modeConfig >> "maxRange");
        [
            ["mode", _x],
            ["present", isClass _modeConfig],
            ["minRange", _minimum],
            ["maxRange", _maximum],
            ["distanceInsideAiRange", isClass _modeConfig
                && {_distance >= _minimum}
                && {_distance <= _maximum}]
        ]
    };
    private _validModes = _modeChecks select {
        [_x, "distanceInsideAiRange", false] call _value
    };
    [
        ["arm", _armLabel],
        ["launcher", _launcherClass],
        ["magazine", _magazineClass],
        ["ammo", _ammoClass],
        ["distance", _distance],
        ["missileLockMinDistance", _lockMin],
        ["missileLockMaxDistance", _lockMax],
        ["modeChecks", _modeChecks],
        ["valid", _ammoClass isNotEqualTo ""
            && {isClass _ammoConfig}
            && {_distance >= _lockMin}
            && {_distance <= _lockMax}
            && {_validModes isNotEqualTo []}]
    ]
};
private _invalidRangeChecks = _rangePreflight select {
    !([_x, "valid", false] call _value)
};

if (_invalidRangeChecks isNotEqualTo []) exitWith {
    private _report = [
        ["report", "Black Skulls interactive radio ROE preflight"],
        ["schemaVersion", 2],
        ["tick", diag_tickTime],
        ["rangePreflight", _rangePreflight],
        ["valid", false]
    ];
    localNamespace setVariable [_resultKey, _report];
    localNamespace setVariable [_runningKey, false];
    diag_log format ["%1 PREFLIGHT_FAILED %2", _prefix, _report];
    copyToClipboard str _report;
    systemChat "Radio ROE preflight failed; report copied.";
    _report
};

private _results = [];
systemChat "RADIO ROE TEST STARTED. Follow the action-menu prompts.";
diag_log format ["%1 START rangePreflight=%2", _prefix, _rangePreflight];

{
    _x params ["_armLabel", "_launcherClass", "_magazineClass", "_distance"];
    private _caseStartedAt = diag_tickTime;
    private _ammoClass = getText (
        configFile >> "CfgMagazines" >> _magazineClass >> "ammo"
    );
    systemChat format ["Radio ROE arm: %1.", _armLabel];

    private _unit = _playerGroup createUnit [
        _hawkinsClass,
        _shooterPosition,
        [],
        0,
        "NONE"
    ];
    _unit setDir _bearing;
    private _identityDeadline = diag_tickTime + 15;
    waitUntil {
        uiSleep 0.05;
        (vehicleVarName _unit) isEqualTo "BSkullHawkins"
        || {diag_tickTime >= _identityDeadline}
        || {isNull _unit}
    };
    private _identityCompleted = !isNull _unit
        && {(vehicleVarName _unit) isEqualTo "BSkullHawkins"};
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
    _unit setCombatBehaviour "AWARE";

    removeAllWeapons _unit;
    removeAllMagazines _unit;
    removeAllItems _unit;
    removeAllAssignedItems _unit;
    _unit addMagazine _primaryMagazine;
    _unit addWeapon _primaryClass;
    _unit addMagazine _magazineClass;
    _unit addWeapon _launcherClass;
    _unit selectWeapon _primaryClass;

    private _targetPosition = [
        (_shooterPosition select 0) + (sin _bearing) * _distance,
        (_shooterPosition select 1) + (cos _bearing) * _distance,
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

    private _stateKey = format [
        "bskulls_titanTopAttackRadioEvents_%1_%2",
        round (_testStartedAt * 1000),
        _forEachIndex
    ];
    localNamespace setVariable [_stateKey, []];
    _unit setVariable ["bskulls_titanTopAttackRadioStateKey", _stateKey];
    _unit setVariable ["bskulls_titanTopAttackRadioTarget", _target];
    _unit setVariable [
        "bskulls_titanTopAttackRadioCaseStartedAt",
        _caseStartedAt
    ];
    _unit setVariable [
        "bskulls_titanTopAttackRadioPhase",
        "setup",
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
            "bskulls_titanTopAttackRadioStateKey",
            ""
        ];
        private _target = _unit getVariable [
            "bskulls_titanTopAttackRadioTarget",
            objNull
        ];
        private _startedAt = _unit getVariable [
            "bskulls_titanTopAttackRadioCaseStartedAt",
            diag_tickTime
        ];
        private _knowledge = if (isNull _target) then {[]} else {
            _unit targetKnowledge _target
        };
        private _events = localNamespace getVariable [_key, []];
        _events pushBack [
            ["tick", diag_tickTime],
            ["elapsed", diag_tickTime - _startedAt],
            ["phase", _unit getVariable [
                "bskulls_titanTopAttackRadioPhase",
                "unknown"
            ]],
            ["weapon", _weapon],
            ["muzzle", _muzzle],
            ["mode", _mode],
            ["ammo", _ammo],
            ["magazine", _magazine],
            ["projectile", str _projectile],
            ["vehicle", str _vehicle],
            ["target", str _target],
            ["knownByUnit", _knowledge param [1, false, [false]]],
            ["knowsAbout", if (isNull _target) then {-1} else {
                _unit knowsAbout _target
            }],
            ["assignedTarget", str assignedTarget _unit],
            ["attackTarget", str getAttackTarget _unit],
            ["currentWeapon", currentWeapon _unit],
            ["currentMode", currentWeaponMode _unit],
            ["weaponState", weaponState _unit],
            ["secondaryMagazine", secondaryWeaponMagazine _unit],
            ["unitCombatMode", unitCombatMode _unit],
            ["groupCombatMode", combatMode group _unit],
            ["groupAttackEnabled", attackEnabled group _unit],
            ["groupSelectedUnits", (groupSelectedUnits player) apply {
                str _x
            }]
        ];
        if ((count _events) > 20) then {
            _events deleteAt 0;
        };
        localNamespace setVariable [_key, _events];
        if (!isNull _projectile) then {
            deleteVehicle _projectile;
        };
    }];

    private _setupDeadline = diag_tickTime + 5;
    private _blueStableAt = -1;
    waitUntil {
        uiSleep 0.05;
        private _setupStateValid = (
            (primaryWeapon _unit) isEqualTo _primaryClass
            && {(secondaryWeapon _unit) isEqualTo _launcherClass}
            && {_magazineClass in secondaryWeaponMagazine _unit}
            && {(unitCombatMode _unit) isEqualTo "BLUE"}
            && {(combatMode _playerGroup) isEqualTo "YELLOW"}
            && {attackEnabled _playerGroup}
            && {(combatBehaviour _unit) isEqualTo "AWARE"}
            && {!(_unit checkAIFeature "AUTOCOMBAT")}
            && {leader _playerGroup isEqualTo player}
        );
        if (_setupStateValid) then {
            if (_blueStableAt < 0) then {
                _blueStableAt = diag_tickTime;
            };
        } else {
            _blueStableAt = -1;
        };
        (
            _blueStableAt >= 0
            && {diag_tickTime - _blueStableAt >= 2}
        )
        || {diag_tickTime >= _setupDeadline}
        || {isNull _unit}
    };
    private _blueStableBeforeBaseline = _blueStableAt >= 0
        && {diag_tickTime - _blueStableAt >= 2};
    private _setupValid = !isNull _unit
        && {_identityCompleted}
        && {(primaryWeapon _unit) isEqualTo _primaryClass}
        && {(secondaryWeapon _unit) isEqualTo _launcherClass}
        && {_magazineClass in secondaryWeaponMagazine _unit}
        && {(unitCombatMode _unit) isEqualTo "BLUE"}
        && {(combatMode _playerGroup) isEqualTo "YELLOW"}
        && {attackEnabled _playerGroup}
        && {(combatBehaviour _unit) isEqualTo "AWARE"}
        && {!(_unit checkAIFeature "AUTOCOMBAT")}
        && {leader _playerGroup isEqualTo player}
        && {_blueStableBeforeBaseline};

    private _initialSnapshot = [
        _unit,
        _target,
        _caseStartedAt,
        "blue-acquisition"
    ] call _describeSnapshot;
    private _transitions = [_initialSnapshot];
    private _trackingState = [
        [_initialSnapshot] call _snapshotSignature,
        0
    ];
    private _acquisitionReadyAt = -1;
    private _acquisitionSnapshot = [];
    private _baselineEndedAt = -1;
    private _baselineFireEvent = [];
    private _acquisitionDeadline = diag_tickTime + _acquisitionDuration;
    private _baselineDeadline = -1;
    _unit setVariable [
        "bskulls_titanTopAttackRadioPhase",
        "blue-acquisition",
        false
    ];

    waitUntil {
        uiSleep 0.1;
        _target engineOn true;
        _target setVehicleTIPars [1, 1, 1];
        _target setVariable ["dapsActive", false, true];
        private _phase = [
            "blue-acquisition",
            "blue-no-command-baseline"
        ] select (_acquisitionReadyAt >= 0);
        _unit setVariable [
            "bskulls_titanTopAttackRadioPhase",
            _phase,
            false
        ];
        private _snapshot = [
            _unit,
            _target,
            _caseStartedAt,
            _phase
        ] call _describeSnapshot;
        [
            _transitions,
            _snapshot,
            _trackingState
        ] call _appendTransition;
        private _knowledge = [_snapshot, "knownByUnit", false] call _value;
        private _selected = (
            [_snapshot, "currentWeapon", ""] call _value
        ) isEqualTo _launcherClass;
        private _loaded = _magazineClass in (
            [_snapshot, "secondaryMagazine", []] call _value
        );
        if (
            _acquisitionReadyAt < 0
            && {_knowledge}
            && {_selected}
            && {_loaded}
        ) then {
            _acquisitionReadyAt = diag_tickTime;
            _baselineDeadline = diag_tickTime + 10;
            _acquisitionSnapshot = _snapshot;
        };
        _baselineFireEvent = [
            _stateKey,
            _launcherClass,
            _ammoClass,
            _caseStartedAt
        ] call _findExpectedFireAfter;
        _baselineFireEvent isNotEqualTo []
        || {
            _acquisitionReadyAt < 0
            && {diag_tickTime >= _acquisitionDeadline}
        }
        || {
            _acquisitionReadyAt >= 0
            && {diag_tickTime >= _baselineDeadline}
        }
        || {isNull _unit}
        || {!alive _unit}
        || {isNull _target}
    };
    _baselineFireEvent = [
        _stateKey,
        _launcherClass,
        _ammoClass,
        _caseStartedAt
    ] call _findExpectedFireAfter;
    _baselineEndedAt = diag_tickTime;

    private _openFireGate = [];
    private _openFireWindow = [];
    private _targetFireGate = [];
    private _targetFireWindow = [];
    private _scriptedYellowWindow = [];
    private _scriptedRescueWindow = [];
    private _preInterventionFireEvent = [];
    private _userInteractionTimedOut = false;

    if (
        _setupValid
        && {_baselineFireEvent isEqualTo []}
        && {!isNull _unit}
        && {alive _unit}
    ) then {
        _openFireGate = [
            _unit,
            _target,
            _stateKey,
            _launcherClass,
            _ammoClass,
            _caseStartedAt,
            "open-fire",
            "START OPEN FIRE window",
            format [
                "%1\n\nHawkins is your only subordinate (normally F2).\n\n1. Use the action menu: START OPEN FIRE window.\n2. Immediately select Hawkins only.\n3. Issue the normal player radio command OPEN FIRE.\n4. Do not assign a target and do not fire your own weapon.",
                _armLabel
            ],
            _interactionTimeout,
            _transitions,
            _trackingState
        ] call _waitForStartAction;
        _preInterventionFireEvent = [
            _openFireGate,
            "preInterventionFireEvent",
            []
        ] call _value;
        _userInteractionTimedOut = [
            _openFireGate,
            "timedOut",
            false
        ] call _value;
        if (
            [_openFireGate, "activated", false] call _value
            && {_preInterventionFireEvent isEqualTo []}
        ) then {
            private _activation = [
                _openFireGate,
                "activation",
                []
            ] call _value;
            private _windowStartedAt = [
                _activation,
                "tick",
                diag_tickTime
            ] call _value;
            hint format [
                "%1\n\nNOW select Hawkins and issue OPEN FIRE.\nObservation window: %2 seconds.",
                _armLabel,
                _observationDuration
            ];
            systemChat format [
                "%1: issue OPEN FIRE now (%2-second window).",
                _armLabel,
                _observationDuration
            ];
            _openFireWindow = [
                _unit,
                _target,
                _stateKey,
                _launcherClass,
                _ammoClass,
                _caseStartedAt,
                "open-fire-window",
                _windowStartedAt,
                _observationDuration,
                _transitions,
                _trackingState
            ] call _observeWindow;
            hintSilent "";
        };
    };

    private _openFireEvent = [
        _openFireWindow,
        "fireEvent",
        []
    ] call _value;
    if (
        _setupValid
        && {_baselineFireEvent isEqualTo []}
        && {_preInterventionFireEvent isEqualTo []}
        && {_openFireEvent isEqualTo []}
        && {!_userInteractionTimedOut}
        && {!isNull _unit}
        && {alive _unit}
    ) then {
        _targetFireGate = [
            _unit,
            _target,
            _stateKey,
            _launcherClass,
            _ammoClass,
            _caseStartedAt,
            "target-fire",
            "START TARGET + FIRE window",
            format [
                "%1\n\n1. Use the action menu: START TARGET + FIRE window.\n2. Immediately select Hawkins only.\n3. Point at the tank and assign/engage it.\n4. Issue the normal player FIRE command.\n5. Do not fire your own weapon.",
                _armLabel
            ],
            _interactionTimeout,
            _transitions,
            _trackingState
        ] call _waitForStartAction;
        _preInterventionFireEvent = [
            _targetFireGate,
            "preInterventionFireEvent",
            []
        ] call _value;
        _userInteractionTimedOut = [
            _targetFireGate,
            "timedOut",
            false
        ] call _value;
        if (
            [_targetFireGate, "activated", false] call _value
            && {_preInterventionFireEvent isEqualTo []}
        ) then {
            private _activation = [
                _targetFireGate,
                "activation",
                []
            ] call _value;
            private _windowStartedAt = [
                _activation,
                "tick",
                diag_tickTime
            ] call _value;
            hint format [
                "%1\n\nNOW assign the tank and issue FIRE.\nObservation window: %2 seconds.",
                _armLabel,
                _observationDuration
            ];
            systemChat format [
                "%1: assign the tank and issue FIRE now (%2-second window).",
                _armLabel,
                _observationDuration
            ];
            _targetFireWindow = [
                _unit,
                _target,
                _stateKey,
                _launcherClass,
                _ammoClass,
                _caseStartedAt,
                "target-fire-window",
                _windowStartedAt,
                _observationDuration,
                _transitions,
                _trackingState
            ] call _observeWindow;
            hintSilent "";
        };
    };

    private _targetFireEvent = [
        _targetFireWindow,
        "fireEvent",
        []
    ] call _value;
    if (
        _setupValid
        && {_baselineFireEvent isEqualTo []}
        && {_preInterventionFireEvent isEqualTo []}
        && {_openFireEvent isEqualTo []}
        && {_targetFireEvent isEqualTo []}
        && {!_userInteractionTimedOut}
        && {!isNull _unit}
        && {alive _unit}
    ) then {
        private _windowStartedAt = diag_tickTime;
        _unit setUnitCombatMode "YELLOW";
        systemChat format [
            "%1: scripted per-unit YELLOW positive control started.",
            _armLabel
        ];
        _scriptedYellowWindow = [
            _unit,
            _target,
            _stateKey,
            _launcherClass,
            _ammoClass,
            _caseStartedAt,
            "scripted-yellow-window",
            _windowStartedAt,
            _observationDuration,
            _transitions,
            _trackingState
        ] call _observeWindow;
    };

    private _scriptedYellowEvent = [
        _scriptedYellowWindow,
        "fireEvent",
        []
    ] call _value;
    if (
        _setupValid
        && {_baselineFireEvent isEqualTo []}
        && {_preInterventionFireEvent isEqualTo []}
        && {_openFireEvent isEqualTo []}
        && {_targetFireEvent isEqualTo []}
        && {_scriptedYellowEvent isEqualTo []}
        && {!_userInteractionTimedOut}
        && {!isNull _unit}
        && {alive _unit}
    ) then {
        _playerGroup reveal [_target, 4];
        _unit commandTarget _target;
        uiSleep 0.25;
        private _windowStartedAt = diag_tickTime;
        _unit commandFire _target;
        systemChat format [
            "%1: scripted target/fire rescue started.",
            _armLabel
        ];
        _scriptedRescueWindow = [
            _unit,
            _target,
            _stateKey,
            _launcherClass,
            _ammoClass,
            _caseStartedAt,
            "scripted-target-fire-window",
            _windowStartedAt,
            _rescueDuration,
            _transitions,
            _trackingState
        ] call _observeWindow;
    };

    private _scriptedRescueEvent = [
        _scriptedRescueWindow,
        "fireEvent",
        []
    ] call _value;
    private _outcome = if (!_setupValid) then {
        "setup-invalid"
    } else {
        if (_baselineFireEvent isNotEqualTo []) then {
            "blue-baseline-fired"
        } else {
            if (_preInterventionFireEvent isNotEqualTo []) then {
                "fired-before-intervention-start"
            } else {
                if (_openFireEvent isNotEqualTo []) then {
                    "open-fire-window-fired"
                } else {
                    if (_targetFireEvent isNotEqualTo []) then {
                        "target-fire-window-fired"
                    } else {
                        if (_userInteractionTimedOut) then {
                            "user-interaction-timeout"
                        } else {
                            if (_scriptedYellowEvent isNotEqualTo []) then {
                                "scripted-yellow-fired"
                            } else {
                                [
                                    "no-fire",
                                    "scripted-rescue-fired"
                                ] select (
                                    _scriptedRescueEvent isNotEqualTo []
                                )
                            }
                        }
                    }
                }
            }
        }
    };

    private _finalSnapshot = if (isNull _unit || {isNull _target}) then {
        []
    } else {
        [
            _unit,
            _target,
            _caseStartedAt,
            "final"
        ] call _describeSnapshot
    };
    private _events = localNamespace getVariable [_stateKey, []];
    private _result = [
        ["arm", _armLabel],
        ["launcher", _launcherClass],
        ["magazine", _magazineClass],
        ["ammo", _ammoClass],
        ["distance", _distance],
        ["identityCompleted", _identityCompleted],
        ["postIdentityUnitCombatMode", _postIdentityUnitCombatMode],
        ["blueStableBeforeBaseline", _blueStableBeforeBaseline],
        ["setupValid", _setupValid],
        ["acquisitionReady", _acquisitionReadyAt >= 0],
        ["acquisitionReadyAt", if (_acquisitionReadyAt < 0) then {-1} else {
            _acquisitionReadyAt - _caseStartedAt
        }],
        ["baselineEndedAt", _baselineEndedAt - _caseStartedAt],
        ["baselineFired", _baselineFireEvent isNotEqualTo []],
        ["baselineFireEvent", _baselineFireEvent],
        ["openFireGate", _openFireGate],
        ["openFireWindow", _openFireWindow],
        ["targetFireGate", _targetFireGate],
        ["targetFireWindow", _targetFireWindow],
        ["scriptedYellowWindow", _scriptedYellowWindow],
        ["scriptedRescueWindow", _scriptedRescueWindow],
        ["userInteractionTimedOut", _userInteractionTimedOut],
        ["outcome", _outcome],
        ["firedEvents", _events],
        ["initialSnapshot", _initialSnapshot],
        ["acquisitionSnapshot", _acquisitionSnapshot],
        ["finalSnapshot", _finalSnapshot],
        ["transitionLimit", 160],
        ["transitionBufferFull", (count _transitions) >= 160],
        ["transitions", _transitions]
    ];
    _results pushBack _result;
    diag_log format ["%1 ARM %2", _prefix, _result];
    systemChat format ["%1 outcome: %2.", _armLabel, _outcome];

    if (!isNull _unit) then {
        _unit removeEventHandler ["FiredMan", _firedHandler];
    };
    localNamespace setVariable [_stateKey, nil];
    deleteVehicle _unit;
    deleteVehicleCrew _target;
    deleteVehicle _target;
    deleteGroup _targetGroup;
    uiSleep 1;
} forEach _arms;

hintSilent "";
private _groupBeforeFinalization = [
    ["combatMode", combatMode _playerGroup],
    ["attackEnabled", attackEnabled _playerGroup],
    ["leader", str leader _playerGroup],
    ["unitCount", count units _playerGroup]
];
private _groupAfterFinalization = [
    ["combatMode", combatMode _playerGroup],
    ["attackEnabled", attackEnabled _playerGroup],
    ["leader", str leader _playerGroup],
    ["unitCount", count units _playerGroup]
];

private _report = [
    ["report", "Black Skulls interactive player-radio ROE test"],
    ["schemaVersion", 2],
    ["tick", diag_tickTime],
    ["world", worldName],
    ["machine", [clientOwner, isServer, hasInterface]],
    ["conditions", [
        ["arms", _arms apply {_x select 0}],
        ["armSelector", _armSelector],
        ["acquisitionDuration", _acquisitionDuration],
        ["blueBaselineDurationAfterAcquisition", 10],
        ["observationDuration", _observationDuration],
        ["interactionTimeout", _interactionTimeout],
        ["rescueDuration", _rescueDuration],
        ["playerLed", true],
        ["playerWasRequiredLeader", true],
        ["individualRoeNormalization", "none before user phases"],
        [
            "groupCombatModeControl",
            "required pre-existing YELLOW; never scripted"
        ],
        ["groupAttackControl", "required pre-existing enabled; never scripted"],
        ["individualBehaviour", "AWARE"],
        ["autocombatDisabled", true],
        ["freshShooterPerArm", true],
        ["freshTargetPerArm", true],
        ["normalizedOneRoundLoadouts", true],
        ["projectilesDeleted", true],
        ["targetDamageDisabled", true],
        ["dapsForcedInactive", true],
        [
            "radioOverrideObservableDirectly",
            false
        ],
        [
            "humanInterventionEvidence",
            "action-gated window plus user compliance"
        ]
    ]],
    ["playerGroup", [
        ["originalCombatMode", _originalGroupCombatMode],
        ["originalAttackEnabled", _originalGroupAttackEnabled],
        ["restorationApplied", false],
        ["beforeFinalization", _groupBeforeFinalization],
        ["afterFinalization", _groupAfterFinalization]
    ]],
    ["rangePreflight", _rangePreflight],
    ["elapsed", diag_tickTime - _testStartedAt],
    ["results", _results]
];

localNamespace setVariable [_resultKey, _report];
localNamespace setVariable [_runningKey, false];
diag_log format ["%1 FINAL %2", _prefix, _report];
copyToClipboard str _report;
systemChat "RADIO ROE TEST COMPLETE. Report copied to clipboard.";

_report
