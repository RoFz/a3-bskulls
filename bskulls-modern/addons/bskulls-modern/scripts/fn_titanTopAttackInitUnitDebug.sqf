/*
 * Trace the AI decision state of the dedicated top-attack Hawkins variant.
 * Projectile events cannot diagnose a launcher that is never selected or
 * fired, so this records target knowledge and weapon state at a low rate.
 */

params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {false};

private _oldHandle = _unit getVariable ["bskulls_titanTopAttackUnitDebugHandle", scriptNull];
if (
    !local _unit
    || {!alive _unit}
    || {isPlayer _unit}
    || {!(missionNamespace getVariable ["bskulls_titanTopAttackDebug", false])}
) exitWith {
    if (!scriptDone _oldHandle) then {
        terminate _oldHandle;
    };
    _unit setVariable ["bskulls_titanTopAttackUnitDebugHandle", scriptNull, false];
    false
};

if (!scriptDone _oldHandle) exitWith {true};

private _unitId = netId _unit;
if (_unitId isEqualTo "") then {
    _unitId = str _unit;
};
private _traceId = format ["unit-%1", _unitId];

private _handle = [_unit, _traceId] spawn {
    params ["_unit", "_traceId"];

    private _lastLoggedState = [];
    private _lastLogAt = -1e10;
    private _carrierConfig = configFile >> "CfgAmmo" >> "M_Titan_AT_TOP_PLUS";
    private _lockMinDistance = getNumber (_carrierConfig >> "missileLockMinDistance");
    private _lockMaxDistance = getNumber (_carrierConfig >> "missileLockMaxDistance");
    if (_lockMinDistance <= 0) then {
        _lockMinDistance = 900;
    };
    if (_lockMaxDistance <= _lockMinDistance) then {
        _lockMaxDistance = 4000;
    };
    private _diagnosticScanDistance = _lockMaxDistance + 500;
    private _angleBetween = {
        params ["_left", "_right"];

        if (
            (vectorMagnitude _left) <= 0
            || {(vectorMagnitude _right) <= 0}
        ) exitWith {-1};

        acos (((_left vectorCos _right) max -1) min 1)
    };
    private _pairValue = {
        params ["_pairs", "_key", "_default"];

        private _index = _pairs findIf {
            (_x param [0, "", [""]]) isEqualTo _key
        };
        if (_index < 0) exitWith {_default};
        (_pairs select _index) param [1, _default]
    };
    private _describeKnowledge = {
        params ["_observer", "_target"];

        if (isNull _target) exitWith {
            [
                ["knownByGroup", false],
                ["knownByUnit", false],
                ["lastSeen", -1],
                ["lastSeenAge", -1],
                ["lastThreat", -1],
                ["lastThreatAge", -1],
                ["knowledgeSide", "UNKNOWN"],
                ["knowledgePositionError", -1],
                ["knowledgePosition", []],
                ["ignoredTarget", false]
            ]
        };

        // targetKnowledge distinguishes group knowledge from the shooter's
        // own observation and exposes when and where the target was perceived.
        // https://community.bohemia.net/wiki/targetKnowledge
        private _knowledge = _observer targetKnowledge _target;
        private _lastSeen = _knowledge param [2, -1, [0]];
        private _lastThreat = _knowledge param [3, -1, [0]];
        [
            ["knownByGroup", _knowledge param [0, false, [false]]],
            ["knownByUnit", _knowledge param [1, false, [false]]],
            ["lastSeen", _lastSeen],
            ["lastSeenAge", if (_lastSeen < 0) then {-1} else {(time - _lastSeen) max 0}],
            ["lastThreat", _lastThreat],
            ["lastThreatAge", if (_lastThreat < 0) then {-1} else {(time - _lastThreat) max 0}],
            ["knowledgeSide", str (_knowledge param [4, sideUnknown])],
            ["knowledgePositionError", _knowledge param [5, -1, [0]]],
            ["knowledgePosition", _knowledge param [6, [], [[]]]],
            ["ignoredTarget", _knowledge param [7, false, [false]]]
        ]
    };
    private _describeGeometry = {
        params ["_observer", "_target"];

        if (isNull _target) exitWith {
            [
                ["targetAimPositionASL", []],
                ["bearing", -1],
                ["relativeBearing", -1],
                ["eyeTargetAngle", -1],
                ["weaponTargetAngle", -1],
                ["viewVisibility", 0],
                ["fireVisibility", 0],
                ["terrainBlocked", false],
                ["viewBlocked", false],
                ["viewBlockPositionASL", []],
                ["viewBlockObject", "<NULL-object>"],
                ["viewBlockClass", ""],
                ["viewBlockParent", "<NULL-object>"],
                ["viewBlockParentClass", ""]
            ]
        };

        private _eyePositionASL = eyePos _observer;
        private _targetAimPositionASL = aimPos _target;
        private _targetDirection = _eyePositionASL vectorFromTo _targetAimPositionASL;
        private _eyeDirection = eyeDirection _observer;
        private _activeWeapon = currentWeapon _observer;
        private _weaponDirection = if (_activeWeapon isEqualTo "") then {
            [0, 0, 0]
        } else {
            _observer weaponDirection _activeWeapon
        };
        private _bearing = _observer getDir _target;
        private _relativeBearing = ((_bearing - getDir _observer + 540) mod 360) - 180;

        // checkVisibility reports partial VIEW/FIRE occlusion. The first VIEW
        // intersection identifies the obstructing object or terrain surface.
        // https://community.bohemia.net/wiki/checkVisibility
        // https://community.bohemia.net/wiki/lineIntersectsSurfaces
        private _viewVisibility = [_observer, "VIEW", _target] checkVisibility [
            _eyePositionASL,
            _targetAimPositionASL
        ];
        private _fireVisibility = [_observer, "FIRE", _target] checkVisibility [
            _eyePositionASL,
            _targetAimPositionASL
        ];
        private _viewIntersections = lineIntersectsSurfaces [
            _eyePositionASL,
            _targetAimPositionASL,
            _observer,
            _target,
            true,
            1,
            "VIEW",
            "NONE"
        ];
        private _firstIntersection = _viewIntersections param [0, []];
        private _blockingObject = _firstIntersection param [2, objNull, [objNull]];
        private _blockingParent = _firstIntersection param [3, objNull, [objNull]];

        [
            ["targetAimPositionASL", _targetAimPositionASL],
            ["bearing", _bearing],
            ["relativeBearing", _relativeBearing],
            ["eyeTargetAngle", [_eyeDirection, _targetDirection] call _angleBetween],
            ["weaponTargetAngle", [_weaponDirection, _targetDirection] call _angleBetween],
            ["viewVisibility", _viewVisibility],
            ["fireVisibility", _fireVisibility],
            ["terrainBlocked", terrainIntersectASL [_eyePositionASL, _targetAimPositionASL]],
            ["viewBlocked", _firstIntersection isNotEqualTo []],
            ["viewBlockPositionASL", _firstIntersection param [0, []]],
            ["viewBlockObject", if (isNull _blockingObject) then {"<NULL-object>"} else {str _blockingObject}],
            ["viewBlockClass", if (isNull _blockingObject) then {""} else {typeOf _blockingObject}],
            ["viewBlockParent", if (isNull _blockingParent) then {"<NULL-object>"} else {str _blockingParent}],
            ["viewBlockParentClass", if (isNull _blockingParent) then {""} else {typeOf _blockingParent}]
        ]
    };
    private _describeTarget = {
        params ["_observer", "_target", "_remoteTargets"];

        if (isNull _target) exitWith {
            [
                ["object", "<NULL-object>"],
                ["class", ""],
                ["actualPositionATL", []],
                ["actualPositionASL", []],
                ["isLandVehicle", false],
                ["alive", false],
                ["distance2D", -1],
                ["distance3D", -1],
                ["side", "UNKNOWN"],
                ["crewCount", 0],
                ["engineOn", false],
                ["speed", 0],
                ["knowsAbout", 0],
                ["irTarget", 0],
                ["isTank", false],
                ["isWheeledAPC", false],
                ["isTruck", false],
                ["armor", 0],
                ["threat", []],
                ["remoteTarget", false],
                ["remoteTargetInfo", []]
            ]
            + ([_observer, _target] call _describeKnowledge)
            + ([_observer, _target] call _describeGeometry)
        };

        private _remoteIndex = _remoteTargets findIf {
            (_x param [0, objNull, [objNull]]) isEqualTo _target
        };
        private _remoteInfo = if (_remoteIndex < 0) then {
            []
        } else {
            +(_remoteTargets select _remoteIndex)
        };
        private _targetClass = typeOf _target;
        [
            ["object", str _target],
            ["class", _targetClass],
            ["actualPositionATL", getPosATL _target],
            ["actualPositionASL", getPosASL _target],
            ["isLandVehicle", _target isKindOf "LandVehicle"],
            ["alive", alive _target],
            ["distance2D", _observer distance2D _target],
            ["distance3D", _observer distance _target],
            ["side", str side _target],
            ["crewCount", count crew _target],
            ["engineOn", isEngineOn _target],
            ["speed", speed _target],
            ["knowsAbout", _observer knowsAbout _target],
            ["irTarget", getNumber (configOf _target >> "irTarget")],
            ["isTank", _target isKindOf "Tank"],
            ["isWheeledAPC", _target isKindOf "Wheeled_APC_F"],
            ["isTruck", _target isKindOf "Truck_F"],
            ["armor", getNumber (configOf _target >> "armor")],
            ["threat", getArray (configOf _target >> "threat")],
            ["remoteTarget", _remoteIndex >= 0],
            ["remoteTargetInfo", _remoteInfo]
        ]
        + ([_observer, _target] call _describeKnowledge)
        + ([_observer, _target] call _describeGeometry)
    };

    while {
        !isNull _unit
        && {alive _unit}
        && {local _unit}
        && {!isPlayer _unit}
        && {missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]}
    } do {
        private _remoteTargets = listRemoteTargets (side (group _unit));
        private _assignedTarget = assignedTarget _unit;
        private _attackTarget = getAttackTarget _unit;
        private _assignedIsVehicle = !isNull _assignedTarget && {_assignedTarget isKindOf "LandVehicle"};
        private _attackIsVehicle = !isNull _attackTarget && {_attackTarget isKindOf "LandVehicle"};
        private _assignedTargetState = [
            _unit,
            _assignedTarget,
            _remoteTargets
        ] call _describeTarget;
        private _attackTargetState = [
            _unit,
            _attackTarget,
            _remoteTargets
        ] call _describeTarget;
        // Prefer a player's explicit assignment for the diagnostic focus. The
        // engine attack target is retained separately so a stale choice is
        // visible instead of masking the assigned vehicle and its range.
        private _focusTarget = if (_assignedIsVehicle) then {
            _assignedTarget
        } else {
            if (_attackIsVehicle) then {
                _attackTarget
            } else {
                [_assignedTarget, _attackTarget] select (!isNull _attackTarget)
            }
        };
        private _focusIsVehicle = !isNull _focusTarget && {_focusTarget isKindOf "LandVehicle"};
        private _targetDistance2D = if (isNull _focusTarget) then {-1} else {_unit distance2D _focusTarget};
        private _targetDistance3D = if (isNull _focusTarget) then {-1} else {_unit distance _focusTarget};
        private _rangeState = if (isNull _focusTarget) then {
            "no-current-target"
        } else {
            if (!_focusIsVehicle) then {
                "current-target-not-land-vehicle"
            } else {
                if (!alive _focusTarget) then {
                    "target-dead"
                } else {
                    if (_targetDistance2D < _lockMinDistance) then {
                        format ["inside-%1m-safety-minimum", round _lockMinDistance]
                    } else {
                        [
                            "inside-top-attack-envelope",
                            format ["outside-%1m-lock-maximum", round _lockMaxDistance]
                        ] select (_targetDistance2D > _lockMaxDistance)
                    }
                }
            }
        };

        private _missileInventory = (magazinesAmmoFull _unit) select {
            (_x param [0, ""]) isEqualTo "Titan_AT_TOP_PLUS"
        };
        private _missileCount = count _missileInventory;

        private _knownArmor = [];
        {
            private _knownObject = _x param [4, objNull, [objNull]];
            if (
                !isNull _knownObject
                && {alive _knownObject}
                && {_knownObject isKindOf "LandVehicle"}
                && {(_x param [3, 0]) > 0}
            ) then {
                private _remoteIndex = _remoteTargets findIf {
                    (_x param [0, objNull, [objNull]]) isEqualTo _knownObject
                };
                private _remoteInfo = if (_remoteIndex < 0) then {
                    []
                } else {
                    +(_remoteTargets select _remoteIndex)
                };
                _knownArmor pushBack (
                    [
                        ["object", str _knownObject],
                        ["class", typeOf _knownObject],
                        ["actualPositionATL", getPosATL _knownObject],
                        ["actualPositionASL", getPosASL _knownObject],
                        ["side", str (_x param [2, sideUnknown])],
                        ["distance2D", _unit distance2D _knownObject],
                        ["distance3D", _unit distance _knownObject],
                        ["engineOn", isEngineOn _knownObject],
                        ["speed", speed _knownObject],
                        ["irTarget", getNumber (configOf _knownObject >> "irTarget")],
                        ["knowsAbout", _unit knowsAbout _knownObject],
                        ["subjectiveCost", _x param [3, 0]],
                        ["nearTargetsPosition", _x param [0, [], [[]]]],
                        ["positionAccuracy", _x param [5, -1]],
                        ["remoteTarget", _remoteIndex >= 0],
                        ["remoteTargetInfo", _remoteInfo],
                        ["dapsType", _knownObject getVariable ["dapsType", ""]],
                        ["dapsActive", _knownObject getVariable ["dapsActive", false]]
                    ]
                    + ([_unit, _knownObject] call _describeKnowledge)
                    + ([_unit, _knownObject] call _describeGeometry)
                );
            };
        } forEach (_unit nearTargets _diagnosticScanDistance);
        if ((count _knownArmor) > 6) then {
            _knownArmor resize 6;
        };

        // nearTargets only contains objects already known to the AI. Compare
        // it with the real nearby vehicle population so the RPT distinguishes
        // acquisition failure from a later range, visibility, lock, weapon,
        // or command refusal. This scan exists only while diagnostics run.
        private _observerSide = side group _unit;
        private _physicalEnemyCandidates = [];
        {
            private _candidate = _x;
            private _distance = _unit distance2D _candidate;
            private _candidateSide = side _candidate;
            if (
                alive _candidate
                && {_candidate isKindOf "LandVehicle"}
                && {_distance <= _diagnosticScanDistance}
                && {_candidateSide isNotEqualTo sideUnknown}
                && {(_observerSide getFriend _candidateSide) < 0.6}
            ) then {
                _physicalEnemyCandidates pushBack [
                    _distance,
                    typeOf _candidate,
                    _candidate
                ];
            };
        } forEach vehicles;
        _physicalEnemyCandidates sort true;
        if ((count _physicalEnemyCandidates) > 6) then {
            _physicalEnemyCandidates resize 6;
        };
        private _physicalEnemyVehicles = _physicalEnemyCandidates apply {
            private _candidate = _x select 2;
            [
                ["assigned", _candidate isEqualTo _assignedTarget],
                ["attack", _candidate isEqualTo _attackTarget]
            ]
            + ([_unit, _candidate, _remoteTargets] call _describeTarget)
        };
        private _physicalEnemyState = _physicalEnemyVehicles apply {
            [
                [_x, "class", ""] call _pairValue,
                round (([_x, "distance2D", -1] call _pairValue) / 25),
                round (([_x, "knowsAbout", 0] call _pairValue) * 20),
                [_x, "engineOn", false] call _pairValue,
                ([_x, "viewVisibility", 0] call _pairValue) > 0,
                ([_x, "fireVisibility", 0] call _pairValue) > 0,
                [_x, "terrainBlocked", false] call _pairValue
            ]
        };

        private _groupLeader = leader group _unit;
        private _connectedUAV = getConnectedUAV _groupLeader;
        private _groupContext = [
            ["group", str group _unit],
            ["leader", str _groupLeader],
            ["leaderLocal", local _groupLeader],
            ["leaderIsPlayer", isPlayer _groupLeader],
            ["connectedUAV", if (isNull _connectedUAV) then {"<NULL-object>"} else {str _connectedUAV}],
            ["connectedUAVClass", if (isNull _connectedUAV) then {""} else {typeOf _connectedUAV}],
            ["sideRemoteTargetCount", count _remoteTargets]
        ];

        private _activeWeapon = currentWeapon _unit;
        private _observerState = [
            ["positionATL", getPosATL _unit],
            ["positionASL", getPosASL _unit],
            ["eyePositionASL", eyePos _unit],
            ["direction", getDir _unit],
            ["eyeDirection", eyeDirection _unit],
            ["weaponDirection", if (_activeWeapon isEqualTo "") then {
                [0, 0, 0]
            } else {
                _unit weaponDirection _activeWeapon
            }],
            ["stance", stance _unit],
            ["animationState", animationState _unit],
            ["simulationEnabled", simulationEnabled _unit],
            ["lifeState", lifeState _unit]
        ];
        // skillFinal includes the active difficulty preset coefficients. The
        // two spotting subskills directly affect acquisition distance, target
        // information precision, and reaction time.
        // https://community.bohemia.net/wiki/skillFinal
        private _aiSkills = [
            ["overall", skill _unit],
            ["general", _unit skillFinal "general"],
            ["spotDistance", _unit skillFinal "spotDistance"],
            ["spotTime", _unit skillFinal "spotTime"],
            ["commanding", _unit skillFinal "commanding"],
            ["courage", _unit skillFinal "courage"]
        ];

        private _targetDaps = if (isNull _focusTarget) then {
            []
        } else {
            [
                ["type", _focusTarget getVariable ["dapsType", ""]],
                ["active", _focusTarget getVariable ["dapsActive", false]],
                ["ammo", _focusTarget getVariable ["dapsAmmo", -1]],
                ["ammoLeft", _focusTarget getVariable ["dapsAmmoL", -1]],
                ["ammoRight", _focusTarget getVariable ["dapsAmmoR", -1]]
            ]
        };

        private _aiFeatures = [
            ["TARGET", _unit checkAIFeature "TARGET"],
            ["AUTOTARGET", _unit checkAIFeature "AUTOTARGET"],
            ["WEAPONAIM", _unit checkAIFeature "WEAPONAIM"],
            ["FSM", _unit checkAIFeature "FSM"],
            ["AUTOCOMBAT", _unit checkAIFeature "AUTOCOMBAT"],
            ["FIREWEAPON", _unit checkAIFeature "FIREWEAPON"]
        ];

        private _focusTargetState = [
            _attackTargetState,
            _assignedTargetState
        ] select (_focusTarget isEqualTo _assignedTarget);
        private _focusClass = [_focusTargetState, "class", ""] call _pairValue;
        private _focusEngineOn = [_focusTargetState, "engineOn", false] call _pairValue;
        private _focusSpeed = [_focusTargetState, "speed", 0] call _pairValue;
        private _focusKnowsAbout = [_focusTargetState, "knowsAbout", 0] call _pairValue;
        private _focusIrTarget = [_focusTargetState, "irTarget", 0] call _pairValue;
        private _focusLastSeenAge = [_focusTargetState, "lastSeenAge", -1] call _pairValue;
        private _focusRemote = [_focusTargetState, "remoteTarget", false] call _pairValue;
        private _focusView = [_focusTargetState, "viewVisibility", 0] call _pairValue;
        private _focusFire = [_focusTargetState, "fireVisibility", 0] call _pairValue;
        private _focusTerrainBlocked = [_focusTargetState, "terrainBlocked", false] call _pairValue;
        private _focusBearing = [_focusTargetState, "relativeBearing", -1] call _pairValue;
        private _focusEyeAngle = [_focusTargetState, "eyeTargetAngle", -1] call _pairValue;

        // These are observed constraints, not a claim about an inaccessible
        // internal AI decision. In particular, an engine-off IR target can
        // remain hot for some time after shutdown.
        // https://community.bohemia.net/wiki/A3_Targeting_config_reference
        private _observedConstraints = [];
        if ((unitCombatMode _unit) isEqualTo "BLUE") then {
            _observedConstraints pushBack "unit-blue";
        };
        if ((combatMode group _unit) isEqualTo "BLUE") then {
            _observedConstraints pushBack "group-blue";
        };
        if (isNull _focusTarget) then {
            _observedConstraints pushBack "no-target";
        } else {
            if (!_focusIsVehicle) then {
                _observedConstraints pushBack "not-vehicle";
            };
            if (!alive _focusTarget) then {
                _observedConstraints pushBack "dead";
            };
            if (_targetDistance2D < _lockMinDistance) then {
                _observedConstraints pushBack "below-min";
            };
            if (_targetDistance2D > _lockMaxDistance) then {
                _observedConstraints pushBack "above-max";
            };
            if (_focusKnowsAbout <= 0) then {
                _observedConstraints pushBack "unknown";
            };
            if (_focusIrTarget <= 0) then {
                _observedConstraints pushBack "ir-disabled";
            };
            if (!_focusEngineOn) then {
                _observedConstraints pushBack "engine-off";
            };
            if (_focusTerrainBlocked) then {
                _observedConstraints pushBack "terrain";
            };
            if (_focusView <= 0) then {
                _observedConstraints pushBack "no-view";
            };
            if (_focusFire <= 0) then {
                _observedConstraints pushBack "no-fire";
            };
            if (_focusLastSeenAge > 30 && {_focusView <= 0}) then {
                _observedConstraints pushBack "stale/remote";
            };
        };
        if ((currentWeapon _unit) isNotEqualTo "B_PTbskull_Wea_law_02_titantop") then {
            _observedConstraints pushBack "weapon-not-selected";
        };
        if (_missileCount <= 0) then {
            _observedConstraints pushBack "no-ammo";
        };
        if !(canFire _unit) then {
            _observedConstraints pushBack "cannot-fire";
        };

        private _physicalKnownCount = {
            ([_x, "knowsAbout", 0] call _pairValue) > 0
        } count _physicalEnemyVehicles;
        private _physicalEnvelopeCount = {
            private _distance = [_x, "distance2D", -1] call _pairValue;
            _distance >= _lockMinDistance && {_distance <= _lockMaxDistance}
        } count _physicalEnemyVehicles;
        private _physicalVisibleEnvelopeCount = {
            private _distance = [_x, "distance2D", -1] call _pairValue;
            _distance >= _lockMinDistance
            && {_distance <= _lockMaxDistance}
            && {([_x, "viewVisibility", 0] call _pairValue) > 0}
            && {([_x, "fireVisibility", 0] call _pairValue) > 0}
            && {!([_x, "terrainBlocked", false] call _pairValue)}
        } count _physicalEnemyVehicles;
        private _physicalRunningEnvelopeCount = {
            private _distance = [_x, "distance2D", -1] call _pairValue;
            _distance >= _lockMinDistance
            && {_distance <= _lockMaxDistance}
            && {[_x, "engineOn", false] call _pairValue}
        } count _physicalEnemyVehicles;

        private _state = [
            str _assignedTarget,
            str _attackTarget,
            _assignedTargetState,
            _attackTargetState,
            _rangeState,
            round (_targetDistance2D / 25),
            currentCommand _unit,
            currentWeapon _unit,
            currentWeaponMode _unit,
            _missileCount,
            behaviour _unit,
            combatBehaviour _unit,
            unitCombatMode _unit,
            combatMode group _unit,
            _groupContext,
            _aiSkills,
            _aiFeatures,
            _targetDaps,
            _knownArmor,
            _physicalEnemyState,
            _observedConstraints
        ];
        private _stateChanged = _state isNotEqualTo _lastLoggedState;
        private _sinceLastLog = diag_tickTime - _lastLogAt;

        if (
            _lastLoggedState isEqualTo []
            || {(_stateChanged && {_sinceLastLog >= 5})}
            || {_sinceLastLog >= 30}
        ) then {
            private _nearestPhysical = _physicalEnemyVehicles apply {
                [
                    [_x, "class", ""] call _pairValue,
                    round ([_x, "distance2D", -1] call _pairValue),
                    round (([_x, "knowsAbout", 0] call _pairValue) * 100) / 100,
                    [_x, "engineOn", false] call _pairValue,
                    round (([_x, "viewVisibility", 0] call _pairValue) * 100) / 100,
                    [_x, "terrainBlocked", false] call _pairValue
                ]
            };
            if ((count _nearestPhysical) > 2) then {
                _nearestPhysical resize 2;
            };
            private _rptDetails = [
                ["unit", str _unit],
                ["targets", [
                    [_assignedTargetState, "class", ""] call _pairValue,
                    [_attackTargetState, "class", ""] call _pairValue,
                    _focusClass
                ]],
                ["focus", [
                    round _targetDistance2D,
                    _focusEngineOn,
                    round _focusSpeed,
                    round (_focusKnowsAbout * 100) / 100,
                    round _focusLastSeenAge,
                    _focusRemote,
                    round (_focusView * 100) / 100,
                    round (_focusFire * 100) / 100,
                    _focusTerrainBlocked,
                    round _focusBearing,
                    round _focusEyeAngle
                ]],
                ["weapon", [
                    currentWeapon _unit,
                    currentWeaponMode _unit,
                    currentCommand _unit,
                    _missileCount,
                    canFire _unit
                ]],
                ["combat", [
                    unitCombatMode _unit,
                    combatMode group _unit,
                    behaviour _unit
                ]],
                ["constraints", _observedConstraints],
                ["physical", [
                    count _physicalEnemyVehicles,
                    _physicalKnownCount,
                    _physicalEnvelopeCount,
                    _physicalVisibleEnvelopeCount,
                    _physicalRunningEnvelopeCount
                ]],
                ["nearest", _nearestPhysical]
            ];
            [
                objNull,
                "UNIT_STATE",
                [
                    ["unit", str _unit],
                    ["unitClass", typeOf _unit],
                    ["unitLocal", local _unit],
                    ["assignedTarget", str _assignedTarget],
                    ["assignedTargetState", _assignedTargetState],
                    ["attackTarget", str _attackTarget],
                    ["attackTargetState", _attackTargetState],
                    ["focusTarget", str _focusTarget],
                    ["focusTargetClass", if (isNull _focusTarget) then {""} else {typeOf _focusTarget}],
                    ["focusTargetIsLandVehicle", _focusIsVehicle],
                    ["focusTargetAlive", !isNull _focusTarget && {alive _focusTarget}],
                    ["targetDistance2D", _targetDistance2D],
                    ["targetDistance3D", _targetDistance3D],
                    ["rangeState", _rangeState],
                    ["currentCommand", currentCommand _unit],
                    ["currentWeapon", currentWeapon _unit],
                    ["currentMuzzle", currentMuzzle _unit],
                    ["currentWeaponMode", currentWeaponMode _unit],
                    ["weaponState", weaponState _unit],
                    ["secondaryWeapon", secondaryWeapon _unit],
                    ["secondaryWeaponMagazine", secondaryWeaponMagazine _unit],
                    ["topAttackMissileCount", _missileCount],
                    ["topAttackMissiles", _missileInventory],
                    ["canFire", canFire _unit],
                    ["unitReady", unitReady _unit],
                    ["behaviour", behaviour _unit],
                    ["combatBehaviour", combatBehaviour _unit],
                    ["unitCombatMode", unitCombatMode _unit],
                    ["groupCombatMode", combatMode group _unit],
                    ["groupContext", _groupContext],
                    ["observerState", _observerState],
                    ["aiSkills", _aiSkills],
                    ["aiFeatures", _aiFeatures],
                    ["targetDaps", _targetDaps],
                    ["knownArmor", _knownArmor],
                    ["physicalEnemyVehicles", _physicalEnemyVehicles],
                    ["observedConstraints", _observedConstraints]
                ],
                _traceId,
                _rptDetails
            ] call bskulls_fnc_titanTopAttackLog;

            _lastLoggedState = _state;
            _lastLogAt = diag_tickTime;
        };

        uiSleep 2;
    };

    if (!isNull _unit) then {
        _unit setVariable ["bskulls_titanTopAttackUnitDebugHandle", scriptNull, false];
    };
};

_unit setVariable ["bskulls_titanTopAttackUnitDebugHandle", _handle, false];
true
