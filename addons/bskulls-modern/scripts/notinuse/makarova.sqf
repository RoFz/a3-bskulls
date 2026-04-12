// JACKSON init script
if (local(_this select 0)) then {
	_onSpawn = {
		private _unit = _this select 0;
		sleep 3;
        _unit setVehicleVarName 'MAKAROVA';
        _unit setName ['Tatyana Makarova', 'Tatyana', 'Makarova'];
        _unit setNameSound 'Wardak';
        _unit setUnitRank 'CORPORAL';
        _unit setSpeaker 'femalevoiceru';
        _unit setPitch 1.0;
        _unit setFace 'TCGM_Fem_Lynch';
        _unit assignTeam 'RED';
		#include "../ALL.sqf"
	};
	_this spawn _onSpawn;
};
