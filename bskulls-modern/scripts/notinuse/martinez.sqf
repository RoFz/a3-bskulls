// MARTINEZ init script
if (local(_this select 0)) then {
	_onSpawn = {
		_this = _this select 0;
		sleep 3;
        _this setVehicleVarName 'MARTINEZ';
        _this setName ['Oscar Martinez', 'Oscar', 'Martinez'];
        _this setNameSound 'Martinez';
        _this setUnitRank 'CORPORAL';
        _this assignTeam 'RED';
		#include "\bskulls-nam\scripts\ALL.sqf"
	};
	_this spawn _onSpawn;
};