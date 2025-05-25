_unit = _this select 0;
private _curVehVarName = vehicleVarName _unit;
private _curVehName = name _unit;
// systemChat format ["%1 (%2): setting group attributes...", _curVehName, _curVehVarName];
_unit setSkill 1;
_unit enableFatigue false;
_unit setCombatBehaviour 'STEALTH';
_unit setUnitCombatMode 'GREEN'; 
[_unit, 'BSKULLS_Nam_Insignia'] call BIS_fnc_setUnitInsignia;
