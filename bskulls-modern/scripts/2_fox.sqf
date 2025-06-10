// FOX init script

private _UnitName = "Fox";
private _VehVarName = "BSkullFox";
private _DRO_VehVarName = "u2";
private _UnitFullName = "Amanda Fox";
private _UnitFirstName = "Amanda";
private _UnitLastName = "Fox";
private _UnitNameSound = "Fox";
private _UnitVoice = "rhs_Female01ENG";
private _UnitVoicePitch = 0.95;
private _UnitFace = "TCGM_Fem_Stone";
private _UnitTraits = ["Medic"];
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
        "_UnitVoicePitch",
        "_UnitFace",
        "_UnitTeam",
        "_UnitTraits",
        "_UnitCombatBeh",
        "_UnitCombatMod"
    ];
    _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
    _u setNameSound _UnitNameSound;
    _u setSpeaker _UnitVoice;
    _u setPitch _UnitVoicePitch;
    _u setFace _UnitFace;
    _u assignTeam _UnitTeam;
    { _u setUnitTrait [_x, true]; } forEach _UnitTraits;
    [_u, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
    _u enableIRLasers true;
    _u setSkill 1;
    _u enableFatigue false;
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
    systemChat format ["%1: DRO detected!", _UnitName];
    uiSleep 5;
    if (!(isNil "u2")) then
    {
        u2 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u2 setNameSound _UnitNameSound;
        u2 setSpeaker _UnitVoice;
        u2 setPitch _UnitVoicePitch;
        u2 setFace _UnitFace;
        u2 assignTeam _UnitTeam;
        { u2 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [_u, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u2 enableIRLasers true;
        u2 setSkill 1;
        u2 enableFatigue false;
        u2 setCombatBehaviour _UnitCombatBeh;
        u2 setUnitCombatMode _UnitCombatMod;
    } else {
        systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u4" };
        systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u2 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u2 setNameSound _UnitNameSound;
        u2 setSpeaker _UnitVoice;
        u2 setPitch _UnitVoicePitch;
        u2 setFace _UnitFace;
        u2 assignTeam _UnitTeam;
        { u2 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [_u, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u2 enableIRLasers true;
        u2 setSkill 1;
        u2 enableFatigue false;
        u2 setCombatBehaviour _UnitCombatBeh;
        u2 setUnitCombatMode _UnitCombatMod;
    };
};
