#include "2Dtype.h"

void _2D_Type::setWxPlotType(const WXPLOT_TYPE wxPlotType) {
	this->wxPlotType = wxPlotType;
}

void _2D_Type::setRadius(const wxCoord radius) {
	scatter.setRadius(radius);
}

void _2D_Type::fillCircles(const bool fillCircle) {
	scatter.fillCircles(fillCircle);
}

void _2D_Type::setData(const std::vector<std::vector<double>>& data) {
	this->data = data;

	// Find max and min for the complete data, or else, we will get very weird scaling inside the plot
	double minX, maxX, minY, maxY;
	findMaxMin2Ddata(data, minX, maxX, minY, maxY);

	// Set the limits
	line.setLimits(minX, maxX, minY, maxY);
	scatter.setLimits(minX, maxX, minY, maxY);
	spline.setLimits(minX, maxX, minY, maxY);
}

void _2D_Type::setPlotStartWidth(const wxCoord plotStartWidth) {
	line.setPlotStartWidth(plotStartWidth);
	scatter.setPlotStartWidth(plotStartWidth);
	spline.setPlotStartWidth(plotStartWidth);
}

void _2D_Type::setPlotStartHeight(const wxCoord plotStartHeight) {
	line.setPlotStartHeight(plotStartHeight);
	scatter.setPlotStartHeight(plotStartHeight);
	spline.setPlotStartHeight(plotStartHeight);
}

void _2D_Type::setPlotEndWidth(const wxCoord plotEndWidth) {
	line.setPlotEndWidth(plotEndWidth);
	scatter.setPlotEndWidth(plotEndWidth);
	spline.setPlotEndWidth(plotEndWidth);
}

void _2D_Type::setPlotEndHeight(const wxCoord plotEndHeight) {
	line.setPlotEndHeight(plotEndHeight);
	scatter.setPlotEndHeight(plotEndHeight);
	spline.setPlotEndHeight(plotEndHeight);
}

bool _2D_Type::drawType(wxDC& dc) {
	// Get the size of the data
	const size_t dataSize = data.size();

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

			// Draw type now
			switch (wxPlotType) {
			case WXPLOT_TYPE_LINE:
				line.draw(dc, xData, yData, colourIndex);
				break;
			case WXPLOT_TYPE_SCATTER:
				scatter.draw(dc, xData, yData, colourIndex);
				break;
			case WXPLOT_TYPE_LINE_SCATTER:
				line.draw(dc, xData, yData, colourIndex);
				scatter.draw(dc, xData, yData, colourIndex);
				break;
			case WXPLOT_TYPE_SPLINE:
				spline.draw(dc, xData, yData, colourIndex);
				break;
			case WXPLOT_TYPE_SPLINE_SCATTER:
				spline.draw(dc, xData, yData, colourIndex);
				scatter.draw(dc, xData, yData, colourIndex);
				break;
			default:
				break;
			}

			// Change colour
			colourIndex++;
		}
	}
	else {
		return false;
	}

	return true;
}

