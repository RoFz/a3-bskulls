// HELO CREW init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
		[_unit, "CORPORAL"] call bskulls_fnc_applyUnitRank;
		_unit setUnitTrait ['Engineer', true];
		_unit enableIRLasers true;
		_unit setSkill 1;
		_unit enableFatigue false;
		if ("insignia" in selectionNames _unit) then { [_unit, "Black_Skulls"] call BIS_fnc_setUnitInsignia; };
	};
	_this spawn _onSpawn;
};
