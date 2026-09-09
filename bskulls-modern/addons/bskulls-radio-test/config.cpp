/*
    Experimental interception test for native AI enemy-contact reports.

    The engine asks SelectEnemyDetectedSentence to choose a radio sentence
    after an AI group reports a contact.  Returning no candidates should stop
    only that generated sentence while leaving target knowledge, datalink, AI
    features, orders, acknowledgements, and every other protocol class intact.

    This is deliberately a separate PBO.  Keep it experimental until an
    in-game RPT confirms both the suppression and the unaffected radio paths.
*/

class CfgPatches
{
    class bskulls_radio_enemy_report_test
    {
        name = "Black Skulls native enemy-report interception test";
        author = "RoFz";
        requiredVersion = 2.00;
        requiredAddons[] =
        {
            "A3_Dubbing_Radio_F",
            "A3_Dubbing_Radio_F_EXP",
            "rhsusf_c_radio",
            "bskull_fc_mo"
        };
        units[] = {};
        weapons[] = {};
    };
};

class CfgFunctions
{
    class BSK_RadioTest
    {
        tag = "BSK_RadioTest";
        class diagnostics
        {
            file = "\bskulls\addons\bskulls-radio-test\functions";
            class init
            {
                postInit = 1;
            };
        };
    };
};

// These are external base classes supplied by the required radio addons.
// Retaining each protocol's original parent is essential: redefining an
// existing class without it resets the parent to nothing in the master config.
class RadioProtocolBase;
class RadioProtocolBaseFemale;

class RadioProtocolENG: RadioProtocolBase
{
    class SelectEnemyDetectedSentence
    {
        sentences[] = {};
    };
};

class RadioProtocolGRE: RadioProtocolBase
{
    class SelectEnemyDetectedSentence
    {
        sentences[] = {};
    };
};

class RadioProtocolCHI: RadioProtocolBase
{
    class SelectEnemyDetectedSentence
    {
        sentences[] = {};
    };
};

class RadioProtocolFemaleENG: RadioProtocolBaseFemale
{
    class SelectEnemyDetectedSentence
    {
        sentences[] = {};
    };
};
