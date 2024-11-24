#pragma once

#include <vector>
#include <wx/wx.h>

class Line {
protected:
	// Size for the rectangle
	wxCoord plotEndWidth = 0;
	wxCoord plotEndHeight = 0;
	wxCoord plotStartWidth = 0;
	wxCoord plotStartHeight = 0;

	// Limits for the data 
	double minX = 0;
	double maxX = 0;
	double minY = 0;
	double maxY = 0;

public:
	// Constructor
	Line() {}

	// Setters
	void setLimits(const double minX, const double maxX, const double minY, const double maxY) { this->minX = minX; this->maxX = maxX; this->minY = minY; this->maxY = maxY; }
	void setPlotStartWidth(const wxCoord plotStartWidth) { this->plotStartWidth = plotStartWidth; }
	void setPlotStartHeight(const wxCoord plotStartHeight) { this->plotStartHeight = plotStartHeight; }
	void setPlotEndWidth(const wxCoord plotEndWidth) { this->plotEndWidth = plotEndWidth; }
	void setPlotEndHeight(const wxCoord plotEndHeight) { this->plotEndHeight = plotEndHeight; }

	// Functions
	virtual bool draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const unsigned int colourIndex);
};