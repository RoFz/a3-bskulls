/*
 * Keep automatic-countermeasure telemetry enabled without requiring a Debug
 * Console command in every mission. CfgFunctions preInit runs before mission
 * objects are initialized, which also lets the Loaded handler exist before a
 * saved mission restores its serialized missionNamespace.
 *
 * Ref: community.bistudio.com/wiki/Arma_3:_Functions_Library
 *      community.bistudio.com/wiki/Arma_3:_Event_Handlers/addMissionEventHandler
 *      community.bistudio.com/wiki/Namespace
 */

missionNamespace setVariable ["BS_autoCMDebug", true];
diag_log "[BSKULLS][AUTO-CM] diagnostics enabled source=addon-preinit";

private _oldLoadedEh = localNamespace getVariable [
    "BS_autoCMDebugLoadedEh",
    -1
];
if (_oldLoadedEh >= 0) then {
    removeMissionEventHandler ["Loaded", _oldLoadedEh];
};

private _loadedEh = addMissionEventHandler ["Loaded", {
    missionNamespace setVariable ["BS_autoCMDebug", true];
    diag_log "[BSKULLS][AUTO-CM] diagnostics enabled source=mission-loaded";
}];
localNamespace setVariable ["BS_autoCMDebugLoadedEh", _loadedEh];

true
