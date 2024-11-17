#pragma once

#include <string>
#include <vector>
#include <wx/wx.h>
#include "../../../plottools/plottools.h"

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
	std::vector<std::vector<double>> data;
	WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE;

public:
	// Constructor
	Proportional() {}

	// Setters
	void setPlotStartWidth(const wxCoord plotStartWidth) { this->plotStartWidth = plotStartWidth; }
	void setPlotStartHeight(const wxCoord plotStartHeight) { this->plotStartHeight = plotStartHeight; }
	void setPlotEndWidth(const wxCoord plotEndWidth) { this->plotEndWidth = plotEndWidth; }
	void setPlotEndHeight(const wxCoord plotEndHeight) { this->plotEndHeight = plotEndHeight; }
	void setFontSize(const unsigned int fontSize) { this->fontSize = fontSize; }
	void setTicks(const unsigned int ticks) { this->ticks = ticks; }
	void gridOn(const bool useGrid) { this->useGrid = useGrid; }
	void setTitle(const wxString& title) { this->title = title; }
	void setXlabel(const wxString& xLabel) { this->xLabel = xLabel; }
	void setYlabel(const wxString& yLabel) { this->yLabel = yLabel; }
	void legendOn(const bool useLegend) { this->useLegend = useLegend; }
	void setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition) { this->legend = legend; this->legendPosition = legendPosition; }
	void setData(const std::vector<std::vector<double>>& data) { this->data = data; }
	void setWxPlotType(const WXPLOT_TYPE wxPlotType) { this->wxPlotType = wxPlotType; }

	// Getters
	wxCoord getPlotStartWidth() const { return plotStartWidth; }
	wxCoord getPlotStartHeight() const { return plotStartHeight; }
	wxCoord getPlotEndWidth() const { return plotEndWidth; }
	wxCoord getPlotEndHeight() const { return plotEndHeight; }

	// Functions
	bool drawFigure(wxDC& dc);
	void drawGrid(wxDC& dc);
	void drawTicks(wxDC& dc);
	void drawLegend(wxDC& dc);

};