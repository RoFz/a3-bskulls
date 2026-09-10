/* Link the engine-created terminal penetrator to its carrier trace. */

params [
    ["_parent", objNull, [objNull]],
    ["_child", objNull, [objNull]],
    ["_positionASL", [], [[]]],
    ["_velocity", [], [[]]]
];

if (isNull _child || {!local _child}) exitWith {false};

private _traceId = if (isNull _parent) then {
    _child getVariable ["bskulls_titanTopAttackTraceId", "untracked"]
} else {
    _parent getVariable ["bskulls_titanTopAttackTraceId", "untracked"]
};
private _childInitTraceId = _child getVariable ["bskulls_titanTopAttackTraceId", ""];
private _target = if (isNull _parent) then {
    objNull
} else {
    _parent getVariable ["bskulls_titanTopAttackTarget", objNull]
};
if (isNull _target && {!isNull _parent}) then {
    _target = missileTarget _parent;
};
private _targetPosASL = if (!isNull _target) then {
    getPosASL _target
} else {
    if (isNull _parent) then {
        []
    } else {
        _parent getVariable ["bskulls_titanTopAttackTargetPosASL", []]
    }
};

_child setVariable ["bskulls_titanTopAttackTraceId", _traceId, false];
_child setVariable ["bskulls_titanTopAttackStage", "terminal", false];
_child setVariable ["bskulls_titanTopAttackTarget", _target, false];
_child setVariable ["bskulls_titanTopAttackTargetPosASL", _targetPosASL, false];
private _debugEnabled = missionNamespace getVariable ["bskulls_titanTopAttackDebug", false];
if (_debugEnabled) then {
    if (!isNull _parent) then {
        _parent setVariable ["bskulls_titanTopAttackSeparated", true, false];
    };
    private _separatedTraces = missionNamespace getVariable ["bskulls_titanTopAttackSeparatedTraces", []];
    _separatedTraces pushBackUnique _traceId;
    if ((count _separatedTraces) > 100) then {
        _separatedTraces deleteAt 0;
    };
    missionNamespace setVariable ["bskulls_titanTopAttackSeparatedTraces", _separatedTraces];
};

if (_positionASL isEqualTo []) then {
    _positionASL = getPosASL _child;
};
if (_velocity isEqualTo []) then {
    _velocity = velocity _child;
};

// Apply one explicit terminal-guidance outcome. This is intentionally a
// Bernoulli reliability roll rather than continuous dispersion: ordinary hits
// remain as accurate as the engine-created SubmunitionTargetDirection vector,
// while failed shots are unambiguous near misses across differently sized
// vehicle classes.
private _childConfig = configOf _child;
private _accuracyProbability = ((getNumber (_childConfig >> "bskulls_terminalAccuracyProbability")) max 0) min 1;
private _missOffsetMin = (getNumber (_childConfig >> "bskulls_terminalMissOffsetMin")) max 0;
private _missOffsetMax = (getNumber (_childConfig >> "bskulls_terminalMissOffsetMax")) max _missOffsetMin;
private _accuracyRoll = random 1;
private _accuracyOverrideValue = missionNamespace getVariable [
    "bskulls_titanTopAttackAccuracyOverride",
    ""
];
private _accuracyOverride = if (_accuracyOverrideValue isEqualType "") then {
    toLower _accuracyOverrideValue
} else {
    ""
};
private _plannedMiss = if (_accuracyOverride isEqualTo "miss") then {
    true
} else {
    if (_accuracyOverride isEqualTo "hit") then {
        false
    } else {
        _accuracyRoll >= _accuracyProbability
    }
};
if (_accuracyOverride in ["hit","miss"]) then {
    // A debug override applies to one terminal stage only.
    missionNamespace setVariable ["bskulls_titanTopAttackAccuracyOverride", ""];
};
private _accuracyOutcome = "nominal";
private _missOffset = 0;
private _missSide = 0;
private _missAimPointASL = [];
private _originalVelocity = +_velocity;

