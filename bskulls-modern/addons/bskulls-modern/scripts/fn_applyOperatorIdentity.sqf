// bskulls_fnc_applyOperatorIdentity
// Applies Black Skulls named-operator identity and shared setup to a unit.
// No DRO globals (lobbycomplete / u1..uN / nameLookup).
//
// Sources:
// - community.bistudio.com CfgFunctions / Functions Library (TAG_fnc_* registration)
// - community.bistudio.com setName / setSpeaker / setFace / setPitch / setNameSound /
//   setUnitTrait / assignTeam / setIdentity (identity commands)
// - Existing CfgIdentities.hpp + unit init scripts (payload values)
// - community.bistudio.com/wiki/setUnitRank via bskulls_fnc_applyUnitRank (DRO-gated)
//
// Params:
//   0: OBJECT - unit
//   1: STRING - operator key or "" to infer from typeOf / unitClass
//      Keys: Viper, Fox, Vega, McKendrick, Jackson, Frost, Hawkins, Sykes,
//            Everett, Taylor, Liu, Makarova, Elias, Martinez

params [
    ["_unit", objNull, [objNull]],
    ["_key", "", [""]]
];

if (isNull _unit) exitWith { false };
if (!local _unit) exitWith { false };

if (_key isEqualTo "") then {
    // Prefer typeOf; also try unitClass (DRO lobby stores class before createUnit).
    private _sources = [typeOf _unit];
    private _uc = _unit getVariable ["unitClass", ""];
    if (_uc isNotEqualTo "" && {_uc isNotEqualTo "CUSTOM"}) then {
        _sources pushBackUnique _uc;
    };
    {
        private _type = _x;
        call {
            if (_type find "Unit_Viper" >= 0) exitWith { _key = "Viper" };
            if (_type find "Unit_Fox" >= 0) exitWith { _key = "Fox" };
            if (_type find "Unit_Vega" >= 0) exitWith { _key = "Vega" };
            if (_type find "Unit_McKendrick" >= 0) exitWith { _key = "McKendrick" };
            if (_type find "Unit_Jackson" >= 0) exitWith { _key = "Jackson" };
            if (_type find "Unit_Frost" >= 0) exitWith { _key = "Frost" };
            if (_type find "Unit_Hawkins" >= 0) exitWith { _key = "Hawkins" };
            if (_type find "Unit_Sykes" >= 0) exitWith { _key = "Sykes" };
            if (_type find "Unit_Everett" >= 0) exitWith { _key = "Everett" };
            if (_type find "Unit_Taylor" >= 0) exitWith { _key = "Taylor" };
            if (_type find "Unit_Liu" >= 0) exitWith { _key = "Liu" };
            if (_type find "Unit_Makarova" >= 0) exitWith { _key = "Makarova" };
            if (_type find "Unit_Elias" >= 0) exitWith { _key = "Elias" };
            if (_type find "Unit_Martinez" >= 0) exitWith { _key = "Martinez" };
        };
        if (_key isNotEqualTo "") exitWith {};
    } forEach _sources;
};

if (_key isEqualTo "") exitWith { false };

