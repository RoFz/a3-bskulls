// JACKSON init script
if (local(_this select 0)) then {
	_onSpawn = {
		_this = _this select 0;
		sleep 3;
        _this setVehicleVarName 'MAKAROVA';
        _this setName ['Tatyana Makarova', 'Tatyana', 'Makarova'];
        _this setNameSound 'Wardak';
        // _this setUnitRank 'CORPORAL';
        _this setSpeaker 'femalevoiceru';
        _this setPitch 1.0;
        _this setFace 'TCGM_Fem_Lynch';
        _this assignTeam 'RED';
		#include "\bskulls-modern\scripts\ALL.sqf"
	};
	_this spawn _onSpawn;
};