// FROST init script
private _UnitName = "Frost";
private _VehVarName = "BSkullFrost";
private _DRO_VehVarName = "u6";
private _UnitFullName = "Patrick Fox";
private _UnitFirstName = "Patrick";
private _UnitLastName = "Frost";
private _UnitNameSound = "Frost";
private _UnitVoice = "Male08ENG";
private _UnitTeam = "RED";
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
        "_UnitTeam",
        "_UnitCombatBeh",
        "_UnitCombatMod"
    ];
    _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
    _u setNameSound _UnitNameSound;
    _u setSpeaker _UnitVoice;
    _u assignTeam _UnitTeam;
    _u setCombatBehaviour _UnitCombatBeh;
    _u setUnitCombatMode _UnitCombatMod;
	_u disableAI "SUPPRESSION";
};
[
    _unit,
    _UnitFullName,
    _UnitFirstName,
    _UnitLastName,
    _UnitNameSound,
    _UnitVoice,
    _UnitTeam,
    _UnitCombatBeh,
    _UnitCombatMod
] spawn _onSpawn;
if ((isNil "lobbycomplete") || (isNil "playersready")) then
{
	_unit setVehicleVarName _VehVarName;
} else {
    systemChat format ["%1: DRO detected!", _UnitName];
    uiSleep 5;
    if (!(isNil "u6")) then
    {
        u6 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u6 setNameSound _UnitNameSound;
        u6 setSpeaker _UnitVoice;
        u6 assignTeam _UnitTeam;
		u6 disableAI "SUPPRESSION";
        u6 setCombatBehaviour _UnitCombatBeh;
        u6 setUnitCombatMode _UnitCombatMod;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u6" };
        systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u6 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u6 setNameSound _UnitNameSound;
        u6 setSpeaker _UnitVoice;
        u6 assignTeam _UnitTeam;
		u6 disableAI "SUPPRESSION";
        u6 setCombatBehaviour _UnitCombatBeh;
        u6 setUnitCombatMode _UnitCombatMod;
    };
};
