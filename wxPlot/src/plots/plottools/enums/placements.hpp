#pragma once

/**
 * @brief Enum representing placement options for an item.
 *
 * This enum defines the different placement positions for an item, such as in a grid or on a coordinate system.
 */
typedef enum {
    PLACEMENT_NORTH_WEST, ///< North-west placement
    PLACEMENT_NORTH_EAST, ///< North-east placement
    PLACEMENT_SOUTH_WEST, ///< South-west placement
    PLACEMENT_SOUTH_EAST, ///< South-east placement
    PLACEMENT_CENTRE      ///< Centre placement
} PLACEMENT;