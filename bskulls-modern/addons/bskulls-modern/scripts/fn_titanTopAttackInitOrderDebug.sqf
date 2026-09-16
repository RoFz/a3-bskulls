/*
 * Trace the local player's command path to any AI launcher carrier in the
 * player's group without issuing or modifying commands. The normal unit-state
 * monitor intentionally runs at a low rate because its visibility scans are
 * expensive; this companion loop samples only lightweight order state so
 * short FIRE/ATTACK transitions are not missed.
 *
 * assignedTarget documents leader target assignments, while currentCommand
 * exposes FIRE, ATTACK, and ATTACKFIRE orders. groupSelectedUnits and
 * commandingMenu establish the local player's command context.
 * https://community.bohemia.net/wiki/assignedTarget
 * https://community.bohemia.net/wiki/currentCommand
 * https://community.bohemia.net/wiki/groupSelectedUnits
 * https://community.bohemia.net/wiki/commandingMenu
 * https://community.bohemia.net/wiki/getUnitState
 * https://community.bohemia.net/wiki/Arma_3:_Event_Handlers
 * https://github.com/CBATeam/CBA_A3/blob/master/addons/common/init_perFrameHandler.sqf
 */

params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {false};

private _oldHandle = [
    _unit,
    "order-debug-pfh",
    -1
] call bskulls_fnc_titanTopAttackRuntimeGet;
if (
    !hasInterface
    || {!local _unit}
    || {!alive _unit}
    || {isPlayer _unit}
    || {(secondaryWeapon _unit) isEqualTo ""}
    || {({isPlayer _x} count units group _unit) <= 0}
    || {!(localNamespace getVariable ["bskulls_titanTopAttackDebug", false])}
) exitWith {
    if (_oldHandle >= 0) then {
        [_oldHandle] call CBA_fnc_removePerFrameHandler;
    };
    [_unit, "order-debug-pfh", -1] call bskulls_fnc_titanTopAttackRuntimeSet;
    [_unit, "order-debug-state", []] call bskulls_fnc_titanTopAttackRuntimeSet;
    false
};

if (_oldHandle >= 0) exitWith {true};

private _unitId = netId _unit;
if (_unitId isEqualTo "") then {
    _unitId = str _unit;
};
private _traceId = format ["unit-%1", _unitId];

