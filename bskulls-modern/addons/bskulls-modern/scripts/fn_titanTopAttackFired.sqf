/* Ammo-config Fired handler: capture the shooter, selected mode, and lock. */

params [
    ["_unit", objNull, [objNull]],
    ["_weapon", "", [""]],
    ["_muzzle", "", [""]],
    ["_mode", "", [""]],
    ["_ammo", "", [""]],
    ["_magazine", "", [""]],
    ["_projectile", objNull, [objNull]],
    ["_gunner", objNull, [objNull]]
];

if (
    _ammo isNotEqualTo "M_Titan_AT_TOP_PLUS"
    || {isNull _projectile}
    || {!local _projectile}
) exitWith {false};

if !(_projectile getVariable ["bskulls_titanTopAttackInitialized", false]) then {
    [_projectile] call bskulls_fnc_titanTopAttackProjectileInit;
};

private _target = missileTarget _projectile;
if (isNull _target && {!isNull _unit}) then {
    _target = assignedTarget _unit;
};

private _missileTargetPosATL = missileTargetPos _projectile;
private _targetPosASL = if (!isNull _target) then {
    getPosASL _target
} else {
    if ((vectorMagnitude _missileTargetPosATL) > 1) then {
        ATLToASL _missileTargetPosATL
    } else {
        []
    }
};

// Preserve the target transfer as save-safe gameplay state on the carrier.
// Diagnostic trace data and monitor handles are deliberately local-only.
_projectile setVariable ["bskulls_titanTopAttackTarget", _target, false];
_projectile setVariable ["bskulls_titanTopAttackTargetPosASL", _targetPosASL, false];

// Arma exposes no cancellable pre-fire event. Keep an AI operator's launcher
// mechanically unready while this carrier is in flight instead; the command is
// local and weapon-specific, so Hawkins's rifle and group fire orders remain
// unaffected.
[
    _unit,
    _weapon,
    _muzzle,
    _projectile,
    _target
] call bskulls_fnc_titanTopAttackFireDiscipline;

if !(localNamespace getVariable ["bskulls_titanTopAttackDebug", false]) exitWith {true};

private _remaining = if (isNull _unit) then {
    -1
} else {
    {
        (_x param [0, ""]) isEqualTo _magazine
    } count (magazinesAmmoFull _unit)
};
private _shotParents = (getShotParents _projectile) apply {str _x};
private _magazineConfig = configFile >> "CfgMagazines" >> _magazine;
private _dapsState = if (isNull _target) then {
    []
} else {
    [
        ["type", _target getVariable ["dapsType", ""]],
        ["active", _target getVariable ["dapsActive", false]],
        ["ammo", _target getVariable ["dapsAmmo", -1]],
        ["ammoLeft", _target getVariable ["dapsAmmoL", -1]],
        ["ammoRight", _target getVariable ["dapsAmmoR", -1]]
    ]
};

[
    _projectile,
    "FIRED",
    [
        ["unit", str _unit],
        ["unitClass", if (isNull _unit) then {""} else {typeOf _unit}],
        ["unitLocal", !isNull _unit && {local _unit}],
        ["isPlayer", !isNull _unit && {isPlayer _unit}],
        ["currentCommand", if (isNull _unit) then {""} else {currentCommand _unit}],
        ["gunner", str _gunner],
        ["weapon", _weapon],
        ["muzzle", _muzzle],
        ["mode", _mode],
        ["ammo", _ammo],
        ["magazine", _magazine],
        ["magazineDisplayName", getText (_magazineConfig >> "displayName")],
        ["configuredInitSpeed", getNumber (_magazineConfig >> "initSpeed")],
        ["remainingMagazines", _remaining],
        ["shotParents", _shotParents],
        ["target", str _target],
        ["targetClass", if (isNull _target) then {""} else {typeOf _target}],
        ["targetPosASL", _targetPosASL],
        ["missileTargetPosATL", _missileTargetPosATL],
        ["daps", _dapsState]
    ]
] call bskulls_fnc_titanTopAttackLog;

true
