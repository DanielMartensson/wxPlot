#pragma once

#include <vector>
#include <wx/wx.h>

/**
 * @class Line
 * @brief Line class. Does the most of the things in 2D.
 */
class Line {
protected:
	
	wxCoord plotEndWidth = 0;       ///< Location of right upper corner in X-axis.
	wxCoord plotEndHeight = 0;      ///< Location of right bottom corner in Y-axis.
	wxCoord plotStartWidth = 0;     ///< Location of left upper corner in X-axis.
	wxCoord plotStartHeight = 0;    ///< Location of left upper corner in Y-axis.

	double minX = 0;                ///< Minimum value of data in X-axis
	double maxX = 0;                ///< Maximum value of data in X-axis.
	double minY = 0;                ///< Minimum value of data in Y-axis.
	double maxY = 0;                ///< Maximum value of data in Y-axis.

public:

	/**
	 * @brief Set minimum and maximum limits of the data.
	 * @param minX Minimum limit in X-axis.
	 * @param maxX Maximum limit in X-axis.
	 * @param minY Minimum limit in Y-axis.
	 * @param maxY Maximum limit in Y-axis.
	 */
	void setLimits(const double minX, const double maxX, const double minY, const double maxY);

	/**
	 * @brief Set the left upper corner in X-axis. Inside this rectangle, the plot is drawn.
	 * NOTE: This value is recalculated since the plot figure is drawn!
	 * (plotStartWidth, plotStartHeight) ----------------------------------------------- (plotEndWidth, plotStartHeight)
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 * (plotStartWidth, plotEndHeight)   ----------------------------------------------- (plotEndWidth, plotEndHeight)
	 * @param plotStartWidth Start width is at the start of X-axis.
	 */
	void setPlotStartWidth(const wxCoord plotStartWidth);

	/**
	 * @brief Set the left upper corner in Y-axis. Inside this rectangle, the plot is drawn.
	 * NOTE: This value is recalculated since the plot figure is drawn!
	 * (plotStartWidth, plotStartHeight) ----------------------------------------------- (plotEndWidth, plotStartHeight)
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 * (plotStartWidth, plotEndHeight)   ----------------------------------------------- (plotEndWidth, plotEndHeight)
	 * @param plotStartHeight Start height is at the start of Y-axis.
	 */
	void setPlotStartHeight(const wxCoord plotStartHeight);

	/**
	 * @brief Set the right upper corner in X-axis. Inside this rectangle, the plot is drawn.
	 * NOTE: This value is recalculated since the plot figure is drawn!
	 * (plotStartWidth, plotStartHeight) ----------------------------------------------- (plotEndWidth, plotStartHeight)
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 * (plotStartWidth, plotEndHeight)   ----------------------------------------------- (plotEndWidth, plotEndHeight)
	 * @param plotEndWidth End width is at the end of X-axis.
	 */
	void setPlotEndWidth(const wxCoord plotEndWidth);

	/**
	 * @brief Set the right bottom corner in Y-axis. Inside this rectangle, the plot is drawn.
	 * NOTE: This value is recalculated since the plot figure is drawn!
	 * (plotStartWidth, plotStartHeight) ----------------------------------------------- (plotEndWidth, plotStartHeight)
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 *                                   |                                             |
	 * (plotStartWidth, plotEndHeight)   ----------------------------------------------- (plotEndWidth, plotEndHeight)
	 * @param plotEndHeight End height is at the end of Y-axis.
	 */
	void setPlotEndHeight(const wxCoord plotEndHeight);

	/**
	 * @brief Draw the line plot inside the rectangle.
	 * @param dc The wxDC object for drawing lines, polygons etc.
	 * @param xData Data in X-axis.
	 * @param yData Data in Y-axis.
	 * @param colourIndex Selection index of the colour.
	 */
	virtual void draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const unsigned int colourIndex);
};