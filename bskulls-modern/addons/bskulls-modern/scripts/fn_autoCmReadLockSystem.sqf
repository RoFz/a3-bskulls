/*
 * Read a weaponLockSystem config value. Bohemia permits either a number or a
 * text expression containing a sum of guidance flags.
 *
 * Return value: mask, or -1 when the property cannot be interpreted.
 *
 * Ref: community.bistudio.com/wiki/CfgAmmo_Config_Reference
 */

params [
    ["_entry", configNull, [configNull]]
];

if (isNumber _entry) exitWith { getNumber _entry };
if (!isText _entry) exitWith { -1 };

private _flags = [];
{
    private _flag = parseNumber _x;
    if (_flag in [1, 2, 4, 8, 16]) then {
        _flags pushBackUnique _flag;
    };
} forEach ((getText _entry) splitString " +|()");

if (_flags isEqualTo []) exitWith { -1 };

private _mask = 0;
{
    _mask = _mask + _x;
} forEach _flags;

_mask
