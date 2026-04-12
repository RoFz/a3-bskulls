#define STR(a) #a
#define QUOTE(a) STR(a)
#define MAG_2(a) QUOTE(a), QUOTE(a)
#define MAG_3(a) QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_4(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_5(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_6(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_7(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_8(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_9(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_10(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_11(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_12(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_20(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)
#define MAG_30(a) QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a), QUOTE(a)

#define MAG_XX(a,b) class _xx_##a {magazine = a; count = b;}
#define WEAP_XX(a,b) class _xx_##a {weapon = a; count = b;}
#define ITEM_XX(a,b) class _xx_##a {name = a; count = b;}

		// class TransportMagazines
		// {
		// 	MAG_XX(100Rnd_65x39_caseless_mag,4);
		// 	MAG_XX(100Rnd_65x39_caseless_mag_Tracer,2);
		// 	MAX_XX(130Rnd_338_Mag,2);
		// };
		// class TransportItems
		// {
		// 	ITEM_XX(optic_tws_mg,1);
		// 	ITEM_XX(bipod_01_F_snd,1);
		// 	ITEM_XX(muzzle_snds_338_sand,1);
		// 	ITEM_XX(muzzle_snds_H_SW,1);
		// };

#define TRANSPORTMAGAZINES\
    class _xx_gm_handgrenade_frag_dm51a1 {count=10;magazine="gm_handgrenade_frag_dm51a1";};\
    class _xx_gm_smokeshell_wht_dm25 {count=10;magazine="gm_smokeshell_wht_dm25";};\
    class _xx_gm_explosive_petn_charge {count=4;magazine="gm_explosive_petn_charge";};\
    class _xx_gm_mine_ap_dm31 {count=10;magazine="gm_mine_ap_dm31";};\
    class _xx_gm_mine_at_dm21 {count=3;magazine="gm_mine_at_dm21";};\
    class _xx_gm_100Rnd_762x51mm_B_T_DM21A2_mg8_oli {count=5;magazine="gm_100Rnd_762x51mm_B_T_DM21A2_mg8_oli";};\
    class _xx_gm_7rnd_12ga_hk512_pellet {count=5;magazine="gm_7rnd_12ga_hk512_pellet";};\
    class _xx_gm_40Rnd_762x51mm_AP_DM151_g3_blk {count=10;magazine="gm_40Rnd_762x51mm_AP_DM151_g3_blk";};\
    class _xx_gm_1Rnd_44x537mm_heat_dm32_pzf44_2 {count=5;magazine="gm_1Rnd_44x537mm_heat_dm32_pzf44_2";};\
    class _xx_gm_1Rnd_66mm_heat_m72a3 {count=5;magazine="gm_1Rnd_66mm_heat_m72a3";};\
    class _xx_gm_1Rnd_70mm_he_m585_fim43 {count=5;magazine="gm_1Rnd_70mm_he_m585_fim43";};\
    class _xx_gm_1Rnd_84x245mm_heat_t_DM32_carlgustaf {count=5;magazine="gm_1Rnd_84x245mm_heat_t_DM32_carlgustaf";};\
    class _xx_gm_1Rnd_84x245mm_ILLUM_DM16_carlgustaf {count=3;magazine="gm_1Rnd_84x245mm_ILLUM_DM16_carlgustaf";};

#define TRANSPORTITEMS\
    class _xx_gm_boltcutter {count=1;name="gm_boltcutter";};\
    class _xx_gm_repairkit_01 {count=1;name="gm_repairkit_01";};\
    class _xx_gm_ge_army_medkit_80 {count=1;name="gm_ge_army_medkit_80";};\
    class _xx_gm_ge_army_burnBandage {count=20;name="gm_ge_army_burnBandage";};\
    class _xx_gm_pzf84_oli {count=1;name="gm_pzf84_oli";};\
    class _xx_gm_feroz2x17_pzf84_blk {count=1;name="gm_feroz2x17_pzf84_blk";};\
    class _xx_gm_m72a3_oli {count=3;name="gm_m72a3_oli";};\
    class _xx_gm_fim43_oli {count=3;name="gm_fim43_oli";};

#define TRANSPORTITEMS_HELO\
    class _xx_gm_backpack_t10_parachute {count=12;name="gm_backpack_t10_parachute";};

class CBA_Extended_EventHandlers_base;

class cfgWeapons {
    class gm_pimb_blk;
    class BSKULLS_gm_pimb_blk : gm_pimb_blk {
        displayName="9mm SD";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle {
                slot="MuzzleSlot";
                item="gm_suppressor_kacnavysd_9mm_blk";
            };
        };
    };

    class gm_g3ka4a1_ris_blk;
    class BSKULLS_gm_g3ka4a1_ris_blk : gm_g3ka4a1_ris_blk {
        displayName="G3KA4A1 (Black)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle
            {
                slot="MuzzleSlot";
                item="gm_suppressor_atec150_762mm_blk";
            };
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="gm_rv_ris_blk";
            };
            class LinkedItemsAcc
            {
            };
            class LinkedItemsUnder {
            };
        };
    };

    class gm_g3a3a1_ris_oli;
    class BSKULLS_gm_g3a3a1_ris_oli : gm_g3a3a1_ris_oli {
        displayName="G3A3A1 (Olive)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle
            {
                slot="MuzzleSlot";
                item="gm_suppressor_atec150_762mm_long_blk";
            };
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="gm_rv_stanagClaw_oli";
            };
            class LinkedItemsAcc
            {
            };
            class LinkedItemsUnder {
            };
        };
    };

    class gm_msg90a1_blk;
    class BSKULLS_gm_msg90a1_blk : gm_msg90a1_blk {
        displayName="MSG90A1";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle
            {
                slot="MuzzleSlot";
                item="gm_suppressor_atec150_762mm_long_blk";
            };
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="gm_zf10x42_stanaghk_blk";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "gm_msg90_bipod_blk";
            };
        };        
    };

    class gm_mg8a2_blk;
    class BSKULLS_gm_mg8a2_blk : gm_mg8a2_blk {
        displayName="MG8A2";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsMuzzle
            {
                slot="MuzzleSlot";
                item="gm_suppressor_atec150_762mm_blk";
            };
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="gm_rv_stanagHK_blk";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "gm_g8_bipod_blk";
            };
        };
    };

    class gm_pzf84_oli;
    class BSKULLS_gm_pzf84_oli : gm_pzf84_oli {
        displayName="";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="gm_feroz2x17_pzf84_blk";
            };
        };
    };

    class BSKULLS_gm_hk512_ris_wud {
        displayName="12ga. RIS + Flashlight";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsAcc
            {
                slot="PointerSlot";
                item="gm_surefire_l60_wht_hoseclamp_blk";
            };
        };
    };

    // class ;
    // class BSKULLS_ {
    //     displayName="";
    //     scope=1;
    //     class LinkedItems
    //     {
    //         class LinkedItemsMuzzle
    //         {
    //             slot="MuzzleSlot";
    //             item="";
    //         };
    //         class LinkedItemsOptic
    //         {
    //             slot="CowsSlot";
    //             item="";
    //         };
    //         class LinkedItemsAcc
    //         {
    //             slot="PointerSlot";
    //             item="";
    //         };
    //         class LinkedItemsUnder {
    //             slot = "UnderBarrelSlot";
    //             item = "";
    //         };
    //     };
    // };
};

