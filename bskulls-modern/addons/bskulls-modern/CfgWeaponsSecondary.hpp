    // LAW #1: Titan Compact
    class launch_I_Titan_short_F;
    // class launch_I_Titan_short_F_OCimport_01 : launch_I_Titan_short_F { scope = 0; class OpticsModes; };
    // class launch_I_Titan_short_F_OCimport_02 : launch_I_Titan_short_F_OCimport_01
    // {
    //
    //     class OpticsModes : OpticsModes
    //     {
    //         class StepScope;
    //     };
    // };
    class B_PTbskull_Wea_law_01_titanat: launch_I_Titan_short_F {
        displayName="Titan+ MPRL Compact (127mm)";
        author = "RoFz";
        scope = 2;



        // maxRange = 1800; // 500
        // maxRangeProbab = 0.7; // 0.04
        // midRange = 750; // 150
        // midRangeProbab = 0.9; // 0.58
        // minRange = 100; // 20
        // minRangeProbab = 0.9; // 0.3

        // distanceZoomMax = 900;
        // distanceZoomMin = 100;

        magazines[] = {"Titan_AT_PLUS","Titan_AP"};

        // inheritsFrom (configfile >> "CfgWeapons" >> "launch_I_Titan_short_F" >> "OpticsModes"); // none
        // inheritsFrom (configfile >> "CfgWeapons" >> "launch_I_Titan_short_F" >> "OpticsModes" >> "StepScope"); // none
        // class OpticsModes : OpticsModes
        // {
        //     class StepScope : StepScope {
        //         distanceZoomMin = 100; // 300
        //         distanceZoomMax = 900; // 300
        //         nFovLimit = 0.08333; // 0.08333
        //         opticsZoomInit = "0.25/7"; // 0.08333
        //         opticsZoomMax = "0.25/7"; // 0.04167
        //         opticsZoomMin = "0.25/35"; // 0.08333
        //     };
        // };

        // inheritsFrom (configfile >> "CfgWeapons" >> "B_PTbskull_Wea_law_01_titanat" >> "Single"); // bin\config.bin/CfgWeapons/launch_Titan_base/Single
        // class Single : Single
        // {
        //     aiDispersionCoefX = 1.4;
        //     aiDispersionCoefY = 1.7;
        //     maxRange = 2000;
        //     maxRangeProbab = 0.8;
        //     midRange = 300;
        //     midRangeProbab = 0.8;
        //     minRange = 70;
        //     minRangeProbab = 0.9;

        // };
        // class TopDown : TopDown
        // {
        //     aiDispersionCoefX = 1.4;
        //     aiDispersionCoefY = 1.7;
        //     maxRange = 2000;
        //     maxRangeProbab = 0.95;
        //     midRange = 500;
        //     midRangeProbab = 0.95;
        //     minRange = 150;
        //     minRangeProbab = 0.9;

        // };

    };

    // Import the inherited fire mode so the new sibling mode can derive from
    // it without redefining the vanilla Titan sound/recoil configuration.
    class B_PTbskull_Wea_law_01_titanat_OCimport_01 : B_PTbskull_Wea_law_01_titanat {
        scope = 0;
        class TopDown;
    };

    // Dedicated carrier launcher. Keeping the magazine well empty prevents
    // Hawkins from falling back to a shallow Direct Titan profile.
    class B_PTbskull_Wea_law_02_titantop: B_PTbskull_Wea_law_01_titanat_OCimport_01 {
        displayName = "HVPS-17 (Archangel)";
        descriptionShort = "Hypersonic Velocity Portable System<br />Dedicated 127 mm soft-launch stand-off top-attack launcher";
        author = "RoFz";
        scope = 2;
        weaponInfoType = "B_PTbskull_RscOptics_Archangel";

        magazines[] = {"Titan_AT_TOP_PLUS"};
        magazineWell[] = {};
        modes[] = {"Overfly"};

        class Overfly : TopDown
        {
            // The Titan optic only maps its TOP/DIR annunciators for the
            // vanilla topDown token. The actual flight-profile pairing still
            // comes from this class name (Overfly).
            textureType = "topDown";
            displayName = "Stand-off Top Attack";
            // AI cadence is only a fallback for the scripted in-flight gate.
            // BI scales aiRateOfFire linearly down at distances shorter than
            // aiRateOfFireDistance, so anchor the full delay at the launcher's
            // minimum range instead of its maximum range.
            // https://community.bohemia.net/wiki/Arma_3:_AI_Config_Reference
            aiRateOfFire = 18;
            aiRateOfFireDistance = 900;
            // The fire-discipline controller repeatedly restores this round
            // reload phase while a carrier is active. Two seconds leaves a
            // safe margin between scheduled refreshes without making a player
            // reload onerous (the scripted hold is AI-only).
            reloadTime = 2;
            minRange = 900;
            minRangeProbab = 0.8;
            midRange = 2400;
            midRangeProbab = 0.95;
            maxRange = 3750;
            maxRangeProbab = 0.9;
        };
    };

    // LAW #3: Titan AA
    // Ammo: Titan_AA
    class launch_B_Titan_olive_F;
    class B_PTbskull_Wea_law_03_titanaa: launch_B_Titan_olive_F {
        displayName="Titan MPRL (127mm)";
        author = "RoFz";
        scope = 2;
    };
