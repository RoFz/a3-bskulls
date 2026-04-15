// WARDAK init script

private _UnitName = "Wardak";
private _VehVarName = "BSkullWardak";
private _DRO_VehVarName = "u12";
private _UnitFullName = "Tatyana Makarova";
private _UnitFirstName = "Tatyana";
private _UnitLastName = "Makarova";
private _UnitNameSound = "Wardak";
private _UnitVoice = "femalevoiceru";
private _UnitVoicePitch = 1.0;
private _UnitFace = "TCGM_Fem_Ayres";
private _UnitTeam = "YELLOW";
private _UnitTraits = [];
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
        "_UnitCombatMod"
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
};
[
    _unit,
    _UnitFullName,
    _UnitFirstName,
    _UnitLastName,
    _UnitNameSound,
    _UnitVoice,
    _UnitVoicePitch,
    _UnitFace,
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
    if (!(isNil "u12")) then
    {
        u12 setVariable ["BIS_enableRandomization", false];
        u12 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u12 setNameSound _UnitNameSound;
        u12 setSpeaker _UnitVoice;
        u12 setPitch _UnitVoicePitch;
        u12 setFace _UnitFace;
        u12 assignTeam _UnitTeam;
        { u12 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u12, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u12 enableIRLasers true;
        u12 setSkill 1;
        u12 enableFatigue false;
        u12 setCombatBehaviour _UnitCombatBeh;
        u12 setUnitCombatMode _UnitCombatMod;
    } else {
        // systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        _time = time;
        waitUntil { sleep 1; not isNil "u12" || time - _time > 600};        // systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u12 setVariable ["BIS_enableRandomization", false];
        u12 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u12 setNameSound _UnitNameSound;
        u12 setSpeaker _UnitVoice;
        u12 setPitch _UnitVoicePitch;
        u12 setFace _UnitFace;
        u12 assignTeam _UnitTeam;
        { u12 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u12, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u12 enableIRLasers true;
        u12 setSkill 1;
        u12 enableFatigue false;
        u12 setCombatBehaviour _UnitCombatBeh;
        u12 setUnitCombatMode _UnitCombatMod;
    };
};

_unit setVariable ["BIS_enableRandomization", false];
_unit setName [_UnitFullName, _UnitFirstName, _UnitLastName];
_unit setNameSound _UnitNameSound;
_unit setSpeaker _UnitVoice;
_unit setPitch _UnitVoicePitch;
_unit setFace _UnitFace;
_unit assignTeam _UnitTeam;
_unit setUnitTrait ['Medic', false];
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
