#pragma once

#include "line/line.h"
#include "scatter/scatter.h"
#include "spline/spline.h"
#include "../../plottools/plottools.h"

class _2D_Type {

private:
	// Type select
	WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE;

	// The data
	std::vector<std::vector<double>> data;

	// Charts
	Line line;
	Scatter scatter;
	Spline spline;

public:
	// Constructor
	_2D_Type() { }

	// Setters
	void setWxPlotType(const WXPLOT_TYPE wxPlotType);
	void setRadius(const wxCoord radius);
	void fillCircles(const bool fillCircle);
	void setData(const std::vector<std::vector<double>>& data);
	void setPlotStartWidth(const wxCoord plotStartWidth);
	void setPlotStartHeight(const wxCoord plotStartHeight);
	void setPlotEndWidth(const wxCoord plotEndWidth);
	void setPlotEndHeight(const wxCoord plotEndHeight);

	// Functions
	bool drawType(wxDC& dc);
};