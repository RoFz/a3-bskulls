/*
 * Render the fuel backpack as a client-local vanilla jerrycan attached to the
 * wearer's torso. The backpack class uses an empty carrier model because the
 * legacy-generated nested proxy does not receive the character transform.
 *
 * attachTo's followBoneRotation argument makes the visual follow spine3 while
 * the unit changes stance. The real backpack container remains responsible for
 * inventory and transportFuel; this simple object is only its visible shell.
 * Keep the shell off units inside vehicles; the attached visual was confirmed
 * to disrupt AI Huron navigation in a controlled test.
 * https://community.bohemia.net/wiki/attachTo
 */

if (!hasInterface) exitWith {false};
if (!isNil {missionNamespace getVariable "bskulls_jerrycanBackpackVisualPFH"}) exitWith {true};

private _backpackClass = "B_PTbskull_Veh_Back_Fuel_blackops_01";
private _modelPath = "\A3\Structures_F\Items\Vessels\CanisterFuel_F.p3d";
private _memoryPoint = "spine3";

// In-game calibrated against Frost's loadout: [right, forward, up].
private _offset = [-0.0247, -0.2088, 0.00560001];
private _direction = [0.258819, 0.965926, 0];
private _up = [0, 0, 1];

missionNamespace setVariable ["bskulls_jerrycanBackpackVisuals", []];

private _handle = [{
    params ["_arguments"];
    _arguments params [
        "_backpackClass",
        "_modelPath",
        "_memoryPoint",
        "_offset",
        "_direction",
        "_up"
    ];

    private _tracked = missionNamespace getVariable ["bskulls_jerrycanBackpackVisuals", []];

    // Remove visuals that are stale, no longer worn, or carried into a vehicle.
    for "_index" from ((count _tracked) - 1) to 0 step -1 do {
        (_tracked # _index) params ["_unit", "_container", "_visual"];

        private _currentContainer = if (isNull _unit) then {
            objNull
        } else {
            backpackContainer _unit
        };

        if (
            isNull _unit
            || {isNull _visual}
            || {!(isNull (objectParent _unit))}
            || {backpack _unit isNotEqualTo _backpackClass}
            || {_currentContainer isNotEqualTo _container}
        ) then {
            if (!isNull _visual) then {
                deleteVehicle _visual;
            };
            _tracked deleteAt _index;
        };
    };

    {
        private _unit = _x;
        private _alreadyTracked = _tracked findIf {(_x # 0) isEqualTo _unit};

        if (
            isNull (objectParent _unit)
            && {backpack _unit isEqualTo _backpackClass}
            && {_alreadyTracked < 0}
        ) then {
            private _container = backpackContainer _unit;

            if (!isNull _container) then {
                private _visual = createSimpleObject [_modelPath, getPosWorld _unit, true];

                if (!isNull _visual) then {
                    _visual attachTo [_unit, _offset, _memoryPoint, true];
                    _visual setVectorDirAndUp [_direction, _up];
                    _tracked pushBack [_unit, _container, _visual];
                };
            };
        };
    } forEach (allUnits + allDeadMen);

    missionNamespace setVariable ["bskulls_jerrycanBackpackVisuals", _tracked];
}, 0.5, [
    _backpackClass,
    _modelPath,
    _memoryPoint,
    _offset,
    _direction,
    _up
]] call CBA_fnc_addPerFrameHandler;

missionNamespace setVariable ["bskulls_jerrycanBackpackVisualPFH", _handle];

true
