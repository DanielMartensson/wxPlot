#include "bar.h"
#include "../../../plottools/plottools.h"

bool Bar::draw(wxDC& dc, const double yData, const int colourIndex, const size_t dataSize, const size_t i) {
	// Set rectangle colour
	setColourPen(dc, colourIndex);
	setColourBrush(dc, colourIndex);

	// Some parameter
	const wxCoord width = (plotEndWidth - plotStartWidth) / dataSize;	
	const wxCoord x = plotStartWidth + width * i;
	wxCoord y = linearScalarYaxis(yData, minY, plotStartHeight, maxY, plotEndHeight);
	const wxCoord y0 = linearScalarYaxis(0, minY, plotStartHeight, maxY, plotEndHeight);
	const wxCoord yMin = linearScalarYaxis(minY, minY, plotStartHeight, maxY, plotEndHeight);
	wxCoord height = 0;
	if (minY < 0 && yData < 0) {
		y = y0;
		height = yMin - y;
	}
	else if(minY < 0 && yData >= 0){
		height = y0 - y;
	}
	else if (minY >= 0 && yData >= 0) {
		height = yMin - y;
	}

	// Draw the rectangle now
	dc.DrawRectangle(x, y, width, height);

	// Nothing went wrong
	return true;
}