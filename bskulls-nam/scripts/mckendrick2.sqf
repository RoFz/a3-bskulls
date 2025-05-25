private _bskull_UnitName = "McKendrick";
private _bskull_VehVarName = "BSkullMcKendrick";
private _VehVarName = vehicleVarName _this;
if (isNil "markerplayerstart") then
    {
        // systemChat format ["%1: Not DRO", _bskull_UnitName];
		if (_VehVarName == "") then {
			// systemChat format ["%1: vehicleVarName empty", _bskull_UnitName];
			_this setVehicleVarName _bskull_VehVarName;
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
_this setName ['Greg McKendrick', 'Greg', 'McKendrick'];
_this setNameSound 'McKendrick';
_this setUnitRank 'SERGEANT';
_this assignTeam 'BLUE';
_this setUnitTrait ['Engineer', true];
_this setUnitTrait ['ExplosiveSpecialist', true];
_this setSpeaker 'male01engb';
