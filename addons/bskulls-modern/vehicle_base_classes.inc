// CfgVehicleBaseClasses.hpp
// Enriched base classes for all 14 named units.
// Included from inside the CfgVehicles block in CfgVehicles.hpp.
// Properties defined here are inherited by all variant classes;
// only properties that differ between variants need to be declared in the variant.

    // ─── 01 Viper ────────────────────────────────────────────────────────────────
    // uniformClass and linkedItems[] are NOT centralised here — they vary per variant.
    class B_PTbskull_Veh_Unit_Viper_base : B_recon_TL_F_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "Falken";
        identityTypes[] = {"Head_NATO_camo_semiarid","LanguageENG_F",VIPER_GOGGLES};
        uniformClass = "U_SSU_Stealth_Uniform_Ghillie_Black";
        linkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,VIPER_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VIPER_GOGGLES};
    };

    // ─── 02 Fox ──────────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Fox_base : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        formationX = 2;
        formationZ = 2;
        faction = "bskull_fc_mo";
        identity = "Fox";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",FOX_GOGGLES};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,FOX_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,FOX_GOGGLES};
    };

    // ─── 03 Vega ─────────────────────────────────────────────────────────────────
    // uniformClass defaults to tna_F; _03/_04 inherit from a sibling and override it.
    class B_PTbskull_Veh_Unit_Vega_base : B_Recon_Sharpshooter_F_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "Vega";
        identityTypes[] = {"Head_NATO_camo_lush","LanguageGRE_F",VEGA_GOGGLES};
        uniformClass = "U_B_T_FullGhillie_tna_F";
        linkedItems[] = {"B_PTbskull_Vest_blackops_02",VEGA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VEGA_GOGGLES};
        respawnlinkedItems[] = {"B_PTbskull_Vest_blackops_02",VEGA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,VEGA_GOGGLES};
    };

    // ─── 04 McKendrick ───────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_McKendrick_base : B_recon_exp_F_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "McKendrick";
        identityTypes[] = {"Head_Enoch","LanguageENGB_F",MCKENDRICK_GOGGLES};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,MCKENDRICK_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MCKENDRICK_GOGGLES};
    };

    // ─── 05 Jackson ──────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Jackson_base : TCGM_Stealth_B_CTRG_Soldier_Medic_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "Jackson";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Aviator"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,JACKSON_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
        respawnlinkedItems[] = {DEFAULT_VEST,JACKSON_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Aviator"};
    };

    // ─── 06 Frost ────────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Frost_base : B_Patrol_HeavyGunner_F_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "Frost";
        identityTypes[] = {"Head_NATO","LanguageENGFRE_F","G_SSU_Bandana_Sports_Black"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Camo_Combat_Helmet_MCAM_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Camo_Combat_Helmet_MCAM_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black"};
    };

    // ─── 07 Hawkins ──────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Hawkins_base : B_recon_LAT_F_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "Hawkins";
        identityTypes[] = {"Head_NATO","LanguageENG_F","G_SSU_Bandana_Sports_Black_Beast"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,HAWKINS_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black_Beast"};
        respawnlinkedItems[] = {DEFAULT_VEST,HAWKINS_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Bandana_Sports_Black_Beast"};
    };

    // ─── 08 Sykes ────────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Sykes_base : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        icon = "iconWomanEngineer";
        identity = "Sykes";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female","G_Tactical_Clear"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Tactical_Clear"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Tactical_Clear"};
    };

    // ─── 09 Everett ──────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Everett_base : B_Recon_Sharpshooter_F_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "Everett";
        identityTypes[] = {"Head_Nato","LanguageENGB_F",EVERETT_GOGGLES};
        uniformClass = "U_B_FullGhillie_sard";
        linkedItems[] = {"V_SSU_Carrier_Lite_M81",EVERETT_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,EVERETT_GOGGLES};
        respawnlinkedItems[] = {"V_SSU_Carrier_Lite_M81",EVERETT_HELMET,"ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,EVERETT_GOGGLES};
    };

    // ─── 10 Taylor ───────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Taylor_base : B_recon_LAT_F_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "Taylor";
        identityTypes[] = {"Head_Nato","LanguageENG_F","G_SSU_Balaclava_TI_G_Black"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Balaclava_TI_G_Black"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Boonie_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_SSU_Balaclava_TI_G_Black"};
    };

    // ─── 11 Liu ──────────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Liu_base : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        armor = 6;
        icon = "iconManRecon";
        identity = "Liu";
        identityTypes[] = {"Head_TCGM_Girls_Asian"};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Special_Purpose_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Special_Purpose_Helmet_Black","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch"};
    };

    // ─── 12 Makarova ─────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Makarova_base : TCGM_Stealth_B_CTRG_Soldier_SC_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "Makarova";
        identityTypes[] = {"Head_TCGM_Girls_WhitePony","Head_Female",MAKAROVA_GOGGLES};
        uniformClass = DEFAULT_UNIFORM_GIRLS;
        linkedItems[] = {DEFAULT_VEST,MAKAROVA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MAKAROVA_GOGGLES};
        respawnlinkedItems[] = {DEFAULT_VEST,MAKAROVA_HELMET,"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,MAKAROVA_GOGGLES};
    };

    // ─── 13 Elias ────────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Elias_base : B_soldier_UAV_F_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "Elias";
        identityTypes[] = {"Head_Greek","LanguageENG_F","G_Squares_Tinted"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_SSU_Cap_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Squares_Tinted"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_SSU_Cap_HS_Black","ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Squares_Tinted"};
    };

    // ─── 14 Martinez ─────────────────────────────────────────────────────────────
    class B_PTbskull_Veh_Unit_Martinez_base : B_Recon_F_OCimport_02
    {
        scope = 0;
        author = "RoFz";
        side = 1;
        faction = "bskull_fc_mo";
        identity = "Martinez";
        identityTypes[] = {"Head_TK","LanguageENG_F","G_Spectacles_Tinted"};
        uniformClass = DEFAULT_UNIFORM;
        linkedItems[] = {DEFAULT_VEST,"H_Hat_Safari_sand_F","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Spectacles_Tinted"};
        respawnlinkedItems[] = {DEFAULT_VEST,"H_Hat_Safari_sand_F","ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",DEFAULT_NVG,"G_Spectacles_Tinted"};
    };
