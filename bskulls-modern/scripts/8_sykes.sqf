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
        "_UnitTraits" 
    ];
    _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
    _u setNameSound _UnitNameSound;
    _u setSpeaker _UnitVoice;
    _u setPitch _UnitVoicePitch;
    _u setFace _UnitFace;
    _u assignTeam _UnitTeam;
    { _u setUnitTrait [_x, true]; } forEach _UnitTraits;
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
    _UnitTraits        
] spawn _onSpawn;
if ((isNil "lobbycomplete") || (isNil "playersready")) then
{
    _unit setVehicleVarName _VehVarName;
} else {
    systemChat format ["%1: DRO detected!", _UnitName];
    uiSleep 5;
    if (!(isNil "u8")) then
    {
        u8 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u8 setNameSound _UnitNameSound;
        u8 setSpeaker _UnitVoice;
        u8 setPitch _UnitVoicePitch;
        u8 setFace _UnitFace;
        u8 assignTeam _UnitTeam;
        { u8 setUnitTrait [_x, true]; } forEach _UnitTraits;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u8" };
        systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u8 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u8 setNameSound _UnitNameSound;
        u8 setSpeaker _UnitVoice;
        u8 setPitch _UnitVoicePitch;
        u8 setFace _UnitFace;
        u8 assignTeam _UnitTeam;
        { u8 setUnitTrait [_x, true]; } forEach _UnitTraits;
    };
};
