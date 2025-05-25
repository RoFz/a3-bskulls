// Liu GHOST init script
if (local(_this select 0)) then {
	_onSpawn = {
		_this = _this select 0;
		sleep 3;
        _this setVehicleVarName 'GHOST';
        _this setName ['Liu Guinu', 'Liu', 'Guinu'];
        _this setNameSound 'Ghost';
        // _this setUnitRank 'LIEUTENANT';
        _this setSpeaker 'male02chi';
        _this setPitch 1.22;
        _this setFace 'TCGM_Fem_Liu';
        _this assignTeam 'GREEN';
		#include "\bskulls-modern\scripts\ALL.sqf"
	};
	_this spawn _onSpawn;
};