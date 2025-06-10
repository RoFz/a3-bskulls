// EVERETT init script
if (local(_this select 0)) then {
	_onSpawn = {
		_this = _this select 0;
		sleep 3;
        _this setVehicleVarName 'EVERETT';
        _this setName ['Frank Everett', 'Frank', 'Everett'];
        _this setNameSound 'Everett';
        // _this setUnitRank 'LIEUTENANT';
        _this assignTeam 'YELLOW';
        _this setCombatBehaviour 'STEALTH';
        _this setUnitCombatMode 'GREEN';
		// #include "\bskulls-modern\scripts\ALL.sqf"
	};
	_this spawn _onSpawn;
};
