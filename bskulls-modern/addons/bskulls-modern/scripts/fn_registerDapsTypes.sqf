/*
 * Register Black Skulls variants only when DAPS supports their base vehicle.
 *
 * DAPS matches exact typeOf class names. Its own assignment module updates
 * these arrays, recompiles the combined type lists, broadcasts them, and then
 * relies on RegisterVehicle. Mirror that sequence without making DAPS a hard
 * dependency of the faction addon.
 */

if (!isServer || {!isClass (configFile >> "CfgPatches" >> "DrongosAPS")}) exitWith {};

[] spawn {
    private _deadline = diag_tickTime + 30;
    waitUntil {
        uiSleep 0.1;
        (missionNamespace getVariable ["dapsReady", false]) || {diag_tickTime > _deadline}
    };

    if !(missionNamespace getVariable ["dapsReady", false]) exitWith {
        diag_log "[BSKULLS][DAPS] DAPS did not become ready within 30 seconds; compatibility registration skipped";
    };

    private _mappings = [
        ["dapsTrophyHV", [
            "B_PTbskull_Veh_Tank_blackops_01"
        ]],
        ["dapsTrophyMV", [
            "B_PTbskull_Veh_APC_blackops_01",
            "B_PTbskull_Veh_APC_blackops_02"
        ]],
        ["dapsNemesis", [
            "B_PTbskull_Veh_Helo_blackops_01",
            "B_PTbskull_Veh_Helo_blackops_01_nodao",
            "B_PTbskull_Veh_Helo_blackops_03",
            "B_PTbskull_Veh_Helo_blackops_03_nodao"
        ]]
    ];

    private _registeredTypes = [];
    {
        _x params ["_arrayName", "_classNames"];
        private _dapsTypes = missionNamespace getVariable [_arrayName, []];
        {
            _dapsTypes pushBackUnique _x;
            _registeredTypes pushBackUnique _x;
        } forEach _classNames;
        missionNamespace setVariable [_arrayName, _dapsTypes];
    } forEach _mappings;

    call DAPS_fnc_CompileTypes;
    call DAPS_fnc_BroadcastTypes;

    // DAPS may have scanned mission-start vehicles before these types existed.
    {
        if ((typeOf _x) in _registeredTypes && {isNil {_x getVariable "dapsType"}}) then {
            _x call DAPS_fnc_RegisterVehicle;
        };
    } forEach vehicles;

    diag_log format ["[BSKULLS][DAPS] Registered %1 supported Black Skulls vehicle classes", count _registeredTypes];
};
