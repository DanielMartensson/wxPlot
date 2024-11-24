#pragma once

#include <string>
#include <vector>
#include <wx/wx.h>
#include "../proportional/proportional.hpp"
#include "../../../plottools/plottools.hpp"

/**
 * @class Histogram
 * @brief Histogram class. Inheritance from class Proportional.
 */
class Histogram : public Proportional {
private:
	
	unsigned int binCount = 10;    ///< Total columns for the histogram

public:

	/**
	 * @brief Set the bin count for e.g. histogram.
	 * @param binCount Bin count is total columns inside a e.g historam chart.
	 */
	void setBinCount(const unsigned int binCount);
	/**
	 * @brief Set 1D data.
	 * @param data1D 1D data in form of 1D vector.
	 */
	void setData(const std::vector<double>& data1D);

};
