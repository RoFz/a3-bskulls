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
#define BS_MINE_RELEASE_TIMEOUT 3
#define BS_MINE_RELEASE_ANIMATION "putdown"

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
                /*
                 * currentCommand clears before the mine-disposal animation has
                 * finished. Let its final stance write complete before
                 * releasing the DOWN rule, or the engine can overwrite AUTO.
                 */
                private _releaseDeadline = diag_tickTime + BS_MINE_RELEASE_TIMEOUT;
                waitUntil {
                    sleep BS_MINE_POLL_INTERVAL;
                    isNull _unit
                    || {!alive _unit}
                    || {!local _unit}
                    || {isPlayer _unit}
                    || {currentCommand _unit isEqualTo BS_MINE_COMMAND}
                    || {
                        ((toLower (animationState _unit)) find BS_MINE_RELEASE_ANIMATION) < 0
                    }
                    || {diag_tickTime >= _releaseDeadline}
                };

                if (
                    !isNull _unit
                    && {alive _unit}
                    && {local _unit}
                    && {!isPlayer _unit}
                    && {currentCommand _unit isNotEqualTo BS_MINE_COMMAND}
                    && {(toUpper (unitPos _unit)) isEqualTo "DOWN"}
                ) then {
                    // Give the completed animation one scheduler turn to settle.
                    sleep BS_MINE_POLL_INTERVAL;

                    if (
                        !isNull _unit
                        && {alive _unit}
                        && {local _unit}
                        && {!isPlayer _unit}
                        && {currentCommand _unit isNotEqualTo BS_MINE_COMMAND}
                        && {(toUpper (unitPos _unit)) isEqualTo "DOWN"}
                    ) then {
                        _unit setUnitPos "AUTO";
                    };
                };
            };
        };
    };

    if (!isNull _unit) then {
        _unit setVariable [BS_MINE_STANCE_HANDLE, scriptNull, false];
    };
};

_unit setVariable [BS_MINE_STANCE_HANDLE, _handle, false];

true
