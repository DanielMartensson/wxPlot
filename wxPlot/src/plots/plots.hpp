#pragma once

#include "plotfigures/plotfigures.hpp"
#include "plottypes/plottypes.hpp"

/**
 * @class Plots
 * @brief Plot class for wxPlot. This class contains plot types and plot figures.
 */
class Plots {

private:
	PlotTypes plotTypes;        ///< Plot types are the type of the plot e.g line, bar, histogram, bubble, scatter etc.

	PlotFigure plotFigures;     ///< Plot frames are figures of the frame e.g 2D, 3D, custom etc.

public:

	/**
	 * @brief Return the reference of plot types object.
	 * @return PlotTypes&
	 */
	PlotTypes& getPlotTypes();

	/**
	 * @brief Return the reference of plot figure object.
	 * @return PlotFigure&
	 */
	PlotFigure& getPlotFigures();

	/**
	 * @brief Set the plot type selection and plot figure selection.
	 * @param wxPlotFigure Selection of plot figure.
	 * @param wxPlotType Selection of plot type.
	 */
	void setWxPlotFigureType(const WXPLOT_FIGURE wxPlotFigure, const WXPLOT_TYPE wxPlotType);

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

};