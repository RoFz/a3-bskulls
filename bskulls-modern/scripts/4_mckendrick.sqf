// MCKENDRICK init script
private _UnitName = "McKendrick";
private _VehVarName = "BSkullMcKendrick";
private _DRO_VehVarName = "u4";
private _UnitFullName = "Greg McKendrick";
private _UnitFirstName = "Greg";
private _UnitLastName = "McKendrick";
private _UnitNameSound = "McKendrick";
private _UnitVoice = "Male01ENGB";
// private _UnitVoicePitch = 0.95;
// private _UnitFace = "TCGM_Fem_Stone";
private _UnitTraits = ["Engineer","ExplosiveSpecialist"];
private _UnitTeam = "BLUE";
private _UnitCombatBeh = "STEALTH";
private _UnitCombatMod = "GREEN";

_unit = _this select 0;

// systemChat format ["%1: vehicleVarName = %2", _UnitName, (vehicleVarName _unit)];

_onSpawn = {
    params [
        "_u",
        "_UnitFullName",
        "_UnitFirstName",
        "_UnitLastName",
        "_UnitNameSound",
        "_UnitVoice",
        "_UnitTeam",
        "_UnitTraits",
        "_UnitCombatBeh",
        "_UnitCombatMod"
    ];
    _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
    _u setNameSound _UnitNameSound;
    _u setSpeaker _UnitVoice;
    _u assignTeam _UnitTeam;
    { _u setUnitTrait [_x, true]; } forEach _UnitTraits;
    _u setCombatBehaviour _UnitCombatBeh;
    _u setUnitCombatMode _UnitCombatMod;
    [_u, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
    _u enableIRLasers true;
    _u setSkill 1;
    _u enableFatigue false;
};
[
    _unit,
    _UnitFullName,
    _UnitFirstName,
    _UnitLastName,
    _UnitNameSound,
    _UnitVoice,
    _UnitTeam,
    _UnitTraits,
    _UnitCombatBeh,
    _UnitCombatMod
] spawn _onSpawn;

if ((isNil "lobbycomplete") || (isNil "playersready")) then
{
    _unit setVehicleVarName _VehVarName;
} else {
    // systemChat format ["%1: DRO detected!", _UnitName];
    uiSleep 5;
    if (!(isNil "u4")) then
    {
        u4 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u4 setNameSound _UnitNameSound;
        u4 setSpeaker _UnitVoice;
        u4 assignTeam _UnitTeam;
        { u4 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u4, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u4 enableIRLasers true;
        u4 setSkill 1;
        u4 enableFatigue false;
        u4 setCombatBehaviour _UnitCombatBeh;
        u4 setUnitCombatMode _UnitCombatMod;
    } else {
        // systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u4" };
        // systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u4 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u4 setNameSound _UnitNameSound;
        u4 setSpeaker _UnitVoice;
        u4 assignTeam _UnitTeam;
        { u4 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u4, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u4 enableIRLasers true;
        u4 setSkill 1;
        u4 enableFatigue false;
        u4 setCombatBehaviour _UnitCombatBeh;
        u4 setUnitCombatMode _UnitCombatMod;
    };
};

_unit setName [_UnitFullName, _UnitFirstName, _UnitLastName];
_unit setNameSound _UnitNameSound;
_unit setSpeaker _UnitVoice;
_unit assignTeam _UnitTeam;
_unit setUnitTrait ['Medic', false];
{ _unit setUnitTrait [_x, true]; } forEach _UnitTraits;
[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
_unit enableIRLasers true;
_unit setSkill 1;
_unit enableFatigue false;
_unit setCombatBehaviour _UnitCombatBeh;
_unit setUnitCombatMode _UnitCombatMod;
_unit setVehicleVarName _VehVarName;
