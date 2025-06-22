// Liu GHOST init script

private _UnitName = "Ghost";
private _VehVarName = "BSkullGhost";
private _DRO_VehVarName = "u11";
private _UnitFullName = "Liu Guinu";
private _UnitFirstName = "Liu";
private _UnitLastName = "Guinu";
private _UnitNameSound = "Ghost";
private _UnitVoice = "male02chi";
private _UnitVoicePitch = 1.22;
private _UnitFace = "TCGM_Fem_Liu";
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
    if (!(isNil "u11")) then
    {
        u11 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u11 setNameSound _UnitNameSound;
        u11 setSpeaker _UnitVoice;
        u11 setPitch _UnitVoicePitch;
        u11 setFace _UnitFace;
        u11 assignTeam _UnitTeam;
        { u11 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u11, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u11 enableIRLasers true;
        u11 setSkill 1;
        u11 enableFatigue false;
        u11 setCombatBehaviour _UnitCombatBeh;
        u11 setUnitCombatMode _UnitCombatMod;
    } else {
        // systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u4" };
        // systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u11 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u11 setNameSound _UnitNameSound;
        u11 setSpeaker _UnitVoice;
        u11 setPitch _UnitVoicePitch;
        u11 setFace _UnitFace;
        u11 assignTeam _UnitTeam;
        { u11 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u11, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u11 enableIRLasers true;
        u11 setSkill 1;
        u11 enableFatigue false;
        u11 setCombatBehaviour _UnitCombatBeh;
        u11 setUnitCombatMode _UnitCombatMod;
    };
};

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
