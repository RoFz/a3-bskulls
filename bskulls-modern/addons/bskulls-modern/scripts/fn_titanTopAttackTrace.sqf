/*
 * Sample one local top-attack projectile at meaningful range crossings.
 * The output distinguishes shallow carrier interception, failed separation,
 * incorrect terminal direction, target loss, and a normal roof impact.
 */

params [["_projectile", objNull, [objNull]]];

if (
    isNull _projectile
    || {!local _projectile}
    || {!(missionNamespace getVariable ["bskulls_titanTopAttackDebug", false])}
) exitWith {false};

uiSleep 0.01;

private _traceId = _projectile getVariable ["bskulls_titanTopAttackTraceId", "untracked"];
private _stage = _projectile getVariable ["bskulls_titanTopAttackStage", "unknown"];
private _thresholds = if (_stage isEqualTo "carrier") then {
    [1000,600,450,400,350,325,310,300,250,200,100,50,30]
} else {
    [310,300,250,200,150,100,75,50,30,15,5]
};
private _crossed = [];
private _start = diag_tickTime;
private _timeout = [2, 35] select (_stage isEqualTo "carrier");
private _samples = 0;
private _lastPosition = if (isNull _projectile) then {[]} else {getPosASL _projectile};
private _lastVelocity = if (isNull _projectile) then {[]} else {velocity _projectile};
private _lastMetrics = [];
private _target = objNull;
private _targetPosASL = [];
private _targetDamageBefore = -1;
private _lastGuidanceTarget = objNull;
private _guidanceTargetObserved = false;
private _lastGuidancePosASL = [];
private _accuracyDetails = _projectile getVariable ["bskulls_titanTopAttackAccuracy", []];

while {
    !isNull _projectile
    && {(diag_tickTime - _start) < _timeout}
    && {missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]}
} do {
    _samples = _samples + 1;

    private _configuredTarget = _projectile getVariable ["bskulls_titanTopAttackTarget", objNull];
    if (!isNull _configuredTarget && {_configuredTarget isNotEqualTo _target}) then {
        _target = _configuredTarget;
        _targetPosASL = getPosASL _target;
        if (_targetDamageBefore < 0) then {
            _targetDamageBefore = damage _target;
        };
        [
            _projectile,
            "INTENDED_TARGET",
            [
                ["stage", _stage],
                ["target", str _target],
                ["targetClass", typeOf _target],
                ["targetPosASL", _targetPosASL],
                ["targetDamage", _targetDamageBefore]
            ],
            _traceId
        ] call bskulls_fnc_titanTopAttackLog;
    };

    if (isNull _target) then {
        private _configuredTargetPos = _projectile getVariable ["bskulls_titanTopAttackTargetPosASL", []];
        if ((count _configuredTargetPos) isEqualTo 3) then {
            _targetPosASL = _configuredTargetPos;
        };
    } else {
        _targetPosASL = getPosASL _target;
    };

    if (_stage isEqualTo "carrier") then {
        private _guidanceTarget = missileTarget _projectile;
        if (!_guidanceTargetObserved || {_guidanceTarget isNotEqualTo _lastGuidanceTarget}) then {
            _guidanceTargetObserved = true;
            _lastGuidanceTarget = _guidanceTarget;
            [
                _projectile,
                "GUIDANCE_TARGET",
                [
                    ["target", str _guidanceTarget],
                    ["targetClass", if (isNull _guidanceTarget) then {""} else {typeOf _guidanceTarget}]
                ],
                _traceId
            ] call bskulls_fnc_titanTopAttackLog;
        };

        private _guidancePosATL = missileTargetPos _projectile;
        if ((vectorMagnitude _guidancePosATL) > 1) then {
            private _guidancePosASL = ATLToASL _guidancePosATL;
            if (
                _lastGuidancePosASL isEqualTo []
                || {_lastGuidancePosASL vectorDistance _guidancePosASL > 5}
            ) then {
                _lastGuidancePosASL = _guidancePosASL;
                [
                    _projectile,
                    "GUIDANCE_POSITION",
                    [
                        ["positionATL", _guidancePosATL],
                        ["positionASL", _guidancePosASL]
                    ],
                    _traceId
                ] call bskulls_fnc_titanTopAttackLog;
            };
        };
    };

    _lastPosition = getPosASL _projectile;
    _lastVelocity = velocity _projectile;

    if ((count _targetPosASL) isEqualTo 3) then {
        private _toTarget = _targetPosASL vectorDiff _lastPosition;
        private _distance3D = vectorMagnitude _toTarget;
        private _horizontalDistance = sqrt (((_toTarget select 0) ^ 2) + ((_toTarget select 1) ^ 2));
        private _altitude = (_lastPosition select 2) - (_targetPosASL select 2);
        private _elevation = if (_horizontalDistance < 0.01) then {90} else {atan (_altitude / _horizontalDistance)};
        private _horizontalSpeed = sqrt (((_lastVelocity select 0) ^ 2) + ((_lastVelocity select 1) ^ 2));
        private _diveAngle = if (_horizontalSpeed < 0.01) then {
            if ((_lastVelocity select 2) < 0) then {90} else {-90}
        } else {
            atan ((-(_lastVelocity select 2)) / _horizontalSpeed)
        };
        private _trackError = -1;
        if ((vectorMagnitude _lastVelocity) > 0.01 && {_distance3D > 0.01}) then {
            private _trackCosine = (vectorNormalized _lastVelocity) vectorCos (vectorNormalized _toTarget);
            _trackError = acos ((_trackCosine max -1) min 1);
        };

        _lastMetrics = [
            ["distance3D", _distance3D],
            ["horizontalDistance", _horizontalDistance],
            ["altitude", _altitude],
            ["dapsElevation", _elevation],
            ["velocityDive", _diveAngle],
            ["trackError", _trackError]
        ];

        {
            if (_distance3D <= _x && {!(_x in _crossed)}) then {
                _crossed pushBack _x;
                [
                    _projectile,
                    "RANGE_CROSSING",
                    [
                        ["stage", _stage],
                        ["threshold", _x],
                        ["positionASL", _lastPosition],
                        ["velocity", _lastVelocity],
                        ["target", str _target],
                        ["targetPosASL", _targetPosASL],
                        ["metrics", _lastMetrics],
                        ["aboveDapsAngle", _elevation > (missionNamespace getVariable ["dapsMaxAngle", 45])]
                    ],
                    _traceId
                ] call bskulls_fnc_titanTopAttackLog;
            };
        } forEach _thresholds;
    };

    uiSleep 0.01;
};

