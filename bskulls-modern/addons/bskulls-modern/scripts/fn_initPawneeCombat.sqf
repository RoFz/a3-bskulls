/*
 * Monitor the Black Skulls Pawnee's Scalpel pylons. Flight, targeting, weapon
 * selection, and firing deliberately remain under vanilla/DAO control.
 */

params [["_vehicle", objNull, [objNull]]];

if (isNull _vehicle || {!local _vehicle}) exitWith { false };

private _oldHandle = _vehicle getVariable ["BS_pawneeMonitorHandle", scriptNull];
if (_oldHandle isNotEqualTo scriptNull && {!scriptDone _oldHandle}) exitWith { false };

private _handle = [_vehicle] spawn {
    params ["_vehicle"];

    while {alive _vehicle && {local _vehicle}} do {
        private _hasScalpelPylon = false;
        private _scalpelRounds = 0;
        {
            if ((toLower _x) find "scalpel" >= 0) then {
                _hasScalpelPylon = true;
                _scalpelRounds = _scalpelRounds + (_vehicle ammoOnPylon (_forEachIndex + 1));
            };
        } forEach (getPylonMagazines _vehicle);

        if (!_hasScalpelPylon) then {
            // Dynamic-loadout systems briefly expose the configured default
            // pylons before replacing them. Removing a Scalpel rack is a
            // loadout change, not ammunition depletion.
            if (_vehicle getVariable ["BS_pawneeHadScalpelRounds", false]) then {
                _vehicle setVariable ["BS_pawneeHadScalpelRounds", false, true];
            };
        } else {
            if (
                _scalpelRounds > 0
                && {!(_vehicle getVariable ["BS_pawneeHadScalpelRounds", false])}
            ) then {
                _vehicle setVariable ["BS_pawneeHadScalpelRounds", true, true];
            };
            if (
                _scalpelRounds <= 0
                && {_vehicle getVariable ["BS_pawneeHadScalpelRounds", false]}
                && {!(_vehicle getVariable ["BS_pawneeMissilesDepletedNotified", false])}
            ) then {
                [_vehicle] call bskulls_fnc_reportPawneeMissilesDepleted;
            };
        };

        sleep 2;
    };

    if (!isNull _vehicle) then {
        _vehicle setVariable ["BS_pawneeMonitorHandle", scriptNull, false];
    };
};

_vehicle setVariable ["BS_pawneeMonitorHandle", _handle, false];
true
