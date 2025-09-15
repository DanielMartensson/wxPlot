#include "wxplot.hpp"

wxPlot::wxPlot(wxWindow* parent, const WXPLOT_FIGURE wxPlotFigure, const WXPLOT_TYPE wxPlotType) 
	: wxWindow(parent, wxID_ANY, wxPoint(100, 100), wxSize(400, 300)) {
	// Set type
	plots.setWxPlotFigureType(wxPlotFigure, wxPlotType);

	// Important event handler that is going to update the complete plot
	Bind(wxEVT_PAINT, &wxPlot::drawPlot, this);
}

void wxPlot::setFontSize(const unsigned int fontSize) { 
	plots.getPlotFigures().setFontSize(fontSize); 
}

void wxPlot::setTitle(const wxString title) { 
	plots.getPlotFigures().setTitle(title); 
}

void wxPlot::setXlabel(const wxString xLabel) { 
	plots.getPlotFigures().setXlabel(xLabel); 
}

void wxPlot::setYlabel(const wxString yLabel) { 
	plots.getPlotFigures().setYlabel(yLabel); 
}

void wxPlot::setTicks(const unsigned int ticksX, const unsigned int ticksY) {
	plots.getPlotFigures().setTicks(ticksX, ticksY); 
}

void wxPlot::gridOn(const bool useGrid) { 
	plots.getPlotFigures().gridOn(useGrid); 
}

void wxPlot::setPlotStartWidth(const wxCoord plotStartWidth) { 
	plots.getPlotFigures().setPlotStartWidth(plotStartWidth); 
}

void wxPlot::setPlotStartHeight(const wxCoord plotStartHeight) { 
	plots.getPlotFigures().setPlotStartHeight(plotStartHeight); 
}

void wxPlot::setPlotEndWidth(const wxCoord plotEndWidth) { 
	plots.getPlotFigures().setPlotEndWidth(plotEndWidth); 
}

void wxPlot::setPlotEndHeight(const wxCoord plotEndHeight) { 
	plots.getPlotFigures().setPlotEndHeight(plotEndHeight); 
}

void wxPlot::getYlim(double& minY, double& maxY) {
	plots.getPlotTypes().getYlim(minY, maxY);
	plots.getPlotFigures().getYlim(minY, maxY);
}

void wxPlot::setData(const std::vector<std::vector<double>>& data2D) { 
	plots.setData(data2D); 
}

void wxPlot::setData(const std::vector<double>& data1D) { 
	plots.setData(data1D); 
}

void wxPlot::setRadius(const wxCoord radius) { 
	plots.getPlotTypes().setRadius(radius); 
}

void wxPlot::legendOn(const bool useLegend) { 
	plots.getPlotFigures().legendOn(useLegend); 
}

void wxPlot::setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition) {
	plots.getPlotFigures().setLegend(legend, legendPosition); 
}

void wxPlot::fillCircles(const bool fillCircle) { 
	plots.getPlotTypes().fillCircles(fillCircle); 
}

void wxPlot::setBinCount(const unsigned int binCount) { 
	plots.getPlotFigures().setBinCount(binCount); 
	plots.getPlotTypes().setBinCount(binCount); 
}

void wxPlot::setYlim(const double minY, const double maxY) { 
	plots.getPlotTypes().setYlim(minY, maxY);  
	plots.getPlotFigures().setYlim(minY, maxY); 
}

void wxPlot::setColour(const unsigned int colorIndex) {
	plots.getPlotTypes().setColour(colorIndex);
	plots.getPlotFigures().setColour(colorIndex);
}

//called by refresh
void wxPlot::drawPlot(wxPaintEvent& event) {
	wxPaintDC dc(this);

	Draw(dc);
}

//called by refresh AND print
void wxPlot::Draw(wxDC& dc)
{
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