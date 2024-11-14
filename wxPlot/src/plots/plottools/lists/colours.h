#pragma once

#include <wx/wx.h>
#include <vector>

typedef enum {
	// Grundläggande färger
	PLOT_COLOUR_RED,
	PLOT_COLOUR_GREEN,
	PLOT_COLOUR_BLUE,
	PLOT_COLOUR_YELLOW,
	PLOT_COLOUR_CYAN,
	PLOT_COLOUR_MAGENTA,
	PLOT_COLOUR_BLACK,
	PLOT_COLOUR_WHITE,

	// Pastellfärger
	PLOT_COLOUR_LIGHT_PINK,
	PLOT_COLOUR_LIGHT_BLUE,
	PLOT_COLOUR_LIGHT_GREEN,
	PLOT_COLOUR_LIGHT_YELLOW,

	// Jordnära färger
	PLOT_COLOUR_BROWN,
	PLOT_COLOUR_SIENNA,
	PLOT_COLOUR_PERU,
	PLOT_COLOUR_SADDLE_BROWN,

	// Moderna färger
	PLOT_COLOUR_TOMATO,
	PLOT_COLOUR_LIME,
	PLOT_COLOUR_VIOLET,
	PLOT_COLOUR_HOT_PINK,

	// Neutrala toner
	PLOT_COLOUR_DARK_GRAY,
	PLOT_COLOUR_LIGHT_GRAY,
	PLOT_COLOUR_GRAY,

	// Dämpade färger
	PLOT_COLOUR_DARK_SLATE_GRAY,
	PLOT_COLOUR_DARK_SLATE_BLUE,
	PLOT_COLOUR_TEAL,
	PLOT_COLOUR_DARK_GREEN,
	PLOT_COLOUR_DARK_ORANGE
}PLOT_COLOUR;

static std::vector<wxColour> plotColours = {
	// Grundläggande färger
	wxColour(255, 0, 0),     // Röd
	wxColour(0, 255, 0),     // Grön
	wxColour(0, 0, 255),     // Blå
	wxColour(255, 255, 0),   // Gul
	wxColour(0, 255, 255),   // Cyan
	wxColour(255, 0, 255),   // Magenta
	wxColour(0, 0, 0),       // Svart
	wxColour(255, 255, 255), // Vit

	// Färger med pastelltoner
	wxColour(255, 182, 193), // Ljusrosa
	wxColour(173, 216, 230), // Ljusblå
	wxColour(144, 238, 144), // Ljusgrön
	wxColour(255, 228, 181), // Ljusgul

	// Jordnära färger
	wxColour(139, 69, 19),  // Brun
	wxColour(160, 82, 45),   // Sienna
	wxColour(205, 133, 63),  // Peru
	wxColour(160, 82, 45),   // Saddle Brown

	// Färger för trendiga och moderna nyanser
	wxColour(255, 99, 71),   // Tomatröd
	wxColour(50, 205, 50),   // Limegrön
	wxColour(238, 130, 238), // Lila
	wxColour(255, 105, 180), // Hot pink

	// Ljus och mörka neutrala färger
	wxColour(169, 169, 169), // Mörkgrå
	wxColour(211, 211, 211), // Ljusgrå
	wxColour(128, 128, 128), // Grå

	// Mer dämpade färger
	wxColour(47, 79, 79),    // Dark Slate Gray
	wxColour(72, 61, 139),   // Dark Slate Blue
	wxColour(0, 128, 128),   // Teal
	wxColour(0, 100, 0),     // Dark Green
	wxColour(255, 140, 0),   // Dark Orange
};