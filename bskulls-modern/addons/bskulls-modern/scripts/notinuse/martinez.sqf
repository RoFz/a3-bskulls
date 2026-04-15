// MARTINEZ init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
        _unit setVehicleVarName 'MARTINEZ';
        _unit setName ['Oscar Martinez', 'Oscar', 'Martinez'];
        _unit setNameSound 'Martinez';
        _unit setUnitRank 'CORPORAL';
        _unit assignTeam 'RED';
		#include "../ALL.sqf"
	};
	_this spawn _onSpawn;
};
