#pragma once

#include "line/line.hpp"
#include "scatter/scatter.hpp"
#include "spline/spline.hpp"
#include "bar/bar.hpp"
#include "../../plottools/plottools.hpp"

/**
 * @class _2DType
 * @brief Here all the 2D plot types.
 */
class _2DType {

private:
	
	WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE;        ///< Type plot selection

	double minX = 0, maxX = 0, minY = 0, maxY = 0;    ///< Minimum and maximum value of the 1D or 2D data
	std::vector<std::vector<double>> data2D;          ///< The 2D data
	std::vector<double> data1D;                       ///< The 1D data
	bool is2Dused = false;                            ///< Flag if 2D data us used
	unsigned int binCount = 10;                       ///< Bin count for e.g histogram
	
	Line line;                                        ///< Line plot object
	Scatter scatter;                                  ///< Scatter plot object
	Spline spline;                                    ///< Spline plot object
	Bar bar;                                          ///< Bar and Histogram plot object

public:

	/**
	 * @brief Set the plot type selection.
	 * @param wxPlotType Selection of plot type
	 */
	void setWxPlotType(const WXPLOT_TYPE wxPlotType);

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
	 * @brief Set 2D data.
	 * @param data2D 2D data in form of 2D vector.
	 */
	void setData(const std::vector<std::vector<double>>& data2D);

	/**
	 * @brief Set 1D data.
	 * @param data1D 1D data in form of 1D vector.
	 */
	void setData(const std::vector<double>& data1D);

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
	 * @brief Set the bin count for e.g. histogram.
	 * @param binCount Bin count is total columns inside a e.g historam chart.
	 */
	void setBinCount(const unsigned int binCount);

	/**
	 * @brief Set the plot zoom limit in Y-axis.
	 * @param minY Minimum limit in Y-axis.
	 * @param maxY Maximum limit in Y-axis.
	 */
	void setYlim(const double minY, const double maxY);

	/**
	 * @brief This function draw the plot e.g line, bar, histogram, spline, scatter etc. inside in this rectangle.
	 * @param dc The wxDC object for drawing lines, polygons etc.
	 */
	void drawType(wxDC& dc);
};