// DEPRECATED for DRO RoFz.
// Identity/traits: unit inits → bskulls_fnc_applyOperatorIdentity.
// Support kit + hangar air: DRO mission
//   sunday_system/player_setup/bskulls_dro_injectAssets.sqf
//   (auto-run after Ready via fileExists; do not exec this file.)
//
// Manual fallback if you need inject without the mission hook:
//   if (fileExists "sunday_system\player_setup\bskulls_dro_injectAssets.sqf") then {
//       [] execVM "sunday_system\player_setup\bskulls_dro_injectAssets.sqf";
//   };

systemChat "Set-Team-Members-FacesandVoices.sqf is retired for DRO — use mission inject script.";
