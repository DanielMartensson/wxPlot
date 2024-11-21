#pragma once

#include "2D/2Dfigure.h"

class PlotFigure {
private:
	// Type select
	WXPLOT_FIGURE wxPlotFigure = WXPLOT_FIGURE_2D;
	
	// 2D figure
	_2DFigure _2d;

public:
	// Constructor
	PlotFigure() {}

	// Setters
	void setWxPlotFigureType(const WXPLOT_FIGURE wxPlotFigure, const WXPLOT_TYPE wxPlotType);
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
	void setData(const std::vector<std::vector<double>>& data2D);
	void setData(const std::vector<double>& data2D);
	void legendOn(const bool useLegend);
	void setFontSize(const unsigned int fontSize);
	void setYlim(const double minY, const double maxY);

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