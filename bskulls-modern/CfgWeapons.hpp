class Mode_SemiAuto;
class Mode_Burst;
class CfgWeapons {

    // // Handgun: R1 Enhanced .45ACP (Engraved)
    // class bnae_r1_e_virtual;
    // class B_PTbskull_Wea_pistol_1_r1 : bnae_r1_e_virtual {
    //     displayName = "R1 Enhanced Engraved SD (.45 ACP)";
    //     author = "RoFz";
    //     scope = 2;
    //     scopeArsenal = 2;
    //     scopeCurator = 2;
    //     access = 1;
    //     class LinkedItems {
    //         class LinkedItemsMuzzle {
    //             slot = "MuzzleSlot";
    //             item = "bnae_suppressor_v4_virtual";
    //         };
    //         class LinkedItemsOptic {
    //             slot = "CowsSlot";
    //             item = "bnae_reddot_virtual";
    //         };
    //         class LinkedItemsAcc { };
    //         class LinkedItemsUnder { };
    //     };
    // };

    // // Handgun: SIG Sauer P226R Combat
    // // Ammo: hlc_12Rnd_357SIG_B_P226
    // #define B_PTbskull_Wea_pistol_2_AMMO "hlc_12Rnd_357SIG_B_P226"
    // class hlc_pistol_P226R_357Combat;
    // class hlc_pistol_P226R_357Combat_OCimport_01 : hlc_pistol_P226R_357Combat { scope = 0; class Single; };
    // class B_PTbskull_Wea_pistol_2_sig : hlc_pistol_P226R_357Combat_OCimport_01 {
    //     displayName = "SIG Sauer P226R SD (.357 SIG)";
    //     author = "RoFz";
    //     scope = 2;
    //     scopeArsenal = 2;
    //     scopeCurator = 2;
    //     access = 1;
    //     // magazines[] = {"hlc_12Rnd_357SIG_B_P226","hlc_12Rnd_357SIG_JHP_P226"};
    //     class Single : Single {
    //         aiRateOfFire = 0.5;
    //     };
    //     class LinkedItems {
    //         class LinkedItemsMuzzle {
    //             slot = "MuzzleSlot";
    //             item = "hlc_muzzle_TiRant9S";
    //         };
    //         class LinkedItemsOptic {
    //             slot = "CowsSlot";
    //             item = "HLC_Optic_Docter_CADEX";
    //         };
    //         class LinkedItemsAcc {
    //             slot = "PointerSlot";
    //             item = "hlc_acc_DBALPL_FL";
    //         };
    //         class LinkedItemsUnder { };
    //     };
    // };

    // // Handgun: FN Five-seven FN 5.7x28mm
    // // Ammo: 20Rnd_57x28_SS198
    // #define B_PTbskull_Wea_pistol_3_AMMO "20Rnd_57x28_SS198"
    // class kt_FN57_tan;
    // class kt_FN57_tan_OCimport_01 : kt_FN57_tan { scope = 0; scopeArsenal = 0; class Single; };
    // class B_PTbskull_Wea_pistol_3_fn57 : kt_FN57_tan_OCimport_01 {
    //     displayName = "FN Five-seven SD (FN 5.7x28mm)";
    //     author = "RoFz";
    //     scope = 2;
    //     scopeArsenal = 2;
    //     scopeCurator = 2;
    //     access = 1;
    //     class Single : Single {
    //         aiDispersionCoefX = 0.1; // 1.4
    //         aiDispersionCoefY = 0.1; // 1.7
    //         aiRateOfFire = 0.3; // 2
    //         aiRateOfFireDispersion = 0; // 1
    //         maxRange = 50; // 100
    //         maxRangeProbab = 0.1; // 0.1
    //         midRange = 30; // 50
    //         midRangeProbab = 0.3; // 0.6
    //         minRange = 1; // 10
    //         minRangeProbab = 0.6; // 0.3
    //     };
    //     class LinkedItems {
    //         class LinkedItemsMuzzle {
    //             slot = "MuzzleSlot";
    //             item = "kt_FN57_Silencer";
    //         };
    //         class LinkedItemsAcc {
    //             slot = "PointerSlot";
    //             item = "kt_FN57_Laser_IR";
    //         };
    //     };
    // };