class CfgVehicles {

    // UNITS

    class B_recon_TL_F;
    class B_recon_TL_F_OCimport_01 : B_recon_TL_F {
        scope = 0;
        class EventHandlers {
            // init="_this = _this select 0;sleep 0.2;_this setVariable ['BIS_enableRandomization', false];"
        };
    };
    class B_recon_TL_F_OCimport_02 : B_recon_TL_F_OCimport_01 {
        armor=10;
        detectSkill=20;
        editorSubcategory="EdSubcat_Personnel_SpecialForces";
        nameSound="veh_infantry_officer_s";
        textPlural="officer";
        textSingular="officers";
        scope=2;
        scopeCurator=2;
        // scopeArsenal=2;
        // accuracy = 2.9; // accuracy needed to recognize type of this target. Usually varies from 0 to 2. The bigger value, the more time you need to recognize specific type. Value 1000 is used for object that should be never recognized, for example medic should be known as regular soldier.
        audible = 0.2; // similar camouflage but for sound. The bigger value, the better the unit is heard.
        camouflage = 0.2; //how difficult to spot. The bigger value, the better is vehicle spot-able over distance. Tanks use 8, men 1, aircraft up to 100.
        // canHideBodies = true;
        cost = 440000;
        formationX = 2;
        formationZ = 2;
        icon="iconManLeader";
        sensitivity = 2;
        sensitivityEar = 0.3;
        staminaDuration = 200;
        staminaRestoration = 5;
        threat[] = {1.2, 0.5, 0.1};
        rank = "COLONEL";
    };

    // class B_recon_medic_F;
    class TCGM_RollUp_B_WDL_Medic;
    class B_recon_medic_F_OCimport_01 : TCGM_RollUp_B_WDL_Medic {
        scope = 0;
        class EventHandlers {
            // init="_this = _this select 0;sleep 0.2;_this setVariable ['BIS_enableRandomization', false];"
        };
    };
    class B_recon_medic_F_OCimport_02 : B_recon_medic_F_OCimport_01 {
        armor=10;
        detectSkill=20;
        // editorSubcategory="EdSubcat_Personnel_SpecialForces";
        // nameSound="veh_infantry_medic_s";
        // textPlural="medics";
        // textSingular="medic";
        scope=2;
        scopeCurator=2;
        // scopeArsenal=2;
        // accuracy = 2.5; // accuracy needed to recognize type of this target. Usually varies from 0 to 2. The bigger value, the more time you need to recognize specific type. Value 1000 is used for object that should be never recognized, for example medic should be known as regular soldier.
        audible = 0.3; // similar camouflage but for sound. The bigger value, the better the unit is heard.
        camouflage = 0.5; //how difficult to spot. The bigger value, the better is vehicle spot-able over distance. Tanks use 8, men 1, aircraft up to 100.
        // canHideBodies = true;
        attendant = 1;
        cost = 290000;
        formationX = 2;
        formationZ = 2;
        // role = "CombatLifeSaver";
        role = "SpecialOperative";
        sensitivity = 2;
        sensitivityEar = 0.3;
        staminaDuration = 200;
        staminaRestoration = 5;
        threat[] = {0.7, 0.1, 0.1};
    };

    class B_Recon_Sharpshooter_F;
    class B_Recon_Sharpshooter_F_OCimport_01 : B_Recon_Sharpshooter_F {
        scope = 0;
        class EventHandlers {
            // init="_this = _this select 0;sleep 0.2;_this setVariable ['BIS_enableRandomization', false];"
        };
    };
    class B_Recon_Sharpshooter_F_OCimport_02 : B_Recon_Sharpshooter_F_OCimport_01 {
        armor=10;
        detectSkill=20;
        // editorSubcategory="EdSubcat_Personnel_SpecialForces";
        nameSound="veh_infantry_sniper_s";
        textPlural="snipers";
        textSingular="sniper";
        scope=2;
        scopeCurator=2;
        // scopeArsenal=2;
        // accuracy = 2.9; // accuracy needed to recognize type of this target. Usually varies from 0 to 2. The bigger value, the more time you need to recognize specific type. Value 1000 is used for object that should be never recognized, for example medic should be known as regular soldier.
        audible = 0.1; // similar camouflage but for sound. The bigger value, the better the unit is heard.
        camouflage = 0.1; //how difficult to spot. The bigger value, the better is vehicle spot-able over distance. Tanks use 8, men 1, aircraft up to 100.
        // canHideBodies = true;
        cost = 350000;
        formationX = 2;
        formationZ = 2;
        // role = "Marksman";
        sensitivity = 3;
        sensitivityEar = 0.3;
        staminaDuration = 200;
        staminaRestoration = 5;
        threat[] = {1.05,0.2,0.1};
    };

    class B_recon_exp_F;
    class B_recon_exp_F_OCimport_01 : B_recon_exp_F {
        scope = 0;
        class EventHandlers {
            // init="_this = _this select 0;sleep 0.2;_this setVariable ['BIS_enableRandomization', false];"
        };
    };
    class B_recon_exp_F_OCimport_02 : B_recon_exp_F_OCimport_01 {
        armor=10;
        detectSkill=50;
        // editorSubcategory="EdSubcat_Personnel_SpecialForces";
        nameSound="veh_infantry_SF_s";
        textPlural="specops";
        textSingular="specop";
        scope=2;
        scopeCurator=2;
        // scopeArsenal=2;
        // accuracy = 2.5; // accuracy needed to recognize type of this target. Usually varies from 0 to 2. The bigger value, the more time you need to recognize specific type. Value 1000 is used for object that should be never recognized, for example medic should be known as regular soldier.
        audible = 0.3; // similar camouflage but for sound. The bigger value, the better the unit is heard.
        camouflage = 0.5; //how difficult to spot. The bigger value, the better is vehicle spot-able over distance. Tanks use 8, men 1, aircraft up to 100.
        // canHideBodies = true;
        canDeactivateMines = 1;
        engineer = 1;
        cost = 115000;
        formationX = 2;
        formationZ = 2;
        icon="iconManExplosive";
        // role = "Sapper";
        sensitivity = 2;
        sensitivityEar = 0.3;
        staminaDuration = 200;
        staminaRestoration = 5;
        threat[] = {1.0, 0.3, 0.1};
    };

    class B_recon_M_F;
    class B_recon_M_F_OCimport_01 : B_recon_M_F {
        scope = 0;
        class EventHandlers {
            // init="_this = _this select 0;sleep 0.2;_this setVariable ['BIS_enableRandomization', false];"
        };
    };
    class B_recon_M_F_OCimport_02 : B_recon_M_F_OCimport_01 {
        armor=10;
        detectSkill=20;
        // editorSubcategory="EdSubcat_Personnel_SpecialForces";
        nameSound="veh_infantry_SF_s";
        textPlural="specops";
        textSingular="specop";
        scope=2;
        scopeCurator=2;
        // scopeArsenal=2;
        // accuracy = 2.9; // accuracy needed to recognize type of this target. Usually varies from 0 to 2. The bigger value, the more time you need to recognize specific type. Value 1000 is used for object that should be never recognized, for example medic should be known as regular soldier.
        audible = 0.3; // similar camouflage but for sound. The bigger value, the better the unit is heard.
        camouflage = 0.4; //how difficult to spot. The bigger value, the better is vehicle spot-able over distance. Tanks use 8, men 1, aircraft up to 100.
        // canHideBodies = true;
        cost = 150000;
        formationX = 2;
        formationZ = 2;
        // role = "Marksman";
        sensitivity = 2.2;
        sensitivityEar = 0.3;
        staminaDuration = 200;
        staminaRestoration = 5;
        threat[] = {1.06, 0.1, 0.1};
    };

