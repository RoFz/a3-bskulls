/*
 * bskulls_fnc_autoCmOnIncomingMissile
 *
 * IncomingMissile EH handler: dispense CMFlareLauncher for AI-operated aircraft.
 * Trigger = engine inbound guided-missile detection (same backend as player RWR).
 *
 * Ref: community.bistudio.com/wiki/Arma_3:_Event_Handlers (IncomingMissile)
 *      community.bistudio.com/wiki/BIS_fnc_fire
 *      community.bistudio.com/wiki/Arma_3:_Countermeasures
 */

params [
    ["_target", objNull, [objNull]],
    ["_ammo", "", [""]],
    ["_firer", objNull, [objNull]],
    ["_instigator", objNull, [objNull]],
    ["_missile", objNull, [objNull]]
];

if (!local _target || {!alive _target}) exitWith {};
if !(_target getVariable ["BS_autoCMInit", false]) exitWith {};
if !(_target hasWeapon "CMFlareLauncher") exitWith {};

private _driver = driver _target;
if (isNull _driver || {!alive _driver}) exitWith {};
// Manned aircraft: player pilot keeps manual [C]. UAV terminal/driver stays auto-CM.
if (isPlayer _driver && {!unitIsUAV _target}) exitWith {};

if (_target getVariable ["BS_autoCM_busy", false]) exitWith {};

// magazinesAllTurrets: [className, turretPath, ammoCount, id, creator]
// community.bistudio.com/wiki/magazinesAllTurrets
private _hasAmmo = (magazinesAllTurrets _target) findIf {
    (_x select 0) find "CMFlare" >= 0 && {(_x select 2) > 0}
} >= 0;
if (!_hasAmmo) exitWith {};

private _cooldownUntil = _target getVariable ["BS_autoCM_cooldownUntil", -1];
if (time < _cooldownUntil) exitWith {};

_target setVariable ["BS_autoCM_busy", true, false];
_target setVariable ["BS_autoCM_cooldownUntil", time + 4, false];

[_target] spawn {
    params ["_veh"];

    private _burstCount = 3;
    private _burstDelay = 0.25;

    for "_i" from 1 to _burstCount do {
        if (!alive _veh || {!local _veh}) exitWith {};
        if !(_veh hasWeapon "CMFlareLauncher") exitWith {};

        private _hasAmmo = (magazinesAllTurrets _veh) findIf {
            (_x select 0) find "CMFlare" >= 0 && {(_x select 2) > 0}
        } >= 0;
        if (!_hasAmmo) exitWith {};

        [_veh, "CMFlareLauncher"] call BIS_fnc_fire;
        if (_i < _burstCount) then { sleep _burstDelay; };
    };

    sleep 4;
    if (!isNull _veh) then {
        _veh setVariable ["BS_autoCM_busy", false, false];
    };
};
