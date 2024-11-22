
#include "line.h"
#include "../../../plottools/plottools.h"

bool Line::draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const int colourIndex) {
	// Set line colour
	setColourPen(dc, colourIndex);

	// Draw lines
	const size_t dataLength = xData.size();
	for (size_t j = 0; j < dataLength - 1; j++) {
		// Get coordinates
		wxCoord x1 = linearScalarXaxis(xData.at(j), minX, plotStartWidth, maxX, plotEndWidth);
		wxCoord y1 = linearScalarYaxis(yData.at(j), minY, plotStartHeight, maxY, plotEndHeight);
		wxCoord x2 = linearScalarXaxis(xData.at(j+1), minX, plotStartWidth, maxX, plotEndWidth);
		wxCoord y2 = linearScalarYaxis(yData.at(j+1), minY, plotStartHeight, maxY, plotEndHeight);
	
		// Limits
		if (x1 < plotStartWidth && x2 < plotStartWidth) {
			continue;
		}

		if (x1 > plotEndWidth && x2 > plotEndWidth) {
			continue;
		}

		if (y1 < plotStartHeight && y2 < plotStartHeight) {
			continue;
		}

		if (y1 > plotEndHeight && y2 > plotEndHeight) {
			continue;
		}

		if (x1 < plotStartWidth) {
			x1 = plotStartWidth;
		}

		if (x2 > plotEndWidth) {
			x2 = plotEndWidth;
		}

		if (y1 < plotStartHeight) {
			y1 = plotStartHeight;
		}

		if (y2 > plotEndHeight) {
			y2 = plotEndHeight;
		}

		dc.DrawLine(x1, y1, x2, y2);
	}

	// Nothing went wrong
	return true;
}
