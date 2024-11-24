#include "plots.hpp"

PlotTypes& Plots::getPlotTypes() {
	return plotTypes; 
}
PlotFigure& Plots::getPlotFigures() {
	return plotFigures; 
}

void Plots::setWxPlotFigureType(const WXPLOT_FIGURE wxPlotFigure, const WXPLOT_TYPE wxPlotType) {
	plotTypes.setWxPlotFigureType(wxPlotFigure, wxPlotType);
	plotFigures.setWxPlotFigureType(wxPlotFigure, wxPlotType);
}

void Plots::setData(const std::vector<std::vector<double>>& data2D) {
	plotTypes.setData(data2D);
	plotFigures.setData(data2D);
}

void Plots::setData(const std::vector<double>& data1D) {
	plotTypes.setData(data1D);
	plotFigures.setData(data1D);
}