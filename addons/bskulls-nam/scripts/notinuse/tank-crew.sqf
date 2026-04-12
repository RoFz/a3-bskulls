// TANK CREW init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
		_unit allowDamage false;
		_unit setUnitRank 'CAPTAIN';
		_unit setUnitTrait ['Engineer', true];
		#include "../ALL.sqf"
	};
	(_this select 0) spawn _onSpawn;
};
