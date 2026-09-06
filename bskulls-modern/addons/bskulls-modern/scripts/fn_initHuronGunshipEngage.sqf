/*
 * bskulls_fnc_initHuronGunshipEngage
 *
 * DRO transport orders can leave the whole flight in BLUE/CARELESS. Keep only
 * the Huron's two minigun operators weapons-free and alert without assigning
 * targets, moving the aircraft, or interfering with pilot orders.
 *
 * The DAO-managed Huron must not call this function: DAO's tablet owns its ROE.
 */

params [["_vehicle", objNull, [objNull]]];

if (isNull _vehicle) exitWith { false };

private _oldHandle = _vehicle getVariable ["BS_huronGunshipHandle", scriptNull];

// The Local XEH also calls us on locality loss. Stop the old worker immediately
// so a rapid return cannot mistake an exiting worker for a running controller.
if (!local _vehicle || {!alive _vehicle}) exitWith {
    if (!scriptDone _oldHandle) then {
        terminate _oldHandle;
    };
    _vehicle setVariable ["BS_huronGunshipHandle", scriptNull, false];
    false
};

if (!scriptDone _oldHandle) exitWith { true };

private _handle = [_vehicle] spawn {
    params ["_veh"];

    private _doorGunTurrets = [[1], [2]];
    private _reportedGunners = [];

    while {alive _veh && {local _veh}} do {
        {
            _x params ["_gunner", "", "", "_turretPath"];
            if (
                !isNull _gunner
                && {alive _gunner}
                && {!isPlayer _gunner}
                && {_turretPath in _doorGunTurrets}
            ) then {
                {
                    _gunner enableAI _x;
                } forEach ["TARGET", "AUTOTARGET", "WEAPONAIM", "AUTOCOMBAT", "FIREWEAPON"];

                // Individual settings override DAO's transport-wide
                // BLUE/CARELESS state without changing the pilot's orders.
                _gunner setUnitCombatMode "YELLOW";
                if ((combatBehaviour _gunner) in ["CARELESS", "SAFE"]) then {
                    _gunner setCombatBehaviour "AWARE";
                };

                private _gunnerId = netId _gunner;
                if (_gunnerId isEqualTo "") then { _gunnerId = str _gunner; };
                if !(_gunnerId in _reportedGunners) then {
                    _reportedGunners pushBack _gunnerId;
                    diag_log format [
                        "BSkulls Huron: door gunner enabled veh=%1 gunner=%2 turret=%3 weapons=%4 magazines=%5 unitCombatMode=%6 combatBehaviour=%7",
                        _veh,
                        _gunner,
                        _turretPath,
                        _veh weaponsTurret _turretPath,
                        _veh magazinesTurret _turretPath,
                        unitCombatMode _gunner,
                        combatBehaviour _gunner
                    ];
                };
            };
        } forEach (fullCrew _veh);

        sleep 2;
    };

    if (!isNull _veh) then {
        _veh setVariable ["BS_huronGunshipHandle", scriptNull, false];
    };
};

_vehicle setVariable ["BS_huronGunshipHandle", _handle, false];
true
