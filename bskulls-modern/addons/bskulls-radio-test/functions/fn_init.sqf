/*
    Runtime proof for the native enemy-report interception experiment.

    Search the client RPT for "BSK radio enemy-report test:".
    Counter order is [all group protocol messages, native enemy reports,
    other group protocol messages].  This observer never blocks chat and never
    changes AI, knowledge, target, datalink, or radio state.
*/

if (!hasInterface) exitWith {};

[] spawn {
    scriptName "BSK native enemy-report interception test";
    waitUntil {
        uiSleep 0.1;
        !isNull player
    };

    if (missionNamespace getVariable ["BSK_radioEnemyReportTestStarted", false]) exitWith {};
    missionNamespace setVariable ["BSK_radioEnemyReportTestStarted", true];
    missionNamespace setVariable ["BSK_radioEnemyReportTestCounts", [0, 0, 0]];

    BSK_RadioTest_fnc_protocolState = {
        private _protocols = [
            "RadioProtocolENG",
            "RadioProtocolGRE",
            "RadioProtocolCHI",
            "RadioProtocolFemaleENG"
        ];

        _protocols apply {
            private _sentences = getArray (
                configFile
                >> _x
                >> "SelectEnemyDetectedSentence"
                >> "sentences"
            );
            [_x, count _sentences, _sentences isEqualTo []]
        }
    };

    private _initialState = [
        ["event", "started"],
        ["tick", diag_tickTime],
        [
            "addonLoaded",
            isClass (
                configFile
                >> "CfgPatches"
                >> "bskulls_radio_enemy_report_test"
            )
        ],
        ["selectors", call BSK_RadioTest_fnc_protocolState]
    ];
    diag_log format ["BSK radio enemy-report test: %1", _initialState];

    private _chatEventHandler = addMissionEventHandler ["HandleChatMessage", {
        params [
            "_channel",
            "_owner",
            "_from",
            "_text",
            "_person",
            "_name",
            "_strID",
            "_forcedDisplay",
            "_isPlayerMessage",
            "_sentenceType",
            "_chatMessageType",
            "_sentenceParams"
        ];

        if (_sentenceType isNotEqualTo 1) exitWith {};
        if (isNull _person) exitWith {};
        if (group _person isNotEqualTo group player) exitWith {};

        private _sentenceTemplate = _sentenceParams param [0, "", [""]];
        private _templateUpper = toUpper _sentenceTemplate;
        private _isEnemyReport = (_templateUpper find "$STR_A3_CONTACT") isEqualTo 0
            || {(_templateUpper find "$STR_A3_SENTENEMYDETECTED") isEqualTo 0};
        private _counts = missionNamespace getVariable [
            "BSK_radioEnemyReportTestCounts",
            [0, 0, 0]
        ];
        _counts set [0, (_counts select 0) + 1];
        private _counterIndex = [2, 1] select _isEnemyReport;
        _counts set [_counterIndex, (_counts select _counterIndex) + 1];
        missionNamespace setVariable ["BSK_radioEnemyReportTestCounts", _counts];

        private _voice = speaker _person;
        private _protocol = getText (
            configFile >> "CfgVoice" >> _voice >> "protocol"
        );
        private _details = [
            ["event", ["other-message", "enemy-report-escaped"] select _isEnemyReport],
            ["tick", diag_tickTime],
            ["counts", _counts],
            ["channel", _channel],
            ["owner", _owner],
            ["from", _from],
            ["text", _text],
            ["speaker", name _person],
            ["reportedName", _name],
            ["voice", _voice],
            ["protocol", _protocol],
            ["strID", _strID],
            ["forcedDisplay", _forcedDisplay],
            ["isPlayerMessage", _isPlayerMessage],
            ["chatMessageType", _chatMessageType],
            ["sentenceTemplate", _sentenceTemplate]
        ];
        diag_log format ["BSK radio enemy-report test: %1", _details];
    }];
    missionNamespace setVariable [
        "BSK_radioEnemyReportTestChatEH",
        _chatEventHandler
    ];

    private _lastVoiceSignature = [];
    while {true} do {
        private _playerGroup = group player;
        private _members = units _playerGroup;
        private _voiceSignature = _members apply {
            private _voice = speaker _x;
            [
                netId _x,
                name _x,
                _voice,
                getText (configFile >> "CfgVoice" >> _voice >> "protocol")
            ]
        };
        if (_voiceSignature isNotEqualTo _lastVoiceSignature) then {
            diag_log format [
                "BSK radio enemy-report test: %1",
                [
                    ["event", "group-speakers-changed"],
                    ["tick", diag_tickTime],
                    ["group", str _playerGroup],
                    ["memberCount", count _members]
                ]
            ];
            {
                diag_log format [
                    "BSK radio enemy-report test: %1",
                    [
                        ["event", "group-speaker"],
                        ["tick", diag_tickTime],
                        ["member", _x]
                    ]
                ];
            } forEach _voiceSignature;
            _lastVoiceSignature = _voiceSignature;
        };

        private _knownEnemies = player targets [true, 0, [], 0];
        private _connectedUAV = getConnectedUAV player;
        diag_log format [
            "BSK radio enemy-report test: %1",
            [
                ["event", "counter-snapshot"],
                ["tick", diag_tickTime],
                [
                    "counts",
                    missionNamespace getVariable [
                        "BSK_radioEnemyReportTestCounts",
                        [0, 0, 0]
                    ]
                ],
                ["knownEnemyCount", count _knownEnemies],
                ["selectors", call BSK_RadioTest_fnc_protocolState],
                ["connectedUAV", if (isNull _connectedUAV) then {"<null>"} else {netId _connectedUAV}]
            ]
        ];

        uiSleep 30;
    };
};
