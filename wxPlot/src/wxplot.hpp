#pragma once

#include <string>
#include <vector>
#include "plots/plots.hpp"

/**
 * @class 
 * @brief Main class for wxPlot. This is the only class the user going to work with.
 */
class wxPlot : public wxPanel {
private:
	Plots plots; ///< Holds all information about plot type and figure plot.
public:

	/**
	 * @brief Constructor of wxPlot.
	 * @param parent The frame which holds the plot.
	 * @param wxPlotFigure The figure frame e.g 2D or 3D or custom.
	 * @param wxPlotType The type of the plot e.g line, bar, histogram, scatter, spline etc. 
	 * @return void
	 */
	wxPlot(wxFrame* parent, const WXPLOT_FIGURE wxPlotFigure = WXPLOT_FIGURE_2D, const WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE);

	/**
	 * @brief Set the size of the fonts.
	 * @param fontSize The size of the fonts.
	 * @return void
	 */
	void setFontSize(const unsigned int fontSize);

	/**
	 * @brief Set the title of the plot.
	 * @param title Name of the title.
	 * @return void
	 */
	void setTitle(const wxString title);

	/**
	 * @brief Set the name of the X-label.
	 * @param xLabel Name of the X-label.
	 * @return void
	 */
	void setXlabel(const wxString xLabel);

	/**
	 * @brief Set the name of the Y-label.
	 * @param yLabel Name of the Y-label.
	 * @return void
	 */
	void setYlabel(const wxString yLabel);

	/**
	 * @brief Set the number of ticks at the figure in all axis.
	 * @param ticks Number of ticks.
	 * @return void
	 */
	void setTicks(const unsigned int ticks);

	/**
	 * @brief Enable grid on the figure.
	 * @param useGrid Set true for enabling grid.
	 * @return void
	 */
	void gridOn(const bool useGrid);

	/**
	 * @brief Set the left upper corner corner in X-axis. Inside this rectangle, the plot is drawn.
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
	 * @return void
	 */
	void setPlotStartWidth(const wxCoord plotStartWidth);

	/**
	 * @brief Set the left upper corner corner in Y-axis. Inside this rectangle, the plot is drawn
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
	 * @return void
	 */
	void setPlotStartHeight(const wxCoord plotStartHeight);

	/**
	 * @brief Set the right upper corner corner in X-axis. Inside this rectangle, the plot is drawn
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
	 * @return void
	 */
	void setPlotEndWidth(const wxCoord plotEndWidth);

	/**
	 * @brief Set the right bottom corner corner in Y-axis. Inside this rectangle, the plot is drawn
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
	 * @return void
	 */
	void setPlotEndHeight(const wxCoord plotEndHeight);

	/**
	 * @brief Set 2D data.
	 * @param data2D 2D data in form of 2D vector.
	 * @return void
	 */
	void setData(const std::vector<std::vector<double>>& data2D);

	/**
	 * @brief Set 1D data.
	 * @param data1D 1D data in form of 1D vector.
	 * @return void
	 */
	void setData(const std::vector<double>& data1D);

	/**
	 * @brief Set radius. Most used for circles e.g filling scatter plots.
	 * @param radius The radius of the circle.
	 * @return void
	 */
	void setRadius(const wxCoord radius);

	/**
	 * @brief Activate the legend.
	 * @param useLegend The radius of the circle.
	 * @return void
	 */
	void legendOn(const bool useLegend);

	/**
	 * @brief Set the labels and placement for the legend.
	 * @param legend Vector of strings for the legend.
	 * @param legendPosition Position where the legend should be placed.
	 * @return void
	 */
	void setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition = PLACEMENT_NORTH_EAST);

	/**
	 * @brief Fill circles if radius is applied if circiles are going to be filled with the same colour as they are drawn.
	 * @param fillCircle Set true if filled.
	 * @return void
	 */
	void fillCircles(const bool fillCircle);

	/**
	 * @brief Set the bin count for e.g. histogram.
	 * @param binCount Bin count is total columns inside a e.g historam chart.
	 * @return void
	 */
	void setBinCount(const unsigned int binCount);

	/**
	 * @brief Set the plot zoom limit in Y-axis.
	 * @param minY Minimum limit in Y-axis.
	 * @param maxY Maximum limit in Y-axis.
	 * @return void
	 */
	void setYlim(const double minY, const double maxY);

	/**
	 * @brief Important event function for draw the whole plot
	 * @param event This even parameter is not used.
	 * @return void
	 */
	void drawPlot(wxPaintEvent& event);
};