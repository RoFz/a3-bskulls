_handle = 0 spawn {
    {
        _x enableIRLasers true;
        _x setSkill 1;
        _x enableFatigue false;
        _x setUnitTrait ['Medic', false];
        _x setUnitTrait ['Engineer', false];
        _x setUnitTrait ['ExplosiveSpecialist', false];
        _x setCombatBehaviour 'STEALTH';
        _x setUnitCombatMode 'GREEN';
        [_x, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
    } forEach units player;
    // 01 viper
    player setName ['Stephen Falken','Stephen','Falken'];
    player setNameSound 'Viper';
    player setUnitRank 'COLONEL';
    player setSpeaker 'male03eng';
    player setUnitTrait ['Engineer', true];
    player setUnitTrait ['ExplosiveSpecialist', true];
    // 02 fox
    u2 setVariable ["BIS_enableRandomization", false];
    u2 setName ['Amanda Fox','Amanda','Fox'];
    u2 setNameSound 'Fox';
    u2 setUnitRank 'PRIVATE';
    u2 setSpeaker 'rhs_Female01ENG';
    u2 setPitch 0.95;
    u2 setFace 'TCGM_Fem_Stone';
    u2 assignTeam 'BLUE';
    u2 setUnitTrait ['Medic', true];
    // 03 vega
    u3 setName ['Vince Vega','Vince','Vega'];
    u3 setNameSound 'Vega';
    u3 setUnitRank 'PRIVATE';
    u3 assignTeam 'BLUE';
    // 04 mckendrick
    u4 setName ['Greg McKendrick','Greg','McKendrick'];
    u4 setNameSound 'McKendrick';
    u4 setUnitRank 'PRIVATE';
    u4 assignTeam 'BLUE';
    u4 setUnitTrait ['Engineer', true];
    u4 setUnitTrait ['ExplosiveSpecialist', true];
    u4 setSpeaker 'male01engb';
    // 05 jackson
    u5 setVariable ["BIS_enableRandomization", false];
    u5 setName ['Jennifer Jackson','Jennifer','Jackson'];
    u5 setNameSound 'Jackson';
    u5 setUnitRank 'PRIVATE';
    u5 setSpeaker 'rhs_Female01ENG';
    u5 setPitch 1.1;
    u5 setFace 'TCGM_Fem_Fox';
    u5 assignTeam 'RED';
    u5 setUnitTrait ['Medic', true];
    // 06 frost
    u6 setName ['Patrick Frost','Patrick','Frost'];
    u6 setNameSound 'Frost';
    u6 setUnitRank 'PRIVATE';
    u6 assignTeam 'RED';
    // 07 hawkins
    u7 setName ['Kendall Hawkins','Kendall','Hawkins'];
    u7 setNameSound 'Hawkins';
    u7 setUnitRank 'PRIVATE';
    u7 assignTeam 'RED';
    // 08 sykes
    u8 setVariable ["BIS_enableRandomization", false];
    u8 setName ['Martha Sykes', 'Martha', 'Sykes'];
    u8 setNameSound 'Sykes';
    u8 setUnitRank 'PRIVATE';
    u8 setSpeaker 'rhs_Female01ENG';
    u8 setPitch 0.9;
    u8 setFace 'TCGM_Fem_Gonzalez';
    u8 assignTeam 'RED';
    u8 setUnitTrait ['Engineer', true];
    u8 setUnitTrait ['UAVHacker', true];
    // 09 everett
    u9 setName ['Frank Everett','Frank','Everett'];
    u9 setNameSound 'Everett';
    u9 setUnitRank 'PRIVATE';
    u9 assignTeam 'YELLOW';
    // 10 taylor
    u10 setName ['Chris Taylor','Chris','Taylor'];
    u10 setNameSound 'Taylor';
    u10 setUnitRank 'PRIVATE';
    u10 assignTeam 'YELLOW';
    // 11 liu
    u11 setName ['Liu Guinu', 'Liu', 'Guinu'];
    u11 setNameSound 'Ghost';
    u11 setUnitRank 'PRIVATE';
    u11 setSpeaker 'male02chi';
    u11 setPitch 1.22;
    u11 setFace 'TCGM_Fem_Liu';
    u11 assignTeam 'YELLOW';
    // 12 makarova
    u12 setVariable ["BIS_enableRandomization", false];
    u12 setName ['Tatyana Makarova', 'Tatyana', 'Makarova'];
    u12 setNameSound 'Wardak';
    u12 setUnitRank 'PRIVATE';
    u12 setSpeaker 'femalevoiceru';
    u12 setPitch 1.0;
    u12 setFace 'TCGM_Fem_Lynch';
    u12 assignTeam 'YELLOW';
    // 13 elias
    u13 setName ['Elias Gordon','Elias','Gordon'];
    u13 setNameSound 'Elias';
    u13 setUnitRank 'PRIVATE';
    u13 assignTeam 'YELLOW';
    u13 setUnitTrait ['UAVHacker', true];
    // 14 martinez
    u14 setName ['Oscar Martinez','Oscar','Martinez'];
    u14 setNameSound 'Martinez';
    u14 setUnitRank 'PRIVATE';
    u14 assignTeam 'YELLOW';

    _pos = [player, 1, 150, 3, 0, 20, 0] call BIS_fnc_findSafePos;
    if ((isNil "lobbycomplete") || (lobbycomplete == 0)) then
    {
        systemChat "This must be executed after the mission has started!"
    } else {
        private _myv1 = vehicle UGV;
        if (isNil "_myv1") then
        {
            UGV = createVehicle ["B_PTbskull_Veh_Drone_blackops_02",_pos, [], 30, "NONE"];
            createVehicleCrew UGV;
        } else {
            systemChat "UGV already spawned!";
        };
        private _myv2 = vehicle RADAR;
        if (isNil "_myv2") then
        {
            RADAR = createVehicle ["B_PTbskull_Veh_Radar_blackops_01",_pos, [], 60, "NONE"];
            createVehicleCrew RADAR;
        } else {
            systemChat "RADAR already spawned!";
        };
        private _myv3 = vehicle SAM;
        if (isNil "_myv3") then
        {
            SAM = createVehicle ["B_PTbskull_Veh_SAM_blackops_01",_pos, [], 80, "NONE"];
            createVehicleCrew SAM;
        } else {
            systemChat "SAM already spawned!";
        };
        private _myv4 = vehicle HemmtAmmo;
        if (isNil "_myv4") then
        {
            HemmtAmmo = createVehicle ["B_PTbskull_Veh_Truck_blackops_02",_pos, [], 50, "NONE"];
            (group player) createVehicleCrew HemmtAmmo;
        } else {
            systemChat "Ammo truck already spawned!";
        };
        private _myv5 = vehicle HemmtFuel;
        if (isNil "_myv5") then
        {
            HemmtFuel = createVehicle ["B_PTbskull_Veh_Truck_blackops_03",_pos, [], 55, "NONE"];
            (group player) createVehicleCrew HemmtFuel;
        } else {
            systemChat "Fuel truck already spawned!";
        };
    };

    // missionNamespace setVariable ["UAVRefitTime", "10"];

    private _fn_spawnOnlyHelos = {
        systemChat "Map without airstrip, spawning random helo...";
        _randomHelo = selectRandom[
            "B_PTbskull_Veh_Helo_blackops_03",
            "B_PTbskull_Veh_Helo_blackops_04",
            "B_T_UAV_03_dynamicLoadout_F"
        ];
        [0,WEST,[_randomHelo]]call dao_fnc_AddToVAM;
        private _randomHeloName = [configFile >> "CfgVehicles" >> _randomHelo] call BIS_fnc_displayName;
        systemChat format ["A %1 was spawned.", _randomHeloName];
        systemChat "Spawning transport aircraft...";
        _randomTransportAircraft = selectRandom[
            "B_PTbskull_Veh_Helo_blackops_01",
            "B_PTbskull_Veh_Helo_blackops_02"
        ];
        [0,WEST,[_randomTransportAircraft]]call dao_fnc_AddToVAM;
        private _randomTransportAircraft = [configFile >> "CfgVehicles" >> _randomTransportAircraft] call BIS_fnc_displayName;
        systemChat format ["A %1 was spawned.", _randomTransportAircraft];
        missionNamespace setVariable ["DAOAircraftAlreadySpawned", true];
    };
    private _fn_spawnAllAircraft = {
        systemChat "Spawning random aircraft...";
        _randomAircraft = selectRandom[
            "B_PTbskull_Veh_Plane_blackops_01",
            "B_PTbskull_Veh_Helo_blackops_03",
            "B_PTbskull_Veh_Helo_blackops_04",
            "B_T_UAV_03_dynamicLoadout_F"
        ];
        [0,WEST,[_randomAircraft]]call dao_fnc_AddToVAM;
        private _randomAircraftName = [configFile >> "CfgVehicles" >> _randomAircraft] call BIS_fnc_displayName;
        systemChat format ["A %1 was spawned.", _randomAircraftName];
        systemChat "Spawning transport aircraft...";
        _randomTransportAircraft = selectRandom[
            "B_PTbskull_Veh_Helo_blackops_01",
            "B_PTbskull_Veh_Helo_blackops_02"
        ];
        [0,WEST,[_randomTransportAircraft]]call dao_fnc_AddToVAM;
        private _randomTransportAircraft = [configFile >> "CfgVehicles" >> _randomTransportAircraft] call BIS_fnc_displayName;
        systemChat format ["A %1 was spawned.", _randomTransportAircraft];
        missionNamespace setVariable ["DAOAircraftAlreadySpawned", true];
    };

    if (isNil "DAOAircraftAlreadySpawned") then
    {
        missionNamespace setVariable ["DAOAircraftAlreadySpawned", false];
        waitUntil{
            !(isNil"daoReady")
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
};
