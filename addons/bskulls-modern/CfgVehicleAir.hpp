    // ── Air Vehicle Base Classes ────────────────────────────────────────────

    class B_Plane_CAS_01_dynamicLoadout_F;
    class B_Plane_CAS_01_dynamicLoadout_F_OCimport_01 : B_Plane_CAS_01_dynamicLoadout_F { scope = 0; };
    class B_Plane_CAS_01_dynamicLoadout_F_OCimport_02 : B_Plane_CAS_01_dynamicLoadout_F_OCimport_01 { scope = 0; };

    class B_Heli_Transport_03_F;
    class B_Heli_Transport_03_F_OCimport_01 : B_Heli_Transport_03_F { scope = 0; class Turrets; };
    class B_Heli_Transport_03_F_OCimport_02 : B_Heli_Transport_03_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class CopilotTurret;
            class MainTurret;
            class RightDoorGun;
            class CargoTurret_01;
            class CargoTurret_02;
        };
    };

    class B_Heli_Light_01_F;
    class B_Heli_Light_01_F_OCimport_01 : B_Heli_Light_01_F { scope = 0; class Turrets; };
    class B_Heli_Light_01_F_OCimport_02 : B_Heli_Light_01_F_OCimport_01 {
        class Turrets : Turrets {
            class CopilotTurret;
            class CargoTurret_01;
            class CargoTurret_02;
            class CargoTurret_03;
            class CargoTurret_04;
        };
    };

    class B_Heli_Attack_01_dynamicLoadout_F;
    class B_Heli_Attack_01_dynamicLoadout_F_OCimport_01 : B_Heli_Attack_01_dynamicLoadout_F { scope = 0; class Turrets; class Components;};
    class B_Heli_Attack_01_dynamicLoadout_F_OCimport_02 : B_Heli_Attack_01_dynamicLoadout_F_OCimport_01 {
        class Components : Components {
            class TransportPylonsComponent;
        };
        class Turrets : Turrets {
            class MainTurret;
        };
    };

    class B_Heli_Light_01_dynamicLoadout_F;
    class B_Heli_Light_01_dynamicLoadout_F_OCimport_01 : B_Heli_Light_01_dynamicLoadout_F { scope = 0; class Components;};
    class B_Heli_Light_01_dynamicLoadout_F_OCimport_02 : B_Heli_Light_01_dynamicLoadout_F_OCimport_01 {
        class Components : Components {
            class TransportPylonsComponent;
        };
    };

    // ── Air Vehicles ────────────────────────────────────────────────────────

    class B_PTbskull_Veh_Plane_blackops_01 : B_Plane_CAS_01_dynamicLoadout_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "A-164 Wipeout (CAS) (1c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Plane_Pilot_blackops_01";
        availableForSupportTypes[] = {"CAS_Bombing"};
        hiddenSelections[] += { "insignia" };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; _unit setVehicleReportOwnPosition true; _unit setVehicleReportRemoteTargets true; _unit setVehicleReceiveRemoteTargets true; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
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
        crew = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        availableForSupportTypes[] = {"Drop","Transport"};
        class Turrets : Turrets
        {
            class CopilotTurret : CopilotTurret { gunnerType = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01"; };
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Unit_Helo_Crew_blackops_01"; };
            class RightDoorGun : RightDoorGun { gunnerType = "B_PTbskull_Veh_Unit_Helo_Crew_blackops_01"; };
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
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [_unit,['Black',1], true] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
            // init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [_unit,['Black',1], true] call BIS_fnc_initVehicle; _unit setVariable['daoExclude',TRUE,TRUE]; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Helo_blackops_02 : B_Heli_Light_01_F_OCimport_02 {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "MH-9 Hummingbird (1c7p)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        availableForSupportTypes[] = {"Drop","Transport"};
        class Turrets : Turrets {
            class CopilotTurret : CopilotTurret { gunnerType = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01"; dontCreateAI = 1; };
            class CargoTurret_01 : CargoTurret_01 { gunnerType = ""; };
            class CargoTurret_02 : CargoTurret_02 { gunnerType = ""; };
            class CargoTurret_03 : CargoTurret_03 { gunnerType = ""; };
            class CargoTurret_04 : CargoTurret_04 { gunnerType = ""; };
        };
        maximumLoad = 50000;
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [ _unit, nil, ['AddBenches',1,'AddTread',1,'AddBackseats',1,'AddHoldingFrame',1,'AddTread_Short',0]] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Helo_blackops_03 : B_Heli_Attack_01_dynamicLoadout_F_OCimport_02 {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "AH-99 Blackfoot (2c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        availableForSupportTypes[] = {"CAS_Bombing"};
        maximumLoad = 50000;
        class Turrets : Turrets {
            class MainTurret : MainTurret { gunnerType = ""; };
        };
        class Components : Components {
                class TransportPylonsComponent : TransportPylonsComponent {
                    class pylons {
                        class PylonLeft1 {
                            attachment = "PylonRack_12Rnd_PG_missiles";
                            bay = 1;
                            hardpoints[] = {"SCALPEL_1RND","B_ASRAAM","DAR","DAGR"};
                            priority = 5;
                            turret[] = {0};
                            UIposition[] = {0.06,0.4};
                        };
                        class PylonLeft2 {
                            attachment = "PylonMissile_1Rnd_LG_scalpel";
                            bay = 1;
                            hardpoints[] = {"SCALPEL_1RND","B_ASRAAM"};
                            priority = 4;
                            turret[] = {0};
                            UIposition[] = {0.08,0.35};
                        };
                        class PylonLeft3 {
                            attachment = "PylonRack_12Rnd_missiles";
                            bay = 1;
                            hardpoints[] = {"SCALPEL_1RND","B_ASRAAM","DAR","DAGR"};
                            priority = 3;
                            turret[] = {0};
                            UIposition[] = {0.1,0.3};
                        };
                        class PylonRight1 : PylonLeft1 {
                            mirroredMissilePos = 1;
                            UIposition[] = {0.64,0.4};
                        };
                        class PylonRight2 : PylonLeft2 {
                            mirroredMissilePos = 2;
                            UIposition[] = {0.62,0.35};
                        };
                        class PylonRight3 : PylonLeft3{
                            mirroredMissilePos = 3;
                            UIposition[] = {0.59,0.3};
                        };
                    };
                };
            };
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

    class B_PTbskull_Veh_Helo_blackops_04 : B_Heli_Light_01_dynamicLoadout_F_OCimport_02 {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "AH-9 Pawnee (2c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01";
        hiddenSelections[] += { "insignia" };
        availableForSupportTypes[] = {"CAS_Bombing"};
        maximumLoad = 50000;
        class Components : Components {
            class TransportPylonsComponent : TransportPylonsComponent {
                class pylons {
                    class PylonLeft1 {
                        attachment = "PylonRack_4Rnd_LG_scalpel"; // PylonRack_12Rnd_missiles (HE), PylonRack_12Rnd_PG_missiles (AT), PylonMissile_1Rnd_LG_scalpel, PylonRack_7Rnd_Rocket_04_AP_F or PylonRack_7Rnd_Rocket_04_HE_F
                        hardpoints[] = {"DAR","DAGR","B_SHIEKER","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR"};
                        priority = 5;
                        UIposition[] = {0.06,0.4};
                    };
                    class PylonRight1 : PylonLeft1 {
                        mirroredMissilePos = 1;
                        UIposition[] = {0.59,0.4};
                    };
                };
            };
        };
        class TransportBackpacks {TRANSPORTBACKPACKS};
        class TransportItems {TRANSPORTITEMS};
        class TransportMagazines {TRANSPORTMAGAZINES};
        class TransportWeapons {TRANSPORTWEAPONS};
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; [ _unit, nil, ['AddTread',1,'AddTread_Short',0]] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
        };
    };

