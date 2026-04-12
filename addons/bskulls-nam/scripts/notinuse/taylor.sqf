// TAYLOR init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
        _unit setVehicleVarName 'TAYLOR';
        _unit setName ['Chris Taylor', 'Chris', 'Taylor'];
        _unit setNameSound 'Taylor';
        _unit setUnitRank 'PRIVATE';
        _unit assignTeam 'GREEN';
		#include "../ALL.sqf"
	};
	(_this select 0) spawn _onSpawn;
};
