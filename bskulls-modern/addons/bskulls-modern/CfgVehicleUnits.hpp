
    // ── Unit Base Classes ────────────────────────────────────────────────────

    class B_recon_TL_F;
    class B_recon_TL_F_OCimport_01 : B_recon_TL_F { scope = 0; class EventHandlers; };
    class B_recon_TL_F_OCimport_02 : B_recon_TL_F_OCimport_01
    {
        camouflage = 0.9;
        sensitivity = 9;
        sensitivityEar = 3;
        canDeactivateMines = 1;
        engineer = 1;
        uavHacker = 1;
        icon = "iconManLeader";
    };

    class TCGM_Stealth_B_CTRG_Soldier_Medic;
    class TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_01 : TCGM_Stealth_B_CTRG_Soldier_Medic { scope = 0; class EventHandlers; };
    class TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_01
    {
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
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        camouflage = 0.9;
        sensitivity = 9;
        sensitivityEar = 3;
    };

    class B_Recon_Sharpshooter_F;
    class B_Recon_Sharpshooter_F_OCimport_01 : B_Recon_Sharpshooter_F { scope = 0; class EventHandlers; };
    class B_Recon_Sharpshooter_F_OCimport_02 : B_Recon_Sharpshooter_F_OCimport_01
    {
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
        camouflage = 0.5;
        sensitivity = 9;
        sensitivityEar = 3;
        canDeactivateMines = 1;
        engineer = 1;
        icon = "iconManExplosive";
    };

    class B_Patrol_HeavyGunner_F;
    class B_Patrol_HeavyGunner_F_OCimport_01 : B_Patrol_HeavyGunner_F { scope = 0; class EventHandlers; };
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
    class B_recon_LAT_F_OCimport_01 : B_recon_LAT_F { scope = 0; class EventHandlers; };
    class B_recon_LAT_F_OCimport_02 : B_recon_LAT_F_OCimport_01
    {
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
        camouflage = 0.5;
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManRecon";
    };

    class B_soldier_UAV_F;
    class B_soldier_UAV_F_OCimport_01 : B_soldier_UAV_F { scope = 0; class EventHandlers; };
    class B_soldier_UAV_F_OCimport_02 : B_soldier_UAV_F_OCimport_01
    {
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        camouflage = 0.9;
        audible = 0.06;
        sensitivity = 9;
        sensitivityEar = 3;
        engineer = 1;
        uavHacker = 1;
        icon = "iconManEngineer";
    };

