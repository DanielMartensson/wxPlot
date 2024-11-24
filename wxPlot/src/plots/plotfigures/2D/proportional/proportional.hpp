#pragma once

#include <string>
#include <vector>
#include <wx/wx.h>
#include "../../../plottools/plottools.hpp"

class Proportional {
protected:
	// General plot information
	wxCoord plotEndWidth = 0;
	wxCoord plotEndHeight = 0;
	wxCoord plotStartWidth = 0;
	wxCoord plotStartHeight = 0;
	unsigned int fontSize = 0;
	unsigned int ticks = 0;
	bool useGrid = false;
	bool useLegend = false;
	wxString title;
	wxString xLabel;
	wxString yLabel;
	std::vector<wxString> legend;
	PLACEMENT legendPosition = PLACEMENT_NORTH_WEST;
	WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE;
	double minX = 0, maxX = 0, minY = 0, maxY = 0;

public:
	// Constructor
	Proportional() {}

	// Setters
	void setPlotStartWidth(const wxCoord plotStartWidth);
	void setPlotStartHeight(const wxCoord plotStartHeight);
	void setPlotEndWidth(const wxCoord plotEndWidth);
	void setPlotEndHeight(const wxCoord plotEndHeight);
	void setFontSize(const unsigned int fontSize);
	void setTicks(const unsigned int ticks);
	void gridOn(const bool useGrid);
	void setTitle(const wxString& title);
	void setXlabel(const wxString& xLabel);
	void setYlabel(const wxString& yLabel);
	void legendOn(const bool useLegend);
	void setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition);
	void setData(const std::vector<std::vector<double>>& data);
	void setData(const std::vector<double>& data);
	void setWxPlotType(const WXPLOT_TYPE wxPlotType);
	void setYlim(const double minY, const double maxY);

	// Getters
	wxCoord getPlotStartWidth() const;
	wxCoord getPlotStartHeight() const;
	wxCoord getPlotEndWidth() const;
	wxCoord getPlotEndHeight() const;

	// Functions
	bool drawFigure(wxDC& dc);
	void drawGrid(wxDC& dc);
	void drawTicks(wxDC& dc);
	void drawLegend(wxDC& dc);

};