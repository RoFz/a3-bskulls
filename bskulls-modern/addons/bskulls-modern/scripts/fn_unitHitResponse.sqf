/*
 * Crouch a wounded AI without replacing its movement, formation, or combat
 * orders. Once the immediate danger has passed, use a FAK or call for a medic.
 *
 * Stance rules: community.bistudio.com/wiki/unitPos and /wiki/setUnitPos.
 * Restore the previous scripted rule when releasing the wound crouch.
 */

#define BS_WOUND_HANDLE "BS_wound_handle"
#define BS_WOUND_LAST_HIT "BS_wound_lastHit"
#define BS_WOUND_EPISODE "BS_wound_episode"

#define BS_DMG_CROUCH 0.01
#define BS_DMG_TREAT 0.2
#define BS_QUIET_TIME 15
#define BS_DANGER_RADIUS 100
#define BS_SAFE_SUPPRESSION 0.05

params [
    ["_unit", objNull, [objNull]],
    ["_source", objNull, [objNull]],
    ["_eventDamage", 0, [0]],
    ["_instigator", objNull, [objNull]]
];

if (!local _unit || {!alive _unit} || {isPlayer _unit}) exitWith {};
if (_unit getVariable ["rev_downed", false]) exitWith {
    if (missionNamespace getVariable ["BS_woundDebug", false]) then {
        diag_log format [
            "BS Wound: SKIP_DRO_DOWNED unit=%1 name=%2 damage=%3",
            _unit,
            name _unit,
            damage _unit
        ];
    };
};

private _fnc_report = {
    params ["_speaker", "_message", "_state", "_episode"];
    if (missionNamespace getVariable ["BS_woundDebug", false]) then {
        diag_log format [
            "BS Wound: STATE episode=%1 state=%2 unit=%3 name=%4 damage=%5 vehicle=%6 message=%7",
            _episode,
            _state,
            _speaker,
            name _speaker,
            damage _speaker,
            vehicle _speaker,
            _message
        ];
    };

    // Keep useful status calls, but never broadcast the once-per-reason wait
    // diagnostics. Target only the unit's group instead of every client.
    private _chatStates = [
        "START",
        "SAFE",
        "SELF_HEAL_START",
        "SELF_HEAL_SUCCESS",
        "MEDIC_REQUESTED_NO_FAK"
    ];
    if (
        missionNamespace getVariable ["BS_woundChat", true]
        && {_state in _chatStates}
    ) then {
        [_speaker, _message] remoteExec ["groupChat", group _speaker];
    };
};

_unit setVariable [BS_WOUND_LAST_HIT, time, false];

private _onFoot = vehicle _unit isEqualTo _unit;
private _oldHandle = _unit getVariable [BS_WOUND_HANDLE, scriptNull];
if (_oldHandle isNotEqualTo scriptNull && {!scriptDone _oldHandle}) exitWith {
    if (missionNamespace getVariable ["BS_woundDebug", false]) then {
        diag_log format [
            "BS Wound: HIT_REFRESH episode=%1 unit=%2 name=%3 damage=%4 eventDamage=%5 source=%6 instigator=%7 lastHit=%8",
            _unit getVariable [BS_WOUND_EPISODE, 0],
            _unit,
            name _unit,
            damage _unit,
            _eventDamage,
            _source,
            _instigator,
            time
        ];
    };
};

// Crouch only once per episode. A hit during treatment must not reapply MIDDLE
// after the worker has already released its stance override.
private _stanceBeforeWound = "";
if (_onFoot && {damage _unit >= BS_DMG_CROUCH}) then {
    _stanceBeforeWound = toUpper (unitPos _unit);
    _unit setUnitPos "MIDDLE";
};

private _episode = (_unit getVariable [BS_WOUND_EPISODE, 0]) + 1;
_unit setVariable [BS_WOUND_EPISODE, _episode, false];

