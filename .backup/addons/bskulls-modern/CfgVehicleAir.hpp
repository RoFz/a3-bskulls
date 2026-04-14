    // Vehicles

    class B_PTbskull_Veh_Plane_blackops_01 : B_Plane_CAS_01_dynamicLoadout_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "A-164 Wipeout (CAS) (1c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Plane_Pilot_blackops_01";
        availableForSupportTypes[] = {"CAS_Bombing"};
        hiddenSelections[] += { "insignia" };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; _unit setVehicleReportOwnPosition true; _unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_UAV_02_dynamicLoadout_F;
    class B_UAV_02_dynamicLoadout_F_OCimport_01 : B_UAV_02_dynamicLoadout_F { scope = 0; class Turrets; class Components;};
    class B_UAV_02_dynamicLoadout_F_OCimport_02 : B_UAV_02_dynamicLoadout_F_OCimport_01
    {
       
        class Components : Components {
            class TransportPylonsComponent;
        };
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };
    class B_PTbskull_Veh_Drone_blackops_01 : B_UAV_02_dynamicLoadout_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "MQ-4A Greyhawk";
        side = 1;
        faction = "bskull_fc_mo";
        reportOwnPosition = 1;
        receiveRemoteTargets = 1;
        reportRemoteTargets = 1;
        crew = "B_PTbskull_Veh_UAV_AI_AIR";
        // hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret {
                gunnerType = "";
                class OpticsIn
                {
                    class Wide // 0.5x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.5;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.5;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.5;
                        opticsDisplayName = "W";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class Medium // 2.5x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.1;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.1;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.1;
                        opticsDisplayName = "M";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class Short // ?x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.0357;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.0357;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.0357;
                        opticsDisplayName = "S";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class Narrow // 8.7x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.0286;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.0286;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.0286;
                        opticsDisplayName = "N";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class SuperNarrow // ??x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.01;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.01;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.01;
                        opticsDisplayName = "SN";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class UltraNarrow // 250x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.001;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.001;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.001;
                        opticsDisplayName = "UN";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                };
            };
        };
        class Components : Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class pylons {
                    class pylons1 {
                        attachment = "PylonRack_4Rnd_LG_scalpel";
                        hardpoints[] = {"B_BOMB_PYLON","B_MISSILE_PYLON"};
                        maxweight = 345;
                        priority = 5;
                        turret[] = {0};
                        UIposition[] = {0.33,0.4};
                    };
                    class pylons2 : pylons1 {
                        mirroredMissilePos = 1;
                        UIposition[] = {0.33,0.15};
                    };
                };
            };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
            // init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit setVehicleReportOwnPosition true; _unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true;_unit setVariable['daoExclude',TRUE,TRUE]; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Drone_blackops_02 : B_UGV_01_rcws_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "UGV Stomper RCWS (1p)";
        side = 1;
        faction = "bskull_fc_mo";
        reportOwnPosition = 1;
        receiveRemoteTargets = 1;
        reportRemoteTargets = 1;
        crew = "B_PTbskull_Veh_UAV_AI_GROUND";
        hiddenSelections[] += { "insignia" };
        armor = 300;
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = ""; };
            class CargoTurret_01 : CargoTurret_01 { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [_unit, ['Olive', 1], true] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_UAV_01_F;
    class B_UAV_01_F_OCimport_01 : B_UAV_01_F { scope = 0; class Turrets;};
    class B_UAV_01_F_OCimport_02 : B_UAV_01_F_OCimport_01
    {
       
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };
    class B_PTbskull_Veh_Drone_blackops_03 : B_UAV_01_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "AR-2+ Darter";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_UAV_AI_AIR";
        maxSpeed = 180; // 100
        typicalCargo[] = {"B_PTbskull_Veh_UAV_AI_AIR"};
        class Turrets : Turrets {
            class MainTurret : MainTurret {
                gunnerType = "";
                class OpticsIn {
                    class Wide // 0.5x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.5;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.5;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.5;
                        opticsDisplayName = "W";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class Medium // 2.5x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.1;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.1;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.1;
                        opticsDisplayName = "M";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class Short // ?x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.0357;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.0357;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.0357;
                        opticsDisplayName = "S";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class Narrow // 8.7x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.0286;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.0286;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.0286;
                        opticsDisplayName = "N";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class SuperNarrow // ??x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.01;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.01;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.01;
                        opticsDisplayName = "SN";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class UltraNarrow // 250x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.001;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.001;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.001;
                        opticsDisplayName = "UN";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                };
            };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit setVariable['daoExclude',TRUE,TRUE]; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_UAV_05_F;
    class B_UAV_05_F_OCimport_01 : B_UAV_05_F { scope = 0; class Turrets; class Components;};
    class B_UAV_05_F_OCimport_02 : B_UAV_05_F_OCimport_01
    {
       
        class Components : Components {
            class TransportPylonsComponent;
        };
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };
    class B_PTbskull_Veh_Drone_blackops_04 : B_UAV_05_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "UCAV Sentinel";
        side = 1;
        faction = "bskull_fc_mo";
        reportOwnPosition = 1;
        receiveRemoteTargets = 1;
        reportRemoteTargets = 1;
        crew = "B_PTbskull_Veh_UAV_AI_AIR";
        // hiddenSelections[] += { "insignia" };
        class Turrets : Turrets {
            class MainTurret : MainTurret {
                gunnerType = "";
                class OpticsIn {
                    class Wide // 0.5x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.5;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.5;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.5;
                        opticsDisplayName = "W";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class Medium // 2.5x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.1;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.1;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.1;
                        opticsDisplayName = "M";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class Short // ?x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.0357;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.0357;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.0357;
                        opticsDisplayName = "S";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class Narrow // 8.7x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.0286;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.0286;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.0286;
                        opticsDisplayName = "N";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class SuperNarrow // ??x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.01;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.01;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.01;
                        opticsDisplayName = "SN";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                    class UltraNarrow // 250x
                    {
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                        initAngleX = 0;
                        initAngleY = 0;
                        initFov = 0.001;
                        maxAngleX = 30;
                        maxAngleY = 100;
                        maxFov = 0.001;
                        minAngleX = -30;
                        minAngleY = -100;
                        minFov = 0.001;
                        opticsDisplayName = "UN";
                        thermalMode[] = {0,1};
                        visionMode[] = {"Normal","NVG","Ti"};
                    };
                };
            };
        };
        class Components : Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class pylons {
                    class pylon1 {
                        attachment = "PylonRack_Bomb_GBU12_x2"; // PylonMissile_Missile_AGM_02_x2, PylonMissile_Bomb_GBU12_x1, PylonRack_Bomb_SDB_x4 // non-std: PylonRack_2Rnd_BombCluster_01_F, PylonRack_4Rnd_LG_scalpel, PylonRack_Bomb_GBU12_x2
                        bay = 2;
                        hardpoints[] = {"B_GBU12","B_AGM65_DUAL","B_HARM_INT","B_SDB_QUAD_RAIL"};
                        maxweight = 1500;
                        priority = 1;
                        turret[] = {0};
                        UIposition[] = {0.5,0.25};
                    };
                    class pylon2 : pylon1 {
                        bay = 1;
                        mirroredMissilePos = 1;
                        UIposition[] = {0.15,0.25};
                    };
                };
            };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [ _unit, ['DarkGreyCamo',1], ['wing_fold_l',0]] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;}; _this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Helo_blackops_01 : B_Heli_Transport_03_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "CH-67 Huron (Miniguns) (4c16p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        availableForSupportTypes[] = {"Drop","Transport"};
        class Turrets : Turrets
        {
            class CopilotTurret : CopilotTurret { gunnerType = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01"; };
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Unit_Helo_Crew_blackops_01"; };
            class RightDoorGun : RightDoorGun { gunnerType = "B_PTbskull_Veh_Unit_Helo_Crew_blackops_01"; };
            class CargoTurret_01 : CargoTurret_01 { gunnerType = ""; };
            class CargoTurret_02 : CargoTurret_02 { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS_HELO};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [_unit,['Black',1], true] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
            // init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [_unit,['Black',1], true] call BIS_fnc_initVehicle; _unit setVariable['daoExclude',TRUE,TRUE]; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Helo_blackops_02 : B_Heli_Light_01_F_OCimport_02 {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "MH-9 Hummingbird (1c7p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        availableForSupportTypes[] = {"Drop","Transport"};
        class Turrets : Turrets {
            class CopilotTurret : CopilotTurret { gunnerType = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01"; dontCreateAI = 1; };
            class CargoTurret_01 : CargoTurret_01 { gunnerType = ""; };
            class CargoTurret_02 : CargoTurret_02 { gunnerType = ""; };
            class CargoTurret_03 : CargoTurret_03 { gunnerType = ""; };
            class CargoTurret_04 : CargoTurret_04 { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [ _unit, nil, ['AddBenches',1,'AddTread',1,'AddBackseats',1,'AddHoldingFrame',1,'AddTread_Short',0]] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Helo_blackops_03 : B_Heli_Attack_01_dynamicLoadout_F_OCimport_02 {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "AH-99 Blackfoot (2c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        availableForSupportTypes[] = {"CAS_Bombing"};
        maximumLoad = 50000;
        class Turrets : Turrets {
            class MainTurret : MainTurret { gunnerType = ""; };
        };
        class Components : Components {
                class TransportPylonsComponent : TransportPylonsComponent {
                    class pylons {
                        class PylonLeft1 {
                            attachment = "PylonRack_12Rnd_PG_missiles";
                            bay = 1;
                            hardpoints[] = {"SCALPEL_1RND","B_ASRAAM","DAR","DAGR"};
                            priority = 5;
                            turret[] = {0};
                            UIposition[] = {0.06,0.4};
                        };
                        class PylonLeft2 {
                            attachment = "PylonMissile_1Rnd_LG_scalpel";
                            bay = 1;
                            hardpoints[] = {"SCALPEL_1RND","B_ASRAAM"};
                            priority = 4;
                            turret[] = {0};
                            UIposition[] = {0.08,0.35};
                        };
                        class PylonLeft3 {
                            attachment = "PylonRack_12Rnd_missiles";
                            bay = 1;
                            hardpoints[] = {"SCALPEL_1RND","B_ASRAAM","DAR","DAGR"};
                            priority = 3;
                            turret[] = {0};
                            UIposition[] = {0.1,0.3};
                        };
                        class PylonRight1 : PylonLeft1 {
                            mirroredMissilePos = 1;
                            UIposition[] = {0.64,0.4};
                        };
                        class PylonRight2 : PylonLeft2 {
                            mirroredMissilePos = 2;
                            UIposition[] = {0.62,0.35};
                        };
                        class PylonRight3 : PylonLeft3{
                            mirroredMissilePos = 3;
                            UIposition[] = {0.59,0.3};
                        };
                    };
                };
            };
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Helo_blackops_04 : B_Heli_Light_01_dynamicLoadout_F_OCimport_02 {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "AH-9 Pawnee (2c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        availableForSupportTypes[] = {"CAS_Bombing"};
        maximumLoad = 50000;
        class Components : Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class pylons {
                    class PylonLeft1 {
                        attachment = "PylonRack_4Rnd_LG_scalpel"; // PylonRack_12Rnd_missiles (HE), PylonRack_12Rnd_PG_missiles (AT), PylonMissile_1Rnd_LG_scalpel, PylonRack_7Rnd_Rocket_04_AP_F or PylonRack_7Rnd_Rocket_04_HE_F
                        hardpoints[] = {"DAR","DAGR","B_SHIEKER","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR"};
                        priority = 5;
                        UIposition[] = {0.06,0.4};
                    };
                    class PylonRight1 : PylonLeft1 {
                        mirroredMissilePos = 1;
                        UIposition[] = {0.59,0.4};
                    };
                };
            };
        };
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [ _unit, nil, ['AddTread',1,'AddTread_Short',0]] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

