// CfgFunctions.hpp — Black Skulls modern scripted functions
// Registration: community.bistudio.com/wiki/Arma_3:_CfgFunctions

class CfgFunctions {
    class bskulls {
        tag = "bskulls";
        class identity {
            file = "\bskulls\addons\bskulls-modern\scripts";
            class applyOperatorIdentity {};
            class applyUnitRank {};
        };
        class dao {
            file = "\bskulls\addons\bskulls-modern\scripts";
            class daoExcludeVehicle {};
        };
        class compatibility {
            file = "\bskulls\addons\bskulls-modern\scripts";
            class registerDapsTypes { postInit = 1; };
        };
        class wounded {
            file = "\bskulls\addons\bskulls-modern\scripts";
            class unitHitResponse {};
        };
        class ai {
            file = "\bskulls\addons\bskulls-modern\scripts";
            class initMineStanceRecovery {};
        };
        class aircraft {
            file = "\bskulls\addons\bskulls-modern\scripts";
            class formatKillSource {};
            class reportAirDestroyed {};
            class initHuronGunshipEngage {};
            class initAutoCountermeasures {};
            class autoCmOnIncomingMissile {};
            class initPawneeCombat {};
            class initRadarRotation {};
            class reportPawneeMissilesDepleted {};
        };
    };
};
