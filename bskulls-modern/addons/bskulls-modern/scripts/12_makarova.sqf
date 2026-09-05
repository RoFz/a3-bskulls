// MAKAROVA init — identity via bskulls_fnc_applyOperatorIdentity (no DRO u12 coupling)
params [["_unit", objNull, [objNull]]];
if (isNull _unit) then { _unit = _this select 0; };
[_unit, "Makarova"] call bskulls_fnc_applyOperatorIdentity;
