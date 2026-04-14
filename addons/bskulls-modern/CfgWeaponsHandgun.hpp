    // Handgun: 4-five .45 ACP
    // Ammo: 11Rnd_45ACP_Mag
    #define B_PTbskull_Wea_pistol_01_4five_AMMO 11Rnd_45ACP_Mag
    class hgun_Pistol_heavy_01_F;
    class hgun_Pistol_heavy_01_F_OCimport_01 : hgun_Pistol_heavy_01_F { scope = 0; scopeArsenal = 0; class Single; };
    class B_PTbskull_Wea_pistol_01_4five : hgun_Pistol_heavy_01_F_OCimport_01 {
        displayName = "4-Five SD (.45 ACP)";
        author = "RoFz";
        scope = 2;
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
                item = "muzzle_snds_acp";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_flashlight_pistol";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_MRD";
            };
        };
    };

    // Handgun: PiMB 9x18mm
    // Ammo: gm_8Rnd_9x18mm_B_pst_pm_blk
    #define B_PTbskull_Wea_pistol_02_pimb_AMMO gm_8Rnd_9x18mm_B_pst_pm_blk
    class gm_pimb_blk;
    class gm_pimb_blk_OCimport_01 : gm_pimb_blk { scope = 0; scopeArsenal = 0; class Single; };
    class B_PTbskull_Wea_pistol_02_pimb : gm_pimb_blk_OCimport_01 {
        displayName = "PiMB SD (9x18mm Makarov)";
        author = "RoFz";
        scope = 2;
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