// Payload: [full, first, last, nameSound, speaker, pitch, face, traitsTrue, traitsFalse,
//           team, combatBeh, combatMode, disableAI, enableRandomization, varName, rank]
// Faces from CfgIdentities.hpp — always setFace on lobby class switches.
private _payload = call {
    if (_key isEqualTo "Viper") exitWith {
        [
            "Stephen Falken", "Stephen", "Falken",
            "Viper", "Male03ENG", 1,
            "WhiteHead_01",
            ["Engineer", "ExplosiveSpecialist", "UAVHacker"], ["Medic"],
            "BLUE", "STEALTH", "BLUE",
            [],
            false,
            "BSkullViper",
            "COLONEL"
        ]
    };
    if (_key isEqualTo "Fox") exitWith {
        [
            "Amanda Fox", "Amanda", "Fox",
            "Fox", "rhs_Female01ENG", 0.95,
            "TCGM_Fem_Stone",
            ["Medic"], ["Engineer", "ExplosiveSpecialist", "UAVHacker"],
            "BLUE", "STEALTH", "BLUE",
            [],
            true,
            "BSkullFox",
            "MAJOR"
        ]
    };
    if (_key isEqualTo "Vega") exitWith {
        [
            "Vince Vega", "Vince", "Vega",
            "Vega", "Male01GRE", 1,
            "WhiteHead_03",
            [], ["Medic", "Engineer", "ExplosiveSpecialist", "UAVHacker"],
            "BLUE", "STEALTH", "BLUE",
            ["AIMINGERROR", "SUPPRESSION"],
            false,
            "BSkullVega",
            "CAPTAIN"
        ]
    };
    if (_key isEqualTo "McKendrick") exitWith {
        [
            "Greg McKendrick", "Greg", "McKendrick",
            "McKendrick", "Male01ENGB", 1,
            "WhiteHead_04",
            ["Engineer", "ExplosiveSpecialist"], ["Medic", "UAVHacker"],
            "BLUE", "STEALTH", "BLUE",
            [],
            false,
            "BSkullMcKendrick",
            "SERGEANT"
        ]
    };
    if (_key isEqualTo "Jackson") exitWith {
        [
            "Jennifer Jackson", "Jennifer", "Jackson",
            "Jackson", "rhs_Female01ENG", 1.1,
            "TCGM_Fem_Fox",
            ["Medic"], ["Engineer", "ExplosiveSpecialist", "UAVHacker"],
            "RED", "STEALTH", "BLUE",
            [],
            true,
            "BSkullJackson",
            "CAPTAIN"
        ]
    };
    if (_key isEqualTo "Frost") exitWith {
        [
            "Patrick Frost", "Patrick", "Frost",
            "Frost", "Male08ENG", 1,
            "WhiteHead_02",
            [], ["Medic", "Engineer", "ExplosiveSpecialist", "UAVHacker"],
            "RED", "STEALTH", "BLUE",
            ["SUPPRESSION"],
            false,
            "BSkullFrost",
            "SERGEANT"
        ]
    };
    if (_key isEqualTo "Hawkins") exitWith {
        [
            "Kendall Hawkins", "Kendall", "Hawkins",
            "Hawkins", "Male01ENG", 1,
            "WhiteHead_05",
            [], ["Medic", "Engineer", "ExplosiveSpecialist", "UAVHacker"],
            "RED", "STEALTH", "BLUE",
            [],
            false,
            "BSkullHawkins",
            "CORPORAL"
        ]
    };
    if (_key isEqualTo "Sykes") exitWith {
        [
            "Martha Sykes", "Martha", "Sykes",
            "Sykes", "rhs_Female01ENG", 0.9,
            "TCGM_Fem_Gonzalez",
            ["Engineer", "UAVHacker"], ["Medic", "ExplosiveSpecialist"],
            "RED", "STEALTH", "BLUE",
            [],
            true,
            "BSkullSykes",
            "PRIVATE"
        ]
    };
    if (_key isEqualTo "Everett") exitWith {
        [
            "Frank Everett", "Frank", "Everett",
            "Everett", "Male10ENG", 1,
            "GreekHead_A3_10_a",
            [], ["Medic", "Engineer", "ExplosiveSpecialist", "UAVHacker"],
            "YELLOW", "STEALTH", "BLUE",
            [],
            false,
            "BSkullEverett",
            "LIEUTENANT"
        ]
    };
    if (_key isEqualTo "Taylor") exitWith {
        [
            "Chris Taylor", "Chris", "Taylor",
            "Taylor", "Male07ENG", 1,
            "WhiteHead_06",
            [], ["Medic", "Engineer", "ExplosiveSpecialist", "UAVHacker"],
            "YELLOW", "STEALTH", "BLUE",
            [],
            false,
            "BSkullTaylor",
            "SERGEANT"
        ]
    };
    if (_key isEqualTo "Liu") exitWith {
        [
            "Liu Guinu", "Liu", "Guinu",
            "Ghost", "Male02CHI", 1.22,
            "TCGM_Fem_Liu",
            [], ["Medic", "Engineer", "ExplosiveSpecialist", "UAVHacker"],
            "YELLOW", "STEALTH", "BLUE",
            [],
            true,
            "BSkullGhost",
            "CORPORAL"
        ]
    };
    if (_key isEqualTo "Makarova") exitWith {
        [
            "Tatyana Makarova", "Tatyana", "Makarova",
            "Wardak", "femalevoiceru", 1,
            "TCGM_Fem_Portman",
            [], ["Medic", "Engineer", "ExplosiveSpecialist", "UAVHacker"],
            "YELLOW", "STEALTH", "BLUE",
            [],
            true,
            "BSkullWardak",
            "PRIVATE"
        ]
    };
    if (_key isEqualTo "Elias") exitWith {
        [
            "Elias Gordon", "Elias", "Gordon",
            "Elias", "Male12ENG", 1,
            "WhiteHead_08",
            ["Engineer", "UAVHacker"], ["Medic", "ExplosiveSpecialist"],
            "YELLOW", "STEALTH", "BLUE",
            [],
            false,
            "BSkullElias",
            "PRIVATE"
        ]
    };
    if (_key isEqualTo "Martinez") exitWith {
        [
            "Oscar Martinez", "Oscar", "Martinez",
            "Martinez", "Male06GRE", 1,
            "PersianHead_A3_01",
            [], ["Medic", "Engineer", "ExplosiveSpecialist", "UAVHacker"],
            "YELLOW", "STEALTH", "BLUE",
            [],
            false,
            "BSkullMartinez",
            "PRIVATE"
        ]
    };
    []
};

