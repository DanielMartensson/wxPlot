#include "functions.h"
#include <wx/wx.h>


void maxMinData(const std::vector<double>& data, double& minLimit, double& maxLimit) {
	minLimit = data.at(0);
	maxLimit = data.at(0);
	const size_t dataLength = data.size();
	for (size_t i = 1; i < dataLength; i++) {
		if (data.at(i) < minLimit) {
			minLimit = data.at(i);
		}
		if (data.at(i) > maxLimit) {
			maxLimit = data.at(i);
		}
	}
}

double linearScalarXaxis(const double value, const double oldMinLimit, const double newMinLimit, const double oldMaxLimit, const double newMaxLimit) {
	return newMinLimit + ((value - oldMinLimit) / (oldMaxLimit - oldMinLimit)) * (newMaxLimit - newMinLimit);
}

double linearScalarYaxis(const double value, const double oldMinLimit, const double newMinLimit, const double oldMaxLimit, const double newMaxLimit) {
	return newMaxLimit - ((value - oldMinLimit) / (oldMinLimit - oldMaxLimit)) * (newMinLimit - newMaxLimit);
}

bool check2DdataSize(const std::vector<std::vector<double>>& data) {
	// Check the size
	const size_t dataSize = data.size();
	if (dataSize % 2 != 0) {
		return false; // Missing an axis
	}
	return true; // No missing axis
}

void findMaxMin2Ddata(const std::vector<std::vector<double>>& data, double& minX, double& maxX, double& minY, double& maxY) {
	const size_t dataSize = data.size();
	for (size_t i = 0; i < dataSize; i += 2) {
		const std::vector<double> xData = data.at(i);
		double minLimit, maxLimit;
		maxMinData(xData, minLimit, maxLimit);
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

		const std::vector<double> yData = data.at(i + 1);
		maxMinData(yData, minLimit, maxLimit);
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