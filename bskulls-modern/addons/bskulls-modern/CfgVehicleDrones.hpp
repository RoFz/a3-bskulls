    // ── Drone & ISR Asset Base Classes ──────────────────────────────────────

    class B_UGV_01_rcws_F;
    class B_UGV_01_rcws_F_OCimport_01 : B_UGV_01_rcws_F { scope = 0; class Turrets; class EventHandlers; };
    class B_UGV_01_rcws_F_OCimport_02 : B_UGV_01_rcws_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
            class CargoTurret_01;
        };
    };

    class B_UAV_02_dynamicLoadout_F;
    class B_UAV_02_dynamicLoadout_F_OCimport_01 : B_UAV_02_dynamicLoadout_F { scope = 0; class Turrets; class Components; class EventHandlers; };
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

    class B_UAV_01_F;
    class B_UAV_01_F_OCimport_01 : B_UAV_01_F { scope = 0; class Turrets; class EventHandlers; };
    class B_UAV_01_F_OCimport_02 : B_UAV_01_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_UAV_05_F;
    class B_UAV_05_F_OCimport_01 : B_UAV_05_F { scope = 0; class Turrets; class Components; class EventHandlers; };
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

    class Radar_System_01_base_F;
    class Radar_System_01_base_F_OCimport_01 : Radar_System_01_base_F { scope = 0; class Turrets; class EventHandlers; };
    class Radar_System_01_base_F_OCimport_02 : Radar_System_01_base_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class SAM_System_03_base_F;
    class SAM_System_03_base_F_OCimport_01 : SAM_System_03_base_F { scope = 0; class Turrets; class EventHandlers; };
    class SAM_System_03_base_F_OCimport_02 : SAM_System_03_base_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_UAV_01_backpack_F;
    class B_UAV_01_backpack_F_OCimport_01 : B_UAV_01_backpack_F { scope = 0; class assembleInfo; };

    class B_UAV_AI;
    class B_UAV_AI_OCimport_01 : B_UAV_AI { scope = 0; class EventHandlers; };
    class B_PTbskull_Veh_UAV_AI_AIR : B_UAV_AI_OCimport_01
    {
        // inheritsFrom(configfile >> "CfgVehicles" >> "B_UAV_AI") = bin\config.bin/CfgVehicles/B_Helipilot_F
        author = "RoFz";
        scope = 1;
        scopeCurator = 0;
        sensitivity = 9;
        sensitivityEar = 0.3;
        class EventHandlers : EventHandlers {
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0; _this setSkill 1;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_UAV_AI_GROUND : B_UAV_AI_OCimport_01
    {
        author = "RoFz";
        scope = 1;
        scopeCurator = 0;
        sensitivity = 9;
        sensitivityEar = 3;
        class EventHandlers : EventHandlers {
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0; _this disableAI 'SUPPRESSION';_this setSkill 1;};_this spawn _onSpawn;};";
        };
    };

    // ── Drones / ISR / AA ────────────────────────────────────────────────────

    class B_PTbskull_Veh_Drone_blackops_01 : B_UAV_02_dynamicLoadout_F_OCimport_02
    {
        author = "RoFz";
        scope = 1;        // DAO default; not in DRO auto-pools (use *_nodao for DRO UAV patrol)
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
            init = "if (local (_this select 0)) then {[_this select 0] call bskulls_fnc_initAutoCountermeasures; _onSpawn = {sleep 0.3; _unit = _this select 0; if ('insignia' in selectionNames _unit) then {[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};};_this spawn _onSpawn;};";
            local = "if (_this select 1) then {[_this select 0] call bskulls_fnc_initAutoCountermeasures;};";
            // init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit setVehicleReportOwnPosition true; _unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true;_unit setVariable['daoExclude',TRUE,TRUE]; if ('insignia' in selectionNames _unit) then {[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Drone_blackops_02 : B_UGV_01_rcws_F_OCimport_02
    {
        author = "RoFz";
        scope = 1;        // manual pad spawn only; blocks DRO FOB UAV-terminal auto-spawn
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
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [_unit, ['Olive', 1], true] call BIS_fnc_initVehicle; if ('insignia' in selectionNames _unit) then {[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Drone_blackops_03 : B_UAV_01_F_OCimport_02
    {
        author = "RoFz";
        scope = 1;        // manual + vanilla UAV terminal; DAO excluded on init; not in DRO pools
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
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; if ('insignia' in selectionNames _unit) then {[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;}; [_unit] call bskulls_fnc_daoExcludeVehicle;}; _this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Drone_blackops_04 : B_UAV_05_F_OCimport_02
    {
        author = "RoFz";
        // Single class: DRO may spawn it (UAV support); keep under DAO (no *_nodao, no auto-exclude).
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
        // CAS-side correction only: DRO makes its stock recon UAV captive, but this armed
        // class remains under DAO, whose CAS filter reads side _aircraft. This is unrelated
        // to DAO's documented VAM behavior of deleting landed aircraft during refit.
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {[_this select 0] call bskulls_fnc_initAutoCountermeasures; _onSpawn = {sleep 0.3; _unit = _this select 0; [_unit, ['DarkGreyCamo',1], ['wing_fold_l',0]] call BIS_fnc_initVehicle; if ('insignia' in selectionNames _unit) then {[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;}; sleep 2; if !(_unit getVariable ['DRO_SUPP_airDefenseHold', false]) then {_unit setCaptive false; { _x setCaptive false } forEach crew _unit;};}; _this spawn _onSpawn;};";
            local = "if (_this select 1) then {[_this select 0] call bskulls_fnc_initAutoCountermeasures;};";
        };
    };

    class B_PTbskull_Veh_Drone_blackops_01_nodao : B_PTbskull_Veh_Drone_blackops_01
    {
        scope = 2;
        scopeCurator = 0;
        displayName = "MQ-4A Greyhawk (no DAO)";
        class EventHandlers : EventHandlers
        {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };

    class B_PTbskull_Veh_Radar_blackops_01 : Radar_System_01_base_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "AN/MPQ-105 Radar";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_UAV_AI_GROUND";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = ""; };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {private _unit = _this select 0; _unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true; [_unit] call bskulls_fnc_initRadarRotation; [_unit] spawn {params ['_unit']; sleep 0.3; if (!alive _unit) exitWith {}; [_unit, ['Olive', 1], true] call BIS_fnc_initVehicle; if ('insignia' in selectionNames _unit) then {[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};};};";
            local = "if (_this select 1) then {[_this select 0] call bskulls_fnc_initRadarRotation;};";
        };
    };

    class B_PTbskull_Veh_SAM_blackops_01 : SAM_System_03_base_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "MIM-145 Defender SAM";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_UAV_AI_GROUND";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = ""; };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['Olive', 1], true] call BIS_fnc_initVehicle;if ('insignia' in selectionNames _unit) then {[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};};_this spawn _onSpawn;};";
            fired = "_unit = _this select 0;_unit setVehicleAmmo 1";
        };
    };

    class B_PTbskull_Veh_Back_UAV_blackops_01 : B_UAV_01_backpack_F_OCimport_01 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (UAV)";
        class assembleInfo : assembleInfo {
            assembleTo = "B_PTbskull_Veh_Drone_blackops_03";
            displayName = "AR-2 BSkull";
        };
    };
