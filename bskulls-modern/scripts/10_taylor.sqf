// TAYLOR init script
if (local(_this select 0)) then {
	_onSpawn = {
		_this = _this select 0;
		sleep 3;
        _this setVehicleVarName 'TAYLOR';
        _this setName ['Chris Taylor', 'Chris', 'Taylor'];
        _this setNameSound 'Taylor';
        // _this setUnitRank 'PRIVATE';
        _this assignTeam 'YELLOW';
        _this setCombatBehaviour 'STEALTH';
        _this setUnitCombatMode 'GREEN';
		// #include "\bskulls-modern\scripts\ALL.sqf"
	};
	_this spawn _onSpawn;
};
