class CfgAmmo
{

    class B_338LM_Ball;
    class B_338LM_Ball_PLUS : B_338LM_Ball {
        access = 1;
        airFriction = -0.00017; // -0.00045
        caliber = 2.9; // 2.1
        hit = 35; // 19
    };

    class B_127x54_Ball;
    class B_127x54_Ball_PLUS : B_127x54_Ball {
        access = 1;
        airFriction = -0.00069; // -0.0014
        caliber = 4.6; // 4.6
        hit = 43; // 20
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

        submunitionAmmo = "APERSMine_Range_Ammo_PLUS";
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

        submunitionAmmo = "rhs_ammo_spall_PLUS";
        submunitionConeType[] = {"randomcenter",50};
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitSpeed = 200;
        submunitionInitialOffset[] = {0,0,-0.4};
        submunitionParentSpeedCoef = 0;

    };

    // High-speed terminal stage for the stand-off top-attack Titan. Vanilla
    // penetrators live for only 0.2 seconds; this one must cross a 310 m
    // vertical stand-off before impact. The production appearance uses a pale
    // Missile4-pattern trail plus a conventional tracer.
    class ammo_Penetrator_Titan_AT_TOP_PLUS : ammo_Penetrator_Titan_AT_PLUS
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        typicalSpeed = 1500;
        timeToLive = 1;
        simulationStep = 0.002;
        airFriction = 0;

        // Vanilla HEAT penetrators use an empty model. A stock-size tracer
        // makes this brief terminal stage readable without an oversized
        // projectile model.
        model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
        tracerScale = 1;
        tracerStartTime = 0;
        tracerEndTime = 1;
        nvgOnly = 0;
        // The explicit local source is the sole trail emitter. An engine-level
        // effectFly would remain centred on the physical projectile and expose
        // the otherwise cosmetic lateral bow as a second, straight trail.
        effectFly = "";
        bskulls_terminalVisualProfile = "Archangel T-HEAT";
        bskulls_terminalVisualCloudlet = "B_PTbskull_ArchangelMissile4Visible";
        bskulls_terminalVisualDropInterval = 0.002;
        bskulls_terminalVisualLinger = 3.8;

        // Cosmetic only: fn_titanTopAttackTerminalVisual offsets the local
        // particle emitter, never the projectile. The sine bow begins and ends
        // at zero so the trail still joins separation and impact. A randomized
        // second harmonic prevents every shot from describing the same arc.
        bskulls_terminalVisualCurveAmplitudeMin = 2.5;
        bskulls_terminalVisualCurveAmplitudeMax = 5.5;
        bskulls_terminalVisualCurveSecondaryMax = 0.2;

        // Per-shot terminal guidance reliability. Successful shots retain the
        // engine-generated target vector unchanged. A failed roll redirects
        // the real penetrator laterally beyond the target's roof and blast
        // radius, producing a visible near miss instead of silently deleting
        // damage or manufacturing a DAPS interception.
        bskulls_terminalAccuracyProbability = 0.95;
        bskulls_terminalMissOffsetMin = 8;
        bskulls_terminalMissOffsetMax = 14;

        // Make the inherited internal-spall stage deterministic on impact.
        triggerOnImpact = 1;
        deleteParentWhenTriggered = 0;

        class EventHandlers
        {
            init = "_this call bskulls_fnc_titanTopAttackProjectileInit;";
            ammoHit = "_this call bskulls_fnc_titanTopAttackAmmoHit;";
        };
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

    // The guided carrier first performs a soft ejection, ignites its inherited
    // Titan flight motor, and then separates just outside the 300 m DAPS
    // detection envelope. A 900 m minimum launch range makes the inbound
    // terminal leg about 52 degrees or steeper against DAPS's default
    // 45-degree limit. This uses BI's documented delayed missile ignition plus
    // Overfly + SubmunitionTargetDirection patterns.
    class M_Titan_AT_TOP_PLUS : M_Titan_AT_PLUS
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        // The carrier is only a delivery stage. All damage belongs to the
        // terminal penetrator, including the on-impact fallback path.
        hit = 0;
        indirectHit = 0;
        indirectHitRange = 0;
        explosive = 0;

        // Stage 1: the magazine ejects the carrier at 20 m/s. During this
        // delay, effectsMissileInit renders a compact launch-motor smoke trail.
        // At approximately seven metres the inherited Titan motor and its
        // normal effectsMissile trail take over for the guided ascent.
        // https://community.bistudio.com/wiki/CfgAmmo
        initTime = 0.35;
        effectsMissileInit = "B_PTbskull_ArchangelSoftLaunchEffect";
        bskulls_softLaunchSafeDistance = 25;

        // Stage 3: create the existing terminal penetrator at the overfly
        // separation point. An early impact can also request a submunition,
        // but the SubmunitionCreated handler suppresses it inside the safe
        // distance above.
        submunitionAmmo = "ammo_Penetrator_Titan_AT_TOP_PLUS";
        submunitionCount = 1;
        submunitionDirectionType = "SubmunitionTargetDirection";
        submunitionInitSpeed = 1500;
        submunitionParentSpeedCoef = 0;
        submunitionInitialOffset[] = {0,0,0};
        triggerDistance = 310;
        triggerOnImpact = 1;
        deleteParentWhenTriggered = 1;

        flightProfiles[] = {"Overfly"};
        class Overfly
        {
            overflyElevation = 310;
        };

        manualControl = 0;
        airLock = 0;
        allowAgainstInfantry = 0;
        missileLockMinDistance = 900;
        missileLockMaxDistance = 2000;
        timeToLive = 30;

        class EventHandlers
        {
            init = "_this call bskulls_fnc_titanTopAttackProjectileInit;";
            fired = "_this call bskulls_fnc_titanTopAttackFired;";
            ammoHit = "_this call bskulls_fnc_titanTopAttackAmmoHit;";
        };
    };

};

// MAGAZINES //
class CfgMagazines {

// 10Rnd_127x54_Mag

    class 10Rnd_127x54_Mag;
    class 10Rnd_127x54_Mag_PLUS : 10Rnd_127x54_Mag {
        author = "RoFz";
        scope = 2;
        access = 1;
        descriptionShort = "Caliber: 12.7x54 mm<br />Rounds: 10<br />Used in: ASP-1 Kir<br />Plus version";
        displayName = "12.7 mm 10Rnd Mag+";
        initSpeed = 320; // 290
        ammo = "B_127x54_Ball_PLUS"; // B_127x54_Ball
    };


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
    };

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

    class Titan_AT;
    class Titan_AT_PLUS : Titan_AT
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        displayName="Titan+ AT Missile";

        ammo = "M_Titan_AT_PLUS";
    };

    class Titan_AT_TOP_PLUS : Titan_AT_PLUS
    {
        author = "RoFz";
        scope = 2;
        scopeCurator = 2;
        access = 1;

        displayName = "Archangel T-HEAT";
        displayNameShort = "T-HEAT";
        descriptionShort = "HVPS-17 soft-launch tandem HEAT round with a stand-off top-attack carrier, high-velocity terminal penetrator, and 95% nominal guidance reliability";
        initSpeed = 20;
        ammo = "M_Titan_AT_TOP_PLUS";
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
    };

};
