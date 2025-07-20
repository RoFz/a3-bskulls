
// VIPER init script
private _UnitName = "Viper";
private _VehVarName = "BSkullViper";
private _DRO_VehVarName = "u1";
private _UnitFullName = "Stephen Falken";
private _UnitFirstName = "Stephen";
private _UnitLastName = "Falken";
private _UnitNameSound = "Viper";
private _UnitVoice = "Male03ENG";
private _UnitTraits = ["Engineer","ExplosiveSpecialist"];
private _UnitTeam = "BLUE";
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
        "_UnitTraits",
        "_UnitCombatBeh",
        "_UnitCombatMod"
    ];
    _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
    _u setNameSound _UnitNameSound;
    _u setSpeaker _UnitVoice;
    _u assignTeam _UnitTeam;
    { _u setUnitTrait [_x, true]; } forEach _UnitTraits;
    _u setCombatBehaviour _UnitCombatBeh;
    _u setUnitCombatMode _UnitCombatMod;
    [_u, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
    _u enableIRLasers true;
    _u setSkill 1;
    _u enableFatigue false;
};
[
    _unit,
    _UnitFullName,
    _UnitFirstName,
    _UnitLastName,
    _UnitNameSound,
    _UnitVoice,
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
    if (!(isNil "u1")) then
    {
        u1 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u1 setNameSound _UnitNameSound;
        u1 setSpeaker _UnitVoice;
        u1 assignTeam _UnitTeam;
        { u1 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u1, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u1 enableIRLasers true;
        u1 setSkill 1;
        u1 enableFatigue false;
        u1 setCombatBehaviour _UnitCombatBeh;
        u1 setUnitCombatMode _UnitCombatMod;
    } else {
        // systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u1" };
        // systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u1 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u1 setNameSound _UnitNameSound;
        u1 setSpeaker _UnitVoice;
        u1 assignTeam _UnitTeam;
        { u1 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u1, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u1 enableIRLasers true;
        u1 setSkill 1;
        u1 enableFatigue false;
        u1 setCombatBehaviour _UnitCombatBeh;
        u1 setUnitCombatMode _UnitCombatMod;
    };
};
