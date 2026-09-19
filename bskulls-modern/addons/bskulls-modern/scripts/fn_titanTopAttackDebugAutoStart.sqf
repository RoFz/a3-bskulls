/*
 * Resume launcher-AI diagnostics at mission post-init only when another
 * startup component explicitly opted in. Normal missions leave diagnostics
 * disabled; SetDebug remains the supported live-session switch.
 *
 * CfgFunctions postInit runs after mission objects are initialized. XEH then
 * the discovery PFH covers launcher carriers and loadout changes later in the
 * mission. Hawkins's XEH provides an immediate first sample.
 * https://community.bohemia.net/wiki/Arma_3:_Functions_Library
 */

private _enabled = localNamespace getVariable [
    "bskulls_titanTopAttackDebug",
    false
];
if (!_enabled) exitWith {
    localNamespace setVariable ["bskulls_titanTopAttackDebugAutoStarted", false];
    true
};

localNamespace setVariable ["bskulls_titanTopAttackDebugAutoStarted", true];
[true, false, true] call bskulls_fnc_titanTopAttackSetDebug;

private _carrier = configFile >> "CfgAmmo" >> "M_Titan_AT_TOP_PLUS";
private _launcher = configFile >> "CfgWeapons" >> "B_PTbskull_Wea_law_02_titantop";
private _mode = _launcher >> "Overfly";

[
    objNull,
    "AUTO_START",
    [
        ["scope", "local AI launcher carriers in player-containing groups"],
        ["launcherPresent", isClass _launcher],
        ["carrierPresent", isClass _carrier],
        ["weaponLockSystem", getNumber (_launcher >> "weaponLockSystem")],
        ["ammoUsage", getNumber (_carrier >> "aiAmmoUsageFlags")],
        ["lockMin", getNumber (_carrier >> "missileLockMinDistance")],
        ["lockMax", getNumber (_carrier >> "missileLockMaxDistance")],
        ["lockMaxSpeed", getNumber (_carrier >> "missileLockMaxSpeed")],
        ["aiMin", getNumber (_mode >> "minRange")],
        ["aiMax", getNumber (_mode >> "maxRange")],
        ["aiRateOfFire", getNumber (_mode >> "aiRateOfFire")],
        ["aiRateOfFireDistance", getNumber (_mode >> "aiRateOfFireDistance")],
        ["reloadTime", getNumber (_mode >> "reloadTime")]
    ],
    "autostart"
] call bskulls_fnc_titanTopAttackLog;

true
