/*
 * bskulls_fnc_aiDapsLauncherFired
 *
 * FiredBIS XEH handler for Hawkins. When his AI fires a Titan+ at an active,
 * charged DAPS vehicle, pause automatic reloading through the missile's flight
 * and then long enough to reassess the target instead of immediately feeding
 * the same APS bank another missile.
 * Firing remains enabled, so the unit can switch to and use its primary weapon.
 *
 * Mission overrides:
 *   BS_aiDapsLauncherCooldown = 15; // seconds; <= 0 disables the hold
 *   BS_aiDapsLauncherDebug = true;  // RPT start/release traces
 *
 * DAPS state follows its Scripts/APS and Scripts/Misc implementation:
 * dapsType, dapsActive, dapsAmmo or dapsAmmoL/dapsAmmoR. This remains an
 * optional compatibility path and does not make DAPS a required addon.
 *
 * References:
 * - community.bistudio.com/wiki/Arma_3:_Event_Handlers (Fired)
 * - community.bistudio.com/wiki/missileTarget
 * - community.bistudio.com/wiki/assignedTarget
 * - community.bistudio.com/wiki/enableReload
 * - github.com/CBATeam/CBA_A3/wiki/Extended-Event-Handlers-(new)
 */

#define BS_DAPS_LAUNCHER "B_PTbskull_Wea_law_01_titanat"
#define BS_DAPS_DEFAULT_COOLDOWN 15
#define BS_DAPS_POLL_INTERVAL 0.25
#define BS_DAPS_MAX_FLIGHT_HOLD 30
#define BS_DAPS_COOLDOWN_GENERATION "BS_aiDapsLauncherCooldownGeneration"

params [
    ["_unit", objNull, [objNull]],
    ["_weapon", "", [""]],
    ["_muzzle", "", [""]],
    ["_mode", "", [""]],
    ["_ammo", "", [""]],
    ["_magazine", "", [""]],
    ["_projectile", objNull, [objNull]]
];

if (
    isNull _unit
    || {!alive _unit}
    || {!local _unit}
    || {isPlayer _unit}
    || {_weapon isNotEqualTo BS_DAPS_LAUNCHER}
) exitWith { false };

private _cooldown = missionNamespace getVariable [
    "BS_aiDapsLauncherCooldown",
    BS_DAPS_DEFAULT_COOLDOWN
];
if !(_cooldown isEqualType 0) then {
    _cooldown = BS_DAPS_DEFAULT_COOLDOWN;
};
if (_cooldown <= 0) exitWith { false };

/*
 * Stop the empty launcher from auto-loading while its missile target becomes
 * available. Non-DAPS shots restore normal reload within half a second.
 */
_unit enableReload false;

private _generation = (
    _unit getVariable [BS_DAPS_COOLDOWN_GENERATION, 0]
) + 1;
_unit setVariable [BS_DAPS_COOLDOWN_GENERATION, _generation, false];

[_unit, _projectile, _cooldown, _generation] spawn {
    params ["_unit", "_projectile", "_cooldown", "_generation"];

    private _target = objNull;
    private _resolveDeadline = diag_tickTime + 0.5;

    waitUntil {
        sleep 0.01;

        if (!isNull _projectile) then {
            _target = missileTarget _projectile;
        };

        !isNull _target
        || {isNull _projectile}
        || {!alive _projectile}
        || {diag_tickTime >= _resolveDeadline}
        || {isNull _unit}
        || {!alive _unit}
        || {!local _unit}
        || {isPlayer _unit}
    };

    if (isNull _target && {!isNull _unit}) then {
        _target = assignedTarget _unit;
    };
    if (!isNull _target) then {
        _target = vehicle _target;
    };

    private _hasDapsCharges = {
        params ["_vehicle"];

        private _singleBank = _vehicle getVariable ["dapsAmmo", -1];
        if (_singleBank >= 0) exitWith { _singleBank > 0 };

        (
            (_vehicle getVariable ["dapsAmmoL", 0])
            + (_vehicle getVariable ["dapsAmmoR", 0])
        ) > 0
    };

    private _targetHasActiveDaps = (
        !isNull _target
        && {alive _target}
        && {(_target getVariable ["dapsType", ""]) isNotEqualTo ""}
        && {_target getVariable ["dapsActive", false]}
        && {isEngineOn _target}
        && {(crew _target) isNotEqualTo []}
        && {[_target] call _hasDapsCharges}
    );

    if (!_targetHasActiveDaps) exitWith {
        if (
            !isNull _unit
            && {local _unit}
            && {
                (_unit getVariable [BS_DAPS_COOLDOWN_GENERATION, -1])
                isEqualTo _generation
            }
        ) then {
            _unit enableReload true;
        };
    };

    private _debug = missionNamespace getVariable [
        "BS_aiDapsLauncherDebug",
        false
    ];
    private _flightDeadline = diag_tickTime + BS_DAPS_MAX_FLIGHT_HOLD;
    private _cooldownDeadline = -1;

    if (_debug) then {
        diag_log format [
            "[BSKULLS][DAPS AI] Holding Titan+ reload: unit=%1 target=%2 daps=%3 charges=%4/%5/%6 cooldown=%7",
            _unit,
            _target,
            _target getVariable ["dapsType", ""],
            _target getVariable ["dapsAmmo", -1],
            _target getVariable ["dapsAmmoL", -1],
            _target getVariable ["dapsAmmoR", -1],
            _cooldown
        ];
    };

    waitUntil {
        sleep BS_DAPS_POLL_INTERVAL;

        // Start the reassessment window when the missile hits, misses, or is
        // deleted by DAPS. The cap prevents a lost projectile from holding the
        // unit's automatic reload indefinitely.
        if (
            _cooldownDeadline < 0
            && {
                isNull _projectile
                || {!alive _projectile}
                || {diag_tickTime >= _flightDeadline}
            }
        ) then {
            _cooldownDeadline = diag_tickTime + _cooldown;
        };

        private _assignedTarget = objNull;
        if (!isNull _unit) then {
            _assignedTarget = assignedTarget _unit;
            if (!isNull _assignedTarget) then {
                _assignedTarget = vehicle _assignedTarget;
            };
        };

        isNull _unit
        || {!alive _unit}
        || {!local _unit}
        || {isPlayer _unit}
        || {
            _cooldownDeadline >= 0
            && {diag_tickTime >= _cooldownDeadline}
        }
        || {isNull _target}
        || {!alive _target}
        || {!(_target getVariable ["dapsActive", false])}
        || {!isEngineOn _target}
        || {(crew _target) isEqualTo []}
        || {!([_target] call _hasDapsCharges)}
        || {
            !isNull _assignedTarget
            && {_assignedTarget isNotEqualTo _target}
        }
    };

    if (
        !isNull _unit
        && {local _unit}
        && {
            (_unit getVariable [BS_DAPS_COOLDOWN_GENERATION, -1])
            isEqualTo _generation
        }
    ) then {
        _unit enableReload true;

        if (_debug) then {
            diag_log format [
                "[BSKULLS][DAPS AI] Released Titan+ reload: unit=%1 target=%2 alive=%3 active=%4 charges=%5/%6/%7 elapsed=%8",
                _unit,
                _target,
                alive _target,
                _target getVariable ["dapsActive", false],
                _target getVariable ["dapsAmmo", -1],
                _target getVariable ["dapsAmmoL", -1],
                _target getVariable ["dapsAmmoR", -1],
                _cooldownDeadline >= 0
                && {diag_tickTime >= _cooldownDeadline}
            ];
        };
    };
};

true
