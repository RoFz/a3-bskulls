if (local (_this select 0)) then {
    _onSpawn = {
        _this = _this select 0;
        sleep 0.2;
        _this setNameSound 'Razer';
        _this setSkill 1;
        _this enableFatigue false;
        _this setCombatBehaviour 'STEALTH';
        _this setUnitRank 'COLONEL';
        _this setName ['Phil Roberts','Phil','Roberts'];
        _this setSpeaker 'male03eng';
        _this setUnitTrait ['Engineer', true];
        _this setUnitTrait ['ExplosiveSpecialist' , true];
        [_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;
    };
    _this spawn _onSpawn;
    (_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];
};