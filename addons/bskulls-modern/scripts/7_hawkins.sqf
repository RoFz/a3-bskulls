// HAWKINS init script
private _UnitName = "Hawkins";
private _VehVarName = "BSkullHawkins";
private _DRO_VehVarName = "u7";
private _UnitFullName = "Kendall Hawkins";
private _UnitFirstName = "Kendall";
private _UnitLastName = "Hawkins";
private _UnitNameSound = "Hawkins";
private _UnitVoice = "Male01ENG";
// private _UnitVoicePitch = 0.95;
// private _UnitFace = "TCGM_Fem_Stone";
private _UnitTeam = "RED";
private _UnitCombatBeh = "STEALTH";
private _UnitCombatMod = "GREEN";

_unit = _this select 0;

// systemChat format ["%1: vehicleVarName = %2", _UnitName, (vehicleVarName _unit)];

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
    // systemChat format ["%1: DRO detected!", _UnitName];
    uiSleep 5;
    if (!(isNil "u7")) then
    {
        u7 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u7 setNameSound _UnitNameSound;
        u7 setSpeaker _UnitVoice;
        u7 assignTeam _UnitTeam;
        u7 setCombatBehaviour _UnitCombatBeh;
        u7 setUnitCombatMode _UnitCombatMod;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        // systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u7" };
        // systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u7 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u7 setNameSound _UnitNameSound;
        u7 setSpeaker _UnitVoice;
        u7 assignTeam _UnitTeam;
        u7 setCombatBehaviour _UnitCombatBeh;
        u7 setUnitCombatMode _UnitCombatMod;
    };
};

_unit setName [_UnitFullName, _UnitFirstName, _UnitLastName];
_unit setNameSound _UnitNameSound;
_unit setSpeaker _UnitVoice;
_unit assignTeam _UnitTeam;
_unit setUnitTrait ['Medic', false];
_unit setUnitTrait ['Engineer', false];
_unit setUnitTrait ['ExplosiveSpecialist', false];
_unit setCombatBehaviour _UnitCombatBeh;
_unit setUnitCombatMode _UnitCombatMod;
_unit setVehicleVarName _VehVarName;
