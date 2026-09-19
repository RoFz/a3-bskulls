/*
 * Return the installed countermeasure inventory and its documented guidance
 * compatibility flags.
 *
 * Return value:
 * [remaining rounds, array of weaponLockSystem masks, masks are complete]
 *
 * Ref: community.bistudio.com/wiki/Arma_3:_Countermeasures
 *      community.bistudio.com/wiki/CfgAmmo_Config_Reference
 *      community.bistudio.com/wiki/magazinesAllTurrets
 */

params [
    ["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle) exitWith { [0, [], false] };

private _rounds = 0;
private _systems = [];
private _foundMagazine = false;
private _systemsComplete = true;

{
    _x params [
        ["_magazine", "", [""]],
        ["_turretPath", [], [[]]],
        ["_ammoCount", 0, [0]]
    ];

    if ((toLower _magazine) find "cmflare" >= 0) then {
        _foundMagazine = true;
        _rounds = _rounds + (_ammoCount max 0);

        private _ammoClass = getText (
            configFile >> "CfgMagazines" >> _magazine >> "ammo"
        );
        private _systemEntry = (
            configFile >> "CfgAmmo" >> _ammoClass >> "weaponLockSystem"
        );
        private _system = [_systemEntry] call bskulls_fnc_autoCmReadLockSystem;

        if (_ammoClass isEqualTo "" || {_system < 0}) then {
            _systemsComplete = false;
        } else {
            _systems pushBackUnique _system;
        };
    };
} forEach (magazinesAllTurrets _vehicle);

[
    _rounds,
    _systems,
    _foundMagazine && {_systemsComplete}
]
