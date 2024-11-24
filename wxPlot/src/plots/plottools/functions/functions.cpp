#include "functions.h"
#include <wx/wx.h>
#include <cmath>

/*
 * This function finds the least minimum value and most maximum value from the 1D data vector
 */
void findMaxMin1Ddata(const std::vector<double>& data1D, double& minLimit, double& maxLimit) {
	minLimit = data1D.at(0);
	maxLimit = data1D.at(0);
	const size_t dataLength = data1D.size();
	for (size_t i = 1; i < dataLength; i++) {
		if (data1D.at(i) < minLimit) {
			minLimit = data1D.at(i);
		}
		if (data1D.at(i) > maxLimit) {
			maxLimit = data1D.at(i);
		}
	}
}

/*
 * This function re-scale the number "value", within oldMinLimit and oldMaxLimit, to a new limit newMinLimit and newMaxLimit in X-axis
 */
double linearScalarXaxis(const double value, const double oldMinLimit, const double newMinLimit, const double oldMaxLimit, const double newMaxLimit) {
	return newMinLimit + ((value - oldMinLimit) / (oldMaxLimit - oldMinLimit)) * (newMaxLimit - newMinLimit);
}


/*
 * This function re-scale the number "value", within oldMinLimit and oldMaxLimit, to a new limit newMinLimit and newMaxLimit in Y-axis
 */
double linearScalarYaxis(const double value, const double oldMinLimit, const double newMinLimit, const double oldMaxLimit, const double newMaxLimit) {
	return newMaxLimit - ((value - oldMinLimit) / (oldMinLimit - oldMaxLimit)) * (newMinLimit - newMaxLimit);
}

/*
 * This function check if we have both X-axis and Y-axis by checking modulus 2
 */
bool check2DdataSize(const std::vector<std::vector<double>>& data2D) {
	// Check the size
	const size_t dataSize = data2D.size();
	if (dataSize % 2 != 0) {
		return false; // Missing an axis
	}

	// Check if X-axis and Y-axis have the same length
	for (size_t i = 0; i < dataSize; i += 2) {
		// Get data
		const std::vector<double> xData = data2D.at(i);
		const std::vector<double> yData = data2D.at(i + 1);

		// Get length of them both
		const size_t xDataLength = xData.size();
		const size_t yDataLength = yData.size();

		// If they are not the same length - Return false
		if (xDataLength != yDataLength) {
			return false;
		}
	}

	return true; // No missing axis
}

/*
 * This function finds the least minimum value and most maximum value from the 2D data vector
 */
void findMaxMin2Ddata(const std::vector<std::vector<double>>& data2D, double& minX, double& maxX, double& minY, double& maxY) {
	const size_t dataSize = data2D.size();
	for (size_t i = 0; i < dataSize; i += 2) {
		const std::vector<double> xData = data2D.at(i);
		double minLimit, maxLimit;
		findMaxMin1Ddata(xData, minLimit, maxLimit);
		if (i == 0) {
			minX = minLimit;
			maxX = maxLimit;
		}
		else {
			if (minLimit < minX) {
				minX = minLimit;
			}
			if (maxLimit > maxX) {
				maxX = maxLimit;
			}
		}

		const std::vector<double> yData = data2D.at(i + 1);
		findMaxMin1Ddata(yData, minLimit, maxLimit);
		if (i == 0) {
			minY = minLimit;
			maxY = maxLimit;
		}
		else {
			if (minLimit < minY) {
				minY = minLimit;
			}
			if (maxLimit > maxY) {
				maxY = maxLimit;
			}
		}
	}
}

std::vector<double> createHistogramData(const std::vector<double>& data1D, const double minY, const double maxY, const unsigned int binCount) {
	std::vector<double> yData(binCount + 1, 0.0);
	for (const auto& value : data1D) {
		const unsigned int index = std::round(linearScalarXaxis(value, minY, 0, maxY, binCount));
		yData.at(index) += 1.0;
	}
	return yData;
}

void setColourPen(wxDC& dc, const int penColour) {
	wxColour colour = penColour < plotColours.size() ? plotColours.at(penColour) : plotColours.at(PLOT_COLOUR_BLACK);
	wxPen pen(colour);
	dc.SetPen(pen);
}

void setColourBrush(wxDC& dc, const int brushColour) {
	wxColour colour = brushColour < plotColours.size() ? plotColours.at(brushColour) : plotColours.at(PLOT_COLOUR_BLACK);
	wxBrush brush(colour);
	dc.SetBrush(brush);
}

void setColourText(wxDC& dc, const int textColour, const int backgroundColour) {
	wxColour background = backgroundColour < plotColours.size() ? plotColours.at(backgroundColour) : plotColours.at(PLOT_COLOUR_BLACK);
	wxColour text = textColour < plotColours.size() ? plotColours.at(textColour) : plotColours.at(PLOT_COLOUR_BLACK);
	dc.SetTextForeground(text);
	dc.SetTextBackground(background);
}