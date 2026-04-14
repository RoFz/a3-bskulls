    // ── Ground Vehicle Base Classes ─────────────────────────────────────────

    class B_MBT_01_TUSK_F;
    class B_MBT_01_TUSK_F_OCimport_01 : B_MBT_01_TUSK_F { scope = 0; class Turrets; };
    class B_MBT_01_TUSK_F_OCimport_02 : B_MBT_01_TUSK_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_MBT_01_arty_F;
    class B_MBT_01_arty_F_OCimport_01 : B_MBT_01_arty_F { scope = 0; class Turrets; };
    class B_MBT_01_arty_F_OCimport_02 : B_MBT_01_arty_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_MBT_01_mlrs_F;
    class B_MBT_01_mlrs_F_OCimport_01 : B_MBT_01_mlrs_F { scope = 0; class Turrets; };
    class B_MBT_01_mlrs_F_OCimport_02 : B_MBT_01_mlrs_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_APC_Wheeled_01_cannon_F;
    class B_APC_Wheeled_01_cannon_F_OCimport_01 : B_APC_Wheeled_01_cannon_F { scope = 0; class Turrets; };
    class B_APC_Wheeled_01_cannon_F_OCimport_02 : B_APC_Wheeled_01_cannon_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_AFV_Wheeled_01_up_cannon_F;
    class B_AFV_Wheeled_01_up_cannon_F_OCimport_01 : B_AFV_Wheeled_01_up_cannon_F { scope = 0; class Turrets; };
    class B_AFV_Wheeled_01_up_cannon_F_OCimport_02 : B_AFV_Wheeled_01_up_cannon_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_Boat_Armed_01_minigun_F;
    class B_Boat_Armed_01_minigun_F_OCimport_01 : B_Boat_Armed_01_minigun_F { scope = 0; class Turrets; };
    class B_Boat_Armed_01_minigun_F_OCimport_02 : B_Boat_Armed_01_minigun_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class FrontTurret;
            class RearTurret;
        };
    };

    class Mortar_01_base_F;
    class Mortar_01_base_F_OCimport_01 : Mortar_01_base_F { scope = 0; class Turrets; };
    class Mortar_01_base_F_OCimport_02 : Mortar_01_base_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class Radar_System_01_base_F;
    class Radar_System_01_base_F_OCimport_01 : Radar_System_01_base_F { scope = 0; class Turrets; };
    class Radar_System_01_base_F_OCimport_02 : Radar_System_01_base_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class SAM_System_03_base_F;
    class SAM_System_03_base_F_OCimport_01 : SAM_System_03_base_F { scope = 0; class Turrets; };
    class SAM_System_03_base_F_OCimport_02 : SAM_System_03_base_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class rhsusf_m1151_m2_v2_usarmy_wd;
    class rhsusf_m1151_m2_v2_usarmy_wd_OCimport_01 : rhsusf_m1151_m2_v2_usarmy_wd { scope = 0; class Turrets; };
    class rhsusf_m1151_m2_v2_usarmy_wd_OCimport_02 : rhsusf_m1151_m2_v2_usarmy_wd_OCimport_01
    {
        class Turrets : Turrets
        {
            class OGPK_Turret;
            class CoDriverTurret;
        };
    };

    class bo_app66_green;
    class bo_app66_green_OCimport_01 : bo_app66_green { scope = 0; };

    class rhsusf_m1165a1_gmv_m134d_m240_socom_d;
    class rhsusf_m1165a1_gmv_m134d_m240_socom_d_OCimport_01 : rhsusf_m1165a1_gmv_m134d_m240_socom_d { scope = 0; class Turrets; };
    class rhsusf_m1165a1_gmv_m134d_m240_socom_d_OCimport_02 : rhsusf_m1165a1_gmv_m134d_m240_socom_d_OCimport_01
    {
        class Turrets : Turrets
        {
            class SAG_Turret;
            class CoDriverTurret;
            class SwingArm_L_Turret;
            class SwingArm_R_Turret;
            class CargoTurret_01;
            class CargoTurret_02;
            class CargoTurret_03;
            class CargoTurret_04;
        };
    };

    class rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy;
    class rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy_OCimport_01 : rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy { scope = 0; class Turrets; };
    class rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy_OCimport_02 : rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy_OCimport_01
    {
        class Turrets : Turrets
        {
            class M2_Turret;
            class CargoTurret_01;
            class CargoTurret_02;
        };
    };

    class B_T_Truck_01_ammo_F;
    class B_T_Truck_01_ammo_F_OCimport_01 : B_T_Truck_01_ammo_F { scope = 0; };

    class B_T_Truck_01_fuel_F;
    class B_T_Truck_01_fuel_F_OCimport_01 : B_T_Truck_01_fuel_F { scope = 0; };

    // ── Ground Vehicles ─────────────────────────────────────────────────────

    class B_PTbskull_Veh_Tank_blackops_01 : B_MBT_01_TUSK_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M2A4 Slammer UP (3c6p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01"; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['Olive',1], ['showCamonetTurret',1,'showCamonetHull',1,'showBags',1]] call BIS_fnc_initVehicle;waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyHV; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Artillery_blackops_01 : B_MBT_01_arty_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M4 Scorcher (3c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret {
                gunnerType = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01";
                magazines[] = {"64Rnd_155mm_Plus_Mo_shells","8Rnd_155mm_Plus_Mo_guided","12Rnd_155mm_Plus_Mo_mine","4Rnd_155mm_Plus_Mo_Cluster","8Rnd_155mm_Plus_Mo_LG","12Rnd_155mm_Plus_Mo_AT_mine"};
                weapons[] = {"B_PTbskull_Wea_art_gun_01"};
            };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; [_unit,['Olive',1],['showCanisters',1,'showCamonetTurret',1,'showAmmobox',1,'showCamonetHull',1]] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Artillery_blackops_02 : B_MBT_01_mlrs_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M5 Sandstorm MLRS (2c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets {
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01"; };
        };
        class EventHandlers : EventHandlers {
            fired = "_unit = _this select 0;_unit setVehicleAmmo 1";
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; [_unit,['Olive',1],['showCamonetTurret',1,'showCamonetHull',1]] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_APC_blackops_01 : B_APC_Wheeled_01_cannon_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "AMV-7 Marshall (3c8p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01"; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit forceFlagTexture '\bskulls-modern\textures\black_skulls_insig_128_128.paa';[_unit, ['Olive',1], ['showCamonetTurret',1,'showCamonetHull',1,'showBags',1,'showSLATHull',1,'showSLATTurret',1]] call BIS_fnc_initVehicle;waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyMV; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_APC_blackops_02 : B_AFV_Wheeled_01_up_cannon_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Rhino MGS UP (3c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01"; };
        };
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit forceFlagTexture '\bskulls-modern\textures\black_skulls_insig_128_128.paa';[_unit, ['Green',1], ['showCamonetHull',1,'showCamonetTurret',1,'showSLATHull',1]] call BIS_fnc_initVehicle;waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyMV; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Car_blackops_01 : bo_app66_green_OCimport_01
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "APP-66 (1c9p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Vehicle_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        armorGlass = 1.5;
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit forceFlagTexture '\bskulls-modern\textures\black_skulls_insig_128_128.paa';[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Car_blackops_02 : rhsusf_m1151_m2_v2_usarmy_wd_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M1151A1 (M2) x5";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Vehicle_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        armorGlass = 1.5;
        class Turrets : Turrets
        {
            class OGPK_Turret : OGPK_Turret { gunnerType = ""; };
            class CoDriverTurret : CoDriverTurret { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit forceFlagTexture '\bskulls-modern\textures\black_skulls_insig_128_128.paa';[_unit, ['rhs_woodland',1], ['DUKE_Hide',0,'bumper2_hide',0,'hide_ogpkover',0,'hide_ogpknet',0,'hide_ogpkbust',0,'hide_rhino',1,'door_LF',0,'door_LB',0,'door_RF',0,'door_RB',0,'door_trunk',0,'iff_hide',0,'dwf_kit_Hide',0,'snorkel_lower',0,'BFT_Hide',0,'Antennas_Hide',0,'hide_spare',0]] call BIS_fnc_initVehicle;[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Car_blackops_03 : rhsusf_m1165a1_gmv_m134d_m240_socom_d_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M1165A1 GMV (SAG-2/M134D/M240) (3c7p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Vehicle_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        armorGlass = 1.5;
        class Turrets : Turrets
        {
            class SAG_Turret : SAG_Turret { gunnerType = ""; };
            class CoDriverTurret : CoDriverTurret { gunnerType = ""; };
            class SwingArm_L_Turret : SwingArm_L_Turret { gunnerType = ""; };
            class SwingArm_R_Turret : SwingArm_R_Turret { gunnerType = ""; };
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
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit forceFlagTexture '\bskulls-modern\textures\black_skulls_insig_128_128.paa';[_unit, ['rhs_sofwoodland',1], ['Hide_Scopes',0,'door_M',0,'door_R',0,'tools_hide',0,'runningboard_hide',0,'ammo_carrier_hide',0,'sag_ammo_hide',0,'sparewheel_carrier_hide',0,'sagr_hide',0,'door_LF',0,'door_LB',0,'door_RF',0,'door_RB',0,'BFT_Hide',0,'Antennas_Hide',0,'hide_spare',0]] call BIS_fnc_initVehicle;[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Truck_blackops_01 : rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M1078A1P2-B (O-GPK/M2) (2c13p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Vehicle_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        armorGlass = 1.5;
        class Turrets : Turrets
        {
            class M2_Turret : M2_Turret { gunnerType = ""; };
            class CargoTurret_01 : CargoTurret_01 { gunnerType = ""; };
            class CargoTurret_02 : CargoTurret_02 { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, nil, ['hide_ogpkover',0,'hide_ogpknet',0,'hide_ogpkbust',0,'hide_cover',0,'hide_spare',0,'hide_scaffold',0,'hide_bench',0]] call BIS_fnc_initVehicle;waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyMV;[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
            // fired = "[_this select 0,_this select 6,'missile_move','MissileBase'] call BIS_fnc_missileLaunchPositionFix; _this call (uinamespace getvariable 'BIS_fnc_effectFired');";
        };
    };

    class B_PTbskull_Veh_Truck_blackops_02 : B_T_Truck_01_ammo_F_OCimport_01
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "HEMTT Ammo (2c)";
        // editorSubcategory = "rhs_EdSubcat_truck";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Martinez_blackops_02";
        // crew = "B_PTbskull_Veh_Unit_Vehicle_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        armorGlass = 1.5;
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };


    class B_PTbskull_Veh_Truck_blackops_03 : B_T_Truck_01_fuel_F_OCimport_01
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "HEMTT Fuel (2c)";
        // editorSubcategory = "rhs_EdSubcat_truck";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Elias_blackops_02";
        // crew = "B_PTbskull_Veh_Unit_Vehicle_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        armorGlass = 1.5;
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Boat_blackops_01 : B_Boat_Armed_01_minigun_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Speedboat (Minigun) x11";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Boat_Crew_blackops_01";
        hiddenSelections[] += {"insignia"};
        class Turrets : Turrets
        {
            class FrontTurret : FrontTurret { gunnerType = ""; };
            class RearTurret : RearTurret { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit forceFlagTexture '\bskulls-modern\textures\black_skulls_insig_128_128.paa';_unit setObjectTextureGlobal [0,'\A3\Boat_F\Boat_Armed_01\Data\Boat_Armed_01_ext_CO.paa'];_unit setObjectTextureGlobal [1,'\A3\boat_f\Boat_Armed_01\data\Boat_Armed_01_int_co.paa'];_unit setObjectTextureGlobal [2,'\A3\boat_f\Boat_Armed_01\data\Boat_Armed_01_crows_blufor_co.paa'];[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Mortar_blackops_01 : Mortar_01_base_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Mk6+ Mortar (82mm)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Vehicle_Crew_blackops_01";
        availableForSupportTypes[] = {"Artillery"};
        class Turrets : Turrets
        {
            class MainTurret : MainTurret {
                discreteDistance[] = {100,200,300,400,500,700,1000,1600,2000,2400,2800,3200,3600,4000,4400,4800,5200};
                magazines[] = {"80Rnd_82mm_Mo_shells_PLUS"};
                maxTurn = 360;
            };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;vehicle player loadMagazine [[0], 'FakeWeapon', '80Rnd_82mm_Mo_shells_PLUS'];while {true} do {sleep 600;_unit setVehicleAmmo 1;[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};};";
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
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['Olive', 1], true] call BIS_fnc_initVehicle;_unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true;while {true} do {{_unit lookAt (_unit getRelPos [100, _x]);sleep 2.45;} forEach [120, 240, 0];};[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
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
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['Olive', 1], true] call BIS_fnc_initVehicle;[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
            fired = "_unit = _this select 0;_unit setVehicleAmmo 1";
        };
    };

    // Units
