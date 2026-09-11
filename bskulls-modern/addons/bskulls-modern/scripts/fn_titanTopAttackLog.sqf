/*
 * Record one parseable diagnostic event for the Archangel top attack.
 *
 * Diagnostics are opt-in through bskulls_fnc_titanTopAttackSetDebug. Terse
 * local systemChat events can be requested separately when enabling them.
 * The latest 500 local records remain in bskulls_titanTopAttackDebugRecords.
 * UNIT_STATE also has a dedicated 240-record buffer so opening the launcher
 * optic cannot evict the AI acquisition history needed for diagnosis.
 */

params [
    ["_projectile", objNull, [objNull]],
    ["_event", "", [""]],
    ["_details", [], [[]]],
    ["_traceId", "", [""]]
];

if !(missionNamespace getVariable ["bskulls_titanTopAttackDebug", false]) exitWith {false};

if (_traceId isEqualTo "" && {!isNull _projectile}) then {
    _traceId = _projectile getVariable ["bskulls_titanTopAttackTraceId", "untracked"];
};
if (_traceId isEqualTo "") then {
    _traceId = "untracked";
};

private _projectileClass = if (isNull _projectile) then {""} else {typeOf _projectile};
private _record = [
    ["tick", diag_tickTime],
    ["trace", _traceId],
    ["event", _event],
    ["machine", [clientOwner, isServer, hasInterface]],
    ["projectile", if (isNull _projectile) then {"<deleted>"} else {str _projectile}],
    ["projectileClass", _projectileClass],
    ["local", !isNull _projectile && {local _projectile}],
    ["details", _details]
];

private _records = missionNamespace getVariable ["bskulls_titanTopAttackDebugRecords", []];
_records pushBack _record;
if ((count _records) > 500) then {
    _records deleteAt 0;
};
missionNamespace setVariable ["bskulls_titanTopAttackDebugRecords", _records];

if (_event isEqualTo "UNIT_STATE") then {
    private _unitStateRecords = missionNamespace getVariable [
        "bskulls_titanTopAttackUnitStateRecords",
        []
    ];
    _unitStateRecords pushBack _record;
    if ((count _unitStateRecords) > 240) then {
        _unitStateRecords deleteAt 0;
    };
    missionNamespace setVariable [
        "bskulls_titanTopAttackUnitStateRecords",
        _unitStateRecords
    ];
};

diag_log format ["[BSKULLS][TITAN-TA] %1", _record];
if (
    hasInterface
    && {missionNamespace getVariable ["bskulls_titanTopAttackDebugChat", false]}
) then {
    systemChat format ["Titan TA %1: %2", _traceId, _event];
};

true
