// HAWKINS init script
private _UnitName = "Hawkins";
private _VehVarName = "BSkullHawkins";
private _DRO_VehVarName = "u7";
private _UnitFullName = "Kendall Fox";
private _UnitFirstName = "Kendall";
private _UnitLastName = "Hawkins";
private _UnitNameSound = "Hawkins";
private _UnitRank = "PRIVATE";
private _UnitVoice = "Male01ENG";
private _UnitTeam = "RED";
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
        "_UnitTeam"
    ];
    _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
    _u setNameSound _UnitNameSound;
    _u setUnitRank _UnitRank;
    _u setSpeaker _UnitVoice;
    _u assignTeam _UnitTeam;
};
[
    _unit,
    _UnitFullName,
    _UnitFirstName,
    _UnitLastName,
    _UnitNameSound,
    _UnitRank,
    _UnitVoice,
    _UnitTeam     
] spawn _onSpawn;
if ((isNil "lobbycomplete") || (isNil "playersready")) then
{
	_unit setVehicleVarName _VehVarName;
} else {
    systemChat format ["%1: DRO detected!", _UnitName];
    uiSleep 5;
    if (!(isNil "u7")) then
    {
        u7 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u7 setNameSound _UnitNameSound;
        u7 setUnitRank _UnitRank;
        u7 setSpeaker _UnitVoice;
        u7 assignTeam _UnitTeam;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u7" };
        systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u7 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u7 setNameSound _UnitNameSound;
        u7 setUnitRank _UnitRank;
        u7 setSpeaker _UnitVoice;
        u7 assignTeam _UnitTeam;
    };
};
