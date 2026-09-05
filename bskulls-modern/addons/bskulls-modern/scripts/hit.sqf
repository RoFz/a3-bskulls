// Hit EH entry — keep unscheduled; logic in bskulls_fnc_unitHitResponse.
params [["_unit", objNull], ["_source", objNull], ["_damage", 0], ["_instigator", objNull]];

// Named player units deliberately never use the AI self-treatment workflow.
if (isNull _unit || {isPlayer _unit}) exitWith {};

if (missionNamespace getVariable ["BS_woundDebug", false]) then {
    diag_log format [
        "BS Wound: Hit EH unit=%1 name=%2 eventDamage=%3 totalDamage=%4 local=%5 alive=%6 vehicle=%7 source=%8 instigator=%9",
        _unit,
        if (isNull _unit) then {""} else {name _unit},
        _damage,
        if (isNull _unit) then {-1} else {damage _unit},
        local _unit,
        alive _unit,
        if (isNull _unit) then {objNull} else {vehicle _unit},
        _source,
        _instigator
    ];
};

if (_damage < 0.01) exitWith {};
if (!local _unit) exitWith {};

[_unit, _source, _damage, _instigator] call bskulls_fnc_unitHitResponse;
