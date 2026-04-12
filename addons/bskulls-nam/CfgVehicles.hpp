_veh = createVehicle ["bo_app66_green",position player,[],0,"NONE"];
[
	_veh,
	["paint_green",1], 
	["lightcamo",1,"HideBeacon",0]
] call BIS_fnc_initVehicle;
[
	_veh,
	[
		["C_man_1","driver"]
	]
] call BIS_fnc_initVehicleCrew;

///


comment "Related vehicle classes:";
comment "B_Pickup_mmg_rf";
comment "B_T_Pickup_mmg_rf";
comment "EF_B_Pickup_mmg_MJTF_Des";
comment "EF_B_Pickup_mmg_MJTF_Wdl";

_veh = createVehicle ["B_Pickup_mmg_rf",position player,[],0,"NONE"];
[
	_veh,
	["Black",1], 
	["hide_trunk_cover",1,"hide_frame_full",0,"hide_bullbar",0,"hide_snorkel",0,"hide_antenna",1,"hide_trunk_door",0,"trunk_door_open",0,"hide_armor_window_armor_top",0,"window_armor_hatch_L_rot",1,"window_armor_hatch_R_rot",1,"door_F_L_open",0,"door_F_R_open",0,"door_R_L_open",0,"door_R_R_open",0,"hide_frame",0,"hide_sidesteps",0]
] call BIS_fnc_initVehicle;


///

comment "Related vehicle classes:";
comment "B_Pickup_aat_rf";
comment "B_T_Pickup_aat_rf";
comment "I_Pickup_aat_rf";
comment "I_E_Pickup_aat_rf";

_veh = createVehicle ["B_Pickup_aat_rf",position player,[],0,"NONE"];
[
	_veh,
	["NATO",1], 
	["hide_frame",1,"hide_frame_full",1,"hide_antenna",0,"hide_armor_window_armor_top",1,"hide_bullbar",0,"hide_snorkel",0,"hide_trunk_door",1,"trunk_door_open",0,"door_F_L_open",0,"door_F_R_open",0,"door_R_L_open",0,"door_R_R_open",0,"hide_rack",0,"hide_rack_spotlights",1,"hide_sidesteps",0]
] call BIS_fnc_initVehicle;


///

comment "Related vehicle classes:";
comment "B_UAV_RC40_SENSOR_RF";
comment "B_UAV_RC40_HE_RF";
comment "B_UAV_RC40_SmokeWhite_RF";
comment "B_UAV_RC40_SmokeBlue_RF";
comment "B_UAV_RC40_SmokeRed_RF";
comment "B_UAV_RC40_SmokeGreen_RF";
comment "B_UAV_RC40_SmokeOrange_RF";
comment "O_UAV_RC40_SENSOR_RF";
comment "O_UAV_RC40_HE_RF";
comment "O_UAV_RC40_SmokeWhite_RF";
comment "O_UAV_RC40_SmokeBlue_RF";
comment "O_UAV_RC40_SmokeRed_RF";
comment "O_UAV_RC40_SmokeGreen_RF";
comment "O_UAV_RC40_SmokeOrange_RF";
comment "I_UAV_RC40_SENSOR_RF";
comment "I_UAV_RC40_HE_RF";
comment "I_UAV_RC40_SmokeWhite_RF";
comment "I_UAV_RC40_SmokeBlue_RF";
comment "I_UAV_RC40_SmokeRed_RF";
comment "I_UAV_RC40_SmokeGreen_RF";
comment "I_UAV_RC40_SmokeOrange_RF";
comment "EF_B_LCC_MJTF_Des";
comment "EF_B_LCC_SideLoad_MJTF_Des";
comment "EF_B_LCC_MJTF_Wdl";
comment "EF_B_LCC_SideLoad_MJTF_Wdl";

_veh = createVehicle ["B_UAV_RC40_SENSOR_RF",position player,[],0,"NONE"];
[
	_veh,
	nil,
	["HideLegs",0]
] call BIS_fnc_initVehicle;
[
	_veh,
	[
		["B_UAV_AI","driver"],
		["B_UAV_AI","gunner",[0]]
	]
] call BIS_fnc_initVehicleCrew;
