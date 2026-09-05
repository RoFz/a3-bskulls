// Killed EH for BS helos/planes — keep unscheduled.
params ["_vehicle", "_killer", "_instigator"];

if (!local _vehicle) exitWith {};

[_vehicle, _killer, _instigator] call bskulls_fnc_reportAirDestroyed;
