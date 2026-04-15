    // Sniper #1: M110A1
    // Ammo: 20Rnd_762x51_Mag
    #define B_PTbskull_Wea_sniper_01_m110_AMMO 20Rnd_762x51_Mag
    class kt_M110A1_khk02; // leads to CfgMagazines.ACE_20Rnd_762x51_Mag_Tracer bug, CONFIRMED
    class kt_M110A1_khk02_OCimport_01 : kt_M110A1_khk02 { scope = 0; scopeArsenal = 0; };
    class B_PTbskull_Wea_sniper_01_m110 : kt_M110A1_khk02_OCimport_01 {
        displayName = "H&K M110A1 SDMR (7.62x51mm NATO)";
        author = "RoFz";
        scope = 2;
        delete ACE_barrelLength;
        delete ACE_barrelTwist;
        delete ace_overheating_allowSwapBarrel;
        delete ACE_Overheating_Dispersion;
        delete ACE_overheating_mrbs;
        delete ace_overheating_slowdownFactor;
        delete ACE_RailHeightAboveBore;
        magazines[] = {"20Rnd_762x51_Mag","BC_20Rnd_762_MEA_Stanag","rhsusf_20Rnd_762x51_m118_special_Mag","rhsusf_20Rnd_762x51_m993_Mag","rhsusf_20Rnd_762x51_m62_Mag"}; // {"20Rnd_762x51_Mag","BC_20Rnd_762_MEA_Stanag","rhsusf_20Rnd_762x51_m118_special_Mag","rhsusf_20Rnd_762x51_m993_Mag","rhsusf_20Rnd_762x51_m62_Mag","ACE_20Rnd_762x51_M118LR_Mag","ACE_20Rnd_762x51_M993_AP_Mag","ACE_20Rnd_762x51_Mk319_Mod_0_Mag","ACE_20Rnd_762x51_Mk316_Mod_0_Mag","kt_20Rnd_762x51_178gr_ELD_X_Mag","kt_20Rnd_762x51_Mk316_Mod_0_Mag"};
        // magazineWell[] = {"CBA_762x51_AR10","CBA_762x51_SR25"};
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "kt_m110a1_silencer_04";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };

    // Sniper #2: TRG-42
    // Ammo: 5Rnd_APDS_338LM_Magazine_PLUS
    #define B_PTbskull_Wea_sniper_02_trg42_AMMO 5Rnd_APDS_338LM_Magazine_PLUS
    class bnae_trg42_virtual;
    class bnae_trg42_virtual_OCimport_01 : bnae_trg42_virtual { access = 0; scope = 0; class WeaponSlotsInfo; class Single; };
    class bnae_trg42_virtual_OCimport_02 : bnae_trg42_virtual_OCimport_01 {
        access = 0;
        scope = 0;
       
        class Single : Single {};
        class WeaponSlotsInfo : WeaponSlotsInfo {
            class CowsSlot;
        };
    };
    class B_PTbskull_Wea_sniper_02_trg42 : bnae_trg42_virtual_OCimport_02 {
        displayName = "Sako TRG-42 (.338 LM)";
        author = "RoFz";
        access = 0;
        scope = 2;
        magazines[] += {"5Rnd_APDS_338LM_Magazine_PLUS"};
        class WeaponSlotsInfo : WeaponSlotsInfo {
            allowedslots[] = {901};
            class CowsSlot : CowsSlot {
                compatibleitems[] += {"kt_atacr06_tremoe3ti_raptar", "optic_Nightstalker"};
            };
        };
         class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "bnae_silencer_virtual";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bnae_bipod_v2_virtual";
            };
        };
        class Single : Single {};
        class medium_optic2 : Single
        {
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFire = 2; // 6
            aiRateOfFireDispersion = 0.1; // 1
            aiRateOfFireDistance = 1000;
            dispersion = 0.00001; // 0.00044
            maxRange = 1000;
            maxRangeProbab = 0.9; // 0.3
            midRange = 750;
            midRangeProbab = 0.9; // 0.7
            minRange = 250;
            minRangeProbab = 0.6; // 0.1
        };
        class far_optic1 : Single
        {
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFire = 1; // 5
            aiRateOfFireDispersion = 0.1; // 1
            aiRateOfFireDistance = 700; // 700
            dispersion = 0.00001; // 0.00044
            maxRange = 1000;
            maxRangeProbab = 0.9; // 0.3
            midRange = 500;
            midRangeProbab = 0.9; // 0.7
            minRange = 150;
            minRangeProbab = 0.6; // 0.1
        };
        class far_optic2 : far_optic1
        {
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFire = 3; // 8
            aiRateOfFireDispersion = 0.1; // 1
            aiRateOfFireDistance = 2000; // 2000
            dispersion = 0.00001; // 0.00044
            maxRange = 2000;
            maxRangeProbab = 0.9; // 0.3
            midRange = 1050;
            midRangeProbab = 0.9; // 0.7
            minRange = 500;
            minRangeProbab = 0.9; // 0.1
        };
    };

    // Sniper #3: Falkor Petra
    // Ammo: 10Rnd_300WM_Magazine
    #define B_PTbskull_Wea_sniper_03_falkor_AMMO 10Rnd_300WM_Magazine
    class bnae_falkor_snd_virtual;
    class bnae_falkor_snd_virtual_OCimport_01 : bnae_falkor_snd_virtual { access = 0; scope = 0; class WeaponSlotsInfo; };
    class B_PTbskull_Wea_sniper_03_falkor : bnae_falkor_snd_virtual_OCimport_01 {
        displayName = "Falkor Petra (.300 WM)";
        author = "RoFz";
        access = 0;
        scope = 2;
        class WeaponSlotsInfo : WeaponSlotsInfo {
            class CowsSlot {
                iconPosition[] = {0.5,0.36};
                iconScale = 0.2;
                linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
                displayName = "Optics Slot";
                iconPicture = "\a3\weapons_f\Data\ui\attachment_top";
                iconPinpoint = "Bottom";
                scope = 0;
                class compatibleItems
                {
                    rhsusf_acc_LEUPOLDMK4 = 0;
                    rhsusf_acc_LEUPOLDMK4_d = 0;
                    rhsusf_acc_LEUPOLDMK4_wd = 0;
                    rhsusf_acc_M8541_low = 0;
                    rhsusf_acc_M8541_low_d = 0;
                    rhsusf_acc_M8541_low_wd = 0;
                    rhsusf_acc_premier_anpvs27 = 1;
                    rhsusf_acc_ACOG_anpvs27 = 1;
                    rhsusf_acc_T1_low_fwd = 1;
                    rhsusf_acc_T1_low_fwd_ak = 1;
                    rhsusf_acc_RM05_fwd = 1;
                    rhsusf_acc_RM05_fwd_ak = 1;
                    rhsusf_acc_mrds_fwd = 1;
                    rhsusf_acc_mrds_fwd_ak = 1;
                    rhsusf_acc_mrds_fwd_c = 1;
                    rhsusf_acc_mrds_fwd_c_ak = 1;
                    kt_8x_Dot_cqb = 1;
                    kt_8x_Dot03_cqb_up = 1;
                    kt_8x_Dot031 = 1;
                    kt_8x_Dot05_cqb_side = 1;
                    kt_8x_Dot051 = 1;
                    kt_8x_Dot_cqb_pip = 1;
                    kt_8x_Dot03_cqb_up_pip = 1;
                    kt_8x_Dot031_pip = 1;
                    kt_8x_Dot05_cqb_side_pip = 1;
                    kt_8x_Dot051_pip = 1;
                    kt_8x_Dot07_side = 1;
                    kt_8x_Dot071 = 1;
                    kt_8x_Dot08_up = 1;
                    kt_8x_Dot081 = 1;
                    kt_8x_Dot07_side_pip = 1;
                    kt_8x_Dot071_pip = 1;
                    kt_8x_Dot08_up_pip = 1;
                    kt_8x_Dot081_pip = 1;
                    kt_8x_Dot09_up = 1;
                    kt_8x_Dot091 = 1;
                    kt_8x_Dot09_up_pip = 1;
                    kt_8x_Dot091_pip = 1;
                    kt_8x_Dot10_up = 1;
                    kt_8x_Dot101 = 1;
                    kt_8x_Dot10_up_pip = 1;
                    kt_8x_Dot101_pip = 1;
                    kt_20x_Round_Dot04_ti_raptar = 1;
                    kt_20x_Round_Dot05_ti_raptar = 1;
                    kt_20x_Round_Dot041 = 1;
                    kt_20x_Round_Dot051 = 1;
                    kt_20x_Round_Dot04_ti_raptar_pip = 1;
                    kt_20x_Round_Dot05_ti_raptar_pip = 1;
                    kt_20x_Round_Dot041_pip = 1;
                    kt_20x_Round_Dot051_pip = 1;
                    kt_25x_PMII02_msr_ti = 1;
                    kt_25x_PMII03_msr_nv = 1;
                    kt_25x_PMII04_msr_ti_RAPTAR = 1;
                    kt_25x_PMII05_tremoe3_ti_RAPTAR = 1;
                    kt_25x_PMII06_msr_ti_RAPTAR = 1;
                    kt_25x_PMII07_tremoe3_ti_RAPTAR = 1;
                    kt_25x_PMII021 = 1;
                    kt_25x_PMII031 = 1;
                    kt_25x_PMII041 = 1;
                    kt_25x_PMII051 = 1;
                    kt_25x_PMII061 = 1;
                    kt_25x_PMII071 = 1;
                    kt_25x_PMII02_msr_ti_pip = 1;
                    kt_25x_PMII03_msr_nv_pip = 1;
                    kt_25x_PMII04_msr_ti_RAPTAR_pip = 1;
                    kt_25x_PMII05_tremoe3_ti_RAPTAR_pip = 1;
                    kt_25x_PMII06_msr_ti_RAPTAR_pip = 1;
                    kt_25x_PMII07_tremoe3_ti_RAPTAR_pip = 1;
                    kt_25x_PMII021_pip = 1;
                    kt_25x_PMII031_pip = 1;
                    kt_25x_PMII041_pip = 1;
                    kt_25x_PMII051_pip = 1;
                    kt_25x_PMII061_pip = 1;
                    kt_25x_PMII071_pip = 1;
                    kt_atacr05_msrti_raptar = 1;
                    kt_atacr06_tremoe3ti_raptar = 1;
                    kt_atacr051 = 1;
                    kt_atacr061 = 1;
                    kt_atacr07_tremoe3ti_raptar = 1;
                    kt_atacr071 = 1;
                    kt_specterDR = 1;
                    kt_specterDR_s = 1;
                    KA_M16A2_Scope = 1;
                    KA_M2_Scope = 1;
                    rhsusf_acc_LEUPOLDMK4_2 = 1;
                    rhsusf_acc_LEUPOLDMK4_2_MRDS = 1;
                    rhsusf_acc_LEUPOLDMK4_2_d = 1;
                    rhsusf_acc_premier = 1;
                    rhsusf_acc_premier_mrds = 1;
                    rhsusf_acc_premier_low = 1;
                    rhsusf_acc_M8541 = 1;
                    rhsusf_acc_M8541_d = 1;
                    rhsusf_acc_M8541_wd = 1;
                    rhsusf_acc_M8541_mrds = 1;
                    rhsusf_acc_nxs_3515x50_md = 1;
                    rhsusf_acc_nxs_3515x50f1_md = 1;
                    rhsusf_acc_nxs_3515x50f1_md_sun = 1;
                    rhsusf_acc_nxs_3515x50f1_h58 = 1;
                    rhsusf_acc_nxs_3515x50f1_h58_sun = 1;
                    rhsusf_acc_nxs_5522x56_md = 1;
                    rhsusf_acc_nxs_5522x56_md_sun = 1;
                    rhsusf_acc_EOTECH = 1;
                    rhsusf_acc_eotech_552 = 1;
                    rhsusf_acc_eotech_552_d = 1;
                    rhsusf_acc_eotech_552_wd = 1;
                    rhsusf_acc_eotech_xps3 = 1;
                    rhsusf_acc_g33_xps3 = 1;
                    rhsusf_acc_g33_xps3_flip = 1;
                    rhsusf_acc_g33_xps3_tan = 1;
                    rhsusf_acc_g33_xps3_tan_flip = 1;
                    rhsusf_acc_g33_t1 = 1;
                    rhsusf_acc_g33_t1_flip = 1;
                    rhsusf_acc_compm4 = 1;
                    rhsusf_acc_T1_high = 1;
                    rhsusf_acc_T1_low = 1;
                    rhsusf_acc_RX01 = 1;
                    rhsusf_acc_RX01_NoFilter = 1;
                    rhsusf_acc_RX01_tan = 1;
                    rhsusf_acc_RX01_NoFilter_tan = 1;
                    rhsusf_acc_RM05 = 1;
                    rhsusf_acc_mrds = 1;
                    rhsusf_acc_mrds_c = 1;
                    rhsusf_acc_ACOG = 1;
                    rhsusf_acc_ACOG2 = 1;
                    rhsusf_acc_ACOG3 = 1;
                    rhsusf_acc_ACOG_wd = 1;
                    rhsusf_acc_ACOG_d = 1;
                    rhsusf_acc_ACOG_sa = 1;
                    rhsusf_acc_ACOG_USMC = 1;
                    rhsusf_acc_ACOG2_USMC = 1;
                    rhsusf_acc_ACOG3_USMC = 1;
                    rhsusf_acc_ACOG_RMR = 1;
                    rhsusf_acc_ACOG_PIP = 1;
                    rhsusf_acc_ACOG2_pip = 1;
                    rhsusf_acc_ACOG3_pip = 1;
                    rhsusf_acc_ACOG_wd_pip = 1;
                    rhsusf_acc_ACOG_d_pip = 1;
                    rhsusf_acc_ACOG_sa_pip = 1;
                    rhsusf_acc_ACOG_USMC_pip = 1;
                    rhsusf_acc_ACOG2_USMC_pip = 1;
                    rhsusf_acc_ACOG3_USMC_pip = 1;
                    rhsusf_acc_ACOG_RMR_PIP = 1;
                    rhsusf_acc_ACOG_3d = 1;
                    rhsusf_acc_ACOG2_3d = 1;
                    rhsusf_acc_ACOG3_3d = 1;
                    rhsusf_acc_ACOG_wd_3d = 1;
                    rhsusf_acc_ACOG_d_3d = 1;
                    rhsusf_acc_ACOG_sa_3d = 1;
                    rhsusf_acc_ACOG_USMC_3d = 1;
                    rhsusf_acc_ACOG2_USMC_3d = 1;
                    rhsusf_acc_ACOG3_USMC_3d = 1;
                    rhsusf_acc_ACOG_RMR_3d = 1;
                    rhsusf_acc_ELCAN = 1;
                    rhsusf_acc_ELCAN_ard = 1;
                    rhsusf_acc_ELCAN_3d = 1;
                    rhsusf_acc_ELCAN_ard_3d = 1;
                    rhsusf_acc_ELCAN_PIP = 1;
                    rhsusf_acc_ELCAN_ard_PIP = 1;
                    rhsusf_acc_su230 = 1;
                    rhsusf_acc_su230_mrds = 1;
                    rhsusf_acc_su230a = 1;
                    rhsusf_acc_su230a_mrds = 1;
                    rhsusf_acc_su230_c = 1;
                    rhsusf_acc_su230_mrds_c = 1;
                    rhsusf_acc_su230a_c = 1;
                    rhsusf_acc_su230a_mrds_c = 1;
                    rhsusf_acc_su230_3d = 1;
                    rhsusf_acc_su230_mrds_3d = 1;
                    rhsusf_acc_su230a_3d = 1;
                    rhsusf_acc_su230a_mrds_3d = 1;
                    rhsusf_acc_su230_c_3d = 1;
                    rhsusf_acc_su230_mrds_c_3d = 1;
                    rhsusf_acc_su230a_c_3d = 1;
                    rhsusf_acc_su230a_mrds_c_3d = 1;
                    rhsusf_acc_SpecterDR = 1;
                    rhsusf_acc_SpecterDR_3d = 1;
                    rhsusf_acc_SpecterDR_A = 1;
                    rhsusf_acc_SpecterDR_A_3d = 1;
                    rhsusf_acc_SpecterDR_CX = 1;
                    rhsusf_acc_SpecterDR_CX_3D = 1;
                    rhsusf_acc_SpecterDR_pvs27 = 1;
                    rhsusf_acc_SpecterDR_D = 1;
                    rhsusf_acc_SpecterDR_OD = 1;
                    rhsusf_acc_SpecterDR_D_3D = 1;
                    rhsusf_acc_SpecterDR_OD_3D = 1;
                    rhsusf_acc_anpvs27 = 1;
                    rhsusf_acc_anpas13gv1 = 1;
                    rhsusf_acc_M2A1 = 1;
                    rhsusf_acc_ACOG_MDO = 1;
                    optic_Nightstalker = 1;
                    optic_tws = 1;
                    optic_tws_mg = 1;
                    optic_NVS = 1;
                    optic_SOS = 1;
                    optic_SOS_khk_F = 1;
                    optic_MRCO = 1;
                    optic_MRCO_broken = 1;
                    optic_Arco = 1;
                    optic_Arco_ghex_F = 1;
                    optic_Arco_blk_F = 1;
                    optic_Arco_AK_arid_F = 1;
                    optic_Arco_AK_blk_F = 1;
                    optic_Arco_AK_lush_F = 1;
                    optic_Arco_arid_F = 1;
                    optic_Arco_lush_F = 1;
                    optic_aco = 1;
                    optic_ACO_grn = 1;
                    optic_Aco_broken = 1;
                    optic_aco_smg = 1;
                    optic_ACO_grn_smg = 1;
                    optic_hamr = 1;
                    optic_Hamr_khk_F = 1;
                    optic_Hamr_broken = 1;
                    optic_Holosight = 1;
                    optic_Holosight_blk_F = 1;
                    optic_Holosight_khk_F = 1;
                    optic_Holosight_arid_F = 1;
                    optic_Holosight_lush_F = 1;
                    optic_Holosight_smg = 1;
                    optic_Holosight_smg_blk_F = 1;
                    optic_Holosight_smg_khk_F = 1;
                    optic_DMS = 1;
                    optic_DMS_ghex_F = 1;
                    optic_DMS_weathered_F = 1;
                    optic_DMS_weathered_Kir_F = 1;
                    optic_LRPS = 1;
                    optic_LRPS_ghex_F = 1;
                    optic_LRPS_tna_F = 1;
                    optic_AMS = 1;
                    optic_AMS_khk = 1;
                    optic_AMS_snd = 1;
                    optic_KHS_blk = 1;
                    optic_KHS_hex = 1;
                    optic_KHS_old = 1;
                    optic_KHS_tan = 1;
                    optic_ERCO_blk_F = 1;
                    optic_ERCO_khk_F = 1;
                    optic_ERCO_snd_F = 1;
                    optic_Yorris = 1;
                    gm_blits_ris_blk = 1;
                    gm_c79a1_blk = 1;
                    gm_c79a1_oli = 1;
                    gm_feroz24_ris_blk = 1;
                    gm_feroz51_ris_oli = 1;
                    gm_ls1500_ir_ris_blk = 1;
                    gm_ls1500_red_ris_blk = 1;
                    gm_ls45_ir_ris_blk = 1;
                    gm_ls45_red_ris_blk = 1;
                    gm_lsminiv_ir_ris_blk = 1;
                    gm_lsminiv_red_ris_blk = 1;
                    gm_maglite_3d_ris_blk = 1;
                    gm_rv_ris_blk = 1;
                    gm_streamlight_sl20_ris_blk = 1;
                    gm_streamlight_sl20_ris_brn = 1;
                    gm_zf10x42_ris_blk = 1;
                    gm_zf10x42_ris_oli = 1;
                    KA_Original_Sight_Carry_Handle = 1;
                    KA_Original_Sight_Flip_Up_Sight = 1;
                    KA_Elcan_black = 1;
                    KA_Elcan_sand = 1;
                    KA_Elcan_black_Folding_Sight_45_Degree = 1;
                    KA_Elcan_sand_Folding_Sight_45_Degree = 1;
                    KA_Rakurs = 1;
                    hlc_optic_LeupoldM3A = 1;
                    hlc_optic_ZF95Base = 1;
                    hlc_optic_VOMZ3d = 1;
                    hlc_optic_VOMZ = 1;
                    hlc_optic_HensoldtZO_Hi = 1;
                    hlc_optic_HensoldtZO_Hi_2D = 1;
                    hlc_optic_HensoldtZO_lo = 1;
                    hlc_optic_HensoldtZO_lo_2D = 1;
                    hlc_optic_HensoldtZO_lo_Docter = 1;
                    hlc_optic_HensoldtZO_lo_Docter_2D = 1;
                    hlc_optic_HensoldtZO_Hi_Docter = 1;
                    hlc_optic_HensoldtZO_Hi_Docter_2D = 1;
                    HLC_optic_DocterR = 1;
                    hlc_optic_ATACR_Offset = 1;
                    hlc_optic_ATACR = 1;
                    HLC_optic_Aimpoint3000 = 1;
                    HLC_optic_Aimpoint3000_Br4 = 1;
                    HLC_optic_Aimpoint3000_Br3 = 1;
                    HLC_optic_Aimpoint3000_Br2 = 1;
                    HLC_optic_Aimpoint3000_Br1 = 1;
                    HLC_optic_Aimpoint3000_Magnifier = 1;
                    HLC_optic_Aimpoint3000_Magnifier_Br4 = 1;
                    HLC_optic_Aimpoint3000_Magnifier_Br3 = 1;
                    HLC_optic_Aimpoint3000_Magnifier_Br2 = 1;
                    HLC_optic_Aimpoint3000_Magnifier_Br1 = 1;
                    HLC_optic_Aimpoint5000 = 1;
                    HLC_optic_Aimpoint5000_Br4 = 1;
                    HLC_optic_Aimpoint5000_Br3 = 1;
                    HLC_optic_Aimpoint5000_Br2 = 1;
                    HLC_optic_Aimpoint5000_Br1 = 1;
                    HLC_optic_Aimpoint5000_Sunshade = 1;
                    HLC_optic_aimpoint5000_Sunshade_Br4 = 1;
                    HLC_optic_aimpoint5000_Sunshade_Br3 = 1;
                    HLC_optic_aimpoint5000_Sunshade_Br2 = 1;
                    HLC_optic_aimpoint5000_Sunshade_Br1 = 1;
                    HLC_optic_Aimpoint5000_Magnifier = 1;
                    HLC_optic_aimpoint5000_Magnifier_Br4 = 1;
                    HLC_optic_aimpoint5000_Magnifier_Br3 = 1;
                    HLC_optic_aimpoint5000_Magnifier_Br2 = 1;
                    HLC_optic_aimpoint5000_Magnifier_Br1 = 1;
                    HLC_optic_ISM1400A7 = 1;
                    Tier1_Eotech551_Black = 1;
                    Tier1_Eotech551_3xMag_Black_Up = 1;
                    Tier1_Eotech551_3xMag_Black_Down = 1;
                    Tier1_Eotech551_L3_Black_Up = 1;
                    Tier1_Eotech551_L3_Black_Down = 1;
                    Tier1_Eotech551_Riser_Black = 1;
                    Tier1_Eotech551_3xMag_Riser_Black_Up = 1;
                    Tier1_Eotech551_3xMag_Riser_Black_Down = 1;
                    Tier1_Eotech551_L3_Riser_Black_Up = 1;
                    Tier1_Eotech551_L3_Riser_Black_Down = 1;
                    Tier1_Eotech551_Desert = 1;
                    Tier1_Eotech551_3xMag_Desert_Up = 1;
                    Tier1_Eotech551_3xMag_Desert_Down = 1;
                    Tier1_Eotech551_L3_Desert_Up = 1;
                    Tier1_Eotech551_L3_Desert_Down = 1;
                    Tier1_Eotech551_Riser_Desert = 1;
                    Tier1_Eotech551_3xMag_Riser_Desert_Up = 1;
                    Tier1_Eotech551_3xMag_Riser_Desert_Down = 1;
                    Tier1_Eotech551_L3_Riser_Desert_Up = 1;
                    Tier1_Eotech551_L3_Riser_Desert_Down = 1;
                    Tier1_Eotech553_Black = 1;
                    Tier1_Eotech553_3xMag_Black_Up = 1;
                    Tier1_Eotech553_3xMag_Black_Down = 1;
                    Tier1_Eotech553_L3_Black_Up = 1;
                    Tier1_Eotech553_L3_Black_Down = 1;
                    Tier1_Eotech553_Tan = 1;
                    Tier1_Eotech553_3xMag_Tan_Up = 1;
                    Tier1_Eotech553_3xMag_Tan_Down = 1;
                    Tier1_Eotech553_L3_TanBlack_Up = 1;
                    Tier1_Eotech553_L3_TanBlack_Down = 1;
                    Tier1_EXPS3_0_Black = 1;
                    Tier1_EXPS3_0_3xMag_Black_Up = 1;
                    Tier1_EXPS3_0_3xMag_Black_Down = 1;
                    Tier1_EXPS3_0_G33_Black_Up = 1;
                    Tier1_EXPS3_0_G33_Black_Down = 1;
                    Tier1_EXPS3_0_Riser_Black = 1;
                    Tier1_EXPS3_0_3xMag_Riser_Black_Up = 1;
                    Tier1_EXPS3_0_3xMag_Riser_Black_Down = 1;
                    Tier1_EXPS3_0_G33_Riser_Black_Up = 1;
                    Tier1_EXPS3_0_G33_Riser_Black_Down = 1;
                    Tier1_EXPS3_0_Desert = 1;
                    Tier1_EXPS3_0_3xMag_Desert_Up = 1;
                    Tier1_EXPS3_0_3xMag_Desert_Down = 1;
                    Tier1_EXPS3_0_G33_Desert_Up = 1;
                    Tier1_EXPS3_0_G33_Desert_Down = 1;
                    Tier1_EXPS3_0_Riser_Desert = 1;
                    Tier1_EXPS3_0_3xMag_Riser_Desert_Up = 1;
                    Tier1_EXPS3_0_3xMag_Riser_Desert_Down = 1;
                    Tier1_EXPS3_0_G33_Riser_Desert_Up = 1;
                    Tier1_EXPS3_0_G33_Riser_Desert_Down = 1;
                    Tier1_EXPS3_0_Tano = 1;
                    Tier1_EXPS3_0_3xMag_Tano_Up = 1;
                    Tier1_EXPS3_0_3xMag_Tano_Down = 1;
                    Tier1_EXPS3_0_G33_Tano_Up = 1;
                    Tier1_EXPS3_0_G33_Tano_Down = 1;
                    Tier1_EXPS3_0_Riser_Tano = 1;
                    Tier1_EXPS3_0_3xMag_Riser_Tano_Up = 1;
                    Tier1_EXPS3_0_3xMag_Riser_Tano_Down = 1;
                    Tier1_EXPS3_0_G33_Riser_Tano_Up = 1;
                    Tier1_EXPS3_0_G33_Riser_Tano_Down = 1;
                    Tier1_EXPS3_2_Black = 1;
                    Tier1_EXPS3_2_3xMag_Black_Up = 1;
                    Tier1_EXPS3_2_3xMag_Black_Down = 1;
                    Tier1_EXPS3_2_G33_Black_Up = 1;
                    Tier1_EXPS3_2_G33_Black_Down = 1;
                    Tier1_EXPS3_2_Riser_Black = 1;
                    Tier1_EXPS3_2_3xMag_Riser_Black_Up = 1;
                    Tier1_EXPS3_2_3xMag_Riser_Black_Down = 1;
                    Tier1_EXPS3_2_G33_Riser_Black_Up = 1;
                    Tier1_EXPS3_2_G33_Riser_Black_Down = 1;
                    Tier1_EXPS3_2_Desert = 1;
                    Tier1_EXPS3_2_3xMag_Desert_Up = 1;
                    Tier1_EXPS3_2_3xMag_Desert_Down = 1;
                    Tier1_EXPS3_2_G33_Desert_Up = 1;
                    Tier1_EXPS3_2_G33_Desert_Down = 1;
                    Tier1_EXPS3_2_Riser_Desert = 1;
                    Tier1_EXPS3_2_3xMag_Riser_Desert_Up = 1;
                    Tier1_EXPS3_2_3xMag_Riser_Desert_Down = 1;
                    Tier1_EXPS3_2_G33_Riser_Desert_Up = 1;
                    Tier1_EXPS3_2_G33_Riser_Desert_Down = 1;
                    Tier1_EXPS3_2_Tano = 1;
                    Tier1_EXPS3_2_3xMag_Tano_Up = 1;
                    Tier1_EXPS3_2_3xMag_Tano_Down = 1;
                    Tier1_EXPS3_2_G33_Tano_Up = 1;
                    Tier1_EXPS3_2_G33_Tano_Down = 1;
                    Tier1_EXPS3_2_Riser_Tano = 1;
                    Tier1_EXPS3_2_3xMag_Riser_Tano_Up = 1;
                    Tier1_EXPS3_2_3xMag_Riser_Tano_Down = 1;
                    Tier1_EXPS3_2_G33_Riser_Tano_Up = 1;
                    Tier1_EXPS3_2_G33_Riser_Tano_Down = 1;
                    Tier1_MicroT1_Low_Black = 1;
                    Tier1_MicroT1_Leap_Black = 1;
                    Tier1_MicroT1_Leap_3xMag_Black_Up = 1;
                    Tier1_MicroT1_Leap_3xMag_Black_Down = 1;
                    Tier1_MicroT1_Leap_Riser_Black = 1;
                    Tier1_MicroT1_Leap_3xMag_Riser_Black_Up = 1;
                    Tier1_MicroT1_Leap_3xMag_Riser_Black_Down = 1;
                    Tier1_MicroT1_Low_Desert = 1;
                    Tier1_MicroT1_Leap_Desert = 1;
                    Tier1_MicroT1_Leap_3xMag_Desert_Up = 1;
                    Tier1_MicroT1_Leap_3xMag_Desert_Down = 1;
                    Tier1_MicroT1_Leap_Riser_Desert = 1;
                    Tier1_MicroT1_Leap_3xMag_Riser_Desert_Up = 1;
                    Tier1_MicroT1_Leap_3xMag_Riser_Desert_Down = 1;
                    Tier1_MicroT2_Low_Black = 1;
                    Tier1_MicroT2_Black = 1;
                    Tier1_MicroT2_3xMag_Black_Up = 1;
                    Tier1_MicroT2_3xMag_Black_Down = 1;
                    Tier1_MicroT2_G33_Black_Up = 1;
                    Tier1_MicroT2_G33_Black_Down = 1;
                    Tier1_MicroT2_Riser_Black = 1;
                    Tier1_MicroT2_3xMag_Riser_Black_Up = 1;
                    Tier1_MicroT2_3xMag_Riser_Black_Down = 1;
                    Tier1_MicroT2_G33_Riser_Black_Up = 1;
                    Tier1_MicroT2_G33_Riser_Black_Down = 1;
                    Tier1_MicroT2_Low_Tan = 1;
                    Tier1_MicroT2_Tan = 1;
                    Tier1_MicroT2_3xMag_Tan_Up = 1;
                    Tier1_MicroT2_3xMag_Tan_Down = 1;
                    Tier1_MicroT2_G33_Tan_Up = 1;
                    Tier1_MicroT2_G33_Tan_Down = 1;
                    Tier1_MicroT2_Riser_Tan = 1;
                    Tier1_MicroT2_3xMag_Riser_Tan_Up = 1;
                    Tier1_MicroT2_3xMag_Riser_Tan_Down = 1;
                    Tier1_MicroT2_G33_Riser_Tan_Up = 1;
                    Tier1_MicroT2_G33_Riser_Tan_Down = 1;
                    Tier1_MicroT2_G33_Desert_Up = 1;
                    Tier1_MicroT2_G33_Desert_Down = 1;
                    Tier1_MicroT2_G33_Riser_Desert_Up = 1;
                    Tier1_MicroT2_G33_Riser_Desert_Down = 1;
                    Tier1_MicroT2_Leap_Black = 1;
                    Tier1_MicroT2_Leap_3xMag_Black_Up = 1;
                    Tier1_MicroT2_Leap_3xMag_Black_Down = 1;
                    Tier1_MicroT2_Leap_G33_Black_Up = 1;
                    Tier1_MicroT2_Leap_G33_Black_Down = 1;
                    Tier1_MicroT2_Leap_Riser_Black = 1;
                    Tier1_MicroT2_Leap_3xMag_Riser_Black_Up = 1;
                    Tier1_MicroT2_Leap_3xMag_Riser_Black_Down = 1;
                    Tier1_MicroT2_Leap_G33_Riser_Black_Up = 1;
                    Tier1_MicroT2_Leap_G33_Riser_Black_Down = 1;
                    Tier1_MicroT2_Leap_Tan = 1;
                    Tier1_MicroT2_Leap_3xMag_Tan_Up = 1;
                    Tier1_MicroT2_Leap_3xMag_Tan_Down = 1;
                    Tier1_MicroT2_Leap_G33_Tan_Up = 1;
                    Tier1_MicroT2_Leap_G33_Tan_Down = 1;
                    Tier1_MicroT2_Leap_G33_TanBlack_Up = 1;
                    Tier1_MicroT2_Leap_G33_TanBlack_Down = 1;
                    Tier1_MicroT2_Leap_Riser_Tan = 1;
                    Tier1_MicroT2_Leap_3xMag_Riser_Tan_Up = 1;
                    Tier1_MicroT2_Leap_3xMag_Riser_Tan_Down = 1;
                    Tier1_MicroT2_Leap_G33_Riser_Tan_Up = 1;
                    Tier1_MicroT2_Leap_G33_Riser_Tan_Down = 1;
                    Tier1_MicroT2_Leap_G33_Riser_TanBlack_Up = 1;
                    Tier1_MicroT2_Leap_G33_Riser_TanBlack_Down = 1;
                    Tier1_MicroT2_Leap_G33_Desert_Up = 1;
                    Tier1_MicroT2_Leap_G33_Desert_Down = 1;
                    Tier1_MicroT2_Leap_G33_Riser_Desert_Up = 1;
                    Tier1_MicroT2_Leap_G33_Riser_Desert_Down = 1;
                    Tier1_Romeo4T_BCD_Low_Black = 1;
                    Tier1_Romeo4T_BCD_4D_Low_Black = 1;
                    Tier1_Romeo4T_BCD_Black = 1;
                    Tier1_Romeo4T_BCD_4D_Black = 1;
                    Tier1_Romeo4T_BCD_G33_Black_Up = 1;
                    Tier1_Romeo4T_BCD_4D_G33_Black_Up = 1;
                    Tier1_Romeo4T_BCD_G33_Black_Down = 1;
                    Tier1_Romeo4T_BCD_4D_G33_Black_Down = 1;
                    Tier1_Romeo4T_BCD_Riser_Black = 1;
                    Tier1_Romeo4T_BCD_4D_Riser_Black = 1;
                    Tier1_Romeo4T_BCD_G33_Riser_Black_Up = 1;
                    Tier1_Romeo4T_BCD_4D_G33_Riser_Black_Up = 1;
                    Tier1_Romeo4T_BCD_G33_Riser_Black_Down = 1;
                    Tier1_Romeo4T_BCD_4D_G33_Riser_Black_Down = 1;
                    Tier1_Romeo4T_BCD_Low_Tan = 1;
                    Tier1_Romeo4T_BCD_4D_Low_Tan = 1;
                    Tier1_Romeo4T_BCD_Tan = 1;
                    Tier1_Romeo4T_BCD_4D_Tan = 1;
                    Tier1_Romeo4T_BCD_G33_Tan_Up = 1;
                    Tier1_Romeo4T_BCD_4D_G33_Tan_Up = 1;
                    Tier1_Romeo4T_BCD_G33_Tan_Down = 1;
                    Tier1_Romeo4T_BCD_4D_G33_Tan_Down = 1;
                    Tier1_Romeo4T_BCD_G33_TanBlack_Up = 1;
                    Tier1_Romeo4T_BCD_4D_G33_TanBlack_Up = 1;
                    Tier1_Romeo4T_BCD_G33_TanBlack_Down = 1;
                    Tier1_Romeo4T_BCD_4D_G33_TanBlack_Down = 1;
                    Tier1_Romeo4T_BCD_Riser_Tan = 1;
                    Tier1_Romeo4T_BCD_4D_Riser_Tan = 1;
                    Tier1_Romeo4T_BCD_G33_Riser_Tan_Up = 1;
                    Tier1_Romeo4T_BCD_4D_G33_Riser_Tan_Up = 1;
                    Tier1_Romeo4T_BCD_G33_Riser_Tan_Down = 1;
                    Tier1_Romeo4T_BCD_4D_G33_Riser_Tan_Down = 1;
                    Tier1_Romeo4T_BCD_G33_Riser_TanBlack_Up = 1;
                    Tier1_Romeo4T_BCD_4D_G33_Riser_TanBlack_Up = 1;
                    Tier1_Romeo4T_BCD_G33_Riser_TanBlack_Down = 1;
                    Tier1_Romeo4T_BCD_4D_G33_Riser_TanBlack_Down = 1;
                    Tier1_Romeo4T_BCQ_Low_Black = 1;
                    Tier1_Romeo4T_BCQ_2D_Low_Black = 1;
                    Tier1_Romeo4T_BCQ_Black = 1;
                    Tier1_Romeo4T_BCQ_2D_Black = 1;
                    Tier1_Romeo4T_BCQ_G33_Black_Up = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_Black_Up = 1;
                    Tier1_Romeo4T_BCQ_G33_Black_Down = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_Black_Down = 1;
                    Tier1_Romeo4T_BCQ_Riser_Black = 1;
                    Tier1_Romeo4T_BCQ_2D_Riser_Black = 1;
                    Tier1_Romeo4T_BCQ_G33_Riser_Black_Up = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_Riser_Black_Up = 1;
                    Tier1_Romeo4T_BCQ_G33_Riser_Black_Down = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_Riser_Black_Down = 1;
                    Tier1_Romeo4T_BCQ_Low_Tan = 1;
                    Tier1_Romeo4T_BCQ_2D_Low_Tan = 1;
                    Tier1_Romeo4T_BCQ_Tan = 1;
                    Tier1_Romeo4T_BCQ_2D_Tan = 1;
                    Tier1_Romeo4T_BCQ_G33_Tan_Up = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_Tan_Up = 1;
                    Tier1_Romeo4T_BCQ_G33_Tan_Down = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_Tan_Down = 1;
                    Tier1_Romeo4T_BCQ_G33_TanBlack_Up = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_TanBlack_Up = 1;
                    Tier1_Romeo4T_BCQ_G33_TanBlack_Down = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_TanBlack_Down = 1;
                    Tier1_Romeo4T_BCQ_Riser_Tan = 1;
                    Tier1_Romeo4T_BCQ_2D_Riser_Tan = 1;
                    Tier1_Romeo4T_BCQ_G33_Riser_Tan_Up = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_Riser_Tan_Up = 1;
                    Tier1_Romeo4T_BCQ_G33_Riser_Tan_Down = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_Riser_Tan_Down = 1;
                    Tier1_Romeo4T_BCQ_G33_Riser_TanBlack_Up = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_Riser_TanBlack_Up = 1;
                    Tier1_Romeo4T_BCQ_G33_Riser_TanBlack_Down = 1;
                    Tier1_Romeo4T_BCQ_2D_G33_Riser_TanBlack_Down = 1;
                    Tier1_Razor_Gen2_16 = 1;
                    Tier1_Razor_Gen2_16_PIP = 1;
                    Tier1_Razor_Gen2_16_CQB = 1;
                    Tier1_Razor_Gen2_16_CQB_PIP = 1;
                    Tier1_Razor_Gen2_16_ADM = 1;
                    Tier1_Razor_Gen2_16_ADM_PIP = 1;
                    Tier1_Razor_Gen2_16_ADM_CQB = 1;
                    Tier1_Razor_Gen2_16_ADM_CQB_PIP = 1;
                    Tier1_Razor_Gen2_16_Geissele = 1;
                    Tier1_Razor_Gen2_16_Geissele_PIP = 1;
                    Tier1_Razor_Gen2_16_Geissele_CQB = 1;
                    Tier1_Razor_Gen2_16_Geissele_CQB_PIP = 1;
                    Tier1_Razor_Gen2_16_Geissele_Docter = 1;
                    Tier1_Razor_Gen2_16_Geissele_Docter_PIP = 1;
                    Tier1_Razor_Gen2_16_Geissele_Docter_CQB = 1;
                    Tier1_Razor_Gen2_16_Geissele_Docter_CQB_PIP = 1;
                    Tier1_Razor_Gen3_110_ADM = 1;
                    Tier1_Razor_Gen3_110_ADM_PIP = 1;
                    Tier1_Razor_Gen3_110_ADM_CQB = 1;
                    Tier1_Razor_Gen3_110_ADM_CQB_PIP = 1;
                    Tier1_Razor_Gen3_110_ADM_T2 = 1;
                    Tier1_Razor_Gen3_110_ADM_T2_PIP = 1;
                    Tier1_Razor_Gen3_110_ADM_T2_CQB = 1;
                    Tier1_Razor_Gen3_110_ADM_T2_CQB_PIP = 1;
                    Tier1_Razor_Gen3_110_Geissele = 1;
                    Tier1_Razor_Gen3_110_Geissele_CQB = 1;
                    Tier1_Razor_Gen3_110_Geissele_PIP = 1;
                    Tier1_Razor_Gen3_110_Geissele_CQB_PIP = 1;
                    Tier1_Razor_Gen3_110_Geissele_Docter = 1;
                    Tier1_Razor_Gen3_110_Geissele_Docter_CQB = 1;
                    Tier1_Razor_Gen3_110_Geissele_Docter_PIP = 1;
                    Tier1_Razor_Gen3_110_Geissele_Docter_CQB_PIP = 1;
                    Tier1_LeupoldM3A_ADM_Black = 1;
                    Tier1_LeupoldM3A_ADM_Desert = 1;
                    Tier1_LeupoldM3A_ADM_Tan = 1;
                    Tier1_LeupoldM3A_ADM_T2_Black = 1;
                    Tier1_LeupoldM3A_ADM_T2_Desert = 1;
                    Tier1_LeupoldM3A_ADM_T2_Tan = 1;
                    Tier1_LeupoldM3A_Geissele_Black = 1;
                    Tier1_LeupoldM3A_Geissele_Desert = 1;
                    Tier1_LeupoldM3A_Geissele_Tan = 1;
                    Tier1_LeupoldM3A_Geissele_Docter_Black = 1;
                    Tier1_LeupoldM3A_Geissele_Docter_Desert = 1;
                    Tier1_LeupoldM3A_Geissele_Docter_Tan = 1;
                    Tier1_ANPVS10_Tan = 1;
                    Tier1_Elcan_156_C1_FDE_2D = 1;
                    Tier1_Elcan_156_C1_FDE_PIP = 1;
                    Tier1_Elcan_156_C1_Black_2D = 1;
                    Tier1_Elcan_156_C1_Black_PIP = 1;
                    Tier1_Elcan_156_C1_ARD_FDE_2D = 1;
                    Tier1_Elcan_156_C1_ARD_FDE_PIP = 1;
                    Tier1_Elcan_156_C1_ARD_Black_2D = 1;
                    Tier1_Elcan_156_C1_ARD_Black_PIP = 1;
                    Tier1_Elcan_156_C1_ARD_Docter_FDE_2D = 1;
                    Tier1_Elcan_156_C1_ARD_Docter_FDE_PIP = 1;
                    Tier1_Elcan_156_C1_ARD_Docter_Black_2D = 1;
                    Tier1_Elcan_156_C1_ARD_Docter_Black_PIP = 1;
                    Tier1_Elcan_156_C1_Docter_FDE_2D = 1;
                    Tier1_Elcan_156_C1_Docter_FDE_PIP = 1;
                    Tier1_Elcan_156_C1_Docter_Black_2D = 1;
                    Tier1_Elcan_156_C1_Docter_Black_PIP = 1;
                    Tier1_Elcan_156_C2_FDE_2D = 1;
                    Tier1_Elcan_156_C2_FDE_PIP = 1;
                    Tier1_Elcan_156_C2_Black_2D = 1;
                    Tier1_Elcan_156_C2_Black_PIP = 1;
                    Tier1_Elcan_156_C2_ARD_FDE_2D = 1;
                    Tier1_Elcan_156_C2_ARD_FDE_PIP = 1;
                    Tier1_Elcan_156_C2_ARD_Black_2D = 1;
                    Tier1_Elcan_156_C2_ARD_Black_PIP = 1;
                    Tier1_Elcan_156_C2_ARD_Docter_FDE_2D = 1;
                    Tier1_Elcan_156_C2_ARD_Docter_FDE_PIP = 1;
                    Tier1_Elcan_156_C2_ARD_Docter_Black_2D = 1;
                    Tier1_Elcan_156_C2_ARD_Docter_Black_PIP = 1;
                    Tier1_Elcan_156_C2_Docter_FDE_2D = 1;
                    Tier1_Elcan_156_C2_Docter_FDE_PIP = 1;
                    Tier1_Elcan_156_C2_Docter_Black_2D = 1;
                    Tier1_Elcan_156_C2_Docter_Black_PIP = 1;
                    Tier1_Elcan_156_C1_FDE = 1;
                    Tier1_Elcan_156_C1_Black = 1;
                    Tier1_Elcan_156_C1_ARD_FDE = 1;
                    Tier1_Elcan_156_C1_ARD_Black = 1;
                    Tier1_Elcan_156_C1_ARD_Docter_FDE = 1;
                    Tier1_Elcan_156_C1_ARD_Docter_Black = 1;
                    Tier1_Elcan_156_C1_Docter_FDE = 1;
                    Tier1_Elcan_156_C1_Docter_Black = 1;
                    Tier1_Elcan_156_C2_FDE = 1;
                    Tier1_Elcan_156_C2_Black = 1;
                    Tier1_Elcan_156_C2_ARD_FDE = 1;
                    Tier1_Elcan_156_C2_ARD_Black = 1;
                    Tier1_Elcan_156_C2_ARD_Docter_FDE = 1;
                    Tier1_Elcan_156_C2_ARD_Docter_Black = 1;
                    Tier1_Elcan_156_C2_Docter_FDE = 1;
                    Tier1_Elcan_156_C2_Docter_Black = 1;
                    Tier1_Shortdot_ADM_Black = 1;
                    Tier1_Shortdot_ADM_Black_PIP = 1;
                    Tier1_Shortdot_ADM_Black_CQB = 1;
                    Tier1_Shortdot_ADM_Black_CQB_PIP = 1;
                    Tier1_Shortdot_ADM_Tan = 1;
                    Tier1_Shortdot_ADM_Tan_PIP = 1;
                    Tier1_Shortdot_ADM_Tan_CQB = 1;
                    Tier1_Shortdot_ADM_Tan_CQB_PIP = 1;
                    Tier1_Shortdot_ADM_Desert = 1;
                    Tier1_Shortdot_ADM_Desert_PIP = 1;
                    Tier1_Shortdot_ADM_Desert_CQB = 1;
                    Tier1_Shortdot_ADM_Desert_CQB_PIP = 1;
                    Tier1_Shortdot_Geissele_Black = 1;
                    Tier1_Shortdot_Geissele_Black_PIP = 1;
                    Tier1_Shortdot_Geissele_Black_CQB = 1;
                    Tier1_Shortdot_Geissele_Black_CQB_PIP = 1;
                    Tier1_Shortdot_Geissele_Tan = 1;
                    Tier1_Shortdot_Geissele_Tan_PIP = 1;
                    Tier1_Shortdot_Geissele_Tan_CQB = 1;
                    Tier1_Shortdot_Geissele_Tan_CQB_PIP = 1;
                    Tier1_Shortdot_Geissele_Desert = 1;
                    Tier1_Shortdot_Geissele_Desert_PIP = 1;
                    Tier1_Shortdot_Geissele_Desert_CQB = 1;
                    Tier1_Shortdot_Geissele_Desert_CQB_PIP = 1;
                    Tier1_Shortdot_Geissele_Docter_Black = 1;
                    Tier1_Shortdot_Geissele_Docter_Black_PIP = 1;
                    Tier1_Shortdot_Geissele_Docter_Black_CQB = 1;
                    Tier1_Shortdot_Geissele_Docter_Black_CQB_PIP = 1;
                    Tier1_Shortdot_Geissele_Docter_Tan = 1;
                    Tier1_Shortdot_Geissele_Docter_Tan_PIP = 1;
                    Tier1_Shortdot_Geissele_Docter_Tan_CQB = 1;
                    Tier1_Shortdot_Geissele_Docter_Tan_CQB_PIP = 1;
                    Tier1_Shortdot_Geissele_Docter_Desert = 1;
                    Tier1_Shortdot_Geissele_Docter_Desert_PIP = 1;
                    Tier1_Shortdot_Geissele_Docter_Desert_CQB = 1;
                    Tier1_Shortdot_Geissele_Docter_Desert_CQB_PIP = 1;
                    Tier1_ATACR18_ADM_Black = 1;
                    Tier1_ATACR18_ADM_Black_PIP = 1;
                    Tier1_ATACR18_ADM_Black_CQB = 1;
                    Tier1_ATACR18_ADM_Black_CQB_PIP = 1;
                    Tier1_ATACR18_ADM_Desert = 1;
                    Tier1_ATACR18_ADM_Desert_PIP = 1;
                    Tier1_ATACR18_ADM_Desert_CQB = 1;
                    Tier1_ATACR18_ADM_Desert_CQB_PIP = 1;
                    Tier1_ATACR18_ADM_T1_Black = 1;
                    Tier1_ATACR18_ADM_T1_Black_PIP = 1;
                    Tier1_ATACR18_ADM_T1_Black_CQB = 1;
                    Tier1_ATACR18_ADM_T1_Black_CQB_PIP = 1;
                    Tier1_ATACR18_ADM_T1_Desert = 1;
                    Tier1_ATACR18_ADM_T1_Desert_PIP = 1;
                    Tier1_ATACR18_ADM_T1_Desert_CQB = 1;
                    Tier1_ATACR18_ADM_T1_Desert_CQB_PIP = 1;
                    Tier1_ATACR18_Geissele_Black = 1;
                    Tier1_ATACR18_Geissele_Black_PIP = 1;
                    Tier1_ATACR18_Geissele_Black_CQB = 1;
                    Tier1_ATACR18_Geissele_Black_CQB_PIP = 1;
                    Tier1_ATACR18_Geissele_Desert = 1;
                    Tier1_ATACR18_Geissele_Desert_PIP = 1;
                    Tier1_ATACR18_Geissele_Desert_CQB = 1;
                    Tier1_ATACR18_Geissele_Desert_CQB_PIP = 1;
                    Tier1_ATACR18_Geissele_Docter_Black = 1;
                    Tier1_ATACR18_Geissele_Docter_Black_PIP = 1;
                    Tier1_ATACR18_Geissele_Docter_Black_CQB = 1;
                    Tier1_ATACR18_Geissele_Docter_Black_CQB_PIP = 1;
                    Tier1_ATACR18_Geissele_Docter_Desert = 1;
                    Tier1_ATACR18_Geissele_Docter_Desert_PIP = 1;
                    Tier1_ATACR18_Geissele_Docter_Desert_CQB = 1;
                    Tier1_ATACR18_Geissele_Docter_Desert_CQB_PIP = 1;
                    KA_557_Magnifier_UP = 1;
                    KA_557_Magnifier_DOWN = 1;
                    KA_Eotech553 = 1;
                    Tier1_Razor_Gen2_16_Vanilla = 1;
                    Tier1_Razor_Gen2_16_ADM_Vanilla = 1;
                    Tier1_Razor_Gen2_16_Geissele_Vanilla = 1;
                    Tier1_Razor_Gen2_16_Geissele_Docter_Vanilla = 1;
                    Tier1_Razor_Gen3_110_ADM_Vanilla = 1;
                    Tier1_Razor_Gen3_110_ADM_T2_Vanilla = 1;
                    Tier1_Razor_Gen3_110_Geissele_Vanilla = 1;
                    Tier1_Razor_Gen3_110_Geissele_Docter_Vanilla = 1;
                    Tier1_Shortdot_ADM_Black_Vanilla = 1;
                    Tier1_Shortdot_ADM_Tan_Vanilla = 1;
                    Tier1_Shortdot_ADM_Desert_Vanilla = 1;
                    Tier1_Shortdot_Geissele_Black_Vanilla = 1;
                    Tier1_Shortdot_Geissele_Tan_Vanilla = 1;
                    Tier1_Shortdot_Geissele_Desert_Vanilla = 1;
                    Tier1_Shortdot_Geissele_Docter_Black_Vanilla = 1;
                    Tier1_Shortdot_Geissele_Docter_Tan_Vanilla = 1;
                    Tier1_Shortdot_Geissele_Docter_Desert_Vanilla = 1;
                    Tier1_ATACR18_ADM_Black_Vanilla = 1;
                    Tier1_ATACR18_ADM_Desert_Vanilla = 1;
                    Tier1_ATACR18_ADM_T1_Black_Vanilla = 1;
                    Tier1_ATACR18_ADM_T1_Desert_Vanilla = 1;
                    Tier1_ATACR18_Geissele_Black_Vanilla = 1;
                    Tier1_ATACR18_Geissele_Desert_Vanilla = 1;
                    Tier1_ATACR18_Geissele_Docter_Black_Vanilla = 1;
                    Tier1_ATACR18_Geissele_Docter_Desert_Vanilla = 1;
                    Tier1_Elcan_156_C1_FDE_Vanilla = 1;
                    Tier1_Elcan_156_C1_Black_Vanilla = 1;
                    Tier1_Elcan_156_C1_ARD_FDE_Vanilla = 1;
                    Tier1_Elcan_156_C1_ARD_Black_Vanilla = 1;
                    Tier1_Elcan_156_C1_Docter_FDE_Vanilla = 1;
                    Tier1_Elcan_156_C1_Docter_Black_Vanilla = 1;
                    Tier1_Elcan_156_C1_ARD_Docter_FDE_Vanilla = 1;
                    Tier1_Elcan_156_C1_ARD_Docter_Black_Vanilla = 1;
                    Tier1_Elcan_156_C2_FDE_Vanilla = 1;
                    Tier1_Elcan_156_C2_Black_Vanilla = 1;
                    Tier1_Elcan_156_C2_ARD_FDE_Vanilla = 1;
                    Tier1_Elcan_156_C2_ARD_Black_Vanilla = 1;
                    Tier1_Elcan_156_C2_Docter_FDE_Vanilla = 1;
                    Tier1_Elcan_156_C2_Docter_Black_Vanilla = 1;
                    Tier1_Elcan_156_C2_ARD_Docter_FDE_Vanilla = 1;
                    Tier1_Elcan_156_C2_ARD_Docter_Black_Vanilla = 1;
                };
            };
        };
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_338_green";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_snd";
            };
        };
    };

    // Sniper #4: M320 LRR .408
    // Ammo: 7Rnd_408_Mag
    #define B_PTbskull_Wea_sniper_04_m320_AMMO 7Rnd_408_Mag
    class srifle_LRR_tna_F;
    class srifle_LRR_tna_F_OCimport_01 : srifle_LRR_tna_F { scope = 0; class WeaponSlotsInfo; };
    class B_PTbskull_Wea_sniper_04_m320 : srifle_LRR_tna_F_OCimport_01 {
        displayName = "M320 LRR (.408 Cheetah)";
        author = "RoFz";
        access = 0;
        scope = 2;
        class WeaponSlotsInfo : WeaponSlotsInfo {
            allowedslots[] = {901};
            mass = 250;
        };
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr07_tremoe3ti_raptar";
            };
        };
    };

    // Sniper #5: Vychlop VSSK 12.7x55mm
    // Ammo: KA_5Rnd_STs_130VPS_AP
    #define B_PTbskull_Wea_sniper_05_vssk_AMMO KA_5Rnd_STs_130VPS_AP
    class KA_VSSK;
    class B_PTbskull_Wea_sniper_05_vssk : KA_VSSK {
        displayName = "VSSK (12.7x55mm)";
        author = "RoFz";
        access = 0;
        scope = 2;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
        };
    };

    // Sniper #6: ASP-1 Kir 12.7x55mm
    // Ammo: 10Rnd_127x54_Mag
    #define B_PTbskull_Wea_sniper_06_asp1_AMMO 10Rnd_127x54_Mag_PLUS
    class srifle_DMR_04_F;
    class srifle_DMR_04_F_OCimport_01 : srifle_DMR_04_F { scope = 0; class Single; };
    class B_PTbskull_Wea_sniper_06_asp1 : srifle_DMR_04_F_OCimport_01 {
        displayName = "ASP-1 (12.7x55mm)";
        author = "RoFz";
        access = 0;
        scope = 2;
        aiDispersionCoefX = 0.01; // 2
        aiDispersionCoefY = 0.01; // 3
        discreteDistance[] = { 100, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600 };
        dispersion = 0.00029;
        maxZeroing = 1600;
        magazines[] = {"10Rnd_127x54_Mag_PLUS","10Rnd_127x54_Mag"};
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
        class Single : Single {
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFireDispersion = 0.1; // 1
        };
        class single_close_optics1 : Single
        {
            aiRateOfFire = 0.5; // 2
            // aiRateOfFireDistance = 250; // 250
            dispersion = 0.0001; // 0.0029
            // maxRange = 400; // 400
            // maxRangeProbab = 0.9; // 0.01
            // midRange = 250; // 250
            // midRangeProbab = 0.9; // 0.8
            // minRange = 2; // 2
            // minRangeProbab = 0.6; // 0.05
        };
        class single_medium_optics1 : Single
        {
            aiRateOfFire = 1; // 2
            // aiRateOfFireDistance = 5000; // 450
            dispersion = 0.0001; // 0.0029
            // maxRange = 800; // 600
            // maxRangeProbab = 0.9; // 0.05
            // midRange = 750; // 400
            // midRangeProbab = 0.9; // 0.7
            // minRange = 250;
            // minRangeProbab = 0.6; // 0.05
        };
        class single_far_optics1 : Single
        {
            aiRateOfFire = 4; // 4
            aiRateOfFireDistance = 700; // 700
            dispersion = 0.0001; // 0.0029
            maxRange = 1000; // 800
            maxRangeProbab = 0.7; // 0.05
            midRange = 600; // 600
            midRangeProbab = 0.95; // 0.5
            minRange = 200; // 200
            minRangeProbab = 0.01; // 0.05
        };
        class single_far_optics2 : Single
        {
            aiRateOfFire = 4;
            aiRateOfFireDistance = 700;
            dispersion = 0.0001;
            maxRange = 1600;
            maxRangeProbab = 0.7;
            midRange = 900;
            midRangeProbab = 0.95;
            minRange = 400;
            minRangeProbab = 0.01;
        };
    };

    // Sniper #7: KA_CS5 (#1 Imp)
    // Ammo: KA_CS5_10rnd_M993_AP_mag
    #define B_PTbskull_Wea_sniper_07_mcmillan_AMMO KA_CS5_10rnd_M993_AP_mag
    class KA_CS5;
    class B_PTbskull_Wea_sniper_07_mcmillan : KA_CS5 {
        displayName = "McMillan CS5 (7.62x51mm NATO)";
        author = "RoFz";
        access = 0;
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "KA_CS5_Silencer";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "KA_CS5_Laser_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };

    // Sniper #8: WA2000 (#1 Acc)
    // Ammo: KA_6Rnd_300win_Mag
    #define B_PTbskull_Wea_sniper_08_wa2000_AMMO KA_6Rnd_300win_Mag
    class KA_WA2000;
    class B_PTbskull_Wea_sniper_08_wa2000 : KA_WA2000 {
        displayName = "Walther WA 2000 (.300 WM)";
        author = "RoFz";
        access = 0;
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "KA_WA2000_Silencer";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            // class LinkedItemsAcc {
            // };
            // class LinkedItemsUnder {
            // };
        };
    };

    // Sniper #9: DSR50 (#2 Acc; #2 Imp)
    // Ammo: KA_DSR50_3Rnd_x2_MK263_AP_Mag
    #define B_PTbskull_Wea_sniper_09_dsr50_AMMO KA_DSR50_3Rnd_x2_MK263_AP_Mag
    class KA_DSR50;
    class B_PTbskull_Wea_sniper_09_dsr50 : KA_DSR50 {
        displayName = "DSR-50 (.50 BMG)";
        author = "RoFz";
        access = 0;
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "KA_DSR50_Silencer";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsAcc { };
            class LinkedItemsUnder { };
        };
    };

    // Sniper #10: Cyrus 9.3x64mm
    // Ammo: 10Rnd_93x64_DMR_05_Mag
    class srifle_DMR_05_blk_F;
    class B_PTbskull_Wea_sniper_10_cyrus : srifle_DMR_05_blk_F {
        displayName = "Cyrus (9.3x64mm)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_93mmg";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };

    // Sniper #12: MAR-10 .338
    // Ammo: 10Rnd_338_Mag
    #define B_PTbskull_Wea_sniper_12_mar10_AMMO 10Rnd_338_Mag
    class srifle_DMR_02_F;
    class srifle_DMR_02_F_OCimport_01 : srifle_DMR_02_F { scope = 0; class WeaponSlotsInfo; };
    class B_PTbskull_Wea_sniper_12_mar10 : srifle_DMR_02_F_OCimport_01 {
        displayName = "MAR-10 (.338 LM)";
        author = "RoFz";
        scope = 2;
        class WeaponSlotsInfo : WeaponSlotsInfo {
            allowedslots[] = {901};
            mass = 250;
        };
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_338_black";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };

    // Sniper #13: Snipex Alligator
    // Ammo: 10Rnd_93x64_DMR_05_Mag
    #define B_PTbskull_Wea_sniper_13_alligator_AMMO 5Rnd_145_mag_B // or 5Rnd_145_mag_BZT // B = AP; Z = Inc.; T = tracer
    class amrifle_alligator_b;
    class amrifle_alligator_b_OCimport_01 : amrifle_alligator_b { access = 0; scope = 0; class Single; };
    class B_PTbskull_Wea_sniper_13_alligator : amrifle_alligator_b_OCimport_01 {
        displayName = "Snipex Alligator (14.5x114mm)";
        access = 0;
        scope = 2;
        class Single : Single {
            aiDispersionCoefX = 0.01;
            aiDispersionCoefY = 0.01;
            aiRateOfFire = 0.9;
            aiRateOfFireDispersion = 0.1;
        };
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };

    // Shotgun: Model 97
    class bnae_m97_s_virtual;
    class B_PTbskull_Wea_shotgun_1_winch : bnae_m97_s_virtual {
        displayName = "Winchester Model 1897 Carbine (12-gauge)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "";
            };
        };
    };

    // Shotgun: SPAS-12
    // Ammo: 8Rnd_SPAS12_buck
    #define B_PTbskull_Wea_shotgun_2_spas_AMMO 8Rnd_SPAS12_buck
    class KA_SPAS12;
    class B_PTbskull_Wea_shotgun_2_spas : KA_SPAS12 {
        displayName = "SPAS (12-gauge)";
        author = "RoFz";
        scope = 2;
    };

    // Shotgun: Benelli M1014
    // Ammo: 6Rnd_M1014_buck
    #define B_PTbskull_Wea_shotgun_3_benelli_AMMO 6Rnd_M1014_buck
    class KA_M1014;
    class B_PTbskull_Wea_shotgun_3_benelli : KA_M1014 {
        displayName = "Benelli M1014 (12-gauge)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Yorris";
            };
        };
    };

    // AR #1: SCAR-H (#1 Imp)
    // Ammo: KA_SCAR_H_20rnd_M993_AP_mag
    class KA_SCAR_H_Black_Grip;
    class B_PTbskull_Wea_ar_01_scarh : KA_SCAR_H_Black_Grip {
        displayName = "FN SCAR-H (7.62x51mm NATO)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "SCAR_13_Inches_Barrel_Silencer";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "KA_SCAR_H_Laser_Black_IR";
            };
            class LinkedItemsUnder { };
        };
    };

    // AR #2: (#2 Imp)
    // Ammo: JAS_RSASS_20rnd_M993_AP_mag
    class JAS_PRS_RSASS_Blk;
    class B_PTbskull_Wea_ar_02_r11 : JAS_PRS_RSASS_Blk {
        displayName = "Remington R11 RSASS (7.62x51mm NATO)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "JAS_SDN6_Suppressor";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "rhsusf_acc_harris_bipod";
            };
        };
    };

    // AR #3:
    // Ammo: hlc_50rnd_300BLK_STANAG_EPR
    class hlc_rifle_honeybase_x15;
    class B_PTbskull_Wea_ar_03_honey : hlc_rifle_honeybase_x15 {
        displayName = "AAC Honey Badger (.300 AAC Blackout)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_HBADGER";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "hlc_acc_LS321G";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "hlc_grip_AFG2";
            };
        };
    };

    // AR #4: (#1 Imp)
    // Ammo: KA_SCAR_H_20rnd_M993_AP_mag + 1Rnd_HE_Grenade_shell
    class KA_SCAR_H_Black_EGLM;
    class B_PTbskull_Wea_ar_04_scarh : KA_SCAR_H_Black_EGLM {
        displayName = "SCAR-H 13in. SD (7.62x51mm NATO)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "SCAR_13_Inches_Barrel_Silencer";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "KA_SCAR_H_Laser_Black_IR";
            };
            class LinkedItemsUnder { };
        };
    };

    // AR #5:
    // Ammo: 30Rnd_65x39_caseless_green + 10Rnd_50BW_Mag_F
    class arifle_ARX_ghex_DMS_Pointer_Snds_Bipod_F;
    class B_PTbskull_Wea_ar_05_type115 : arifle_ARX_ghex_DMS_Pointer_Snds_Bipod_F {
        displayName = "Type 115 (6.5x39mm + .50 BW)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_65_TI_ghex_F";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };

    // AR #6:
    // Ammo: 20Rnd_762x51_Mag
    class arifle_SPAR_03_blk_F;
    class B_PTbskull_Wea_ar_06_spar17 : arifle_SPAR_03_blk_F {
        displayName = "SPAR-17 (7.62x51mm)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_B";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };

    // AR #7:
    // Ammo: MRC_492x34_RT_skin1
        #define B_PTbskull_Wea_ar_07_mrc_AMMO MRC_492x34_RT_skin1
    class MRC_GL_Black;
    class B_PTbskull_Wea_ar_07_mrc : MRC_GL_Black {
        displayName = "MR-C (6.8mm)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "MRC_Silencer";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_ERCO_blk_F";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "KA_MRC_Laser_IR";
            };
        };
    };

    // AR #8:
    // Ammo: MRC_492x34_RT_skin1
        #define B_PTbskull_Wea_ar_08_xm7_AMMO ICM_XM7_Magazine_277_Fury_BP_F
    class ICM_XM7_F;
    class B_PTbskull_Wea_ar_08_xm7 : ICM_XM7_F {
        displayName = "XM-7 (6.8x51mm)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "ICM_SLX_Suppressor_F";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "TOTT_XPS3_g33";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
        };
    };

    // MG #1:
    // Ammo: 130Rnd_338_Mag
    class MMG_02_black_F;
    class MMG_02_black_F_OCimport_01 : MMG_02_black_F { scope = 0; class manual; };
    class B_PTbskull_Wea_mg_01_smpg : MMG_02_black_F_OCimport_01 {
        displayName = "SPMG (.338 NM)";
        author = "RoFz";
        scope = 2;
        class close : manual
        {
            burst = 12;
            aiBurstTerminable = 1;
        };
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_338_black";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_tws_mg";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };

    // MG #2:
    // Ammo: 150Rnd_93x64_Mag
    class MMG_01_tan_F;
    class MMG_01_tan_F_OCimport_01 : MMG_01_tan_F { scope = 0; class manual; };
    class B_PTbskull_Wea_mg_02_navid : MMG_01_tan_F_OCimport_01 {
        displayName = "Navid (9.3x64mm)";
        author = "RoFz";
        scope = 2;
        class close : manual
        {
            burst = 12;
            aiBurstTerminable = 1;
        };
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_93mmg";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_tws_mg";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_02_F_tan";
            };
        };
    };

    // MG #3 - Russian:
    // AMMO: 75rnd_762x39_AK12_Mag_Tracer_F
    #define B_PTbskull_Wea_mg_3_AMMO 75rnd_762x39_AK12_Mag_Tracer_F
    class arifle_RPK12_F;
    class arifle_RPK12_F_OCimport_01 : arifle_RPK12_F { scope = 0; };
    class B_PTbskull_Wea_mg_03_rpk : arifle_RPK12_F_OCimport_01 {
        displayName = "RPK-12 (7.62x39mm)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_B";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_02_F_tan";
            };
        };
    };

    // MG #4 - XM250
    // AMMO: 75rnd_762x39_AK12_Mag_Tracer_F
    #define B_PTbskull_Wea_mg_04_xm250_AMMO KAR_100Rnd_Fury_RT_blk
    class KAR_XM250_BLK;
    class KAR_XM250_BLK_OCimport_01 : KAR_XM250_BLK { scope = 0; };
    class B_PTbskull_Wea_mg_04_xm250 : KAR_XM250_BLK_OCimport_01 {
        displayName = "XM-250 (6.8x51mm)";
        author = "RoFz";
        scope = 2;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "KAR_XM250_SUP_BLK";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
        };
    };


    // SMG #1: Vermin SMG .45 *
    class SMG_01_F;
    class SMG_01_F_OCimport_01 : SMG_01_F { scope = 0; };
    class SMG_01_F_OCimport_02 : SMG_01_F_OCimport_01 { };
    class B_PTbskull_Wea_SMG_01_vermin: SMG_01_F_OCimport_02 {
        displayName="Vermin SMG (.45 ACP)";
        author = "RoFz";
        scope = 2;
        class LinkedItems
        {
            class LinkedItemsMuzzle {
                slot="MuzzleSlot";
                item="muzzle_snds_acp";
            };
            class LinkedItemsOptic {
                slot="CowsSlot";
                item="optic_Aco_smg";
            };
            class LinkedItemsAcc {
                slot="PointerSlot";
                item="acc_flashlight_smg_01";
            };
        };
    };

    // SMG #2: Sting 9mm
    // Ammo: 30Rnd_9x21_Mag_SMG_02_Tracer_Green
    #define B_PTbskull_Wea_SMG_02_sting_AMMO 30Rnd_9x21_Mag_SMG_02_Tracer_Green
    class SMG_02_F;
    class B_PTbskull_Wea_SMG_02_sting: SMG_02_F {
        displayName="Sting SMG (9mm)";
        author = "RoFz";
        scope = 2;
        class LinkedItems
        {
            class LinkedItemsMuzzle {
                slot="MuzzleSlot";
                item="muzzle_snds_L";
            };
            class LinkedItemsOptic {
                slot="CowsSlot";
                item="optic_Aco_smg";
            };
            class LinkedItemsAcc {
                slot="PointerSlot";
                item="acc_pointer_IR";
            };
        };
    };
