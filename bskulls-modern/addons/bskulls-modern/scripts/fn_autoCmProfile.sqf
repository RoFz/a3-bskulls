/*
 * Return the bounded countermeasure program for a Black Skulls aircraft.
 *
 * Navigation is deliberately left to the aircraft's active controller. DAO,
 * DRO support, Zeus, and vanilla AI can all own the flight plan, so issuing a
 * generic evasive doMove/flyInHeight command here would make those controllers
 * compete. The profiles instead vary dispense density and threat coverage by
 * aircraft role.
 *
 * The first seven values retain the bounded fallback program used when an
 * IncomingMissile event does not provide a live projectile. The final three
 * values bound and tune live threat tracking. Bohemia documents guidance
 * compatibility and cmImmunity, but not a deployment cadence; these time
 * bands are conservative gameplay defaults exposed in diagnostics for
 * controlled in-game validation.
 *
 * Return value:
 * [name, terminal interval, fallback minimum activations,
 *  maximum attempts per threat, quiet tail, fallback duration, cooldown,
 *  approach time, terminal time, maximum threat tracking duration]
 */

params [
    ["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle) exitWith {
    ["fallback", 0.5, 5, 9, 3, 7, 0.75, 8, 4, 45]
};

switch true do {
    // Light attack helicopter: conserve its 60-round magazine while covering
    // the longer terminal phase seen in the Titan/Pawnee trace.
    case (_vehicle isKindOf "B_PTbskull_Veh_Helo_blackops_04"): {
        ["light-attack-helicopter", 0.55, 6, 9, 3.5, 7, 0.75, 8, 4, 45]
    };

    // Dedicated attack helicopter: denser and longer than the Pawnee program;
    // the Blackfoot carries a substantially larger countermeasure magazine.
    case (_vehicle isKindOf "B_PTbskull_Veh_Helo_blackops_03"): {
        ["attack-helicopter", 0.45, 7, 12, 4, 8, 0.75, 8, 4, 45]
    };

    // Heavy transport: it cannot rapidly change its energy state, so retain a
    // dense defensive screen for longer than the combat helicopters.
    case (_vehicle isKindOf "B_PTbskull_Veh_Helo_blackops_01"): {
        ["heavy-transport-helicopter", 0.4, 8, 14, 4.5, 9, 1, 10, 5, 50]
    };

    // Fast fixed-wing aircraft need a shorter, denser program around the
    // missile's terminal phase rather than a helicopter-length sequence.
    case (_vehicle isKindOf "B_PTbskull_Veh_Plane_blackops_01"): {
        ["cas-jet", 0.3, 5, 9, 2.5, 5, 0.5, 6, 3, 40]
    };

    // The Greyhawk is a comparatively slow and fragile propeller UAV.
    case (_vehicle isKindOf "B_PTbskull_Veh_Drone_blackops_01"): {
        ["propeller-uav", 0.5, 7, 12, 4, 8, 0.75, 9, 4.5, 45]
    };

    // The Sentinel uses the shorter fixed-wing program.
    case (_vehicle isKindOf "B_PTbskull_Veh_Drone_blackops_04"): {
        ["ucav", 0.3, 5, 9, 2.5, 5, 0.5, 6, 3, 40]
    };

    // Future or externally inherited rotary-wing UAVs get helicopter-length
    // coverage without assuming a particular mission controller.
    case (_vehicle isKindOf "Helicopter"): {
        ["generic-helicopter", 0.45, 7, 12, 4, 8, 0.75, 8, 4, 45]
    };

    case (_vehicle isKindOf "Plane"): {
        ["generic-fixed-wing", 0.35, 5, 9, 2.5, 5, 0.5, 6, 3, 40]
    };

    default {
        ["fallback", 0.5, 5, 9, 3, 7, 0.75, 8, 4, 45]
    };
};
