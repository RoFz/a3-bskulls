/*
 * Enable Archangel diagnostics on every machine at mission post-init. This is
 * intentionally always-on while Hawkins's intermittent AI engagement is under
 * investigation; chat remains quiet and the normal runtime switch can still
 * disable collection.
 *
 * CfgFunctions postInit runs after mission objects are initialized. XEH then
 * covers Hawkins units created later in the mission.
 * https://community.bohemia.net/wiki/Arma_3:_Functions_Library
 */

missionNamespace setVariable ["bskulls_titanTopAttackDebugAutoStarted", true];
[true, false, true] call bskulls_fnc_titanTopAttackSetDebug;

private _carrier = configFile >> "CfgAmmo" >> "M_Titan_AT_TOP_PLUS";
private _launcher = configFile >> "CfgWeapons" >> "B_PTbskull_Wea_law_02_titantop";
private _mode = _launcher >> "Overfly";

[
    objNull,
    "AUTO_START",
    [
        ["launcherPresent", isClass _launcher],
        ["carrierPresent", isClass _carrier],
        ["weaponLockSystem", getNumber (_launcher >> "weaponLockSystem")],
        ["ammoUsage", getNumber (_carrier >> "aiAmmoUsageFlags")],
        ["lockMin", getNumber (_carrier >> "missileLockMinDistance")],
        ["lockMax", getNumber (_carrier >> "missileLockMaxDistance")],
        ["lockMaxSpeed", getNumber (_carrier >> "missileLockMaxSpeed")],
        ["aiMin", getNumber (_mode >> "minRange")],
        ["aiMax", getNumber (_mode >> "maxRange")]
    ],
    "autostart"
] call bskulls_fnc_titanTopAttackLog;

true
