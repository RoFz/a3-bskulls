/*
 * bskulls_fnc_formatKillSource
 *
 * Short destroyer label for air-loss messages:
 *   - Man on foot  -> unit class displayName (Rifleman, AT Specialist, …)
 *   - Man in vehicle / vehicle killer -> vehicle displayName
 */

params [
    ["_killer", objNull, [objNull]],
    ["_instigator", objNull, [objNull]]
];

private _fnc_vehicleLabel = {
    params ["_obj"];
    if (isNull _obj) exitWith { "" };
    getText (configOf _obj >> "displayName")
};

private _fnc_unitRole = {
    params ["_unit"];
    if (isNull _unit || {!(_unit isKindOf "Man")}) exitWith { "unknown" };
    getText (configOf _unit >> "displayName")
};

private _agent = [_killer, _instigator] select (!isNull _instigator);
if (isNull _agent) exitWith { "unknown" };

if (_agent isKindOf "AllVehicles" && {!(_agent isKindOf "Man")}) exitWith {
    [_agent] call _fnc_vehicleLabel
};

if (_agent isKindOf "Man") exitWith {
    private _veh = vehicle _agent;
    if (_veh != _agent) exitWith { [_veh] call _fnc_vehicleLabel };
    [_agent] call _fnc_unitRole
};

private _label = [_agent] call _fnc_vehicleLabel;
[_label, "unknown"] select (_label isEqualTo "");
