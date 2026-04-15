// FOX init script
private _UnitName = "Fox";
private _VehVarName = "BSkullFox";
private _DRO_VehVarName = "u2";
private _UnitFullName = "Amanda Fox";
private _UnitFirstName = "Amanda";
private _UnitLastName = "Fox";
private _UnitNameSound = "Fox";
private _UnitRank = "MAJOR";
private _UnitVoice = "rhs_Female01ENG";
private _UnitVoicePitch = 0.95;
private _UnitFace = "TCGM_Fem_Stone";
private _UnitTeam = "BLUE";
private _UnitTraits = ["Medic"];
_unit = _this select 0;
_onSpawn = {
    params [
        "_u",
        "_UnitFullName",
        "_UnitFirstName",
        "_UnitLastName",
        "_UnitNameSound",
        "_UnitRank",
        "_UnitVoice",
        "_UnitVoicePitch",
        "_UnitFace",
        "_UnitTeam",
        "_UnitTraits" 
    ];
    _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
    _u setNameSound _UnitNameSound;
    _u setUnitRank _UnitRank;
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
    _UnitRank,
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
    if (!(isNil "u2")) then
    {
        u2 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u2 setNameSound _UnitNameSound;
        u2 setUnitRank _UnitRank;
        u2 setSpeaker _UnitVoice;
        u2 setPitch _UnitVoicePitch;
        u2 setFace _UnitFace;
        u2 assignTeam _UnitTeam;
        { u2 setUnitTrait [_x, true]; } forEach _UnitTraits;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u2" };
        systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u2 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u2 setNameSound _UnitNameSound;
        u2 setUnitRank _UnitRank;
        u2 setSpeaker _UnitVoice;
        u2 setPitch _UnitVoicePitch;
        u2 setFace _UnitFace;
        u2 assignTeam _UnitTeam;
        { u2 setUnitTrait [_x, true]; } forEach _UnitTraits;
    };
};
