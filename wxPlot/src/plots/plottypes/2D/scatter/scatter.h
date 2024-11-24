#pragma once

#include <vector>
#include <wx/wx.h>
#include "../line/line.h"

class Scatter: public Line {
private:
	// Proportional configuration
	wxCoord radius = 3;
	bool fillCircle = false;

public:
	// Setters
	void setRadius(const wxCoord radius) { this->radius = radius; }
	void fillCircles(const bool fillCircle) { this->fillCircle = fillCircle; }

	// Functions
	bool draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const unsigned int colourIndex) override;
};