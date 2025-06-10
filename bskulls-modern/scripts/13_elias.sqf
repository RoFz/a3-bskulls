// ELIAS init script
if (local(_this select 0)) then {
	_onSpawn = {
		_this = _this select 0;
		sleep 3;
        _this setVehicleVarName 'ELIAS';
        _this setName ['Elias Gordon', 'Elias', 'Gordon'];
        _this setNameSound 'Elias';
        // _this setUnitRank 'PRIVATE';
        _this assignTeam 'GREEN';
        _this setUnitTrait ['Engineer', true];
        _this setCombatBehaviour 'STEALTH';
        _this setUnitCombatMode 'GREEN';
		// #include "\bskulls-modern\scripts\ALL.sqf"
	};
	_this spawn _onSpawn;
};