if (_payload isEqualTo []) exitWith { false };

_payload params [
    "_fullName",
    "_firstName",
    "_lastName",
    "_nameSound",
    "_speaker",
    "_pitch",
    "_face",
    "_traitsTrue",
    "_traitsFalse",
    "_team",
    "_combatBeh",
    "_combatMode",
    "_disableAI",
    "_enableRandomization",
    "_varName",
    "_rank"
];

if (_enableRandomization) then {
    _unit setVariable ["BIS_enableRandomization", false];
};

_unit setName [_fullName, _firstName, _lastName];
_unit setNameSound _nameSound;
_unit setSpeaker _speaker;
_unit setPitch _pitch;
if (_face isNotEqualTo "") then {
    _unit setFace _face;
};

{ _unit setUnitTrait [_x, false]; } forEach _traitsFalse;
{ _unit setUnitTrait [_x, true]; } forEach _traitsTrue;

_unit assignTeam _team;
_unit setCombatBehaviour _combatBeh;

// BLUE is an intentional hard "never fire" rule for the player's group. Do
// not impose it on independently spawned DRO friendlies that happen to use a
// named Black Skulls class. DRO reapplies this identity after joining a unit
// to the player's group, so replacements still receive the rule.
if (((units group _unit) findIf { isPlayer _x }) >= 0) then {
    _unit setUnitCombatMode _combatMode;
};

{ _unit disableAI _x; } forEach _disableAI;

if ("insignia" in selectionNames _unit) then {
    [_unit, "Black_Skulls"] call BIS_fnc_setUnitInsignia;
};

_unit enableIRLasers true;
_unit setSkill 1;
_unit enableFatigue false;

[_unit, _rank] call bskulls_fnc_applyUnitRank;
[_unit] call bskulls_fnc_initMineStanceRecovery;

// Vehicle var names (BSkull*) are for non-DRO only. DRO slots must stay u1..uN.
// Never overwrite an existing DRO slot name from this function.
if (_varName isNotEqualTo "") then {
    private _cur = vehicleVarName _unit;
    if (_cur isEqualTo "" || {(_cur select [0, 1]) isNotEqualTo "u"}) then {
        _unit setVehicleVarName _varName;
    };
};

true
