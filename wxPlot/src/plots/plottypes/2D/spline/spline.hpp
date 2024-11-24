#pragma once

#include <vector>
#include <wx/wx.h>
#include "../line/line.hpp"

/**
 * @class Spline
 * @brief Spline class. Inheritance from class Line.
 */
class Spline: public Line {
private:

public:
	/**
	 * @brief Draw the spline plot inside the rectangle.
	 * @param dc The wxDC object for drawing lines, polygons etc.
	 * @param xData Data in X-axis.
	 * @param yData Data in Y-axis.
	 * @param colourIndex Selection index of the colour.
	 */
	void draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const unsigned int colourIndex) override;
};