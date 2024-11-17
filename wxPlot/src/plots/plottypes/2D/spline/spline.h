#pragma once

#include <vector>
#include <wx/wx.h>
#include "../line/line.h"

class Spline: public Line {
private:

public:
	// Functions
	bool draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const int colourIndex) override;
};