private _timedOut = !isNull _projectile;
private _separated = if (isNull _projectile) then {
    _traceId in (missionNamespace getVariable ["bskulls_titanTopAttackSeparatedTraces", []])
} else {
    _projectile getVariable ["bskulls_titanTopAttackSeparated", false]
};

uiSleep 0.1;
private _targetDamageAfter = if (isNull _target) then {-1} else {damage _target};
private _dapsState = if (isNull _target) then {
    []
} else {
    [
        ["type", _target getVariable ["dapsType", ""]],
        ["active", _target getVariable ["dapsActive", false]],
        ["ammo", _target getVariable ["dapsAmmo", -1]],
        ["ammoLeft", _target getVariable ["dapsAmmoL", -1]],
        ["ammoRight", _target getVariable ["dapsAmmoR", -1]]
    ]
};

[
    objNull,
    ["PROJECTILE_ENDED", "TRACE_TIMEOUT"] select _timedOut,
    [
        ["stage", _stage],
        ["accuracy", _accuracyDetails],
        ["elapsed", diag_tickTime - _start],
        ["samples", _samples],
        ["separated", _separated],
        ["lastPositionASL", _lastPosition],
        ["lastVelocity", _lastVelocity],
        ["lastMetrics", _lastMetrics],
        ["target", str _target],
        ["targetClass", if (isNull _target) then {""} else {typeOf _target}],
        ["targetDamageBefore", _targetDamageBefore],
        ["targetDamageAfter", _targetDamageAfter],
        ["targetDamageDelta", if (_targetDamageBefore < 0 || {_targetDamageAfter < 0}) then {-1} else {_targetDamageAfter - _targetDamageBefore}],
        ["daps", _dapsState]
    ],
    _traceId
] call bskulls_fnc_titanTopAttackLog;

true
