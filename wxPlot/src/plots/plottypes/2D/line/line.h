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

	// Plotting data
	std::vector<std::vector<double>> data;
public:
	// Constructor
	Line() {}

	// Setters
	void setData(const std::vector<std::vector<double>>& data) { this->data = data; };
	void setPlotStartWidth(const wxCoord plotStartWidth) { this->plotStartWidth = plotStartWidth; }
	void setPlotStartHeight(const wxCoord plotStartHeight) { this->plotStartHeight = plotStartHeight; }
	void setPlotEndWidth(const wxCoord plotEndWidth) { this->plotEndWidth = plotEndWidth; }
	void setPlotEndHeight(const wxCoord plotEndHeight) { this->plotEndHeight = plotEndHeight; }

	// Functions
	virtual bool draw(wxDC& dc);
};