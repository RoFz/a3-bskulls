    // ── Fire Support Base Classes ────────────────────────────────────────────

    class B_MBT_01_arty_F;
    class B_MBT_01_arty_F_OCimport_01 : B_MBT_01_arty_F { scope = 0; class Turrets; };
    class B_MBT_01_arty_F_OCimport_02 : B_MBT_01_arty_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class B_MBT_01_mlrs_F;
    class B_MBT_01_mlrs_F_OCimport_01 : B_MBT_01_mlrs_F { scope = 0; class Turrets; };
    class B_MBT_01_mlrs_F_OCimport_02 : B_MBT_01_mlrs_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    class Mortar_01_base_F;
    class Mortar_01_base_F_OCimport_01 : Mortar_01_base_F { scope = 0; class Turrets; };
    class Mortar_01_base_F_OCimport_02 : Mortar_01_base_F_OCimport_01
    {
        class Turrets : Turrets
        {
            class MainTurret;
        };
    };

    // ── Fire Support Assets ──────────────────────────────────────────────────

    class B_PTbskull_Veh_Artillery_blackops_01 : B_MBT_01_arty_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "M4 Scorcher (3c)";
        side = 1;
        faction = "bskull_fc_mo";
        crew = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets
        {
            class MainTurret : MainTurret {
                gunnerType = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01";
                magazines[] = {"64Rnd_155mm_Plus_Mo_shells","8Rnd_155mm_Plus_Mo_guided","12Rnd_155mm_Plus_Mo_mine","4Rnd_155mm_Plus_Mo_Cluster","8Rnd_155mm_Plus_Mo_LG","12Rnd_155mm_Plus_Mo_AT_mine"};
                weapons[] = {"B_PTbskull_Wea_art_gun_01"};
            };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; [_unit,['Olive',1],['showCanisters',1,'showCamonetTurret',1,'showAmmobox',1,'showCamonetHull',1]] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
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
        crew = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01";
        hiddenSelections[] += { "insignia" };
        class Turrets : Turrets {
            class MainTurret : MainTurret { gunnerType = "B_PTbskull_Veh_Unit_Tank_Crew_blackops_01"; };
        };
        class EventHandlers : EventHandlers {
            fired = "_unit = _this select 0;_unit setVehicleAmmo 1";
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0; _unit allowdamage false; [_unit,['Olive',1],['showCamonetTurret',1,'showCamonetHull',1]] call BIS_fnc_initVehicle; [_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};";
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
        crew = "B_PTbskull_Veh_Unit_Vehicle_Crew_blackops_01";
        availableForSupportTypes[] = {"Artillery"};
        class Turrets : Turrets
        {
            class MainTurret : MainTurret {
                discreteDistance[] = {100,200,300,400,500,700,1000,1600,2000,2400,2800,3200,3600,4000,4400,4800,5200};
                magazines[] = {"80Rnd_82mm_Mo_shells_PLUS"};
                maxTurn = 360;
            };
        };
        class EventHandlers : EventHandlers
        {
            init = "if (local (_this select 0)) then {_onSpawn = {sleep 0.3; _unit = _this select 0;vehicle player loadMagazine [[0], 'FakeWeapon', '80Rnd_82mm_Mo_shells_PLUS'];while {true} do {sleep 600;_unit setVehicleAmmo 1;[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;};_this spawn _onSpawn;};};";
        };
    };
