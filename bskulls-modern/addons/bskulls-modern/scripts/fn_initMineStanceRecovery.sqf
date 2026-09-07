/*
 * Release an AI unit from the prone stance imposed by the Deactivate Mine
 * command by returning its scripted position rule to automatic.
 *
 * Sources:
 * - community.bohemia.net/wiki/Arma_3:_Event_Handlers documents the
 *   "DISABLE MINE" AI command name.
 * - community.bohemia.net/wiki/setUnitPos documents "AUTO" as the mode in
 *   which the unit chooses its stance according to circumstances.
 */

#define BS_MINE_STANCE_HANDLE "BS_mineStanceHandle"
#define BS_MINE_COMMAND "DISABLE MINE"
#define BS_MINE_POLL_INTERVAL 0.2

params [["_unit", objNull, [objNull]]];

if (isNull _unit || {!local _unit} || {isPlayer _unit}) exitWith { false };

private _oldHandle = _unit getVariable [BS_MINE_STANCE_HANDLE, scriptNull];
if (_oldHandle isNotEqualTo scriptNull && {!scriptDone _oldHandle}) exitWith { true };

private _handle = [_unit] spawn {
    params ["_unit"];

    private _keepWatching = true;

    while {_keepWatching} do {
        waitUntil {
            sleep BS_MINE_POLL_INTERVAL;

            private _unavailable = (
                isNull _unit
                || {!alive _unit}
                || {!local _unit}
                || {isPlayer _unit}
            );

            _unavailable || {currentCommand _unit isEqualTo BS_MINE_COMMAND}
        };

        if (isNull _unit || {!alive _unit} || {!local _unit} || {isPlayer _unit}) then {
            _keepWatching = false;
        } else {
            waitUntil {
                sleep BS_MINE_POLL_INTERVAL;
                isNull _unit
                || {!alive _unit}
                || {!local _unit}
                || {isPlayer _unit}
                || {currentCommand _unit isNotEqualTo BS_MINE_COMMAND}
            };

            if (isNull _unit || {!alive _unit} || {!local _unit} || {isPlayer _unit}) then {
                _keepWatching = false;
            } else {
                _unit setUnitPos "AUTO";
            };
        };
    };

    if (!isNull _unit) then {
        _unit setVariable [BS_MINE_STANCE_HANDLE, scriptNull, false];
    };
};

_unit setVariable [BS_MINE_STANCE_HANDLE, _handle, false];

true
