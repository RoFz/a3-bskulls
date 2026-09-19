/*
 * Return live relative-motion and guidance data for an incoming missile.
 * Linear closest-approach values are recomputed by the caller because guided
 * missiles accelerate and turn; they are scheduling estimates, not impact
 * predictions.
 *
 * Return value:
 * [valid, range, closing speed, time to closest approach,
 *  closest-approach distance, missile speed, aircraft speed,
 *  engine state, lock state, flight state, guidance target]
 *
 * Ref: community.bistudio.com/wiki/velocity
 *      community.bistudio.com/wiki/vectorDotProduct
 *      community.bistudio.com/wiki/missileState
 *      community.bistudio.com/wiki/missileTarget
 */

params [
    ["_vehicle", objNull, [objNull]],
    ["_missile", objNull, [objNull]]
];

if (isNull _vehicle || {isNull _missile}) exitWith {
    [false, -1, 0, -1, -1, 0, 0, "", "", "", objNull]
};

private _vehiclePosition = getPosASL _vehicle;
private _missilePosition = getPosASL _missile;
private _vehicleVelocity = velocity _vehicle;
private _missileVelocity = velocity _missile;

private _relativePosition = _missilePosition vectorDiff _vehiclePosition;
private _relativeVelocity = _missileVelocity vectorDiff _vehicleVelocity;
private _range = vectorMagnitude _relativePosition;
private _relativeSpeedSquared = _relativeVelocity vectorDotProduct _relativeVelocity;
private _positionVelocityDot = _relativePosition vectorDotProduct _relativeVelocity;

private _closingSpeed = if (_range > 0.1) then {
    -(_positionVelocityDot / _range)
} else {
    0
};

private _timeToClosestApproach = if (_relativeSpeedSquared > 1) then {
    (-(_positionVelocityDot / _relativeSpeedSquared)) max 0
} else {
    -1
};

private _closestApproachDistance = _range;
if (_timeToClosestApproach >= 0) then {
    private _closestPosition = _relativePosition vectorAdd (
        _relativeVelocity vectorMultiply _timeToClosestApproach
    );
    _closestApproachDistance = vectorMagnitude _closestPosition;
};

private _state = missileState _missile;
_state params [
    ["_engineState", "", [""]],
    ["_lockState", "", [""]],
    ["_flightState", "", [""]]
];

[
    true,
    _range,
    _closingSpeed,
    _timeToClosestApproach,
    _closestApproachDistance,
    vectorMagnitude _missileVelocity,
    vectorMagnitude _vehicleVelocity,
    _engineState,
    _lockState,
    _flightState,
    missileTarget _missile
]
