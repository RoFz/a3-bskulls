#include "symbols.hpp"
#include "CfgWeapons.hpp"

// class Turrets;
// class MainTurret;

class CfgVehicles
{
    class EventHandlers;


    // Base Vehicles
    class B_Plane_CAS_01_dynamicLoadout_F;
    class B_Plane_CAS_01_dynamicLoadout_F_OCimport_01 : B_Plane_CAS_01_dynamicLoadout_F { scope = 0; };
    class B_Plane_CAS_01_dynamicLoadout_F_OCimport_02 : B_Plane_CAS_01_dynamicLoadout_F_OCimport_01 { scope = 0; };

    class B_UGV_01_rcws_F;
    class B_UGV_01_rcws_F_OCimport_01 : B_UGV_01_rcws_F { scope = 0; class Turrets; };
    class B_UGV_01_rcws_F_OCimport_02 : B_UGV_01_rcws_F_OCimport_01
    {
       
        class Turrets : Turrets
        {
            class MainTurret;
            class CargoTurret_01;
        };
    };

    class B_Heli_Transport_03_F;
    class B_Heli_Transport_03_F_OCimport_01 : B_Heli_Transport_03_F { scope = 0; class Turrets; };
    class B_Heli_Transport_03_F_OCimport_02 : B_Heli_Transport_03_F_OCimport_01
    {
       
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

    class B_Heli_Light_01_F;
    class B_Heli_Light_01_F_OCimport_01 : B_Heli_Light_01_F { scope = 0; class Turrets; };
    class B_Heli_Light_01_F_OCimport_02 : B_Heli_Light_01_F_OCimport_01 {
       
        class Turrets : Turrets {
            class CopilotTurret;
            class CargoTurret_01;
            class CargoTurret_02;
            class CargoTurret_03;
            class CargoTurret_04;
        };
    };

    class B_Heli_Attack_01_dynamicLoadout_F;
    class B_Heli_Attack_01_dynamicLoadout_F_OCimport_01 : B_Heli_Attack_01_dynamicLoadout_F { scope = 0; class Turrets; class Components;};
    class B_Heli_Attack_01_dynamicLoadout_F_OCimport_02 : B_Heli_Attack_01_dynamicLoadout_F_OCimport_01 {
       
        class Components : Components {
            class TransportPylonsComponent;
        };
        class Turrets : Turrets {
            class MainTurret;
        };
    };

    class B_Heli_Light_01_dynamicLoadout_F;
    class B_Heli_Light_01_dynamicLoadout_F_OCimport_01 : B_Heli_Light_01_dynamicLoadout_F { scope = 0; class Components;};
    class B_Heli_Light_01_dynamicLoadout_F_OCimport_02 : B_Heli_Light_01_dynamicLoadout_F_OCimport_01 {
       
        class Components : Components {
            class TransportPylonsComponent;
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
    class rhsusf_m1151_m2_v2_usarmy_wd_OCimport_02 : rhsusf_m1151_m2_v2_usarmy_wd_OCimport_01 {
       
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


    // Base Units

    class B_Fighter_Pilot_F;
    class B_Fighter_Pilot_F_OCimport_01 : B_Fighter_Pilot_F { scope = 0; };
    class B_Fighter_Pilot_F_OCimport_02 : B_Fighter_Pilot_F_OCimport_01
    {
       
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManOfficer";
    };

    class B_Helipilot_F;
    class B_Helipilot_F_OCimport_01 : B_Helipilot_F { scope = 0; };
    class B_Helipilot_F_OCimport_02 : B_Helipilot_F_OCimport_01
    {
       
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManLeader";
    };

    class B_helicrew_F;
    class B_helicrew_F_OCimport_01 : B_helicrew_F { scope = 0; };
    class B_helicrew_F_OCimport_02 : B_helicrew_F_OCimport_01
    {
       
        sensitivity = 9;
        sensitivityEar = 3;
    };

    class B_crew_F;
    class B_crew_F_OCimport_01 : B_crew_F { scope = 0; };
    class B_crew_F_OCimport_02 : B_crew_F_OCimport_01
    {
       
        sensitivity = 9;
        sensitivityEar = 3;
    };

    class B_recon_TL_F;
    class B_recon_TL_F_OCimport_01 : B_recon_TL_F { scope = 0; };
    class B_recon_TL_F_OCimport_02 : B_recon_TL_F_OCimport_01
    {
       
        camouflage = 0.9;
        sensitivity = 9;
        sensitivityEar = 3;
		canDeactivateMines = 1;
		engineer = 1;
        uavHacker = 1;
        // attendant = 1;
        icon = "iconManLeader";
    };

