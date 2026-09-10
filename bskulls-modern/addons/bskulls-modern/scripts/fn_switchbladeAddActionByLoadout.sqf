/*
    Keep Switchblade deployment in the action menu without repeatedly
    presenting it in the middle of the screen.

    The upstream function owns item discovery, ACE integration, deployment,
    and action cleanup. Run that implementation unchanged, then normalize only
    the vanilla addAction showWindow parameter.

    References:
    - https://community.bistudio.com/wiki/addAction
    - https://community.bistudio.com/wiki/actionParams
*/

if (isNil "bskulls_switchbladeOriginalAddActionByLoadout") then {
    bskulls_switchbladeOriginalAddActionByLoadout = compile preprocessFileLineNumbers
        "\switchblade\functions\util\fn_addActionByLoadout.sqf";
};

_this call bskulls_switchbladeOriginalAddActionByLoadout;

// Switchblade already uses ACE self-actions when ACE is present.
if (isClass (configFile >> "CfgPatches" >> "ace_main")) exitWith {};

{
    private _variableName = _x;
    if (
        "switchblade_" in _variableName
        && {"_action" in _variableName}
    ) then {
        private _actionId = player getVariable [_variableName, -1];
        if (_actionId >= 0) then {
            private _actionParameters = player actionParams _actionId;
            if (
                count _actionParameters >= 8
                && {_actionParameters select 4}
            ) then {
                player removeAction _actionId;
                _actionParameters set [4, false];

                private _replacementId = player addAction
                    (_actionParameters select [0, 8]);
                player setVariable [_variableName, _replacementId];
            };
        };
    };
} forEach allVariables player;
