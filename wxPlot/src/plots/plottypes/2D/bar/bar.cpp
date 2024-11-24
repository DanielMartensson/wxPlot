#include "bar.hpp"
#include "../../../plottools/plottools.hpp"

void Bar::draw(wxDC& dc, const double value, const unsigned int dataSize, const unsigned int colourIndex, const size_t i) {

	// Some parameters
	const unsigned int gap = 5;
	const wxCoord width = (plotEndWidth - plotStartWidth) / dataSize - gap;
	wxCoord y0 = linearScalarYaxis(0, minY, plotStartHeight, maxY, plotEndHeight) - 1;

	// Saturation on y0
	if (y0 > plotEndHeight) {
		y0 = plotEndHeight;
	}
	if (y0 < plotStartHeight) {
		y0 = plotStartHeight;
	}

	// Head of the column
	wxCoord y = linearScalarYaxis(value, minY, plotStartHeight, maxY, plotEndHeight);

	// Position of the column
	const wxCoord x = plotStartWidth + (width + gap) * i;

	// Out of rectangle
	if (y <= plotStartHeight && y0 < plotStartHeight) {
		return;
	}

	// Saturation
	if (y < plotStartHeight) {
		y = plotStartHeight;
	}

	// Out of rectangle
	if (y >= plotEndHeight && y0 > plotEndHeight) {
		return;
	}

	// Saturation
	if (y >= plotEndHeight) {
		y = plotEndHeight - 1;
	}

	// Create the height
	const wxCoord height = y0 - y;

	// Set rectangle colour
	setColourPen(dc, colourIndex);
	setColourBrush(dc, colourIndex);

	// Draw the rectangle now
	dc.DrawRectangle(x + gap, y, width, height);
}