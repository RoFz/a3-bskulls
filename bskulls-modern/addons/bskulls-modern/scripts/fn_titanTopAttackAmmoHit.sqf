/* Ammo-config AmmoHit handler for carrier fallback and terminal impact. */

params [
    ["_projectile", objNull, [objNull]],
    ["_shooter", objNull, [objNull]],
    ["_hitObject", objNull, [objNull]],
    ["_position", [], [[]]],
    ["_velocity", [], [[]]],
    ["_hitComponents", [], [[]]],
    ["_damageData", [], [[]]],
    ["_normal", [], [[]]],
    ["_explode", false, [false]],
    ["_instigator", objNull, [objNull]]
];

if !(missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]) exitWith {false};

private _traceId = if (isNull _projectile) then {
    "untracked"
} else {
    _projectile getVariable ["bskulls_titanTopAttackTraceId", "untracked"]
};
private _stage = if (isNull _projectile) then {
    "unknown"
} else {
    _projectile getVariable ["bskulls_titanTopAttackStage", "unknown"]
};

[
    _projectile,
    "AMMO_HIT",
    [
        ["stage", _stage],
        ["accuracy", if (isNull _projectile) then {[]} else {
            _projectile getVariable ["bskulls_titanTopAttackAccuracy", []]
        }],
        ["shooter", str _shooter],
        ["instigator", str _instigator],
        ["hitObject", str _hitObject],
        ["hitClass", if (isNull _hitObject) then {""} else {typeOf _hitObject}],
        ["hitAlive", !isNull _hitObject && {alive _hitObject}],
        ["hitDamageImmediate", if (isNull _hitObject) then {-1} else {damage _hitObject}],
        ["positionASL", _position],
        ["velocity", _velocity],
        ["hitComponents", _hitComponents],
        ["damageData", _damageData],
        ["normal", _normal],
        ["explode", _explode]
    ],
    _traceId
] call bskulls_fnc_titanTopAttackLog;

if (!isNull _hitObject) then {
    [_hitObject, _traceId, _stage] spawn {
        params ["_hitObject", "_traceId", "_stage"];
        uiSleep 0.1;
        [
            objNull,
            "POST_HIT_STATE",
            [
                ["stage", _stage],
                ["hitObject", str _hitObject],
                ["hitClass", if (isNull _hitObject) then {""} else {typeOf _hitObject}],
                ["alive", !isNull _hitObject && {alive _hitObject}],
                ["damage", if (isNull _hitObject) then {-1} else {damage _hitObject}],
                ["dapsType", if (isNull _hitObject) then {""} else {_hitObject getVariable ["dapsType", ""]}],
                ["dapsAmmo", if (isNull _hitObject) then {-1} else {_hitObject getVariable ["dapsAmmo", -1]}],
                ["dapsAmmoLeft", if (isNull _hitObject) then {-1} else {_hitObject getVariable ["dapsAmmoL", -1]}],
                ["dapsAmmoRight", if (isNull _hitObject) then {-1} else {_hitObject getVariable ["dapsAmmoR", -1]}]
            ],
            _traceId
        ] call bskulls_fnc_titanTopAttackLog;
    };
};

true
