// VEGA init — identity via bskulls_fnc_applyOperatorIdentity (no DRO u3 coupling)
params [["_unit", objNull, [objNull]]];
if (isNull _unit) then { _unit = _this select 0; };
[_unit, "Vega"] call bskulls_fnc_applyOperatorIdentity;
