#include "bar.h"
#include "../../../plottools/plottools.h"

bool Bar::draw(wxDC& dc, const double yData, const int colourIndex, const size_t dataSize, const size_t i) {
	// Set rectangle colour
	setColourPen(dc, colourIndex);
	setColourBrush(dc, colourIndex);

	// Some parameters
	const unsigned int gap = 5;
	const wxCoord width = (plotEndWidth - plotStartWidth) / dataSize - gap;
	const wxCoord x = plotStartWidth + (width + gap) * i;
	wxCoord y = linearScalarYaxis(yData, minY, plotStartHeight, maxY, plotEndHeight);
	wxCoord y0 = linearScalarYaxis(0, minY, plotStartHeight, maxY, plotEndHeight) - 1;

	// Limit on y0
	if (y0 > plotEndHeight) {
		y0 = plotEndHeight;
	}
	if (y0 < plotStartHeight) {
		y0 = plotStartHeight;
	}

	// If we are under the data
	if (y <= plotStartHeight && y0 < plotStartHeight) {
		return true;
	}

	// If we cut inside the data
	if (y < plotStartHeight) {
		y = plotStartHeight;
	}

	// If we are above the data
	if (y >= plotEndHeight && y0 > plotEndHeight) {
		return true;
	}

	// If we cut inside the data
	if (y >= plotEndHeight) {
		y = plotEndHeight - 1;
	}

	// Create the height
	const wxCoord height = y0 - y;

	// Draw the rectangle now
	dc.DrawRectangle(x + gap, y, width, height); 

	// Nothing went wrong
	return true;
}