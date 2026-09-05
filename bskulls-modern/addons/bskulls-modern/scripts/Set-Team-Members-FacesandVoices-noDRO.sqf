/*
 * Manual, non-DRO setup entry point.
 *
 * The DAO hangar injection mirrors the maintained DRO injector: wait with a
 * timeout, reject non-ILS DAO positions, use helicopters where a jet runway is
 * unavailable, and add the selected combat and transport aircraft together.
 */

PAR_revive = 1;
PAR_ai_limit = 8;
PAR_only_ai_revive = true;

[] spawn {
    {
        _x enableIRLasers true;
        _x setSkill 1;
        _x enableFatigue false;
        _x setCombatBehaviour "STEALTH";
        _x setUnitCombatMode "BLUE";
        if ("insignia" in selectionNames _x) then {
            [_x, "Black_Skulls"] call BIS_fnc_setUnitInsignia;
        };
    } forEach (units group player);

    player setName ["Stephen Falken", "Stephen", "Falken"];
    player setNameSound "Viper";
    player setSpeaker "male03eng";
    player setUnitTrait ["Medic", false];
    player setUnitTrait ["Engineer", true];
    player setUnitTrait ["ExplosiveSpecialist", true];

    if (missionNamespace getVariable ["DAOAircraftAlreadySpawned", false]) exitWith {
        systemChat "DAO aircraft already spawned!";
    };

    private _timeout = time + 300;
    waitUntil {
        sleep 2;
        (!isNil "daoReady" && {daoReady}) || {time > _timeout}
    };
    if (isNil "daoReady" || {!daoReady}) exitWith {
        diag_log "BS manual inject: daoReady timeout — skip AddToVAM";
        systemChat "BS inject: DAO not ready — no hangar air.";
    };
    if (isNil "dao_fnc_AddToVAM") exitWith {
        diag_log "BS manual inject: dao_fnc_AddToVAM missing";
        systemChat "BS inject: dao_fnc_AddToVAM missing.";
    };
    if (isNil "daoairportpositionlist" || {daoairportpositionlist isEqualTo []}) exitWith {
        diag_log "BS manual inject: no daoairportpositionlist";
        systemChat "BS inject: no DAO airfields — no hangar air.";
    };

    private _fnc_realIlsInfo = {
        params ["_idx"];
        if (isNil "dao_fnc_GetAirportInfo") exitWith { [] };
        private _info = _idx call dao_fnc_GetAirportInfo;
        if ((count _info) != 5) exitWith { [] };
        if (_info select 4) exitWith { [] };
        _info
    };

    // As in DRO, keep hangar combat aircraft away from the active player area.
    private _bestIdx = -1;
    private _bestDistance = -1;
    {
        if ((_x isEqualType []) && {(count _x) >= 2}) then {
            private _info = [_forEachIndex] call _fnc_realIlsInfo;
            if (_info isNotEqualTo []) then {
                private _distance = player distance2D _x;
                if (_distance > _bestDistance) then {
                    _bestDistance = _distance;
                    _bestIdx = _forEachIndex;
                };
            };
        };
    } forEach daoairportpositionlist;

    private _weferlingen = ["weferlingen", worldName] call BIS_fnc_inString;
    private _allowJet = _bestIdx >= 0 && {!_weferlingen};
    private _airfieldIdx = _bestIdx max 0;

    private _combatCandidates = if (_allowJet) then {
        [
            "B_PTbskull_Veh_Plane_blackops_01",
            "B_PTbskull_Veh_Helo_blackops_03",
            "B_PTbskull_Veh_Helo_blackops_04"
        ]
    } else {
        [
            "B_PTbskull_Veh_Helo_blackops_03",
            "B_PTbskull_Veh_Helo_blackops_04"
        ]
    };
    private _transportCandidates = [
        "B_PTbskull_Veh_Helo_blackops_01",
        "B_PTbskull_Veh_Helo_blackops_02"
    ];
    private _combat = selectRandom _combatCandidates;
    private _transport = selectRandom _transportCandidates;

    [_airfieldIdx, west, [_combat, _transport]] call dao_fnc_AddToVAM;
    missionNamespace setVariable ["DAOAircraftAlreadySpawned", true, true];

    private _combatName = getText (configFile >> "CfgVehicles" >> _combat >> "displayName");
    private _transportName = getText (configFile >> "CfgVehicles" >> _transport >> "displayName");
    systemChat format [
        "BS inject: %1 and %2 added to DAO airfield %3.",
        _combatName,
        _transportName,
        _airfieldIdx
    ];
    diag_log format [
        "BS manual inject: VAM [%1, %2] @%3 allowJet=%4",
        _combat,
        _transport,
        _airfieldIdx,
        _allowJet
    ];
};
