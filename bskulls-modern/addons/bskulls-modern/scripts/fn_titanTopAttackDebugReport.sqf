/*
 * Snapshot the production Archangel configuration and buffered diagnostics.
 * The report remains available while collection is disabled.
 *
 * Debug Console examples:
 *   [true] call bskulls_fnc_titanTopAttackSetDebug;
 *   [] call bskulls_fnc_titanTopAttackDebugReport;
 *
 * Pass false to avoid copying, or true as the second argument to clear the
 * buffer after taking the snapshot: [false, true] call ...
 */

params [
    ["_copyToClipboard", true, [true]],
    ["_clearAfter", false, [false]]
];

private _carrier = configFile >> "CfgAmmo" >> "M_Titan_AT_TOP_PLUS";
private _terminal = configFile >> "CfgAmmo" >> "ammo_Penetrator_Titan_AT_TOP_PLUS";
private _magazine = configFile >> "CfgMagazines" >> "Titan_AT_TOP_PLUS";
private _launcher = configFile >> "CfgWeapons" >> "B_PTbskull_Wea_law_02_titantop";
private _overfly = _launcher >> "Overfly";
private _optic = configFile >> "RscInGameUI" >> "B_PTbskull_RscOptics_Archangel";
private _softLaunchEffectName = getText (_carrier >> "effectsMissileInit");
private _softLaunchEffect = configFile >> _softLaunchEffectName;
private _softLaunchCloudletName = getText (_softLaunchEffect >> "EjectionSmoke" >> "type");
private _softLaunchCloudlet = configFile >> "CfgCloudlets" >> _softLaunchCloudletName;
private _visualCloudletName = getText (_terminal >> "bskulls_terminalVisualCloudlet");
private _visualCloudlet = configFile >> "CfgCloudlets" >> _visualCloudletName;
private _records = +(missionNamespace getVariable ["bskulls_titanTopAttackDebugRecords", []]);
private _unitStateRecords = +(
    missionNamespace getVariable ["bskulls_titanTopAttackUnitStateRecords", []]
);
private _debugStartedAt = missionNamespace getVariable [
    "bskulls_titanTopAttackDebugStartedAt",
    -1
];
private _dapsExcludedAmmo = missionNamespace getVariable ["dapsExcludedAmmo", []];
private _hawkinsUnits = allUnits select {
    _x isKindOf "B_PTbskull_Veh_Unit_Hawkins_blackops_04"
};

