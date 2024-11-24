#pragma once

#include <string>
#include <vector>
#include <wx/wx.h>
#include "../proportional/proportional.hpp"
#include "../../../plottools/plottools.hpp"

class Histogram : public Proportional {
private:
	// For the histogram
	unsigned int binCount = 10;

public:

	// Setters
	void setBinCount(const unsigned int binCount);
	void setData(const std::vector<double>& data);

};
