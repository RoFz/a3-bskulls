// CBA object events belong at config root; InitPost receives [vehicle].
// https://github.com/CBATeam/CBA_A3/wiki/Extended-Event-Handlers-(new)
class Extended_InitPost_EventHandlers {
    class B_PTbskull_Veh_Plane_blackops_01_nodao {
        class bskulls_noDao {
            init = "params ['_vehicle']; if (local _vehicle) then {[_vehicle] call bskulls_fnc_daoExcludeVehicle;};";
        };
    };
    class B_PTbskull_Veh_Helo_blackops_01_nodao {
        class bskulls_noDao {
            init = "params ['_vehicle']; if (local _vehicle) then {[_vehicle] call bskulls_fnc_daoExcludeVehicle; [_vehicle] call bskulls_fnc_initHuronGunshipEngage;};";
        };
    };
    class B_PTbskull_Veh_Helo_blackops_02_nodao {
        class bskulls_noDao {
            init = "params ['_vehicle']; if (local _vehicle) then {[_vehicle] call bskulls_fnc_daoExcludeVehicle;};";
        };
    };
    class B_PTbskull_Veh_Helo_blackops_03_nodao {
        class bskulls_noDao {
            init = "params ['_vehicle']; if (local _vehicle) then {[_vehicle] call bskulls_fnc_daoExcludeVehicle;};";
        };
    };
    class B_PTbskull_Veh_Helo_blackops_04_nodao {
        class bskulls_noDao {
            init = "params ['_vehicle']; if (local _vehicle) then {[_vehicle] call bskulls_fnc_daoExcludeVehicle;};";
        };
    };
    class B_PTbskull_Veh_Drone_blackops_01_nodao {
        class bskulls_noDao {
            init = "params ['_vehicle']; if (local _vehicle) then {[_vehicle] call bskulls_fnc_daoExcludeVehicle;};";
        };
    };
};

// Hawkins's concrete variants inherit this handler from the scope-0 base.
// FiredBIS preserves the engine Fired arguments, including the projectile.
class Extended_FiredBIS_EventHandlers {
    class B_PTbskull_Veh_Unit_Hawkins_base {
        class bskulls_aiDapsLauncherDiscipline {
            firedBIS = "_this call bskulls_fnc_aiDapsLauncherFired;";
        };
    };
};

// Handle both locality loss (stop) and gain (start) for the DRO Huron only.
// XEH adds this alongside the inherited countermeasure Local handler.
class Extended_Local_EventHandlers {
    class B_PTbskull_Veh_Helo_blackops_01_nodao {
        class bskulls_huronGunship {
            local = "_this call bskulls_fnc_initHuronGunshipEngage;";
        };
    };
};
