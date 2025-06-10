#include "symbols.hpp"
#include "CfgWeapons.hpp"

// class Turrets;
// class MainTurret;
class CBA_Extended_EventHandlers_base;

class CfgVehicles
{

    // Base Vehicles
    class B_Plane_CAS_01_dynamicLoadout_F;
    class B_Plane_CAS_01_dynamicLoadout_F_OCimport_01 : B_Plane_CAS_01_dynamicLoadout_F { scope = 0; class EventHandlers; };
    class B_Plane_CAS_01_dynamicLoadout_F_OCimport_02 : B_Plane_CAS_01_dynamicLoadout_F_OCimport_01 { scope = 0; class EventHandlers; };

    class B_UAV_02_dynamicLoadout_F;
    class B_UAV_02_dynamicLoadout_F_OCimport_01 : B_UAV_02_dynamicLoadout_F { scope = 0; class EventHandlers; class Turrets; class Components;};
    class B_UAV_02_dynamicLoadout_F_OCimport_02 : B_UAV_02_dynamicLoadout_F_OCimport_01
    {
        class EventHandlers;
        class Components : Components {
            class TransportPylonsComponent;
        };
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_UAV_05_F;
    class B_UAV_05_F_OCimport_01 : B_UAV_05_F { scope = 0; class EventHandlers; class Turrets; class Components;};
    class B_UAV_05_F_OCimport_02 : B_UAV_05_F_OCimport_01
    {
        class EventHandlers;
        class Components : Components {
            class TransportPylonsComponent;
        };
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_UGV_01_rcws_F;
    class B_UGV_01_rcws_F_OCimport_01 : B_UGV_01_rcws_F { scope = 0; class EventHandlers; class Turrets; };
    class B_UGV_01_rcws_F_OCimport_02 : B_UGV_01_rcws_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class MainTurret;
            class CargoTurret_01;
        };
    };

    class B_UAV_01_F;
    class B_UAV_01_F_OCimport_01 : B_UAV_01_F { scope = 0; class EventHandlers; };

