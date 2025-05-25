// HELO PILOT init script
if (local(_this select 0)) then {
	_onSpawn = {
		_this = _this select 0;
		sleep 3;
		_this allowdamage false;
		_this setUnitRank 'CAPTAIN';
		#include "\bskulls-nam\scripts\ALL-crew.sqf"
	};
	_this spawn _onSpawn;
};