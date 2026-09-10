// Preserve the complete stock Titan HUD. Archangel changes only the TOP/DIR
// lamp tint after the display has loaded; redefining the nested controls here
// would replace inherited control data supplied by A3_Ui_F.
class RscInGameUI
{
    class RscOptics_titan;

    class B_PTbskull_RscOptics_Archangel : RscOptics_titan
    {
        onLoad = "_this call bskulls_fnc_titanTopAttackOpticLoad;";
    };
};
