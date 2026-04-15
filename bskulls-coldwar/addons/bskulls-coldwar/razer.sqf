if (local (_this select 0)) then {
    _onSpawn = {
        private _unit = _this select 0;
        sleep 0.2;
        _unit setNameSound 'Razer';
        _unit setSkill 1;
        _unit enableFatigue false;
        _unit setCombatBehaviour 'STEALTH';
        _unit setUnitRank 'COLONEL';
        _unit setName ['Phil Roberts','Phil','Roberts'];
        _unit setSpeaker 'male03eng';
        _unit setUnitTrait ['Engineer', true];
        _unit setUnitTrait ['ExplosiveSpecialist' , true];
        [_unit, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;
    };
    (_this select 0) spawn _onSpawn;
    (_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];
};
