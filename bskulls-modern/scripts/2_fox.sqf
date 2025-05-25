// FOX init script

_UnitName = "Fox";
_VehVarName = "BSkullFox";
_DRO_VehVarName = "u2";
_UnitFullName = "Amanda Fox";
_UnitFirstName = "Amanda";
_UnitLastName = "Fox";
_UnitNameSound = "Fox";
_UnitVoice = "rhs_Female01ENG";
_UnitVoicePitch = 0.95;
_UnitFace = "TCGM_Fem_Stone";
_UnitTraits = ["Medic"];

_unit = _this select 0;

if ((isNil "lobbycomplete") || (isNil "playersready")) then
{
    systemChat format ["%1: no DRO detected.", _UnitName];
    _unit setVehicleVarName _VehVarName;
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
            "_UnitTraits" 
        ];
        _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        _u setNameSound _UnitNameSound;
        _u setSpeaker _UnitVoice;
        _u setPitch _UnitVoicePitch;
        _u setFace _UnitFace;
        { _u setUnitTrait [_x, true]; } forEach _UnitTraits;
        [_u, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;
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
        _UnitTraits        
    ] spawn _onSpawn;
} else {
    systemChat format ["%1: DRO detected!", _UnitName];
    uiSleep 5;
    if (!(isNil "u2")) then
    {
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
                "_UnitTraits" 
            ];
            _u setName [_UnitFullName, _UnitFirstName, _UnitLastName];
            _u setNameSound _UnitNameSound;
            _u setSpeaker _UnitVoice;
            _u setPitch _UnitVoicePitch;
            _u setFace _UnitFace;
            { _u setUnitTrait [_x, true]; } forEach _UnitTraits;
            [_u, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;
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
            _UnitTraits        
        ] spawn _onSpawn;
        // u2 setName [_UnitFullName, _UnitFirstName, _UnitLastName];
        // u2 setNameSound _UnitNameSound;
        // u2 setSpeaker _UnitVoice;
        // u2 setPitch _UnitVoicePitch;
        // u2 setFace _UnitFace;
        // { u2 setUnitTrait [_x, true]; } forEach _UnitTraits;
        // [u2, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;
        // u2 enableIRLasers true;
        // u2 setSkill 1;
        // u2 enableFatigue false;
    };
};