    // Handgun: PiMB 9x18mm
    // Ammo: gm_8Rnd_9x18mm_B_pst_pm_blk
    #define B_PTbskull_Wea_pistol_4_AMMO "gm_8Rnd_9x18mm_B_pst_pm_blk"
    class gm_pimb_blk;
    class gm_pimb_blk_OCimport_01 : gm_pimb_blk { scope = 0; scopeArsenal = 0; class Single; };
    class B_PTbskull_Wea_pistol_4_pimb : gm_pimb_blk_OCimport_01 {
        displayName = "PiMB SD (9x18mm Makarov)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
                item = "gm_suppressor_kacnavysd_9mm_blk";
            };
        };
    };

    // Sniper #1: M110A1
    // Ammo: kt_20Rnd_762x51_Ball_XM1158_AP_Mag // leads to CfgMagazines.ACE_20Rnd_762x51_Mag_Tracer bug?
    #define B_PTbskull_Wea_sniper_01_m110_AMMO "kt_20Rnd_762x51_Ball_XM1158_AP_Mag"
    class kt_M110A1_blk02;
    class B_PTbskull_Wea_sniper_01_m110 : kt_M110A1_blk02 {
        displayName = "H&K M110A1 SDMR (7.62x51mm NATO)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
        magazines[] = {"20Rnd_762x51_Mag","kt_20Rnd_762x51_Ball_XM1158_AP_Mag","kt_20Rnd_762x51_178gr_ELD_X_Mag","kt_20Rnd_762x51_Mk316_Mod_0_Mag"};
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
    #define B_PTbskull_Wea_sniper_02_trg42_AMMO "5Rnd_APDS_338LM_Magazine_PLUS"
    class bnae_trg42_virtual;
    class bnae_trg42_virtual_OCimport_01 : bnae_trg42_virtual { scope = 0; class EventHandlers; class Single; class WeaponSlotsInfo; };
    class bnae_trg42_virtual_OCimport_02 : bnae_trg42_virtual_OCimport_01 {
        class EventHandlers;
        class Single;
        class WeaponSlotsInfo : WeaponSlotsInfo {
            class CowsSlot;
        };
    };
    class B_PTbskull_Wea_sniper_02_trg42 : bnae_trg42_virtual_OCimport_02 {
        displayName = "Sako TRG-42 (.338 LM)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
        class Single : Single {
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
        };
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
    };

    // Sniper #3: Falkor Petra
    // Ammo: 10Rnd_300WM_Magazine
    #define B_PTbskull_Wea_sniper_03_falkor_AMMO "10Rnd_300WM_Magazine"
    class bnae_falkor_snd_virtual;
    class bnae_falkor_snd_virtual_OCimport_01 : bnae_falkor_snd_virtual { scope = 0; class EventHandlers; class WeaponSlotsInfo; };
    class bnae_falkor_snd_virtual_OCimport_02 : bnae_falkor_snd_virtual_OCimport_01 {
        class EventHandlers;
        class WeaponSlotsInfo : WeaponSlotsInfo {
            class CowsSlot;
        };
    };
    class B_PTbskull_Wea_sniper_03_falkor : bnae_falkor_snd_virtual_OCimport_02 {
        displayName = "Falkor Petra (.300 WM)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
        class WeaponSlotsInfo : WeaponSlotsInfo {
            allowedslots[] = {901};
            class CowsSlot : CowsSlot {
                compatibleitems[] += {"kt_atacr06_tremoe3ti_raptar", "optic_Nightstalker"};
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

    // Sniper #5: AX50SD
    // Ammo: 5Rnd_127x99_Ball_TAC50 (soft targets)
    class ax50_bolt2;
    class B_PTbskull_Wea_sniper_05_ax50 : ax50_bolt2 {
        displayName = "AX-50 (12.7x99mm)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
        // maxRange = 500;
        // maxRangeProbab = 0.04;
        // midRange = 150;
        // midRangeProbab = 0.58;
        // minRange = 1;
        // minRangeProbab = 0.3;
        magazines[] = {"5Rnd_127x108_Mag","5Rnd_127x108_APDS_Mag","5Rnd_127x99_AXMX_TAC50","5Rnd_127x99_API_TAC50","5Rnd_127x99_Ball_TAC50","5Rnd_127x108_APDS_TAC50","5Rnd_127x108_Ball_TAC50"};
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

    // Sniper #7: KA_CS5 (#1 Imp)
    // Ammo: KA_CS5_10rnd_M993_AP_mag
    class KA_CS5;
    class B_PTbskull_Wea_sniper_07_mcmillan : KA_CS5 {
        displayName = "McMillan CS5 (7.62x51mm NATO)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
    class B_PTbskull_Wea_sniper_08_wa2000 : KA_WA2000 {
        displayName = "Walther WA 2000 (.300 WM)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
    class B_PTbskull_Wea_sniper_09_dsr50 : KA_DSR50 {
        displayName = "DSR-50 (.50 BMG)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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

    // Sniper #11: McMillan TAC-50
    // Ammo: 10Rnd_127x99_API_TAC50 or 10Rnd_127x99_AXMX_TAC50
    class kt_tac50_04;
    class B_PTbskull_Wea_sniper_11_tac50 : kt_tac50_04 {
        displayName = "McMillan TAC-50 (.50 BMG)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
        magazines[] = {"5Rnd_127x108_Mag","5Rnd_127x108_APDS_Mag","5Rnd_127x99_AXMX_TAC50","5Rnd_127x99_API_TAC50","5Rnd_127x99_Ball_TAC50","5Rnd_127x108_APDS_TAC50","5Rnd_127x108_Ball_TAC50"};
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

    // Sniper #12: MAR-10 .338
    // Ammo: 10Rnd_338_Mag
    class srifle_DMR_02_F;
    class srifle_DMR_02_F_OCimport_01 : srifle_DMR_02_F { scope = 0; class EventHandlers; class WeaponSlotsInfo; };
    class B_PTbskull_Wea_sniper_12_mar10 : srifle_DMR_02_F_OCimport_01 {
        displayName = "MAR-10 (.338 LM)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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

    // Shotgun: Model 97
    class bnae_m97_s_virtual;
    class B_PTbskull_Wea_shotgun_1_winch : bnae_m97_s_virtual {
        displayName = "Winchester Model 1897 Carbine (12-gauge)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
    class KA_SPAS12;
    class B_PTbskull_Wea_shotgun_2_spas : KA_SPAS12 {
        displayName = "SPAS (12-gauge)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
    };

    // AR #1: SCAR-H (#1 Imp)
    // Ammo: KA_SCAR_H_20rnd_M993_AP_mag
    class KA_SCAR_H_Black_Grip;
    class B_PTbskull_Wea_ar_01_scarh : KA_SCAR_H_Black_Grip {
        displayName = "FN SCAR-H (7.62x51mm NATO)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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

    // AR #4: (#1 Imp)
    // Ammo: KA_SCAR_H_20rnd_M993_AP_mag + 1Rnd_HE_Grenade_shell
    class KA_SCAR_H_Black_EGLM;
    class B_PTbskull_Wea_ar_04_scarh : KA_SCAR_H_Black_EGLM {
        displayName = "SCAR-H 13in. SD (7.62x51mm NATO)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
    // Ammo: kt_20Rnd_762x51_Ball_XM1158_AP_Mag
    class arifle_SPAR_03_blk_F;
    class B_PTbskull_Wea_ar_06_spar17 : arifle_SPAR_03_blk_F {
        displayName = "SPAR-17 (7.62x51mm)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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

    // BR #1:
    // Ammo: kt_20Rnd_65_Creedmoor_108gr_AP_mag (AP) or 20Rnd_57x28_Sb193 (subsonic)
    class sig716_02_65;
    class B_PTbskull_Wea_br_01_sig716 : sig716_02_65 {
        displayName = "SIG716 (6.5x48mm CM)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
        magazines[] = {"kt_20Rnd_65_Creedmoor_147gr_ELD_Match_mag","kt_20Rnd_65_Creedmoor_108gr_AP_mag"};
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
                item = "acc_pointer_IR";
            };
            // class LinkedItemsUnder { };
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
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
    #define B_PTbskull_Wea_mg_3_AMMO "75rnd_762x39_AK12_Mag_Tracer_F"
    class arifle_RPK12_F;
    class arifle_RPK12_F_OCimport_01 : arifle_RPK12_F { scope = 0; };
    class B_PTbskull_Wea_mg_03_rpk : arifle_RPK12_F_OCimport_01 {
        displayName = "RPK-12 (7.62x39mm)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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

    // SMG #1: Vermin SMG .45 *
    class SMG_01_F;
    class SMG_01_F_OCimport_01 : SMG_01_F { scope = 0; class EventHandlers; };
    class SMG_01_F_OCimport_02 : SMG_01_F_OCimport_01 { class EventHandlers; };
    class B_PTbskull_Wea_SMG_01_vermin: SMG_01_F_OCimport_02 {
        displayName="Vermin SMG (.45 ACP)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
    #define B_PTbskull_Wea_SMG_02_sting_AMMO "30Rnd_9x21_Mag_SMG_02_Tracer_Green"
    class SMG_02_F;
    class B_PTbskull_Wea_SMG_02_sting: SMG_02_F {
        displayName="Sting SMG (9mm)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
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
    class B_PTbskull_Wea_law_01_titanat: launch_I_Titan_short_F {
        displayName="Titan+ MPRL Compact (127mm)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;



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

        // inheritsFrom (configfile >> "CfgWeapons" >> "B_PTbskull_Wea_law_01_titanat" >> "Single"); // bin\config.bin/CfgWeapons/launch_Titan_base/Single
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

    // LAW #2: M72A3
    // Ammo: gm_1Rnd_66mm_heat_m72a3
    class gm_m72a3_oli;
    class B_PTbskull_Wea_law_02_m72: gm_m72a3_oli {
        displayName="M72A3 LAW (66mm)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
    };

    // LAW #3: Titan AA
    // Ammo: Titan_AA
    class launch_B_Titan_olive_F;
    class B_PTbskull_Wea_law_03_titanaa: launch_B_Titan_olive_F {
        displayName="Titan MPRL (127mm)";
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        access = 1;
    };

    // // LAW #5: FIM-92 Stinger
    // // Ammo: rhs_fim92_mag
    // class rhs_weap_fim92;
    // class B_PTbskull_Wea_law_05: rhs_weap_fim92 {
    //     displayName="FIM-92 Stinger (70mm)";
    //     scope=1;
    // };

    // Artillery #1: M4 (Howitzer 155mm)
    class CannonCore;
    class mortar_155mm_AMOS : CannonCore
    {
        class Single1 : Mode_SemiAuto { artilleryDispersion=0.1; };
        class Burst1 : Mode_Burst { artilleryDispersion=0.1; };
    };
    class B_PTbskull_Wea_art_gun_01: mortar_155mm_AMOS
    {
        // magazines[] = {"32Rnd_155mm_Mo_shells","32Rnd_155mm_Mo_shells_O","6Rnd_155mm_Mo_smoke","6Rnd_155mm_Mo_smoke_O","2Rnd_155mm_Mo_guided","4Rnd_155mm_Mo_guided","4Rnd_155mm_Mo_guided_O","2Rnd_155mm_Mo_LG","4Rnd_155mm_Mo_LG","4Rnd_155mm_Mo_LG_O","6Rnd_155mm_Mo_mine","6Rnd_155mm_Mo_mine_O","2Rnd_155mm_Mo_Cluster","2Rnd_155mm_Mo_Cluster_O","6Rnd_155mm_Mo_AT_mine","6Rnd_155mm_Mo_AT_mine_O"};
        magazines[] = {"64Rnd_155mm_Plus_Mo_shells","8Rnd_155mm_Plus_Mo_guided","12Rnd_155mm_Plus_Mo_mine","4Rnd_155mm_Plus_Mo_Cluster","8Rnd_155mm_Plus_Mo_LG","12Rnd_155mm_Plus_Mo_AT_mine"};
    };

    // // GAU-8 - this experiment did not go well - recoil drops the plane
    // class Gatling_30mm_Plane_CAS_01_F;
    // class B_PTbskull_Wea_cas_gun_01: Gatling_30mm_Plane_CAS_01_F
    // {
    //     magazines[] = {"MG8_1174Rnd_Gau8_30mm_PLUS"};
    // };

    class Default;
    class mortar_82mm : Default {
        magazines[] += {"80Rnd_82mm_Mo_shells_PLUS"};
        class Single1 : Mode_SemiAuto { artilleryDispersion=0.9; };
        class Burst1 : Mode_Burst { artilleryDispersion=1.2; };
    };

    class V_PlateCarrier2_blk;
    class V_PlateCarrier2_blk_OCimport_01 : V_PlateCarrier2_blk { class ItemInfo; };
    class B_PTbskull_Vest_blackops_01 : V_PlateCarrier2_blk_OCimport_01 {
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        displayName = "Carrier Lite+ (Black)";
        mass = 1;
        class ItemInfo : ItemInfo {
            containerClass = "Supply500";
            // hiddenSelections[] = {"camo"};
            mass = 5;
            showHolsteredPistol = 1;
        };
    };

    class V_PlateCarrier1_rgr_noflag_F;
    class V_PlateCarrier1_rgr_noflag_F_OCimport_01 : V_PlateCarrier1_rgr_noflag_F { class ItemInfo; };
    class B_PTbskull_Vest_blackops_02 : V_PlateCarrier1_rgr_noflag_F_OCimport_01 {
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        displayName = "Carrier Lite+ (Green)";
        mass = 1;
        class ItemInfo : ItemInfo {
            containerClass = "Supply500";
            // hiddenSelections[] = {"camo"};
            mass = 5;
            showHolsteredPistol = 1;
        };
    };

    class V_SSU_Carrier_Lite_Black;
    class V_SSU_Carrier_Lite_Black_OCimport_01 : V_SSU_Carrier_Lite_Black { class ItemInfo; };
    class B_PTbskull_Vest_blackops_03 : V_SSU_Carrier_Lite_Black_OCimport_01 {
        author = "RoFz";
        scope = 2;
        scopeArsenal = 2;
        displayName = "Carrier Lite+ (NO THERM SIG, Black)";
        mass = 1;
        class ItemInfo : ItemInfo {
            containerClass = "Supply500";
            // hiddenSelections[] = {"camo"};
            mass = 5;
            showHolsteredPistol = 1;
        };
    };

};
