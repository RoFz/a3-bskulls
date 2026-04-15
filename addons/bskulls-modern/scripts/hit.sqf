params [["_unit", objNull], ["_source", objNull], ["_damage", 0], ["_instigator", objNull]];

// Filter: only react to enemy-caused damage
if (isNull _instigator || {side _instigator == side _unit}) exitWith {};

// Filter: skip trivial hits
if (_damage < 0.05) exitWith {};

// Re-entry guard: ignore while already reacting to a previous hit
if (_unit getVariable ["BS_hit_reacting", false]) exitWith {};
_unit setVariable ["BS_hit_reacting", true];

if (damage _unit > 0.2) then {
    _unit setUnitPos "DOWN";
    sleep 10;

    if (alive _unit && {damage _unit > 0.4}) then {
        // Find cover from shooter; fall back to safe distance if none found
        private _retreat_pos = _unit getHideFrom _instigator;
        if (_retreat_pos isEqualTo [0,0,0]) then {
            _retreat_pos = [_instigator, 20, 50, 1, 0, 20, 0] call BIS_fnc_findSafePos;
        };

        _unit doMove _retreat_pos;
        private _startTime = time;
        waitUntil { sleep 1; moveToCompleted _unit || !alive _unit || (time - _startTime > 30) };

        if (alive _unit && {"FirstAidKit" in items _unit}) then {
            _unit action ["HealSoldierSelf", _unit];
            sleep 30;
        } else {
            // No FAK — spawn a separate loop that calls for a medic every 3 minutes
            // while the unit is still alive, still damaged, and still without a FAK.
            // Uses HealthNeedMedicNow — a vanilla radio protocol sentence (Situation Report).
            [_unit] spawn {
                params ["_u"];
                while {alive _u && damage _u > 0.4 && !("FirstAidKit" in items _u)} do {
                    _u groupChat "MEDIC!";
                    _u groupRadio "HealthNeedMedicNow";
                    sleep 180;
                };
            };
        };
    };
};

if (alive _unit) then { _unit setUnitPos "AUTO"; };
_unit setVariable ["BS_hit_reacting", false];
