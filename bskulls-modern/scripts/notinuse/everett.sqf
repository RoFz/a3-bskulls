// EVERETT init script
if (local(_this select 0)) then {
	_onSpawn = {
		_this = _this select 0;
		sleep 3;
        _this setVehicleVarName 'EVERETT';
        _this setName ['Frank Everett', 'Frank', 'Everett'];
        _this setNameSound 'Everett';
        _this setUnitRank 'CAPTAIN';
        _this assignTeam 'GREEN';
		#include "\bskulls-nam\scripts\ALL.sqf"
	};
	_this spawn _onSpawn;
};