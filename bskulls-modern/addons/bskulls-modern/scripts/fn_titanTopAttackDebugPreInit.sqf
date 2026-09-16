/*
 * Register save-load recovery before mission state can be restored. Bohemia's
 * Loaded mission event is the supported hook for recreating runtime-only
 * monitoring; an EachFrame event defers object access until restoration has
 * completed without creating another scheduled script to serialize.
 *
 * https://community.bohemia.net/wiki/Arma_3:_Mission_Event_Handlers
 * https://community.bohemia.net/wiki/addMissionEventHandler
 */

if (isNil {localNamespace getVariable "bskulls_titanTopAttackDebug"}) then {
    localNamespace setVariable ["bskulls_titanTopAttackDebug", true];
    localNamespace setVariable ["bskulls_titanTopAttackDebugChat", false];
};
localNamespace setVariable ["bskulls_titanTopAttackDebugAutoStarted", true];
localNamespace setVariable [
    "bskulls_titanTopAttackAcquisitionTestRunning",
    false
];
localNamespace setVariable [
    "bskulls_titanTopAttackAcquisitionTestResult",
    []
];
localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourTestRunning",
    false
];
localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourTestResult",
    []
];
localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourIsolationTestRunning",
    false
];
localNamespace setVariable [
    "bskulls_titanTopAttackBehaviourIsolationTestResult",
    []
];
localNamespace setVariable [
    "bskulls_titanTopAttackRadioRoeTestRunning",
    false
];
localNamespace setVariable [
    "bskulls_titanTopAttackRadioRoeTestResult",
    []
];

private _oldLoadedEh = localNamespace getVariable [
    "bskulls_titanTopAttackLoadedEh",
    -1
];
if (_oldLoadedEh >= 0) then {
    removeMissionEventHandler ["Loaded", _oldLoadedEh];
};

private _loadedEh = addMissionEventHandler ["Loaded", {
    localNamespace setVariable ["bskulls_titanTopAttackDebugAutoStarted", true];
    private _discoveryHandle = localNamespace getVariable [
        "bskulls_titanTopAttackLauncherDiscoveryPfh",
        -1
    ];
    if (_discoveryHandle >= 0) then {
        [_discoveryHandle] call CBA_fnc_removePerFrameHandler;
    };
    localNamespace setVariable [
        "bskulls_titanTopAttackLauncherDiscoveryPfh",
        -1
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackLauncherUnits",
        []
    ];
    {
        localNamespace setVariable [_x, nil];
    } forEach (localNamespace getVariable [
        "bskulls_titanTopAttackTransientMonitorNames",
        []
    ]);
    localNamespace setVariable [
        "bskulls_titanTopAttackTransientMonitorNames",
        []
    ];
    localNamespace setVariable ["bskulls_titanTopAttackSeparatedTraces", []];

    // Keep only the two persistent diagnostic PFH identifiers. Their CBA
    // callbacks repopulate local comparison state after the load. In-flight
    // discipline, projectile, visual, and telemetry state must follow the
    // restored timeline rather than the one from which the user loaded.
    private _runtimeRecords = localNamespace getVariable [
        "bskulls_titanTopAttackRuntimeRecords",
        []
    ];
    _runtimeRecords = _runtimeRecords select {
        (_x param [1, ""]) in ["unit-debug-pfh", "order-debug-pfh"]
    };
    localNamespace setVariable [
        "bskulls_titanTopAttackRuntimeRecords",
        _runtimeRecords
    ];

    localNamespace setVariable ["bskulls_titanTopAttackDebugRecords", []];
    localNamespace setVariable ["bskulls_titanTopAttackUnitStateRecords", []];
    localNamespace setVariable ["bskulls_titanTopAttackOrderRecords", []];
    localNamespace setVariable [
        "bskulls_titanTopAttackAcquisitionTestRunning",
        false
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackAcquisitionTestResult",
        []
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackBehaviourTestRunning",
        false
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackBehaviourTestResult",
        []
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackBehaviourIsolationTestRunning",
        false
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackBehaviourIsolationTestResult",
        []
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackRadioRoeTestRunning",
        false
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackRadioRoeTestResult",
        []
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackDebugStartedAt",
        diag_tickTime
    ];
    localNamespace setVariable [
        "bskulls_titanTopAttackLoadResumeFrames",
        0
    ];

    addMissionEventHandler ["EachFrame", {
        private _resumeFrames = 1 + (localNamespace getVariable [
            "bskulls_titanTopAttackLoadResumeFrames",
            0
        ]);
        localNamespace setVariable [
            "bskulls_titanTopAttackLoadResumeFrames",
            _resumeFrames
        ];
        if (
            !isSaving
            && {_resumeFrames >= 3}
            && {!hasInterface || {!isNull player}}
        ) then {
            removeMissionEventHandler ["EachFrame", _thisEventHandler];
            private _enabled = localNamespace getVariable [
                "bskulls_titanTopAttackDebug",
                true
            ];
            [_enabled, false, false] call bskulls_fnc_titanTopAttackSetDebug;
            [
                objNull,
                "DEBUG_RESUMED_AFTER_LOAD",
                [["enabled", _enabled]],
                "load"
            ] call bskulls_fnc_titanTopAttackLog;
        };
    }];
}];
localNamespace setVariable [
    "bskulls_titanTopAttackLoadedEh",
    _loadedEh
];

true
