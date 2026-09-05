// bskulls_fnc_applyUnitRank
// Applies setUnitRank to a local unit, with a DRO ambient-friendly guard.
//
// Sources:
// - community.bistudio.com/wiki/setUnitRank (local unit)
// - community.bistudio.com/wiki/createUnit (default PRIVATE when rank omitted)
//
// After DRO Ready (lobbycomplete == 1), units that are not in a group with any
// player keep engine PRIVATE. That stops pInfClassesForWeights / friendly
// createUnit clones of named operators from inheriting COLONEL/MAJOR/etc.
// Non-DRO (Zeus/editor) always applies.
//
// Params:
//   0: OBJECT - unit
//   1: STRING - rank (PRIVATE..COLONEL)

params [
    ["_unit", objNull, [objNull]],
    ["_rank", "", [""]]
];

if (isNull _unit) exitWith { false };
if (!local _unit) exitWith { false };
if (_rank isEqualTo "") exitWith { false };

if (
    !isNil "lobbycomplete"
    && {lobbycomplete isEqualTo 1}
    && {{isPlayer _x} count units group _unit == 0}
) exitWith { false };

_unit setUnitRank _rank;
true
