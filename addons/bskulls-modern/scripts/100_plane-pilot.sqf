// PLANE PILOT init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
		// _unit allowDamage false;
		// _unit setUnitRank 'COLONEL';
		_unit setUnitTrait ['Engineer', true];
		#include "ALL-crew.sqf"
	};
	_this spawn _onSpawn;
};
