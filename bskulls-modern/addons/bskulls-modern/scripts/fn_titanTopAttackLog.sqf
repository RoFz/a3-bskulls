/*
 * Record one parseable diagnostic event for the Archangel top attack.
 *
 * Diagnostics start automatically and remain switchable through
 * bskulls_fnc_titanTopAttackSetDebug. Terse local systemChat events can be
 * requested separately when enabling them.
 * The latest 500 local records remain in bskulls_titanTopAttackDebugRecords.
 * UNIT_STATE also has a dedicated 960-record buffer so several launcher
 * carriers can be followed without the launcher optic evicting acquisition
 * history. Player sampled order transitions and scheduled followups use a
 * separate 960-record buffer for the same reason. Long events pass a compact
 * RPT projection; complete records remain in the local in-memory buffers.
 */

params [
    ["_projectile", objNull, [objNull]],
    ["_event", "", [""]],
    ["_details", [], [[]]],
    ["_traceId", "", [""]],
    ["_rptDetails", [], [[]]]
];

if !(localNamespace getVariable ["bskulls_titanTopAttackDebug", false]) exitWith {false};

if (_traceId isEqualTo "" && {!isNull _projectile}) then {
    _traceId = [
        _projectile,
        "trace-id",
        "untracked"
    ] call bskulls_fnc_titanTopAttackRuntimeGet;
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

private _isUnitState = _event isEqualTo "UNIT_STATE";
private _isOrderState = _event in [
    "ORDER_STATE",
    "ORDER_FOLLOWUP",
    "GROUP_COMMAND_CHANGED",
    "WEAPON_CHANGED"
];

// Unit and order events have dedicated buffers. Avoid retaining a second copy
// in the general projectile/event buffer.
if (!_isUnitState && {!_isOrderState}) then {
    private _records = localNamespace getVariable [
        "bskulls_titanTopAttackDebugRecords",
        []
    ];
    _records pushBack _record;
    if ((count _records) > 500) then {
        _records deleteAt 0;
    };
    localNamespace setVariable ["bskulls_titanTopAttackDebugRecords", _records];
};

if (_isUnitState) then {
    private _unitStateRecords = localNamespace getVariable [
        "bskulls_titanTopAttackUnitStateRecords",
        []
    ];
    _unitStateRecords pushBack _record;
    if ((count _unitStateRecords) > 960) then {
        _unitStateRecords deleteAt 0;
    };
    localNamespace setVariable [
        "bskulls_titanTopAttackUnitStateRecords",
        _unitStateRecords
    ];
};

if (_isOrderState) then {
    private _orderRecords = localNamespace getVariable [
        "bskulls_titanTopAttackOrderRecords",
        []
    ];
    _orderRecords pushBack _record;
    if ((count _orderRecords) > 960) then {
        _orderRecords deleteAt 0;
    };
    localNamespace setVariable [
        "bskulls_titanTopAttackOrderRecords",
        _orderRecords
    ];
};

private _rptRecord = +_record;
if (_rptDetails isNotEqualTo []) then {
    _rptRecord set [7, ["details", _rptDetails]];
};
diag_log format ["[BSKULLS][TITAN-TA] %1", _rptRecord];
if (
    hasInterface
    && {localNamespace getVariable ["bskulls_titanTopAttackDebugChat", false]}
) then {
    systemChat format ["Titan TA %1: %2", _traceId, _event];
};

true