private _handle = [{
    params ["_arguments", "_handle"];
    _arguments params ["_unit", "_traceId"];

    if (
        !hasInterface
        || {isNull _unit}
        || {!local _unit}
        || {!alive _unit}
        || {isPlayer _unit}
        || {(secondaryWeapon _unit) isEqualTo ""}
        || {({isPlayer _x} count units group _unit) <= 0}
        || {!(localNamespace getVariable ["bskulls_titanTopAttackDebug", false])}
    ) exitWith {
        [_handle] call CBA_fnc_removePerFrameHandler;
        if (!isNull _unit) then {
            private _registeredHandle = [
                _unit,
                "order-debug-pfh",
                -1
            ] call bskulls_fnc_titanTopAttackRuntimeGet;
            if (_registeredHandle isEqualTo _handle) then {
                [
                    _unit,
                    "order-debug-pfh",
                    -1
                ] call bskulls_fnc_titanTopAttackRuntimeSet;
            };
        };
    };

    private _registeredHandle = [
        _unit,
        "order-debug-pfh",
        -1
    ] call bskulls_fnc_titanTopAttackRuntimeGet;
    if (_registeredHandle < 0) then {
        [
            _unit,
            "order-debug-pfh",
            _handle
        ] call bskulls_fnc_titanTopAttackRuntimeSet;
    };

    private _monitorState = [
        _unit,
        "order-debug-state",
        [[], -1, 0, -1e10]
    ] call bskulls_fnc_titanTopAttackRuntimeGet;
    private _lastState = _monitorState param [0, []];
    private _followupStartedAt = _monitorState param [1, -1];
    private _followupIndex = _monitorState param [2, 0];
    private _lastNoiseLogAt = _monitorState param [3, -1e10];
    private _followupDelays = [0.25, 1, 2, 5];
    private _stateLabels = [
        "same-player-group",
        "launcher-unit-selected",
        "commanding-menu",
        "assigned-target",
        "attack-target",
        "current-command",
        "ai-planner-state",
        "current-weapon",
        "current-muzzle",
        "current-mode",
        "loaded-magazine",
        "loaded-rounds",
        "round-reloading",
        "magazine-reloading",
        "unit-combat-mode",
        "group-combat-mode",
        "behaviour",
        "combat-behaviour",
        "unit-ready",
        "can-fire",
        "group-attack-enabled",
        "reload-enabled",
        "simulation-enabled",
        "secondary-launcher",
        "launcher-loaded-magazine",
        "launcher-rounds",
        "launcher-round-reloading",
        "launcher-magazine-reloading"
    ];

    private _describeTarget = {
        params ["_observer", "_commander", "_target"];

        if (isNull _target) exitWith {[]};

        private _targetPositionASL = aimPos _target;
        private _observerEyeASL = eyePos _observer;
        private _isVehicleEntity = _target isKindOf "AllVehicles";
        private _knowledge = if (_isVehicleEntity) then {
            _observer targetKnowledge _target
        } else {
            [false, false, -1, -1, sideUnknown, -1, [], false]
        };
        private _lastSeen = _knowledge param [2, -1, [0]];
        [
            ["object", str _target],
            ["class", typeOf _target],
            ["side", str side _target],
            ["alive", alive _target],
            ["isLandVehicle", _target isKindOf "LandVehicle"],
            ["distanceFromUnit", _observer distance2D _target],
            ["distanceFromCommander", if (isNull _commander) then {-1} else {
                _commander distance2D _target
            }],
            ["engineOn", _isVehicleEntity && {isEngineOn _target}],
            ["speed", if (_isVehicleEntity) then {speed _target} else {0}],
            ["irTarget", getNumber (configOf _target >> "irTarget")],
            ["unitKnowsAbout", if (_isVehicleEntity) then {
                _observer knowsAbout _target
            } else {-1}],
            ["commanderKnowsAbout", if (
                isNull _commander
                || {!_isVehicleEntity}
            ) then {-1} else {
                _commander knowsAbout _target
            }],
            ["knownByGroup", _knowledge param [0, false, [false]]],
            ["knownByUnit", _knowledge param [1, false, [false]]],
            ["lastSeenAge", if (_lastSeen < 0) then {-1} else {
                (time - _lastSeen) max 0
            }],
            ["knowledgePositionError", _knowledge param [5, -1, [0]]],
            ["viewVisibility", [_observer, "VIEW", _target] checkVisibility [
                _observerEyeASL,
                _targetPositionASL
            ]],
            ["fireVisibility", [_observer, "FIRE", _target] checkVisibility [
                _observerEyeASL,
                _targetPositionASL
            ]],
            ["terrainBlocked", terrainIntersectASL [
                _observerEyeASL,
                _targetPositionASL
            ]]
        ]
    };

    private _makeSnapshot = {
        params [
            "_unit",
            "_commander",
            "_samePlayerGroup",
            "_selected",
            "_menu",
            "_assigned",
            "_attack",
            "_reasons",
            "_after"
        ];

        private _cursorTargetObject = if (isNull _commander) then {
            objNull
        } else {
            cursorTarget
        };
        private _cursorObjectObject = if (isNull _commander) then {
            objNull
        } else {
            cursorObject
        };
        private _selectedUnits = if (isNull _commander) then {
            []
        } else {
            groupSelectedUnits _commander
        };
        private _launcherClass = secondaryWeapon _unit;
        private _launcherState = _unit weaponState _launcherClass;
        private _compatibleLauncherMagazines = compatibleMagazines _launcherClass;
        private _launcherInventory = (magazinesAmmoFull _unit) select {
            (_x param [0, ""]) in _compatibleLauncherMagazines
            || {(_x param [3, -1]) isEqualTo 4}
        };
        private _launcherRoundCount = 0;
        {
            _launcherRoundCount = _launcherRoundCount + (_x param [1, 0]);
        } forEach _launcherInventory;

        [
            ["reasons", _reasons],
            ["afterPotentialOrder", _after],
            ["unit", str _unit],
            ["unitLocal", local _unit],
            ["commander", if (isNull _commander) then {"<NULL-object>"} else {
                str _commander
            }],
            ["samePlayerGroup", _samePlayerGroup],
            ["groupContext", [
                ["group", str group _unit],
                ["groupLocal", local group _unit],
                ["leader", str leader group _unit],
                ["leaderLocal", local leader group _unit],
                ["playerIsLeader", !isNull _commander && {
                    (leader group _unit) isEqualTo _commander
                }],
                ["attackEnabled", attackEnabled group _unit]
            ]],
            ["launcherUnitSelected", _selected],
            ["selectedUnits", _selectedUnits apply {
                [str _x, typeOf _x, netId _x]
            }],
            ["commandingMenu", _menu],
            ["assignedTarget", [_unit, _commander, _assigned] call _describeTarget],
            ["attackTarget", [_unit, _commander, _attack] call _describeTarget],
            ["cursorTarget", [
                _unit,
                _commander,
                _cursorTargetObject
            ] call _describeTarget],
            ["cursorObject", [
                _unit,
                _commander,
                _cursorObjectObject
            ] call _describeTarget],
            ["currentCommand", currentCommand _unit],
            ["unitState", getUnitState _unit],
            ["weapon", [
                currentWeapon _unit,
                currentMuzzle _unit,
                currentWeaponMode _unit
            ]],
            ["weaponState", weaponState _unit],
            ["secondaryWeapon", _launcherClass],
            ["secondaryWeaponMagazine", secondaryWeaponMagazine _unit],
            ["launcherState", _launcherState],
            ["compatibleLauncherMagazines", _compatibleLauncherMagazines],
            ["launcherInventory", _launcherInventory],
            ["launcherRoundCount", _launcherRoundCount],
            ["topAttackMissileCount", {
                (_x param [0, ""]) isEqualTo "Titan_AT_TOP_PLUS"
            } count magazinesAmmoFull _unit],
            ["combat", [
                unitCombatMode _unit,
                combatMode group _unit,
                behaviour _unit,
                combatBehaviour _unit
            ]],
            ["readiness", [unitReady _unit, canFire _unit]],
            ["reloadEnabled", reloadEnabled _unit],
            ["archangelReloadPhase", (
                _unit weaponState "B_PTbskull_Wea_law_02_titantop"
            ) param [5, -1]],
            ["fireDiscipline", [
                _unit,
                "discipline-state",
                []
            ] call bskulls_fnc_titanTopAttackRuntimeGet],
            ["expectedDestination", expectedDestination _unit],
            ["simulationEnabled", simulationEnabled _unit],
            ["autoSpotDifficulty", difficultyEnabled "autoSpot"],
            ["aiFeatures", [
                ["TARGET", _unit checkAIFeature "TARGET"],
                ["AUTOTARGET", _unit checkAIFeature "AUTOTARGET"],
                ["CHECKVISIBLE", _unit checkAIFeature "CHECKVISIBLE"],
                ["WEAPONAIM", _unit checkAIFeature "WEAPONAIM"],
                ["FSM", _unit checkAIFeature "FSM"],
                ["AUTOCOMBAT", _unit checkAIFeature "AUTOCOMBAT"],
                ["FIREWEAPON", _unit checkAIFeature "FIREWEAPON"],
                ["MOVE", _unit checkAIFeature "MOVE"],
                ["PATH", _unit checkAIFeature "PATH"],
                ["SUPPRESSION", _unit checkAIFeature "SUPPRESSION"]
            ]]
        ]
    };

    // One lightweight order sample. CBA owns the save-compatible scheduler;
    // mutable comparison state remains in localNamespace.
        private _commander = player;
        if (isNull _commander) then {
            _commander = objNull;
        };
        private _unitGroup = group _unit;
        private _samePlayerGroup = !isNull _commander
            && {_unitGroup isEqualTo group _commander};
        private _selected = _samePlayerGroup
            && {_unit in groupSelectedUnits _commander};
        private _menu = if (_samePlayerGroup) then {commandingMenu} else {""};
        private _assigned = assignedTarget _unit;
        private _attack = getAttackTarget _unit;
        private _weaponState = weaponState _unit;
        private _launcherClass = secondaryWeapon _unit;
        private _launcherState = _unit weaponState _launcherClass;
        private _compatibleLauncherMagazines = compatibleMagazines _launcherClass;
        private _launcherInventory = (magazinesAmmoFull _unit) select {
            (_x param [0, ""]) in _compatibleLauncherMagazines
            || {(_x param [3, -1]) isEqualTo 4}
        };
        private _launcherRoundCount = 0;
        {
            _launcherRoundCount = _launcherRoundCount + (_x param [1, 0]);
        } forEach _launcherInventory;
        private _state = [
            _samePlayerGroup,
            _selected,
            _menu,
            str _assigned,
            str _attack,
            currentCommand _unit,
            getUnitState _unit,
            currentWeapon _unit,
            currentMuzzle _unit,
            currentWeaponMode _unit,
            _weaponState param [3, ""],
            _weaponState param [4, 0],
            (_weaponState param [5, 0]) > 0,
            (_weaponState param [6, 0]) > 0,
            unitCombatMode _unit,
            combatMode _unitGroup,
            behaviour _unit,
            combatBehaviour _unit,
            unitReady _unit,
            canFire _unit,
            attackEnabled _unitGroup,
            reloadEnabled _unit,
            simulationEnabled _unit,
            _launcherClass,
            _launcherState param [3, ""],
            _launcherRoundCount,
            (_launcherState param [5, 0]) > 0,
            (_launcherState param [6, 0]) > 0
        ];

        private _reasons = [];
        if (_lastState isEqualTo []) then {
            _reasons pushBack "monitor-start";
        } else {
            for "_index" from 0 to ((count _state) - 1) do {
                if ((_state select _index) isNotEqualTo (_lastState select _index)) then {
                    _reasons pushBack (_stateLabels select _index);
                };
            };
        };

        private _wasSamePlayerGroup = _lastState param [0, false];
        private _meaningfulReasons = _reasons select {
            _x isNotEqualTo "ai-planner-state"
        };
        private _plannerOnly = _reasons isNotEqualTo []
            && {_meaningfulReasons isEqualTo []};
        private _shouldLogState = _meaningfulReasons isNotEqualTo []
            || {_plannerOnly && {diag_tickTime - _lastNoiseLogAt >= 15}};
        if (_plannerOnly && {_shouldLogState}) then {
            _lastNoiseLogAt = diag_tickTime;
        };
        if (
            _shouldLogState
            && {_samePlayerGroup || {_wasSamePlayerGroup}}
        ) then {
            private _details = [
                _unit,
                _commander,
                _samePlayerGroup,
                _selected,
                _menu,
                _assigned,
                _attack,
                _reasons,
                -1
            ] call _makeSnapshot;
            private _rptDetails = [
                ["unit", str _unit],
                ["reasons", _reasons],
                ["selected", _selected],
                ["menu", _menu],
                ["targets", [
                    if (isNull _assigned) then {""} else {typeOf _assigned},
                    if (isNull _attack) then {""} else {typeOf _attack},
                    if (isNull cursorTarget) then {""} else {typeOf cursorTarget},
                    if (isNull cursorObject) then {""} else {typeOf cursorObject}
                ]],
                ["command", currentCommand _unit],
                ["unitState", getUnitState _unit],
                ["weapon", [
                    currentWeapon _unit,
                    currentWeaponMode _unit,
                    _weaponState param [3, ""],
                    _weaponState param [4, 0],
                    _launcherClass,
                    _launcherState param [3, ""],
                    _launcherRoundCount
                ]],
                ["combat", [
                    unitCombatMode _unit,
                    combatMode _unitGroup,
                    behaviour _unit,
                    attackEnabled _unitGroup
                ]]
            ];
            [
                objNull,
                "ORDER_STATE",
                _details,
                _traceId,
                _rptDetails
            ] call bskulls_fnc_titanTopAttackLog;
        };

        if (_lastState isNotEqualTo [] && {_samePlayerGroup}) then {
            private _menuClosed = (_lastState select 2) isNotEqualTo ""
                && {_menu isEqualTo ""};
            private _selectionReleased = (_lastState select 1) && {!_selected};
            private _actionCommandStarted = "current-command" in _reasons
                && {currentCommand _unit in ["ATTACK", "FIRE", "ATTACKFIRE"]};
            if (_menuClosed || {_selectionReleased} || {_actionCommandStarted}) then {
                _followupStartedAt = diag_tickTime;
                _followupIndex = 0;
            };
        };

        if (
            _samePlayerGroup
            && {_followupStartedAt >= 0}
            && {_followupIndex < count _followupDelays}
            && {
                diag_tickTime - _followupStartedAt
                >= (_followupDelays select _followupIndex)
            }
        ) then {
            private _after = diag_tickTime - _followupStartedAt;
            private _details = [
                _unit,
                _commander,
                _samePlayerGroup,
                _selected,
                _menu,
                _assigned,
                _attack,
                ["scheduled-followup"],
                _after
            ] call _makeSnapshot;
            private _rptDetails = [
                ["unit", str _unit],
                ["after", _after],
                ["selected", _selected],
                ["menu", _menu],
                ["targets", [
                    if (isNull _assigned) then {""} else {typeOf _assigned},
                    if (isNull _attack) then {""} else {typeOf _attack}
                ]],
                ["command", currentCommand _unit],
                ["unitState", getUnitState _unit],
                ["weapon", [
                    currentWeapon _unit,
                    currentWeaponMode _unit,
                    _launcherClass,
                    _launcherState param [3, ""],
                    _launcherRoundCount
                ]],
                ["combat", [
                    unitCombatMode _unit,
                    combatMode _unitGroup,
                    attackEnabled _unitGroup
                ]]
            ];
            [
                objNull,
                "ORDER_FOLLOWUP",
                _details,
                _traceId,
                _rptDetails
            ] call bskulls_fnc_titanTopAttackLog;
            _followupIndex = _followupIndex + 1;
            if (_followupIndex >= count _followupDelays) then {
                _followupStartedAt = -1;
            };
        };

        _lastState = _state;
    [
        _unit,
        "order-debug-state",
        [_lastState, _followupStartedAt, _followupIndex, _lastNoiseLogAt]
    ] call bskulls_fnc_titanTopAttackRuntimeSet;
}, 0.25, [_unit, _traceId]] call CBA_fnc_addPerFrameHandler;

[_unit, "order-debug-pfh", _handle] call bskulls_fnc_titanTopAttackRuntimeSet;
true
