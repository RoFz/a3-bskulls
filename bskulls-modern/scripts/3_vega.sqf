// VEGA init script
private _UnitName = "Vega";
private _VehVarName = "BSkullVega";
private _DRO_VehVarName = "u3";
private _UnitFullName = "Vince Vega";
private _UnitFirstName = "Vince";
private _UnitLastName = "Vega";
private _UnitNameSound = "Vega";
private _UnitVoice = "Male01GRE";
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
        "_UnitCombatBeh",
        "_UnitCombatMod"
    ];
    _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
    _u setNameSound _UnitNameSound;
    _u setSpeaker _UnitVoice;
    _u assignTeam _UnitTeam;
    _u setCombatBehaviour _UnitCombatBeh;
    _u setUnitCombatMode _UnitCombatMod;
	_u disableAI "AIMINGERROR";
	_u disableAI "SUPPRESSION";
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
    _UnitCombatBeh,
    _UnitCombatMod
] spawn _onSpawn;

if ((isNil "lobbycomplete") || (isNil "playersready")) then
{
	_unit setVehicleVarName _VehVarName;
} else {
    systemChat format ["%1: DRO detected!", _UnitName];
    uiSleep 5;
    if (!(isNil "u3")) then
    {
        u3 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u3 setNameSound _UnitNameSound;
        u3 setSpeaker _UnitVoice;
        u3 assignTeam _UnitTeam;
		u3 disableAI "AIMINGERROR";
		u3 disableAI "SUPPRESSION";
        [u3, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u3 enableIRLasers true;
        u3 setSkill 1;
        u3 enableFatigue false;
        u3 setCombatBehaviour _UnitCombatBeh;
        u3 setUnitCombatMode _UnitCombatMod;
    } else {
        // note: it's not known if this condition actually happens - this might not be needed
        systemChat format ["%1: (%2) Nil. Waiting for it...", _UnitName, _DRO_VehVarName];
        waitUntil { sleep 1; not isNil "u3" };
        systemChat format ["%1: (%2) not Nil. Setting unit attributes...", _UnitName, _DRO_VehVarName];
        u3 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        u3 setNameSound _UnitNameSound;
        u3 setSpeaker _UnitVoice;
        u3 assignTeam _UnitTeam;
		u3 disableAI "AIMINGERROR";
		u3 disableAI "SUPPRESSION";
        [u3, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
        u3 enableIRLasers true;
        u3 setSkill 1;
        u3 enableFatigue false;
        u3 setCombatBehaviour _UnitCombatBeh;
        u3 setUnitCombatMode _UnitCombatMod;
    };
};
