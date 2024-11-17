#pragma once

#include <vector>
#include <wx/wx.h>
#include "../line/line.h"

class Bar : public Line {
private:

public:
	// Functions
	bool draw(wxDC& dc, const double yData, const int colourIndex, const size_t dataSize, const size_t i);
};