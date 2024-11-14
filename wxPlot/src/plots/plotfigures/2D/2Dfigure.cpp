#include "2Dfigure.h"

void _2D_Figure::setWxPlotType(const WXPLOT_TYPE wxPlotType) {
	this->wxPlotType = wxPlotType;
}

void _2D_Figure::setTitle(const wxString& title) {
	proportional.setTitle(title);
}

void _2D_Figure::setXlabel(const wxString& xLabel) {
	proportional.setXlabel(xLabel);
}

void _2D_Figure::setYlabel(const wxString& yLabel) {
	proportional.setYlabel(yLabel);
}

void _2D_Figure::setTicks(const unsigned int ticks) {
	proportional.setTicks(ticks);
}

void _2D_Figure::gridOn(const bool useGrid) {
	proportional.gridOn(useGrid);
}

void _2D_Figure::setPlotStartWidth(const wxCoord plotStartWidth) {
	proportional.setPlotStartWidth(plotStartWidth);
}

void _2D_Figure::setPlotStartHeight(const wxCoord plotStartHeight) {
	proportional.setPlotStartHeight(plotStartHeight);
}

void _2D_Figure::setPlotEndWidth(const wxCoord plotEndWidth) {
	proportional.setPlotEndWidth(plotEndWidth);
}

void _2D_Figure::setPlotEndHeight(const wxCoord plotEndHeight) {
	proportional.setPlotEndHeight(plotEndHeight);
}

void _2D_Figure::setData(const std::vector<std::vector<double>>& data) {
	proportional.setData(data);
}

void _2D_Figure::legendOn(const bool useLegend) {
	proportional.legendOn(useLegend);
}

void _2D_Figure::setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition) {
	proportional.setLegend(legend, legendPosition);
}

void _2D_Figure::setFontSize(const unsigned int fontSize) {
	proportional.setFontSize(fontSize);
}

wxCoord _2D_Figure::getPlotStartWidth() const {
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
	default:
		return 0;
		break;
	}
}

wxCoord _2D_Figure::getPlotEndWidth() const {
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
	default:
		return 0;
		break;
	}
}

wxCoord _2D_Figure::getPlotStartHeight() const {
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
	default:
		return 0;
		break;
	}
}

wxCoord _2D_Figure::getPlotEndHeight() const {
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
	default:
		return 0;
		break;
	}
}

void _2D_Figure::drawFigure(wxDC& dc) {
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
	default:
		proportional.drawFigure(dc);
		break;
	}
}

void _2D_Figure::drawTicks(wxDC& dc) {
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

void _2D_Figure::drawGrid(wxDC& dc) {
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

void _2D_Figure::drawLegend(wxDC& dc) {
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