#include "plotfigures.h"


void PlotFigure::setWxPlotFigureType(const WXPLOT_FIGURE wxPlotFigure, const WXPLOT_TYPE wxPlotType) {
	this->wxPlotFigure = wxPlotFigure;
	_2d.setWxPlotType(wxPlotType);
}

void PlotFigure::setTitle(const wxString& title) {
	_2d.setTitle(title);
}

void PlotFigure::setXlabel(const wxString& xLabel) {
	_2d.setXlabel(xLabel);
}

void PlotFigure::setYlabel(const wxString& yLabel) {
	_2d.setYlabel(yLabel);
}

void PlotFigure::setTicks(const unsigned int ticks) {
	_2d.setTicks(ticks);
}

void PlotFigure::gridOn(const bool useGrid) {
	_2d.gridOn(useGrid);
}

void PlotFigure::setPlotStartWidth(const wxCoord plotStartWidth) {
	_2d.setPlotStartWidth(plotStartWidth);
}

void PlotFigure::setPlotStartHeight(const wxCoord plotStartHeight) {
	_2d.setPlotStartHeight(plotStartHeight);
}

void PlotFigure::setPlotEndWidth(const wxCoord plotEndWidth) {
	_2d.setPlotEndWidth(plotEndWidth);
}

void PlotFigure::setPlotEndHeight(const wxCoord plotEndHeight) {
	_2d.setPlotEndHeight(plotEndHeight);
}

void PlotFigure::setData(const std::vector<std::vector<double>>& data) {
	_2d.setData(data);
}

void PlotFigure::legendOn(const bool useLegend) {
	_2d.legendOn(useLegend);
}

void PlotFigure::setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition) {
	_2d.setLegend(legend, legendPosition);
}

void PlotFigure::setFontSize(const unsigned int fontSize) {
	_2d.setFontSize(fontSize);
}

void PlotFigure::setYlim(const double minY, const double maxY) {
	_2d.setYlim(minY, maxY);
}

wxCoord PlotFigure::getPlotStartWidth() const {
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_2D:
		return _2d.getPlotStartWidth();
	default:
		return 0;
		break;
	}
}

wxCoord PlotFigure::getPlotEndWidth() const {
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_2D:
		return _2d.getPlotEndWidth();
	default:
		return 0;
		break;
	}
}

wxCoord PlotFigure::getPlotStartHeight() const {
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_2D:
		return _2d.getPlotStartHeight();
	default:
		return 0;
		break;
	}
}

wxCoord PlotFigure::getPlotEndHeight() const {
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_2D:
		return _2d.getPlotEndHeight();
	default:
		return 0;
		break;
	}
}

void PlotFigure::drawFigure(wxDC& dc) {
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_2D:
		_2d.drawFigure(dc);
		break;
	default:
		_2d.drawFigure(dc);
		break;
	}
}

void PlotFigure::drawTicks(wxDC& dc) {
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_2D:
		_2d.drawTicks(dc);
		break;
	default:
		_2d.drawTicks(dc);
		break;
	}
}

void PlotFigure::drawGrid(wxDC& dc) {
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_2D:
		_2d.drawGrid(dc);
		break;
	default:
		_2d.drawGrid(dc);
		break;
	}
}

void PlotFigure::drawLegend(wxDC& dc) {
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_2D:
		_2d.drawLegend(dc);
		break;
	default:
		_2d.drawLegend(dc);
		break;
	}
}