#pragma once

#include <string>
#include <vector>
#include "plots/plots.h"

class wxPlot : public wxPanel {
private:
	// A plot that contains a type and a figure
	Plots plots;
public:
	// Constructor
	wxPlot(wxFrame* parent, const WXPLOT_FIGURE wxPlotFigure = WXPLOT_FIGURE_2D, const WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE);

	// Setters
	void setFontSize(const unsigned int fontSize) { plots.getPlotFigures().setFontSize(fontSize); }
	void setTitle(const wxString title) { plots.getPlotFigures().setTitle(title); }
	void setXlabel(const wxString xLabel) { plots.getPlotFigures().setXlabel(xLabel); }
	void setYlabel(const wxString yLabel) { plots.getPlotFigures().setYlabel(yLabel); }
	void setTicks(const unsigned int ticks) { plots.getPlotFigures().setTicks(ticks); }
	void gridOn(const bool useGrid) { plots.getPlotFigures().gridOn(useGrid); }
	void setPlotStartWidth(const wxCoord plotStartWidth) { plots.getPlotFigures().setPlotStartWidth(plotStartWidth); }
	void setPlotStartHeight(const wxCoord plotStartHeight) { plots.getPlotFigures().setPlotStartHeight(plotStartHeight); }
	void setPlotEndWidth(const wxCoord plotEndWidth) { plots.getPlotFigures().setPlotEndWidth(plotEndWidth); }
	void setPlotEndHeight(const wxCoord plotEndHeight) { plots.getPlotFigures().setPlotEndHeight(plotEndHeight); }
	void setData(const std::vector<std::vector<double>>& data2D) { plots.setData(data2D); }
	void setData(const std::vector<double>& data1D) { plots.setData(data1D); }

	void setRadius(const wxCoord radius) { plots.getPlotTypes().setRadius(radius); }
	void legendOn(const bool useLegend) { plots.getPlotFigures().legendOn(useLegend); }
	void setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition = PLACEMENT_NORTH_EAST) { plots.getPlotFigures().setLegend(legend, legendPosition); }
	void fillCircles(const bool fillCircle) { plots.getPlotTypes().fillCircles(fillCircle); }
	void setYlim(const double minY, const double maxY) { plots.getPlotTypes().setYlim(minY, maxY);  plots.getPlotFigures().setYlim(minY, maxY); }

	// This function renders the complete plot when the refresh function is called
	void drawPlot(wxPaintEvent& event);
};
