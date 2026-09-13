/*
 * Observes movement and medical state for a local Black Skulls AI unit.
 *
 * The monitor is observational: it does not change damage, stance, fatigue,
 * orders, AI features, or DRO revive variables. Diagnostic records use the
 * [BSKULLS][WOUND-MOVE] prefix and are enabled by default. Disable them for a
 * mission with: BS_woundDiagnostics = false;
 *
 * Sources:
 * - community.bistudio.com/wiki/getAllHitPointsDamage
 * - community.bistudio.com/wiki/isForcedWalk
 * - community.bistudio.com/wiki/isWalking
 * - community.bistudio.com/wiki/getFatigue
 * - community.bistudio.com/wiki/expectedDestination
 */

#define BS_WOUND_HANDLE "BS_wound_handle"
#define BS_DIAGNOSTIC_HANDLE "BS_woundMovementDiagnosticsHandle"

params [["_unit", objNull, [objNull]]];

if (
    isNull _unit
    || {!local _unit}
    || {isPlayer _unit}
    || {!(missionNamespace getVariable ["BS_woundDiagnostics", true])}
) exitWith {scriptNull};

private _oldHandle = _unit getVariable [BS_DIAGNOSTIC_HANDLE, scriptNull];
if (_oldHandle isNotEqualTo scriptNull && {!scriptDone _oldHandle}) exitWith {
    _oldHandle
};

