// SYKES init script
private _UnitName = "Sykes";
private _VehVarName = "BSkullSykes";
private _DRO_VehVarName = "u8";
private _UnitFullName = "Martha Sykes";
private _UnitFirstName = "Martha";
private _UnitLastName = "Sykes";
private _UnitNameSound = "Sykes";
private _UnitVoice = "rhs_Female01ENG";
private _UnitVoicePitch = 0.9;
private _UnitFace = "TCGM_Fem_Gonzalez";
private _UnitTeam = "RED";
private _UnitTraits = ["Engineer"];
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
    if (!(isNil "u8")) then
    {
        u8 setVariable ["BIS_enableRandomization", false];
        u8 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u8 setNameSound _UnitNameSound;
        u8 setSpeaker _UnitVoice;
        u8 setPitch _UnitVoicePitch;
        u8 setFace _UnitFace;
        u8 assignTeam _UnitTeam;
        { u8 setUnitTrait [_x, true]; } forEach _UnitTraits;
        u8 setCombatBehaviour _UnitCombatBeh;
        u8 setUnitCombatMode _UnitCombatMod;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        // systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        _time = time;
        waitUntil { sleep 1; not isNil "u8" || time - _time > 600};        // systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u8 setVariable ["BIS_enableRandomization", false];
        u8 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u8 setNameSound _UnitNameSound;
        u8 setSpeaker _UnitVoice;
        u8 setPitch _UnitVoicePitch;
        u8 setFace _UnitFace;
        u8 assignTeam _UnitTeam;
        { u8 setUnitTrait [_x, true]; } forEach _UnitTraits;
        u8 setCombatBehaviour _UnitCombatBeh;
        u8 setUnitCombatMode _UnitCombatMod;
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
_unit setUnitTrait ['ExplosiveSpecialist', false];
{ _unit setUnitTrait [_x, true]; } forEach _UnitTraits;
_unit setCombatBehaviour _UnitCombatBeh;
_unit setUnitCombatMode _UnitCombatMod;
_unit setVehicleVarName _VehVarName;
