// HELO PILOT init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
		_unit allowDamage false;
		_unit setUnitRank 'MAJOR';
		#include "ALL-crew.sqf"
	};
	(_this select 0) spawn _onSpawn;
};
