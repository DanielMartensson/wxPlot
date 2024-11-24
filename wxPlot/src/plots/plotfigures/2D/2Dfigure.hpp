#pragma once

#include "proportional/proportional.hpp"
#include "histogram/histogram.hpp"
#include "../../plottools/plottools.hpp"

/**
 * @class _2DFigure
 * @brief This is the 2D plot figure class. It contains plot figures such as propotional, histogram etc.
 */
class _2DFigure {
private:
	
	WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE;     ///< Plot type selection
	
	Proportional proportional;                     ///< Proportional figure
	
	Histogram histogram;                           ///< Histogram figure

public:

	/**
	 * @brief Set the plot type selection.
	 * @param wxPlotType Selection of plot type.
	 */
	void setWxPlotType(const WXPLOT_TYPE wxPlotType);

	/**
	 * @brief Set the size of the fonts.
	 * @param fontSize The size of the fonts.
	 */
	void setFontSize(const unsigned int fontSize);

	/**
	 * @brief Set the title of the plot.
	 * @param title Name of the title.
	 */
	void setTitle(const wxString& title);

	/**
	 * @brief Set the name of the X-label.
	 * @param xLabel Name of the X-label.
	 */
	void setXlabel(const wxString& xLabel);

	/**
	 * @brief Set the name of the Y-label.
	 * @param yLabel Name of the Y-label.
	 */
	void setYlabel(const wxString& yLabel);

	/**
	 * @brief Set the number of ticks at the figure in all axis.
	 * @param ticks Number of ticks.
	 */
	void setTicks(const unsigned int ticks);

	/**
	 * @brief Enable grid on the figure.
	 * @param useGrid Set true for enabling grid.
	 */
	void gridOn(const bool useGrid);

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
	 * @brief Activate the legend.
	 * @param useLegend Set true to make a little box with labels appear.
	 */
	void legendOn(const bool useLegend);

	/**
	 * @brief Set the labels and placement for the legend.
	 * @param legend Vector of strings for the legend.
	 * @param legendPosition Position where the legend should be placed.
	 */
	void setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition = PLACEMENT_NORTH_EAST);

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
	 * @brief Get the recalculated start width X-axis value.
	 * This value is recalculated after the figure is drawn.
	 * @return wxCoord Recalculated value
	 */
	wxCoord getPlotStartWidth() const;

	/**
	 * @brief Get the recalculated end width X-axis value.
	 * This value is recalculated after the figure is drawn.
	 * @return wxCoord Recalculated value
	 */
	wxCoord getPlotEndWidth() const;

	/**
	 * @brief Get the recalculated start height Y-axis value.
	 * This value is recalculated after the figure is drawn.
	 * @return wxCoord Recalculated value
	 */
	wxCoord getPlotStartHeight() const;

	/**
	 * @brief Get the recalculated end height Y-axis value.
	 * This value is recalculated after the figure is drawn.
	 * @return wxCoord Recalculated value
	 */
	wxCoord getPlotEndHeight() const;

	/**
	 * @brief This function will do the following:
	 * - Set the fonts
	 * - Draw the title
	 * - Draw the y-label
	 * - Draw the x-label
	 * - Draw the rectangle
	 * - Update the plotStartHeight, plotEndtHeight, plotStartWidth and plotEndtWidth for correct plotting the plot type
	 * @param dc The wxDC object for drawing lines, polygons etc.
	 */
	void drawFigure(wxDC& dc);

	/**
	 * @brief This function will draw the grid.
	 * Call this function after you have drawn the plot type.
	 * @param dc The wxDC object for drawing lines, polygons etc.
	 */
	void drawGrid(wxDC& dc);

	/**
	 * @brief This function will draw the ticks.
	 * Call this function after you have drawn the plot type.
	 * @param dc The wxDC object for drawing lines, polygons etc.
	 */
	void drawTicks(wxDC& dc);

	/**
	 * @brief This function will draw the legend.
	 * Call this function after you have drawn the plot type.
	 * @param dc The wxDC object for drawing lines, polygons etc.
	 */
	void drawLegend(wxDC& dc);
};