// VIPER init script
private _UnitName = "Viper";
private _VehVarName = "BSkullViper";
private _DRO_VehVarName = "u1";
private _UnitFullName = "Stephen Falken";
private _UnitFirstName = "Stephen";
private _UnitLastName = "Falken";
private _UnitNameSound = "Viper";
private _UnitRank = "MAJOR";
private _UnitVoice = "Male03ENG";
private _UnitTeam = "BLUE";
private _UnitTraits = ["Engineer","ExplosiveSpecialist"];
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
        "_UnitTeam",
        "_UnitTraits" 
    ];
    _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
    _u setNameSound _UnitNameSound;
    _u setUnitRank _UnitRank;
    _u setSpeaker _UnitVoice;
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
    _UnitTeam,
    _UnitTraits
] spawn _onSpawn;
if ((isNil "lobbycomplete") || (isNil "playersready")) then
{
    _unit setVehicleVarName _VehVarName;
} else {
    systemChat format ["%1: DRO detected!", _UnitName];
    uiSleep 5;
    if (!(isNil "u1")) then
    {
        u1 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u1 setNameSound _UnitNameSound;
        u1 setUnitRank _UnitRank;
        u1 setSpeaker _UnitVoice;
        u1 assignTeam _UnitTeam;
        { u1 setUnitTrait [_x, true]; } forEach _UnitTraits;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u1" };
        systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u1 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u1 setNameSound _UnitNameSound;
        u1 setUnitRank _UnitRank;
        u1 setSpeaker _UnitVoice;
        u1 assignTeam _UnitTeam;
        { u1 setUnitTrait [_x, true]; } forEach _UnitTraits;
    };
};
