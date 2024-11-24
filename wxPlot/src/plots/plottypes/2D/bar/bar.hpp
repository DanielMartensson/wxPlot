#pragma once

#include <vector>
#include <wx/wx.h>
#include "../line/line.hpp"

/**
 * @class Bar
 * @brief Bar class. Inheritance from class Line.
 */
class Bar : public Line {
private:

public:
	/**
	 * @brief Draw the bar plot inside the rectangle. This is called by iteration.
	 * For example, this function is used inside a for-loop and each data, extracted from an array or vector.
	 * The extracted value is called "value" and the array or vector has the lenght "dataSize".
	 * 
	 * @param dc The wxDC object for drawing lines, polygons etc.
	 * @param value The extracted value from data array or vector.
	 * @param dataSize The size of the data array or vector.
	 * @param colourIndex Selection index of the colour.
	 * @param i Index where the columns of the bar plot are going to be placed.
	 */
	void draw(wxDC& dc, const double value, const unsigned int dataSize, const unsigned int colourIndex, const size_t i);
};