    class B_Heli_Transport_03_F;
    class B_Heli_Transport_03_F_OCimport_01 : B_Heli_Transport_03_F { scope = 0; class EventHandlers; class Turrets; };
    class B_Heli_Transport_03_F_OCimport_02 : B_Heli_Transport_03_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class CopilotTurret;
            class MainTurret;
            class RightDoorGun;
            class CargoTurret_01;
            class CargoTurret_02;
        };
    };

    class B_MBT_01_TUSK_F;
    class B_MBT_01_TUSK_F_OCimport_01 : B_MBT_01_TUSK_F { scope = 0; class EventHandlers; class Turrets; };
    class B_MBT_01_TUSK_F_OCimport_02 : B_MBT_01_TUSK_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_MBT_01_arty_F;
    class B_MBT_01_arty_F_OCimport_01 : B_MBT_01_arty_F { scope = 0; class EventHandlers; class Turrets; };
    class B_MBT_01_arty_F_OCimport_02 : B_MBT_01_arty_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_MBT_01_mlrs_F;
    class B_MBT_01_mlrs_F_OCimport_01 : B_MBT_01_mlrs_F { scope = 0; class EventHandlers; class Turrets; };
    class B_MBT_01_mlrs_F_OCimport_02 : B_MBT_01_mlrs_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_APC_Wheeled_01_cannon_F;
    class B_APC_Wheeled_01_cannon_F_OCimport_01 : B_APC_Wheeled_01_cannon_F { scope = 0; class EventHandlers; class Turrets; };
    class B_APC_Wheeled_01_cannon_F_OCimport_02 : B_APC_Wheeled_01_cannon_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_AFV_Wheeled_01_up_cannon_F;
    class B_AFV_Wheeled_01_up_cannon_F_OCimport_01 : B_AFV_Wheeled_01_up_cannon_F { scope = 0; class EventHandlers; class Turrets; };
    class B_AFV_Wheeled_01_up_cannon_F_OCimport_02 : B_AFV_Wheeled_01_up_cannon_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_Heli_Light_01_F;
    class B_Heli_Light_01_F_OCimport_01 : B_Heli_Light_01_F { scope = 0; class EventHandlers; class Turrets; };
    class B_Heli_Light_01_F_OCimport_02 : B_Heli_Light_01_F_OCimport_01 {
        class EventHandlers;
        class Turrets : Turrets {
            class CopilotTurret;
            class CargoTurret_01;
            class CargoTurret_02;
            class CargoTurret_03;
            class CargoTurret_04;
        };
    };

    class B_Heli_Attack_01_dynamicLoadout_F;
    class B_Heli_Attack_01_dynamicLoadout_F_OCimport_01 : B_Heli_Attack_01_dynamicLoadout_F { scope = 0; class EventHandlers; class Turrets; class Components;};
    class B_Heli_Attack_01_dynamicLoadout_F_OCimport_02 : B_Heli_Attack_01_dynamicLoadout_F_OCimport_01 {
        class EventHandlers;
        class Components : Components {
            class TransportPylonsComponent;
        };
        class Turrets : Turrets {
            class MainTurret;
        };
    };

    class B_Heli_Light_01_dynamicLoadout_F;
    class B_Heli_Light_01_dynamicLoadout_F_OCimport_01 : B_Heli_Light_01_dynamicLoadout_F { scope = 0; class EventHandlers; class Components;};
    class B_Heli_Light_01_dynamicLoadout_F_OCimport_02 : B_Heli_Light_01_dynamicLoadout_F_OCimport_01 {
        class EventHandlers;
        class Components : Components {
            class TransportPylonsComponent;
        };
    };

    class B_Boat_Armed_01_minigun_F;
    class B_Boat_Armed_01_minigun_F_OCimport_01 : B_Boat_Armed_01_minigun_F { scope = 0; class EventHandlers; class Turrets; };
    class B_Boat_Armed_01_minigun_F_OCimport_02 : B_Boat_Armed_01_minigun_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class FrontTurret;
            class RearTurret;
        };
    };

    class Mortar_01_base_F;
    class Mortar_01_base_F_OCimport_01 : Mortar_01_base_F { scope = 0; class EventHandlers; class Turrets; };
    class Mortar_01_base_F_OCimport_02 : Mortar_01_base_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class Radar_System_01_base_F;
    class Radar_System_01_base_F_OCimport_01 : Radar_System_01_base_F { scope = 0; class EventHandlers; class Turrets; };
    class Radar_System_01_base_F_OCimport_02 : Radar_System_01_base_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class SAM_System_03_base_F;
    class SAM_System_03_base_F_OCimport_01 : SAM_System_03_base_F { scope = 0; class EventHandlers; class Turrets; };
    class SAM_System_03_base_F_OCimport_02 : SAM_System_03_base_F_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };


    class rhsusf_m1151_m2_v2_usarmy_wd;
    class rhsusf_m1151_m2_v2_usarmy_wd_OCimport_01 : rhsusf_m1151_m2_v2_usarmy_wd { scope = 0; class EventHandlers; class Turrets; };
    class rhsusf_m1151_m2_v2_usarmy_wd_OCimport_02 : rhsusf_m1151_m2_v2_usarmy_wd_OCimport_01 {
        class EventHandlers;
        class Turrets : Turrets
        {
            class OGPK_Turret;
            class CoDriverTurret;
        };
    };

    class rhsusf_m1165a1_gmv_m134d_m240_socom_d;
    class rhsusf_m1165a1_gmv_m134d_m240_socom_d_OCimport_01 : rhsusf_m1165a1_gmv_m134d_m240_socom_d { scope = 0; class EventHandlers; class Turrets; };
    class rhsusf_m1165a1_gmv_m134d_m240_socom_d_OCimport_02 : rhsusf_m1165a1_gmv_m134d_m240_socom_d_OCimport_01
    {
        class EventHandlers;
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
    class rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy_OCimport_01 : rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy { scope = 0; class EventHandlers; class Turrets; };
    class rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy_OCimport_02 : rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy_OCimport_01
    {
        class EventHandlers;
        class Turrets : Turrets
        {
            class M2_Turret;
            class CargoTurret_01;
            class CargoTurret_02;
        };
    };

    class B_T_Truck_01_ammo_F;
    class B_T_Truck_01_ammo_F_OCimport_01 : B_T_Truck_01_ammo_F { scope = 0; class EventHandlers; };

    class B_T_Truck_01_fuel_F;
    class B_T_Truck_01_fuel_F_OCimport_01 : B_T_Truck_01_fuel_F { scope = 0; class EventHandlers; };


    // Base Units

    class B_Fighter_Pilot_F;
    class B_Fighter_Pilot_F_OCimport_01 : B_Fighter_Pilot_F { scope = 0; class EventHandlers; };
    class B_Fighter_Pilot_F_OCimport_02 : B_Fighter_Pilot_F_OCimport_01
    {
        class EventHandlers;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManOfficer";
    };

    class B_Helipilot_F;
    class B_Helipilot_F_OCimport_01 : B_Helipilot_F { scope = 0; class EventHandlers; };
    class B_Helipilot_F_OCimport_02 : B_Helipilot_F_OCimport_01
    {
        class EventHandlers;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManLeader";
    };

    class B_helicrew_F;
    class B_helicrew_F_OCimport_01 : B_helicrew_F { scope = 0; class EventHandlers; };
    class B_helicrew_F_OCimport_02 : B_helicrew_F_OCimport_01
    {
        class EventHandlers;
        sensitivity = 9;
        sensitivityEar = 3;
    };

    class B_crew_F;
    class B_crew_F_OCimport_01 : B_crew_F { scope = 0; class EventHandlers; };
    class B_crew_F_OCimport_02 : B_crew_F_OCimport_01
    {
        class EventHandlers;
        sensitivity = 9;
        sensitivityEar = 3;
    };

    class B_recon_TL_F;
    class B_recon_TL_F_OCimport_01 : B_recon_TL_F { scope = 0; class EventHandlers; };
    class B_recon_TL_F_OCimport_02 : B_recon_TL_F_OCimport_01
    {
        class EventHandlers;
        camouflage = 0.9;
        sensitivity = 9;
        sensitivityEar = 3;
		canDeactivateMines = true;
		engineer = true;
        uavHacker = 1;
        // attendant = 1;
        icon = "iconManLeader";
    };

    class TCGM_Stealth_B_CTRG_Soldier_Medic;
    class TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_01 : TCGM_Stealth_B_CTRG_Soldier_Medic { scope = 0; class EventHandlers; };
    class TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_01
    {
        class EventHandlers;
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        camouflage = 0.5;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconWomanMedic";
    };

    class TCGM_Stealth_B_CTRG_Soldier_SC;
    class TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_01 : TCGM_Stealth_B_CTRG_Soldier_SC { scope = 0; class EventHandlers; };
    class TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_01
    {
        class EventHandlers;
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        camouflage = 0.9;
        sensitivity = 9;
        sensitivityEar = 3;
    };

    // Does not work - uniform never loads while in DRO!
    // class TCGM_Viper_O_m_GHex_Soldier;
    // class TCGM_Viper_O_m_GHex_Soldier_OCimport_01 : TCGM_Viper_O_m_GHex_Soldier { scope = 0; class EventHandlers; };
    // class TCGM_Viper_O_m_GHex_Soldier_OCimport_02 : TCGM_Viper_O_m_GHex_Soldier_OCimport_01
    // {
    //     class EventHandlers;
    //     editorSubcategory="EdSubcat_Personnel_SpecialForces";
    //     camouflage = 0.1;
    //     audible = 0.01;
    //     sensitivity = 90;
    //     sensitivityEar = 3;
    //     icon = "iconWomanRecon";
    // };

    class B_Recon_Sharpshooter_F;
    class B_Recon_Sharpshooter_F_OCimport_01 : B_Recon_Sharpshooter_F { scope = 0; class EventHandlers; };
    class B_Recon_Sharpshooter_F_OCimport_02 : B_Recon_Sharpshooter_F_OCimport_01
    {
        class EventHandlers;
        camouflage = 0.1;
        audible = 0.01;
        sensitivity = 90;
        sensitivityEar = 3;
        icon = "iconManRecon";
    };

    class B_recon_exp_F;
    class B_recon_exp_F_OCimport_01 : B_recon_exp_F { scope = 0; class EventHandlers; };
    class B_recon_exp_F_OCimport_02 : B_recon_exp_F_OCimport_01
    {
        class EventHandlers;
        camouflage = 0.5;
        sensitivity = 9;
        sensitivityEar = 3;
		canDeactivateMines = true;
		engineer = true;
        icon = "iconManExplosive";
    };

    class B_Patrol_HeavyGunner_F;
    class B_Patrol_HeavyGunner_F_OCimport_01 : B_Patrol_HeavyGunner_F { scope = 0; class EventHandlers; };
    class B_Patrol_HeavyGunner_F_OCimport_02 : B_Patrol_HeavyGunner_F_OCimport_01
    {
        class EventHandlers;
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        camouflage = 0.9;
        audible = 0.06;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManMG";
    };

    class B_recon_LAT_F;
    class B_recon_LAT_F_OCimport_01 : B_recon_LAT_F { scope = 0; class EventHandlers; };
    class B_recon_LAT_F_OCimport_02 : B_recon_LAT_F_OCimport_01
    {
        class EventHandlers;
        camouflage = 0.9;
        audible = 0.06;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManAT";
    };

    class B_Recon_F;
    class B_Recon_F_OCimport_01 : B_Recon_F { scope = 0; class EventHandlers; };
    class B_Recon_F_OCimport_02 : B_Recon_F_OCimport_01
    {
        class EventHandlers;
        camouflage = 0.5;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManRecon";
    };

    class B_soldier_UAV_F;
    class B_soldier_UAV_F_OCimport_01 : B_soldier_UAV_F { scope = 0; class EventHandlers; };
    class B_soldier_UAV_F_OCimport_02 : B_soldier_UAV_F_OCimport_01
    {
        class EventHandlers;
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        camouflage = 0.9; // Medic,Exp,Ammo = 0.5; Sniper = 0.1; TL,AT,UAV,MG = 0.9;
        audible = 0.06; // Sniper = 0.01; AT,UAV,MG = 0.06
        sensitivity = 9;
        sensitivityEar = 3;
		engineer = true;
        uavHacker = 1;
        icon = "iconManEngineer";
    };

    class B_UAV_AI;
    class B_UAV_AI_OCimport_01 : B_UAV_AI { scope = 0; class EventHandlers; };
    class B_PTbskull_Veh_UAV_AI_AIR : B_UAV_AI_OCimport_01
    {
        // inheritsFrom(configfile >> "CfgVehicles" >> "B_UAV_AI") = bin\config.bin/CfgVehicles/B_Helipilot_F
        // inheritsFrom(configfile >> "CfgVehicles" >> "B_Helipilot_F") = bin\config.bin/CfgVehicles/B_Soldier_04_f
        // inheritsFrom(configfile >> "CfgVehicles" >> "B_Soldier_04_f") = bin\config.bin/CfgVehicles/B_Soldier_base_F
        // inheritsFrom(configfile >> "CfgVehicles" >> "B_Soldier_base_F") = bin\config.bin/CfgVehicles/SoldierWB
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        sensitivity = 9;
        sensitivityEar = 0.3;
        class EventHandlers : EventHandlers {
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0; _this setSkill 1;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_UAV_AI_GROUND : B_UAV_AI_OCimport_01
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        sensitivity = 9;
        sensitivityEar = 3;
        class EventHandlers : EventHandlers {
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0; _this disableAI 'SUPPRESSION';_this setSkill 1;};_this spawn _onSpawn;};";
        };
    };

    // Vehicles

    class B_PTbskull_Veh_Plane_blackops_01 : B_Plane_CAS_01_dynamicLoadout_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "A-164 Wipeout (CAS) (1c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Plane_Pilot_blackops_01";
        availableForSupportTypes[] = {"CAS_Bombing"};
        hiddenSelections[] += { "insignia" };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; _unit setVehicleReportOwnPosition true; _unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
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
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = ""; };
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

    class B_PTbskull_Veh_Drone_blackops_03 : B_UAV_01_F_OCimport_01
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
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit setVariable['daoExclude',TRUE,TRUE]; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
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
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = ""; };
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
        crew = "B_PTbskull_Veh_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        availableForSupportTypes[] = {"Drop","Transport"};
        class Turrets : Turrets
        {
            class CopilotTurret : CopilotTurret { gunnerType = "B_PTbskull_Veh_Helo_Pilot_blackops_01"; };
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Helo_Crew_blackops_01"; };
            class RightDoorGun : RightDoorGun { gunnerType = "B_PTbskull_Veh_Helo_Crew_blackops_01"; };
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
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [_unit,['Black',1], true] call BIS_fnc_initVehicle; _unit setVariable['daoExclude',TRUE,TRUE]; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Helo_blackops_02 : B_Heli_Light_01_F_OCimport_02 {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "MH-9 Hummingbird (1c7p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        availableForSupportTypes[] = {"Drop","Transport"};
        class Turrets : Turrets {
            class CopilotTurret : CopilotTurret { gunnerType = "B_PTbskull_Veh_Helo_Pilot_blackops_01"; dontCreateAI = true; };
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
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [ _unit, nil, ['AddBenches',1,'AddTread',1,'AddBackseats',1,'AddHoldingFrame',1,'AddTread_Short',0]] call BIS_fnc_initVehicle; _unit setVariable['daoExclude',TRUE,TRUE]; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Helo_blackops_03 : B_Heli_Attack_01_dynamicLoadout_F_OCimport_02 {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "AH-99 Blackfoot (2c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Helo_Pilot_blackops_01";
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
        crew = "B_PTbskull_Veh_Helo_Pilot_blackops_01";
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

    class B_PTbskull_Veh_Tank_blackops_01 : B_MBT_01_TUSK_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M2A4 Slammer UP (3c6p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Tank_Crew_blackops_01"; };
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
        crew = "B_PTbskull_Veh_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret {
                gunnerType = "B_PTbskull_Veh_Tank_Crew_blackops_01";
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
        crew = "B_PTbskull_Veh_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets {
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Tank_Crew_blackops_01"; };
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
        crew = "B_PTbskull_Veh_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Tank_Crew_blackops_01"; };
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
        crew = "B_PTbskull_Veh_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Tank_Crew_blackops_01"; };
        };
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit forceFlagTexture '\bskulls-modern\textures\black_skulls_insig_128_128.paa';[_unit, ['Green',1], ['showCamonetHull',1,'showCamonetTurret',1,'showSLATHull',1]] call BIS_fnc_initVehicle;waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyMV; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
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
        crew = "B_PTbskull_Veh_Vehicle_Crew_blackops_01";
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
        crew = "B_PTbskull_Veh_Vehicle_Crew_blackops_01";
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
        crew = "B_PTbskull_Veh_Vehicle_Crew_blackops_01";
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
        crew = "B_PTbskull_Veh_Vehicle_Crew_blackops_01";
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
        crew = "B_PTbskull_Veh_Vehicle_Crew_blackops_01";
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
        crew = "B_PTbskull_Veh_Boat_Crew_blackops_01";
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
        crew = "B_PTbskull_Veh_Vehicle_Crew_blackops_01";
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

    class B_PTbskull_Veh_Viper_blackops_01 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL, NO THERM SIG) (SIG716 + AXMC)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        // weaponSlots = "1 + 4 + 24*256 + 4096 + 2 + 3*16 + 12*131072";
        linkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_br_1","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_br_1","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_13(kt_20Rnd_65_Creedmoor_108gr_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_13(kt_20Rnd_65_Creedmoor_108gr_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_TL_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';"
        };
    };

    class B_PTbskull_Veh_Viper_blackops_02 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (HB300AAC + WA2000)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_6","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_6","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_9(hlc_50rnd_300BLK_STANAG_EPR),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_9(hlc_50rnd_300BLK_STANAG_EPR),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_TL_blackops_02";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';"
        };
    };

    class B_PTbskull_Veh_Viper_blackops_03 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (SCAR-H GL + M110)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_7","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_7","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_13(KA_SCAR_H_20rnd_M993_AP_mag),MAG_2(1Rnd_HE_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_13(KA_SCAR_H_20rnd_M993_AP_mag),MAG_2(1Rnd_HE_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_TL_blackops_03";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';"
        };
    };

    class B_PTbskull_Veh_Viper_blackops_04 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (SIG716 + AXMC) (Ghillie)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        // weaponSlots = "1 + 4 + 24*256 + 4096 + 2 + 3*16 + 12*131072";
        linkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_br_1","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_br_1","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_13(kt_20Rnd_65_Creedmoor_108gr_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_13(kt_20Rnd_65_Creedmoor_108gr_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_TL_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';"
        };
    };

    class B_PTbskull_Veh_Viper_blackops_05 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + SPAS + MAR-10) (Ghillie)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        linkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_SMG_02","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_10(30Rnd_9x21_Mag_SMG_02_Tracer_Green),MAG_20(10Rnd_338_Mag),MAG_5(8Rnd_SPAS12_buck),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_10(30Rnd_9x21_Mag_SMG_02_Tracer_Green),MAG_20(10Rnd_338_Mag),MAG_5(8Rnd_SPAS12_buck),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_TL_blackops_05";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';"
        };
    };

    class B_PTbskull_Veh_Fox_blackops_01 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (SIG716, NO THERM SIG)";
        side = 1;
        formationX = 2;
        formationZ = 2;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",DEFAULT_GOGGLES};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,DEFAULT_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,DEFAULT_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_br_1",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_br_1",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_10(kt_20Rnd_65_Creedmoor_108gr_AP_mag)};
        respawnMagazines[] = {MAG_10(kt_20Rnd_65_Creedmoor_108gr_AP_mag)};
        backpack = "B_PTbskull_Veh_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_fox = (this select 0); _fox execVM '\bskulls-modern\scripts\2_fox.sqf';"
        };
    };

    class B_PTbskull_Veh_Fox_blackops_02 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (HB300AAC)";
        side = 1;
        formationX = 2;
        formationZ = 2;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",FOX_GOGGLES};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_6","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_6","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_6(hlc_50rnd_300BLK_STANAG_EPR),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_6(hlc_50rnd_300BLK_STANAG_EPR),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\2_fox.sqf';"
        };
    };

    class B_PTbskull_Veh_Fox_blackops_03 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (SCAR-H)";
        side = 1;
        formationX = 2;
        formationZ = 2;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",FOX_GOGGLES};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_15(DEFAULT_AR_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_15(DEFAULT_AR_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\2_fox.sqf';"
        };
    };

    class B_PTbskull_Veh_Vega_blackops_01 : B_Recon_Sharpshooter_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "03 Vega (Sniper) (AXMC)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_lush","LanguageGRE_F",VEGA_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        linkedItems[] = {DEFAULT_VEST,VEGA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VEGA_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VEGA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VEGA_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_sniper_6",DEFAULT_HANDGUN,DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_6",DEFAULT_HANDGUN,DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_4(DEFAULT_HANDGUN_AMMO),MAG_20(B_PTbskull_Wea_sniper_6_AMMO)};
        respawnMagazines[] = {MAG_4(DEFAULT_HANDGUN_AMMO),MAG_20(B_PTbskull_Wea_sniper_6_AMMO)};
        backpack = "B_PTbskull_Veh_SNIPER_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\3_vega.sqf';"
        };
    };

    class B_PTbskull_Veh_Vega_blackops_02 : B_Recon_Sharpshooter_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "03 Vega (Sniper) (McMillan)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_lush","LanguageGRE_F",VEGA_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        linkedItems[] = {DEFAULT_VEST,VEGA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VEGA_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VEGA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VEGA_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_sniper_7",DEFAULT_HANDGUN,DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_7",DEFAULT_HANDGUN,DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_4(DEFAULT_HANDGUN_AMMO),MAG_25(KA_CS5_10rnd_M993_AP_mag)};
        respawnMagazines[] = {MAG_4(DEFAULT_HANDGUN_AMMO),MAG_25(KA_CS5_10rnd_M993_AP_mag)};
        backpack = "B_PTbskull_Veh_SNIPER_blackops_02";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\3_vega.sqf';"
        };
    };

    class B_PTbskull_Veh_McKendrick_blackops_01 : B_recon_exp_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (Demo, NO THERM SIG) (SIG716)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Enoch","LanguageENGB_F",DEFAULT_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,DEFAULT_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,DEFAULT_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_br_1",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_br_1",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_10(kt_20Rnd_65_Creedmoor_108gr_AP_mag)};
        respawnMagazines[] = {MAG_10(kt_20Rnd_65_Creedmoor_108gr_AP_mag)};
        backpack = "B_PTbskull_Veh_EXP_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\4_mckendrick.sqf';"
        };
    };

    class B_PTbskull_Veh_McKendrick_blackops_02 : B_recon_exp_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (Demo) (HB300AAC)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Enoch","LanguageENGB_F",MCKENDRICK_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_6","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_6","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_6(hlc_50rnd_300BLK_STANAG_EPR),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_6(hlc_50rnd_300BLK_STANAG_EPR),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_EXP_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\4_mckendrick.sqf';"
        };
    };

    class B_PTbskull_Veh_McKendrick_blackops_03 : B_recon_exp_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (Demo) (SCAR-H)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Enoch","LanguageENGB_F",MCKENDRICK_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_15(DEFAULT_AR_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_15(DEFAULT_AR_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_EXP_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\4_mckendrick.sqf';"
        };
    };

    class B_PTbskull_Veh_Jackson_blackops_01 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "05 Jackson (Medic) (R11)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,JACKSON_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,JACKSON_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        weapons[] = {"B_PTbskull_Wea_ar_3","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_3","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_11(JAS_RSASS_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_11(JAS_RSASS_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\5_jackson.sqf';"
        };
    };

    class B_PTbskull_Veh_Jackson_blackops_02 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "05 Jackson (Medic) (SCAR-H)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,JACKSON_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,JACKSON_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_15(DEFAULT_AR_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_15(DEFAULT_AR_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\5_jackson.sqf';"
        };
    };

    class B_PTbskull_Veh_Frost_blackops_01 : B_Patrol_HeavyGunner_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "06 Frost (SPMG338)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENGFRE_F","G_SSU_Bandana_Sports_Black"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Camo_Combat_Helmet_MCAM_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Camo_Combat_Helmet_MCAM_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black"};
        weapons[] = {"B_PTbskull_Wea_mg_1",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_1",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_3(130Rnd_338_Mag)};
        respawnMagazines[] = {MAG_3(130Rnd_338_Mag)};
        backpack = "B_PTbskull_Veh_MG_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\6_frost.sqf';"
        };
    };

    class B_PTbskull_Veh_Frost_blackops_02 : B_Patrol_HeavyGunner_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "06 Frost (Navid9.3)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENGFRE_F","G_SSU_Bandana_Sports_Black"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Camo_Combat_Helmet_MCAM_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Camo_Combat_Helmet_MCAM_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black"};
        weapons[] = {"B_PTbskull_Wea_mg_2",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_2",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_3(150Rnd_93x64_Mag)};
        respawnMagazines[] = {MAG_3(150Rnd_93x64_Mag)};
        backpack = "B_PTbskull_Veh_MG_blackops_02";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\6_frost.sqf';"
        };
    };

    class B_PTbskull_Veh_Hawkins_blackops_01 : B_recon_LAT_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "07 Hawkins (AT) (SIG716)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_SSU_Bandana_Sports_Black_Beast"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,HAWKINS_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black_Beast"};
        respawnlinkedItems[] = {DEFAULT_VEST,HAWKINS_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black_Beast"};
        weapons[] = {"B_PTbskull_Wea_br_1","B_PTbskull_Wea_law_01",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_br_1","B_PTbskull_Wea_law_01",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {"Titan_AT_PLUS",MAG_9(kt_20Rnd_65_Creedmoor_108gr_AP_mag)};
        respawnMagazines[] = {"Titan_AT_PLUS",MAG_9(kt_20Rnd_65_Creedmoor_108gr_AP_mag)};
        backpack = "B_PTbskull_Veh_AT_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\7_hawkins.sqf';"
        };
    };

    class B_PTbskull_Veh_Hawkins_blackops_02 : B_recon_LAT_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "07 Hawkins (AT) (SCAR-H GL)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_SSU_Bandana_Sports_Black_Beast"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,HAWKINS_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black_Beast"};
        respawnlinkedItems[] = {DEFAULT_VEST,HAWKINS_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black_Beast"};
        weapons[] = {"B_PTbskull_Wea_ar_7","B_PTbskull_Wea_law_01",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_7","B_PTbskull_Wea_law_01",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {"Titan_AT_PLUS",MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),MAG_6(1Rnd_HE_Grenade_shell)};
        respawnMagazines[] = {"Titan_AT_PLUS",MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),MAG_6(1Rnd_HE_Grenade_shell)};
        backpack = "B_PTbskull_Veh_AT_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\7_hawkins.sqf';"
        };
    };

    class B_PTbskull_Veh_Sykes_blackops_01 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "08 Sykes (UAV) (R11)";
        side = 1;
        faction = "bskull_fc_mo";
        icon = "iconWomanEngineer";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Tactical_Clear"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Tactical_Clear"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Tactical_Clear"};
        weapons[] = {"B_PTbskull_Wea_ar_3","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_3","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_20(JAS_RSASS_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_20(JAS_RSASS_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_UAV_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\8_sykes.sqf';"
        };
    };

    class B_PTbskull_Veh_Everett_blackops_01 : B_Recon_Sharpshooter_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "09 Everett (Sniper) (Falkor)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Nato","LanguageENGB_F",EVERETT_GOGGLES};
        uniformClass = "U_B_FullGhillie_sard";
        linkedItems[] = {"V_SSU_Carrier_Lite_M81",EVERETT_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,EVERETT_GOGGLES};
        respawnlinkedItems[] = {"V_SSU_Carrier_Lite_M81",EVERETT_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,EVERETT_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_sniper_3",DEFAULT_HANDGUN,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_3",DEFAULT_HANDGUN,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_4(DEFAULT_HANDGUN_AMMO),MAG_17(10Rnd_300WM_Magazine),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(DEFAULT_HANDGUN_AMMO),MAG_17(10Rnd_300WM_Magazine),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_SNIPER_blackops_03";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\9_everett.sqf';"
        };
    };

    class B_PTbskull_Veh_Everett_blackops_02 : B_Recon_Sharpshooter_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "09 Everett (Sniper) (DSR50)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Nato","LanguageENGB_F",EVERETT_GOGGLES};
        uniformClass = "U_B_FullGhillie_sard";
        linkedItems[] = {"V_SSU_Carrier_Lite_M81",EVERETT_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,EVERETT_GOGGLES};
        respawnlinkedItems[] = {"V_SSU_Carrier_Lite_M81",EVERETT_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,EVERETT_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_sniper_9",DEFAULT_HANDGUN,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_9",DEFAULT_HANDGUN,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_4(DEFAULT_HANDGUN_AMMO),MAG_7(KA_DSR50_3Rnd_x2_M33_FMJ_Mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(DEFAULT_HANDGUN_AMMO),MAG_7(KA_DSR50_3Rnd_x2_M33_FMJ_Mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_SNIPER_blackops_04";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\9_everett.sqf';"
        };
    };

    class B_PTbskull_Veh_Taylor_blackops_02 : B_recon_LAT_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "10 Taylor (AA Titan) (SCAR-H)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Nato","LanguageENG_F","G_SSU_Balaclava_TI_G_Black"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Balaclava_TI_G_Black"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Balaclava_TI_G_Black"};
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_04",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_04",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_15(DEFAULT_AR_AMMO),"Titan_AA"};
        respawnMagazines[] = {MAG_15(DEFAULT_AR_AMMO),"Titan_AA"};
        backpack = "B_PTbskull_Veh_AA_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\10_taylor.sqf';"
        };
    };

    class B_PTbskull_Veh_Liu_blackops_01 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "11 Liu (Viper) (Cyrus 9.3mm)";
        side = 1;
        faction = "bskull_fc_mo";
        armor = 6;
        icon = "iconManRecon";
        identityTypes[] = {"Head_TCGM_Girls_Asian"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Special_Purpose_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Special_Purpose_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch"};
        weapons[] = {"B_PTbskull_Wea_sniper_10",DEFAULT_HANDGUN,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_10",DEFAULT_HANDGUN,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_4(DEFAULT_HANDGUN_AMMO),MAG_11(10Rnd_93x64_DMR_05_Mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(DEFAULT_HANDGUN_AMMO),MAG_11(10Rnd_93x64_DMR_05_Mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_VIPERCHN_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\11_liu.sqf';"
        };
    };

    class B_PTbskull_Veh_Liu_blackops_02 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "11 Liu (Viper) (Type 115 6.5mm + .50 BW)";
        side = 1;
        faction = "bskull_fc_mo";
        armor = 6;
        icon = "iconManRecon";
        identityTypes[] = {"Head_TCGM_Girls_Asian"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Special_Purpose_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Special_Purpose_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch"};
        weapons[] = {"B_PTbskull_Wea_ar_9","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_9","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_11(30Rnd_65x39_caseless_green_mag_Tracer),MAG_5(10Rnd_50BW_Mag_F),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_11(30Rnd_65x39_caseless_green_mag_Tracer),MAG_5(10Rnd_50BW_Mag_F),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_VIPERCHN_blackops_02";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\11_liu.sqf';"
        };
    };

    class B_PTbskull_Veh_Makarova_blackops_01 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "12 Makarova (RPK-12)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",MAKAROVA_GOGGLES};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,MAKAROVA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MAKAROVA_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,MAKAROVA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MAKAROVA_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_mg_3","B_PTbskull_Wea_law_03","B_PTbskull_Wea_pistol_4",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_3","B_PTbskull_Wea_law_03","B_PTbskull_Wea_pistol_4",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_11(B_PTbskull_Wea_mg_3_AMMO),MAG_4(B_PTbskull_Wea_pistol_4_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(MiniGrenade),MAG_2(SmokeShell)};
        respawnMagazines[] = {MAG_11(B_PTbskull_Wea_mg_3_AMMO),MAG_4(B_PTbskull_Wea_pistol_4_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(MiniGrenade),MAG_2(SmokeShell)};
        // no backpack
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\12_makarova.sqf';"
        };
    };

    class B_PTbskull_Veh_Elias_blackops_01 : B_soldier_UAV_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "13 Elias (UAV, NO THERM SIG) (SIG716)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Greek","LanguageENG_F",DEFAULT_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Cap_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,DEFAULT_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Cap_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,DEFAULT_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_br_1",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_br_1",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_9(kt_20Rnd_65_Creedmoor_108gr_AP_mag)};
        respawnMagazines[] = {MAG_9(kt_20Rnd_65_Creedmoor_108gr_AP_mag)};
        backpack = "B_PTbskull_Veh_UAV_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\13_elias.sqf';"
        };
    };

    class B_PTbskull_Veh_Elias_blackops_02 : B_soldier_UAV_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "13 Elias (UAV) (SCAR-H)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Greek","LanguageENG_F","G_Squares_Tinted"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Cap_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Squares_Tinted"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Cap_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Squares_Tinted"};
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_15(DEFAULT_AR_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_15(DEFAULT_AR_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_UAV_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\13_elias.sqf';"
        };
    };

    class B_PTbskull_Veh_Martinez_blackops_01 : B_Recon_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "14 Martinez (Ammo) (SIG716)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TK","LanguageENG_F","G_Spectacles_Tinted"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_Hat_Safari_sand_F","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Spectacles_Tinted"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_Hat_Safari_sand_F","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Spectacles_Tinted"};
        weapons[] = {"B_PTbskull_Wea_br_1","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_br_1","B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_9(kt_20Rnd_65_Creedmoor_108gr_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_9(kt_20Rnd_65_Creedmoor_108gr_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_AMMO_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\14_martinez.sqf';"
        };
    };

    class B_PTbskull_Veh_Martinez_blackops_02 : B_Recon_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "14 Martinez (Ammo) (SCAR-H)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TK","LanguageENG_F","G_Spectacles_Tinted"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_Hat_Safari_sand_F","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Spectacles_Tinted"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_Hat_Safari_sand_F","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Spectacles_Tinted"};
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_15(DEFAULT_AR_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_15(DEFAULT_AR_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_AMMO_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\14_martinez.sqf';"
        };
    };

    // JUNGLE

    // Units

    // class B_PTbskull_Veh_Viper_jungleops_01 : B_PTbskull_Veh_Viper_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J01 Viper (TL) (SIG716 + AXMC)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,VIPER_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,VIPER_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Viper_jungleops_02 : B_PTbskull_Veh_Viper_blackops_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J01 Viper (TL) (HB300AAC + WA2000)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,VIPER_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,VIPER_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Viper_jungleops_03 : B_PTbskull_Veh_Viper_blackops_03
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J01 Viper (TL) (SCAR-H GL + M110)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,VIPER_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,VIPER_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Fox_jungleops_01 : B_PTbskull_Veh_Fox_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J02 Fox (Medic) (SIG716)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",FOX_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_GIRLS_J;
    //     linkedItems[] = {DEFAULT_VEST_J,FOX_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,FOX_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Fox_jungleops_02 : B_PTbskull_Veh_Fox_blackops_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J02 Fox (Medic) (HB300AAC)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",FOX_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_GIRLS_J;
    //     linkedItems[] = {DEFAULT_VEST_J,FOX_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,FOX_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Fox_jungleops_03 : B_PTbskull_Veh_Fox_blackops_03
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J02 Fox (Medic) (SCAR-H)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",FOX_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_GIRLS_J;
    //     linkedItems[] = {DEFAULT_VEST_J,FOX_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,FOX_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_McKendrick_jungleops_01 : B_PTbskull_Veh_McKendrick_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J04 McKendrick (Demo) (SIG716)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_Enoch","LanguageENGB_F",MCKENDRICK_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,MCKENDRICK_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,MCKENDRICK_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_McKendrick_jungleops_02 : B_PTbskull_Veh_McKendrick_blackops_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J04 McKendrick (Demo) (HB300AAC)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_Enoch","LanguageENGB_F",MCKENDRICK_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,MCKENDRICK_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,MCKENDRICK_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_McKendrick_jungleops_03 : B_PTbskull_Veh_McKendrick_blackops_03
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J04 McKendrick (Demo) (SCAR-H)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_Enoch","LanguageENGB_F",MCKENDRICK_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,MCKENDRICK_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,MCKENDRICK_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Jackson_jungleops_01 : B_PTbskull_Veh_Jackson_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J05 Jackson (Medic) (R11)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",JACKSON_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_GIRLS_J;
    //     linkedItems[] = {DEFAULT_VEST_J,JACKSON_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,JACKSON_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,JACKSON_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,JACKSON_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Jackson_jungleops_02 : B_PTbskull_Veh_Jackson_blackops_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J05 Jackson (Medic) (SCAR-H)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",JACKSON_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_GIRLS_J;
    //     linkedItems[] = {DEFAULT_VEST_J,JACKSON_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,JACKSON_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,JACKSON_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,JACKSON_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Frost_jungleops_01 : B_PTbskull_Veh_Frost_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J06 Frost (SPMG338)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_NATO","LanguageENGFRE_F",FROST_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,FROST_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FROST_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,FROST_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FROST_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Frost_jungleops_02 : B_PTbskull_Veh_Frost_blackops_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J06 Frost (Navid9.3)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_NATO","LanguageENGFRE_F",FROST_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,FROST_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FROST_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,FROST_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FROST_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Hawkins_jungleops_01 : B_PTbskull_Veh_Hawkins_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J07 Hawkins (AT) (SIG716)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_NATO","LanguageENG_F",HAWKINS_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,HAWKINS_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,HAWKINS_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,HAWKINS_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,HAWKINS_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Hawkins_jungleops_02 : B_recon_LAT_F_OCimport_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J07 Hawkins (AT) (SCAR-H GL)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_NATO","LanguageENG_F",HAWKINS_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,HAWKINS_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,HAWKINS_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,HAWKINS_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,HAWKINS_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Sykes_jungleops_01 : B_PTbskull_Veh_Sykes_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J08 Sykes (UAV) (R11)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",SYKES_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_GIRLS_J;
    //     linkedItems[] = {DEFAULT_VEST_J,SYKES_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,SYKES_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,SYKES_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,SYKES_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Taylor_jungleops_01 : B_PTbskull_Veh_Taylor_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J10 Taylor (AA Stinger) (SCAR-H)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_Nato","LanguageENG_F",TAYLOR_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,TAYLOR_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,TAYLOR_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,TAYLOR_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,TAYLOR_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Taylor_jungleops_02 : B_PTbskull_Veh_Taylor_blackops_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J10 Taylor (AA Titan) (SCAR-H)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_Nato","LanguageENG_F",TAYLOR_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,TAYLOR_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,TAYLOR_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,TAYLOR_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,TAYLOR_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Liu_jungleops_01 : B_PTbskull_Veh_Liu_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J11 Liu (Viper) (Cyrus 9.3mm)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TCGM_Girls_Asian",LIU_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_GIRLS_J;
    //     linkedItems[] = {DEFAULT_VEST_J,LIU_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",LIU_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,LIU_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",LIU_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Liu_jungleops_02 : B_PTbskull_Veh_Liu_blackops_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J11 Liu (Viper) (Type 115 6.5mm + .50 BW)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TCGM_Girls_Asian",LIU_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_GIRLS_J;
    //     linkedItems[] = {DEFAULT_VEST_J,LIU_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",LIU_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,LIU_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",LIU_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Makarova_jungleops_01 : B_PTbskull_Veh_Makarova_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J12 Makarova (VS-121)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",MAKAROVA_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_GIRLS_J;
    //     linkedItems[] = {DEFAULT_VEST_J,MAKAROVA_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MAKAROVA_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,MAKAROVA_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MAKAROVA_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Elias_jungleops_01 : B_PTbskull_Veh_Elias_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J13 Elias (UAV) (SIG716)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_Greek","LanguageENG_F",ELIAS_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST,ELIAS_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,ELIAS_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST,ELIAS_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,ELIAS_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Elias_jungleops_02 : B_PTbskull_Veh_Elias_blackops_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J13 Elias (UAV) (SCAR-H)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_Greek","LanguageENG_F",ELIAS_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST,ELIAS_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,ELIAS_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST,ELIAS_HELMET_J,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,ELIAS_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Martinez_jungleops_01 : B_PTbskull_Veh_Martinez_blackops_01
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J14 Martinez (Ammo) (SIG716)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TK","LanguageENG_F",MARTINEZ_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,MARTINEZ_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MARTINEZ_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,MARTINEZ_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MARTINEZ_GOGGLES_J};
    // };

    // class B_PTbskull_Veh_Martinez_jungleops_02 : B_PTbskull_Veh_Martinez_blackops_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "J14 Martinez (Ammo) (SCAR-H)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     identityTypes[] = {"Head_TK","LanguageENG_F",MARTINEZ_GOGGLES_J};
    //     uniformClass = DEFAULT_UNIFORM_J;
    //     linkedItems[] = {DEFAULT_VEST_J,MARTINEZ_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MARTINEZ_GOGGLES_J};
    //     respawnlinkedItems[] = {DEFAULT_VEST_J,MARTINEZ_HELMET_J,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MARTINEZ_GOGGLES_J};
    // };


    // Support Units

    class B_PTbskull_Veh_Plane_Pilot_blackops_01 : B_Fighter_Pilot_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Plane Pilot";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_PilotHelmetFighter_B","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch","G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_PilotHelmetFighter_B","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch","G_Aviator"};
        weapons[] = {"B_PTbskull_Wea_SMG_01",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_01",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_6(30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_6(30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        backpack = "B_Parachute";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\100_plane-pilot.sqf';"
        };
    };

    class B_PTbskull_Veh_Helo_Pilot_blackops_01 : B_Helipilot_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Helo Pilot";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_PilotHelmetHeli_B","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_PilotHelmetHeli_B","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        weapons[] = {"B_PTbskull_Wea_SMG_01",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_01",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_6(30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_6(30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        backpack = "B_Parachute";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\200_helo-pilot.sqf';"
        };
    };

    class B_PTbskull_Veh_Helo_Crew_blackops_01 : B_helicrew_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Helo Crew";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_NATO_pilot"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Heli_Crew_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Heli_Crew_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG};
        weapons[] = {"B_PTbskull_Wea_SMG_01",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_01",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_6(30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_6(30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        backpack = "B_Parachute";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\204_helo-crew.sqf';"
        };
    };

    class B_PTbskull_Veh_Tank_Crew_blackops_01 : B_crew_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Tank Crew";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_NATO_default"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_Tank_eaf_F","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_Tank_eaf_F","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG};
        weapons[] = {"B_PTbskull_Wea_SMG_01",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_01",DEFAULT_BINOCULARS,"Throw","Put"};
         items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_6(30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_6(30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\300_tank-crew.sqf';"
        };
    };

    class B_PTbskull_Veh_Boat_Crew_blackops_01 : B_crew_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Boat Crew";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Cap_HS_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Cap_HS_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        weapons[] = {"B_PTbskull_Wea_ar_3",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_3",DEFAULT_BINOCULARS,"Throw","Put"};
            items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_12(JAS_RSASS_20rnd_M62_Tracer_Red_mag),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_12(JAS_RSASS_20rnd_M62_Tracer_Red_mag),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\400_boat-crew.sqf';"
        };
    };

    class B_PTbskull_Veh_Vehicle_Crew_blackops_01 : B_crew_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Vehicle Crew";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_Lowprofile"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Combat_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Lowprofile"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Combat_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Lowprofile"};
        weapons[] = {"B_PTbskull_Wea_SMG_02",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02",DEFAULT_BINOCULARS,"Throw","Put"};
         items[] = {MAG_5(FirstAidKit)};
        respawnItems[] = {MAG_5(FirstAidKit)};
        magazines[] = {MAG_12(30Rnd_9x21_Mag_SMG_02_Tracer_Green),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_12(30Rnd_9x21_Mag_SMG_02_Tracer_Green),MAG_2(SmokeShell),"SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue",MAG_2(MiniGrenade)};
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\500_vehicle-crew.sqf';"
        };
    };

    class B_Assaultpack_blk;
    class B_PTbskull_Veh_Backpack_blackops_01 : B_Assaultpack_blk {
        scope = 1;
        mass = 1;
        maximumLoad = 1500;
    };

    class B_PTbskull_Veh_TL_blackops_01: B_PTbskull_Veh_Backpack_blackops_01 {
        class TransportMagazines {
            class _xx_B_PTbskull_Wea_sniper_6_AMMO {count=10;magazine=B_PTbskull_Wea_sniper_6_AMMO;};
            class _xx_HandGrenade {count=4;magazine="HandGrenade";};
            class _xx_MiniGrenade {count=4;magazine="MiniGrenade";};
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=4;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=2;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=2;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};

        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_6 {count=1;weapon="B_PTbskull_Wea_sniper_6";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
        };
    };

    class B_PTbskull_Veh_TL_blackops_02: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_KA_6Rnd_300win_Mag {count=12;magazine="KA_6Rnd_300win_Mag";};
            class _xx_HandGrenade {count=4;magazine="HandGrenade";};
            class _xx_MiniGrenade {count=4;magazine="MiniGrenade";};
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=4;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=2;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=2;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};
        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_8 {count=1;weapon="B_PTbskull_Wea_sniper_8";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
        };
    };

    class B_PTbskull_Veh_TL_blackops_03: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_kt_20Rnd_762x51_Ball_XM1158_AP_Mag {count=5;magazine="kt_20Rnd_762x51_Ball_XM1158_AP_Mag";};
            class _xx_HandGrenade {count=4;magazine="HandGrenade";};
            class _xx_MiniGrenade {count=4;magazine="MiniGrenade";};
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=4;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=2;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=2;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};
        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_1 {count=1;weapon="B_PTbskull_Wea_sniper_1";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
        };
    };

    class B_PTbskull_Veh_TL_blackops_05: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_HandGrenade {count=2;magazine="HandGrenade";};
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=2;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=1;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=1;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};
            class _xx_10Rnd_338_Mag {count=1;magazine="10Rnd_338_Mag";};
        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_12 {count=1;weapon="B_PTbskull_Wea_sniper_12";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
            class _xx_B_PTbskull_Wea_shotgun_2 {count=1;weapon="B_PTbskull_Wea_shotgun_2";};
        };
    };

    class B_PTbskull_Veh_MEDIC_blackops_01: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
        };
        class TransportItems {
            class _xx_Medikit {count=1;name="Medikit";};
            class _xx_FirstAidKit {count=10;name="FirstAidKit";};
        };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_SNIPER_blackops_01: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_B_PTbskull_Wea_sniper_6_AMMO {count=10;magazine=B_PTbskull_Wea_sniper_6_AMMO;};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_SNIPER_blackops_02: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_KA_CS5_10rnd_M993_AP_mag {count=10;magazine="KA_CS5_10rnd_M993_AP_mag";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_EXP_blackops_01: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
        };
        class TransportItems {
            class _xx_MineDetector {count=1;name="MineDetector";};
            class _xx_ToolKit {count=1;name="ToolKit";};
            class _xx_DemoCharge_Remote_Mag {count=2;name="DemoCharge_Remote_Mag";};
            class _xx_SatchelCharge_Remote_Mag {count=2;name="SatchelCharge_Remote_Mag";};
            class _xx_ATMine_Range_Mag {count=1;name="ATMine_Range_Mag";};
        };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_MG_blackops_01: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_130Rnd_338_Mag {count=1;magazine="130Rnd_338_Mag";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_MG_blackops_02: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_150Rnd_93x64_Mag {count=1;magazine="150Rnd_93x64_Mag";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

   class B_PTbskull_Veh_AT_blackops_01: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_Titan_AT_PLUS {count=4;magazine="Titan_AT_PLUS";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

   class B_PTbskull_Veh_AMMO_blackops_01: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_Titan_AT_PLUS {count=2;magazine="Titan_AT_PLUS";};
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_HandGrenade {count=2;magazine="HandGrenade";};
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_KA_SCAR_H_20rnd_M993_AP_mag {count=6;magazine="KA_SCAR_H_20rnd_M993_AP_mag";};
            class _xx_hlc_50rnd_300BLK_STANAG_EPR {count=6;magazine="hlc_50rnd_300BLK_STANAG_EPR";};
            class _xx_kt_20Rnd_65_Creedmoor_108gr_AP_mag {count=6;magazine="kt_20Rnd_65_Creedmoor_108gr_AP_mag";};
            class _xx_JAS_RSASS_20rnd_M993_AP_mag {count=2;magazine="JAS_RSASS_20rnd_M993_AP_mag";};
            class _xx_kt_20Rnd_762x51_Ball_XM1158_AP_Mag {count=2;magazine="kt_20Rnd_762x51_Ball_XM1158_AP_Mag";};
            class _xx_B_PTbskull_Wea_sniper_6_AMMO {count=2;magazine=B_PTbskull_Wea_sniper_6_AMMO;};
            class _xx_KA_CS5_10rnd_M993_AP_mag {count=2;magazine="KA_CS5_10rnd_M993_AP_mag";};
            class _xx_10Rnd_300WM_Magazine {count=2;magazine="10Rnd_300WM_Magazine";};
            class _xx_KA_DSR50_3Rnd_x2_M33_FMJ_Mag {count=2;magazine="KA_DSR50_3Rnd_x2_M33_FMJ_Mag";};
            class _xx_150Rnd_93x64_Mag {count=1;magazine="150Rnd_93x64_Mag";};
            class _xx_130Rnd_338_Mag {count=1;magazine="130Rnd_338_Mag";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_SNIPER_blackops_03: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_10Rnd_300WM_Magazine {count=7;magazine="10Rnd_300WM_Magazine";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_SNIPER_blackops_04: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_KA_DSR50_3Rnd_x2_M33_FMJ_Mag {count=10;magazine="KA_DSR50_3Rnd_x2_M33_FMJ_Mag";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_AA_blackops_01: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_Titan_AA {count=4;magazine="Titan_AA";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_BACKUP_blackops_01: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_kt_20Rnd_65_Creedmoor_108gr_AP_mag {count=5;magazine="kt_20Rnd_65_Creedmoor_108gr_AP_mag";};
        };
        class TransportItems {
            class _xx_FirstAidKit {count=5;name="FirstAidKit";};
            class _xx_DEFAULT_UNIFORM {count=1;name=DEFAULT_UNIFORM;};
            class _xx_DEFAULT_VEST {count=1;name=DEFAULT_VEST;};
            class _xx_DEFAULT_HELMET {count=1;name=DEFAULT_HELMET;};
            class _xx_DEFAULT_NVG {count=1;name=DEFAULT_NVG;};
            class _xx_DEFAULT_BINOCULARS {count=1;name=DEFAULT_BINOCULARS;};
        };
        class TransportWeapons {
            class _xx_B_PTbskull_Wea_br_1 {count=1;weapon="B_PTbskull_Wea_br_1";};
        };
    };

    class B_PTbskull_Veh_VIPERCHN_blackops_01: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_10Rnd_93x64_DMR_05_Mag {count=10;magazine="10Rnd_93x64_DMR_05_Mag";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_VIPERCHN_blackops_02: B_PTbskull_Veh_Backpack_blackops_01
    {
        class TransportMagazines {
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_30Rnd_65x39_caseless_green_mag_Tracer {count=5;magazine="30Rnd_65x39_caseless_green_mag_Tracer";};
            class _xx_10Rnd_50BW_Mag_F {count=5;magazine="10Rnd_50BW_Mag_F";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_UAV_01_backpack_F;
    class B_UAV_01_backpack_F_OCimport_01 : B_UAV_01_backpack_F { scope = 0; class assembleInfo; }
    class B_PTbskull_Veh_UAV_blackops_01 : B_UAV_01_backpack_F_OCimport_01 {
            scope = 1;
            mass = 1;
            class assembleInfo : assembleInfo {
                assembleTo = "B_PTbskull_Veh_Drone_blackops_03";
                displayName = "AR-2 BSkull";
            };
    };
};
