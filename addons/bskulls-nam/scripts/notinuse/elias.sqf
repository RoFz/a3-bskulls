// ELIAS init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
        _unit setVehicleVarName 'ELIAS';
        _unit setName ['Elias Gordon', 'Elias', 'Gordon'];
        _unit setNameSound 'Elias';
        _unit setUnitRank 'PRIVATE';
        _unit assignTeam 'GREEN';
        _unit setUnitTrait ['Engineer', true];
		#include "../ALL.sqf"
	};
	(_this select 0) spawn _onSpawn;
};
