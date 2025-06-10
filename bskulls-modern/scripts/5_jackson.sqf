// JACKSON init script
private _UnitName = "Jackson";
private _VehVarName = "BSkullJackson";
private _DRO_VehVarName = "u5";
private _UnitFullName = "Jennifer Jackson";
private _UnitFirstName = "Jennifer";
private _UnitLastName = "Jackson";
private _UnitNameSound = "Jackson";
private _UnitVoice = "rhs_Female01ENG";
private _UnitVoicePitch = 1.1;
private _UnitFace = "TCGM_Fem_FoxBun";
private _UnitTraits = ["Medic"];
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
    if (!(isNil "u5")) then
    {
        u5 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u5 setNameSound _UnitNameSound;
        u5 setSpeaker _UnitVoice;
        u5 setPitch _UnitVoicePitch;
        u5 setFace _UnitFace;
        u5 assignTeam _UnitTeam;
        { u5 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u5, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u5 enableIRLasers true;
        u5 setSkill 1;
        u5 enableFatigue false;
        u5 setCombatBehaviour _UnitCombatBeh;
        u5 setUnitCombatMode _UnitCombatMod;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u5" };
        systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u5 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u5 setNameSound _UnitNameSound;
        u5 setSpeaker _UnitVoice;
        u5 setPitch _UnitVoicePitch;
        u5 setFace _UnitFace;
        u5 assignTeam _UnitTeam;
        { u5 setUnitTrait [_x, true]; } forEach _UnitTraits;
        [u5, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u5 enableIRLasers true;
        u5 setSkill 1;
        u5 enableFatigue false;
        u5 setCombatBehaviour _UnitCombatBeh;
        u5 setUnitCombatMode _UnitCombatMod;
    };
};
