/*
 * Trace the local player's command path to a Hawkins unit without issuing or
 * modifying any commands. The normal unit-state monitor intentionally runs at
 * a low rate because its visibility scans are expensive; this companion loop
 * samples only lightweight order state so short FIRE/ATTACK transitions are
 * not missed.
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
 */

params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {false};

private _oldHandle = _unit getVariable [
    "bskulls_titanTopAttackOrderDebugHandle",
    scriptNull
];
if (
    !hasInterface
    || {!local _unit}
    || {!alive _unit}
    || {isPlayer _unit}
    || {!(missionNamespace getVariable ["bskulls_titanTopAttackDebug", false])}
) exitWith {
    if (!scriptDone _oldHandle) then {
        terminate _oldHandle;
    };
    _unit setVariable [
        "bskulls_titanTopAttackOrderDebugHandle",
        scriptNull,
        false
    ];
    false
};

if (!scriptDone _oldHandle) exitWith {true};

private _unitId = netId _unit;
if (_unitId isEqualTo "") then {
    _unitId = str _unit;
};
private _traceId = format ["unit-%1", _unitId];

private _weaponChangedEh = _unit getVariable [
    "bskulls_titanTopAttackWeaponChangedDebugEh",
    -1
];
if (_weaponChangedEh < 0) then {
    _weaponChangedEh = _unit addEventHandler ["WeaponChanged", {
        params [
            "_object",
            "_oldWeapon",
            "_newWeapon",
            "_oldMode",
            "_newMode",
            "_oldMuzzle",
            "_newMuzzle",
            "_turretPath"
        ];

        if (
            local _object
            && {missionNamespace getVariable [
                "bskulls_titanTopAttackDebug",
                false
            ]}
        ) then {
            private _assigned = assignedTarget _object;
            private _attack = getAttackTarget _object;
            private _eventUnitId = netId _object;
            if (_eventUnitId isEqualTo "") then {
                _eventUnitId = str _object;
            };
            private _eventTraceId = format ["unit-%1", _eventUnitId];
            private _details = [
                ["unit", str _object],
                ["old", [_oldWeapon, _oldMuzzle, _oldMode]],
                ["new", [_newWeapon, _newMuzzle, _newMode]],
                ["turretPath", _turretPath],
                ["assignedTarget", if (isNull _assigned) then {[]} else {
                    [str _assigned, typeOf _assigned]
                }],
                ["attackTarget", if (isNull _attack) then {[]} else {
                    [str _attack, typeOf _attack]
                }],
                ["currentCommand", currentCommand _object],
                ["unitState", getUnitState _object],
                ["combat", [
                    unitCombatMode _object,
                    combatMode group _object,
                    behaviour _object
                ]],
                ["weaponState", weaponState _object]
            ];
            [
                objNull,
                "WEAPON_CHANGED",
                _details,
                _eventTraceId,
                _details
            ] call bskulls_fnc_titanTopAttackLog;
        };
    }];
    _unit setVariable [
        "bskulls_titanTopAttackWeaponChangedDebugEh",
        _weaponChangedEh,
        false
    ];
};

private _handle = [_unit, _traceId] spawn {
    params ["_unit", "_traceId"];

    private _lastState = [];
    private _followupStartedAt = -1;
    private _followupIndex = 0;
    private _followupDelays = [0.25, 1, 2, 5];
    private _stateLabels = [
        "same-player-group",
        "hawkins-selected",
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
        "formation-task",
        "simulation-enabled"
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
            ["distanceFromHawkins", _observer distance2D _target],
            ["distanceFromCommander", if (isNull _commander) then {-1} else {
                _commander distance2D _target
            }],
            ["engineOn", _isVehicleEntity && {isEngineOn _target}],
            ["speed", if (_isVehicleEntity) then {speed _target} else {0}],
            ["irTarget", getNumber (configOf _target >> "irTarget")],
            ["hawkinsKnowsAbout", if (_isVehicleEntity) then {
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
            ["hawkinsSelected", _selected],
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
            ["secondaryWeapon", secondaryWeapon _unit],
            ["secondaryWeaponMagazine", secondaryWeaponMagazine _unit],
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
            ["formationTask", formationTask _unit],
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

    while {
        !isNull _unit
        && {alive _unit}
        && {local _unit}
        && {!isPlayer _unit}
        && {hasInterface}
        && {missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]}
    } do {
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
            formationTask _unit,
            simulationEnabled _unit
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
        if (
            _reasons isNotEqualTo []
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
                    _weaponState param [4, 0]
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
                ["weapon", [currentWeapon _unit, currentWeaponMode _unit]],
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

        if (_samePlayerGroup) then {
            private _groupCommandEh = _unitGroup getVariable [
                "bskulls_titanTopAttackCommandChangedDebugEh",
                -1
            ];
            if (_groupCommandEh < 0) then {
                _groupCommandEh = _unitGroup addEventHandler ["CommandChanged", {
                    params ["_group", "_newCommand"];

                    if (
                        hasInterface
                        && {missionNamespace getVariable [
                            "bskulls_titanTopAttackDebug",
                            false
                        ]}
                        && {!isNull player}
                        && {_group isEqualTo group player}
                    ) then {
                        private _hawkins = units _group select {
                            _x isKindOf "B_PTbskull_Veh_Unit_Hawkins_blackops_04"
                        };
                        if (_hawkins isNotEqualTo []) then {
                            private _cursorTargetObject = cursorTarget;
                            private _cursorObjectObject = cursorObject;
                            private _details = [
                                ["group", str _group],
                                ["newCommand", _newCommand],
                                ["player", str player],
                                ["selectedUnits", (groupSelectedUnits player) apply {
                                    [str _x, typeOf _x, netId _x]
                                }],
                                ["commandingMenu", commandingMenu],
                                ["cursorTarget", if (isNull _cursorTargetObject) then {[]} else {
                                    [
                                        str _cursorTargetObject,
                                        typeOf _cursorTargetObject,
                                        player distance2D _cursorTargetObject
                                    ]
                                }],
                                ["cursorObject", if (isNull _cursorObjectObject) then {[]} else {
                                    [
                                        str _cursorObjectObject,
                                        typeOf _cursorObjectObject,
                                        player distance2D _cursorObjectObject
                                    ]
                                }],
                                ["hawkins", _hawkins apply {
                                    private _assigned = assignedTarget _x;
                                    private _attack = getAttackTarget _x;
                                    [
                                        str _x,
                                        currentCommand _x,
                                        getUnitState _x,
                                        currentWeapon _x,
                                        if (isNull _assigned) then {""} else {typeOf _assigned},
                                        if (isNull _attack) then {""} else {typeOf _attack},
                                        unitCombatMode _x,
                                        canFire _x
                                    ]
                                }]
                            ];
                            private _groupTraceId = format ["group-%1", str _group];
                            [
                                objNull,
                                "GROUP_COMMAND_CHANGED",
                                _details,
                                _groupTraceId,
                                _details
                            ] call bskulls_fnc_titanTopAttackLog;
                        };
                    };
                }];
                _unitGroup setVariable [
                    "bskulls_titanTopAttackCommandChangedDebugEh",
                    _groupCommandEh,
                    false
                ];
            };
        };

        _lastState = _state;
        uiSleep ([0.5, 0.1] select _samePlayerGroup);
    };

    if (!isNull _unit) then {
        _unit setVariable [
            "bskulls_titanTopAttackOrderDebugHandle",
            scriptNull,
            false
        ];
    };
};

_unit setVariable [
    "bskulls_titanTopAttackOrderDebugHandle",
    _handle,
    false
];
true
