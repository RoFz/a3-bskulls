private _unit = _this;
// _unit = _unit select 0;
// private _curVehVarName = vehicleVarName _unit;
// private _curVehName = name _unit;
// systemChat format ["%1 (%2): setting group attributes...", _curVehName, _curVehVarName];
_unit enableIRLasers true;
_unit setSkill 1;
_unit enableFatigue false;
// _unit setCombatBehaviour 'AWARE';
// _unit setUnitCombatMode 'BLUE';
// {
// 	detach _x;
// 	deleteVehicle _x;
// } forEach attachedObjects _unit;
// sleep 1;
// if (GDMN_setting_thermal) then {
// 	_GDMN_object_thermal = '#particlesource' createVehicle getPos _unit;
// 	GDMN_object_thermal = _GDMN_object_thermal;
// 	_GDMN_object_thermal setParticleClass 'IFF_strobe_particle';
// 	if (isNull attachedTo _GDMN_object_thermal) then {
// 		_GDMN_object_thermal attachTo[_unit, [0, 0, 0.2], 'rightshoulder'];
// 		GDMN_strobe_is_on = true;
// 		systemChat format ["Thermal strobe enabled for %1", name _unit]
// 	};
// };
// if (GDMN_setting_NVG) then {
// 	_GDMN_object_NVG = 'GDMN_strobe_NVG' createVehicle getPos _unit;
// 	GDMN_object_NVG = _GDMN_object_NVG;
// 	if (isNull attachedTo _GDMN_object_NVG) then {
// 		_GDMN_object_NVG attachTo[_unit, [-0.05, -0.1, 0.17], 'neck'];
// 		GDMN_strobe_is_on = true;
// 	};
// };
// insignia is visible via thermals
[_unit, 'Black_Skulls'] call BIS_fnc_setUnitInsignia;
// reload _unit;
