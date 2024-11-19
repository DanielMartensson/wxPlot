#include "2Dfigure.h"

void _2DFigure::setWxPlotType(const WXPLOT_TYPE wxPlotType) {
	this->wxPlotType = wxPlotType;
	proportional.setWxPlotType(wxPlotType);
}

void _2DFigure::setTitle(const wxString& title) {
	proportional.setTitle(title);
}

void _2DFigure::setXlabel(const wxString& xLabel) {
	proportional.setXlabel(xLabel);
}

void _2DFigure::setYlabel(const wxString& yLabel) {
	proportional.setYlabel(yLabel);
}

void _2DFigure::setTicks(const unsigned int ticks) {
	proportional.setTicks(ticks);
}

void _2DFigure::gridOn(const bool useGrid) {
	proportional.gridOn(useGrid);
}

void _2DFigure::setPlotStartWidth(const wxCoord plotStartWidth) {
	proportional.setPlotStartWidth(plotStartWidth);
}

void _2DFigure::setPlotStartHeight(const wxCoord plotStartHeight) {
	proportional.setPlotStartHeight(plotStartHeight);
}

void _2DFigure::setPlotEndWidth(const wxCoord plotEndWidth) {
	proportional.setPlotEndWidth(plotEndWidth);
}

void _2DFigure::setPlotEndHeight(const wxCoord plotEndHeight) {
	proportional.setPlotEndHeight(plotEndHeight);
}

void _2DFigure::setData(const std::vector<std::vector<double>>& data) {
	proportional.setData(data);
}

void _2DFigure::legendOn(const bool useLegend) {
	proportional.legendOn(useLegend);
}

void _2DFigure::setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition) {
	proportional.setLegend(legend, legendPosition);
}

void _2DFigure::setFontSize(const unsigned int fontSize) {
	proportional.setFontSize(fontSize);
}

void _2DFigure::setYlim(const double minY, const double maxY) {
	proportional.setYlim(minY, maxY);
}

wxCoord _2DFigure::getPlotStartWidth() const {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		return proportional.getPlotStartWidth();
	case WXPLOT_TYPE_SCATTER:
		return proportional.getPlotStartWidth();
	case WXPLOT_TYPE_LINE_SCATTER:
		return proportional.getPlotStartWidth();
	case WXPLOT_TYPE_SPLINE:
		return proportional.getPlotStartWidth();
	case WXPLOT_TYPE_SPLINE_SCATTER:
		return proportional.getPlotStartWidth();
	case WXPLOT_TYPE_BAR:
		return proportional.getPlotStartWidth();
	default:
		return 0;
		break;
	}
}

wxCoord _2DFigure::getPlotEndWidth() const {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		return proportional.getPlotEndWidth();
	case WXPLOT_TYPE_SCATTER:
		return proportional.getPlotEndWidth();
	case WXPLOT_TYPE_LINE_SCATTER:
		return proportional.getPlotEndWidth();
	case WXPLOT_TYPE_SPLINE:
		return proportional.getPlotEndWidth();
	case WXPLOT_TYPE_SPLINE_SCATTER:
		return proportional.getPlotEndWidth();
	case WXPLOT_TYPE_BAR:
		return proportional.getPlotEndWidth();
	default:
		return 0;
		break;
	}
}

wxCoord _2DFigure::getPlotStartHeight() const {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		return proportional.getPlotStartHeight();
	case WXPLOT_TYPE_SCATTER:
		return proportional.getPlotStartHeight();
	case WXPLOT_TYPE_LINE_SCATTER:
		return proportional.getPlotStartHeight();
	case WXPLOT_TYPE_SPLINE:
		return proportional.getPlotStartHeight();
	case WXPLOT_TYPE_SPLINE_SCATTER:
		return proportional.getPlotStartHeight();
	case WXPLOT_TYPE_BAR:
		return proportional.getPlotStartHeight();
	default:
		return 0;
		break;
	}
}

wxCoord _2DFigure::getPlotEndHeight() const {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		return proportional.getPlotEndHeight();
	case WXPLOT_TYPE_SCATTER:
		return proportional.getPlotEndHeight();
	case WXPLOT_TYPE_LINE_SCATTER:
		return proportional.getPlotEndHeight();
	case WXPLOT_TYPE_SPLINE:
		return proportional.getPlotEndHeight();
	case WXPLOT_TYPE_SPLINE_SCATTER:
		return proportional.getPlotEndHeight();
	case WXPLOT_TYPE_BAR:
		return proportional.getPlotEndHeight();
	default:
		return 0;
		break;
	}
}

void _2DFigure::drawFigure(wxDC& dc) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		proportional.drawFigure(dc);
		break;
	case WXPLOT_TYPE_SCATTER:
		proportional.drawFigure(dc);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		proportional.drawFigure(dc);
		break;
	case WXPLOT_TYPE_SPLINE:
		proportional.drawFigure(dc);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		proportional.drawFigure(dc);
		break;
	case WXPLOT_TYPE_BAR:
		proportional.drawFigure(dc);
		break;
	default:
		proportional.drawFigure(dc);
		break;
	}
}

void _2DFigure::drawTicks(wxDC& dc) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		proportional.drawTicks(dc);
		break;
	case WXPLOT_TYPE_SCATTER:
		proportional.drawTicks(dc);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		proportional.drawTicks(dc);
		break;
	case WXPLOT_TYPE_SPLINE:
		proportional.drawTicks(dc);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		proportional.drawTicks(dc);
		break;
	default:
		proportional.drawTicks(dc);
		break;
	}
}

void _2DFigure::drawGrid(wxDC& dc) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		proportional.drawGrid(dc);
		break;
	case WXPLOT_TYPE_SCATTER:
		proportional.drawGrid(dc);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		proportional.drawGrid(dc);
		break;
	case WXPLOT_TYPE_SPLINE:
		proportional.drawGrid(dc);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		proportional.drawGrid(dc);
		break;
	default:
		proportional.drawGrid(dc);
		break;
	}
}

void _2DFigure::drawLegend(wxDC& dc) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		proportional.drawLegend(dc);
		break;
	case WXPLOT_TYPE_SCATTER:
		proportional.drawLegend(dc);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		proportional.drawLegend(dc);
		break;
	case WXPLOT_TYPE_SPLINE:
		proportional.drawLegend(dc);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		proportional.drawLegend(dc);
		break;
	default:
		proportional.drawLegend(dc);
		break;
	}
}