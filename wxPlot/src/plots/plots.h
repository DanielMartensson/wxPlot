#pragma once

#include "plotfigures/plotfigures.h"
#include "plottypes/plottypes.h"

class Plots {

private:
	// Plot types are the type of the plot e.g line, bar, histogram, bubble, scatter etc.
	PlotTypes plotTypes;

	// Plot frames are figures of the frame e.g 2D, 3D, custom etc.
	PlotFigure plotFigures;

public:
	// Constructor
	Plots() {}

	// Classes
	PlotTypes& getPlotTypes() { return plotTypes; }
	PlotFigure& getPlotFigures() { return plotFigures; }

	// Setters 
	void setWxPlotFigureType(const WXPLOT_FIGURE wxPlotFigure, const WXPLOT_TYPE wxPlotType);
	void setData(const std::vector<std::vector<double>>& data);
	void setData(const std::vector<double>& data);

};