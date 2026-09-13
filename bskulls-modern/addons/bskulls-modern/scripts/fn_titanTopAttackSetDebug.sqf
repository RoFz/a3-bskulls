/*
 * Enable or disable Archangel diagnostics on the machine executing this call.
 * Collection starts automatically in the diagnostic build. Use Local Exec in
 * single-player and Global Exec when changing every multiplayer machine.
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

private _wasEnabled = localNamespace getVariable ["bskulls_titanTopAttackDebug", false];
localNamespace setVariable ["bskulls_titanTopAttackDebug", _enabled];
localNamespace setVariable ["bskulls_titanTopAttackDebugChat", _enabled && {_chat}];

if (_clearRecords) then {
    localNamespace setVariable ["bskulls_titanTopAttackDebugRecords", []];
    localNamespace setVariable ["bskulls_titanTopAttackUnitStateRecords", []];
    localNamespace setVariable ["bskulls_titanTopAttackOrderRecords", []];
};

if (_enabled && {!_wasEnabled || {_clearRecords}}) then {
    localNamespace setVariable ["bskulls_titanTopAttackDebugStartedAt", diag_tickTime];
};

// XEH starts monitors for units created while debugging is already enabled.
// Re-running the initializer here also handles units that already exist and
// removes their per-frame handlers when diagnostics are switched off.
private _hawkinsUnits = allUnits select {
    _x isKindOf "B_PTbskull_Veh_Unit_Hawkins_blackops_04"
};
{
    [_x] call bskulls_fnc_titanTopAttackInitUnitDebug;
    [_x] call bskulls_fnc_titanTopAttackInitOrderDebug;
} forEach _hawkinsUnits;

private _runningMonitors = {
    private _handle = [
        _x,
        "unit-debug-pfh",
        -1
    ] call bskulls_fnc_titanTopAttackRuntimeGet;
    _handle >= 0
} count _hawkinsUnits;
private _runningOrderMonitors = {
    private _handle = [
        _x,
        "order-debug-pfh",
        -1
    ] call bskulls_fnc_titanTopAttackRuntimeGet;
    _handle >= 0
} count _hawkinsUnits;
private _state = ["disabled", "enabled"] select _enabled;
private _message = format [
    "Archangel diagnostics %1 (chat: %2, local AI monitors: %3, order monitors: %4).",
    _state,
    _enabled && {_chat},
    _runningMonitors,
    _runningOrderMonitors
];

diag_log format ["[BSKULLS][TITAN-TA] %1", _message];
if (hasInterface) then {
    systemChat _message;
};

[
    _enabled,
    _enabled && {_chat},
    count _hawkinsUnits,
    _runningMonitors,
    _runningOrderMonitors
]
