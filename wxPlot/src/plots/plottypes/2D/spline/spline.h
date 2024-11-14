#pragma once

#include <vector>
#include <wx/wx.h>
#include "../line/line.h"

class Spline: public Line {
private:

public:
	// Functions
	bool draw(wxDC& dc) override;
};