    class B_recon_F;
    class B_recon_F_OCimport_01 : B_recon_F {
        scope = 0;
        class EventHandlers {
            // init="_this = _this select 0;sleep 0.2;_this setVariable ['BIS_enableRandomization', false];"
        };
    };
    class B_recon_F_OCimport_02 : B_recon_F_OCimport_01 {
        armor=10;
        detectSkill=25;
        // editorSubcategory="EdSubcat_Personnel_SpecialForces";
        nameSound="veh_infantry_MG_s";
        textPlural="machinegunners";
        textSingular="machinegunner";
        scope=2;
        scopeCurator=2;
        // scopeArsenal=2;
        // accuracy = 2.9; // accuracy needed to recognize type of this target. Usually varies from 0 to 2. The bigger value, the more time you need to recognize specific type. Value 1000 is used for object that should be never recognized, for example medic should be known as regular soldier.
        audible = 0.7; // similar camouflage but for sound. The bigger value, the better the unit is heard.
        camouflage = 0.8; //how difficult to spot. The bigger value, the better is vehicle spot-able over distance. Tanks use 8, men 1, aircraft up to 100.
        // canHideBodies = true;
        cost = 125000;
        formationX = 2;
        formationZ = 2;
        icon = "iconManMG";
        // role = "MachineGunner";
        sensitivity = 2;
        sensitivityEar = 0.3;
        staminaDuration = 200;
        staminaRestoration = 5;
        threat[] = {1.08,0.4,0.2};
    };

    class B_recon_LAT_F;
    class B_recon_LAT_F_OCimport_01 : B_recon_LAT_F {
        scope = 0;
        class EventHandlers {
            // init="_this = _this select 0;sleep 0.2;_this setVariable ['BIS_enableRandomization', false];"
        };
    };
    class B_recon_LAT_F_OCimport_02 : B_recon_LAT_F_OCimport_01 {
        armor=10;
        detectSkill=30;
        // editorSubcategory="EdSubcat_Personnel_SpecialForces";
        nameSound="veh_infantry_AT_s";
        textPlural="AT soldiers";
        textSingular="AT soldier";
        scope=2;
        scopeCurator=2;
        // scopeArsenal=2;
        // accuracy = 2.5; // accuracy needed to recognize type of this target. Usually varies from 0 to 2. The bigger value, the more time you need to recognize specific type. Value 1000 is used for object that should be never recognized, for example medic should be known as regular soldier.
        audible = 0.4; // similar camouflage but for sound. The bigger value, the better the unit is heard.
        camouflage = 0.7; //how difficult to spot. The bigger value, the better is vehicle spot-able over distance. Tanks use 8, men 1, aircraft up to 100.
        // canHideBodies = true;
        cost = 150000;
        formationX = 2;
        formationZ = 2;
        icon="iconManAT";
        // role = "MissileSpecialist";
        secondaryAmmoCoef=0.5;
        sensitivity = 2.1;
        sensitivityEar = 0.3;
        staminaDuration = 200;
        staminaRestoration = 5;
        threat[] = {1,0.6,0.3};
    };

    class B_helicrew_F;
    class B_helicrew_F_OCimport_01 : B_helicrew_F {
        scope = 0;
        class EventHandlers {
            // init="_this = _this select 0;sleep 0.2;_this setVariable ['BIS_enableRandomization', false];"
        };
    };
    class B_helicrew_F_OCimport_02 : B_helicrew_F_OCimport_01 { class EventHandlers; };

    class B_Helipilot_F;
    class B_Helipilot_F_OCimport_01 : B_Helipilot_F {
        scope = 0;
        class EventHandlers {
            // init="_this = _this select 0;sleep 0.2;_this setVariable ['BIS_enableRandomization', false];"
        };
    };
    class B_Helipilot_F_OCimport_02 : B_Helipilot_F_OCimport_01 { class EventHandlers; };

    class B_Fighter_Pilot_F;
    class B_Fighter_Pilot_F_OCimport_01 : B_Fighter_Pilot_F {
        scope = 0;
        class EventHandlers {
            // init="_this = _this select 0;sleep 0.2;_this setVariable ['BIS_enableRandomization', false];"
        };
    };
    class B_Fighter_Pilot_F_OCimport_02 : B_Fighter_Pilot_F_OCimport_01 { class EventHandlers; };

    // VEHICLES
    
    // Helos

