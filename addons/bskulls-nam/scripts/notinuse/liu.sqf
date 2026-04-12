// Liu GHOST init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
        _unit setVehicleVarName 'GHOST';
        _unit setName ['Liu Guinu', 'Liu', 'Guinu'];
        _unit setNameSound 'Ghost';
        _unit setUnitRank 'LIEUTENANT';
        _unit setSpeaker 'male02chi';
        _unit setPitch 1.22;
        _unit setFace 'TCGM_Fem_Liu';
        _unit assignTeam 'GREEN';
		#include "../ALL.sqf"
	};
	(_this select 0) spawn _onSpawn;
};
