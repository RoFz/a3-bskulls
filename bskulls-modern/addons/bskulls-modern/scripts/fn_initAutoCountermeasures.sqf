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
 *      community.bistudio.com/wiki/weaponsTurret
 */

params [["_vehicle", objNull, [objNull]]];

if (isNull _vehicle || {!local _vehicle}) exitWith { false };
if (_vehicle getVariable ["BS_autoCMInit", false]) exitWith { true };

// Countermeasure launchers are driver weapons. Match the vanilla Burst,
// Singles, and Triples variants without hard-coding one exact classname.
private _launcher = "";
{
    if ((toLower _x) find "cmflarelauncher" >= 0) exitWith {
        _launcher = _x;
    };
} forEach (_vehicle weaponsTurret [-1]);

if (_launcher isEqualTo "") exitWith { false };

private _launcherConfig = configFile >> "CfgWeapons" >> _launcher;
private _modes = getArray (_launcherConfig >> "modes");
private _mode = _modes param [0, "", [""]];
if (_mode isEqualTo "this") then {
    _mode = _launcher;
};
if (_mode isEqualTo "") exitWith { false };

_vehicle setVariable ["BS_autoCMInit", true, false];
_vehicle setVariable ["BS_autoCM_launcher", _launcher, false];
_vehicle setVariable ["BS_autoCM_mode", _mode, false];
_vehicle setVariable ["BS_autoCM_workerToken", 0, false];
_vehicle setVariable ["BS_autoCM_workerHandle", scriptNull, false];
_vehicle setVariable ["BS_autoCM_workerExpiresAt", -1, false];
_vehicle setVariable ["BS_autoCM_cooldownUntil", -1, false];

private _ehId = _vehicle addEventHandler [
    "IncomingMissile",
    { _this call bskulls_fnc_autoCmOnIncomingMissile; }
];

_vehicle setVariable ["BS_autoCM_ehId", _ehId, false];

true