private _startedAt = time;
private _damageAtStart = damage _unit;
private _faksAtStart = {_x isEqualTo "FirstAidKit"} count (items _unit);
if (missionNamespace getVariable ["BS_woundDebug", false]) then {
    diag_log format [
        "BS Wound: TRIGGER episode=%1 unit=%2 name=%3 source=%4 instigator=%5 eventDamage=%6 totalDamage=%7 FAKs=%8 onFoot=%9",
        _episode,
        _unit,
        name _unit,
        _source,
        _instigator,
        _eventDamage,
        _damageAtStart,
        _faksAtStart,
        vehicle _unit isEqualTo _unit
    ];
};

private _openingMessages = [
    [
        "I've been hit! Staying in the vehicle.",
        "I've been shot! Crouching and staying in the fight."
    ],
    [
        "I've been hit badly! Staying in the vehicle; treatment will wait.",
        "I've been shot! Crouching — I'm badly hurt, but staying in the fight."
    ]
] select (damage _unit >= BS_DMG_TREAT);
private _openingMessage = _openingMessages select _onFoot;
[_unit, _openingMessage, "START", _episode] call _fnc_report;

private _handle = [
    _unit,
    _fnc_report,
    _episode,
    _startedAt,
    _damageAtStart,
    _faksAtStart,
    _stanceBeforeWound
] spawn {
    params [
        "_unit",
        "_fnc_report",
        "_episode",
        "_startedAt",
        "_damageAtStart",
        "_faksAtStart",
        "_stanceBeforeWound"
    ];

    private _fnc_dangerReason = {
        params ["_wounded"];

        if ((time - (_wounded getVariable [BS_WOUND_LAST_HIT, time])) < BS_QUIET_TIME) exitWith {
            "recent incoming fire"
        };
        if (getSuppression _wounded > BS_SAFE_SUPPRESSION) exitWith {
            "still suppressed"
        };

        private _enemy = _wounded findNearestEnemy _wounded;
        if (!isNull _enemy && {_wounded distance2D _enemy <= BS_DANGER_RADIUS}) exitWith {
            format ["known enemy within %1 m", BS_DANGER_RADIUS]
        };
        if (
            damage _wounded >= BS_DMG_TREAT
            && {vehicle _wounded isNotEqualTo _wounded}
        ) exitWith {
            "still inside the vehicle"
        };

        ""
    };

    private _outcome = "UNKNOWN";
    private _lastDangerReason = "";
    waitUntil {
        sleep 1;

        private _dangerReason = [_unit] call _fnc_dangerReason;
        if (
            alive _unit
            && {damage _unit >= BS_DMG_CROUCH}
            && {_dangerReason isNotEqualTo ""}
            && {_dangerReason isNotEqualTo _lastDangerReason}
        ) then {
            [
                _unit,
                format ["I'm wounded. Treatment delayed: %1.", _dangerReason],
                "WAIT_DANGER",
                _episode
            ] call _fnc_report;
            _lastDangerReason = _dangerReason;
        };

        !alive _unit
        || {!local _unit}
        || {isPlayer _unit}
        || {_unit getVariable ["rev_downed", false]}
        || {damage _unit < BS_DMG_CROUCH}
        || {_dangerReason isEqualTo ""}
    };

    // Release our crouch before any treatment/exit branch, including DRO revive
    // takeover. A downed unit is still alive and must not retain MIDDLE on revival.
    // Preserve a different stance rule installed by another script meanwhile.
    if (
        alive _unit
        && {local _unit}
        && {_stanceBeforeWound isNotEqualTo ""}
        && {toUpper (unitPos _unit) isEqualTo "MIDDLE"}
    ) then {
        _unit setUnitPos _stanceBeforeWound;
    };

    if (!alive _unit) then {
        _outcome = "UNIT_DIED";
    };
    if (alive _unit && {!local _unit}) then {
        _outcome = "LOCALITY_CHANGED";
    };
    if (alive _unit && {_unit getVariable ["rev_downed", false]}) then {
        _outcome = "DRO_REVIVE_TAKEOVER";
    };
    if (alive _unit && {isPlayer _unit}) then {
        _outcome = "BECAME_PLAYER_CONTROLLED";
    };

    if (
        alive _unit
        && {local _unit}
        && {!isPlayer _unit}
        && {!(_unit getVariable ["rev_downed", false])}
    ) then {
        if (damage _unit < BS_DMG_CROUCH) then {
            _outcome = "RECOVERED_EXTERNALLY";
            [
                _unit,
                "I'm patched up. Returning to normal.",
                _outcome,
                _episode
            ] call _fnc_report;
        } else {
            [_unit, "It's clear enough. Checking my wounds.", "SAFE", _episode] call _fnc_report;
        };

        if (damage _unit >= BS_DMG_TREAT) then {
            if ("FirstAidKit" in items _unit) then {
                private _damageBeforeTreatment = damage _unit;
                [
                    _unit,
                    "Applying a first aid kit.",
                    "SELF_HEAL_START",
                    _episode
                ] call _fnc_report;
                _unit action ["HealSoldierSelf", _unit];

                private _treatmentDeadline = time + 15;
                waitUntil {
                    sleep 0.5;
                    !alive _unit
                    || {isPlayer _unit}
                    || {_unit getVariable ["rev_downed", false]}
                    || {damage _unit < _damageBeforeTreatment}
                    || {time >= _treatmentDeadline}
                };

                if (!alive _unit) then {
                    _outcome = "UNIT_DIED_DURING_SELF_HEAL";
                } else {
                    if (_unit getVariable ["rev_downed", false]) then {
                        _outcome = "DRO_REVIVE_TAKEOVER";
                    } else {
                        if (isPlayer _unit) then {
                            _outcome = "BECAME_PLAYER_CONTROLLED";
                        } else {
                            if (damage _unit < _damageBeforeTreatment) then {
                                _outcome = "SELF_HEAL_SUCCESS";
                                [_unit, "First aid complete.", _outcome, _episode] call _fnc_report;
                            } else {
                                _outcome = "SELF_HEAL_NO_EFFECT_15S";
                                [
                                    _unit,
                                    "First aid produced no damage reduction after 15 seconds.",
                                    _outcome,
                                    _episode
                                ] call _fnc_report;
                            };
                        };
                    };
                };
            } else {
                _outcome = "MEDIC_REQUESTED_NO_FAK";
                [_unit, "No first aid kits! Medic!", _outcome, _episode] call _fnc_report;
                _unit groupRadio "HealthNeedMedicNow";
            };
        } else {
            if (damage _unit >= BS_DMG_CROUCH) then {
                _outcome = "BELOW_TREAT_THRESHOLD";
                [
                    _unit,
                    "It's superficial. No treatment needed.",
                    _outcome,
                    _episode
                ] call _fnc_report;
            };
        };
    };

    if (!isNull _unit) then {
        _unit setVariable [BS_WOUND_HANDLE, scriptNull, false];
    };

    if (missionNamespace getVariable ["BS_woundDebug", false]) then {
        private _damageAtEnd = if (isNull _unit) then {-1} else {damage _unit};
        private _faksAtEnd = if (isNull _unit) then {
            0
        } else {
            {_x isEqualTo "FirstAidKit"} count (items _unit)
        };
        diag_log format [
            "BS Wound: FINISH episode=%1 unit=%2 name=%3 outcome=%4 damageStart=%5 damageEnd=%6 FAKsStart=%7 FAKsEnd=%8 FAKsConsumed=%9 elapsed=%10 alive=%11 playerControlled=%12 unitPos=%13",
            _episode,
            _unit,
            if (isNull _unit) then {""} else {name _unit},
            _outcome,
            _damageAtStart,
            _damageAtEnd,
            _faksAtStart,
            _faksAtEnd,
            (_faksAtStart - _faksAtEnd) max 0,
            time - _startedAt,
            alive _unit,
            isPlayer _unit,
            if (isNull _unit) then {""} else {unitPos _unit}
        ];
    };
};

_unit setVariable [BS_WOUND_HANDLE, _handle, false];
