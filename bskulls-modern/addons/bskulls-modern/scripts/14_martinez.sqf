// MARTINEZ init — identity via bskulls_fnc_applyOperatorIdentity (no DRO u14 coupling)
params [["_unit", objNull, [objNull]]];
if (isNull _unit) then { _unit = _this select 0; };
[_unit, "Martinez"] call bskulls_fnc_applyOperatorIdentity;
