// VEHICLE CREW init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
		// _unit allowDamage false;
		// _unit setUnitRank 'CAPTAIN';
		_unit setUnitTrait ['Engineer', true];
		sleep 5;
		_unit stop true;
		#include "ALL-crew.sqf"
	};
	_this spawn _onSpawn;
};
