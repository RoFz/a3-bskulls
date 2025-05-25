_unit = _this select 0;
private _curVehVarName = vehicleVarName _unit;
private _curVehName = name _unit;
// systemChat format ["%1 (%2): setting group attributes...", _curVehName, _curVehVarName];
_this enableIRLasers true;
_this setSkill 1;
_this enableFatigue false;
_this setCombatBehaviour 'COMBAT';
_this setUnitCombatMode 'RED'; 
{
	detach _x;
	deleteVehicle _x;
} forEach attachedObjects _this;
sleep 1;
if (GDMN_setting_thermal) then {
	_GDMN_object_thermal = '#particlesource' createVehicle getpos _this;
	GDMN_object_thermal = _GDMN_object_thermal;
	_GDMN_object_thermal setParticleClass 'IFF_strobe_particle';
	if (isNull attachedTo _GDMN_object_thermal) then {
		_GDMN_object_thermal attachTo[_this, [0, 0, 0.2], 'rightshoulder'];
		GDMN_strobe_is_on = true;
		systemChat format ["Thermal strobe enabled for %1", name _this]
	};
};
if (GDMN_setting_NVG) then {
	_GDMN_object_NVG = 'GDMN_strobe_NVG' createVehicle getPos _this;
	GDMN_object_NVG = _GDMN_object_NVG;
	if (isNull attachedTo _GDMN_object_NVG) then {
		_GDMN_object_NVG attachTo[_this, [-0.05, -0.1, 0.17], 'neck'];
		GDMN_strobe_is_on = true;
	};
};
// insignia is visible via thermals
[_this, 'BSKULLS_Insignia'] call BIS_fnc_setUnitInsignia;
// reload _this;