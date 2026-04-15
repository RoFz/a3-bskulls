class CfgUnitInsignia {
    class Black_Skulls {
        displayName="Black Skulls Insignia";
        author="RoFz";
        texture="\bskulls-modern\textures\black_skulls_insig_128_128.paa";
        material = "\A3\Ui_f\data\GUI\Cfg\UnitInsignia\default_insignia.rvmat";
        // BUG: textureVehicle is unimplemented in the A3 engine — vehicle hull decals (hood, doors) never apply regardless of value.
        // For vehicle surface markings use hiddenSelectionsTextures in CfgVehicles instead.
        // textureVehicle="";
        scope = 2;
    };
};
