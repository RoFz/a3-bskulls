class CfgAmmo
{

    class B_338LM_Ball;
    class B_338LM_Ball_PLUS : B_338LM_Ball {
        access = 1;
        airFriction = -0.00017; // -0.00045
        caliber = 2.9; // 2.1
        hit = 35; // 19
    };

    // Mortar Ammo
    class Sh_82mm_AMOS;
    class Sh_82mm_AMOS_PLUS : Sh_82mm_AMOS {
        caliber = 10; // 10
        explosionAngle = 45; // 45
        explosionForceCoef = 1.2; // 1.2
        hit = 390; // 350
        indirectHit = 150; // 92
        indirectHitRange = 50; // 50
        typicalSpeed = 700; // 700
    };

    // Artillery HE Ammo
    class Sh_155mm_AMOS;
    class Sh_155mm_AMOS_PLUS : Sh_155mm_AMOS
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        caliber = 10; // 10
        explosionAngle = 45; // 60
        explosionForceCoef = 1.2; // 1
        hit = 640; // 340
        indirectHit = 225; // 125
        indirectHitRange = 70; // 30
        typicalSpeed = 700; // 800
    };

    // Cluster Ammo
    class Mo_cluster_AP;
    class Mo_cluster_AP_PLUS : Mo_cluster_AP
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        // caliber = 34; // 34
        // deflecting = 10; // 10
        // deflectionSlowDown = 0.8; // 0.8
        // explosionAngle = 60; // 60
        // explosionForceCoef = 1; // 1
        // hit = 35; // 35
        // indirectHit = 25; // 25
        // indirectHitRange = 8; // 8
        // penetrationDirDistribution = 0.26; // 0.26
        // submunitionAmmo = ""; // ""

    };

    // Cluster submunition
    class Cluster_155mm_AMOS;
    class Cluster_155mm_AMOS_PLUS : Cluster_155mm_AMOS
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        explosionAngle = 90; // 60
        explosionForceCoef = 1; // 1
        hit = 600; // 300
        indirectHit = 20; // 0
        indirectHitRange = 5; // 8
        typicalSpeed = 700; // 900

        // https://community.bistudio.com/wiki/Arma_3:_Weapon_Config_Guidelines#Ammo_changes_on_fly_and_on_hit
        submunitionAmmo[] = {"Mo_cluster_AP_PLUS",0.93,"Mo_cluster_AP_UXO_deploy",0.07};
        submunitionConeAngle = 10; // 15
        submunitionConeType[] = {"randomcenter",65}; // {"randomcenter",35};

    };

    // Guided Submunition
    class M_Mo_155mm_AT;
    class M_Mo_155mm_AT_PLUS : M_Mo_155mm_AT
    {
        caliber = 2; // 1
        explosionAngle = 360; // 60
        hit = 2200; // 1200
        indirectHit = 240; // 200
        indirectHitRange = 20; // 4
        maxSpeed = 1200; // 500
        thrust = 385; // 350
        thrustTime = 2.5; //2.5
    };

    // Guided Ammo
    class Sh_155mm_AMOS_guided;
    class Sh_155mm_AMOS_guided_PLUS : Sh_155mm_AMOS_guided
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;
        // hit = 300; // 300
        // indirectHitRange = 20; // 8
        // caliber = 1; // 1
        // thrust = 210; // 210
        // thrustTime = 1.5; // 1.5
        // typicalSpeed = 900; // 900
        submunitionAmmo = "M_Mo_155mm_AT_PLUS"; // M_Mo_155mm_AT
        submunitionCount = 1; // 1
    };

    // Laser-guided Submunition
    class M_Mo_155mm_AT_LG;
    class M_Mo_155mm_AT_LG_PLUS : M_Mo_155mm_AT_LG
    {
        caliber = 2; // 1
        explosionAngle = 360; // 60
        hit = 2200; // 1200
        indirectHit = 240; // 200
        indirectHitRange = 20; // 4
        maxSpeed = 1200; // 500
        thrust = 385; // 350
        thrustTime = 2.5; //2.5
    };

    // Laser-guided Ammo
    class Sh_155mm_AMOS_LG;
    class Sh_155mm_AMOS_LG_PLUS : Sh_155mm_AMOS_LG
    {
            author = "RoFz";
            scope = 2;
            scopeCurator = 2;
            access = 1;
            submunitionAmmo = "M_Mo_155mm_AT_LG_PLUS";
            submunitionCount = 1;
    };

    // Mine Submunition #2
    class APERSMine_Range_Ammo; // Submunition
    class APERSMine_Range_Ammo_PLUS : APERSMine_Range_Ammo
    {
        caliber = 1; // 1
        explosionAngle = 60; // 60
        hit = 300; // 300
        indirectHit = 10; // 10
        indirectHitRange = 5; // 5
        mineBoundingDist = 3; // 3
        mineBoundingTime = 3; // 3
        mineInconspicuousness = 50; // 50
        mineTrigger = "RangeTriggerShort";
    };

    // Mine Submunition #1
    class Mo_ClassicMineRange; // Submunition
    class Mo_ClassicMineRange_PLUS : Mo_ClassicMineRange
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        // caliber = 1; // 1
        // explosionAngle = 60; // 60
        // hit = 300; // 300
        // indirectHit = 0; // 0
        // indirectHitRange = 8; // 8
        // mineBoundingDist = 3;
        // mineBoundingTime = 3;
        // mineInconspicuousness = 10; //10
        // mineTrigger = "RangeTrigger";

        submunitionAmmo = "APERSMine_Range_Ammo";
    };

    // Mine Ammo
    class Mine_155mm_AMOS_range; // Ammo
    class Mine_155mm_AMOS_range_PLUS : Mine_155mm_AMOS_range
    {
            author = "RoFz";
            scope = 2;
            scopeCurator = 2;
            access = 1;

            submunitionAmmo = "Mo_ClassicMineRange_PLUS";
            submunitionConeAngle = 15; // 30
            submunitionConeType[] = {"randomcenter",34}; // "randomcenter",24
    };

    // AT Mine Submunition #2
    class ATMine_Range_Ammo; // Submunition
    class ATMine_Range_Ammo_PLUS : ATMine_Range_Ammo
    {
        caliber = 1; // 1
        explosionAngle = 60; // 60
        hit = 2000; // 2000
        indirectHit = 2000; // 2000
        indirectHitRange = 1; // 1
        mineInconspicuousness = 40; // 40
        mineTrigger = "TankTriggerMagnetic";
    };

    // AT Mine Submunition #1
    class Mo_ATMineRange; // Submunition
    class Mo_ATMineRange_PLUS : Mo_ATMineRange
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        // caliber = 1; // 1
        // explosionAngle = 60; // 60
        // hit = 300; // 300
        // indirectHit = 0; // 0
        // indirectHitRange = 8; // 8
        // mineBoundingDist = 3;
        // mineBoundingTime = 3;
        // mineInconspicuousness = 10;
        // mineTrigger = "RangeTrigger";

        submunitionAmmo = "ATMine_Range_Ammo_PLUS";
    };

    // AT Mine Ammo
    class AT_Mine_155mm_AMOS_range; // Ammo
    class AT_Mine_155mm_AMOS_range_PLUS : AT_Mine_155mm_AMOS_range
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        submunitionAmmo = "Mo_ATMineRange_PLUS";
        submunitionConeAngle = 10;
        submunitionConeType[] = {"randomcenter",12};
    };


    // // inheritsFrom (configfile >> "CfgAmmo" >> "MG8_Gau8_30mm"); = bin\config.bin/CfgAmmo/Gatling_30mm_HE_Plane_CAS_01_F
    // // inheritsFrom (configfile >> "CfgAmmo" >> "Gatling_30mm_HE_Plane_CAS_01_F"); = bin\config.bin/CfgAmmo/BulletBase
    // // inheritsFrom (configfile >> "CfgAmmo" >> "MG8_Gau8_30mm" >> "hit"); =
    // class MG8_Gau8_30mm;
    // class MG8_Gau8_30mm_PLUS : MG8_Gau8_30mm
    // {
    //     author = "RoFz";
    //     scope = 2;
    //     scopeCurator = 2;
    //     access = 1;

    //     aiAmmoUsageFlags = "64 + 128 + 256 + 512"; //  RHS: 64 + 128 + 512
    //     caliber = 4.17; // 4.17 RHS: 5
    //     explosive = 0.55; // 0.35 RHS: 0.4
    //     hit = 1200; // 300 RHS: 180
    //     indirectHit = 200; // 100 RHS: 4
    //     // indirectHitRange = 3.5; // 3.5 RHS: 8
    //     // weaponType = "Default"; // RHS: cannon
    //     // typicalSpeed = 960; // RHS: 960
    //     // thrust = 210; // RHS: 210
    //     // thrustTime = 1.5; // RHS: 1.5
    //     // submunitionAmmo = ""; // RHS: {"rhs_ammo_PGU14B_API",0.8,"rhs_ammo_PGU13B_HE",0.2};
    //     // simulation = "shotBullet"; // RHS: "shotSubmunitions";
    //     // simulationStep = 0.05; // RHS: 0.05;
    //     // muzzleEffect = "MG8_fnc_effectFiredGau8"; // RHS: N/A
    // };

    class rhs_ammo_spall;
    class rhs_ammo_spall_PLUS : rhs_ammo_spall
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        caliber = 10;
        deflecting = 90;
        deflectionDirDistribution = 1;
        deflectionSlowDown = 2;
        hit = 20;
        indirectHit = 0;
        indirectHitRange = 0.15;
        timeToLive = 0.5;

    };

    class ammo_Penetrator_Titan_AT;
    class ammo_Penetrator_Titan_AT_PLUS : ammo_Penetrator_Titan_AT
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        caliber = 110; //
        hit = 785; //
        typicalSpeed = 1000; // 1000

        submunitionAmmo = "rhs_ammo_spall";
        submunitionConeType[] = {"randomcenter",50};
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitSpeed = 200;
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;

    };

    class M_Titan_AT;
    class M_Titan_AT_PLUS : M_Titan_AT
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        caliber = 1; // 1
        hit = 155; // 95
        indirectHit = 30; // 20
        indirectHitRange = 3.3; // 3.3
        maxSpeed = 180; // 180

        submunitionAmmo = "ammo_Penetrator_Titan_AT_PLUS";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitSpeed = 1500; // 1000
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionParentSpeedCoef = 0;

    };



};

