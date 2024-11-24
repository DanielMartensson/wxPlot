#pragma once

#include <wx/wx.h>
#include <vector>

/**
 * @brief Enum for various plot colors.
 *
 * This enum provides identifiers for a range of colors, categorized into basic colors,
 * pastel shades, earthy tones, modern colors, neutrals, and muted shades.
 */
typedef enum {
    // Grundläggande färger
    PLOT_COLOUR_RED,          ///< Red: A basic and vibrant primary color.
    PLOT_COLOUR_GREEN,        ///< Green: A basic primary color.
    PLOT_COLOUR_BLUE,         ///< Blue: A basic primary color.
    PLOT_COLOUR_YELLOW,       ///< Yellow: A bright secondary color.
    PLOT_COLOUR_CYAN,         ///< Cyan: A bright secondary color.
    PLOT_COLOUR_MAGENTA,      ///< Magenta: A bright secondary color.
    PLOT_COLOUR_BLACK,        ///< Black: A neutral and strong color.
    PLOT_COLOUR_WHITE,        ///< White: A neutral and bright color.

    // Pastellfärger
    PLOT_COLOUR_LIGHT_PINK,   ///< Light Pink: A pastel tone for soft designs.
    PLOT_COLOUR_LIGHT_BLUE,   ///< Light Blue: A pastel tone for calm visuals.
    PLOT_COLOUR_LIGHT_GREEN,  ///< Light Green: A pastel tone for fresh visuals.
    PLOT_COLOUR_LIGHT_YELLOW, ///< Light Yellow: A pastel tone for cheerful visuals.

    // Jordnära färger
    PLOT_COLOUR_BROWN,        ///< Brown: An earthy and natural color.
    PLOT_COLOUR_SIENNA,       ///< Sienna: An earthy and warm color.
    PLOT_COLOUR_PERU,         ///< Peru: An earthy and muted tone.
    PLOT_COLOUR_SADDLE_BROWN, ///< Saddle Brown: A rich earthy tone.

    // Moderna färger
    PLOT_COLOUR_TOMATO,       ///< Tomato Red: A vibrant and trendy color.
    PLOT_COLOUR_LIME,         ///< Lime Green: A vibrant and trendy green.
    PLOT_COLOUR_VIOLET,       ///< Violet: A trendy and modern purple.
    PLOT_COLOUR_HOT_PINK,     ///< Hot Pink: A trendy and bold pink.

    // Neutrala toner
    PLOT_COLOUR_DARK_GRAY,    ///< Dark Gray: A neutral and muted shade.
    PLOT_COLOUR_LIGHT_GRAY,   ///< Light Gray: A neutral and soft shade.
    PLOT_COLOUR_GRAY,         ///< Gray: A balanced neutral shade.

    // Dämpade färger
    PLOT_COLOUR_DARK_SLATE_GRAY, ///< Dark Slate Gray: A subdued and earthy shade.
    PLOT_COLOUR_DARK_SLATE_BLUE, ///< Dark Slate Blue: A rich and muted blue.
    PLOT_COLOUR_TEAL,            ///< Teal: A balanced mix of blue and green.
    PLOT_COLOUR_DARK_GREEN,      ///< Dark Green: A strong and natural shade.
    PLOT_COLOUR_DARK_ORANGE      ///< Dark Orange: A warm and vibrant tone.
} PLOT_COLOUR;

/**
 * @brief A collection of colors for use in plotting or visualization.
 *
 * This vector contains a mix of basic, pastel, earthy, trendy, and neutral colors.
 */
static std::vector<wxColour> plotColours = {
	wxColour(255, 0, 0),     ///< Red: A basic and vibrant primary color.
	wxColour(0, 255, 0),     ///< Green: A basic primary color.
	wxColour(0, 0, 255),     ///< Blue: A basic primary color.
	wxColour(255, 255, 0),   ///< Yellow: A bright secondary color.
	wxColour(0, 255, 255),   ///< Cyan: A bright secondary color.
	wxColour(255, 0, 255),   ///< Magenta: A bright secondary color.
	wxColour(0, 0, 0),       ///< Black: A neutral and strong color.
	wxColour(255, 255, 255), ///< White: A neutral and bright color.

	wxColour(255, 182, 193), ///< Light Pink: A pastel tone for soft designs.
	wxColour(173, 216, 230), ///< Light Blue: A pastel tone for calm visuals.
	wxColour(144, 238, 144), ///< Light Green: A pastel tone for fresh visuals.
	wxColour(255, 228, 181), ///< Light Yellow: A pastel tone for cheerful visuals.

	wxColour(139, 69, 19),   ///< Brown: An earthy and natural color.
	wxColour(160, 82, 45),   ///< Sienna: An earthy and warm color.
	wxColour(205, 133, 63),  ///< Peru: An earthy and muted tone.
	wxColour(160, 82, 45),   ///< Saddle Brown: A rich earthy tone.

	wxColour(255, 99, 71),   ///< Tomato Red: A vibrant and trendy color.
	wxColour(50, 205, 50),   ///< Lime Green: A vibrant and trendy green.
	wxColour(238, 130, 238), ///< Violet: A trendy and modern purple.
	wxColour(255, 105, 180), ///< Hot Pink: A trendy and bold pink.

	wxColour(169, 169, 169), ///< Dark Gray: A neutral and muted shade.
	wxColour(211, 211, 211), ///< Light Gray: A neutral and soft shade.
	wxColour(128, 128, 128), ///< Gray: A balanced neutral shade.

	wxColour(47, 79, 79),    ///< Dark Slate Gray: A subdued and earthy shade.
	wxColour(72, 61, 139),   ///< Dark Slate Blue: A rich and muted blue.
	wxColour(0, 128, 128),   ///< Teal: A balanced mix of blue and green.
	wxColour(0, 100, 0),     ///< Dark Green: A strong and natural shade.
	wxColour(255, 140, 0),   ///< Dark Orange: A warm and vibrant tone.
};