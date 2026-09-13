/*
 * Store transient Archangel runtime state in localNamespace. The registry may
 * contain engine handles and object references because it is deliberately not
 * serialized into saved games.
 *
 * https://community.bohemia.net/wiki/Namespace
 * https://community.bohemia.net/wiki/localNamespace
 */

params ["_owner", ["_key", "", [""]], "_value"];

if (isNull _owner || {_key isEqualTo ""}) exitWith {false};

private _records = (localNamespace getVariable [
    "bskulls_titanTopAttackRuntimeRecords",
    []
]) select {
    !isNull (_x param [0, objNull])
};
private _index = _records findIf {
    (_x param [0, objNull]) isEqualTo _owner
    && {(_x param [1, ""]) isEqualTo _key}
};
private _record = [_owner, _key, _value];
if (_index < 0) then {
    _records pushBack _record;
} else {
    _records set [_index, _record];
};

localNamespace setVariable ["bskulls_titanTopAttackRuntimeRecords", _records];
true