// MAGAZINES //
class CfgMagazines {

    class 5Rnd_APDS_338LM_Magazine;
    class 5Rnd_APDS_338LM_Magazine_PLUS : 5Rnd_APDS_338LM_Magazine {
        author = "RoFz";
        scope = 2;
        access = 1;
        descriptionShort = "APDS .338 LM 5Rnd Mag+";
        displayName = "APDS .338 LM 5Rnd Mag+";
        initSpeed = 1240; // 1120
        ammo = "B_338LM_Ball_PLUS";
    };

    class 32Rnd_155mm_Mo_shells;
    class 64Rnd_155mm_Plus_Mo_shells : 32Rnd_155mm_Mo_shells
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;
        count = 64; // 32
        // initSpeed = 910; // 810 - changes artillery reach radius
        ammo = "Sh_155mm_AMOS_PLUS";
    }

    class 2Rnd_155mm_Mo_Cluster;
    class 4Rnd_155mm_Plus_Mo_Cluster : 2Rnd_155mm_Mo_Cluster
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;
        count = 4; // 2
        // initSpeed = 910; // 810 - changes artillery reach radius
        ammo = "Cluster_155mm_AMOS_PLUS";
    };

    class 2Rnd_155mm_Mo_guided;
    class 8Rnd_155mm_Plus_Mo_guided : 2Rnd_155mm_Mo_guided
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;
        count = 8;
        ammo = "Sh_155mm_AMOS_guided_PLUS";
    };

    class 2Rnd_155mm_Mo_LG;
    class 8Rnd_155mm_Plus_Mo_LG : 2Rnd_155mm_Mo_LG
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;
        count = 8;
        ammo = "Sh_155mm_AMOS_LG_PLUS";
    };

    class 6Rnd_155mm_Mo_mine;
    class 12Rnd_155mm_Plus_Mo_mine : 6Rnd_155mm_Mo_mine
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;
        count = 12;
        ammo = "Mine_155mm_AMOS_range_PLUS";
    };

    class 6Rnd_155mm_Mo_AT_mine;
    class 12Rnd_155mm_Plus_Mo_AT_mine : 6Rnd_155mm_Mo_AT_mine
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;
        count = 12;
        ammo = "AT_Mine_155mm_AMOS_range_PLUS";
    };

    // magazines[] = {"MG8_1174Rnd_Gau8_30mm","Laserbatteries","240Rnd_CMFlare_Chaff_Magazine"};
    class MG8_1174Rnd_Gau8_30mm;
    class MG8_1174Rnd_Gau8_30mm_PLUS : MG8_1174Rnd_Gau8_30mm
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        // inheritsFrom (configfile >> "CfgMagazines" >> "MG8_1174Rnd_Gau8_30mm" >> "ammo"); = none
        ammo = "MG8_Gau8_30mm_PLUS";
    };

    class Titan_AT;
    class Titan_AT_PLUS : Titan_AT
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        displayName="Titan+ AT Missile";

        // inheritsFrom (configfile >> "CfgMagazines" >> "MG8_1174Rnd_Gau8_30mm" >> "ammo"); = none
        ammo = "M_Titan_AT_PLUS";
    };

    class 8Rnd_82mm_Mo_shells;
    class 80Rnd_82mm_Mo_shells_PLUS : 8Rnd_82mm_Mo_shells
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        displayName = "HE Mortar Shells Plus";
        displayNameMFDFormat = "HE+";
        displayNameShort = "HE+";
        count = 80; // 8
        ammo = "Sh_82mm_AMOS_PLUS"; // Sh_82mm_AMOS
    }

}
