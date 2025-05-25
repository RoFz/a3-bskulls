// JACKSON init script
private _UnitName = "Jackson";
private _VehVarName = "BSkullJackson";
private _DRO_VehVarName = "u5";
private _UnitFullName = "Jennifer Jackson";
private _UnitFirstName = "Jennifer";
private _UnitLastName = "Jackson";
private _UnitNameSound = "Jackson";
private _UnitRank = "COLONEL";
private _UnitVoice = "rhs_Female01ENG";
private _UnitVoicePitch = 1.1;
private _UnitFace = "TCGM_Fem_FoxBun";
private _UnitTeam = "RED";
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
    if (!(isNil "u5")) then
    {
        u5 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u5 setNameSound _UnitNameSound;
        u5 setUnitRank _UnitRank;
        u5 setSpeaker _UnitVoice;
        u5 setPitch _UnitVoicePitch;
        u5 setFace _UnitFace;
        u5 assignTeam _UnitTeam;
        { u5 setUnitTrait [_x, true]; } forEach _UnitTraits;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u5" };
        systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u5 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u5 setNameSound _UnitNameSound;
        u5 setUnitRank _UnitRank;
        u5 setSpeaker _UnitVoice;
        u5 setPitch _UnitVoicePitch;
        u5 setFace _UnitFace;
        u5 assignTeam _UnitTeam;
        { u5 setUnitTrait [_x, true]; } forEach _UnitTraits;
    };
};
