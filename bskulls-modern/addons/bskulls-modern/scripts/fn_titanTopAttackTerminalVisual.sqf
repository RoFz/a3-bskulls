/*
 * Render an explicit local smoke source for Archangel's very short terminal
 * stage. This source makes the selected profile visible on every interface
 * where projectile Init runs and keeps already-emitted particles alive after
 * the penetrator impacts. Optional path variance moves only this visual source;
 * it never changes the projectile position, velocity, damage, or DAPS geometry.
 */

params [["_projectile", objNull, [objNull]]];

if (isNull _projectile || {!hasInterface}) exitWith {false};

private _projectileClass = typeOf _projectile;
private _ammoConfig = configFile >> "CfgAmmo" >> _projectileClass;
private _cloudletClass = getText (_ammoConfig >> "bskulls_terminalVisualCloudlet");
if (_cloudletClass isEqualTo "") exitWith {false};

// Projectile variables are local here: every rendering client needs its own
// local particle source, but repeated Init/Fired paths on one client must not
// create duplicates.
if (_projectile getVariable ["bskulls_titanTopAttackVisualInitialized", false]) exitWith {true};
_projectile setVariable ["bskulls_titanTopAttackVisualInitialized", true, false];

private _traceId = _projectile getVariable ["bskulls_titanTopAttackTraceId", "untracked"];
private _debugEnabled = missionNamespace getVariable ["bskulls_titanTopAttackDebug", false];
private _profile = getText (_ammoConfig >> "bskulls_terminalVisualProfile");
private _cloudletConfig = configFile >> "CfgCloudlets" >> _cloudletClass;
private _dropInterval = getNumber (_ammoConfig >> "bskulls_terminalVisualDropInterval");
private _linger = getNumber (_ammoConfig >> "bskulls_terminalVisualLinger");
private _curveAmplitudeMin = (getNumber (_ammoConfig >> "bskulls_terminalVisualCurveAmplitudeMin")) max 0;
private _curveAmplitudeMax = (getNumber (_ammoConfig >> "bskulls_terminalVisualCurveAmplitudeMax")) max _curveAmplitudeMin;
private _curveSecondaryMax = (getNumber (_ammoConfig >> "bskulls_terminalVisualCurveSecondaryMax")) max 0;

if (_dropInterval <= 0) then {
    _dropInterval = getNumber (_cloudletConfig >> "interval");
};
if (_dropInterval <= 0) then {
    _dropInterval = 0.003;
};
if (_linger <= 0) then {
    _linger = 3;
};

if !(isClass _cloudletConfig) exitWith {
    if (_debugEnabled) then {
        [
            _projectile,
            "VISUAL_SOURCE_FAILED",
            [
                ["reason", "missing CfgCloudlets class"],
                ["profile", _profile],
                ["cloudlet", _cloudletClass],
                ["particleQuality", particlesQuality]
            ],
            _traceId
        ] call bskulls_fnc_titanTopAttackLog;
    };
    false
};

private _positionASL = getPosASL _projectile;
private _projectileSpeed = vectorMagnitude (velocity _projectile);
private _curveEnabled = _curveAmplitudeMax > 0;
private _curveAmplitude = if (_curveEnabled) then {
    _curveAmplitudeMin + random (_curveAmplitudeMax - _curveAmplitudeMin)
} else {
    0
};
private _curveDirection = [-1,1] select (floor (random 2));
private _curveSecondary = if (_curveEnabled) then {
    (random (2 * _curveSecondaryMax)) - _curveSecondaryMax
} else {
    0
};
private _curveTarget = _projectile getVariable ["bskulls_titanTopAttackTarget", objNull];
private _curveTargetPosASL = if (isNull _curveTarget) then {
    _projectile getVariable ["bskulls_titanTopAttackTargetPosASL", []]
} else {
    getPosASL _curveTarget
};
private _curveInitialDistance = if ((count _curveTargetPosASL) isEqualTo 3) then {
    _positionASL vectorDistance _curveTargetPosASL
} else {
    -1
};
private _curveEstimatedDuration = if (_projectileSpeed > 0.01) then {
    ([_curveInitialDistance,310] select (_curveInitialDistance <= 0)) / _projectileSpeed
} else {
    0.25
};
private _source = "#particlesource" createVehicleLocal (ASLToAGL _positionASL);
if (isNull _source) exitWith {
    if (_debugEnabled) then {
        [
            _projectile,
            "VISUAL_SOURCE_FAILED",
            [
                ["reason", "createVehicleLocal returned objNull"],
                ["profile", _profile],
                ["cloudlet", _cloudletClass],
                ["particleQuality", particlesQuality]
            ],
            _traceId
        ] call bskulls_fnc_titanTopAttackLog;
    };
    false
};

_source setParticleClass _cloudletClass;
_source setDropInterval _dropInterval;
_source attachTo [_projectile, [0,0,0]];
_projectile setVariable ["bskulls_titanTopAttackVisualSource", _source, false];

