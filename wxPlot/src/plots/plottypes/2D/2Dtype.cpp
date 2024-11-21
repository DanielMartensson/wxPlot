#include "2Dtype.h"

void _2DType::setWxPlotType(const WXPLOT_TYPE wxPlotType) {
	this->wxPlotType = wxPlotType;
}

void _2DType::setRadius(const wxCoord radius) {
	scatter.setRadius(radius);
}

void _2DType::fillCircles(const bool fillCircle) {
	scatter.fillCircles(fillCircle);
}

void _2DType::setData(const std::vector<std::vector<double>>& data2D) {
	this->data2D = data2D;
	this->isUsed2D = true;

	// Find max and min for the complete data, or else, we will get very weird scaling inside the plot
	findMaxMin2Ddata(data2D, minX, maxX, minY, maxY);

	// Set the limits
	line.setLimits(minX, maxX, minY, maxY);
	scatter.setLimits(minX, maxX, minY, maxY);
	spline.setLimits(minX, maxX, minY, maxY);
	bar.setLimits(minX, maxX, minY, maxY);
}

void _2DType::setData(const std::vector<double>& data1D) {
	this->data1D = data1D;
	this->isUsed2D = false;

	// Find max and min for the complete data, or else, we will get very weird scaling inside the plot
	minX = 0;
	maxX = data1D.size();
	findMaxMin1Ddata(data1D, minY, maxY);

	// Set the limits
	line.setLimits(minX, maxX, minY, maxY);
	scatter.setLimits(minX, maxX, minY, maxY);
	spline.setLimits(minX, maxX, minY, maxY);
	bar.setLimits(minX, maxX, minY, maxY);
}

void _2DType::setYlim(const double minY, const double maxY) {

	// Find max and min for the complete data, or else, we will get very weird scaling inside the plot
	if (isUsed2D) {
		findMaxMin2Ddata(data2D, minX, maxX, this->minY, this->maxY);
	}
	else {
		minX = 0;
		maxX = data1D.size();
		findMaxMin1Ddata(data1D, this->minY, this->maxY);
	}

	// Set the limits, by using minY and maxY
	line.setLimits(minX, maxX, minY, maxY);
	scatter.setLimits(minX, maxX, minY, maxY);
	spline.setLimits(minX, maxX, minY, maxY);
	bar.setLimits(minX, maxX, minY, maxY);
}

void _2DType::setPlotStartWidth(const wxCoord plotStartWidth) {
	line.setPlotStartWidth(plotStartWidth);
	scatter.setPlotStartWidth(plotStartWidth);
	spline.setPlotStartWidth(plotStartWidth);
	bar.setPlotStartWidth(plotStartWidth);
}

void _2DType::setPlotStartHeight(const wxCoord plotStartHeight) {
	line.setPlotStartHeight(plotStartHeight);
	scatter.setPlotStartHeight(plotStartHeight);
	spline.setPlotStartHeight(plotStartHeight);
	bar.setPlotStartHeight(plotStartHeight);
}

void _2DType::setPlotEndWidth(const wxCoord plotEndWidth) {
	line.setPlotEndWidth(plotEndWidth);
	scatter.setPlotEndWidth(plotEndWidth);
	spline.setPlotEndWidth(plotEndWidth);
	bar.setPlotEndWidth(plotEndWidth);
}

void _2DType::setPlotEndHeight(const wxCoord plotEndHeight) {
	line.setPlotEndHeight(plotEndHeight);
	scatter.setPlotEndHeight(plotEndHeight);
	spline.setPlotEndHeight(plotEndHeight);
	bar.setPlotEndHeight(plotEndHeight);
}

bool _2DType::drawType(wxDC& dc) {

	// We must have at least double(2). One for X-axis and one for Y-axis
	if (isUsed2D) {
		// Check
		if (!check2DdataSize(data2D)) {
			return false;
		}

		// Create counter for colour
		int colourIndex = 0;

		// Get the size of the data
		const size_t dataSize = data2D.size();

		for (size_t i = 0; i < dataSize; i += 2) {
			// Get data
			const std::vector<double> xData = data2D.at(i);
			const std::vector<double> yData = data2D.at(i + 1);

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
	else{

		// Draw type now
		switch (wxPlotType) {
		case WXPLOT_TYPE_BAR:
			bar.draw(dc, data1D);
			break;
		default:
			break;
		}
	}

	return true;
}

