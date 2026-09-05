// MCKENDRICK init — identity via bskulls_fnc_applyOperatorIdentity (no DRO u4 coupling)
params [["_unit", objNull, [objNull]]];
if (isNull _unit) then { _unit = _this select 0; };
[_unit, "McKendrick"] call bskulls_fnc_applyOperatorIdentity;