#include "CfgVehicleBaseClasses.hpp"

    // ── Units ────────────────────────────────────────────────────────────────

    class B_PTbskull_Veh_Unit_Viper_blackops_00 : B_PTbskull_Veh_Unit_Viper_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (HB300AAC + Benelli + VSSK)";
        weapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_9(hlc_50rnd_300BLK_STANAG_EPR),MAG_20(B_PTbskull_Wea_sniper_05_vssk_AMMO),MAG_6(B_PTbskull_Wea_shotgun_3_benelli_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade),"KA_M14","KA_M7290","KA_M7A3","KA_M814"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_9(hlc_50rnd_300BLK_STANAG_EPR),MAG_20(B_PTbskull_Wea_sniper_05_vssk_AMMO),MAG_6(B_PTbskull_Wea_shotgun_3_benelli_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade),"KA_M14","KA_M7290","KA_M7A3","KA_M814"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_06";
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_01 : B_PTbskull_Veh_Unit_Viper_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (HB300AAC + Benelli + ASP-2)";
        weapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_9(hlc_50rnd_300BLK_STANAG_EPR),MAG_10(B_PTbskull_Wea_sniper_06_asp1_AMMO),MAG_6(B_PTbskull_Wea_shotgun_3_benelli_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade),"KA_M14","KA_M7290","KA_M7A3","KA_M814"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_9(hlc_50rnd_300BLK_STANAG_EPR),MAG_10(B_PTbskull_Wea_sniper_06_asp1_AMMO),MAG_6(B_PTbskull_Wea_shotgun_3_benelli_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade),"KA_M14","KA_M7290","KA_M7A3","KA_M814"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_07";
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_02 : B_PTbskull_Veh_Unit_Viper_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (HB300AAC + SPAS + WA2000)";
        weapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_9(hlc_50rnd_300BLK_STANAG_EPR),MAG_5(B_PTbskull_Wea_shotgun_2_spas_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_9(hlc_50rnd_300BLK_STANAG_EPR),MAG_5(B_PTbskull_Wea_shotgun_2_spas_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_02";
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_03 : B_PTbskull_Veh_Unit_Viper_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (SCAR-H GL + SPAS + M110)";
        weapons[] = {"B_PTbskull_Wea_ar_04_scarh","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_04_scarh","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_13(KA_SCAR_H_20rnd_M993_AP_mag),MAG_10(B_PTbskull_Wea_sniper_01_m110_AMMO),MAG_5(1Rnd_HE_Grenade_shell),MAG_5(B_PTbskull_Wea_shotgun_2_spas_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_13(KA_SCAR_H_20rnd_M993_AP_mag),MAG_10(B_PTbskull_Wea_sniper_01_m110_AMMO),MAG_5(1Rnd_HE_Grenade_shell),MAG_5(B_PTbskull_Wea_shotgun_2_spas_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_03";
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_04 : B_PTbskull_Veh_Unit_Viper_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + SPAS + Falkor) (Ghillie, Jungle)";
        uniformClass = "U_B_T_FullGhillie_tna_F";
        LINKED_ITEMS_UAV("B_PTbskull_Vest_blackops_02",VIPER_HELMET,VIPER_GOGGLES);
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(B_PTbskull_Wea_SMG_02_sting_AMMO),MAG_10(B_PTbskull_Wea_sniper_03_falkor_AMMO),MAG_5(B_PTbskull_Wea_shotgun_2_spas_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(B_PTbskull_Wea_SMG_02_sting_AMMO),MAG_10(B_PTbskull_Wea_sniper_03_falkor_AMMO),MAG_5(B_PTbskull_Wea_shotgun_2_spas_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_05 : B_PTbskull_Veh_Unit_Viper_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + SPAS + MAR-10) (Ghillie, Jungle)";
        uniformClass = "U_B_T_FullGhillie_tna_F";
        LINKED_ITEMS_UAV("B_PTbskull_Vest_blackops_02",VIPER_HELMET,VIPER_GOGGLES);
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_SMG_02_sting_AMMO),MAG_20(10Rnd_338_Mag),MAG_5(B_PTbskull_Wea_shotgun_2_spas_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_SMG_02_sting_AMMO),MAG_20(10Rnd_338_Mag),MAG_5(B_PTbskull_Wea_shotgun_2_spas_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_05";
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_06 : B_PTbskull_Veh_Unit_Viper_blackops_04
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + SPAS + Falkor) (Ghillie, Semi-Arid)";
        uniformClass = "U_B_FullGhillie_sard";
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_07 : B_PTbskull_Veh_Unit_Viper_blackops_05
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + SPAS + MAR-10) (Ghillie, Arid)";
        uniformClass = "U_B_FullGhillie_ard";
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_08 : B_PTbskull_Veh_Unit_Viper_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + Benelli + M320) (Ghillie, Jungle)";
        uniformClass = "U_B_T_FullGhillie_tna_F";
        LINKED_ITEMS_UAV("B_PTbskull_Vest_blackops_02",VIPER_HELMET,VIPER_GOGGLES);
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(B_PTbskull_Wea_SMG_02_sting_AMMO),MAG_10(B_PTbskull_Wea_sniper_04_m320_AMMO),MAG_5(B_PTbskull_Wea_shotgun_3_benelli_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(B_PTbskull_Wea_SMG_02_sting_AMMO),MAG_10(B_PTbskull_Wea_sniper_04_m320_AMMO),MAG_5(B_PTbskull_Wea_shotgun_3_benelli_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_08";
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_09 : B_PTbskull_Veh_Unit_Viper_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (MR-C + Benelli + M320) (Ghillie, Semi-Arid)";
        uniformClass = "U_B_FullGhillie_sard";
        LINKED_ITEMS_UAV("B_PTbskull_Vest_blackops_02",VIPER_HELMET,VIPER_GOGGLES);
        weapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_5(B_PTbskull_Wea_ar_07_mrc_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),MAG_10(B_PTbskull_Wea_sniper_04_m320_AMMO),MAG_5(B_PTbskull_Wea_shotgun_3_benelli_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_5(B_PTbskull_Wea_ar_07_mrc_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),MAG_10(B_PTbskull_Wea_sniper_04_m320_AMMO),MAG_5(B_PTbskull_Wea_shotgun_3_benelli_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_08";
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_10 : B_PTbskull_Veh_Unit_Viper_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (XM-7 + SPAS + Falkor) (Ghillie, Jungle)";
        uniformClass = "U_B_T_FullGhillie_tna_F";
        LINKED_ITEMS_UAV("B_PTbskull_Vest_blackops_02",VIPER_HELMET,VIPER_GOGGLES);
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_10(B_PTbskull_Wea_sniper_03_falkor_AMMO),MAG_5(B_PTbskull_Wea_shotgun_2_spas_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_10(B_PTbskull_Wea_sniper_03_falkor_AMMO),MAG_5(B_PTbskull_Wea_shotgun_2_spas_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(HandGrenade),MAG_2(MiniGrenade)};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Fox_blackops_01 : B_PTbskull_Veh_Unit_Fox_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (Sting)";
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_20(B_PTbskull_Wea_SMG_02_sting_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_20(B_PTbskull_Wea_SMG_02_sting_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
    };


    class B_PTbskull_Veh_Unit_Fox_blackops_02 : B_PTbskull_Veh_Unit_Fox_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (HB300AAC)";
        weapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_6(hlc_50rnd_300BLK_STANAG_EPR),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_6(hlc_50rnd_300BLK_STANAG_EPR),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Fox_blackops_03 : B_PTbskull_Veh_Unit_Fox_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (SCAR-H)";
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Fox_blackops_04 : B_PTbskull_Veh_Unit_Fox_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (ASP-2)";
        weapons[] = {"B_PTbskull_Wea_sniper_06_asp1","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_06_asp1","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_20(B_PTbskull_Wea_sniper_06_asp1_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_20(B_PTbskull_Wea_sniper_06_asp1_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Fox_blackops_05 : B_PTbskull_Veh_Unit_Fox_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (MR-C)";
        weapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_07_mrc_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_07_mrc_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Fox_blackops_06 : B_PTbskull_Veh_Unit_Fox_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (XM-7)";
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Vega_blackops_01 : B_PTbskull_Veh_Unit_Vega_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "03 Vega (Sniper) (TRG-42)";
        weapons[] = {"B_PTbskull_Wea_sniper_02_trg42","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_02_trg42","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_24(B_PTbskull_Wea_sniper_02_trg42_AMMO),MAG_5(B_PTbskull_Wea_SMG_02_sting_AMMO)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_24(B_PTbskull_Wea_sniper_02_trg42_AMMO),MAG_5(B_PTbskull_Wea_SMG_02_sting_AMMO)};
        backpack = "B_PTbskull_Veh_Back_SNIPER_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Vega_blackops_02 : B_PTbskull_Veh_Unit_Vega_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "03 Vega (Sniper) (McMillan)";
        weapons[] = {"B_PTbskull_Wea_sniper_07_mcmillan","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_07_mcmillan","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_25(KA_CS5_10rnd_M993_AP_mag),MAG_5(B_PTbskull_Wea_SMG_02_sting_AMMO)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_25(KA_CS5_10rnd_M993_AP_mag),MAG_5(B_PTbskull_Wea_SMG_02_sting_AMMO)};
        backpack = "B_PTbskull_Veh_Back_SNIPER_blackops_02";
    };

    class B_PTbskull_Veh_Unit_Vega_blackops_03 : B_PTbskull_Veh_Unit_Vega_blackops_01
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "03 Vega (Sniper) (TRG-42) Semi-Arid";
        uniformClass = "U_B_FullGhillie_sard";
    };

    class B_PTbskull_Veh_Unit_Vega_blackops_04 : B_PTbskull_Veh_Unit_Vega_blackops_02
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "03 Vega (Sniper) (McMillan) Arid";
        uniformClass = "U_B_FullGhillie_ard";
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_01 : B_PTbskull_Veh_Unit_McKendrick_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (UAV) (Sting)";
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(B_PTbskull_Wea_SMG_02_sting_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(B_PTbskull_Wea_SMG_02_sting_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_02 : B_PTbskull_Veh_Unit_McKendrick_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (Demo) (HB300AAC)";
        weapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_6(hlc_50rnd_300BLK_STANAG_EPR),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_6(hlc_50rnd_300BLK_STANAG_EPR),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_EXP_blackops_01";
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_03 : B_PTbskull_Veh_Unit_McKendrick_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (Demo) (SCAR-H)";
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_EXP_blackops_01";
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_04 : B_PTbskull_Veh_Unit_McKendrick_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (UAV) (MR-C)";
        weapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_07_mrc_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_07_mrc_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_05 : B_PTbskull_Veh_Unit_McKendrick_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (UAV) (XM-250)";
        weapons[] = {"B_PTbskull_Wea_mg_04_xm250","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_04_xm250","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_5(B_PTbskull_Wea_mg_04_xm250_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_5(B_PTbskull_Wea_mg_04_xm250_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_06 : B_PTbskull_Veh_Unit_McKendrick_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (Demo) (XM-7)";
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(B_PTbskull_Wea_ar_08_xm7_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(B_PTbskull_Wea_ar_08_xm7_AMMO),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_EXP_blackops_01";
    };


    class B_PTbskull_Veh_Unit_Jackson_blackops_01 : B_PTbskull_Veh_Unit_Jackson_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "05 Jackson (Medic) (R11)";
        weapons[] = {"B_PTbskull_Wea_ar_02_r11","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_02_r11","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(JAS_RSASS_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(JAS_RSASS_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Jackson_blackops_02 : B_PTbskull_Veh_Unit_Jackson_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "05 Jackson (Medic) (SCAR-H)";
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Jackson_blackops_03 : B_PTbskull_Veh_Unit_Jackson_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "05 Jackson (Medic) (MR-C)";
        weapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_07_mrc_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_07_mrc_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Jackson_blackops_04 : B_PTbskull_Veh_Unit_Jackson_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "05 Jackson (Medic) (XM-7)";
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Frost_blackops_01 : B_PTbskull_Veh_Unit_Frost_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "06 Frost (SPMG338)";
        weapons[] = {"B_PTbskull_Wea_mg_01_smpg","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_01_smpg","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_5(130Rnd_338_Mag)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_5(130Rnd_338_Mag)};
        backpack = "B_PTbskull_Veh_Back_MG_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Frost_blackops_02 : B_PTbskull_Veh_Unit_Frost_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "06 Frost (Navid9.3)";
        weapons[] = {"B_PTbskull_Wea_mg_02_navid","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_02_navid","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_5(150Rnd_93x64_Mag)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_5(150Rnd_93x64_Mag)};
        backpack = "B_PTbskull_Veh_Back_MG_blackops_02";
    };

    class B_PTbskull_Veh_Unit_Frost_blackops_03 : B_PTbskull_Veh_Unit_Frost_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "06 Frost (Navid9.3 + Fuel)";
        weapons[] = {"B_PTbskull_Wea_mg_02_navid","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_02_navid","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_5(150Rnd_93x64_Mag)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_5(150Rnd_93x64_Mag)};
        backpack = "B_PTbskull_Veh_Back_Fuel_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Frost_blackops_04 : B_PTbskull_Veh_Unit_Frost_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "06 Frost (XM-250 + Fuel)";
        weapons[] = {"B_PTbskull_Wea_mg_04_xm250","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_04_xm250","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_8(B_PTbskull_Wea_mg_04_xm250_AMMO)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_8(B_PTbskull_Wea_mg_04_xm250_AMMO)};
        backpack = "B_PTbskull_Veh_Back_Fuel_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Hawkins_blackops_01 : B_PTbskull_Veh_Unit_Hawkins_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "07 Hawkins (AT) (SPAR-17)";
        weapons[] = {"B_PTbskull_Wea_ar_06_spar17","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_06_spar17","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),"Titan_AT_PLUS",MAG_15(20Rnd_762x51_Mag)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),"Titan_AT_PLUS",MAG_15(20Rnd_762x51_Mag)};
        backpack = "B_PTbskull_Veh_Back_AT_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Hawkins_blackops_02 : B_PTbskull_Veh_Unit_Hawkins_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "07 Hawkins (AT) (SCAR-H GL)";
        weapons[] = {"B_PTbskull_Wea_ar_04_scarh","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_04_scarh","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),"Titan_AT_PLUS",MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),MAG_6(1Rnd_HE_Grenade_shell),MAG_3(UGL_FlareWhite_Illumination_F)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),"Titan_AT_PLUS",MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),MAG_6(1Rnd_HE_Grenade_shell),MAG_3(UGL_FlareWhite_Illumination_F)};
        backpack = "B_PTbskull_Veh_Back_AT_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Hawkins_blackops_03 : B_PTbskull_Veh_Unit_Hawkins_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "07 Hawkins (AT) (XM-7)";
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),"Titan_AT_PLUS",MAG_15(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_6(1Rnd_HE_Grenade_shell)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),"Titan_AT_PLUS",MAG_15(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_6(1Rnd_HE_Grenade_shell)};
        backpack = "B_PTbskull_Veh_Back_AT_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Sykes_blackops_01 : B_PTbskull_Veh_Unit_Sykes_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "08 Sykes (UAV) (R11)";
        weapons[] = {"B_PTbskull_Wea_ar_02_r11","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_02_r11","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_20(JAS_RSASS_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_20(JAS_RSASS_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Sykes_blackops_02 : B_PTbskull_Veh_Unit_Sykes_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "08 Sykes (UAV) (MR-C)";
        weapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_07_mrc_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_07_mrc_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Sykes_blackops_03 : B_PTbskull_Veh_Unit_Sykes_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "08 Sykes (UAV) (XM-7)";
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Sykes_blackops_04 : B_PTbskull_Veh_Unit_Sykes_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "08 Sykes (AIMS) (XM-7)";
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_10(B_PTbskull_Wea_ar_08_xm7_AMMO),MAG_3(3Rnd_HE_Grenade_shell),MAG_3(KA_40mm_M814),MAG_3(KA_40mm_M14),MAG_3(1Rnd_Flechette_Cartridge_Grenade_shell),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_KA_Metal_Storm_AI_NATO";
    };

    class B_PTbskull_Veh_Unit_Everett_blackops_01 : B_PTbskull_Veh_Unit_Everett_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "09 Everett (Sniper) (Falkor)";
        weapons[] = {"B_PTbskull_Wea_sniper_03_falkor","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_03_falkor","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_17(10Rnd_300WM_Magazine),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_17(10Rnd_300WM_Magazine),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_SNIPER_blackops_03";
    };

    class B_PTbskull_Veh_Unit_Everett_blackops_02 : B_PTbskull_Veh_Unit_Everett_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "09 Everett (Sniper) (DSR50)";
        weapons[] = {"B_PTbskull_Wea_sniper_09_dsr50","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_09_dsr50","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_7(KA_DSR50_3Rnd_x2_M33_FMJ_Mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_7(KA_DSR50_3Rnd_x2_M33_FMJ_Mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_SNIPER_blackops_04";
    };

    class B_PTbskull_Veh_Unit_Taylor_blackops_01 : B_PTbskull_Veh_Unit_Taylor_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "10 Taylor (AA Titan) (SCAR-H)";
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03_titanaa","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03_titanaa","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"Titan_AA"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"Titan_AA"};
        backpack = "B_PTbskull_Veh_Back_AA_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Liu_blackops_01 : B_PTbskull_Veh_Unit_Liu_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "11 Liu (Viper) (Cyrus 9.3mm)";
        weapons[] = {"B_PTbskull_Wea_sniper_10_cyrus","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_10_cyrus","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(10Rnd_93x64_DMR_05_Mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(10Rnd_93x64_DMR_05_Mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_VIPERCHN_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Liu_blackops_02 : B_PTbskull_Veh_Unit_Liu_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "11 Liu (Viper) (Type 115 6.5mm + .50 BW)";
        weapons[] = {"B_PTbskull_Wea_ar_05_type115","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_05_type115","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(30Rnd_65x39_caseless_green_mag_Tracer),MAG_5(10Rnd_50BW_Mag_F),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(30Rnd_65x39_caseless_green_mag_Tracer),MAG_5(10Rnd_50BW_Mag_F),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_VIPERCHN_blackops_02";
    };

    class B_PTbskull_Veh_Unit_Makarova_blackops_01 : B_PTbskull_Veh_Unit_Makarova_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "12 Makarova (RPK-12)";
        weapons[] = {"B_PTbskull_Wea_mg_03_rpk","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_02_pimb","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_03_rpk","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_02_pimb","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(B_PTbskull_Wea_mg_3_AMMO),MAG_4(B_PTbskull_Wea_pistol_02_pimb_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(MiniGrenade),MAG_2(SmokeShell)};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_11(B_PTbskull_Wea_mg_3_AMMO),MAG_4(B_PTbskull_Wea_pistol_02_pimb_AMMO),"gm_1Rnd_66mm_heat_m72a3",MAG_2(MiniGrenade),MAG_2(SmokeShell)};
        // no backpack
    };

    class B_PTbskull_Veh_Unit_Elias_blackops_02 : B_PTbskull_Veh_Unit_Elias_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "13 Elias (UAV) (SCAR-H)";
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
    };

    class B_PTbskull_Veh_Unit_Martinez_blackops_02 : B_PTbskull_Veh_Unit_Martinez_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "14 Martinez (Ammo) (SCAR-H)";
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {MAG_4(B_PTbskull_Wea_pistol_01_4five_AMMO),MAG_15(KA_SCAR_H_20rnd_M993_AP_mag),"gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_AMMO_blackops_01";
    };
