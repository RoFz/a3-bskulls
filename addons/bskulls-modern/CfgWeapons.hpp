class Mode_SemiAuto;
class Mode_Burst;
class CfgWeapons {

    // Handguns
    #include "CfgWeaponsHandgun.hpp"
    // Primary Weapons
    #include "CfgWeaponsPrimary.hpp"
    // Secondary Weapons
    #include "CfgWeaponsSecondary.hpp"

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
