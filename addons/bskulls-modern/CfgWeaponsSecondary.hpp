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
        //         distanceZoomMin = 900; // 300
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

    // LAW #2: M72A3
    // Ammo: gm_1Rnd_66mm_heat_m72a3
    class gm_m72a3_oli;
    class B_PTbskull_Wea_law_02_m72: gm_m72a3_oli {
        displayName="M72A3 LAW (66mm)";
        author = "RoFz";
        scope = 2;
    };

    // LAW #3: Titan AA
    // Ammo: Titan_AA
    class launch_B_Titan_olive_F;
    class B_PTbskull_Wea_law_03_titanaa: launch_B_Titan_olive_F {
        displayName="Titan MPRL (127mm)";
        author = "RoFz";
        scope = 2;
    };

