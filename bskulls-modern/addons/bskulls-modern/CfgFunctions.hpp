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
            class unitHit { file = "\bskulls\addons\bskulls-modern\scripts\hit.sqf"; };
            class unitHitResponse {};
        };
        class ai {
            file = "\bskulls\addons\bskulls-modern\scripts";
            class initMineStanceRecovery {};
        };
        class weapons {
            file = "\bskulls\addons\bskulls-modern\scripts";
            class titanTopAttackAmmoHit {};
            class titanTopAttackDebugAutoStart { postInit = 1; };
            class titanTopAttackDebugReport {};
            class titanTopAttackFired {};
            class titanTopAttackInitOrderDebug {};
            class titanTopAttackInitUnitDebug {};
            class titanTopAttackLog {};
            class titanTopAttackOpticLoad {};
            class titanTopAttackProjectileInit {};
            class titanTopAttackSetDebug {};
            class titanTopAttackSubmunitionCreated {};
            class titanTopAttackTerminalVisual {};
            class titanTopAttackTrace {};
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

    // Switchblade Loitering Munition compatibility. CfgPatches loads the
    // switchblade addon first, so this function-level file overrides only its
    // deployment-action wrapper while preserving the rest of the SWB API.
    class SWB {
        class util {
            class addActionByLoadout {
                file = "\bskulls\addons\bskulls-modern\scripts\fn_switchbladeAddActionByLoadout.sqf";
            };
        };
    };
};
