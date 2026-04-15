private _unit = _this;
private _bskull_UnitName = "McKendrick";
private _bskull_VehVarName = "BSkullMcKendrick";
private _VehVarName = vehicleVarName _this;
if (isNil "markerplayerstart") then
    {
        // systemChat format ["%1: Not DRO", _bskull_UnitName];
		if (_VehVarName == "") then {
			// systemChat format ["%1: vehicleVarName empty", _bskull_UnitName];
			_unit setVehicleVarName _bskull_VehVarName;
		} else {
			systemChat format ["%1: vehicleVarName = %2", _bskull_UnitName, _VehVarName];
		};
    } else {
		// systemChat format ["%1: DRO started. Waiting for vehicleVarName...", _bskull_UnitName];
		waitUntil{ sleep 1; if (vehicleVarName _this != "") exitWith { true }; }; // might not work
		// systemChat format ["waitUntil done. vehicleVarName = %1", vehicleVarName _this];
	};

private _VehVarName = vehicleVarName _this;
// systemChat format ["%1 (%2): Setting attributes...", _bskull_UnitName, _VehVarName]; 
_unit setName ['Greg McKendrick', 'Greg', 'McKendrick'];
_unit setNameSound 'McKendrick';
_unit setUnitRank 'SERGEANT';
_unit assignTeam 'BLUE';
_unit setUnitTrait ['Engineer', true];
_unit setUnitTrait ['ExplosiveSpecialist', true];
_unit setSpeaker 'male01engb';
