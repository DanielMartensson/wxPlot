#include "2Dfigure.hpp"

void _2DFigure::setWxPlotType(const WXPLOT_TYPE wxPlotType) {
	this->wxPlotType = wxPlotType;
	proportional.setWxPlotType(wxPlotType);
	histogram.setWxPlotType(wxPlotType);
}

void _2DFigure::setTitle(const wxString& title) {
	proportional.setTitle(title);
	histogram.setTitle(title);
}

void _2DFigure::setXlabel(const wxString& xLabel) {
	proportional.setXlabel(xLabel);
	histogram.setXlabel(xLabel);
}

void _2DFigure::setYlabel(const wxString& yLabel) {
	proportional.setYlabel(yLabel);
	histogram.setYlabel(yLabel);
}

void _2DFigure::setTicks(const unsigned int ticks) {
	proportional.setTicks(ticks);
	histogram.setTicks(ticks);
}

void _2DFigure::gridOn(const bool useGrid) {
	proportional.gridOn(useGrid);
	histogram.gridOn(useGrid);
}

void _2DFigure::setPlotStartWidth(const wxCoord plotStartWidth) {
	proportional.setPlotStartWidth(plotStartWidth);
	histogram.setPlotStartWidth(plotStartWidth);
}

void _2DFigure::setPlotStartHeight(const wxCoord plotStartHeight) {
	proportional.setPlotStartHeight(plotStartHeight);
	histogram.setPlotStartHeight(plotStartHeight);
}

void _2DFigure::setPlotEndWidth(const wxCoord plotEndWidth) {
	proportional.setPlotEndWidth(plotEndWidth);
	histogram.setPlotEndWidth(plotEndWidth);
}

void _2DFigure::setPlotEndHeight(const wxCoord plotEndHeight) {
	proportional.setPlotEndHeight(plotEndHeight);
	histogram.setPlotEndHeight(plotEndHeight);
}

void _2DFigure::setData(const std::vector<std::vector<double>>& data2D) {
	proportional.setData(data2D);
}

void _2DFigure::setData(const std::vector<double>& data1D) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		proportional.setData(data1D);
		break;
	case WXPLOT_TYPE_SCATTER:
		proportional.setData(data1D);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		proportional.setData(data1D);
		break;
	case WXPLOT_TYPE_SPLINE:
		proportional.setData(data1D);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		proportional.setData(data1D);
		break;
	case WXPLOT_TYPE_BAR:
		proportional.setData(data1D);
		break;
	case WXPLOT_TYPE_HIST:
		histogram.setData(data1D);
		break;
	default:
		break;
	}
}

void _2DFigure::legendOn(const bool useLegend) {
	proportional.legendOn(useLegend);
	histogram.legendOn(useLegend);
}

void _2DFigure::setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition) {
	proportional.setLegend(legend, legendPosition);
	histogram.setLegend(legend, legendPosition);
}

void _2DFigure::setFontSize(const unsigned int fontSize) {
	proportional.setFontSize(fontSize);
	histogram.setFontSize(fontSize);
}

void _2DFigure::setYlim(const double minY, const double maxY) {
	proportional.setYlim(minY, maxY);
	histogram.setYlim(minY, maxY);
}

void _2DFigure::setBinCount(const unsigned int binCount) {
	histogram.setBinCount(binCount);
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
	case WXPLOT_TYPE_HIST:
		return histogram.getPlotStartWidth();
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
	case WXPLOT_TYPE_HIST:
		return histogram.getPlotEndWidth();
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
	case WXPLOT_TYPE_HIST:
		return histogram.getPlotStartHeight();
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
	case WXPLOT_TYPE_HIST:
		return histogram.getPlotEndHeight();
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
	case WXPLOT_TYPE_HIST:
		histogram.drawFigure(dc);
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
	case WXPLOT_TYPE_HIST:
		histogram.drawTicks(dc);
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
	case WXPLOT_TYPE_HIST:
		histogram.drawGrid(dc);
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
	case WXPLOT_TYPE_HIST:
		histogram.drawLegend(dc);
		break;
	default:
		proportional.drawLegend(dc);
		break;
	}
}