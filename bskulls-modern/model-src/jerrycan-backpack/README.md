# Jerrycan backpack model

`bskulls_jerrycan_backpack.p3d` is the retired editable MLOD experiment for
the jerrycan backpack.

The model contains no copied BI mesh. It places a proxy to the vanilla
`CanisterFuel_F` model at `[0, 0.337, 0.235]` and weights the proxy to
`spine2`.

The legacy `armake` P3D converter retains the proxy and skeleton data but the
resulting nested proxy does not receive the character's torso transform when
the model is worn. The runtime backpack therefore uses
`\A3\Weapons_F\empty.p3d` as its carrier model.

`fn_initJerrycanBackpackVisual.sqf` attaches a client-local vanilla canister to
the wearer's `spine3` memory point. The configured backpack remains the real
inventory and fuel container.

If this model is regenerated, retain the complete 103-bone
`OFP2_ManSkeleton`. Each weighted LOD currently contains only bone 3
(`spine2`) in its sub-skeleton and declares a one-bone section. Do not use
legacy `armake` output without inspecting these fields: its upstream
documentation describes P3D conversion as incomplete, and its default output
expands every LOD section to all 103 bones.
