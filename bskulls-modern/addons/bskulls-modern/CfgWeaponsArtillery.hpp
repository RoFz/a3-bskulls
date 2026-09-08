    // Artillery #1: M4 (Howitzer 155mm)
    class CannonCore;
    class mortar_155mm_AMOS : CannonCore
    {
        class Single1;
        class Single2;
        class Single3;
        class Single4;
        class Single5;
        class Burst1;
        class Burst2;
        class Burst3;
        class Burst4;
        class Burst5;
    };
    class B_PTbskull_Wea_art_gun_01: mortar_155mm_AMOS
    {
        // magazines[] = {"32Rnd_155mm_Mo_shells","32Rnd_155mm_Mo_shells_O","6Rnd_155mm_Mo_smoke","6Rnd_155mm_Mo_smoke_O","2Rnd_155mm_Mo_guided","4Rnd_155mm_Mo_guided","4Rnd_155mm_Mo_guided_O","2Rnd_155mm_Mo_LG","4Rnd_155mm_Mo_LG","4Rnd_155mm_Mo_LG_O","6Rnd_155mm_Mo_mine","6Rnd_155mm_Mo_mine_O","2Rnd_155mm_Mo_Cluster","2Rnd_155mm_Mo_Cluster_O","6Rnd_155mm_Mo_AT_mine","6Rnd_155mm_Mo_AT_mine_O"};
        magazines[] = {"64Rnd_155mm_Plus_Mo_shells","6Rnd_155mm_Mo_smoke","8Rnd_155mm_Plus_Mo_guided","12Rnd_155mm_Plus_Mo_mine","4Rnd_155mm_Plus_Mo_Cluster","8Rnd_155mm_Plus_Mo_LG","12Rnd_155mm_Plus_Mo_AT_mine"};
        // Keep every charge's accuracy override on our weapon. Inherit each
        // vanilla mode separately to preserve its charge, range and reload settings.
        class Single1: Single1 { artilleryDispersion = 0.1; };
        class Single2: Single2 { artilleryDispersion = 0.1; };
        class Single3: Single3 { artilleryDispersion = 0.1; };
        class Single4: Single4 { artilleryDispersion = 0.1; };
        class Single5: Single5 { artilleryDispersion = 0.1; };
        class Burst1: Burst1 { artilleryDispersion = 0.1; };
        class Burst2: Burst2 { artilleryDispersion = 0.1; };
        class Burst3: Burst3 { artilleryDispersion = 0.1; };
        class Burst4: Burst4 { artilleryDispersion = 0.1; };
        class Burst5: Burst5 { artilleryDispersion = 0.1; };
    };

    // Artillery #2: Mk6 82mm — own weapon (ACE-style); do not patch vanilla mortar_82mm
    class mortar_82mm: CannonCore {
        class Single1;
        class Burst1;
    };
    class B_PTbskull_Wea_art_mortar_01: mortar_82mm {
        magazines[] += {"80Rnd_82mm_Mo_shells_PLUS"};
        class Single1: Single1 {
            artilleryDispersion=0.9;
        };
        class Burst1: Burst1 {
            artilleryDispersion=1.2;
        };
    };
