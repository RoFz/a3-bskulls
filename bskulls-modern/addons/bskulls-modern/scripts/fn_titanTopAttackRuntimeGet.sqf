/*
 * Read transient Archangel runtime state without placing it in a namespace
 * that Arma serializes into mission saves. Owners are objects or groups; stale
 * entries are discarded when the registry is read.
 *
 * https://community.bohemia.net/wiki/Namespace
 * https://community.bohemia.net/wiki/localNamespace
 */

params ["_owner", ["_key", "", [""]], "_default"];

if (isNull _owner || {_key isEqualTo ""}) exitWith {_default};

private _records = localNamespace getVariable [
    "bskulls_titanTopAttackRuntimeRecords",
    []
];
private _liveRecords = _records select {
    !isNull (_x param [0, objNull])
};
if ((count _liveRecords) isNotEqualTo (count _records)) then {
    localNamespace setVariable [
        "bskulls_titanTopAttackRuntimeRecords",
        _liveRecords
    ];
};

private _index = _liveRecords findIf {
    (_x param [0, objNull]) isEqualTo _owner
    && {(_x param [1, ""]) isEqualTo _key}
};
if (_index < 0) exitWith {_default};

(_liveRecords select _index) param [2, _default]
