// EVERETT init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
        _unit setVehicleVarName 'EVERETT';
        _unit setName ['Frank Everett', 'Frank', 'Everett'];
        _unit setNameSound 'Everett';
        _unit setUnitRank 'CAPTAIN';
        _unit assignTeam 'GREEN';
		#include "../ALL.sqf"
	};
	(_this select 0) spawn _onSpawn;
};
