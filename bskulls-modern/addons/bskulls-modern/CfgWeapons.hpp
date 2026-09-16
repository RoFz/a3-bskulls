class CfgWeapons {

    class weapon_GBU12Launcher;
    class B_PTbskull_Wea_GBU12Launcher_x4 : weapon_GBU12Launcher {
        author = "RoFz";
        magazines[] += {"B_PTbskull_PylonRack_Bomb_GBU12_x4"};
    };

    // Handguns
    #include "CfgWeaponsHandgun.hpp"
    // Primary Weapons
    #include "CfgWeaponsPrimary.hpp"
    // Secondary Weapons
    #include "CfgWeaponsSecondary.hpp"
    // Artillery
    #include "CfgWeaponsArtillery.hpp"
    // Vests
    #include "CfgWeaponsVests.hpp"

};
