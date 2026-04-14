
    // ── Unit Base Classes ────────────────────────────────────────────────────

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
        camouflage = 0.9;
        audible = 0.06;
        sensitivity = 9;
        sensitivityEar = 3;
        engineer = 1;
        uavHacker = 1;
        icon = "iconManEngineer";
    };

    // ── Units ────────────────────────────────────────────────────────────────

    class B_PTbskull_Veh_Unit_Viper_blackops_00 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (HB300AAC + Benelli + VSSK)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_SSU_Stealth_Uniform_Ghillie_Black";
        linkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade","KA_M14","KA_M7290","KA_M7A3","KA_M814"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_sniper_05_vssk_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade","KA_M14","KA_M7290","KA_M7A3","KA_M814"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_06";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_01 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (HB300AAC + Benelli + ASP-2)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_SSU_Stealth_Uniform_Ghillie_Black";
        linkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade","KA_M14","KA_M7290","KA_M7A3","KA_M814"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade","KA_M14","KA_M7290","KA_M7A3","KA_M814"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_07";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_02 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (HB300AAC + SPAS + WA2000)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_SSU_Stealth_Uniform_Ghillie_Black";
        linkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_02";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_03 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (SCAR-H GL + SPAS + M110)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_SSU_Stealth_Uniform_Ghillie_Black";
        linkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_04_scarh","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_04_scarh","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","B_PTbskull_Wea_sniper_01_m110_AMMO","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_03";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_04 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + SPAS + Falkor) (Ghillie, Jungle)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        linkedItems[] = {"B_PTbskull_Vest_blackops_02",VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {"B_PTbskull_Vest_blackops_02",VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_05 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + SPAS + MAR-10) (Ghillie, Jungle)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        linkedItems[] = {"B_PTbskull_Vest_blackops_02",VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {"B_PTbskull_Vest_blackops_02",VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","10Rnd_338_Mag","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_05";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_06 : B_PTbskull_Veh_Unit_Viper_blackops_04
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + SPAS + Falkor) (Ghillie, Semi-Arid)";
        side = 1;
        faction = "bskull_fc_mo";
        uniformClass = "U_B_FullGhillie_sard";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_07 : B_PTbskull_Veh_Unit_Viper_blackops_05
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + SPAS + MAR-10) (Ghillie, Arid)";
        side = 1;
        faction = "bskull_fc_mo";
        uniformClass = "U_B_FullGhillie_ard";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_08 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (Sting + Benelli + M320) (Ghillie, Jungle)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        linkedItems[] = {"B_PTbskull_Vest_blackops_02",VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {"B_PTbskull_Vest_blackops_02",VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_08";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_09 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (MR-C + Benelli + M320) (Ghillie, Semi-Arid)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_B_FullGhillie_sard";
        linkedItems[] = {"B_PTbskull_Vest_blackops_02",VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {"B_PTbskull_Vest_blackops_02",VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_sniper_04_m320_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","B_PTbskull_Wea_shotgun_3_benelli_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_08";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Viper_blackops_10 : B_recon_TL_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "01 Viper (TL) (XM-7 + SPAS + Falkor) (Ghillie, Jungle)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        linkedItems[] = {"B_PTbskull_Vest_blackops_02",VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {"B_PTbskull_Vest_blackops_02",VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_sniper_03_falkor_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","B_PTbskull_Wea_shotgun_2_spas_AMMO","gm_1Rnd_66mm_heat_m72a3","HandGrenade","HandGrenade","MiniGrenade","MiniGrenade"};
        backpack = "B_PTbskull_Veh_Back_TL_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\1_viper.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Fox_blackops_01 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (Sting)";
        side = 1;
        formationX = 2;
        formationZ = 2;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",FOX_GOGGLES};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\2_fox.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
            // killed = "if (local (_this select 0)) then {_unit = _this select 0;removeAllActions _unit;};"
        };
    };


    class B_PTbskull_Veh_Unit_Fox_blackops_02 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\2_fox.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
            // killed = "if (local (_this select 0)) then {_unit = _this select 0;removeAllActions _unit;};"
        };
    };

    class B_PTbskull_Veh_Unit_Fox_blackops_03 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
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
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\2_fox.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
            // killed = "if (local (_this select 0)) then {_unit = _this select 0;removeAllActions _unit;};"
        };
    };

    class B_PTbskull_Veh_Unit_Fox_blackops_04 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (ASP-2)";
        side = 1;
        formationX = 2;
        formationZ = 2;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",FOX_GOGGLES};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_sniper_06_asp1","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_06_asp1","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnItems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","B_PTbskull_Wea_sniper_06_asp1_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\2_fox.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
            // killed = "if (local (_this select 0)) then {_unit = _this select 0;removeAllActions _unit;};"
        };
    };

    class B_PTbskull_Veh_Unit_Fox_blackops_05 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (MR-C)";
        side = 1;
        formationX = 2;
        formationZ = 2;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",FOX_GOGGLES};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\2_fox.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
            // killed = "if (local (_this select 0)) then {_unit = _this select 0;removeAllActions _unit;};"
        };
    };

    class B_PTbskull_Veh_Unit_Fox_blackops_06 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "02 Fox (Medic) (XM-7)";
        side = 1;
        formationX = 2;
        formationZ = 2;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",FOX_GOGGLES};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\2_fox.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
            // killed = "if (local (_this select 0)) then {_unit = _this select 0;removeAllActions _unit;};"
        };
    };

    class B_PTbskull_Veh_Unit_Vega_blackops_01 : B_Recon_Sharpshooter_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "03 Vega (Sniper) (TRG-42)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_lush","LanguageGRE_F",VEGA_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        linkedItems[] = {"B_PTbskull_Vest_blackops_02",VEGA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VEGA_GOGGLES};
        respawnlinkedItems[] = {"B_PTbskull_Vest_blackops_02",VEGA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VEGA_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_sniper_02_trg42","B_PTbskull_Wea_pistol_01_4five","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_02_trg42","B_PTbskull_Wea_pistol_01_4five","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_sniper_02_trg42_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO"};
        backpack = "B_PTbskull_Veh_Back_SNIPER_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\3_vega.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Vega_blackops_02 : B_Recon_Sharpshooter_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "03 Vega (Sniper) (McMillan)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO_camo_lush","LanguageGRE_F",VEGA_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        linkedItems[] = {"B_PTbskull_Vest_blackops_02",VEGA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VEGA_GOGGLES};
        respawnlinkedItems[] = {"B_PTbskull_Vest_blackops_02",VEGA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VEGA_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_sniper_07_mcmillan","B_PTbskull_Wea_pistol_01_4five","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_07_mcmillan","B_PTbskull_Wea_pistol_01_4five","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","KA_CS5_10rnd_M993_AP_mag","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO"};
        backpack = "B_PTbskull_Veh_Back_SNIPER_blackops_02";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\3_vega.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Vega_blackops_03 : B_PTbskull_Veh_Unit_Vega_blackops_01
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "03 Vega (Sniper) (TRG-42) Semi-Arid";
        side = 1;
        faction = "bskull_fc_mo";
        uniformClass = "U_B_FullGhillie_sard";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\3_vega.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Vega_blackops_04 : B_PTbskull_Veh_Unit_Vega_blackops_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "03 Vega (Sniper) (McMillan) Arid";
        side = 1;
        faction = "bskull_fc_mo";
        uniformClass = "U_B_FullGhillie_ard";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\3_vega.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_01 : B_recon_exp_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (UAV) (Sting)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Enoch","LanguageENGB_F",MCKENDRICK_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\4_mckendrick.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_02 : B_recon_exp_F_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_03_honey","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","hlc_50rnd_300BLK_STANAG_EPR","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_EXP_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\4_mckendrick.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_03 : B_recon_exp_F_OCimport_02
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
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_EXP_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\4_mckendrick.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_04 : B_recon_exp_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (UAV) (MR-C)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Enoch","LanguageENGB_F",MCKENDRICK_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\4_mckendrick.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_05 : B_recon_exp_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (UAV) (XM-250)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Enoch","LanguageENGB_F",MCKENDRICK_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_mg_04_xm250","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_04_xm250","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\4_mckendrick.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_McKendrick_blackops_06 : B_recon_exp_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "04 McKendrick (Demo) (XM-7)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_Enoch","LanguageENGB_F",MCKENDRICK_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {MAG_5(FirstAidKit),"MineDetector"};
        respawnItems[] = {MAG_5(FirstAidKit),"MineDetector"};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_EXP_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\4_mckendrick.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };


    class B_PTbskull_Veh_Unit_Jackson_blackops_01 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_ar_02_r11","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_02_r11","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\5_jackson.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Jackson_blackops_02 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
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
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\5_jackson.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Jackson_blackops_03 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "05 Jackson (Medic) (MR-C)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,JACKSON_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,JACKSON_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        weapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\5_jackson.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Jackson_blackops_04 : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "05 Jackson (Medic) (XM-7)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,JACKSON_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,JACKSON_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_MEDIC_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\5_jackson.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Frost_blackops_01 : B_Patrol_HeavyGunner_F_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_mg_01_smpg","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_01_smpg","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","130Rnd_338_Mag","130Rnd_338_Mag","130Rnd_338_Mag","130Rnd_338_Mag","130Rnd_338_Mag"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","130Rnd_338_Mag","130Rnd_338_Mag","130Rnd_338_Mag","130Rnd_338_Mag","130Rnd_338_Mag"};
        backpack = "B_PTbskull_Veh_Back_MG_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\6_frost.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Frost_blackops_02 : B_Patrol_HeavyGunner_F_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_mg_02_navid","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_02_navid","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag"};
        backpack = "B_PTbskull_Veh_Back_MG_blackops_02";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\6_frost.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Frost_blackops_03 : B_Patrol_HeavyGunner_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "06 Frost (Navid9.3 + Fuel)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENGFRE_F","G_SSU_Bandana_Sports_Black"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Camo_Combat_Helmet_MCAM_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Camo_Combat_Helmet_MCAM_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black"};
        weapons[] = {"B_PTbskull_Wea_mg_02_navid","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_02_navid","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag","150Rnd_93x64_Mag"};
        backpack = "B_PTbskull_Veh_Back_Fuel_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\6_frost.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Frost_blackops_04 : B_Patrol_HeavyGunner_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "06 Frost (XM-250 + Fuel)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENGFRE_F","G_SSU_Bandana_Sports_Black"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Camo_Combat_Helmet_MCAM_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Camo_Combat_Helmet_MCAM_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black"};
        weapons[] = {"B_PTbskull_Wea_mg_04_xm250","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_04_xm250","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO","B_PTbskull_Wea_mg_04_xm250_AMMO"};
        backpack = "B_PTbskull_Veh_Back_Fuel_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\6_frost.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Hawkins_blackops_01 : B_recon_LAT_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "07 Hawkins (AT) (SPAR-17)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_SSU_Bandana_Sports_Black_Beast"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,HAWKINS_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black_Beast"};
        respawnlinkedItems[] = {DEFAULT_VEST,HAWKINS_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black_Beast"};
        weapons[] = {"B_PTbskull_Wea_ar_06_spar17","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_06_spar17","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","Titan_AT_PLUS","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","Titan_AT_PLUS","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag","20Rnd_762x51_Mag"};
        backpack = "B_PTbskull_Veh_Back_AT_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\7_hawkins.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Hawkins_blackops_02 : B_recon_LAT_F_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_ar_04_scarh","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_04_scarh","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","Titan_AT_PLUS","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","UGL_FlareWhite_Illumination_F","UGL_FlareWhite_Illumination_F","UGL_FlareWhite_Illumination_F"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","Titan_AT_PLUS","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","KA_SCAR_H_20rnd_M993_AP_mag","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","UGL_FlareWhite_Illumination_F","UGL_FlareWhite_Illumination_F","UGL_FlareWhite_Illumination_F"};
        backpack = "B_PTbskull_Veh_Back_AT_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\7_hawkins.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Hawkins_blackops_03 : B_recon_LAT_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "07 Hawkins (AT) (XM-7)";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_SSU_Bandana_Sports_Black_Beast"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,HAWKINS_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black_Beast"};
        respawnlinkedItems[] = {DEFAULT_VEST,HAWKINS_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black_Beast"};
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_01_titanat","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","Titan_AT_PLUS","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","Titan_AT_PLUS","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell"};
        backpack = "B_PTbskull_Veh_Back_AT_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\7_hawkins.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Sykes_blackops_01 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_ar_02_r11","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_02_r11","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","JAS_RSASS_20rnd_M993_AP_mag","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\8_sykes.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Sykes_blackops_02 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "08 Sykes (UAV) (MR-C)";
        side = 1;
        faction = "bskull_fc_mo";
        icon = "iconWomanEngineer";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Tactical_Clear"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Tactical_Clear"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Tactical_Clear"};
        weapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_07_mrc","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","B_PTbskull_Wea_ar_07_mrc_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\8_sykes.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Sykes_blackops_03 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "08 Sykes (UAV) (XM-7)";
        side = 1;
        faction = "bskull_fc_mo";
        icon = "iconWomanEngineer";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Tactical_Clear"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Tactical_Clear"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Tactical_Clear"};
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\8_sykes.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Sykes_blackops_04 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "08 Sykes (AIMS) (XM-7)";
        side = 1;
        faction = "bskull_fc_mo";
        icon = "iconWomanEngineer";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Tactical_Clear"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Tactical_Clear"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Tactical_Clear"};
        weapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_08_xm7","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","B_PTbskull_Wea_ar_08_xm7_AMMO","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","3Rnd_HE_Grenade_shell","KA_40mm_M814","KA_40mm_M814","KA_40mm_M814","KA_40mm_M14","KA_40mm_M14","KA_40mm_M14","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","1Rnd_Flechette_Cartridge_Grenade_shell","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_KA_Metal_Storm_AI_NATO";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\8_sykes.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Everett_blackops_01 : B_Recon_Sharpshooter_F_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_sniper_03_falkor","B_PTbskull_Wea_pistol_01_4five","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_03_falkor","B_PTbskull_Wea_pistol_01_4five","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","10Rnd_300WM_Magazine","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_SNIPER_blackops_03";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\9_everett.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Everett_blackops_02 : B_Recon_Sharpshooter_F_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_sniper_09_dsr50","B_PTbskull_Wea_pistol_01_4five","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_09_dsr50","B_PTbskull_Wea_pistol_01_4five","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","KA_DSR50_3Rnd_x2_M33_FMJ_Mag","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_SNIPER_blackops_04";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\9_everett.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Taylor_blackops_01 : B_recon_LAT_F_OCimport_02
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
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03_titanaa","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_03_titanaa","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","Titan_AA"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","Titan_AA"};
        backpack = "B_PTbskull_Veh_Back_AA_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\10_taylor.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Liu_blackops_01 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_sniper_10_cyrus","B_PTbskull_Wea_pistol_01_4five","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_sniper_10_cyrus","B_PTbskull_Wea_pistol_01_4five","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","10Rnd_93x64_DMR_05_Mag","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_VIPERCHN_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\11_liu.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Liu_blackops_02 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_ar_05_type115","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_05_type115","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","10Rnd_50BW_Mag_F","10Rnd_50BW_Mag_F","10Rnd_50BW_Mag_F","10Rnd_50BW_Mag_F","10Rnd_50BW_Mag_F","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","30Rnd_65x39_caseless_green_mag_Tracer","10Rnd_50BW_Mag_F","10Rnd_50BW_Mag_F","10Rnd_50BW_Mag_F","10Rnd_50BW_Mag_F","10Rnd_50BW_Mag_F","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_VIPERCHN_blackops_02";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\11_liu.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Makarova_blackops_01 : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
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
        weapons[] = {"B_PTbskull_Wea_mg_03_rpk","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_02_pimb","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_mg_03_rpk","B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_02_pimb","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_pistol_02_pimb_AMMO","B_PTbskull_Wea_pistol_02_pimb_AMMO","B_PTbskull_Wea_pistol_02_pimb_AMMO","B_PTbskull_Wea_pistol_02_pimb_AMMO","gm_1Rnd_66mm_heat_m72a3","MiniGrenade","MiniGrenade","SmokeShell","SmokeShell"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_mg_3_AMMO","B_PTbskull_Wea_pistol_02_pimb_AMMO","B_PTbskull_Wea_pistol_02_pimb_AMMO","B_PTbskull_Wea_pistol_02_pimb_AMMO","B_PTbskull_Wea_pistol_02_pimb_AMMO","gm_1Rnd_66mm_heat_m72a3","MiniGrenade","MiniGrenade","SmokeShell","SmokeShell"};
        // no backpack
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\12_makarova.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Elias_blackops_02 : B_soldier_UAV_F_OCimport_02
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
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\13_elias.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    class B_PTbskull_Veh_Unit_Martinez_blackops_02 : B_Recon_F_OCimport_02
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
        weapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {DEFAULT_AR,"B_PTbskull_Wea_law_02_m72","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","DEFAULT_AR_AMMO","gm_1Rnd_66mm_heat_m72a3"};
        backpack = "B_PTbskull_Veh_Back_AMMO_blackops_01";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\14_martinez.sqf';";
            // hit = "_this execVM '\bskulls-modern\scripts\hit.sqf';"
        };
    };

    // JUNGLE

    // Units


    // class B_PTbskull_Veh_Viper_jungleops_02 : B_PTbskull_Veh_Unit_Viper_blackops_02
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

    // class B_PTbskull_Veh_Viper_jungleops_03 : B_PTbskull_Veh_Unit_Viper_blackops_03
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

    // class B_PTbskull_Veh_Fox_jungleops_02 : B_PTbskull_Veh_Unit_Fox_blackops_02
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

    // class B_PTbskull_Veh_Fox_jungleops_03 : B_PTbskull_Veh_Unit_Fox_blackops_03
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

    // class B_PTbskull_Veh_McKendrick_jungleops_02 : B_PTbskull_Veh_Unit_McKendrick_blackops_02
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

    // class B_PTbskull_Veh_McKendrick_jungleops_03 : B_PTbskull_Veh_Unit_McKendrick_blackops_03
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

    // class B_PTbskull_Veh_Jackson_jungleops_01 : B_PTbskull_Veh_Unit_Jackson_blackops_01
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

    // class B_PTbskull_Veh_Jackson_jungleops_02 : B_PTbskull_Veh_Unit_Jackson_blackops_02
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

    // class B_PTbskull_Veh_Frost_jungleops_01 : B_PTbskull_Veh_Unit_Frost_blackops_01
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

    // class B_PTbskull_Veh_Frost_jungleops_02 : B_PTbskull_Veh_Unit_Frost_blackops_02
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

    // class B_PTbskull_Veh_Sykes_jungleops_01 : B_PTbskull_Veh_Unit_Sykes_blackops_01
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

    // class B_PTbskull_Veh_Taylor_jungleops_01 : B_PTbskull_Veh_Unit_Taylor_blackops_01
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

    // class B_PTbskull_Veh_Taylor_jungleops_02 : B_PTbskull_Veh_Unit_Taylor_blackops_01
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

    // class B_PTbskull_Veh_Liu_jungleops_01 : B_PTbskull_Veh_Unit_Liu_blackops_01
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

    // class B_PTbskull_Veh_Liu_jungleops_02 : B_PTbskull_Veh_Unit_Liu_blackops_02
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

    // class B_PTbskull_Veh_Makarova_jungleops_01 : B_PTbskull_Veh_Unit_Makarova_blackops_01
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

    // class B_PTbskull_Veh_Elias_jungleops_02 : B_PTbskull_Veh_Unit_Elias_blackops_02
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

    // class B_PTbskull_Veh_Martinez_jungleops_02 : B_PTbskull_Veh_Unit_Martinez_blackops_02
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


    class THC_Bag50;
    // class Bag_Base_OCimport_001 : Bag_Base {
    //     scope = 0;
    //     maximumLoad = 2000;
    //     model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
    //     picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
    // };

    class B_PTbskull_Veh_Back_TL_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Viper SPAS + Falkor)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=1;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=1;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=1;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};
            class _xx_B_PTbskull_Wea_sniper_03_falkor_AMMO {count=1;magazine="B_PTbskull_Wea_sniper_03_falkor_AMMO";};
            class _xx_8Rnd_SPAS12_buck {count=1;magazine="B_PTbskull_Wea_shotgun_2_spas_AMMO";};
        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_03_falkor {count=1;weapon="B_PTbskull_Wea_sniper_03_falkor";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
            class _xx_B_PTbskull_Wea_shotgun_2 {count=1;weapon="B_PTbskull_Wea_shotgun_2_spas";};
        };
    };

    class B_PTbskull_Veh_Back_TL_blackops_02: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Viper SPAS + WA2000)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=1;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=1;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=1;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};
            class _xx_B_PTbskull_Wea_sniper_08_wa2000_AMMO {count=1;magazine="B_PTbskull_Wea_sniper_08_wa2000_AMMO";};
            class _xx_8Rnd_SPAS12_buck {count=1;magazine="B_PTbskull_Wea_shotgun_2_spas_AMMO";};
        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_8 {count=1;weapon="B_PTbskull_Wea_sniper_08_wa2000";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
            class _xx_B_PTbskull_Wea_shotgun_2 {count=1;weapon="B_PTbskull_Wea_shotgun_2_spas";};
        };
    };

    class B_PTbskull_Veh_Back_TL_blackops_03: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Viper SPAS + M110A1)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=1;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=1;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=1;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};
            class _xx_B_PTbskull_Wea_sniper_01_m110_AMMO {count=1;magazine="B_PTbskull_Wea_sniper_01_m110_AMMO";};
            class _xx_8Rnd_SPAS12_buck {count=1;magazine="B_PTbskull_Wea_shotgun_2_spas_AMMO";};
        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_01_m110 {count=1;weapon="B_PTbskull_Wea_sniper_01_m110";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
            class _xx_B_PTbskull_Wea_shotgun_2 {count=1;weapon="B_PTbskull_Wea_shotgun_2_spas";};
        };
    };

    class B_PTbskull_Veh_Back_TL_blackops_05: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Viper SPAS + MAR-10)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=1;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=1;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=1;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};
            class _xx_10Rnd_338_Mag {count=1;magazine="10Rnd_338_Mag";};
            class _xx_8Rnd_SPAS12_buck {count=1;magazine="B_PTbskull_Wea_shotgun_2_spas_AMMO";};
        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_12 {count=1;weapon="B_PTbskull_Wea_sniper_12_mar10";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
            class _xx_B_PTbskull_Wea_shotgun_2 {count=1;weapon="B_PTbskull_Wea_shotgun_2_spas";};
        };
    };

    class B_PTbskull_Veh_Back_TL_blackops_06: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Viper VSSK + Benelli M1014)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=1;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=1;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=1;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};
            class _xx_B_PTbskull_Wea_sniper_05_vssk_AMMO {count=1;magazine="B_PTbskull_Wea_sniper_05_vssk_AMMO";};
            class _xx_B_PTbskull_Wea_shotgun_3_benelli_AMMO {count=1;magazine="B_PTbskull_Wea_shotgun_3_benelli_AMMO";};
        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_05_vssk {count=1;weapon="B_PTbskull_Wea_sniper_05_vssk";};
            class _xx_B_PTbskull_Wea_shotgun_3_benelli {count=1;weapon="B_PTbskull_Wea_shotgun_3_benelli";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
        };
    };

    class B_PTbskull_Veh_Back_TL_blackops_07: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Viper ASP-2 + Benelli M1014)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=1;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=1;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=1;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};
            class _xx_B_PTbskull_Wea_sniper_06_asp1_AMMO {count=1;magazine="B_PTbskull_Wea_sniper_06_asp1_AMMO";};
            class _xx_B_PTbskull_Wea_shotgun_3_benelli_AMMO {count=1;magazine="B_PTbskull_Wea_shotgun_3_benelli_AMMO";};
        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_06_asp1 {count=1;weapon="B_PTbskull_Wea_sniper_06_asp1";};
            class _xx_B_PTbskull_Wea_shotgun_3_benelli {count=1;weapon="B_PTbskull_Wea_shotgun_3_benelli";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
        };
    };

    class B_PTbskull_Veh_Back_TL_blackops_08: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Viper M320 + Benelli M1014)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_B_IR_Grenade {count=1;magazine="B_IR_Grenade";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=1;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_Chemlight_yellow {count=1;magazine="Chemlight_yellow";};
            class _xx_Chemlight_green {count=1;magazine="Chemlight_green";};
            class _xx_Laserbatteries {count=1;magazine="Laserbatteries";};
            class _xx_B_PTbskull_Wea_sniper_04_m320_AMMO {count=1;magazine="B_PTbskull_Wea_sniper_04_m320_AMMO";};
            class _xx_B_PTbskull_Wea_shotgun_3_benelli_AMMO {count=1;magazine="B_PTbskull_Wea_shotgun_3_benelli_AMMO";};
        };
        class TransportItems {VIPER_BAG_ITEMS};
        class TransportWeapons{
            class _xx_B_PTbskull_Wea_sniper_04_m320 {count=1;weapon="B_PTbskull_Wea_sniper_04_m320";};
            class _xx_B_PTbskull_Wea_shotgun_3_benelli {count=1;weapon="B_PTbskull_Wea_shotgun_3_benelli";};
            class _xx_Laserdesignator_03 {count=1;weapon="Laserdesignator_03";};
        };
    };

    class B_PTbskull_Veh_Back_MEDIC_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Paramedic)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
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

    class B_PTbskull_Veh_Back_SNIPER_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Sniper TRG-42)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_B_PTbskull_Wea_sniper_02_trg42_AMMO {count=10;magazine="B_PTbskull_Wea_sniper_02_trg42_AMMO";};
            class _xx_B_PTbskull_Wea_SMG_02_sting_AMMO {count=10;magazine="B_PTbskull_Wea_SMG_02_sting_AMMO";};
        };
        class TransportItems { };
        class TransportWeapons {
            class _xx_B_PTbskull_Wea_SMG_02_sting {count=1;weapon="B_PTbskull_Wea_SMG_02_sting";};
        };
    };

    class B_PTbskull_Veh_Back_SNIPER_blackops_02: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Sniper McMillan)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_KA_CS5_10rnd_M993_AP_mag {count=10;magazine="KA_CS5_10rnd_M993_AP_mag";};
            class _xx_B_PTbskull_Wea_SMG_02_sting_AMMO {count=10;magazine="B_PTbskull_Wea_SMG_02_sting_AMMO";};
        };
        class TransportItems { };
        class TransportWeapons {
            class _xx_B_PTbskull_Wea_SMG_02_sting {count=1;weapon="B_PTbskull_Wea_SMG_02_sting";};
        };
    };

    class B_PTbskull_Veh_Back_EXP_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Demolition)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
        };
        class TransportItems {
            class _xx_ToolKit {count=1;name="ToolKit";};
            class _xx_DemoCharge_Remote_Mag {count=2;name="DemoCharge_Remote_Mag";};
            class _xx_SatchelCharge_Remote_Mag {count=2;name="SatchelCharge_Remote_Mag";};
            class _xx_ATMine_Range_Mag {count=2;name="ATMine_Range_Mag";};
        };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_Back_MG_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (MG SPMG)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_130Rnd_338_Mag {count=1;magazine="130Rnd_338_Mag";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_Back_MG_blackops_02: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (MG Navid)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_150Rnd_93x64_Mag {count=1;magazine="150Rnd_93x64_Mag";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

   class B_PTbskull_Veh_Back_AT_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (AT Titan+)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_Titan_AT_PLUS {count=4;magazine="Titan_AT_PLUS";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

   class B_PTbskull_Veh_Back_AMMO_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Ammo)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
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
            class _xx_B_PTbskull_Wea_sniper_02_trg42_AMMO {count=2;magazine="B_PTbskull_Wea_sniper_02_trg42_AMMO";};
            class _xx_B_PTbskull_Wea_sniper_03_falkor_AMMO {count=2;magazine="B_PTbskull_Wea_sniper_03_falkor_AMMO";};
            class _xx_KA_CS5_10rnd_M993_AP_mag {count=2;magazine="KA_CS5_10rnd_M993_AP_mag";};
            class _xx_10Rnd_300WM_Magazine {count=2;magazine="10Rnd_300WM_Magazine";};
            class _xx_KA_DSR50_3Rnd_x2_M33_FMJ_Mag {count=2;magazine="KA_DSR50_3Rnd_x2_M33_FMJ_Mag";};
            class _xx_150Rnd_93x64_Mag {count=1;magazine="150Rnd_93x64_Mag";};
            class _xx_130Rnd_338_Mag {count=1;magazine="130Rnd_338_Mag";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_Back_SNIPER_blackops_03: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Sniper Falkor)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_10Rnd_300WM_Magazine {count=7;magazine="10Rnd_300WM_Magazine";};
            class _xx_B_PTbskull_Wea_SMG_02_sting_AMMO {count=10;magazine="B_PTbskull_Wea_SMG_02_sting_AMMO";};
        };
        class TransportItems { };
        class TransportWeapons {
            class _xx_B_PTbskull_Wea_SMG_02 {count=1;weapon="B_PTbskull_Wea_SMG_02_sting";};
        };
    };

    class B_PTbskull_Veh_Back_SNIPER_blackops_04: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Sniper DSR-50)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_MiniGrenade {count=2;magazine="MiniGrenade";};
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_KA_DSR50_3Rnd_x2_M33_FMJ_Mag {count=10;magazine="KA_DSR50_3Rnd_x2_M33_FMJ_Mag";};
            class _xx_KA_DSR50_3Rnd_x2_MK263_AP_Mag {count=10;magazine="KA_DSR50_3Rnd_x2_MK263_AP_Mag";};
            class _xx_B_PTbskull_Wea_SMG_02_sting_AMMO {count=10;magazine="B_PTbskull_Wea_SMG_02_sting_AMMO";};
        };
        class TransportItems { };
        class TransportWeapons {
            class _xx_B_PTbskull_Wea_SMG_02 {count=1;weapon="B_PTbskull_Wea_SMG_02_sting";};
        };
    };

    class B_PTbskull_Veh_Back_AA_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (AA)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_Titan_AA {count=4;magazine="Titan_AA";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_Back_BACKUP_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Backup)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_B_PTbskull_Wea_SMG_02_sting_AMMO {count=10;magazine="B_PTbskull_Wea_SMG_02_sting_AMMO";};
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
            class _xx_B_PTbskull_Wea_SMG_02 {count=1;weapon="B_PTbskull_Wea_SMG_02_sting";};
        };
    };

    class B_PTbskull_Veh_Back_VIPERCHN_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Liu Cyrus)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_10Rnd_93x64_DMR_05_Mag {count=10;magazine="10Rnd_93x64_DMR_05_Mag";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_Back_VIPERCHN_blackops_02: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Liu Type 115)";
        maximumLoad = 2000;
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_compact_blk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Compact";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Compact_blk_ca.paa";
        class TransportMagazines {
            class _xx_SmokeShell {count=2;magazine="SmokeShell";};
            class _xx_30Rnd_65x39_caseless_green_mag_Tracer {count=5;magazine="30Rnd_65x39_caseless_green_mag_Tracer";};
            class _xx_10Rnd_50BW_Mag_F {count=5;magazine="10Rnd_50BW_Mag_F";};
        };
        class TransportItems { };
        class TransportWeapons { };
    };

    class B_PTbskull_Veh_Back_Fuel_blackops_01: THC_Bag50 {
        author = "RoFz";
        scope = 2;
        displayName = "Assault Pack (Fuel)";
        explosionEffect = "FuelExplosion";
        explosionShielding = 1;
        fuelExplosionPower = 0.7;
        transportFuel = 5;
    };

