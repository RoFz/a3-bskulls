// bskulls_fnc_daoExcludeVehicle
// Keep a vehicle off the Drongo Air Ops tablet.
//
// Do NOT call DAO\Scripts\Core\Exclude.sqf: it pushes OBJECT/GROUP into daoIgnore,
// and DAO_fnc_Ignore then does `isKindOf` on those entries (expects classnames) —
// that errors and can break AirGroupsBySide so hangar aircraft vanish from orders.
// Do NOT call CfgFunctions DAO_fnc_Exclude (Eden module stub with wrong args).
//
// Safe pattern (matches Eden module + CheckExclude):
//   - daoExclude on vehicle + group
//   - classname string in daoIgnore (isKindOf-safe; also covers typeOf-in checks)
//
// Params:
//   0: OBJECT - vehicle
//   1: NUMBER - seconds before re-apply (RegisterLoop race), 0 = immediate only

params [
	["_veh", objNull, [objNull]],
	["_deferSec", 3, [0]]
];

if (isNull _veh) exitWith { false };

// UCAV Sentinel: single DAO-managed class (DRO may spawn it; never exclude).
if ((typeOf _veh) isEqualTo "B_PTbskull_Veh_Drone_blackops_04") exitWith { false };

private _fnc_apply = {
	params ["_v"];
	if (isNull _v) exitWith { false };

	if (isNil "daoIgnore") then { daoIgnore = []; };
	if (isNil "daoRegisteredAircraft") then { daoRegisteredAircraft = []; };

	private _class = typeOf _v;
	private _g = group _v;

	_v setVariable ["daoExclude", true, true];
	if (!isNull _g) then {
		_g setVariable ["daoExclude", true, true];
	};

	// Classname only — never push Object/Group (breaks DAO_fnc_Ignore).
	daoIgnore pushBackUnique _class;

	if (!isNil "DAO_fnc_TimeStamp") then {
		_v setVariable ["daoActionTime", (call DAO_fnc_TimeStamp) + 999, true];
	};
	true
};

[_veh] call _fnc_apply;

if (_deferSec > 0) then {
	[_veh, _deferSec, _fnc_apply] spawn {
		params ["_v", "_delay", "_apply"];
		sleep _delay;
		if (!isNull _v && {alive _v}) then {
			[_v] call _apply;
		};
	};
};

true
