#include "plots.h"

void Plots::setWxPlotFigureType(const WXPLOT_FIGURE wxPlotFigure, const WXPLOT_TYPE wxPlotType) {
	plotTypes.setWxPlotFigureType(wxPlotFigure, wxPlotType);
	plotFigures.setWxPlotFigureType(wxPlotFigure, wxPlotType);
}
void Plots::setData(const std::vector<std::vector<double>>& data) {
	plotTypes.setData(data);
	plotFigures.setData(data);
}