// FOX init script

private _UnitName = "Fox";
private _VehVarName = "_BSkullFox";
private _UnitFullName = "Amanda Fox";
private _UnitFirstName = "Amanda";
private _UnitLastName = "Fox";
private _UnitNameSound = "Fox";
private _UnitVoice = "rhs_Female01ENG";
private _UnitVoicePitch = 0.95;
private _UnitFace = "TCGM_Fem_Stone";
private _UnitTraits = ["Medic"];
private _UnitTeam = "BLUE";
private _UnitCombatBeh = "STEALTH";
private _UnitCombatMod = "GREEN";

_unit = _this select 0;

_onSpawn = {
    params [
        "_u",
        "_UnitFullName",
        "_UnitFirstName",
        "_UnitLastName",
        "_UnitNameSound",
        "_UnitVoice",
        "_UnitVoicePitch",
        "_UnitFace",
        "_UnitTeam",
        "_UnitTraits",
        "_UnitCombatBeh",
        "_UnitCombatMod",
        "_UnitName",
        "_VehVarName",
        "_DRO_VehVarName"
    ];
    _u setVariable ["BIS_enableRandomization", false];
    _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
    _u setNameSound _UnitNameSound;
    _u setSpeaker _UnitVoice;
    _u setPitch _UnitVoicePitch;
    _u setFace _UnitFace;
    _u assignTeam _UnitTeam;
    { _u setUnitTrait [_x, true]; } forEach _UnitTraits;
    [_u, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
    _u enableIRLasers true;
    _u setSkill 1;
    _u enableFatigue false;
    _u setCombatBehaviour _UnitCombatBeh;
    _u setUnitCombatMode _UnitCombatMod;
//     if ((isNil "lobbycomplete") || (isNil "playersready")) then {
//         systemChat format ["%1: no DRO detected.", _UnitName];
//         // if (isNil (vehicleVarName _u)) then {
//         //     sleep 5;
//         //     systemChat format ["%1: vehicleVarName is Nil after 5 secs. Setting it to %2", _UnitName, _VehVarName];
//         //     // this must be defined only when unit is in players group - but does it really matter outside of DRO?
//         //     // missionNamespace setVariable [_VehVarName, _this, true];
//         //     _u setVehicleVarName _VehVarName;
//         // } else {
//         //     systemChat format ["%1: vehicleVarName is already set to %2", _UnitName, (vehicleVarName _u)];
//         // };
//     } else {
//         systemChat format ["%1: DRO detected!", _UnitName];
//         // if (isNil (vehicleVarName _u)) then {
//         //     sleep 5;
//         //     // this must be defined only when unit is in players group
//         //     systemChat format ["%1: DRO vehicleVarName is Nil after 5 secs. Setting it to %2", _UnitName, _VehVarName];
//         //     // this must be defined only when unit is in players group
//         //     // missionNamespace setVariable [_VehVarName, _this, true];
//         //     // "_VehVarName" setVariable [_VehVarName, _this, true];
//         // } else {
//         //     systemChat format ["%1: DRO vehicleVarName is already set to %2", _UnitName, (vehicleVarName _u)];
//         // };

//         waitUntil { sleep 3; missionNamespace getVariable ["lobbycomplete", 0] == 1 && missionNamespace getVariable ["playersready", 0] == 1 };
//         // systemChat format [ "%1: lobbycomplete and playersready are set.", _UnitName ];

//         private _playerGrp = group player;
//         // systemChat format ["%1: _playerGrp = %2", _UnitName, _playerGrp];
//         private _objNetId = _u call BIS_fnc_netId;
//         // systemChat format ["%1: _objNetId = %2", _UnitName, _objNetId];
//         private _objId = _objNetId call BIS_fnc_objectFromNetId;
//         // systemChat format ["%1: _objId = %2", _UnitName, _objId];

//         // not working - never executes for actual team member
//         systemChat format ["%1: _objId = %2, vehicleVarName = %3", _UnitName, _objId, (vehicleVarName _objId)];
//         if (isNil (vehicleVarName _objId)) then {
//             systemChat format ["%1: vehicleVarName is Nil", _UnitName];
//         } else {
//             systemChat format ["%1: vehicleVarName is not Nil, set to %2", _UnitName, (vehicleVarName _objId)];
//         };

//         // Todo: check group player netid then compare it to unit's group netid

//         // systemChat format ["%1: group _objId = %2", _UnitName, group _objId]; // B Delta

//         _time = time;
//         waitUntil { sleep 1; group _objId == _playerGrp || time - _time > 60};
//         // systemChat format ["%1: _unitGrp = %2, _playerGrp = %3", _UnitName, group _objId, _playerGrp];
//         if (group _objId == _playerGrp) then { // not working - never true
//             systemChat format ["%1 (%2): in player group (%3), adding reset action...", _UnitName, vehicleVarName _objId, _playerGrp];
//             // _actionTitle = format ["Reset Id %1", _UnitName];
//             // _actionID = player addAction [_actionTitle, "\bskulls-modern\scripts\reset_unit.sqf", [_UnitName, _UnitFullName, _UnitFirstName, _UnitLastName, _UnitNameSound, _UnitVoice, _UnitVoicePitch, _UnitFace, _UnitTeam, _UnitTraits], 6, false, true];
//         } else {
//             systemChat format ["%1 (%2): NOT in player group, reset action not added.", _UnitName, vehicleVarName _objId];
        // };

    };

//     // private _varName = vehicleVarName _u;
//     // systemChat format ["%1: _varName = %2", _UnitName, _varName];

// };
// [
//     _this,
//     _UnitFullName,
//     _UnitFirstName,
//     _UnitLastName,
//     _UnitNameSound,
//     _UnitVoice,
//     _UnitVoicePitch,
//     _UnitFace,
//     _UnitTeam,
//     _UnitTraits,
//     _UnitCombatBeh,
//     _UnitCombatMod,
//     _UnitName,
//     _VehVarName
// ] spawn _onSpawn;




// if ((isNil "lobbycomplete") || (isNil "playersready")) then
// {
//     systemChat format ["%1: no DRO detected or DRO mission not started yet.", _UnitName];
//     if (isNil (vehicleVarName _this)) then {
//          systemChat format ["%1: vehicleVarName is Nil. Waiting for it...", _UnitName];
//         waitUntil { sleep 1; not isNil (vehicleVarName _this) }; // endless loop ?
//         systemChat format ["%1: vehicleVarName is still Nil. Setting it to %2", _UnitName, _VehVarName];
//         _this setVehicleVarName _VehVarName;
//         systemChat format ["%1: vehicleVarName has been set to %2", _UnitName, (vehicleVarName _this)];
//     } else {
//         systemChat format ["%1: vehicleVarName is not Nil, set to %2", _UnitName, (vehicleVarName _this)];
//     };
// } else {
//     systemChat format ["%1: DRO detected!", _UnitName];
//     if (isNil (vehicleVarName _this)) then {
//          systemChat format ["%1: DRO vehicleVarName is Nil. Waiting for it...", _UnitName];
//         waitUntil { sleep 1; not isNil (vehicleVarName _this) }; // endless loop ?
//         systemChat format ["%1: DRO vehicleVarName set to %2", _UnitName, (vehicleVarName _this)];
//     } else {
//         systemChat format ["%1: DRO vehicleVarName is not Nil, set to %2", _UnitName, (vehicleVarName _this)];
//     };
// };



if ((isNil "lobbycomplete") || (isNil "playersready")) then
{
    systemChat format ["%1: no DRO detected.", _UnitName];
} else {
    // systemChat format ["%1: DRO detected!", _UnitName];
    private _objNetId = _unit call BIS_fnc_netId;
    private _objId = _objNetId call BIS_fnc_objectFromNetId;
    // systemChat format ["%1: _objNetId = %2", _UnitName, _objNetId];
    // systemChat format ["%1: _objId = %2",_UnitName, _objId];
    // systemChat format ["%1: vehicleVarName = %2", _UnitName, vehicleVarName _objId];

        // _time = time;
        // waitUntil { sleep 1; not isNil  || time - _time > 60};

//         private _playerGrp = group player;
//         // systemChat format ["%1: _playerGrp = %2", _UnitName, _playerGrp];
//         private _objNetId = _u call BIS_fnc_netId;
//         // systemChat format ["%1: _objNetId = %2", _UnitName, _objNetId];
//         private _objId = _objNetId call BIS_fnc_objectFromNetId;
//         // systemChat format ["%1: _objId = %2", _UnitName, _objId];

//         // not working - never executes for actual team member
//         systemChat format ["%1: _objId = %2, vehicleVarName = %3", _UnitName, _objId, (vehicleVarName _objId)];
//         if (isNil (vehicleVarName _objId)) then {
//             systemChat format ["%1: vehicleVarName is Nil", _UnitName];
//         } else {
//             systemChat format ["%1: vehicleVarName is not Nil, set to %2", _UnitName, (vehicleVarName _objId)];
//         };

//         // Todo: check group player netid then compare it to unit's group netid

//         // systemChat format ["%1: group _objId = %2", _UnitName, group _objId]; // B Delta

//         _time = time;
//         waitUntil { sleep 1; group _objId == _playerGrp || time - _time > 60};


    if (!(isNil "u2")) then
    {
        u2 setVariable ["BIS_enableRandomization", false];
        u2 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u2 setNameSound _UnitNameSound;
        u2 setSpeaker _UnitVoice;
        u2 setPitch _UnitVoicePitch;
        u2 setFace _UnitFace;
        u2 assignTeam _UnitTeam;
        { u2 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u2, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u2 enableIRLasers true;
        u2 setSkill 1;
        u2 enableFatigue false;
        u2 setCombatBehaviour _UnitCombatBeh;
        u2 setUnitCombatMode _UnitCombatMod;
    } else {
        // systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        _time = time;
        waitUntil { sleep 1; not isNil "u2" || time - _time > 600};
        // systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u2 setVariable ["BIS_enableRandomization", false];
        u2 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u2 setNameSound _UnitNameSound;
        u2 setSpeaker _UnitVoice;
        u2 setPitch _UnitVoicePitch;
        u2 setFace _UnitFace;
        u2 assignTeam _UnitTeam;
        { u2 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u2, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u2 enableIRLasers true;
        u2 setSkill 1;
        u2 enableFatigue false;
        u2 setCombatBehaviour _UnitCombatBeh;
        u2 setUnitCombatMode _UnitCombatMod;
    };
};


// works outside of DRO
_unit setVariable ["BIS_enableRandomization", false];
_unit setName [_UnitFullName, _UnitFirstName, _UnitLastName];
_unit setNameSound _UnitNameSound;
_unit setSpeaker _UnitVoice;
_unit setPitch _UnitVoicePitch;
_unit setFace _UnitFace;
_unit assignTeam _UnitTeam;
_unit setUnitTrait ['Engineer', false];
_unit setUnitTrait ['ExplosiveSpecialist', false];
{ _unit setUnitTrait [_x, true]; } forEach _UnitTraits;
[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
_unit enableIRLasers true;
_unit setSkill 1;
_unit enableFatigue false;
_unit setCombatBehaviour _UnitCombatBeh;
_unit setUnitCombatMode _UnitCombatMod;
_unit setVehicleVarName _VehVarName;
