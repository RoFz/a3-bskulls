/*
 * Enable or disable Archangel diagnostics on the machine executing this call.
 * Use Local Exec in single-player and Global Exec when every multiplayer
 * machine should collect its local projectile, optic, and AI state.
 *
 * Debug Console examples:
 *   [true] call bskulls_fnc_titanTopAttackSetDebug;              // enable
 *   [true, true] call bskulls_fnc_titanTopAttackSetDebug;        // + chat
 *   [true, false, true] call bskulls_fnc_titanTopAttackSetDebug; // fresh log
 *   [false] call bskulls_fnc_titanTopAttackSetDebug;             // disable
 */

params [
    ["_enabled", true, [true]],
    ["_chat", false, [false]],
    ["_clearRecords", false, [false]]
];

private _wasEnabled = missionNamespace getVariable ["bskulls_titanTopAttackDebug", false];
missionNamespace setVariable ["bskulls_titanTopAttackDebug", _enabled];
missionNamespace setVariable ["bskulls_titanTopAttackDebugChat", _enabled && {_chat}];

if (_clearRecords) then {
    missionNamespace setVariable ["bskulls_titanTopAttackDebugRecords", []];
    missionNamespace setVariable ["bskulls_titanTopAttackUnitStateRecords", []];
};

if (_enabled && {!_wasEnabled || {_clearRecords}}) then {
    missionNamespace setVariable ["bskulls_titanTopAttackDebugStartedAt", diag_tickTime];
};

// XEH starts monitors for units created while debugging is already enabled.
// Re-running the initializer here also handles units that already exist and
// terminates their loops immediately when diagnostics are switched off.
private _hawkinsUnits = allUnits select {
    _x isKindOf "B_PTbskull_Veh_Unit_Hawkins_blackops_04"
};
{
    [_x] call bskulls_fnc_titanTopAttackInitUnitDebug;
} forEach _hawkinsUnits;

private _runningMonitors = {
    private _handle = _x getVariable ["bskulls_titanTopAttackUnitDebugHandle", scriptNull];
    !scriptDone _handle
} count _hawkinsUnits;
private _state = ["disabled", "enabled"] select _enabled;
private _message = format [
    "Archangel diagnostics %1 (chat: %2, local AI monitors: %3).",
    _state,
    _enabled && {_chat},
    _runningMonitors
];

diag_log format ["[BSKULLS][TITAN-TA] %1", _message];
if (hasInterface) then {
    systemChat _message;
};

[_enabled, _enabled && {_chat}, count _hawkinsUnits, _runningMonitors]
