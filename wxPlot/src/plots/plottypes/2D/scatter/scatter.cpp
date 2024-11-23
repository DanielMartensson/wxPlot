
#include "scatter.h"
#include "../../../plottools/plottools.h"

bool Scatter::draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const int colourIndex) {
	// Fill circles
	if (fillCircle) {
		setColourBrush(dc, colourIndex);
	}

	// Set line colour
	setColourPen(dc, colourIndex);

	// Draw scatters
	const size_t dataLength = xData.size();
	for (size_t j = 0; j < dataLength; j++) {
		const wxCoord x = linearScalarXaxis(xData.at(j), minX, plotStartWidth, maxX, plotEndWidth);
		wxCoord y = linearScalarYaxis(yData.at(j), minY, plotStartHeight, maxY, plotEndHeight);

		// Out of rectangle
		if (y > plotEndHeight) {
			continue;
		}

		if (y < plotStartHeight) {
			continue;
		}

		dc.DrawCircle(x, y, radius);
	}

	// Nothing went wrong
	return true;
}