if (_plannedMiss) then {
    if ((count _targetPosASL) isEqualTo 3) then {
        private _toTarget = _targetPosASL vectorDiff _positionASL;
        private _horizontalDirection = [_toTarget select 0,_toTarget select 1,0];
        private _lateralDirection = if ((vectorMagnitude _horizontalDirection) > 0.01) then {
            vectorNormalized [
                -(_horizontalDirection select 1),
                _horizontalDirection select 0,
                0
            ]
        } else {
            private _azimuth = random 360;
            [sin _azimuth,cos _azimuth,0]
        };

        _missOffset = _missOffsetMin + random (_missOffsetMax - _missOffsetMin);
        _missSide = [-1,1] select (floor (random 2));
        _missAimPointASL = _targetPosASL vectorAdd (
            _lateralDirection vectorMultiply (_missOffset * _missSide)
        );

        private _speed = vectorMagnitude _velocity;
        private _missVector = _missAimPointASL vectorDiff _positionASL;
        if (_speed > 0.01 && {(vectorMagnitude _missVector) > 0.01}) then {
            _velocity = (vectorNormalized _missVector) vectorMultiply _speed;
            _child setVelocity _velocity;
            _accuracyOutcome = [
                "planned-near-miss",
                "planned-near-miss-forced"
            ] select (_accuracyOverride isEqualTo "miss");
        } else {
            _accuracyOutcome = "failure-roll-invalid-velocity";
        };
    } else {
        _accuracyOutcome = "failure-roll-no-target-position";
    };
};

private _accuracyDetails = [
    ["probability", _accuracyProbability],
    ["roll", _accuracyRoll],
    ["override", _accuracyOverride],
    ["outcome", _accuracyOutcome],
    ["missOffset", _missOffset],
    ["missSide", _missSide],
    ["missAimPointASL", _missAimPointASL],
    ["originalVelocity", _originalVelocity],
    ["appliedVelocity", _velocity]
];
_child setVariable ["bskulls_titanTopAttackAccuracy", _accuracyDetails, false];

if (!_debugEnabled) exitWith {true};

private _distance3D = -1;
private _horizontalDistance = -1;
private _altitude = -1;
private _elevation = -999;
private _diveAngle = -999;
private _trackError = -1;
if ((count _targetPosASL) isEqualTo 3) then {
    private _toTarget = _targetPosASL vectorDiff _positionASL;
    _distance3D = vectorMagnitude _toTarget;
    _horizontalDistance = sqrt (((_toTarget select 0) ^ 2) + ((_toTarget select 1) ^ 2));
    _altitude = (_positionASL select 2) - (_targetPosASL select 2);
    _elevation = if (_horizontalDistance < 0.01) then {90} else {atan (_altitude / _horizontalDistance)};

    private _horizontalSpeed = sqrt (((_velocity select 0) ^ 2) + ((_velocity select 1) ^ 2));
    _diveAngle = if (_horizontalSpeed < 0.01) then {
        if ((_velocity select 2) < 0) then {90} else {-90}
    } else {
        atan ((-(_velocity select 2)) / _horizontalSpeed)
    };
    if ((vectorMagnitude _velocity) > 0.01 && {_distance3D > 0.01}) then {
        private _trackCosine = (vectorNormalized _velocity) vectorCos (vectorNormalized _toTarget);
        _trackError = acos ((_trackCosine max -1) min 1);
    };
};

private _details = [
    ["parent", str _parent],
    ["parentClass", if (isNull _parent) then {""} else {typeOf _parent}],
    ["child", str _child],
    ["childClass", typeOf _child],
    ["childInitTrace", _childInitTraceId],
    ["target", str _target],
    ["targetClass", if (isNull _target) then {""} else {typeOf _target}],
    ["targetPosASL", _targetPosASL],
    ["positionASL", _positionASL],
    ["velocity", _velocity],
    ["accuracy", _accuracyDetails],
    ["distance3D", _distance3D],
    ["horizontalDistance", _horizontalDistance],
    ["altitude", _altitude],
    ["dapsElevation", _elevation],
    ["velocityDive", _diveAngle],
    ["trackError", _trackError]
];

[_parent, "STAGE_SEPARATION", _details, _traceId] call bskulls_fnc_titanTopAttackLog;
[_child, "TERMINAL_LINKED", _details, _traceId] call bskulls_fnc_titanTopAttackLog;

true
