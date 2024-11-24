#pragma once

#include <string>
#include <vector>
#include "plots/plots.hpp"

class wxPlot : public wxPanel {
private:
	// A plot that contains a type and a figure
	Plots plots;
public:
	// Constructor
	wxPlot(wxFrame* parent, const WXPLOT_FIGURE wxPlotFigure = WXPLOT_FIGURE_2D, const WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE);

	// Setters
	void setFontSize(const unsigned int fontSize);
	void setTitle(const wxString title);
	void setXlabel(const wxString xLabel);
	void setYlabel(const wxString yLabel);
	void setTicks(const unsigned int ticks);
	void gridOn(const bool useGrid);
	void setPlotStartWidth(const wxCoord plotStartWidth);
	void setPlotStartHeight(const wxCoord plotStartHeight);
	void setPlotEndWidth(const wxCoord plotEndWidth);
	void setPlotEndHeight(const wxCoord plotEndHeight);
	void setData(const std::vector<std::vector<double>>& data2D);
	void setData(const std::vector<double>& data1D);
	void setRadius(const wxCoord radius);
	void legendOn(const bool useLegend);
	void setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition = PLACEMENT_NORTH_EAST);
	void fillCircles(const bool fillCircle);
	void setBinCount(const unsigned int binCount);
	void setYlim(const double minY, const double maxY);

	// This function renders the complete plot when the refresh function is called
	void drawPlot(wxPaintEvent& event);
};
