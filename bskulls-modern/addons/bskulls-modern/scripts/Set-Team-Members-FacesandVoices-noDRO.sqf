PAR_revive = 1;
PAR_ai_limit = 8;
PAR_only_ai_revive = true;

_handle = 0 spawn {
    {
        _x enableIRLasers true;
        _x setSkill 1;
        _x enableFatigue false;
        _x setCombatBehaviour 'STEALTH';
        _x setUnitCombatMode 'GREEN';
        [_x, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
    } forEach units player;

    // 01 viper
    player setName ['Stephen Falken','Stephen','Falken'];
    player setNameSound 'Viper';
    // player setUnitRank 'COLONEL';
    player setSpeaker 'male03eng';
    player setUnitTrait ['Medic', false];
    player setUnitTrait ['Engineer', true];
    player setUnitTrait ['ExplosiveSpecialist', true];

    private _fn_spawnOnlyHelos = {
        systemChat "Map without airstrip, spawning random CAS helo...";
        _randomHelo = selectRandom[
            "B_PTbskull_Veh_Helo_blackops_03",
            "B_PTbskull_Veh_Helo_blackops_04"
        ];
        [0,west,[_randomHelo]]call dao_fnc_AddToVAM;
        private _randomHeloName = [configFile >> "CfgVehicles" >> _randomHelo] call BIS_fnc_displayName;
        systemChat format ["A %1 was spawned.", _randomHeloName];
        missionNamespace setVariable ["DAOAircraftAlreadySpawned", true];
    };

    private _fn_spawnAllAircraft = {
        systemChat "Spawning random CAS aircraft...";
        _randomAircraft = selectRandom[
            "B_PTbskull_Veh_Plane_blackops_01",
            "B_PTbskull_Veh_Helo_blackops_03",
            "B_PTbskull_Veh_Helo_blackops_04",
            "B_T_UAV_03_dynamicLoadout_F"
        ];
        [0,west,[_randomAircraft]]call dao_fnc_AddToVAM;
        private _randomAircraftName = [configFile >> "CfgVehicles" >> _randomAircraft] call BIS_fnc_displayName;
        systemChat format ["A %1 was spawned.", _randomAircraftName];

        systemChat "Spawning transport aircraft...";
        _randomTransportAircraft = selectRandom[
            "B_PTbskull_Veh_Helo_blackops_01",
            "B_PTbskull_Veh_Helo_blackops_02"
        ];
        [0,west,[_randomTransportAircraft]]call dao_fnc_AddToVAM;
        private _randomTransportAircraft = [configFile >> "CfgVehicles" >> _randomTransportAircraft] call BIS_fnc_displayName;
        systemChat format ["A %1 was spawned.", _randomTransportAircraft];

        missionNamespace setVariable ["DAOAircraftAlreadySpawned", true];
    };

    private _fn_spawnUAV = {
        systemChat "Spawning random UAV...";
        _randomUAV = selectRandom[
            "B_PTbskull_Veh_Drone_blackops_04",
            "B_PTbskull_Veh_Drone_blackops_01"
        ];
        [0,west,[_randomUAV]]call dao_fnc_AddToVAM;
        private _randomUAVName = [configFile >> "CfgVehicles" >> _randomUAV] call BIS_fnc_displayName;
        systemChat format ["A %1 was spawned.", _randomUAVName];
        missionNamespace setVariable ["DAOUAVAlreadySpawned", true];
    };

    private _fn_spawnMQ12 = {
        systemChat "Map without airstrip, spawning a MQ-12...";
        _MQ12 = "B_T_UAV_03_dynamicLoadout_F";
        [0,west,[_MQ12]]call dao_fnc_AddToVAM;
        private _MQ12_name = [configFile >> "CfgVehicles" >> _MQ12] call BIS_fnc_displayName;
        systemChat format ["A %1 was spawned.", _MQ12_name];
        missionNamespace setVariable ["DAOUAVAlreadySpawned", true];
    };

    if (isNil "DAOAircraftAlreadySpawned") then
    {
        missionNamespace setVariable ["DAOAircraftAlreadySpawned", false];
        waitUntil{
            !(isNil "daoReady")
        };
        waitUntil{
            daoReady
        };
        sleep 5;
        switch true do
        {
            case (["weferlingen", worldName] call BIS_fnc_inString): _fn_spawnOnlyHelos;
            default _fn_spawnAllAircraft;
        };
    } else {
        systemChat "DAO aircraft already spawned!";
    };

    if (isNil "DAOUAVAlreadySpawned") then
    {
        missionNamespace setVariable ["DAOUAVAlreadySpawned", false];
        waitUntil{
            !(isNil "daoReady")
        };
        waitUntil{
            daoReady
        };
        sleep 5;
        switch true do
        {
            case (["weferlingen", worldName] call BIS_fnc_inString): _fn_spawnMQ12;
            default _fn_spawnUAV;
        };
    } else {
        systemChat "DAO UAV already spawned!";
    };

};
