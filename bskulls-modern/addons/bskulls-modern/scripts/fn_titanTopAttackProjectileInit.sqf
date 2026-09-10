/*
 * Ammo-config Init handler for both stages of the Titan top-attack round.
 * Cosmetic terminal sources are local to each interface; authoritative
 * diagnostics and projectile handlers remain limited to projectile locality.
 */

params [["_projectile", objNull, [objNull]]];

if (isNull _projectile) exitWith {false};

private _projectileClass = typeOf _projectile;
private _carrierClass = "M_Titan_AT_TOP_PLUS";
private _terminalClass = "ammo_Penetrator_Titan_AT_TOP_PLUS";
if !(_projectileClass in [_carrierClass, _terminalClass]) exitWith {false};

private _stage = ["terminal", "carrier"] select (_projectileClass isEqualTo _carrierClass);
if (_stage isEqualTo "terminal") then {
    [_projectile] spawn bskulls_fnc_titanTopAttackTerminalVisual;
};

if (!local _projectile) exitWith {true};

if (_projectile getVariable ["bskulls_titanTopAttackInitialized", false]) exitWith {true};
_projectile setVariable ["bskulls_titanTopAttackInitialized", true, false];
_projectile setVariable ["bskulls_titanTopAttackStage", _stage, false];

if (_stage isEqualTo "carrier") then {
    _projectile addEventHandler ["SubmunitionCreated", {
        _this call bskulls_fnc_titanTopAttackSubmunitionCreated;
    }];
};

// Target transfer and the terminal visual remain active with diagnostics off;
// only the report construction and high-frequency trace are optional.
if !(missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]) exitWith {true};

// SubmunitionCreated and the child's config Init do not have a documented
// ordering. Preserve a trace ID already assigned by the parent callback so
// either event order links both stages correctly.
private _traceId = _projectile getVariable ["bskulls_titanTopAttackTraceId", ""];
if (_traceId isEqualTo "") then {
    private _counter = 1 + (missionNamespace getVariable ["bskulls_titanTopAttackTraceCounter", 0]);
    missionNamespace setVariable ["bskulls_titanTopAttackTraceCounter", _counter];
    _traceId = format ["%1-%2-%3", clientOwner, floor (diag_tickTime * 1000), _counter];
};
_projectile setVariable ["bskulls_titanTopAttackTraceId", _traceId, false];

private _shotParents = (getShotParents _projectile) apply {str _x};
private _visualConfig = [];
if (_stage isEqualTo "terminal") then {
    private _ammoConfig = configFile >> "CfgAmmo" >> _projectileClass;
    private _effectName = getText (_ammoConfig >> "effectFly");
    _visualConfig = [
        ["model", getText (_ammoConfig >> "model")],
        ["effectFly", _effectName],
        ["effectPresent", _effectName isNotEqualTo "" && {isClass (configFile >> _effectName)}],
        ["scriptedProfile", getText (_ammoConfig >> "bskulls_terminalVisualProfile")],
        ["scriptedCloudlet", getText (_ammoConfig >> "bskulls_terminalVisualCloudlet")],
        ["scriptedDropInterval", getNumber (_ammoConfig >> "bskulls_terminalVisualDropInterval")],
        ["scriptedLinger", getNumber (_ammoConfig >> "bskulls_terminalVisualLinger")],
        ["visualCurveAmplitudeMin", getNumber (_ammoConfig >> "bskulls_terminalVisualCurveAmplitudeMin")],
        ["visualCurveAmplitudeMax", getNumber (_ammoConfig >> "bskulls_terminalVisualCurveAmplitudeMax")],
        ["visualCurveSecondaryMax", getNumber (_ammoConfig >> "bskulls_terminalVisualCurveSecondaryMax")],
        ["visualCurvePhysicalProjectileAffected", false],
        ["accuracyProbability", getNumber (_ammoConfig >> "bskulls_terminalAccuracyProbability")],
        ["missOffsetMin", getNumber (_ammoConfig >> "bskulls_terminalMissOffsetMin")],
        ["missOffsetMax", getNumber (_ammoConfig >> "bskulls_terminalMissOffsetMax")],
        ["tracerScale", getNumber (_ammoConfig >> "tracerScale")],
        ["tracerStartTime", getNumber (_ammoConfig >> "tracerStartTime")],
        ["tracerEndTime", getNumber (_ammoConfig >> "tracerEndTime")],
        ["nvgOnly", getNumber (_ammoConfig >> "nvgOnly")]
    ];
};
[
    _projectile,
    "PROJECTILE_INIT",
    [
        ["stage", _stage],
        ["positionASL", getPosASL _projectile],
        ["velocity", velocity _projectile],
        ["shotParents", _shotParents],
        ["visualConfig", _visualConfig],
        ["dapsMaxAngle", missionNamespace getVariable ["dapsMaxAngle", "unset"]],
        ["dapsHitLimit", missionNamespace getVariable ["dapsHitLimit", "unset"]]
    ]
] call bskulls_fnc_titanTopAttackLog;

[_projectile] spawn bskulls_fnc_titanTopAttackTrace;

true
