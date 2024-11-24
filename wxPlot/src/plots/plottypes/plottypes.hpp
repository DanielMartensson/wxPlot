#pragma once

#include "2D/2Dtype.hpp"

/**
 * @class PlotTypes
 * @brief Here all the plot types e.g 2D, 3D, custom etc. are included.
 */
class PlotTypes {

private:

	WXPLOT_FIGURE wxPlotFigure = WXPLOT_FIGURE_2D; ///< Selection of plot figure

	_2DType _2d;                                   ///< Plot 2D type object

public:

	/**
	 * @brief Set the plot type selection and plot figure selection.
	 * @param wxPlotFigure Selection of plot figure.
	 * @param wxPlotType Selection of plot type.
	 */
	void setWxPlotFigureType(const WXPLOT_FIGURE wxPlotFigure, const WXPLOT_TYPE wxPlotType);

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