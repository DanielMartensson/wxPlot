#pragma once

#include "proportional/proportional.h"
#include "histogram/histogram.h"
#include "../../plottools/plottools.h"

class _2DFigure {
private:
	// Type select
	WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE;

	// Proportional figure
	Proportional proportional;

	// Histogram figure
	Histogram histogram;

public:
	// Constructor
	_2DFigure() {}

	// Setters
	void setWxPlotType(const WXPLOT_TYPE wxPlotType);
	void setTitle(const wxString& title);
	void setXlabel(const wxString& xLabel);
	void setYlabel(const wxString& yLabel);
	void setTicks(const unsigned int gridSize);
	void gridOn(const bool grid);
	void setPlotStartWidth(const wxCoord plotStartWidth);
	void setPlotStartHeight(const wxCoord plotStartHeight);
	void setPlotEndWidth(const wxCoord plotEndWidth);
	void setPlotEndHeight(const wxCoord plotEndHeight);
	void setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition);
	void setData(const std::vector<std::vector<double>>& data);
	void setData(const std::vector<double>& data);
	void legendOn(const bool useLegend);
	void setFontSize(const unsigned int fontSize);
	void setYlim(const double minY, const double maxY);
	void setBinCount(const unsigned int binCount);

	// Getters
	wxCoord getPlotStartWidth() const;
	wxCoord getPlotEndWidth() const;
	wxCoord getPlotStartHeight() const;
	wxCoord getPlotEndHeight() const;

	// Functions
	void drawFigure(wxDC& dc);
	void drawGrid(wxDC& dc);
	void drawTicks(wxDC& dc);
	void drawLegend(wxDC& dc);
};