    class gm_ge_army_bo105p1m_vbh_swooper;
    class BSKULLS_CW_helo_01 : gm_ge_army_bo105p1m_vbh_swooper {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        scopeArsenal = 2;
        displayName = "VBH 1A1 Swooper 9p+2c";
        side = 1;
        faction = "BSKULLS_CW"; 
        crew = "BSKULLS_CW_helo_pilot_01";
        transportSoldier = 9;
        class TransportBackpacks {
            class _xx_gm_backpack_t10_parachute {count=11;backpack="gm_backpack_t10_parachute";};
        };
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit,['gm_ge_n84',1],['swooperRopes_unhide',1,'door_2_1_unhide',1,'door_2_2_unhide',1,'door_1_1_unhide',1,'door_1_2_unhide',1]] call BIS_fnc_initVehicle;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };
    };
    class gm_ge_army_ch53gs;
    class BSKULLS_CW_helo_02 : gm_ge_army_ch53gs {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        displayName = "CH-53GS 2c+24p";
        side = 1;
        faction = "BSKULLS_CW";
        crew = "BSKULLS_CW_helo_pilot_01";
        class TransportBackpacks {
            class _xx_gm_backpack_t10_parachute {count=26;backpack="gm_backpack_t10_parachute";};
        };
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit,['gm_ge_n84',1],['cargoseat_source',0,'fueltank_1_1_unhide',1]] call BIS_fnc_initVehicle;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };
    };

    // Planes
    class RHS_A10;
    class BSKULLS_cas_01 : RHS_A10 {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        displayName = "A-10";
        side = 1;
        faction = "BSKULLS_CW";
        crew = "BSKULLS_CW_fighter_pilot_01";

        // class EventHandlers : EventHandlers {
        //     class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        //     init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        // };

    };

    // APCs
    class gm_ge_army_fuchsa0_reconnaissance;
    class BSKULLS_CW_apc_00 : gm_ge_army_fuchsa0_reconnaissance {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        displayName = "TPz 1A0 Recon 3c+7p";
        side = 1;
        faction = "BSKULLS_CW";
        crew = "BSKULLS_CW_tank_crew_01";
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['gm_ge_wdl',1], ['beacon_01_org_unhide',0,'beacon_01_blu_unhide',0,'CamoNet_01_unhide',1,'CamoNet_02_rack_unhide',1,'StowingBox_01_unhide',0,'SignsExtraWide_unhide',1,'camonet_hull_unhide',1,'camofoilage_hull_unhide',1]] call BIS_fnc_initVehicle;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };
    };
    class gm_ge_army_luchsa2;
    class BSKULLS_CW_apc_01 : gm_ge_army_luchsa2 {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        displayName = "SpPz 2A2 5c+4pO";
        side = 1;
        faction = "BSKULLS_CW";
        crew = "BSKULLS_CW_tank_crew_01";
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['gm_ge_wdl',1], ['radio_03_unhide',1,'SignsExtraWide_unhide',0,'TurretBox_01_unhide',1,'CamoNet_01_unhide',1,'CamoNet_02_unhide',1,'beacon_01_org_unhide',0,'beacon_01_blu_unhide',0,'camonet_hull_unhide',1,'camofoilage_hull_unhide',1,'camonet_MainTurret_trav_unhide',1,'camofoilage_MainTurret_trav_unhide',1]] call BIS_fnc_initVehicle;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };
    };
    class gm_ge_army_marder1a1plus;
    class BSKULLS_CW_apc_02 : gm_ge_army_marder1a1plus {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        displayName = "SPz 1A1+ 5c+5p";
        side = 1;
        faction = "BSKULLS_CW";
        crew = "BSKULLS_CW_tank_crew_01";
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['gm_ge_wdl',1], ['beacon_01_org_unhide',0,'sideskirt_unhide',1,'CamoNet_01_unhide',1,'supply_01_unhide',1,'supply_02_unhide',1,'camonet_hull_unhide',1,'camofoilage_hull_unhide',1,'camonet_MainTurret_trav_unhide',1,'camofoilage_MainTurret_trav_unhide',1]] call BIS_fnc_initVehicle;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };
    };

    // Tanks
    class gm_ge_army_Leopard1a5;
    class BSKULLS_CW_tank_00 : gm_ge_army_Leopard1a5 {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Leopard 1A5 5c";
        side = 1;
        faction = "BSKULLS_CW";
        crew = "BSKULLS_CW_tank_crew_01";
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['gm_ge_wdl',1], ['CamoNet_01_unhide',0,'CamoNet_04_unhide',1,'CamoNet_02_unhide',1,'CamoNet_05_unhide',0,'CamoNet_03_unhide',0,'SpareWheel_01_unhide',1,'SpareWheel_02_unhide',0,'SpareWheel_03_unhide',0,'SpareWheel_04_unhide',0,'AmmoBox_01_unhide',1,'AmmoBox_02_unhide',1,'FuelCanister_01_unhide',1,'FuelCanister_02_unhide',1,'FuelCanister_03_unhide',1,'beacon_01_org_unhide',0,'sideskirt_unhide',1,'camonet_hull_unhide',1,'camofoilage_hull_unhide',1,'camonet_MainTurret_trav_unhide',1,'camofoilage_MainTurret_trav_unhide',1,'camonet_MainTurret_elev_unhide',1]] call BIS_fnc_initVehicle;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };
    };

    // Cars
    class gm_ge_civ_typ253;
    class BSKULLS_CW_car_00 : gm_ge_civ_typ253 {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Civ Typ253 2c+6p";
        side = 1;
        faction = "BSKULLS_CW";
        crew = "BSKULLS_CW_tank_crew_01";
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['gm_zis508',1], ['cargo_rack_01_unhide',1,'cargo_rack_03_unhide',0,'cargo_rack_04_unhide',1,'bag_01_unhide',1,'bag_02_unhide',0,'box_01_unhide',0,'box_02_unhide',1,'box_03_unhide',0,'canister_01_unhide',1,'canister_02_unhide',1,'ladder_02_unhide',0,'pipes_01_unhide',0,'pipes_02_unhide',0,'pipes_03_unhide',0,'pipes_04_unhide',0,'suitcase_01_unhide',0,'suitcase_02_unhide',0,'suitcase_03_unhide',0,'suitcase_04_unhide',0,'suitcase_05_unhide',0,'ladder_01_unhide',1,'blinker_external_unhide',1,'taxi_sign_unhide',0,'sirenLights_01_unhide',0,'sirenLights_05_unhide',0,'sirenLights_02_unhide',0,'wheel_1_1_cap_unhide',1]] call BIS_fnc_initVehicle;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };
    };
    class bo_app66_green;
    class BSKULLS_CW_car_01 : bo_app66_green {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        displayName = "APP 66 x10";
        side = 1;
        faction = "BSKULLS_CW";
        crew = "BSKULLS_CW_tank_crew_01";
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['paint_green',1], ['lightcamo',1,'HideBeacon',0]] call BIS_fnc_initVehicle;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };
    };

    // Artillery
    class gm_ge_army_kat1_463_mlrs;
    class BSKULLS_art_01 : gm_ge_army_kat1_463_mlrs {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        displayName = "SF2 LARS2";
        side = 1;
        faction = "BSKULLS_CW";
        crew = "BSKULLS_CW_tank_crew_01";
        class TransportItems {
            class _xx_gm_boltcutter {count=1;name="gm_boltcutter";};
            class _xx_gm_repairkit_01 {count=1;name="gm_repairkit_01";};
            class _xx_gm_ge_firstaidkit_vehicle {count=1;name="gm_ge_firstaidkit_vehicle";};
        };
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit,['gm_ge_wdl',1]] call BIS_fnc_initVehicle;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };
    };
    class gm_dk_army_m109;
    class BSKULLS_art_02 : gm_dk_army_m109 {
        author = "rofz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M109";
        side = 1;
        faction = "BSKULLS_CW";
        crew = "BSKULLS_CW_tank_crew_01";

        class TransportItems {
            class _xx_gm_boltcutter {count=1;name="gm_boltcutter";};
            class _xx_gm_repairkit_01 {count=1;name="gm_repairkit_01";};
            class _xx_gm_ge_firstaidkit_vehicle {count=1;name="gm_ge_firstaidkit_vehicle";};
        };

        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit,['gm_dk_wdl',1],['CamoNet_01_unhide',1,'ammo_01_unhide',1,'camonet_hull_unhide',1,'camofoilage_hull_unhide',1,'camonet_MainTurret_trav_unhide',1,'camofoilage_MainTurret_trav_unhide',1]] call BIS_fnc_initVehicle;};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };
    };


    // UNITS

    class BSKULLS_CW_TL_Stephen_Viper_Falken_01 : B_recon_TL_F_OCimport_02 {
        author      = "rofz";
        displayName = "1 - TL Viper";
        side        = 1;
        faction     = "BSKULLS_CW";

        identityTypes[]         = {"gm_faces_camo_02","LanguageENG_F","gm_xx_facewear_scarf_01_oli"};
        uniformClass            = "gm_xx_army_uniform_fighter_04_wdl";
        linkedItems[]           = {"gm_ge_vest_sov_armor_80_wdl","gm_ge_headgear_psh77_down_oli","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","gm_xx_facewear_scarf_01_oli"};
        respawnlinkedItems[]    = {"gm_ge_vest_sov_armor_80_wdl","gm_ge_headgear_psh77_down_oli","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","gm_xx_facewear_scarf_01_oli"};
        weapons[]               = {"BSKULLS_gm_g3ka4a1_ris_blk","BSKULLS_gm_pimb_blk","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_g3ka4a1_ris_blk","BSKULLS_gm_pimb_blk","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        // items[]                 = {"ACE_EarPlugs","ACE_CableTie","ACE_Flashlight_MX991","ACE_RangeCard","ACE_EntrenchingTool","ACE_Fortify","MineDetector","ACE_Chemlight_Shield","ACE_DefusalKit",MAG_3(ACE_bodyBag),MAG_3(ACE_epinephrine),MAG_3(ACE_morphine),MAG_3(ACE_adenosine),MAG_3(ACE_salineIV_500),MAG_3(ACE_splint),MAG_3(ACE_tourniquet),MAG_30(ACE_packingBandage)};
        // respawnItems[]          = {"ACE_EarPlugs","ACE_CableTie","ACE_Flashlight_MX991","ACE_RangeCard","ACE_EntrenchingTool","ACE_Fortify","MineDetector","ACE_Chemlight_Shield","ACE_DefusalKit",MAG_3(ACE_bodyBag),MAG_3(ACE_epinephrine),MAG_3(ACE_morphine),MAG_3(ACE_adenosine),MAG_3(ACE_salineIV_500),MAG_3(ACE_splint),MAG_3(ACE_tourniquet),MAG_30(ACE_packingBandage)};
        // magazines[]             = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_2(ACE_Chemlight_HiBlue),MAG_2(ACE_Chemlight_HiGreen),MAG_2(ACE_Chemlight_HiRed),MAG_2(ACE_Chemlight_HiWhite),MAG_2(ACE_Chemlight_HiYellow),MAG_2(gm_handgrenade_conc_dm51a1),MAG_4(gm_handgrenade_frag_dm51a1),MAG_5(gm_8Rnd_9x18mm_B_pst_pm_blk),MAG_7(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};
        // respawnMagazines[]      = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_2(ACE_Chemlight_HiBlue),MAG_2(ACE_Chemlight_HiGreen),MAG_2(ACE_Chemlight_HiRed),MAG_2(ACE_Chemlight_HiWhite),MAG_2(ACE_Chemlight_HiYellow),MAG_2(gm_handgrenade_conc_dm51a1),MAG_4(gm_handgrenade_frag_dm51a1),MAG_5(gm_8Rnd_9x18mm_B_pst_pm_blk),MAG_7(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};
        items[]                 = {"MineDetector",MAG_10(gm_ge_army_burnBandage)};
        respawnItems[]          = {"MineDetector",MAG_10(gm_ge_army_burnBandage)};
        magazines[]             = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_conc_dm51a1),MAG_4(gm_handgrenade_frag_dm51a1),MAG_5(gm_8Rnd_9x18mm_B_pst_pm_blk),MAG_7(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};
        respawnMagazines[]      = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_conc_dm51a1),MAG_4(gm_handgrenade_frag_dm51a1),MAG_5(gm_8Rnd_9x18mm_B_pst_pm_blk),MAG_7(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};

        backpack                = "BSKULLS_TL";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setName ['Stephen Falken','Stephen','Falken'];_this setNameSound 'Viper';_this setUnitRank 'COLONEL';_this setSpeaker 'male03eng';_this setUnitTrait ['Engineer', true];_this setUnitTrait ['ExplosiveSpecialist' , true];_this setSkill 1;_this enableFatigue false;_this setCombatBehaviour 'STEALTH';[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    class BSKULLS_CW_Medic_Amanda_Fox_01 : B_recon_medic_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "2 - Medic Fox";
        side            = 1;
        faction         = "BSKULLS_CW";
        // icon            = "iconWomanMedic";

        identityTypes[]         = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Lady_Blue"};
        // uniformClass            = "TCGM_F_SoldierParamilitary2";
        linkedItems[]           = {"gm_ge_vest_sov_armor_80_wdl","gm_ge_headgear_hat_80_m62_oli","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","G_Lady_Blue"};
        respawnlinkedItems[]    = {"gm_ge_vest_sov_armor_80_wdl","gm_ge_headgear_hat_80_m62_oli","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","G_Lady_Blue"};
        weapons[]               = {"BSKULLS_gm_g3a3a1_ris_oli","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_g3a3a1_ris_oli","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        items[]                 = {MAG_5(gm_ge_army_burnBandage)};
        respawnItems[]          = {MAG_5(gm_ge_army_burnBandage)};
        magazines[]             = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_5(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};
        respawnMagazines[]      = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_5(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};

        backpack = "BSKULLS_Medic";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setName ['Amanda Fox','Amanda','Fox'];_this setNameSound 'Fox';_this setUnitRank 'MAJOR';_this setSpeaker 'rhs_Female01ENG'; _this setPitch 0.95; _this setFace 'TCGM_Fem_Stone';_this assignTeam 'BLUE';_this setUnitTrait ['Medic', true];_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;_this setCombatBehaviour 'STEALTH';_this setUnitCombatMode 'BLUE';[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    class BSKULLS_CW_Sniper_Vince_Vega_01 : B_Recon_Sharpshooter_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "3 - Sniper Vega";
        side            = 1;
        faction         = "BSKULLS_CW";

        identityTypes[]         = {"gm_faces_camo_01","LanguageENG_F","gm_headgear_foliage_summer_grass_02"};
        uniformClass            = "gm_xx_army_uniform_fighter_04_wdl";
        linkedItems[]           = {"gm_ge_vest_sov_armor_80_wdl","gm_ge_headgear_hat_boonie_wdl","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","gm_headgear_foliage_summer_grass_02"};
        respawnlinkedItems[]    = {"gm_ge_vest_sov_armor_80_wdl","gm_ge_headgear_hat_boonie_wdl","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","gm_headgear_foliage_summer_grass_02"};
        weapons[]               = {"BSKULLS_gm_msg90a1_blk","BSKULLS_gm_pimb_blk","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_msg90a1_blk","BSKULLS_gm_pimb_blk","gm_ferod16_oli","Throw","Put"};
        items[]                 = {MAG_10(gm_ge_army_burnBandage)};
        respawnItems[]          = {MAG_10(gm_ge_army_burnBandage)};
        magazines[]             = {MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_frag_dm51a1),MAG_6(gm_8Rnd_9x18mm_B_pst_pm_blk),MAG_7(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};
        respawnMagazines[]      = {MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_frag_dm51a1),MAG_6(gm_8Rnd_9x18mm_B_pst_pm_blk),MAG_7(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};

        // backpack = "BSKULLS_Sniper";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setName ['Vince Vega','Vince','Vega'];_this setNameSound 'Vega';_this setUnitRank 'COLONEL';_this assignTeam 'BLUE';_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;_this setCombatBehaviour 'STEALTH';_this setUnitCombatMode 'BLUE';[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    class BSKULLS_CW_Demo_Greg_McKendrick_01 : B_recon_exp_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "4 - Demo McKendrick";
        side            = 1;
        faction         = "BSKULLS_CW";

        identityTypes[]         = {"Head_Euro","LanguageENGB_F","gm_ge_facewear_stormhood_blk"};
        uniformClass            = "gm_xx_army_uniform_fighter_04_grn";
        linkedItems[]           = {"gm_ge_vest_sov_armor_80_oli","gm_ge_bgs_headgear_psh77_cover_down_smp","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","gm_ge_facewear_stormhood_blk"};
        respawnlinkedItems[]    = {"gm_ge_vest_sov_armor_80_oli","gm_ge_bgs_headgear_psh77_cover_down_smp","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","gm_ge_facewear_stormhood_blk"};
        weapons[]               = {"BSKULLS_gm_g3ka4a1_ris_blk","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_g3ka4a1_ris_blk","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        items[]                 = {"MineDetector","gm_repairkit_01"};
        respawnItems[]          = {"MineDetector","gm_repairkit_01"};
        magazines[]             = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_frag_dm51a1),MAG_5(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};
        respawnMagazines[]      = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_frag_dm51a1),MAG_5(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};

        backpack = "BSKULLS_Demo";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            // init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setName ['Greg McKendrick','Greg','McKendrick'];_this setNameSound 'McKendrick';_this setUnitRank 'MAJOR';_this assignTeam 'RED';_this setUnitTrait ['Engineer', true];_this setUnitTrait ['ExplosiveSpecialist', true];_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;_this setCombatBehaviour 'STEALTH';_this setUnitCombatMode 'BLUE';[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;_this addPrimaryWeaponItem 'rhsusf_acc_anpeq15_bk'; _this addPrimaryWeaponItem 'optic_ERCO_blk_F';reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setName ['Greg McKendrick','Greg','McKendrick'];_this setNameSound 'McKendrick';_this setUnitRank 'MAJOR';_this assignTeam 'BLUE';_this setUnitTrait ['Engineer', true];_this setUnitTrait ['ExplosiveSpecialist', true];_this setSpeaker 'male01engb';_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;_this setCombatBehaviour 'STEALTH';_this setUnitCombatMode 'BLUE';[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    class BSKULLS_CW_Medic_Jennifer_Jackson_01 : B_recon_medic_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "5 - Medic Jackson";
        side            = 1;
        faction         = "BSKULLS_CW";
        icon            = "iconWomanMedic";

        identityTypes[]         = {"Head_TCGM_Girls_WhiteCiv","Head_Female","rhsusf_shemagh_gogg_grn"};
        // uniformClass            = "TCGM_CombatFatigues_wdl_RollUp";
        linkedItems[]           = {"gm_ge_vest_sov_armor_80_blk","gm_dk_headgear_m52_oli","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","rhsusf_shemagh_gogg_grn"};
        respawnlinkedItems[]    = {"gm_ge_vest_sov_armor_80_blk","gm_dk_headgear_m52_oli","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","rhsusf_shemagh_gogg_grn"};
        weapons[]               = {"BSKULLS_gm_g3a3a1_ris_oli","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_g3a3a1_ris_oli","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        items[]                 = {MAG_10(gm_ge_army_burnBandage)};
        respawnItems[]          = {MAG_10(gm_ge_army_burnBandage)};
        magazines[]             = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_5(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};
        respawnMagazines[]      = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_5(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};

        backpack = "BSKULLS_Medic";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setName ['Jennifer Jackson','Jennifer','Jackson'];_this setNameSound 'Jackson';_this setUnitRank 'MAJOR';_this setSpeaker 'rhs_Female01ENG'; _this setPitch 1.1; _this setFace 'TCGM_Fem_Fox';_this assignTeam 'RED';_this setUnitTrait ['Medic', true];_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;_this setCombatBehaviour 'STEALTH';_this setUnitCombatMode 'BLUE';[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    class BSKULLS_CW_MG_Patrick_Frost_01 : B_recon_M_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "6 - MG Frost";
        side            = 1;
        faction         = "BSKULLS_CW";

        identityTypes[]         = {"gm_faces_camo_02","LanguageENGFRE_F","gm_headgear_foliage_summer_grass_01"};
        uniformClass            = "gm_xx_army_uniform_fighter_01_alp";
        linkedItems[]           = {"gm_ge_vest_sov_armor_80_oli","gm_ge_headgear_m62_net","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","gm_headgear_foliage_summer_grass_01"};
        respawnlinkedItems[]    = {"gm_ge_vest_sov_armor_80_oli","gm_ge_headgear_m62_net","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","gm_headgear_foliage_summer_grass_01"};
        weapons[]               = {"BSKULLS_gm_mg8a2_blk","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_mg8a2_blk","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        items[]                 = {MAG_10(gm_ge_army_burnBandage)};
        respawnItems[]          = {MAG_10(gm_ge_army_burnBandage)};
        magazines[]             = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_frag_dm51a1),MAG_4(gm_100Rnd_762x51mm_B_T_DM21A2_mg8_oli)};
        respawnMagazines[]      = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_frag_dm51a1),MAG_4(gm_100Rnd_762x51mm_B_T_DM21A2_mg8_oli)};

        // backpack = "BSKULLS_MG";

    };

    class BSKULLS_CW_AT_Kendall_Hawkins_01 : B_recon_LAT_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "7 - AT Hawkins";
        side            = 1;
        faction         = "BSKULLS_CW";

        identityTypes[]         = {"Head_NATO","LanguageENG_F","gm_headgear_foliage_summer_grass_01"};
        uniformClass            = "gm_xx_army_uniform_fighter_04_grn";
        linkedItems[]           = {"gm_ge_vest_sov_armor_80_oli","gm_ge_headgear_m62_net","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","gm_headgear_foliage_summer_grass_01"};
        respawnlinkedItems[]    = {"gm_ge_vest_sov_armor_80_oli","gm_ge_headgear_m62_net","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","gm_headgear_foliage_summer_grass_01"};
        weapons[]               = {"BSKULLS_gm_g3ka4a1_ris_blk","BSKULLS_gm_pzf84_oli","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_g3ka4a1_ris_blk","BSKULLS_gm_pzf84_oli","gm_ferod16_oli","Throw","Put"};
        items[]                 = {MAG_10(gm_ge_army_burnBandage)};
        respawnItems[]          = {MAG_10(gm_ge_army_burnBandage)};
        magazines[]             = {"gm_1Rnd_84x245mm_heat_t_DM12_carlgustaf",MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_frag_dm51a1),MAG_5(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};
        respawnMagazines[]      = {"gm_1Rnd_84x245mm_heat_t_DM12_carlgustaf",MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_frag_dm51a1),MAG_5(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};

        backpack = "BSKULLS_AT";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setName ['Kendall Hawkins','Kendall','Hawkins'];_this setNameSound 'Hawkins';_this setUnitRank 'SERGEANT';_this assignTeam 'RED';_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;_this setCombatBehaviour 'STEALTH';_this setUnitCombatMode 'BLUE';[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    class BSKULLS_CW_Ammo_Oscar_Martinez_01 : B_recon_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "8 - Ammo Martinez";
        side            = 1;
        faction         = "BSKULLS_CW";

        identityTypes[]         = {"Head_TK","LanguageENG_F","gm_xx_facewear_scarf_01_oli"};
        uniformClass            = "gm_xx_army_uniform_fighter_01_m84";
        linkedItems[]           = {"gm_ge_vest_sov_armor_80_oli","H_Hat_Safari_sand_F","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","gm_xx_facewear_scarf_01_oli"};
        respawnlinkedItems[]    = {"gm_ge_vest_sov_armor_80_oli","H_Hat_Safari_sand_F","ItemMap","ItemRadio","gm_ge_army_conat2","gm_watch_kosei_80","gm_xx_facewear_scarf_01_oli"};
        weapons[]               = {"BSKULLS_gm_g3ka4a1_ris_blk","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_g3ka4a1_ris_blk","gm_m72a3_oli","gm_ferod16_oli","Throw","Put"};
        items[]                 = {MAG_10(gm_ge_army_burnBandage)};
        respawnItems[]          = {MAG_10(gm_ge_army_burnBandage)};
        magazines[]             = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_frag_dm51a1),MAG_5(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};
        respawnMagazines[]      = {"gm_1Rnd_66mm_heat_m72a3",MAG_2(gm_smokeshell_wht_dm25),MAG_2(gm_handgrenade_frag_dm51a1),MAG_5(gm_40Rnd_762x51mm_AP_DM151_g3_blk)};

        backpack = "BSKULLS_Ammo";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setName ['Oscar Martinez','Oscar','Martinez'];_this setNameSound 'Martinez';_this setUnitRank 'CORPORAL';_this assignTeam 'RED';_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;_this setCombatBehaviour 'STEALTH';_this setUnitCombatMode 'BLUE';[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    class BSKULLS_CW_helo_crew_01 : B_helicrew_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "Crew, Helo";
        side            = 1;
        faction         = "BSKULLS_CW";
        rank            = "LIEUTENANT";

        identityTypes[]         = {"Head_Euro","LanguageENG_F","gm_ge_facewear_dustglasses"};
        uniformClass            = "gm_ge_army_uniform_pilot_rolled_oli";
        linkedItems[]           = {"gm_ge_army_vest_80_officer","gm_ge_headgear_sph4_oli","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","NVGogglesC_SSU_blk","gm_ge_facewear_dustglasses"};
        respawnlinkedItems[]    = {"gm_ge_army_vest_80_officer","gm_ge_headgear_sph4_oli","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","NVGogglesC_SSU_blk","gm_ge_facewear_dustglasses"};
        weapons[]               = {"BSKULLS_gm_pimb_blk","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_pimb_blk","gm_ferod16_oli","Throw","Put"};
        items[]                 = {MAG_5(gm_ge_army_burnBandage),"gm_repairkit_01"};
        respawnItems[]          = {MAG_5(gm_ge_army_burnBandage),"gm_repairkit_01"};
        magazines[]             = {MAG_2(gm_smokeshell_wht_dm25),MAG_3(gm_8Rnd_9x18mm_B_pst_pm_blk)};
        respawnMagazines[]      = {MAG_2(gm_smokeshell_wht_dm25),MAG_3(gm_8Rnd_9x18mm_B_pst_pm_blk)};

        backpack = "gm_backpack_t10_parachute";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setUnitRank 'LIEUTENANT';_this setUnitTrait ['Engineer', true];_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    class BSKULLS_CW_helo_pilot_01 : B_Helipilot_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "Pilot, Helo";
        side            = 1;
        faction         = "BSKULLS_CW";
        rank            = "MAJOR";

        identityTypes[]         = {"Head_Euro","LanguageENG_F","gm_ge_facewear_dustglasses"};
        uniformClass            = "gm_ge_army_uniform_pilot_oli";
        linkedItems[]           = {"gm_ge_army_vest_80_officer","gm_ge_headgear_sph4_oli","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","NVGogglesC_SSU_blk","gm_ge_facewear_dustglasses"};
        respawnlinkedItems[]    = {"gm_ge_army_vest_80_officer","gm_ge_headgear_sph4_oli","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","NVGogglesC_SSU_blk","gm_ge_facewear_dustglasses"};
        weapons[]               = {"BSKULLS_gm_pimb_blk","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_pimb_blk","gm_ferod16_oli","Throw","Put"};
        items[]                 = {MAG_5(gm_ge_army_burnBandage),"gm_repairkit_01"};
        respawnItems[]          = {MAG_5(gm_ge_army_burnBandage),"gm_repairkit_01"};
        magazines[]             = {MAG_2(gm_smokeshell_wht_dm25),MAG_3(gm_8Rnd_9x18mm_B_pst_pm_blk)};
        respawnMagazines[]      = {MAG_2(gm_smokeshell_wht_dm25),MAG_3(gm_8Rnd_9x18mm_B_pst_pm_blk)};

        backpack = "gm_backpack_t10_parachute";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setUnitRank 'MAJOR';_this setUnitTrait ['Engineer', true];_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    class BSKULLS_CW_fighter_pilot_01 : B_Fighter_Pilot_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "Pilot, Fighter";
        side            = 1;
        faction         = "BSKULLS_CW";
        rank            = "COLONEL";

        identityTypes[]         = {"Head_Euro","LanguageENG_F","gm_ge_facewear_dustglasses"};
        uniformClass            = "gm_ge_army_uniform_pilot_oli";
        linkedItems[]           = {"gm_ge_army_vest_80_officer","gm_ge_headgear_sph4_oli","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","NVGogglesC_SSU_blk","gm_ge_facewear_dustglasses"};
        respawnlinkedItems[]    = {"gm_ge_army_vest_80_officer","gm_ge_headgear_sph4_oli","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","NVGogglesC_SSU_blk","gm_ge_facewear_dustglasses"};
        weapons[]               = {"BSKULLS_gm_pimb_blk","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_pimb_blk","gm_ferod16_oli","Throw","Put"};
        items[]                 = {MAG_5(gm_ge_army_burnBandage),"gm_repairkit_01"};
        respawnItems[]          = {MAG_5(gm_ge_army_burnBandage),"gm_repairkit_01"};
        magazines[]             = {MAG_2(gm_smokeshell_wht_dm25),MAG_3(gm_8Rnd_9x18mm_B_pst_pm_blk)};
        respawnMagazines[]      = {MAG_2(gm_smokeshell_wht_dm25),MAG_3(gm_8Rnd_9x18mm_B_pst_pm_blk)};

        backpack = "gm_backpack_t10_parachute";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setUnitRank 'COLONEL';_this setUnitTrait ['Engineer', true];_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    class BSKULLS_CW_tank_crew_01 : B_helicrew_F_OCimport_02 {
        author          = "rofz";
        scope           = 2;
        scopeCurator    = 2;
        displayName     = "Crew, Tank/Artillery";
        side            = 1;
        faction         = "BSKULLS_CW";
        rank            = "MAJOR";

        identityTypes[]         = {"Head_Euro","LanguageENG_F","gm_ge_facewear_dustglasses"};
        uniformClass            = "gm_ge_army_uniform_crew_80_oli";
        linkedItems[]           = {"gm_ge_army_vest_80_officer","gm_ge_headgear_crewhat_80_blk","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","NVGogglesC_SSU_blk","gm_ge_facewear_dustglasses"};
        respawnlinkedItems[]    = {"gm_ge_army_vest_80_officer","gm_ge_headgear_crewhat_80_blk","ItemMap","ItemRadio","gm_ferod51_oli","gm_ge_army_conat2","gm_watch_kosei_80","NVGogglesC_SSU_blk","gm_ge_facewear_dustglasses"};
        weapons[]               = {"BSKULLS_gm_pimb_blk","gm_ferod16_oli","Throw","Put"};
        respawnWeapons[]        = {"BSKULLS_gm_pimb_blk","gm_ferod16_oli","Throw","Put"};
        items[]                 = {MAG_5(gm_ge_army_burnBandage),"gm_repairkit_01"};
        respawnItems[]          = {MAG_5(gm_ge_army_burnBandage),"gm_repairkit_01"};
        magazines[]             = {MAG_2(gm_smokeshell_wht_dm25),MAG_3(gm_8Rnd_9x18mm_B_pst_pm_blk)};
        respawnMagazines[]      = {MAG_2(gm_smokeshell_wht_dm25),MAG_3(gm_8Rnd_9x18mm_B_pst_pm_blk)};

        backpack = "";

        class EventHandlers : EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
            init = "if (local (_this select 0)) then {_onSpawn = {_this = _this select 0;sleep 3;_this setUnitRank 'MAJOR';_this setUnitTrait ['Engineer', true];_this enableIRLasers true;_this setSkill 1;_this enableFatigue false;[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;reload _this};_this spawn _onSpawn;(_this select 0) addMPEventHandler ['MPRespawn', _onSpawn];};";
        };

    };

    // BACKPACKS

    class THC_Bag65;

    class BSKULLS_TL: THC_Bag65 {
        scope=1;
        isbackpack = 1;
		icon = "iconBackpack";
        mass = 1;
        class TransportMagazines {
            class _xx_gm_40Rnd_762x51mm_AP_DM151_g3_blk {count=1;magazine="gm_40Rnd_762x51mm_AP_DM151_g3_blk";};
            class _xx_gm_7rnd_12ga_hk512_pellet {count=5;magazine="gm_7rnd_12ga_hk512_pellet";};
            class _xx_gm_explosive_petn_charge {count=2;magazine="gm_explosive_petn_charge";};
            class _xx_gm_mine_ap_dm31 {count=5;magazine="gm_mine_ap_dm31";};
            class _xx_gm_mine_at_dm21 {count=1;magazine="gm_mine_at_dm21";};
            class _xx_gm_handgrenade_frag_dm51a1 {count=5;magazine="gm_handgrenade_frag_dm51a1";};
        };
        class TransportItems {
            class _xx_gm_repairkit_01 {count=1;name="gm_repairkit_01";};
            class _xx_gm_ge_army_medkit_80 {count=1;name="gm_ge_army_medkit_80";};
            class _xx_BSKULLS_gm_msg90a1_blk {count=1;name="BSKULLS_gm_msg90a1_blk";};
            class _xx_BSKULLS_gm_hk512_ris_wud {count=1;name="BSKULLS_gm_hk512_ris_wud";};
            class _xx_gm_ge_facewear_m65 {count=1;name="gm_ge_facewear_m65";};
        };
        class TransportWeapons{};
    };

    class THC_Bag56;
    class BSKULLS_Medic: THC_Bag56 {
        scope=1;
        isbackpack = 1;
		icon = "iconBackpack";
        mass = 1;
        class TransportMagazines {
            // class _xx_gm_40Rnd_762x51mm_AP_DM151_g3_blk {count=2;magazine="gm_40Rnd_762x51mm_AP_DM151_g3_blk";};
            class _xx_gm_handgrenade_frag_dm51a1 {count=2;magazine="gm_handgrenade_frag_dm51a1";};
        };
        class TransportItems {
            class _xx_gm_ge_army_medkit_80 {count=1;name="gm_ge_army_medkit_80";};
            // class _xx_gm_ge_army_gauzeBandage {count=10;name="gm_ge_army_gauzeBandage";};
            // class _xx_gm_ge_army_gauzeCompress {count=10;name="gm_ge_army_gauzeCompress";};
            class _xx_gm_ferod51_oli {count=1;name="gm_ferod51_oli";};
            class _xx_gm_ge_facewear_m65 {count=1;name="gm_ge_facewear_m65";};
            class _xx_gm_ge_army_burnBandage {count=20;name="gm_ge_army_burnBandage";};
        };
        class TransportWeapons{};
    };

    class BSKULLS_Demo: THC_Bag65 {
        scope=1;
        isbackpack = 1;
		icon = "iconBackpack";
        mass = 1;
        class TransportMagazines {
            class _xx_gm_explosive_petn_charge {count=4;magazine="gm_explosive_petn_charge";};
            class _xx_gm_mine_at_dm21 {count=2;magazine="gm_mine_at_dm21";};
            class _xx_gm_mine_ap_dm31 {count=2;magazine="gm_mine_ap_dm31";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=2;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_gm_handgrenade_frag_dm51a1 {count=2;magazine="gm_handgrenade_frag_dm51a1";};
        };
        class TransportItems {
            class _xx_gm_ferod51_oli {count=1;name="gm_ferod51_oli";};
            class _xx_gm_ge_facewear_m65 {count=1;name="gm_ge_facewear_m65";};
            // class _xx_gm_repairkit_01 {count=1;name="gm_repairkit_01";};
        };
        class TransportWeapons{};        
    };

    class BSKULLS_AT: THC_Bag65 {
        scope=1;
        isbackpack = 1;
		icon = "iconBackpack";
        mass = 1;
        class TransportMagazines {
            class _xx_gm_1Rnd_84x245mm_heat_t_DM32_carlgustaf {count=5;magazine="gm_1Rnd_84x245mm_heat_t_DM32_carlgustaf";};
        };
        class TransportItems {
            class _xx_gm_ferod51_oli {count=1;name="gm_ferod51_oli";};
            class _xx_gm_ge_facewear_m65 {count=1;name="gm_ge_facewear_m65";};
        };
        class TransportWeapons{};        
    };

    class BSKULLS_Ammo: THC_Bag65 {
        scope=1;
        isbackpack = 1;
		icon = "iconBackpack";
        mass = 1;
        class TransportMagazines {
            class _xx_gm_100Rnd_762x51mm_B_T_DM21A2_mg8_oli {count=2;magazine="gm_100Rnd_762x51mm_B_T_DM21A2_mg8_oli";};
            class _xx_gm_40Rnd_762x51mm_AP_DM151_g3_blk {count=8;magazine="gm_40Rnd_762x51mm_AP_DM151_g3_blk";};
            class _xx_gm_mine_ap_dm31 {count=4;magazine="gm_mine_ap_dm31";};
            class _xx_gm_handgrenade_conc_dm51a1 {count=2;magazine="gm_handgrenade_conc_dm51a1";};
            class _xx_gm_handgrenade_frag_dm51a1 {count=4;magazine="gm_handgrenade_frag_dm51a1";};
            class _xx_gm_8Rnd_9x18mm_B_pst_pm_blk {count=2;magazine="gm_8Rnd_9x18mm_B_pst_pm_blk";};
            class _xx_gm_smokeshell_wht_dm25 {count=6;magazine="gm_smokeshell_wht_dm25";};
        };
        class TransportItems {
            class _xx_gm_ferod51_oli {count=1;name="gm_ferod51_oli";};
            class _xx_gm_ge_facewear_m65 {count=1;name="gm_ge_facewear_m65";};
        };
        class TransportWeapons{};        
    };

};


// NOTE (READ THIS BEFORE SCREWING THIS FILE UP!):
// SOME MODULES DO NOT SUPPORT ALIVE LOADOUT CLASS, SO INDIVIDUAL CLASSES FOR WEAPONS AND BACKPACKS ARE NEEDED!
// ALSO, ALIVE ORBAT SCREWS THE MAGAZINES ATTRIBUTE!
// ALSO, ALIVE ORBAT DOES NOT ADD ITEMS, THIS MUST BE FIXED MANUALLY!
