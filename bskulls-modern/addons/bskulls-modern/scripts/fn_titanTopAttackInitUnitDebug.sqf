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

    while {
        !isNull _unit
        && {alive _unit}
        && {local _unit}
        && {!isPlayer _unit}
        && {missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]}
    } do {
        private _assignedTarget = assignedTarget _unit;
        private _attackTarget = getAttackTarget _unit;
        private _assignedIsVehicle = !isNull _assignedTarget && {_assignedTarget isKindOf "LandVehicle"};
        private _attackIsVehicle = !isNull _attackTarget && {_attackTarget isKindOf "LandVehicle"};
        private _focusTarget = if (_attackIsVehicle) then {
            _attackTarget
        } else {
            if (_assignedIsVehicle) then {
                _assignedTarget
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
                    if (_targetDistance2D < 900) then {
                        "inside-900m-safety-minimum"
                    } else {
                        [
                            "inside-top-attack-envelope",
                            "outside-2000m-lock-maximum"
                        ] select (_targetDistance2D > 2000)
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
                _knownArmor pushBack [
                    ["object", str _knownObject],
                    ["class", typeOf _knownObject],
                    ["side", str (_x param [2, sideUnknown])],
                    ["distance2D", _unit distance2D _knownObject],
                    ["knowsAbout", _unit knowsAbout _knownObject],
                    ["subjectiveCost", _x param [3, 0]],
                    ["positionAccuracy", _x param [5, -1]],
                    ["dapsType", _knownObject getVariable ["dapsType", ""]],
                    ["dapsActive", _knownObject getVariable ["dapsActive", false]]
                ];
            };
        } forEach (_unit nearTargets 2500);
        if ((count _knownArmor) > 6) then {
            _knownArmor resize 6;
        };

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

        private _state = [
            str _assignedTarget,
            str _attackTarget,
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
            _targetDaps,
            _knownArmor
        ];
        private _stateChanged = _state isNotEqualTo _lastLoggedState;
        private _sinceLastLog = diag_tickTime - _lastLogAt;

        if (
            _lastLoggedState isEqualTo []
            || {(_stateChanged && {_sinceLastLog >= 5})}
            || {_sinceLastLog >= 30}
        ) then {
            [
                objNull,
                "UNIT_STATE",
                [
                    ["unit", str _unit],
                    ["unitClass", typeOf _unit],
                    ["unitLocal", local _unit],
                    ["assignedTarget", str _assignedTarget],
                    ["attackTarget", str _attackTarget],
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
                    ["targetDaps", _targetDaps],
                    ["knownArmor", _knownArmor]
                ],
                _traceId
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
