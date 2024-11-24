#pragma once

#include <vector>
#include <wx/wx.h>
#include "../line/line.hpp"

class Bar : public Line {
private:

public:
	// Functions
	bool draw(wxDC& dc, const double data, const unsigned int dataSize, const unsigned int colourIndex, const size_t i);
};