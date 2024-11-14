
#include "line.h"
#include "../../../plottools/plottools.h"

bool Line::draw(wxDC& dc) {
	// Get the size of the data
	const size_t dataSize = data.size();

	// Find max and min for the complete data, or else, we will get very weird scaling inside the plot
	double minX, maxX, minY, maxY;
	findMaxMin2Ddata(data, minX, maxX, minY, maxY);

	// We must have at least double(2). One for X-axis and one for Y-axis
	if (check2DdataSize(data)) {
		// Create a line plot
		int colourIndex = 0;
		for (size_t i = 0; i < dataSize; i += 2) {
			// Get data
			const std::vector<double> xData = data.at(i);
			const std::vector<double> yData = data.at(i + 1);

			// Get length of them both
			const size_t xDataLength = xData.size();
			const size_t yDataLength = yData.size();

			// If they are not the same length - Return false
			if (xDataLength != yDataLength) {
				return false;
			}

			// Set line colour
			setColourPen(dc, colourIndex++);

			// Draw lines
			for (size_t j = 0; j < xDataLength - 1; j++) {
				const wxCoord x1 = linearScalarXaxis(xData.at(j), minX, plotStartWidth, maxX, plotEndWidth);
				const wxCoord y1 = linearScalarYaxis(yData.at(j), minY, plotStartHeight, maxY, plotEndHeight);
				const wxCoord x2 = linearScalarXaxis(xData.at(j+1), minX, plotStartWidth, maxX, plotEndWidth);
				const wxCoord y2 = linearScalarYaxis(yData.at(j+1), minY, plotStartHeight, maxY, plotEndHeight);
				dc.DrawLine(x1, y1, x2, y2);
			}
		}
	}

	return true;
}
