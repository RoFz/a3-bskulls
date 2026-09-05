// TAYLOR init — identity via bskulls_fnc_applyOperatorIdentity (no DRO u10 coupling)
params [["_unit", objNull, [objNull]]];
if (isNull _unit) then { _unit = _this select 0; };
[_unit, "Taylor"] call bskulls_fnc_applyOperatorIdentity;
