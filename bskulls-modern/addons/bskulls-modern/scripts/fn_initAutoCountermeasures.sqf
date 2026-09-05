/*
 * bskulls_fnc_initAutoCountermeasures
 *
 * Registers IncomingMissile EH on CM-capable BS aircraft
 * (Wipeout, Huron, Blackfoot, Pawnee, Greyhawk, Sentinel).
 * Auto-fires flares/chaff only when an AI is driving — player pilots keep manual [C].
 * UAVs stay on auto-CM even if the player takes UAV driver (terminal control).
 *
 * Config Local EH re-runs this after locality transfer (UAV connect / MP).
 * IncomingMissile runs on the machine where the EH was added
 * (community.bistudio.com/wiki/Arma_3:_Event_Handlers).
 *
 * Covers DRO-spawned, DAO VAM, Zeus, and any createVehicle of hooked classes.
 *
 * Ref: community.bistudio.com/wiki/Arma_3:_Event_Handlers (IncomingMissile)
 */

params [["_vehicle", objNull, [objNull]]];

if (!local _vehicle || {isNull _vehicle}) exitWith {};
if (_vehicle getVariable ["BS_autoCMInit", false]) exitWith {};
if !(_vehicle hasWeapon "CMFlareLauncher") exitWith {};

_vehicle setVariable ["BS_autoCMInit", true, false];

private _ehId = _vehicle addEventHandler [
    "IncomingMissile",
    { _this call bskulls_fnc_autoCmOnIncomingMissile; }
];

_vehicle setVariable ["BS_autoCM_ehId", _ehId, false];
