// MCKENDRICK init script
private _UnitName = "McKendrick";
private _VehVarName = "BSkullMcKendrick";
private _DRO_VehVarName = "u4";
private _UnitFullName = "Greg McKendrick";
private _UnitFirstName = "Greg";
private _UnitLastName = "McKendrick";
private _UnitNameSound = "McKendrick";
private _UnitRank = "SERGEANT";
private _UnitVoice = "Male01ENGB";
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
    if (!(isNil "u4")) then
    {
        u4 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u4 setNameSound _UnitNameSound;
        u4 setUnitRank _UnitRank;
        u4 setSpeaker _UnitVoice;
        u4 assignTeam _UnitTeam;
        { u4 setUnitTrait [_x, true]; } forEach _UnitTraits;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u4" };
        systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u4 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u4 setNameSound _UnitNameSound;
        u4 setUnitRank _UnitRank;
        u4 setSpeaker _UnitVoice;
        u4 assignTeam _UnitTeam;
        { u4 setUnitTrait [_x, true]; } forEach _UnitTraits;
    };
};
