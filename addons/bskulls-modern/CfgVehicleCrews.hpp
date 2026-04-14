    // ── Vehicle Crew Base Classes ────────────────────────────────────────────

    class B_Fighter_Pilot_F;
    class B_Fighter_Pilot_F_OCimport_01 : B_Fighter_Pilot_F { scope = 0; };
    class B_Fighter_Pilot_F_OCimport_02 : B_Fighter_Pilot_F_OCimport_01
    {
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManOfficer";
    };

    class B_Helipilot_F;
    class B_Helipilot_F_OCimport_01 : B_Helipilot_F { scope = 0; };
    class B_Helipilot_F_OCimport_02 : B_Helipilot_F_OCimport_01
    {
        sensitivity = 9;
        sensitivityEar = 3;
        icon = "iconManLeader";
    };

    class B_helicrew_F;
    class B_helicrew_F_OCimport_01 : B_helicrew_F { scope = 0; };
    class B_helicrew_F_OCimport_02 : B_helicrew_F_OCimport_01
    {
        sensitivity = 9;
        sensitivityEar = 3;
    };

    class B_crew_F;
    class B_crew_F_OCimport_01 : B_crew_F { scope = 0; };
    class B_crew_F_OCimport_02 : B_crew_F_OCimport_01
    {
        sensitivity = 9;
        sensitivityEar = 3;
    };

    // ── Vehicle Crews ────────────────────────────────────────────────────────

    class B_PTbskull_Veh_Unit_Plane_Pilot_blackops_01 : B_Fighter_Pilot_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Plane Pilot";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_PilotHelmetFighter_B","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch","G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_PilotHelmetFighter_B","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch","G_Aviator"};
        weapons[] = {"B_PTbskull_Wea_SMG_01_vermin","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_01_vermin","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        backpack = "B_Parachute";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\100_plane-pilot.sqf';";
        };
    };

    class B_PTbskull_Veh_Unit_Helo_Pilot_blackops_01 : B_Helipilot_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Helo Pilot";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_PilotHelmetHeli_B","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_PilotHelmetHeli_B","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        weapons[] = {"B_PTbskull_Wea_SMG_01_vermin","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_01_vermin","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        backpack = "B_Parachute";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\200_helo-pilot.sqf';";
        };
    };

    class B_PTbskull_Veh_Unit_Helo_Crew_blackops_01 : B_helicrew_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Helo Crew";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_NATO_pilot"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Heli_Crew_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Heli_Crew_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG};
        weapons[] = {"B_PTbskull_Wea_SMG_01_vermin","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_01_vermin","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        backpack = "B_Parachute";
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\204_helo-crew.sqf';";
        };
    };

    class B_PTbskull_Veh_Unit_Tank_Crew_blackops_01 : B_crew_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Tank Crew";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_NATO_default"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_Tank_eaf_F","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_Tank_eaf_F","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG};
        weapons[] = {"B_PTbskull_Wea_SMG_01_vermin","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_01_vermin","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\300_tank-crew.sqf';";
        };
    };

    class B_PTbskull_Veh_Unit_Boat_Crew_blackops_01 : B_crew_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Boat Crew";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Cap_HS_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Cap_HS_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        weapons[] = {"B_PTbskull_Wea_ar_02_r11","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_ar_02_r11","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","JAS_RSASS_20rnd_M62_Tracer_Red_mag","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\400_boat-crew.sqf';";
        };
    };

    class B_PTbskull_Veh_Unit_Vehicle_Crew_blackops_01 : B_crew_F_OCimport_02
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        displayName = "Vehicle Crew";
        side = 1;
        faction = "bskull_fc_mo";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_Lowprofile"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Combat_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Lowprofile"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Combat_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Lowprofile"};
        weapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        respawnWeapons[] = {"B_PTbskull_Wea_SMG_02_sting","B_PTbskull_Wea_pistol_01_4five",DEFAULT_BINOCULARS,"Throw","Put"};
        items[] = {BASE_KIT};
        respawnitems[] = {BASE_KIT};
        magazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        respawnMagazines[] = {"B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_pistol_01_4five_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","B_PTbskull_Wea_SMG_02_sting_AMMO","SmokeShell","SmokeShell","SmokeShellYellow","SmokeShellRed","SmokeShellGreen","SmokeShellBlue","MiniGrenade","MiniGrenade"};
        class EventHandlers : EventHandlers
        {
            init = "_this execVM '\bskulls-modern\scripts\500_vehicle-crew.sqf';";
        };
    };