if (_debugEnabled) then {
    private _observerDistance = if (isNull cameraOn) then {
        -1
    } else {
        cameraOn distance _projectile
    };
    [
        _projectile,
        "VISUAL_SOURCE_CREATED",
        [
            ["profile", _profile],
            ["cloudlet", _cloudletClass],
            ["cloudletPresent", true],
            ["source", str _source],
            ["dropInterval", _dropInterval],
            ["configuredLifetime", getNumber (_cloudletConfig >> "lifeTime")],
            ["configuredParticleShape", getText (_cloudletConfig >> "particleShape")],
            ["configuredParticleFrames", [
                getNumber (_cloudletConfig >> "particleFSNtieth"),
                getNumber (_cloudletConfig >> "particleFSIndex"),
                getNumber (_cloudletConfig >> "particleFSFrameCount")
            ]],
            ["configuredSize", getArray (_cloudletConfig >> "size")],
            ["configuredColor", getArray (_cloudletConfig >> "color")],
            ["projectileSpeed", _projectileSpeed],
            ["estimatedParticleSpacing", _projectileSpeed * _dropInterval],
            ["visualCurve", [
                ["enabled", _curveEnabled],
                ["amplitude", _curveAmplitude],
                ["direction", _curveDirection],
                ["secondary", _curveSecondary],
                ["initialTargetDistance", _curveInitialDistance],
                ["estimatedDuration", _curveEstimatedDuration],
                ["physicalProjectileAffected", false],
                ["dapsGeometryAffected", false]
            ]],
            ["linger", _linger],
            ["particleQuality", particlesQuality],
            ["observerDistance", _observerDistance],
            ["positionASL", _positionASL]
        ],
        _traceId
    ] call bskulls_fnc_titanTopAttackLog;
};

private _startedAt = diag_tickTime;
private _lastPositionASL = _positionASL;
private _lastCurveProgress = 0;
private _lastCurveOffset = 0;
private _maximumCurveOffset = 0;
waitUntil {
    uiSleep 0.005;
    if (!isNull _projectile) then {
        _lastPositionASL = getPosASL _projectile;

        if (_curveEnabled) then {
            if (isNull _curveTarget) then {
                _curveTarget = _projectile getVariable ["bskulls_titanTopAttackTarget", objNull];
            };
            if (!isNull _curveTarget) then {
                _curveTargetPosASL = getPosASL _curveTarget;
            } else {
                private _configuredTargetPosASL = _projectile getVariable ["bskulls_titanTopAttackTargetPosASL", []];
                if ((count _configuredTargetPosASL) isEqualTo 3) then {
                    _curveTargetPosASL = _configuredTargetPosASL;
                };
            };

            if (_curveInitialDistance <= 0 && {(count _curveTargetPosASL) isEqualTo 3}) then {
                _curveInitialDistance = _lastPositionASL vectorDistance _curveTargetPosASL;
                if (_projectileSpeed > 0.01) then {
                    _curveEstimatedDuration = _curveInitialDistance / _projectileSpeed;
                };
            };

            _lastCurveProgress = if (
                _curveInitialDistance > 0
                && {(count _curveTargetPosASL) isEqualTo 3}
            ) then {
                1 - ((_lastPositionASL vectorDistance _curveTargetPosASL) / _curveInitialDistance)
            } else {
                (diag_tickTime - _startedAt) / (_curveEstimatedDuration max 0.01)
            };
            _lastCurveProgress = (_lastCurveProgress max 0) min 1;

            // SQF trigonometric functions use degrees. Both components are
            // zero at progress 0 and 1, keeping separation and impact aligned.
            private _curveFactor = (sin (180 * _lastCurveProgress))
                + (_curveSecondary * sin (360 * _lastCurveProgress));
            _lastCurveOffset = _curveDirection * _curveAmplitude * _curveFactor;
            _maximumCurveOffset = _maximumCurveOffset max (abs _lastCurveOffset);
            _source attachTo [_projectile, [_lastCurveOffset,0,0]];
        };
    };
    isNull _projectile || {(diag_tickTime - _startedAt) >= 1.2}
};

// Stop new particles without deleting the source yet. Existing particles can
// then complete their configured lifetime instead of vanishing at impact.
if (!isNull _source) then {
    detach _source;
    _source setPosASL _lastPositionASL;
    _source setDropInterval 3600;
};

if (_debugEnabled) then {
    [
        objNull,
        "VISUAL_EMISSION_ENDED",
        [
            ["profile", _profile],
            ["cloudlet", _cloudletClass],
            ["sourceAlive", !isNull _source],
            ["emittedFor", diag_tickTime - _startedAt],
            ["lastPositionASL", _lastPositionASL],
            ["visualCurve", [
                ["enabled", _curveEnabled],
                ["progress", _lastCurveProgress],
                ["lastOffset", _lastCurveOffset],
                ["maximumObservedOffset", _maximumCurveOffset],
                ["physicalProjectileAffected", false],
                ["dapsGeometryAffected", false]
            ]],
            ["linger", _linger]
        ],
        _traceId
    ] call bskulls_fnc_titanTopAttackLog;
};

uiSleep _linger;
if (!isNull _source) then {
    deleteVehicle _source;
};

if (_debugEnabled) then {
    [
        objNull,
        "VISUAL_SOURCE_DELETED",
        [
            ["profile", _profile],
            ["cloudlet", _cloudletClass],
            ["elapsed", diag_tickTime - _startedAt]
        ],
        _traceId
    ] call bskulls_fnc_titanTopAttackLog;
};

true
