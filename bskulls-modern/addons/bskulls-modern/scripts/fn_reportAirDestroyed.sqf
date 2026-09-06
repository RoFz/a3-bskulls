/*
 * bskulls_fnc_reportAirDestroyed — systemChat when a BS helo/plane is destroyed.
 */

params [
    ["_vehicle", objNull, [objNull]],
    ["_killer", objNull, [objNull]],
    ["_instigator", objNull, [objNull]]
];

if (!local _vehicle) exitWith {};

private _assetName = getText (configOf _vehicle >> "displayName");
private _source = [_killer, _instigator] call bskulls_fnc_formatKillSource;
private _msg = format ["%1 destroyed by %2", _assetName, _source];

diag_log format ["BS air lost: %1", _msg];

// A wreck or empty aircraft can report civilian. The single-player user must
// receive the loss message regardless of the aircraft's side after destruction.
if (!isMultiplayer) exitWith {
    systemChat _msg;
};

private _side = side _vehicle;
{
    if (isPlayer _x && {side _x isEqualTo _side}) then {
        [_msg] remoteExec ["systemChat", _x];
    };
} forEach allPlayers;
