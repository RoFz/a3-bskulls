/*
 * bskulls_fnc_reportPawneeMissilesDepleted
 *
 * Announces a faction Pawnee's first transition from loaded Scalpel pylons
 * to no remaining Scalpel rounds.
 */

params [["_vehicle", objNull, [objNull]]];

if (isNull _vehicle || {!local _vehicle}) exitWith { false };
if (_vehicle getVariable ["BS_pawneeMissilesDepletedNotified", false]) exitWith { false };

private _assetName = getText (configOf _vehicle >> "displayName");
private _message = format ["%1: Scalpel missiles depleted.", _assetName];
private _side = side _vehicle;
private _recipients = allPlayers select {
    isPlayer _x && {side _x isEqualTo _side}
};

// Keep retrying from the controller until a player can receive the message.
if (_recipients isEqualTo []) exitWith { false };

_vehicle setVariable ["BS_pawneeMissilesDepletedNotified", true, true];

diag_log format ["BS Pawnee: %1", _message];

{
    [_message] remoteExec ["systemChat", _x];
} forEach _recipients;

true
