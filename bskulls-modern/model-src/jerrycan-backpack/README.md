# Jerrycan backpack model

`bskulls_jerrycan_backpack.p3d` is the editable MLOD source for the runtime
model under `addons/bskulls-modern/models/`.

The model contains no copied BI mesh. It places a proxy to the vanilla
`CanisterFuel_F` model at `[0, 0.337, 0.235]` and weights the proxy to
`spine2`, allowing the prop to follow the character skeleton as a backpack.

Keep `model.cfg` beside the MLOD source when binarizing it with an Arma P3D
binarization tool.
