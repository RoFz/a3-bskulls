/*
 * Return the bounded countermeasure program for a Black Skulls aircraft.
 *
 * Navigation is deliberately left to the aircraft's active controller. DAO,
 * DRO support, Zeus, and vanilla AI can all own the flight plan, so issuing a
 * generic evasive doMove/flyInHeight command here would make those controllers
 * compete. The profiles instead vary dispense density and threat coverage by
 * aircraft role.
 *
 * Return value:
 * [name, interval, minimum activations, maximum activations,
 *  quiet tail, hard duration, cooldown]
 */

params [
    ["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle) exitWith {
    ["fallback", 0.5, 5, 9, 3, 7, 0.75]
};

switch true do {
    // Light attack helicopter: conserve its 60-round magazine while covering
    // the longer terminal phase seen in the Titan/Pawnee trace.
    case (_vehicle isKindOf "B_PTbskull_Veh_Helo_blackops_04"): {
        ["light-attack-helicopter", 0.55, 6, 9, 3.5, 7, 0.75]
    };

    // Dedicated attack helicopter: denser and longer than the Pawnee program;
    // the Blackfoot carries a substantially larger countermeasure magazine.
    case (_vehicle isKindOf "B_PTbskull_Veh_Helo_blackops_03"): {
        ["attack-helicopter", 0.45, 7, 12, 4, 8, 0.75]
    };

    // Heavy transport: it cannot rapidly change its energy state, so retain a
    // dense defensive screen for longer than the combat helicopters.
    case (_vehicle isKindOf "B_PTbskull_Veh_Helo_blackops_01"): {
        ["heavy-transport-helicopter", 0.4, 8, 14, 4.5, 9, 1]
    };

    // Fast fixed-wing aircraft need a shorter, denser program around the
    // missile's terminal phase rather than a helicopter-length sequence.
    case (_vehicle isKindOf "B_PTbskull_Veh_Plane_blackops_01"): {
        ["cas-jet", 0.3, 5, 9, 2.5, 5, 0.5]
    };

    // The Greyhawk is a comparatively slow and fragile propeller UAV.
    case (_vehicle isKindOf "B_PTbskull_Veh_Drone_blackops_01"): {
        ["propeller-uav", 0.5, 7, 12, 4, 8, 0.75]
    };

    // The Sentinel uses the shorter fixed-wing program.
    case (_vehicle isKindOf "B_PTbskull_Veh_Drone_blackops_04"): {
        ["ucav", 0.3, 5, 9, 2.5, 5, 0.5]
    };

    // Future or externally inherited rotary-wing UAVs get helicopter-length
    // coverage without assuming a particular mission controller.
    case (_vehicle isKindOf "Helicopter"): {
        ["generic-helicopter", 0.45, 7, 12, 4, 8, 0.75]
    };

    case (_vehicle isKindOf "Plane"): {
        ["generic-fixed-wing", 0.35, 5, 9, 2.5, 5, 0.5]
    };

    default {
        ["fallback", 0.5, 5, 9, 3, 7, 0.75]
    };
};
