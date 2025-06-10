 [_this, 'B_PTbskull_Ins'] call BIS_fnc_setUnitInsignia;
 [_unit, 'B_PTbskull_Ins'] call BIS_fnc_setUnitInsignia;

[_unit, 'B_PTbskull_Ins'] call BIS_fnc_setUnitInsignia;


_unit = _this select 0; sleep 3; [_unit, 'B_PTbskull_Ins'] call BIS_fnc_setUnitInsignia;







    // Too weak - weird sound
    // class B_PTbskull_Veh_Plane_blackops_02 : RHS_A10_OCimport_02
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     displayName = "A-10 Thunderbolt (CAS) (1c)";
    //     side = 1;
    //     faction = "bskull_fc_mo";
    //     crew = "B_PTbskull_Veh_Plane_Pilot_blackops_01";
    //     availableForSupportTypes[] = {"CAS_Bombing"};
    //     // magazines[] = {"rhs_mag_1150Rnd_30x173_mixed"}; --> ammo = "rhs_ammo_30x173mm_GAU8_mixed";
    //     // weapons[] = {"rhs_weap_MASTERSAFE","RHS_weap_gau8"};
    //     // RHS_weap_gau8: magazines[] = {"rhs_mag_1150Rnd_30x173","rhs_mag_1150Rnd_30x173_mixed","rhs_mag_1000Rnd_30x173","rhs_mag_1000Rnd_30x173_mixed"};
    //     class EventHandlers : EventHandlers
    //     {
    //         // class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base { };
    //         init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit allowdamage false;_unit setVehicleReportOwnPosition true; _unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true;};_this spawn _onSpawn;};";
    //         class ALiVE_orbatCreator
    //         {
    //             init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit allowdamage false;_unit setVehicleReportOwnPosition true; _unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true;};_this spawn _onSpawn;};";
    //         };

    //     };
    //     // custom attributes (do not delete)
    //     ALiVE_orbatCreator_owned = 1;
    // };



    class B_PTbskull_Veh_Plane_blackops_01 : B_Plane_CAS_01_dynamicLoadout_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "A-164 Wipeout (CAS) (1c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Plane_Pilot_blackops_01";
        availableForSupportTypes[] = {"CAS_Bombing"};
        hiddenSelections[] += { "insignia" };
        // inheritsFrom (configfile >> "CfgWeapons" >> "Gatling_30mm_Plane_CAS_01_F" >> "magazines"); = none
        // inheritsFrom (configfile >> "CfgVehicles" >> "B_PTbskull_Veh_Plane_blackops_01" >> "magazines"); =
        // inheritsFrom (configfile >> "CfgVehicles" >> "B_Plane_CAS_01_dynamicLoadout_F" >> "weapons"); = none
        // weapons[] = {"Gatling_30mm_Plane_CAS_01_F","Laserdesignator_pilotCamera","CMFlareLauncher"};
        // inheritsFrom (configfile >> "CfgWeapons" >> "Gatling_30mm_Plane_CAS_01_F" >> "MG8_close" >> "recoil"); = none
        // inheritsFrom (
        // inheritsFrom (
        // recoil = "Empty";
        // recoilProne = "recoil_auto_primary_prone_3outof10";

        // did not work well: recoil of the gun brings the plane down
        // magazines[] = {"MG8_1174Rnd_Gau8_30mm_PLUS","Laserbatteries","240Rnd_CMFlare_Chaff_Magazine"};
        // recoilProne = "";
        // weapons[] = {"B_PTbskull_Wea_cas_gun_01","Laserdesignator_pilotCamera","CMFlareLauncher"};

        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; _unit setVehicleReportOwnPosition true; _unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true;};_this spawn _onSpawn; [_this, 'B_PTbskull_Ins'] call BIS_fnc_setUnitInsignia;};";
        };
    };


	    class B_PTbskull_Veh_Helo_blackops_01 : B_Heli_Transport_03_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "CH-67 Huron (Miniguns) (4c16p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        // typicalCargo[] = {"B_recon_TL_F", "B_Recon_Sharpshooter_F", "B_recon_exp_F", "B_recon_LAT_F"};
        availableForSupportTypes[] = {"Drop","Transport"};
        // hiddenSelectionsTextures[] = {"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_co.paa","\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_co.paa","\bskulls-modern\textures\black_skulls_insig_128_128.paa"};
        class Turrets : Turrets
        {
            class CopilotTurret : CopilotTurret { gunnerType = "B_PTbskull_Veh_Helo_Pilot_blackops_01"; };
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Helo_Crew_blackops_01"; };
            class RightDoorGun : RightDoorGun { gunnerType = "B_PTbskull_Veh_Helo_Crew_blackops_01"; };
            class CargoTurret_01 : CargoTurret_01 { gunnerType = ""; };
            class CargoTurret_02 : CargoTurret_02 { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS_HELO};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            // init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit setObjectTextureGlobal [0,'\A3\Air_F_Heli\Heli_Transport_03\Data\Heli_Transport_03_ext01_black_CO.paa'];_unit setObjectTextureGlobal [1,'\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_black_co.paa'];waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_Nemesis;};_this spawn _onSpawn;};";
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; };_this spawn _onSpawn;};";
        };
    };



	    class B_PTbskull_Veh_Drone_blackops_02 : B_UGV_01_rcws_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "UGV Stomper RCWS (1p)";
        side = 1;
        faction = "bskull_fc_mo";
        reportOwnPosition = 1;
        receiveRemoteTargets = 1;
        reportRemoteTargets = 1;
        crew = "B_PTbskull_Veh_UAV_AI_GROUND";
        hiddenSelections[] += { "insignia" };
        // armorWheels = 1.5;
        armor = 300;
        hiddenSelectionsTextures[] = {"\A3\Soft_F_Exp\UGV_01\Data\UGV_01_ext_olive_CO.paa","\A3\Soft_F_Exp\UGV_01\Data\UGV_01_int_olive_CO.paa","\A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa"};
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = ""; };
            class CargoTurret_01 : CargoTurret_01 { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [_unit, ['Olive', 1], true] call BIS_fnc_initVehicle;_unit setVehicleRadar 1;_unit setVehicleReportOwnPosition true; _unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true;};_this spawn _onSpawn;};";
        };
    };



	    class B_PTbskull_Veh_Artillery_blackops_01 : B_MBT_01_arty_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M4 Scorcher (3c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        // hiddenSelections[] = {"Camo1","Camo2","Camo3","CamoNet","insignia"};
        class Turrets : Turrets
        {
            class MainTurret : MainTurret {
                gunnerType = "B_PTbskull_Veh_Tank_Crew_blackops_01";
                magazines[] = {"64Rnd_155mm_Plus_Mo_shells","8Rnd_155mm_Plus_Mo_guided","12Rnd_155mm_Plus_Mo_mine","4Rnd_155mm_Plus_Mo_Cluster","8Rnd_155mm_Plus_Mo_LG","12Rnd_155mm_Plus_Mo_AT_mine"}; // "32Rnd_155mm_Mo_shells","4Rnd_155mm_Mo_guided","6Rnd_155mm_Mo_mine","2Rnd_155mm_Mo_Cluster","6Rnd_155mm_Mo_smoke","2Rnd_155mm_Mo_LG","6Rnd_155mm_Mo_AT_mine"
                weapons[] = {"B_PTbskull_Wea_art_gun_01"}; // mortar_155mm_AMOS
            };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; [_unit,['Olive',1],['showCanisters',1,'showCamonetTurret',1,'showAmmobox',1,'showCamonetHull',1]] call BIS_fnc_initVehicle; };_this spawn _onSpawn;};";
            // init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit setObjectTextureGlobal [0,'A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa'];_unit setObjectTextureGlobal [1,'A3\Armor_F_Exp\MBT_01\data\MBT_01_scorcher_olive_CO.paa'];_unit setObjectTextureGlobal [2,'A3\Data_F_Exp\Vehicles\Turret_olive_CO.paa'];_unit setObjectTextureGlobal [3,'A3\Armor_F\Data\camonet_NATO_Green_CO.paa'];};_this spawn _onSpawn;};";
        };
    };




	    class B_PTbskull_Veh_Artillery_blackops_02 : B_MBT_01_mlrs_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M5 Sandstorm MLRS (2c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        // hiddenSelections[] = {"Camo1","Camo2","CamoNet","insignia"};
        class Turrets : Turrets
        {
            class MainTurret : MainTurret {
                gunnerType = "B_PTbskull_Veh_Tank_Crew_blackops_01";
                // magazines[] = {"12Rnd_230mm_rockets"};
                // weapons[] = {"rockets_230mm_GAT"};
            };
        };
        class EventHandlers : EventHandlers
        {
            fired = "_unit = _this select 0;_unit setVehicleAmmo 1";
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; [_unit,['Olive',1],['showCamonetTurret',1,'showCamonetHull',1]] call BIS_fnc_initVehicle; };_this spawn _onSpawn;};";
            // init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit setObjectTextureGlobal [0,'A3\Armor_F_Exp\MBT_01\data\MBT_01_body_olive_CO.paa'];_unit setObjectTextureGlobal [1,'A3\Armor_F_Exp\MBT_01\data\MBT_01_MLRS_olive_co.paa'];_unit setObjectTextureGlobal [2,'A3\Armor_F\Data\camonet_NATO_Green_CO.paa'];};_this spawn _onSpawn;};";
        };
    };




    class B_PTbskull_Veh_APC_blackops_01 : B_APC_Wheeled_01_cannon_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "AMV-7 Marshall (3c8p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        // hiddenSelections[] = {"camo1","camo2","camo3","CamoNet","CamoSlat","insignia"};
        // _unit forceFlagTexture "\bskulls-modern\textures\black_skulls_insig_128_128.paa";
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Tank_Crew_blackops_01"; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit forceFlagTexture '\bskulls-modern\textures\black_skulls_insig_128_128.paa';[_unit, ['Olive',1], ['showCamonetTurret',1,'showCamonetHull',1,'showBags',1,'showSLATHull',1,'showSLATTurret',1]] call BIS_fnc_initVehicle;waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyMV;};_this spawn _onSpawn;};";
            //     init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit forceFlagTexture '\bskulls-modern\textures\black_skulls_insig_128_128.paa';_unit setObjectTextureGlobal [0,'A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_base_olive_CO.paa'];_unit setObjectTextureGlobal [1,'A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_adds_olive_co.paa'];_unit setObjectTextureGlobal [2,'A3\Armor_F_Exp\APC_Wheeled_01\data\APC_Wheeled_01_tows_olive_co.paa'];_unit setObjectTextureGlobal [3,'a3\Armor_F\Data\camonet_NATO_Green_CO.paa'];_unit setObjectTextureGlobal [4,'a3\Armor_F\Data\cage_olive_CO.paa'];waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyMV;};_this spawn _onSpawn;};";
        };
    };





	    class B_PTbskull_Veh_Car_blackops_02 : rhsusf_m1151_m2_v2_usarmy_wd_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M1151A1 (M2) x5";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Vehicle_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        // HiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa","rhsusf\addons\rhsusf_rg33l\data\rhsusf_camonet_wdl_co.paa","insignia"};
        // hiddenSelections[] = {"insignia"}; // does not work
        armorGlass = 1.5;
        class Turrets : Turrets
        {
            class OGPK_Turret : OGPK_Turret { gunnerType = ""; };
            class CoDriverTurret : CoDriverTurret { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit forceFlagTexture '\bskulls-modern\textures\black_skulls_insig_128_128.paa';[_unit, ['rhs_woodland',1], ['DUKE_Hide',0,'bumper2_hide',0,'hide_ogpkover',0,'hide_ogpknet',0,'hide_ogpkbust',0,'hide_rhino',1,'door_LF',0,'door_LB',0,'door_RF',0,'door_RB',0,'door_trunk',0,'iff_hide',0,'dwf_kit_Hide',0,'snorkel_lower',0,'BFT_Hide',0,'Antennas_Hide',0,'hide_spare',0]] call BIS_fnc_initVehicle;waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyMV;[_unit, 'B_PTbskull_Wea_Insignia'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
            //     init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit setObjectTextureGlobal [0,'rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa'];_unit setObjectTextureGlobal [1,'rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa'];_unit setObjectTextureGlobal [2,'rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa'];_unit setObjectTextureGlobal [3,'rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa'];_unit setObjectTextureGlobal [4,'rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa'];_unit setObjectTextureGlobal [5,'rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa'];_unit setObjectTextureGlobal [6,'rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa'];_unit setObjectTextureGlobal [7,'rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa'];_unit setObjectTextureGlobal [8,'rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa'];_unit setObjectTextureGlobal [9,'rhsusf\addons\rhsusf_rg33l\data\rhsusf_camonet_wdl_co.paa'];_unit setObjectTextureGlobal [10,'rhsusf\addons\rhsusf_m1165\data\rhsusf_m11165a1_gmv_h246mount_wd_co.paa'];waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyMV;[_unit, 'B_PTbskull_Wea_Insignia'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };





    class B_PTbskull_Veh_Truck_blackops_01 : rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M1078A1P2-B (O-GPK/M2) (2c13p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Vehicle_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        armorGlass = 1.5;
        class Turrets : Turrets
        {
            class M2_Turret : M2_Turret { gunnerType = ""; };
            class CargoTurret_01 : CargoTurret_01 { gunnerType = ""; };
            class CargoTurret_02 : CargoTurret_02 { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, nil, ['hide_ogpkover',0,'hide_ogpknet',0,'hide_ogpkbust',0,'hide_cover',0,'hide_spare',0,'hide_scaffold',0,'hide_bench',0]] call BIS_fnc_initVehicle;waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyMV;};_this spawn _onSpawn;};";
            //     init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;_unit setObjectTextureGlobal [0,'rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa'];_unit setObjectTextureGlobal [1,'rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa'];_unit setObjectTextureGlobal [2,'rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa'];_unit setObjectTextureGlobal [3,'rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa'];_unit setObjectTextureGlobal [4,'rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa'];_unit setObjectTextureGlobal [5,'rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa'];_unit setObjectTextureGlobal [6,'rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa'];_unit setObjectTextureGlobal [7,'rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa'];_unit setObjectTextureGlobal [8,'rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa'];_unit setObjectTextureGlobal [9,'rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa'];_unit setObjectTextureGlobal [10,'rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa'];_unit setObjectTextureGlobal [11,'rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa'];_unit setObjectTextureGlobal [12,'rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa'];_unit setObjectTextureGlobal [13,'rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa'];_unit setObjectTextureGlobal [14,'rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa'];_unit setObjectTextureGlobal [15,'rhsusf\addons\rhsusf_fmtv\data\fmtv_sovchassis_wd_co.paa'];_unit setObjectTextureGlobal [16,'rhsusf\addons\rhsusf_fmtv\data\fmtv_sovcab_w_co.paa'];_unit setObjectTextureGlobal [17,'rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa'];_unit setObjectTextureGlobal [18,'rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa'];_unit setObjectTextureGlobal [19,'rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa'];waitUntil{!(isNil'dapsReady')};waitUntil{dapsReady};_unit setVariable['dapsCanSmoke',1,TRUE];_unit spawn DAPS_fnc_APSTrophyMV;};_this spawn _onSpawn;};";
        };
    };


    class B_PTbskull_Veh_Mortar_blackops_01 : Mortar_01_base_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Mk6+ Mortar (82mm)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Vehicle_Crew_blackops_01";
        availableForSupportTypes[] = {"Artillery"};
        class Turrets : Turrets
        {
            class MainTurret : MainTurret {
                discreteDistance[] = {100,200,300,400,500,700,1000,1600,2000,2400,2800,3200,3600,4000,4400,4800,5200};
                magazines[] = {"80Rnd_82mm_Mo_shells_PLUS"};
                // magazines[] = {"8Rnd_82mm_Mo_shells","8Rnd_82mm_Mo_shells","8Rnd_82mm_Mo_shells","8Rnd_82mm_Mo_shells","8Rnd_82mm_Mo_Flare_white","8Rnd_82mm_Mo_Smoke_white"};
                // magazines[] += {"80Rnd_82mm_Mo_shells_PLUS"};
                maxTurn = 360;
            };
        };
        class EventHandlers : EventHandlers
        {
            // class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base { };
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;vehicle player loadMagazine [[0], 'FakeWeapon', '80Rnd_82mm_Mo_shells_PLUS'];while {true} do {sleep 600;_unit setVehicleAmmo 1;};_this spawn _onSpawn;};};";
        };
    };


    class B_PTbskull_Veh_Radar_blackops_01 : Radar_System_01_base_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "AN/MPQ-105 Radar";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_UAV_AI_GROUND";
        hiddenSelections[] += { "insignia" };
        // bin\config.bin/CfgVehicles/Radar_System_01_base_F/Turrets/MainTurret
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = ""; };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['Olive', 1], true] call BIS_fnc_initVehicle;_unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true;while {true} do {{_unit lookAt (_unit getRelPos [100, _x]);sleep 2.45;} forEach [120, 240, 0];};};_this spawn _onSpawn;};";
        };
    };


    class B_PTbskull_Veh_SAM_blackops_01 : SAM_System_03_base_F_OCimport_02
    {
        // get turrets 1:
        // "B_SAM_System_03_F" call BIS_fnc_vehicleCrewTurrets;
        // get turrets 2:
        // ["B_SAM_System_03_F", [0]] call BIS_fnc_turretConfig; // bin\config.bin/CfgVehicles/SAM_System_03_base_F/Turrets/MainTurret
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "MIM-145 Defender SAM";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_UAV_AI_GROUND";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret { gunnerType = ""; };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;[_unit, ['Olive', 1], true] call BIS_fnc_initVehicle;[_unit, 'B_PTbskull_Wea_Insignia'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
            // _unit addEventHandler ['Fired',{(_this select 0) setVehicleAmmo 1}]
            fired = "_unit = _this select 0;_unit setVehicleAmmo 1";
        };
    };