private _handle = [_unit] spawn {
    params ["_unit"];

    private _fnc_medicalState = {
        params ["_observedUnit"];

        private _woundHandle = _observedUnit getVariable [BS_WOUND_HANDLE, scriptNull];
        private _woundWorkerActive =
            _woundHandle isNotEqualTo scriptNull
            && {!scriptDone _woundHandle};

        [
            _observedUnit getVariable ["rev_downed", false],
            _observedUnit getVariable ["rev_beingAssisted", false],
            _observedUnit getVariable ["rev_beingRevived", false],
            _observedUnit getVariable ["rev_revivingUnit", false],
            _observedUnit getVariable ["rev_aiBeingTreated", false],
            _woundWorkerActive
        ]
    };

    private _fnc_report = {
        params ["_observedUnit", "_state", ["_transition", []]];

        if (
            isNull _observedUnit
            || {!(missionNamespace getVariable ["BS_woundDiagnostics", true])}
        ) exitWith {};

        private _observedGroup = group _observedUnit;
        private _observedLeader = leader _observedGroup;
        private _isLocal = local _observedUnit;
        private _medicalItems = items _observedUnit;
        private _woundHandle = _observedUnit getVariable [BS_WOUND_HANDLE, scriptNull];
        private _medicalState = [
            _observedUnit getVariable ["rev_downed", false],
            _observedUnit getVariable ["rev_beingAssisted", false],
            _observedUnit getVariable ["rev_beingRevived", false],
            _observedUnit getVariable ["rev_revivingUnit", false],
            _observedUnit getVariable ["rev_aiBeingTreated", false],
            _woundHandle isNotEqualTo scriptNull && {!scriptDone _woundHandle}
        ];

        diag_log format [
            "[BSKULLS][WOUND-MOVE] %1",
            [
                ["tick", diag_tickTime],
                ["state", _state],
                ["unit", str _observedUnit],
                ["name", name _observedUnit],
                ["class", typeOf _observedUnit],
                ["local", _isLocal],
                ["alive", alive _observedUnit],
                ["player", isPlayer _observedUnit],
                ["lifeState", lifeState _observedUnit],
                ["vehicle", str vehicle _observedUnit],
                ["transition", _transition],
                ["movement", [
                    ["speedKph", round ((speed _observedUnit) * 100) / 100],
                    ["velocityModelSpace", velocityModelSpace _observedUnit],
                    ["forcedWalk", isForcedWalk _observedUnit],
                    ["walkToggle", isWalking _observedUnit],
                    ["fatigue", getFatigue _observedUnit],
                    ["stamina", getStamina _observedUnit],
                    ["staminaEnabled", isStaminaEnabled _observedUnit],
                    ["load", load _observedUnit],
                    ["loadAbs", loadAbs _observedUnit],
                    ["canMove", canMove _observedUnit],
                    ["unitPos", unitPos _observedUnit],
                    ["stance", stance _observedUnit],
                    ["animation", animationState _observedUnit]
                ]],
                ["orders", [
                    ["currentCommand", currentCommand _observedUnit],
                    ["unitReady", unitReady _observedUnit],
                    ["expectedDestination", if (_isLocal) then {expectedDestination _observedUnit} else {[]}],
                    ["behaviour", behaviour _observedUnit],
                    ["combatBehaviour", combatBehaviour _observedUnit],
                    ["unitCombatMode", unitCombatMode _observedUnit],
                    ["group", str _observedGroup],
                    ["groupLeader", str _observedLeader],
                    ["leaderSpeedKph", if (isNull _observedLeader) then {-1} else {round ((speed _observedLeader) * 100) / 100}],
                    ["distanceToLeader", if (isNull _observedLeader) then {-1} else {_observedUnit distance2D _observedLeader}],
                    ["speedMode", speedMode _observedGroup],
                    ["formation", formation _observedGroup]
                ]],
                ["medical", [
                    ["damage", damage _observedUnit],
                    ["hitLegs", _observedUnit getHitPointDamage "HitLegs"],
                    ["hitpoints", getAllHitPointsDamage _observedUnit],
                    ["firstAidKits", {_x isEqualTo "FirstAidKit"} count _medicalItems],
                    ["hasMedikit", "Medikit" in _medicalItems],
                    ["state", _medicalState]
                ]]
            ]
        ];
    };

    private _lastMedicalState = [_unit] call _fnc_medicalState;
    private _everMedical = (_lastMedicalState findIf {_x}) >= 0;
    private _lastHeartbeat = diag_tickTime;
    private _slowSince = -1;
    private _lastSlowReport = -1000;

    [_unit, "MONITOR_STARTED", [[], _lastMedicalState]] call _fnc_report;

    while {
        alive _unit
        && {local _unit}
        && {!isPlayer _unit}
        && {missionNamespace getVariable ["BS_woundDiagnostics", true]}
    } do {
        sleep 0.5;

        private _medicalState = [_unit] call _fnc_medicalState;
        if (_medicalState isNotEqualTo _lastMedicalState) then {
            private _wasMedical = (_lastMedicalState findIf {_x}) >= 0;
            private _isMedical = (_medicalState findIf {_x}) >= 0;
            _everMedical = _everMedical || {_wasMedical} || {_isMedical};

            [_unit, "MEDICAL_STATE_CHANGED", [_lastMedicalState, _medicalState]] call _fnc_report;

            if (_wasMedical && {!_isMedical}) then {
                {
                    [_unit, _fnc_report, _x] spawn {
                        params ["_delayedUnit", "_report", "_delay"];
                        sleep _delay;
                        if (
                            alive _delayedUnit
                            && {local _delayedUnit}
                            && {!isPlayer _delayedUnit}
                            && {missionNamespace getVariable ["BS_woundDiagnostics", true]}
                        ) then {
                            [
                                _delayedUnit,
                                format ["POST_MEDICAL_PLUS_%1S", _delay]
                            ] call _report;
                        };
                    };
                } forEach [1, 5, 15, 30, 60, 120];
            };

            _lastMedicalState = _medicalState;
        };

        private _observedGroup = group _unit;
        private _observedLeader = leader _observedGroup;
        private _unitSpeed = abs (speed _unit);
        private _leaderSpeed = if (isNull _observedLeader) then {0} else {abs (speed _observedLeader)};
        private _distanceToLeader = if (isNull _observedLeader) then {0} else {_unit distance2D _observedLeader};
        private _playerLedGroup = ((units _observedGroup) findIf {isPlayer _x}) >= 0;
        private _slowFollower =
            _playerLedGroup
            && {_observedLeader isNotEqualTo _unit}
            && {vehicle _unit isEqualTo _unit}
            && {vehicle _observedLeader isEqualTo _observedLeader}
            && {_distanceToLeader >= 20}
            && {_leaderSpeed >= 8}
            && {_unitSpeed <= (_leaderSpeed * 0.65)}
            && {speedMode _observedGroup isNotEqualTo "LIMITED"};

        if (_slowFollower) then {
            if (_slowSince < 0) then {
                _slowSince = diag_tickTime;
            };
            if (
                diag_tickTime - _slowSince >= 3
                && {diag_tickTime - _lastSlowReport >= 10}
            ) then {
                [_unit, "SLOW_FOLLOWER"] call _fnc_report;
                _lastSlowReport = diag_tickTime;
            };
        } else {
            _slowSince = -1;
        };

        if (_everMedical && {diag_tickTime - _lastHeartbeat >= 60}) then {
            [_unit, "POST_MEDICAL_HEARTBEAT"] call _fnc_report;
            _lastHeartbeat = diag_tickTime;
        };
    };

    if (!isNull _unit) then {
        _unit setVariable [BS_DIAGNOSTIC_HANDLE, scriptNull, false];
    };
};

_unit setVariable [BS_DIAGNOSTIC_HANDLE, _handle, false];
_handle