    class TCGM_Stealth_B_CTRG_Soldier_Medic;
    class TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_01 : TCGM_Stealth_B_CTRG_Soldier_Medic { scope = 0; };
    class TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_01
    {
       
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        camouflage = 0.5;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconWomanMedic";
    };

    class TCGM_Stealth_B_CTRG_Soldier_SC;
    class TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_01 : TCGM_Stealth_B_CTRG_Soldier_SC { scope = 0; };
    class TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_01
    {
       
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        camouflage = 0.9;
        sensitivity = 9;
        sensitivityEar = 3;
    };

    // Does not work - uniform never loads while in DRO!
    // class TCGM_Viper_O_m_GHex_Soldier;
    // class TCGM_Viper_O_m_GHex_Soldier_OCimport_01 : TCGM_Viper_O_m_GHex_Soldier { scope = 0; };
    // class TCGM_Viper_O_m_GHex_Soldier_OCimport_02 : TCGM_Viper_O_m_GHex_Soldier_OCimport_01
    // {
    //    
    //     editorSubcategory="EdSubcat_Personnel_SpecialForces";
    //     camouflage = 0.1;
    //     audible = 0.01;
    //     sensitivity = 90;
    //     sensitivityEar = 3;
    //     icon = "iconWomanRecon";
    // };

    class B_Recon_Sharpshooter_F;
    class B_Recon_Sharpshooter_F_OCimport_01 : B_Recon_Sharpshooter_F { scope = 0; };
    class B_Recon_Sharpshooter_F_OCimport_02 : B_Recon_Sharpshooter_F_OCimport_01
    {
       
        camouflage = 0.1;
        audible = 0.01;
        sensitivity = 90;
        sensitivityEar = 3;
        icon = "iconManRecon";
    };

    class B_recon_exp_F;
    class B_recon_exp_F_OCimport_01 : B_recon_exp_F { scope = 0; };
    class B_recon_exp_F_OCimport_02 : B_recon_exp_F_OCimport_01
    {
       
        camouflage = 0.5;
        sensitivity = 9;
        sensitivityEar = 3;
		canDeactivateMines = 1;
		engineer = 1;
        icon = "iconManExplosive";
    };

    class B_Patrol_HeavyGunner_F;
    class B_Patrol_HeavyGunner_F_OCimport_01 : B_Patrol_HeavyGunner_F { scope = 0; };
    class B_Patrol_HeavyGunner_F_OCimport_02 : B_Patrol_HeavyGunner_F_OCimport_01
    {
       
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        camouflage = 0.9;
        audible = 0.06;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManMG";
    };

    class B_recon_LAT_F;
    class B_recon_LAT_F_OCimport_01 : B_recon_LAT_F { scope = 0; };
    class B_recon_LAT_F_OCimport_02 : B_recon_LAT_F_OCimport_01
    {
       
        camouflage = 0.9;
        audible = 0.06;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManAT";
    };

    class B_Recon_F;
    class B_Recon_F_OCimport_01 : B_Recon_F { scope = 0; };
    class B_Recon_F_OCimport_02 : B_Recon_F_OCimport_01
    {
       
        camouflage = 0.5;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManRecon";
    };

    class B_soldier_UAV_F;
    class B_soldier_UAV_F_OCimport_01 : B_soldier_UAV_F { scope = 0; };
    class B_soldier_UAV_F_OCimport_02 : B_soldier_UAV_F_OCimport_01
    {
       
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        camouflage = 0.9; // Medic,Exp,Ammo = 0.5; Sniper = 0.1; TL,AT,UAV,MG = 0.9;
        audible = 0.06; // Sniper = 0.01; AT,UAV,MG = 0.06
        sensitivity = 9;
        sensitivityEar = 3;
		engineer = 1;
        uavHacker = 1;
        icon = "iconManEngineer";
    };

    class B_UAV_AI;
    class B_UAV_AI_OCimport_01 : B_UAV_AI { scope = 0; };
    class B_PTbskull_Veh_UAV_AI_AIR : B_UAV_AI_OCimport_01
    {
        // inheritsFrom(configfile >> "CfgVehicles" >> "B_UAV_AI") = bin\config.bin/CfgVehicles/B_Helipilot_F
        // inheritsFrom(configfile >> "CfgVehicles" >> "B_Helipilot_F") = bin\config.bin/CfgVehicles/B_Soldier_04_f
        // inheritsFrom(configfile >> "CfgVehicles" >> "B_Soldier_04_f") = bin\config.bin/CfgVehicles/B_Soldier_base_F
        // inheritsFrom(configfile >> "CfgVehicles" >> "B_Soldier_base_F") = bin\config.bin/CfgVehicles/SoldierWB
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

