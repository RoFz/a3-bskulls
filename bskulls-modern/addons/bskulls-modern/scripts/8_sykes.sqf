// SYKES init — identity via bskulls_fnc_applyOperatorIdentity (no DRO u8 coupling)
params [["_unit", objNull, [objNull]]];
if (isNull _unit) then { _unit = _this select 0; };
[_unit, "Sykes"] call bskulls_fnc_applyOperatorIdentity;
