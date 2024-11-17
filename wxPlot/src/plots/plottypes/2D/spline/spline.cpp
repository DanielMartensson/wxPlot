
#include "spline.h"
#include "../../../plottools/plottools.h"

bool Spline::draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const int colourIndex) {
	// Set line colour
	setColourPen(dc, colourIndex);

	// Load splines
	const size_t dataLength = xData.size();
	std::vector<wxPoint> points = std::vector<wxPoint>();
	for (size_t j = 0; j < dataLength; j++) {
		const wxCoord x = linearScalarXaxis(xData.at(j), minX, plotStartWidth, maxX, plotEndWidth);
		const wxCoord y = linearScalarYaxis(yData.at(j), minY, plotStartHeight, maxY, plotEndHeight);
		wxPoint point(x, y);
		points.push_back(point);
	}

	// Draw splines
	dc.DrawSpline(dataLength, points.data());

	// Nothing went wrong
	return true;
}
