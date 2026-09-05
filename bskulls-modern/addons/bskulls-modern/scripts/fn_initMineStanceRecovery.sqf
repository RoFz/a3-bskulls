/*
 * Release an AI unit from the prone stance imposed by the Deactivate Mine
 * command, while preserving any stance rule that existed before the command.
 *
 * Sources:
 * - community.bohemia.net/wiki/Arma_3:_Event_Handlers documents the
 *   "DISABLE MINE" AI command name.
 * - community.bohemia.net/wiki/setUnitPos documents "AUTO" and the other
 *   position rules restored by this function.
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
    private _positionRule = unitPos _unit;

    while {_keepWatching} do {
        waitUntil {
            sleep BS_MINE_POLL_INTERVAL;

            private _unavailable = (
                isNull _unit
                || {!alive _unit}
                || {!local _unit}
                || {isPlayer _unit}
            );

            if (!_unavailable && {currentCommand _unit isNotEqualTo BS_MINE_COMMAND}) then {
                _positionRule = unitPos _unit;
            };

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
                _unit setUnitPos _positionRule;
            };
        };
    };

    if (!isNull _unit) then {
        _unit setVariable [BS_MINE_STANCE_HANDLE, scriptNull, false];
    };
};

_unit setVariable [BS_MINE_STANCE_HANDLE, _handle, false];

true
