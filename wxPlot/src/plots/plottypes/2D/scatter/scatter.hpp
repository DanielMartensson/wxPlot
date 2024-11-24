#pragma once

#include <vector>
#include <wx/wx.h>
#include "../line/line.hpp"

/**
 * @class Scatter
 * @brief Scatter class. Inheritance from class Line.
 */
class Scatter: public Line {
private:

	wxCoord radius = 3;               ///< Radius of the scatter circles.
	bool fillCircle = false;          ///< Flag of filling the scatter circles or not.

public:
	/**
	 * @brief Set radius. Most used for circles e.g filling scatter plots.
	 * @param radius The radius of the circle.
	 */
	void setRadius(const wxCoord radius);

	/**
	 * @brief Fill circles if radius is applied if circiles are going to be filled with the same colour as they are drawn.
	 * @param fillCircle Set true if filled.
	 */
	void fillCircles(const bool fillCircle);

	/**
	 * @brief Draw the scatter plot inside the rectangle
	 * @param dc The wxDC object for drawing lines, polygons etc.
	 * @param xData Data in X-axis
	 * @param yData Data in Y-axis
	 * @param colourIndex Selection index of the colour.
	 */
	void draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const unsigned int colourIndex) override;
};