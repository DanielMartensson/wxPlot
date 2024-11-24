
#include "line.hpp"
#include "../../../plottools/plottools.hpp"

void Line::setLimits(const double minX, const double maxX, const double minY, const double maxY) { 
	this->minX = minX; 
	this->maxX = maxX; 
	this->minY = minY; 
	this->maxY = maxY; 
}

void Line::setPlotStartWidth(const wxCoord plotStartWidth) { 
	this->plotStartWidth = plotStartWidth;
}

void Line::setPlotStartHeight(const wxCoord plotStartHeight) { 
	this->plotStartHeight = plotStartHeight; 
}

void Line::setPlotEndWidth(const wxCoord plotEndWidth) { 
	this->plotEndWidth = plotEndWidth; 
}

void Line::setPlotEndHeight(const wxCoord plotEndHeight) { 
	this->plotEndHeight = plotEndHeight; 
}

bool Line::draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const unsigned int colourIndex) {
	// Set line colour
	setColourPen(dc, colourIndex);

	// Draw lines
	const size_t dataLength = xData.size();
	for (size_t j = 0; j < dataLength - 1; j++) {
		// Get coordinates
		const wxCoord x1 = linearScalarXaxis(xData.at(j), minX, plotStartWidth, maxX, plotEndWidth);
		wxCoord y1 = linearScalarYaxis(yData.at(j), minY, plotStartHeight, maxY, plotEndHeight);
		const wxCoord x2 = linearScalarXaxis(xData.at(j+1), minX, plotStartWidth, maxX, plotEndWidth);
		wxCoord y2 = linearScalarYaxis(yData.at(j+1), minY, plotStartHeight, maxY, plotEndHeight);
		
		// Out of rectangle
		if (y1 <= plotStartHeight && y2 <= plotStartHeight) {
			continue;
		}

		if (y1 >= plotEndHeight && y2 >= plotEndHeight) {
			continue;
		}

		// Saturation
		if (y2 >= plotEndHeight) {
			y2 = plotEndHeight - 1;
		}

		if (y1 <= plotStartHeight) {
			y1 = plotStartHeight + 1;
		}

		if (y1 >= plotEndHeight) {
			y1 = plotEndHeight - 1;
		}

		if (y2 <= plotStartHeight) {
			y2 = plotStartHeight + 1;
		}

		dc.DrawLine(x1, y1, x2, y2);
	
	}

	// Nothing went wrong
	return true;
}
