#include "bar.h"
#include "../../../plottools/plottools.h"

bool Bar::draw(wxDC& dc, const double yData, const int colourIndex, const size_t dataSize, const size_t i) {
	// Set rectangle colour
	setColourPen(dc, colourIndex);
	setColourBrush(dc, colourIndex);

	// Some parameter
	const wxCoord width = (plotEndWidth - plotStartWidth) / dataSize;

	// Draw rectangle
	const wxCoord x = plotStartWidth + width * i;
	const wxCoord y = linearScalarYaxis(yData, minY, plotStartHeight, maxY, plotEndHeight);
	const wxCoord y0 = linearScalarYaxis(0, minY, plotStartHeight, maxY, plotEndHeight);
	const wxCoord yMin = linearScalarYaxis(minY, minY, plotStartHeight, maxY, plotEndHeight);
	const wxCoord delta = yMin - y0;
	const wxCoord height = plotEndHeight - y - delta;
	dc.DrawRectangle(x, y, width, height);
	
	// Nothing went wrong
	return true;
}