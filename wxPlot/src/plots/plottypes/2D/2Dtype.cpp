#include "2Dtype.h"

void _2D_Type::setWxPlotType(const WXPLOT_TYPE wxPlotType) {
	this->wxPlotType = wxPlotType;
}

void _2D_Type::setRadius(const wxCoord radius) {
	scatter.setRadius(radius);
}

void _2D_Type::fillCircles(const bool fillCircle) {
	scatter.fillCircles(fillCircle);
}

void _2D_Type::setData(const std::vector<std::vector<double>>& data) {
	line.setData(data);
	scatter.setData(data);
	spline.setData(data);
}

void _2D_Type::setPlotStartWidth(const wxCoord plotStartWidth) {
	line.setPlotStartWidth(plotStartWidth);
	scatter.setPlotStartWidth(plotStartWidth);
	spline.setPlotStartWidth(plotStartWidth);
}

void _2D_Type::setPlotStartHeight(const wxCoord plotStartHeight) {
	line.setPlotStartHeight(plotStartHeight);
	scatter.setPlotStartHeight(plotStartHeight);
	spline.setPlotStartHeight(plotStartHeight);
}

void _2D_Type::setPlotEndWidth(const wxCoord plotEndWidth) {
	line.setPlotEndWidth(plotEndWidth);
	scatter.setPlotEndWidth(plotEndWidth);
	spline.setPlotEndWidth(plotEndWidth);
}

void _2D_Type::setPlotEndHeight(const wxCoord plotEndHeight) {
	line.setPlotEndHeight(plotEndHeight);
	scatter.setPlotEndHeight(plotEndHeight);
	spline.setPlotEndHeight(plotEndHeight);
}

void _2D_Type::drawType(wxDC& dc) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		line.draw(dc);
		break;
	case WXPLOT_TYPE_SCATTER:
		scatter.draw(dc);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		line.draw(dc);
		scatter.draw(dc);
		break;
	case WXPLOT_TYPE_SPLINE:
		spline.draw(dc);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		spline.draw(dc);
		scatter.draw(dc);
		break;
	default:
		break;
	}
}