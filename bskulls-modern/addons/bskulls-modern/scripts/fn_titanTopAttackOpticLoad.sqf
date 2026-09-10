/*
 * Preserve the stock Titan optic and force only the fixed Archangel attack-mode
 * lamps: TOP bright, DIR dim. While diagnostics are enabled, record the stock
 * HUD state and the target under/locked to the player's cursor.
 *
 * The Titan controls live inside controls group IDC 170, so they must be
 * resolved with controlsGroupCtrl rather than directly from the display.
 */

disableSerialization;

params [["_display", displayNull, [displayNull]]];

if (isNull _display) exitWith {false};

private _group = _display displayCtrl 170;
private _topOff = if (isNull _group) then {controlNull} else {_group controlsGroupCtrl 1006};
private _topOn = if (isNull _group) then {controlNull} else {_group controlsGroupCtrl 196};
private _dirOff = if (isNull _group) then {controlNull} else {_group controlsGroupCtrl 1007};
private _dirOn = if (isNull _group) then {controlNull} else {_group controlsGroupCtrl 197};

private _topColor = [0.2941, 0.8745, 0.2157, 1];
private _dimColor = [0.2941, 0.2941, 0.2941, 1];

{
    _x params ["_control", "_color"];
    if !(isNull _control) then {
        _control ctrlSetTextColor _color;
    };
} forEach [
    [_topOff, _topColor],
    [_topOn, _topColor],
    [_dirOff, _dimColor],
    [_dirOn, _dimColor]
];

if !(missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]) exitWith {
    !isNull _group
};

private _traceId = format ["optic-%1-%2", clientOwner, round (diag_tickTime * 1000)];
[
    objNull,
    "OPTIC_LOADED",
    [
        ["display", str _display],
        ["groupPresent", !isNull _group],
        ["topOffPresent", !isNull _topOff],
        ["topOnPresent", !isNull _topOn],
        ["dirOffPresent", !isNull _dirOff],
        ["dirOnPresent", !isNull _dirOn],
        ["topOffColor", if (isNull _topOff) then {[]} else {ctrlTextColor _topOff}],
        ["dirOnColor", if (isNull _dirOn) then {[]} else {ctrlTextColor _dirOn}]
    ],
    _traceId
] call bskulls_fnc_titanTopAttackLog;

if (isNull _group) exitWith {false};

[_display, _group, _traceId] spawn {
    disableSerialization;

    params ["_display", "_group", "_traceId"];

    private _seekOn = _group controlsGroupCtrl 166;
    private _missileOn = _group controlsGroupCtrl 167;
    private _topOn = _group controlsGroupCtrl 196;
    private _dirOn = _group controlsGroupCtrl 197;
    private _distance = _group controlsGroupCtrl 198;
    private _lastState = [];
    private _startedAt = diag_tickTime;

    while {
        !isNull _display
        && {!isNull _group}
        && {missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]}
    } do {
        private _unit = player;
        private _cursorTarget = cursorTarget;
        private _cursorObject = cursorObject;
        private _observedObject = [_cursorObject, _cursorTarget] select (!isNull _cursorTarget);
        private _weaponState = if (isNull _unit) then {[]} else {weaponState _unit};
        private _roundReloadPhase = _weaponState param [5, -1];
        private _magazineReloadPhase = _weaponState param [6, -1];
        private _state = [
            if (isNull _seekOn) then {false} else {ctrlShown _seekOn},
            if (isNull _missileOn) then {false} else {ctrlShown _missileOn},
            if (isNull _topOn) then {false} else {ctrlShown _topOn},
            if (isNull _dirOn) then {false} else {ctrlShown _dirOn},
            if (isNull _distance) then {""} else {ctrlText _distance},
            if (isNull _unit) then {""} else {currentWeapon _unit},
            _weaponState param [3, ""],
            _weaponState param [4, -1],
            round (_roundReloadPhase * 10),
            round (_magazineReloadPhase * 10),
            str _cursorTarget,
            str _cursorObject,
            if (isNull _observedObject) then {-1} else {round ((_unit distance2D _observedObject) / 5)},
            if (isNull _observedObject) then {false} else {isEngineOn _observedObject}
        ];

        if (_state isNotEqualTo _lastState) then {
            [
                objNull,
                "OPTIC_STATE",
                [
                    ["elapsed", diag_tickTime - _startedAt],
                    ["seekLampShown", _state select 0],
                    ["missileLampShown", _state select 1],
                    ["topLampShown", _state select 2],
                    ["dirLampShown", _state select 3],
                    ["displayedDistance", _state select 4],
                    ["currentWeapon", _state select 5],
                    ["weaponState", _weaponState],
                    ["secondaryWeaponMagazine", if (isNull _unit) then {[]} else {secondaryWeaponMagazine _unit}],
                    ["canFire", !isNull _unit && {canFire _unit}],
                    ["cursorTarget", str _cursorTarget],
                    ["cursorTargetClass", if (isNull _cursorTarget) then {""} else {typeOf _cursorTarget}],
                    ["cursorObject", str _cursorObject],
                    ["cursorObjectClass", if (isNull _cursorObject) then {""} else {typeOf _cursorObject}],
                    ["observedDistance2D", if (isNull _observedObject) then {-1} else {_unit distance2D _observedObject}],
                    ["observedAlive", !isNull _observedObject && {alive _observedObject}],
                    ["observedEngineOn", !isNull _observedObject && {isEngineOn _observedObject}],
                    ["knowsAbout", if (isNull _observedObject || {isNull _unit}) then {-1} else {_unit knowsAbout _observedObject}]
                ],
                _traceId
            ] call bskulls_fnc_titanTopAttackLog;

            _lastState = _state;
        };

        uiSleep 0.2;
    };

    [
        objNull,
        "OPTIC_CLOSED",
        [["elapsed", diag_tickTime - _startedAt]],
        _traceId
    ] call bskulls_fnc_titanTopAttackLog;
};

true
