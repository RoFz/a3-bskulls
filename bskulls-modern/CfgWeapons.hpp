class Mode_SemiAuto;
class Mode_Burst;
class cfgWeapons {

    // Handgun: R1 Enhanced .45ACP (Engraved)
    class bnae_r1_e_virtual;
    class BSKULLS_pistol_1 : bnae_r1_e_virtual {
        displayName = "R1 Enhanced Engraved SD (.45 ACP)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "bnae_suppressor_v4_virtual";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "bnae_reddot_virtual";
            };
            class LinkedItemsAcc { };
            class LinkedItemsUnder { };
        };
    };

    // Handgun: SIG Sauer P226R Combat
    // Ammo: hlc_12Rnd_357SIG_B_P226
    #define BSKULLS_pistol_2_AMMO "hlc_12Rnd_357SIG_B_P226"
    class hlc_pistol_P226R_357Combat;
    class hlc_pistol_P226R_357Combat_OCimport_01 : hlc_pistol_P226R_357Combat { scope = 0; class Single; };
    class BSKULLS_pistol_2 : hlc_pistol_P226R_357Combat_OCimport_01 {
        displayName = "SIG Sauer P226R SD (.357 SIG)";
        scope = 1;
        // magazines[] = {"hlc_12Rnd_357SIG_B_P226","hlc_12Rnd_357SIG_JHP_P226"};
        class Single : Single {
            aiRateOfFire = 0.5;
        };
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "hlc_muzzle_TiRant9S";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "HLC_Optic_Docter_CADEX";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "hlc_acc_DBALPL_FL";
            };
            class LinkedItemsUnder { };
        };
    };

    // Handgun: FN Five-seven FN 5.7x28mm
    // Ammo: 20Rnd_57x28_SS198
    #define BSKULLS_pistol_3_AMMO "20Rnd_57x28_SS198"
    class kt_FN57_tan;
    class kt_FN57_tan_OCimport_01 : kt_FN57_tan { scope = 0; class Single; };
    class BSKULLS_pistol_3 : kt_FN57_tan_OCimport_01 {
        displayName = "FN Five-seven SD (FN 5.7x28mm)";
        scope = 1;
        class Single : Single {
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFire = 0.3; // 2
            aiRateOfFireDispersion = 0; // 1
            maxRange = 50; // 100
            maxRangeProbab = 0.1; // 0.1
            midRange = 30; // 50
            midRangeProbab = 0.3; // 0.6
            minRange = 1; // 10
            minRangeProbab = 0.6; // 0.3
        };
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "kt_FN57_Silencer";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "kt_FN57_Laser_IR";
            };
        };
    };

    // Sniper #1: M110A1
    // Ammo: kt_20Rnd_762x51_Ball_XM1158_AP_Mag
    class kt_M110A1_blk02;
    class BSKULLS_sniper_1 : kt_M110A1_blk02 {
        displayName = "H&K M110A1 SDMR (7.62x51mm NATO)";
        scope = 1;

        // magazines[] = {"20Rnd_762x51_Mag","BC_20Rnd_762_MEA_Stanag","rhsusf_20Rnd_762x51_m118_special_Mag","rhsusf_20Rnd_762x51_m993_Mag","rhsusf_20Rnd_762x51_m62_Mag","ACE_20Rnd_762x51_M118LR_Mag","ACE_20Rnd_762x51_M993_AP_Mag","ACE_20Rnd_762x51_Mk319_Mod_0_Mag","ACE_20Rnd_762x51_Mk316_Mod_0_Mag","kt_20Rnd_762x51_178gr_ELD_X_Mag","kt_20Rnd_762x51_Mk316_Mod_0_Mag"};
        // maxRange = 500;
        // maxRangeProbab = 0.04;
        // midRange = 150;
        // midRangeProbab = 0.58;
        // minRange = 1;
        // minRangeProbab = 0.3;

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
                item = "Tier1_LA5_Side";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };

    // Sniper #2: TRG 42F MMRS .338
    // Ammo: 5Rnd_APDS_338LM_Magazine
    class bnae_trg42_f_mmrs_virtual;
    class BSKULLS_sniper_2 : bnae_trg42_f_mmrs_virtual {
        displayName = "Sako TRG-42 MMRS (.338 LM)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "bnae_silencer_virtual";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsAcc { };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bnae_bipod_blk_virtual";
            };
        };
    };

    // Sniper #3: Falkor Petra
    class bnae_falkor_snd_virtual;
    class BSKULLS_sniper_3 : bnae_falkor_snd_virtual {
        displayName = "Falkor Petra (.300 WM)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_338_green";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_LRPS";
            };
            // class LinkedItemsAcc {
            //     slot = "PointerSlot";
            //     item = "";
            // };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_snd";
            };
        };
    };

    // Sniper #4: M-14 EBR-RI
    class rhs_weap_m14ebrri;
    class BSKULLS_sniper_4 : rhs_weap_m14ebrri {
        displayName = "M14 EBR-RI (7.62x51mm NATO)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "rhsusf_acc_aac_m14dcqd_silencer";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "rhsusf_acc_anpeq15side_bk";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "rhsusf_acc_harris_bipod";
            };
        };
    };

    // Sniper #5: AX50SD
    // Ammo: 5Rnd_127x99_Ball_TAC50 (soft targets) / 10Rnd_127x99_API_TAC50 (explosive)
    class ax50_bolt2;
    class BSKULLS_sniper_5 : ax50_bolt2 {
        displayName = "AX-50 (12.7x99mm)";
        scope = 1;

        // magazines[] = {"5Rnd_127x108_Mag","5Rnd_127x108_APDS_Mag","ACE_5Rnd_127x99_Mag","ACE_5Rnd_127x99_AMAX_Mag","ACE_5Rnd_127x99_API_Mag","5Rnd_127x99_AXMX_TAC50","5Rnd_127x99_API_TAC50","5Rnd_127x99_Ball_TAC50","5Rnd_127x108_APDS_TAC50","5Rnd_127x108_Ball_TAC50"};
        // maxRange = 500;
        // maxRangeProbab = 0.04;
        // midRange = 150;
        // midRangeProbab = 0.58;
        // minRange = 1;
        // minRangeProbab = 0.3;

        class LinkedItems {
            // class LinkedItemsMuzzle {
            //     slot = "MuzzleSlot";
            //     item = "kt_tac50_silencer";
            // };
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

    // Sniper #6: AXMC (#1 Ran)
    // Ammo: kt_338_NM_Mag
    #define BSKULLS_sniper_6_AMMO "kt_338_NM_Mag_PLUS"
    class kt_axmcasr_blk1;
    class kt_axmcasr_blk1_OCimport_01 : kt_axmcasr_blk1 { scope = 0; class Single; };
    // class kt_axmcasr_blk1_OCimport_02 : kt_axmcasr_blk1_OCimport_01
    // {
    //     class Single;
    // };
    class BSKULLS_sniper_6 : kt_axmcasr_blk1_OCimport_01 {
        displayName = "AXMC+ (.338LM)";
        scope = 2;
        magazines[] += {"kt_338_NM_Mag_PLUS"}; // kt_338_NM_Mag
        maxLeadSpeed = 80; // 23
        class Single : Single {};
        class single_close_optics1 : Single 
        {
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFire = 1; // 2
            aiRateOfFireDispersion = 0; // 1
            aiRateOfFireDistance = 300; // 500
            maxRange = 500; // 600
            maxRangeProbab = 0.01; // 0.04
            midRange = 300; // 300
            midRangeProbab = 0.8; // 0.58
            minRange = 50; // 30
            minRangeProbab = 0.05; // 0.25
            requiredOpticType = 1; // -1
            showToPlayer = 0; // 1
        };
        class single_medium_optics1 : single_close_optics1
        {
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFire = 1; // 2
            aiRateOfFireDispersion = 0; // 1
            aiRateOfFireDistance = 500; // 500
            maxRange = 700; // 600
            maxRangeProbab = 0.05; // 0.04
            midRange = 500; // 300
            midRangeProbab = 0.7; // 0.58
            minRange = 300; // 30
            minRangeProbab = 0.05; // 0.25
        };
		class single_far_optics1 : single_medium_optics1 
		{
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFire = 1; // 2
            aiRateOfFireDispersion = 0; // 1
            aiRateOfFireDistance = 1000; // 500
            maxRange = 1500; // 600
            maxRangeProbab = 0.05; // 0.04
            midRange = 1000; // 300
            midRangeProbab = 0.5; // 0.58
            minRange = 500; // 30
            minRangeProbab = 0.05; // 0.25
            requiredOpticType = 2; // -1
		};
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                 item = "kt_338_silencer_01";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_atacr06_tremoe3ti_raptar";
            };
            class LinkedItemsUnder {
            };
        };
    };


    // Sniper #7: KA_CS5 (#1 Imp)
    // Ammo: KA_CS5_10rnd_M993_AP_mag
    class KA_CS5;
    class BSKULLS_sniper_7 : KA_CS5 {
        displayName = "McMillan CS5 (7.62x51mm NATO)";
        scope = 1;
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
    class KA_WA2000;
    class BSKULLS_sniper_8 : KA_WA2000 {
        displayName = "Walther WA 2000 (.300 WM)";
        scope = 1;
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
    class KA_DSR50;
    class BSKULLS_sniper_9 : KA_DSR50 {
        displayName = "DSR-50 (.50 BMG)";
        scope = 1;
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
    class BSKULLS_sniper_10 : srifle_DMR_05_blk_F {
        displayName = "Cyrus (9.3x64mm)";
        scope = 1;
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
                item = "bipod_02_F_blk";
            };
        };
    };

    // Shotgun: Model 97
    class bnae_m97_s_virtual;
    class BSKULLS_shotgun_1 : bnae_m97_s_virtual {
        displayName = "Winchester Model 1897 Carbine (12-gauge)";
        scope = 1;
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

    // // AR #1: MCX Virtus .300BLK
    // class Tier1_SIG_MCX_115_Virtus_300BLK_Black;
    // class BSKULLS_ar_1 : Tier1_SIG_MCX_115_Virtus_300BLK_Black {
    //     displayName = "SIG Sauer MCX-Virtus (.300 AAC Blackout)";
    //     scope = 1;
    //     class LinkedItems {
    //         class LinkedItemsMuzzle {
    //             slot = "MuzzleSlot";
    //             item = "Tier1_Gemtech_Halo";
    //         };
    //         class LinkedItemsOptic {
    //             slot = "CowsSlot";
    //             item = "optic_Nightstalker";
    //         };
    //         class LinkedItemsAcc {
    //             slot = "PointerSlot";
    //             item = "Tier1_MCX_LA5_Side";
    //         };
    //         class LinkedItemsUnder {
    //             slot = "UnderBarrelSlot";
    //             item = "Tier1_AFG_MLOK_Black";
    //         };
    //     };
    // };

    // AR #2: SCAR-H (#1 Imp)
    // Ammo: KA_SCAR_H_20rnd_M993_AP_mag
    class KA_SCAR_H_Black_Grip;
    class BSKULLS_ar_2 : KA_SCAR_H_Black_Grip {
        displayName = "FN SCAR-H (7.62x51mm NATO)";
        scope = 1;
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

    // AR #3: (#2 Imp)
    // Ammo: JAS_RSASS_20rnd_M993_AP_mag
    class JAS_PRS_RSASS_Blk;
    class BSKULLS_ar_3 : JAS_PRS_RSASS_Blk {
        displayName = "Remington R11 RSASS (7.62x51mm NATO)";
        scope = 1;
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

    // // AR #4: 
    // class rhs_weap_hk416d10_m320;
    // class BSKULLS_ar_4 : rhs_weap_hk416d10_m320 {
    //     displayName = "H&K HK416 D10RS (5.56x45mm NATO)";
    //     scope = 1;
    //     class LinkedItems {
    //         class LinkedItemsMuzzle {
    //             slot = "MuzzleSlot";
    //             item = "Tier1_Gemtech_Halo";
    //         };
    //         class LinkedItemsOptic {
    //             slot = "CowsSlot";
    //             item = "optic_Nightstalker";
    //         };
    //         class LinkedItemsAcc {
    //             slot = "PointerSlot";
    //             item = "acc_pointer_IR";
    //         };
    //         class LinkedItemsUnder { };
    //     };
    // };

    // // AR #5: 
    // class ar15_sig516;
    // class BSKULLS_ar_5 : ar15_sig516 {
    //     displayName = "SIG516 (5.56x45mm NATO)";
    //     scope = 1;
    //     class LinkedItems {
    //         class LinkedItemsMuzzle {
    //             slot = "MuzzleSlot";
    //             item = "rhsusf_acc_nt4_black";
    //         };
    //         class LinkedItemsOptic {
    //             slot = "CowsSlot";
    //             item = "optic_Nightstalker";
    //         };
    //         class LinkedItemsAcc {
    //             slot = "PointerSlot";
    //             item = "acc_pointer_IR";
    //         };
    //         class LinkedItemsUnder { };
    //     };
    // };

    // AR #6:
    // Ammo: hlc_50rnd_300BLK_STANAG_EPR
    class hlc_rifle_honeybase_x15;
    class BSKULLS_ar_6 : hlc_rifle_honeybase_x15 {
        displayName = "AAC Honey Badger (.300 AAC Blackout)";
        scope = 1;
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
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder { };
        };
    };

    // AR #7: (#1 Imp)
    // Ammo: KA_SCAR_H_20rnd_M993_AP_mag + 1Rnd_HE_Grenade_shell
    class KA_SCAR_H_Black_EGLM;
    class BSKULLS_ar_7 : KA_SCAR_H_Black_EGLM {
        displayName = "SCAR-H 13in. SD (7.62x51mm NATO)";
        scope = 1;
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

    // AR #8: 
    // class MCX_Spear_B;
    // class BSKULLS_ar_8 : MCX_Spear_B {
    //     displayName = "SIG Sauer MCX-Spear (6.8x51mm)";
    //     scope = 1;
    //     class LinkedItems {
    //         class LinkedItemsMuzzle {
    //             slot = "MuzzleSlot";
    //             item = "muzzle_spear_b";
    //         };
    //         class LinkedItemsOptic {
    //             slot = "CowsSlot";
    //             item = "optic_Nightstalker";
    //         };
    //         class LinkedItemsAcc {
    //             slot = "PointerSlot";
    //             item = "BC_ACC_B_IR_MCXV";
    //         };
    //         class LinkedItemsUnder {
    //         };
    //     };
    // };

    // AR #9: 
    // Ammo: 30Rnd_65x39_caseless_green + 10Rnd_50BW_Mag_F
    class arifle_ARX_ghex_DMS_Pointer_Snds_Bipod_F;
    class BSKULLS_ar_9 : arifle_ARX_ghex_DMS_Pointer_Snds_Bipod_F {
        displayName = "Type 115 (6.5x39mm + .50 BW)";
        scope = 1;
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
                item = "bipod_02_F_blk";
            };
        };
    };

    // BR #1: 
    // Ammo: kt_20Rnd_65_Creedmoor_108gr_AP_mag
    class sig716_02_65;
    class BSKULLS_br_1 : sig716_02_65 {
        displayName = "SIG716 (6.5x48mm CM)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "kt_m110a1_silencer_06";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "kt_8x_Dot10_up";
                // item = "optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "rhsusf_acc_anpeq15side_bk";
            };
            // class LinkedItemsUnder { };
        };
    };

    // MG #1: 
    class MMG_02_black_F;
    class MMG_02_black_F_OCimport_01 : MMG_02_black_F { scope = 0; class manual; };
    class BSKULLS_mg_1 : MMG_02_black_F_OCimport_01 {
        displayName = "SPMG (.338 NM)";
        scope = 1;
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
    class MMG_01_tan_F;
    class MMG_01_tan_F_OCimport_01 : MMG_01_tan_F { scope = 0; class manual; };
    class BSKULLS_mg_2 : MMG_01_tan_F_OCimport_01 {
        displayName = "Navid (9.3x64mm)";
        scope = 1;
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

    // SMG #1: Vermin SMG .45 *
    class SMG_01_F;
    class BSKULLS_SMG_01: SMG_01_F {
        displayName="Vermin SMG (.45 ACP)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle {
                slot="MuzzleSlot";
                item="muzzle_snds_acp";
            };
            class LinkedItemsOptic {
                slot="CowsSlot";
                item="optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot="PointerSlot";
                item="acc_flashlight_smg_01";
            };
        };
    };

    // SMG #2: Sting 9mm
    class SMG_02_F;
    class BSKULLS_SMG_02: SMG_02_F {
        displayName="Sting SMG (9mm)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle {
                slot="MuzzleSlot";
                item="muzzle_snds_L";
            };
            class LinkedItemsOptic {
                slot="CowsSlot";
                item="optic_Nightstalker";
            };
            class LinkedItemsAcc {
                slot="PointerSlot";
                item="acc_pointer_IR";
            };
        };
    };

    // LAW #1: Titan Compact
    class launch_I_Titan_short_F;
    // class launch_I_Titan_short_F_OCimport_01 : launch_I_Titan_short_F { scope = 0; class EventHandlers; class OpticsModes; };
    // class launch_I_Titan_short_F_OCimport_02 : launch_I_Titan_short_F_OCimport_01
    // {
    //     class EventHandlers;
    //     class OpticsModes : OpticsModes
    //     {
    //         class StepScope;
    //     };
    // };
    class BSKULLS_law_01: launch_I_Titan_short_F {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        access = 1;
        displayName="Titan+ MPRL Compact (127mm)";
    
        // maxRange = 1800; // 500
        // maxRangeProbab = 0.7; // 0.04
        // midRange = 750; // 150
        // midRangeProbab = 0.9; // 0.58
        // minRange = 100; // 20
        // minRangeProbab = 0.9; // 0.3

        // distanceZoomMax = 900;
        // distanceZoomMin = 100;

        magazines[] = {"Titan_AT_PLUS","Titan_AP"};

        // inheritsFrom (configfile >> "CfgWeapons" >> "launch_I_Titan_short_F" >> "OpticsModes"); // none 
        // inheritsFrom (configfile >> "CfgWeapons" >> "launch_I_Titan_short_F" >> "OpticsModes" >> "StepScope"); // none
        // class OpticsModes : OpticsModes
        // {
        //     class StepScope : StepScope {
        //         distanceZoomMin = 100; // 300
        //         distanceZoomMin = 900; // 300
        //         nFovLimit = 0.08333; // 0.08333
        //         opticsZoomInit = "0.25/7"; // 0.08333
        //         opticsZoomMax = "0.25/7"; // 0.04167
        //         opticsZoomMin = "0.25/35"; // 0.08333
        //     };
        // };

        // inheritsFrom (configfile >> "CfgWeapons" >> "BSKULLS_law_01" >> "Single"); // bin\config.bin/CfgWeapons/launch_Titan_base/Single
        // class Single : Single
        // {
        //     aiDispersionCoefX = 1.4;
        //     aiDispersionCoefY = 1.7;
        //     maxRange = 2000;
        //     maxRangeProbab = 0.8;
        //     midRange = 300;
        //     midRangeProbab = 0.8;
        //     minRange = 70;
        //     minRangeProbab = 0.9;
            
        // };
        // class TopDown : TopDown
        // {
        //     aiDispersionCoefX = 1.4;
        //     aiDispersionCoefY = 1.7;
        //     maxRange = 2000;
        //     maxRangeProbab = 0.95;
        //     midRange = 500;
        //     midRangeProbab = 0.95;
        //     minRange = 150;
        //     minRangeProbab = 0.9;
            
        // };

    };

    // LAW #2: M72A3 - no therm sig - AI can't use it: probably due to the initial 'reload' (activate scope) requirement; let's overcome this via a custom event
    class rhs_weap_m72a7;
    class BSKULLS_law_02: rhs_weap_m72a7 {
        displayName="M72A3 LAW (66mm)";
        scope=1;
    };

    // LAW #3: M72A3
    // Ammo: gm_1Rnd_66mm_heat_m72a3
    class gm_m72a3_oli;
    class BSKULLS_law_03: gm_m72a3_oli {
        displayName="M72A3 LAW (66mm)";
        scope=1;
    };

    // LAW #4: Titan AA
    // Ammo: Titan_AA
    class launch_B_Titan_olive_F;
    class BSKULLS_law_04: launch_B_Titan_olive_F {
        displayName="Titan MPRL (127mm)";
        scope=1;
    };

    // LAW #5: FIM-92 Stinger
    // Ammo: rhs_fim92_mag
    class rhs_weap_fim92;
    class BSKULLS_law_05: rhs_weap_fim92 {
        displayName="FIM-92 Stinger (70mm)";
        scope=1;
    };

    // Artillery #1: M4 (Howitzer 155mm)
    class CannonCore;
    class mortar_155mm_AMOS : CannonCore 
    { 
        class Single1 : Mode_SemiAuto { artilleryDispersion=0.1; }; 
        class Burst1 : Mode_Burst { artilleryDispersion=0.1; }; 
    };
    class BSKULLS_art_gun_01: mortar_155mm_AMOS
    {
        // magazines[] = {"32Rnd_155mm_Mo_shells","32Rnd_155mm_Mo_shells_O","6Rnd_155mm_Mo_smoke","6Rnd_155mm_Mo_smoke_O","2Rnd_155mm_Mo_guided","4Rnd_155mm_Mo_guided","4Rnd_155mm_Mo_guided_O","2Rnd_155mm_Mo_LG","4Rnd_155mm_Mo_LG","4Rnd_155mm_Mo_LG_O","6Rnd_155mm_Mo_mine","6Rnd_155mm_Mo_mine_O","2Rnd_155mm_Mo_Cluster","2Rnd_155mm_Mo_Cluster_O","6Rnd_155mm_Mo_AT_mine","6Rnd_155mm_Mo_AT_mine_O"};
        magazines[] = {"64Rnd_155mm_Plus_Mo_shells","8Rnd_155mm_Plus_Mo_guided","12Rnd_155mm_Plus_Mo_mine","4Rnd_155mm_Plus_Mo_Cluster","8Rnd_155mm_Plus_Mo_LG","12Rnd_155mm_Plus_Mo_AT_mine"};
    };

    // // GAU-8 - this experiment did not go well - recoil drops the plane
    // class Gatling_30mm_Plane_CAS_01_F;
    // class BSKULLS_cas_gun_01: Gatling_30mm_Plane_CAS_01_F
    // {
    //     magazines[] = {"MG8_1174Rnd_Gau8_30mm_PLUS"};
    // };

    class Default;
    class mortar_82mm : Default {
        magazines[] += {"80Rnd_82mm_Mo_shells_PLUS"};
        class Single1 : Mode_SemiAuto { artilleryDispersion=0.9; }; 
        class Burst1 : Mode_Burst { artilleryDispersion=1.2; };
    };

};