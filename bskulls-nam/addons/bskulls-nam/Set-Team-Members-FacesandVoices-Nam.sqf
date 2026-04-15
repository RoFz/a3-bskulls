missionNamespace setVariable ["PAR_revive", 0];

_handle = 0 spawn { 
    {  
        _x setSkill 1;  
        _x enableFatigue false;  
        _x setCombatBehaviour 'STEALTH';  
        _x setUnitCombatMode 'GREEN';  
        _x setUnitTrait ['Medic', false];  
        _x setUnitTrait ['Engineer', false];  
        _x setUnitTrait ['ExplosiveSpecialist', false];  
        [_x, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia; 
    } forEach units player; 
    player execVM '\bskulls-nam\scripts\viper2.sqf'; 
    u2 execVM '\bskulls-nam\scripts\fox2.sqf'; 
    u3 execVM '\bskulls-nam\scripts\vega2.sqf';  
    u4 execVM '\bskulls-nam\scripts\mckendrick2.sqf';  
    u5 execVM '\bskulls-nam\scripts\jackson.sqf';
    u6 execVM '\bskulls-nam\scripts\frost.sqf';
    u7 execVM '\bskulls-nam\scripts\hawkins.sqf';
    u8 execVM '\bskulls-nam\scripts\sykes.sqf'; 
     private _fn_spawnAllAircraft = { 
        systemChat "Spawning CAS helicopter..."; 
        _randomHelo = selectRandom[ 
            "B_bskullfcnam_helo_cas_01"
        ]; 
        [4,west,[_randomHelo]]call dao_fnc_AddToVAM; 
        private _randomHeloName = [configFile >> "CfgVehicles" >> _randomHelo] call BIS_fnc_displayName; 
        systemChat format ["A %1 was spawned.", _randomHeloName];

        systemChat "Spawning CAS plane..."; 
        _randomPlane = selectRandom[ 
            "B_bskullfcnam_cas_01"
        ]; 
        [4,west,[_randomPlane]]call dao_fnc_AddToVAM; 
        private _randomPlaneName = [configFile >> "CfgVehicles" >> _randomPlane] call BIS_fnc_displayName; 
        systemChat format ["A %1 was spawned.", _randomPlaneName]; 

        missionNamespace setVariable ["DAOAircraftAlreadySpawned", true]; 
    };
     private _fn_spawnHelo = { 
        systemChat "Spawning CAS helicopter..."; 
        _randomHelo = selectRandom[ 
            "B_bskullfcnam_helo_cas_01"
        ]; 
        [4,west,[_randomHelo]]call dao_fnc_AddToVAM; 
        private _randomHeloName = [configFile >> "CfgVehicles" >> _randomHelo] call BIS_fnc_displayName; 
        systemChat format ["A %1 was spawned.", _randomHeloName];

        missionNamespace setVariable ["DAOAircraftAlreadySpawned", true]; 
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
            case (["weferlingen", worldName] call BIS_fnc_inString): _fn_spawnHelo; 
            default _fn_spawnAllAircraft; 
        }; 
    } else { 
        systemChat "DAO aircraft already spawned!"; 
    };
};
