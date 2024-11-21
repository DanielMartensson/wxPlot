#pragma once

#include <vector>
#include <wx/wx.h>
#include "../line/line.h"

class Bar : public Line {
private:

public:
	// Functions
	bool draw(wxDC& dc, const std::vector<double>& data);
};