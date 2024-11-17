#pragma once

#include "../lists/colours.h"
#include <vector>

void findMaxMin1Ddata(const std::vector<double>& data, double& minLimit, double& maxLimit);
void setColourPen(wxDC& dc, const int penColour);
void setColourBrush(wxDC& dc, const int brushColour);
void setColourText(wxDC& dc, const int textColour, const int backgroundColour);
double linearScalarXaxis(const double value, const double oldMinLimit, const double newMinLimit, const double oldMaxLimit, const double newMaxLimit);
double linearScalarYaxis(const double value, const double oldMinLimit, const double newMinLimit, const double oldMaxLimit, const double newMaxLimit);
bool check2DdataSize(const std::vector<std::vector<double>>& data);
void findMaxMin2Ddata(const std::vector<std::vector<double>>& data, double& minX, double& maxX, double& minY, double& maxY);