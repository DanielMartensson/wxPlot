#pragma once

#include "../lists/colours.hpp"
#include <vector>

/**
 * @brief Finds the minimum and maximum values in a 1D data vector.
 *
 * This function iterates through the provided 1D data vector and finds
 * the smallest and largest values, storing them in the references provided.
 *
 * @param data1D The input 1D data vector.
 * @param minLimit Reference to store the minimum value.
 * @param maxLimit Reference to store the maximum value.
 */
void findMaxMin1Ddata(const std::vector<double>& data1D, double& minLimit, double& maxLimit);

/**
 * @brief Creates histogram data from 1D data.
 *
 * This function takes the 1D data vector and creates a histogram with the
 * specified number of bins between minY and maxY, counting the number of
 * occurrences of each value within the corresponding bins.
 *
 * @param data1D The input 1D data vector.
 * @param minY The minimum value for the histogram's Y-axis.
 * @param maxY The maximum value for the histogram's Y-axis.
 * @param binCount The number of bins to divide the data into.
 * @return A vector containing the histogram data.
 */
std::vector<double> createHistogramData(const std::vector<double>& data1D, const double minY, const double maxY, const unsigned int binCount);

/**
 * @brief Sets the pen color for drawing in wxDC.
 *
 * This function sets the color of the pen used for drawing in a wxDC
 * (wxWidgets Drawing Context) to the specified color from the plot's
 * predefined color palette.
 *
 * @param dc The wxDC context where the pen color is applied.
 * @param penColour The color index to be applied to the pen.
 */
void setColourPen(wxDC& dc, const int penColour);

/**
 * @brief Sets the brush color for filling areas in wxDC.
 *
 * This function sets the color of the brush used for filling shapes in
 * a wxDC (wxWidgets Drawing Context) to the specified color from the
 * plot's predefined color palette.
 *
 * @param dc The wxDC context where the brush color is applied.
 * @param brushColour The color index to be applied to the brush.
 */
void setColourBrush(wxDC& dc, const int brushColour);

/**
 * @brief Sets the text color for drawing text in wxDC.
 *
 * This function sets the color of the text and its background in a
 * wxDC (wxWidgets Drawing Context) to the specified values.
 *
 * @param dc The wxDC context where the text color is applied.
 * @param textColour The color index to be applied to the text.
 * @param backgroundColour The color index to be applied to the background.
 */
void setColourText(wxDC& dc, const int textColour, const int backgroundColour);

/**
 * @brief Scales a value linearly along the X-axis.
 *
 * This function performs a linear transformation of the value on the X-axis,
 * mapping it from one range to another.
 *
 * @param value The value to be transformed.
 * @param oldMinLimit The old minimum value of the X-axis range.
 * @param newMinLimit The new minimum value of the X-axis range.
 * @param oldMaxLimit The old maximum value of the X-axis range.
 * @param newMaxLimit The new maximum value of the X-axis range.
 * @return The scaled value.
 */
double linearScalarXaxis(const double value, const double oldMinLimit, const double newMinLimit, const double oldMaxLimit, const double newMaxLimit);

/**
 * @brief Scales a value linearly along the Y-axis.
 *
 * This function performs a linear transformation of the value on the Y-axis,
 * mapping it from one range to another.
 *
 * @param value The value to be transformed.
 * @param oldMinLimit The old minimum value of the Y-axis range.
 * @param newMinLimit The new minimum value of the Y-axis range.
 * @param oldMaxLimit The old maximum value of the Y-axis range.
 * @param newMaxLimit The new maximum value of the Y-axis range.
 * @return The scaled value.
 */
double linearScalarYaxis(const double value, const double oldMinLimit, const double newMinLimit, const double oldMaxLimit, const double newMaxLimit);

/**
 * @brief Checks the size of a 2D data vector.
 *
 * This function verifies whether the given 2D data vector is non-empty
 * and has consistent sizes for each inner vector (i.e., each row).
 *
 * @param data2D The input 2D data vector to check.
 * @return True if the 2D data vector is valid and all rows have the same size, false otherwise.
 */
bool check2DdataSize(const std::vector<std::vector<double>>& data2D);

/**
 * @brief Finds the minimum and maximum values in a 2D data vector.
 *
 * This function finds the minimum and maximum values across both axes
 * (X and Y) of a 2D data vector and stores the results in the references provided.
 *
 * @param data2D The input 2D data vector.
 * @param minX Reference to store the minimum value for the X-axis.
 * @param maxX Reference to store the maximum value for the X-axis.
 * @param minY Reference to store the minimum value for the Y-axis.
 * @param maxY Reference to store the maximum value for the Y-axis.
 */
void findMaxMin2Ddata(const std::vector<std::vector<double>>& data2D, double& minX, double& maxX, double& minY, double& maxY);