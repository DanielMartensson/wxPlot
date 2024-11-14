#include "wxplot.h"

wxPlot::wxPlot(wxFrame* parent, const WXPLOT_FIGURE wxPlotFigure, const WXPLOT_TYPE wxPlotType) : wxPanel(parent) {
	// Set type
	plots.setWxPlotFigureType(wxPlotFigure, wxPlotType);

	// Important event handler that is going to update the complete plot
	Bind(wxEVT_PAINT, &wxPlot::drawPlot, this);
}

void wxPlot::drawPlot(wxPaintEvent& event) {
	// Create DC
	wxPaintDC dc(this);

	// Draw figure - Must be done before drawing the type
	plots.getPlotFigures().drawFigure(dc);

	// Get the updated size
	const wxCoord plotStartWidth = plots.getPlotFigures().getPlotStartWidth();
	const wxCoord plotStartHeight = plots.getPlotFigures().getPlotStartHeight();
	const wxCoord plotEndWidth = plots.getPlotFigures().getPlotEndWidth();
	const wxCoord plotEndHeight = plots.getPlotFigures().getPlotEndHeight();

	// Update the plot size
	plots.getPlotTypes().setPlotStartWidth(plotStartWidth);
	plots.getPlotTypes().setPlotStartHeight(plotStartHeight);
	plots.getPlotTypes().setPlotEndWidth(plotEndWidth);
	plots.getPlotTypes().setPlotEndHeight(plotEndHeight);

	// Draw type
	plots.getPlotTypes().drawType(dc);

	// Draw grid if enabled
	plots.getPlotFigures().drawGrid(dc);

	// Draw ticks if used
	plots.getPlotFigures().drawTicks(dc);

	// Draw legend if enabled
	plots.getPlotFigures().drawLegend(dc);
}