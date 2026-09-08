    class B_supplyCrate_F;
    class B_PTbskull_Veh_SupplyCrate_blackops_01 : B_supplyCrate_F
    {
        author = "RoFz";
        scope = 1;
        scopeCurator = 1;
        displayName = "Black Skulls Emergency Supply Crate";
        side = 1;
        faction = "bskull_fc_mo";

        // The fixed manifest contains 166 top-level cargo objects: 15 backpacks,
        // 12 weapons, 89 magazines/explosives, and 50 equipment items.
        // Bootstrap capacity prevents that config cargo from being truncated.
        // DRO replaces it at runtime with the exact loadAbs result plus a 10%
        // handling reserve after adding ammunition for the active squad.
        maximumLoad = 50000;
        DRO_supplyDropActiveSquadAmmo = 1;
        // DRO converts this round budget to magazines and caps the result at
        // the unit class's normal issued primary-magazine count.
        DRO_supplyDropPrimaryAmmoRounds = 150;
        DRO_supplyDropMachineGunAmmoCount = 2;
        DRO_supplyDropLoadReservePercent = 10;
        DRO_supplyDropMachineGuns[] = {
            "B_PTbskull_Wea_mg_01_smpg",
            "B_PTbskull_Wea_mg_02_navid",
            "B_PTbskull_Wea_mg_03_rpk",
            "B_PTbskull_Wea_mg_04_xm250"
        };
        // heliDrop.sqf checks this opt-in contract after creation and again
        // after landing, restoring only a missing shortfall in each category.
        class DRO_supplyDropMinimumCargo
        {
            class backpacks
            {
                // Both static Titan and standard HMG weapon bags assemble on
                // this tripod, so four tripods support the four weapon bags.
                class staticWeaponTripod
                {
                    className = "B_HMG_01_support_F";
                    count = 4;
                };
                class staticTitanLauncher
                {
                    className = "B_AT_01_weapon_F";
                    count = 2;
                };
                class staticMachineGun
                {
                    className = "B_HMG_01_weapon_F";
                    count = 2;
                };
            };
            class weapons
            {
                class titanAtPlusLauncher
                {
                    className = "B_PTbskull_Wea_law_01_titanat";
                    count = 3;
                };
            };
            class magazines
            {
                class titanAtPlusMissile
                {
                    className = "Titan_AT_PLUS";
                    count = 10;
                };
                class antiTankMine
                {
                    className = "ATMine_Range_Mag";
                    count = 5;
                };
            };
            class items
            {
                class switchblade600
                {
                    className = "SwitchBlade_600_Tube_Woodland";
                    count = 10;
                };
            };
        };

        class TransportBackpacks
        {
            class _xx_B_PTbskull_Veh_Back_UAV_blackops_01
            {
                backpack = "B_PTbskull_Veh_Back_UAV_blackops_01";
                count = 1;
            };
            class _xx_C_IDAP_UAV_06_antimine_backpack_F
            {
                backpack = "C_IDAP_UAV_06_antimine_backpack_F";
                count = 1;
            };
            class _xx_B_KA_Metal_Storm_AI_NATO
            {
                backpack = "B_KA_Metal_Storm_AI_NATO";
                count = 1;
            };
            class _xx_B_PTbskull_Veh_Back_Fuel_blackops_01
            {
                backpack = "B_PTbskull_Veh_Back_Fuel_blackops_01";
                count = 1;
            };
            class _xx_B_AssaultPack_blk
            {
                backpack = "B_AssaultPack_blk";
                count = 3;
            };
            class _xx_B_HMG_01_support_F
            {
                backpack = "B_HMG_01_support_F";
                count = 4;
            };
            class _xx_B_AT_01_weapon_F
            {
                backpack = "B_AT_01_weapon_F";
                count = 2;
            };
            class _xx_B_HMG_01_weapon_F
            {
                backpack = "B_HMG_01_weapon_F";
                count = 2;
            };
        };

        class TransportWeapons
        {
            class _xx_B_PTbskull_Wea_law_03_titanaa
            {
                weapon = "B_PTbskull_Wea_law_03_titanaa";
                count = 1;
            };
            class _xx_B_PTbskull_Wea_law_01_titanat
            {
                weapon = "B_PTbskull_Wea_law_01_titanat";
                count = 3;
            };
            class _xx_B_PTbskull_Wea_ar_03_honey
            {
                weapon = "B_PTbskull_Wea_ar_03_honey";
                count = 3;
            };
            class _xx_B_PTbskull_Wea_ar_04_scarh
            {
                weapon = "B_PTbskull_Wea_ar_04_scarh";
                count = 3;
            };
            class _xx_B_PTbskull_Wea_sniper_13_alligator
            {
                weapon = "B_PTbskull_Wea_sniper_13_alligator";
                count = 1;
            };
            class _xx_Laserdesignator_03
            {
                weapon = "Laserdesignator_03";
                count = 1;
            };
        };

        class TransportMagazines
        {
            class _xx_Titan_AA
            {
                magazine = "Titan_AA";
                count = 5;
            };
            class _xx_Titan_AT_PLUS
            {
                magazine = "Titan_AT_PLUS";
                count = 10;
            };
            class _xx_hlc_50rnd_300BLK_STANAG_EPR
            {
                magazine = "hlc_50rnd_300BLK_STANAG_EPR";
                count = 15;
            };
            class _xx_KA_SCAR_H_20rnd_M993_AP_mag
            {
                magazine = "KA_SCAR_H_20rnd_M993_AP_mag";
                count = 15;
            };
            class _xx_5Rnd_145_mag_B
            {
                magazine = "5Rnd_145_mag_B";
                count = 5;
            };
            class _xx_5Rnd_145_mag_BZT
            {
                magazine = "5Rnd_145_mag_BZT";
                count = 5;
            };
            class _xx_1Rnd_HE_Grenade_shell
            {
                magazine = "1Rnd_HE_Grenade_shell";
                count = 6;
            };
            class _xx_UGL_FlareWhite_Illumination_F
            {
                magazine = "UGL_FlareWhite_Illumination_F";
                count = 2;
            };
            class _xx_Laserbatteries
            {
                magazine = "Laserbatteries";
                count = 1;
            };
            class _xx_DemoCharge_Remote_Mag
            {
                magazine = "DemoCharge_Remote_Mag";
                count = 4;
            };
            class _xx_SatchelCharge_Remote_Mag
            {
                magazine = "SatchelCharge_Remote_Mag";
                count = 2;
            };
            class _xx_ATMine_Range_Mag
            {
                magazine = "ATMine_Range_Mag";
                count = 5;
            };
            class _xx_HandGrenade
            {
                magazine = "HandGrenade";
                count = 2;
            };
            class _xx_MiniGrenade
            {
                magazine = "MiniGrenade";
                count = 2;
            };
            class _xx_SmokeShell
            {
                magazine = "SmokeShell";
                count = 4;
            };
            class _xx_B_IR_Grenade
            {
                magazine = "B_IR_Grenade";
                count = 2;
            };
            class _xx_Chemlight_green
            {
                magazine = "Chemlight_green";
                count = 2;
            };
            class _xx_Chemlight_yellow
            {
                magazine = "Chemlight_yellow";
                count = 2;
            };
        };

        class TransportItems
        {
            class _xx_MineDetector
            {
                name = "MineDetector";
                count = 1;
            };
            class _xx_ToolKit
            {
                name = "ToolKit";
                count = 1;
            };
            class _xx_Medikit
            {
                name = "Medikit";
                count = 1;
            };
            class _xx_FirstAidKit
            {
                name = "FirstAidKit";
                count = 10;
            };
            class _xx_SwitchBlade_600_Tube_Woodland
            {
                name = "SwitchBlade_600_Tube_Woodland";
                count = 10;
            };
            class _xx_DEFAULT_HELMET
            {
                name = DEFAULT_HELMET;
                count = 3;
            };
            class _xx_DEFAULT_UNIFORM
            {
                name = DEFAULT_UNIFORM;
                count = 2;
            };
            class _xx_DEFAULT_UNIFORM_GIRLS
            {
                name = DEFAULT_UNIFORM_GIRLS;
                count = 1;
            };
            class _xx_DEFAULT_NVG
            {
                name = DEFAULT_NVG;
                count = 3;
            };
            class _xx_DEFAULT_VEST
            {
                name = DEFAULT_VEST;
                count = 3;
            };
            class _xx_ItemMap
            {
                name = "ItemMap";
                count = 3;
            };
            class _xx_ItemGPS
            {
                name = "ItemGPS";
                count = 2;
            };
            class _xx_B_UavTerminal
            {
                name = "B_UavTerminal";
                count = 1;
            };
            class _xx_ItemCompass
            {
                name = "ItemCompass";
                count = 3;
            };
            class _xx_ItemRadio
            {
                name = "ItemRadio";
                count = 3;
            };
            class _xx_ItemWatch
            {
                name = "ItemWatch";
                count = 3;
            };
        };
    };
