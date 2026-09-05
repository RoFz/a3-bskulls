/* Keep the radar dish rotating while the vehicle is alive and local. */

params [["_vehicle", objNull, [objNull]]];

if (isNull _vehicle || {!local _vehicle}) exitWith { false };

private _oldHandle = _vehicle getVariable ["BS_radarRotationHandle", scriptNull];
if (_oldHandle isNotEqualTo scriptNull && {!scriptDone _oldHandle}) exitWith { false };

private _handle = [_vehicle] spawn {
    params ["_vehicle"];

    private _directions = [120, 240, 0];
    private _index = 0;
    while {alive _vehicle && {local _vehicle}} do {
        _vehicle lookAt (_vehicle getRelPos [100, _directions select _index]);
        _index = (_index + 1) mod count _directions;
        sleep 2.45;
    };

    if (!isNull _vehicle) then {
        _vehicle setVariable ["BS_radarRotationHandle", scriptNull, false];
    };
};

_vehicle setVariable ["BS_radarRotationHandle", _handle, false];
true
