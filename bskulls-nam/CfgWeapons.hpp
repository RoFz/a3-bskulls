class cfgWeapons {

    // Handgun: M1911 SD
    class vn_m1911;
    class vn_m1911_OCimport_01 : vn_m1911 { scope = 0; class Single; };
    class BSKULLS_pistol_1 : vn_m1911_OCimport_01 {
        displayName = "M1911 SD (.45 ACP)";
        scope = 1;
        class Single : Single {
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFire = 0.3; // 2
            aiRateOfFireDispersion = 0; // 1
            maxRange = 50; // 100
            maxRangeProbab = 0.1; // 0.1
            midRange = 30; // 50
            midRangeProbab = 0.6; // 0.6
            minRange = 1; // 10
            minRangeProbab = 0.8; // 0.3
        };
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "vn_s_m1911";
            };
            class LinkedItemsOptic { };
            class LinkedItemsAcc { };
            class LinkedItemsUnder { };
        };
    };

    // Handgun: M1911 SD + MX991 Flashlight
    class vn_mx991_m1911;
    class vn_mx991_m1911_OCimport_01 : vn_mx991_m1911 { scope = 0; class Single; };
    class BSKULLS_pistol_2 : vn_mx991_m1911_OCimport_01 {
        displayName = "M1911 SD (.45 ACP) + MX991 Fulton";
        scope = 1;
        class Single : Single {
            aiDispersionCoefX = 0.1; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFire = 0.3; // 2
            aiRateOfFireDispersion = 0; // 1
            maxRange = 50; // 100
            maxRangeProbab = 0.1; // 0.1
            midRange = 30; // 50
            midRangeProbab = 0.6; // 0.6
            minRange = 1; // 10
            minRangeProbab = 0.8; // 0.3
        };
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "vn_s_m1911";
            };
            class LinkedItemsOptic { };
            class LinkedItemsAcc { };
            class LinkedItemsUnder { };
        };
    };


    // Sniper #1: M40A1 SD
    // class vn_m40a1_camo;
    // class vn_m40a1_camo_OCimport_01 : vn_m40a1_camo { scope = 0; class Single; };
    // class BSKULLS_sniper_1 : vn_m40a1_camo_OCimport_01 {    class vn_m40a1_camo;
    class vn_m40a1_sniper_sd;
    class vn_m40a1_sniper_sd_OCimport_01 : vn_m40a1_sniper_sd { scope = 0; class Single; };
    class BSKULLS_sniper_1 : vn_m40a1_sniper_sd_OCimport_01 {
        displayName = "M40A1 SD (7.62x51mm NATO)";
        scope = 1;
        maxLeadSpeed = 80; // 23
        class Single : Single {
            aiDispersionCoefX = 0.05; // 1.4
            aiDispersionCoefY = 0.1; // 1.7
            aiRateOfFire = 1; // 2
            aiRateOfFireDispersion = 0; // 1
            aiRateOfFireDistance = 300; // 500
            maxRange = 800; // 600
            maxRangeProbab = 1; // 0.04
            midRange = 400; // 300
            midRangeProbab = 1; // 0.58
            minRange = 50; // 30
            minRangeProbab = 0.7; // 0.25
        };
        // class LinkedItems {
        //     class LinkedItemsMuzzle {
        //         slot = "MuzzleSlot";
        //         item = "vn_s_m14";
        //     };
        //     class LinkedItemsOptic {
        //         slot = "CowsSlot";
        //         item = "vn_o_9x_m40a1";
        //     };
        //     class LinkedItemsAcc { };
        //     class LinkedItemsUnder {
        //         slot = "UnderBarrelSlot";
        //         item = "vn_b_camo_m40a1";
        //     };
        // };
    };

    // Shotgun: M1897
    class vn_m1897;
    class BSKULLS_shotgun_1 : vn_m1897 {
        displayName = "Winchester Model 1897 Carbine (12-gauge)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsMuzzle { };
            class LinkedItemsOptic { };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "vn_b_m1897";                
            };
            class LinkedItemsUnder { };
        };
    };

    // AR #1: M16A1 SD
    class vn_m16_camo;
    class BSKULLS_ar_1 : vn_m16_camo {
        displayName = "M16A1 SD (5.56x45mm NATO)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "vn_s_m16";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "vn_o_4x_m16";
            };
            class LinkedItemsAcc { };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "vn_bipod_m16";
            };
        };
    };

    // AR #2: M14 SD
    class vn_m14_camo;
    class BSKULLS_ar_2 : vn_m14_camo {
        displayName = "M14 SD (7.62x51mm NATO)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "vn_s_m14";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "vn_o_9x_m14";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "vn_b_m14";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "vn_b_camo_m14";
            };
        };
    };

    // MG #1: 
    class vn_m60_shorty_camo;
    class vn_m60_shorty_camo_OCimport_01 : vn_m60_shorty_camo { scope = 0; class manual; };
    class BSKULLS_mg_1 : vn_m60_shorty_camo_OCimport_01 {
        displayName = "M60 (7.62x51mm NATO)";
        scope = 1;
        class close : manual
        {
            burst = 12;
            aiBurstTerminable = 1;
        };
        class LinkedItems {
            class LinkedItemsMuzzle { };
            class LinkedItemsOptic { };
            class LinkedItemsAcc { };
            class LinkedItemsUnder { };
        };
    };


    // SMG #1: MPU
    class vn_mpu;
    class BSKULLS_SMG_1: vn_mpu {
        displayName="MPU SD (9x19mm)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle {
                slot="MuzzleSlot";
                item="vn_s_mpu";
            };
            class LinkedItemsOptic { };
            class LinkedItemsAcc { };
        };
    };

    // SMG #2: Type 64
    class vn_m45_camo;
    class BSKULLS_SMG_2: vn_m45_camo {
        displayName="M/45 SD (9x19mm)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "vn_s_m45_camo";
            };
            class LinkedItemsOptic { };
            class LinkedItemsAcc { };
        };
    };

    // SMG #3: Type 64
    class vn_sten;
    class BSKULLS_SMG_3: vn_sten {
        displayName="Sten Mk. II SD (9x19mm)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "vn_s_sten";
            };
            class LinkedItemsOptic { };
            class LinkedItemsAcc { };
        };
    };

    // SMG #4: L34A1+GL
    class vn_l34a1_xm148;
    class BSKULLS_SMG_4: vn_l34a1_xm148 {
        displayName="Sterling SD/GL (9x19mm)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle { };
            class LinkedItemsOptic { };
            class LinkedItemsAcc { };
        };
    };

    class vn_m41_v_01;
    class BSKULLS_tank_turret_1 : vn_m41_v_01 {
        displayName = "M41 90mm (auto)";
        scope = 1;
        autoFire = 1;
    };




};