private _report = [
    ["report", "Black Skulls HVPS-17 Archangel"],
    ["schemaVersion", 2],
    ["tick", diag_tickTime],
    ["world", worldName],
    ["machine", [clientOwner, isServer, hasInterface]],
    ["particleQuality", particlesQuality],
    ["environment", [
        ["date", date],
        ["dayTime", dayTime],
        ["sunOrMoon", sunOrMoon],
        ["overcast", overcast],
        ["fog", fog],
        ["rain", rain],
        ["viewDistance", viewDistance],
        ["objectViewDistance", getObjectViewDistance]
    ]],
    ["debug", [
        ["enabled", missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]],
        ["chat", missionNamespace getVariable ["bskulls_titanTopAttackDebugChat", false]],
        ["startedAtTick", _debugStartedAt],
        ["elapsed", if (_debugStartedAt < 0) then {-1} else {diag_tickTime - _debugStartedAt}],
        ["accuracyOverride", missionNamespace getVariable ["bskulls_titanTopAttackAccuracyOverride", ""]],
        ["hawkinsMonitors", _hawkinsUnits apply {
            private _handle = _x getVariable ["bskulls_titanTopAttackUnitDebugHandle", scriptNull];
            [
                ["unit", str _x],
                ["local", local _x],
                ["alive", alive _x],
                ["running", !scriptDone _handle]
            ]
        }]
    ]],
    ["daps", [
        ["maxAngle", missionNamespace getVariable ["dapsMaxAngle", "unset"]],
        ["hitLimit", missionNamespace getVariable ["dapsHitLimit", "unset"]],
        ["excludedAmmoPresent", !(isNil "dapsExcludedAmmo")],
        ["carrierExcluded", "M_Titan_AT_TOP_PLUS" in _dapsExcludedAmmo],
        ["terminalExcluded", "ammo_Penetrator_Titan_AT_TOP_PLUS" in _dapsExcludedAmmo]
    ]],
    ["carrierConfig", [
        ["present", isClass _carrier],
        ["simulation", getText (_carrier >> "simulation")],
        ["hit", getNumber (_carrier >> "hit")],
        ["indirectHit", getNumber (_carrier >> "indirectHit")],
        ["indirectHitRange", getNumber (_carrier >> "indirectHitRange")],
        ["explosive", getNumber (_carrier >> "explosive")],
        ["cost", getNumber (_carrier >> "cost")],
        ["aiAmmoUsageFlags", getNumber (_carrier >> "aiAmmoUsageFlags")],
        ["irLock", getNumber (_carrier >> "irLock")],
        ["airLock", getNumber (_carrier >> "airLock")],
        ["weaponLockSystem", getNumber (_carrier >> "weaponLockSystem")],
        ["allowAgainstInfantry", getNumber (_carrier >> "allowAgainstInfantry")],
        ["initTime", getNumber (_carrier >> "initTime")],
        ["thrust", getNumber (_carrier >> "thrust")],
        ["thrustTime", getNumber (_carrier >> "thrustTime")],
        ["maxSpeed", getNumber (_carrier >> "maxSpeed")],
        ["effectsMissileInit", _softLaunchEffectName],
        ["effectsMissileInitPresent", isClass _softLaunchEffect],
        ["effectsMissile", getText (_carrier >> "effectsMissile")],
        ["softLaunchSafeDistance", getNumber (_carrier >> "bskulls_softLaunchSafeDistance")],
        ["flightProfiles", getArray (_carrier >> "flightProfiles")],
        ["triggerDistance", getNumber (_carrier >> "triggerDistance")],
        ["triggerOnImpact", getNumber (_carrier >> "triggerOnImpact")],
        ["submunitionAmmo", getText (_carrier >> "submunitionAmmo")],
        ["submunitionDirectionType", getText (_carrier >> "submunitionDirectionType")],
        ["submunitionInitSpeed", getNumber (_carrier >> "submunitionInitSpeed")],
        ["overflyElevation", getNumber (_carrier >> "Overfly" >> "overflyElevation")],
        ["missileLockCone", getNumber (_carrier >> "missileLockCone")],
        ["missileKeepLockedCone", getNumber (_carrier >> "missileKeepLockedCone")],
        ["missileLockMinDistance", getNumber (_carrier >> "missileLockMinDistance")],
        ["missileLockMaxDistance", getNumber (_carrier >> "missileLockMaxDistance")],
        ["missileLockMaxSpeed", getNumber (_carrier >> "missileLockMaxSpeed")]
    ]],
    ["softLaunchVisual", [
        ["effectPresent", isClass _softLaunchEffect],
        ["effect", _softLaunchEffectName],
        ["cloudletPresent", isClass _softLaunchCloudlet],
        ["cloudlet", _softLaunchCloudletName],
        ["interval", getNumber (_softLaunchCloudlet >> "interval")],
        ["lifeTime", getNumber (_softLaunchCloudlet >> "lifeTime")],
        ["particleShape", getText (_softLaunchCloudlet >> "particleShape")],
        ["size", getArray (_softLaunchCloudlet >> "size")],
        ["color", getArray (_softLaunchCloudlet >> "color")]
    ]],
    ["terminalConfig", [
        ["present", isClass _terminal],
        ["simulation", getText (_terminal >> "simulation")],
        ["model", getText (_terminal >> "model")],
        ["effectFly", getText (_terminal >> "effectFly")],
        ["tracerScale", getNumber (_terminal >> "tracerScale")],
        ["tracerStartTime", getNumber (_terminal >> "tracerStartTime")],
        ["tracerEndTime", getNumber (_terminal >> "tracerEndTime")],
        ["nvgOnly", getNumber (_terminal >> "nvgOnly")],
        ["visualProfile", getText (_terminal >> "bskulls_terminalVisualProfile")],
        ["visualCloudlet", _visualCloudletName],
        ["visualDropInterval", getNumber (_terminal >> "bskulls_terminalVisualDropInterval")],
        ["visualLinger", getNumber (_terminal >> "bskulls_terminalVisualLinger")],
        ["visualCurveAmplitudeMin", getNumber (_terminal >> "bskulls_terminalVisualCurveAmplitudeMin")],
        ["visualCurveAmplitudeMax", getNumber (_terminal >> "bskulls_terminalVisualCurveAmplitudeMax")],
        ["visualCurveSecondaryMax", getNumber (_terminal >> "bskulls_terminalVisualCurveSecondaryMax")],
        ["accuracyProbability", getNumber (_terminal >> "bskulls_terminalAccuracyProbability")],
        ["missOffsetMin", getNumber (_terminal >> "bskulls_terminalMissOffsetMin")],
        ["missOffsetMax", getNumber (_terminal >> "bskulls_terminalMissOffsetMax")],
        ["hit", getNumber (_terminal >> "hit")],
        ["timeToLive", getNumber (_terminal >> "timeToLive")],
        ["typicalSpeed", getNumber (_terminal >> "typicalSpeed")],
        ["triggerOnImpact", getNumber (_terminal >> "triggerOnImpact")]
    ]],
    ["terminalVisual", [
        ["present", isClass _visualCloudlet],
        ["class", _visualCloudletName],
        ["interval", getNumber (_visualCloudlet >> "interval")],
        ["lifeTime", getNumber (_visualCloudlet >> "lifeTime")],
        ["particleShape", getText (_visualCloudlet >> "particleShape")],
        ["particleFrames", [
            getNumber (_visualCloudlet >> "particleFSNtieth"),
            getNumber (_visualCloudlet >> "particleFSIndex"),
            getNumber (_visualCloudlet >> "particleFSFrameCount")
        ]],
        ["size", getArray (_visualCloudlet >> "size")],
        ["color", getArray (_visualCloudlet >> "color")],
        ["positionVar", getArray (_visualCloudlet >> "positionVar")],
        ["moveVelocityVar", getArray (_visualCloudlet >> "moveVelocityVar")]
    ]],
    ["magazineConfig", [
        ["present", isClass _magazine],
        ["displayName", getText (_magazine >> "displayName")],
        ["displayNameShort", getText (_magazine >> "displayNameShort")],
        ["descriptionShort", getText (_magazine >> "descriptionShort")],
        ["ammo", getText (_magazine >> "ammo")],
        ["initSpeed", getNumber (_magazine >> "initSpeed")],
        ["count", getNumber (_magazine >> "count")]
    ]],
    ["launcherConfig", [
        ["present", isClass _launcher],
        ["displayName", getText (_launcher >> "displayName")],
        ["descriptionShort", getText (_launcher >> "descriptionShort")],
        ["magazines", getArray (_launcher >> "magazines")],
        ["magazineWell", getArray (_launcher >> "magazineWell")],
        ["modes", getArray (_launcher >> "modes")],
        ["canLock", getNumber (_launcher >> "canLock")],
        ["weaponLockSystem", getNumber (_launcher >> "weaponLockSystem")],
        ["weaponLockDelay", getNumber (_launcher >> "weaponLockDelay")],
        ["lockAcquire", getNumber (_launcher >> "lockAcquire")],
        ["weaponInfoType", getText (_launcher >> "weaponInfoType")],
        ["opticPresent", isClass _optic],
        ["opticOnLoad", getText (_optic >> "onLoad")],
        ["hudGroupPresent", isClass (_optic >> "CA_javelin_elements_group")],
        ["hudGroupIdc", getNumber (_optic >> "CA_javelin_elements_group" >> "idc")],
        ["topOffIdc", getNumber (_optic >> "CA_javelin_elements_group" >> "Controls" >> "CA_Javelin_TOP_off" >> "idc")],
        ["dirOnIdc", getNumber (_optic >> "CA_javelin_elements_group" >> "Controls" >> "CA_Javelin_DIR_on" >> "idc")],
        ["aiRateOfFire", getNumber (_overfly >> "aiRateOfFire")],
        ["aiRateOfFireDistance", getNumber (_overfly >> "aiRateOfFireDistance")],
        ["minRange", getNumber (_overfly >> "minRange")],
        ["minRangeProbab", getNumber (_overfly >> "minRangeProbab")],
        ["midRange", getNumber (_overfly >> "midRange")],
        ["midRangeProbab", getNumber (_overfly >> "midRangeProbab")],
        ["maxRange", getNumber (_overfly >> "maxRange")],
        ["maxRangeProbab", getNumber (_overfly >> "maxRangeProbab")]
    ]],
    ["recordCount", count _records],
    ["recordLimit", 500],
    ["recordBufferFull", (count _records) >= 500],
    ["unitStateRecordCount", count _unitStateRecords],
    ["unitStateRecordLimit", 240],
    ["unitStateBufferFull", (count _unitStateRecords) >= 240],
    ["unitStateRecords", _unitStateRecords],
    ["records", _records]
];

diag_log format ["[BSKULLS][TITAN-TA] DEBUG_REPORT %1", _report];
if (_copyToClipboard && {hasInterface}) then {
    copyToClipboard str _report;
    systemChat format [
        "Archangel report copied (%1 events, %2 preserved AI states).",
        count _records,
        count _unitStateRecords
    ];
};

if (_clearAfter) then {
    missionNamespace setVariable ["bskulls_titanTopAttackDebugRecords", []];
    missionNamespace setVariable ["bskulls_titanTopAttackUnitStateRecords", []];
    if (missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]) then {
        missionNamespace setVariable ["bskulls_titanTopAttackDebugStartedAt", diag_tickTime];
    };
};

_report
