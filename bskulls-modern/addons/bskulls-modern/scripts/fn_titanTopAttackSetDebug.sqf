/*
 * Enable or disable launcher-AI diagnostics on the machine executing this
 * call. Collection starts automatically in the diagnostic build. Use Local
 * Exec in single-player and Global Exec when changing every multiplayer
 * machine.
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
    localNamespace setVariable [
        "bskulls_titanTopAttackAcquisitionTestResult",
        []
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackBehaviourTestResult",
        []
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackBehaviourIsolationTestResult",
        []
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackRadioRoeTestResult",
        []
    ];
};

if (_enabled && {!_wasEnabled || {_clearRecords}}) then {
    localNamespace setVariable ["bskulls_titanTopAttackDebugStartedAt", diag_tickTime];
};

// Recreate the discovery handler on every state change. Both its handle and
// tracked object list live in localNamespace so neither enters mission saves.
private _oldDiscoveryHandle = localNamespace getVariable [
    "bskulls_titanTopAttackLauncherDiscoveryPfh",
    -1
];
if (_oldDiscoveryHandle >= 0) then {
    [_oldDiscoveryHandle] call CBA_fnc_removePerFrameHandler;
};
localNamespace setVariable [
    "bskulls_titanTopAttackLauncherDiscoveryPfh",
    -1
];

private _previousUnits = localNamespace getVariable [
    "bskulls_titanTopAttackLauncherUnits",
    []
];
private _launcherUnits = allUnits select {
    private _candidate = _x;
    local _candidate
    && {alive _candidate}
    && {!isPlayer _candidate}
    && {(secondaryWeapon _candidate) isNotEqualTo ""}
    && {({isPlayer _x} count units group _candidate) > 0}
};
private _refreshUnits = [];
{
    if (!isNull _x) then {
        _refreshUnits pushBackUnique _x;
    };
} forEach (_previousUnits + _launcherUnits);
{
    [_x] call bskulls_fnc_titanTopAttackInitUnitDebug;
    [_x] call bskulls_fnc_titanTopAttackInitOrderDebug;
} forEach _refreshUnits;
localNamespace setVariable [
    "bskulls_titanTopAttackLauncherUnits",
    [_launcherUnits, []] select !_enabled
];

if (_enabled) then {
    private _discoveryHandle = [{
        private _previousUnits = localNamespace getVariable [
            "bskulls_titanTopAttackLauncherUnits",
            []
        ];
        private _launcherUnits = allUnits select {
            private _candidate = _x;
            local _candidate
            && {alive _candidate}
            && {!isPlayer _candidate}
            && {(secondaryWeapon _candidate) isNotEqualTo ""}
            && {({isPlayer _x} count units group _candidate) > 0}
        };
        private _refreshUnits = [];
        {
            if (!isNull _x) then {
                _refreshUnits pushBackUnique _x;
            };
        } forEach (_previousUnits + _launcherUnits);
        {
            [_x] call bskulls_fnc_titanTopAttackInitUnitDebug;
            [_x] call bskulls_fnc_titanTopAttackInitOrderDebug;
        } forEach _refreshUnits;
        localNamespace setVariable [
            "bskulls_titanTopAttackLauncherUnits",
            _launcherUnits
        ];
    }, 2, []] call CBA_fnc_addPerFrameHandler;
    localNamespace setVariable [
        "bskulls_titanTopAttackLauncherDiscoveryPfh",
        _discoveryHandle
    ];
};

private _runningMonitors = {
    private _handle = [
        _x,
        "unit-debug-pfh",
        -1
    ] call bskulls_fnc_titanTopAttackRuntimeGet;
    _handle >= 0
} count _launcherUnits;
private _runningOrderMonitors = {
    private _handle = [
        _x,
        "order-debug-pfh",
        -1
    ] call bskulls_fnc_titanTopAttackRuntimeGet;
    _handle >= 0
} count _launcherUnits;
private _state = ["disabled", "enabled"] select _enabled;
private _message = format [
    "Launcher AI diagnostics %1 (chat: %2, carriers: %3, state monitors: %4, order monitors: %5).",
    _state,
    _enabled && {_chat},
    count _launcherUnits,
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
    count _launcherUnits,
    _runningMonitors,
    _runningOrderMonitors
]
