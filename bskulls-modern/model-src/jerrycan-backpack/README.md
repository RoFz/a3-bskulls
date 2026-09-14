# Jerrycan backpack model

`bskulls_jerrycan_backpack.p3d` is the editable MLOD source for the runtime
model under `addons/bskulls-modern/models/`.

The model contains no copied BI mesh. It places a proxy to the vanilla
`CanisterFuel_F` model at `[0, 0.337, 0.235]` and weights the proxy to
`spine2`, allowing the prop to follow the character skeleton as a backpack.

Keep `model.cfg` beside the MLOD source when binarizing it with an Arma P3D
binarization tool.

The binarized ODOL must retain the complete 103-bone `OFP2_ManSkeleton`, but
each weighted LOD must contain only bone 3 (`spine2`) in its sub-skeleton and
declare a one-bone section. This is how the proxy receives the character's
torso transform while avoiding an incompatible embedded skeleton. Do not use
the legacy `armake` P3D output without checking these fields: its upstream
documentation describes P3D conversion as incomplete, and its default output
expands every LOD section to all 103 bones.
