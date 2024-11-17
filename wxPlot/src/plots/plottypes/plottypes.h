#pragma once

#include "2D/2Dtype.h"

class PlotTypes {

private:
	// Figure select
	WXPLOT_FIGURE wxPlotFigure = WXPLOT_FIGURE_2D;

	// Plot types
	_2DType _2d;

public:
	// Constructor
	PlotTypes() { }

	// Setters
	void setWxPlotFigureType(const WXPLOT_FIGURE wxPlotFigure, const WXPLOT_TYPE wxPlotType);
	void setRadius(const wxCoord radius);
	void fillCircles(const bool fillCircle);
	void setData(const std::vector<std::vector<double>>& data);
	void setPlotStartWidth(const wxCoord plotStartWidth);
	void setPlotStartHeight(const wxCoord plotStartHeight);
	void setPlotEndWidth(const wxCoord plotEndWidth);
	void setPlotEndHeight(const wxCoord plotEndHeight);

	// Functions
	void drawType(wxDC& dc);
};