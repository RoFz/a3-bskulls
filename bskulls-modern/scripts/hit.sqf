_unit = _this select 0; // object the event handler is assigned to
_source = _this select 1; // object that caused the damage – contains unit in case of collisions
_damage = _this select 2; // level of damage caused by the hit
_instigator = _this select 3; // person who pulled the trigger
_UnitName = name _unit;
_UnitCombatMode = combatMode _unit;
enemy_pos = _unit getHideFrom _instigator;
retreat_pos = [_instigator, 6, 18, 0.05, 0, 20, 0] call BIS_fnc_findSafePos;
if (damage _unit > 0.2) then {
	_unit setUnitPos "DOWN";
	sleep 10;
	if (damage _unit > 0.4) then {
		_unit doMove retreat_pos;
		sleep 15;
		_unit action ["HealSoldierSelf", _unit];
		sleep 30;
	};
};
_unit setUnitPos "AUTO";
