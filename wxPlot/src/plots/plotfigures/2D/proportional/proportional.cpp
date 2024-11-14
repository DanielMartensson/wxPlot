#include "proportional.h"
#include <cmath>

/*
 * This function will do the following:
 * - Set the font
 * - Draw the title
 * - Draw the y-label
 * - Draw the x-label
 * - Draw the rectangle
 * - Update the rectangle size for correct plotting the plot type
 */
bool Proportional::drawFigure(wxDC& dc) {

	// Check the size
	if (!check2DdataSize(data)) {
		return false; // Missing an axis
	}

	// Set the font, or get the font size
	if (fontSize) {
		dc.SetFont(wxFont(fontSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	}
	else {
		fontSize = dc.GetFont().GetPointSize();
	}

	// Set default size on the rectangle
	wxCoord yStartRectangle = plotStartHeight;
	wxCoord xStartRectangle = plotStartWidth;
	wxCoord heightRectangle = plotEndHeight;
	wxCoord widthRectangle = plotEndWidth;

	// Set color
	setColourPen(dc, PLOT_COLOUR_BLACK);

	// Compute the width and height of the ticks
	wxCoord ticksWidth = 0, ticksHeight = 0;
	if (ticks > 0) {
		double minX, maxX, minY, maxY;
		findMaxMin2Ddata(data, minX, maxX, minY, maxY);
		char value[100];
		std::snprintf(value, sizeof(value), "%0.2f", maxY > std::abs(minY) ? maxY : minY); // Sometimes a negative number can be longer than a positive number
		dc.GetTextExtent(value, &ticksWidth, &ticksHeight);
	}

	// Compute width and height of the title
	wxCoord titleWidth = 0, titleHeight = 0;
	if (title.length() > 0) {
		dc.GetTextExtent(title, &titleWidth, &titleHeight);
	}

	// Compute width and height of the X-label
	wxCoord xLabelWidth = 0, xLabelHeight = 0;
	if (xLabel.length() > 0) {
		dc.GetTextExtent(xLabel, &xLabelWidth, &xLabelHeight);
	}

	// Compute width and height of the Y-label
	wxCoord yLabelWidth = 0, yLabelHeight = 0;
	if (yLabel.length() > 0) {
		dc.GetTextExtent(yLabel, &yLabelWidth, &yLabelHeight);
	}

	// Write out in X-axis - Add some 5 and 10 to make a proper distance between rectangle and numbers
	wxCoord x = plotEndWidth / 2 - titleWidth / 2;												// Compute the centre of the title
	wxCoord y = 0;																				// Compute the hight placement of the title
	dc.DrawText(title, x, y);																	// Draw title
	yStartRectangle += titleHeight + 5;															// Move down the start of the rectangle
	heightRectangle -= titleHeight;																// Decrease the height of the rectangle
	heightRectangle -= ticksHeight + xLabelHeight + 10;											// Make room for ticks and X-label						
	x = plotEndWidth / 2 - xLabelWidth / 2;														// Compute the centre of the X-label
	y = heightRectangle + (ticksHeight > 0) * xLabelHeight + (titleHeight > 0) * xLabelHeight;	// Compute the hight placement of the X-label
	dc.DrawText(xLabel, x, y + 5);																// Draw X-label

	// Write out in Y-axis - Add some 5 and 10 to make a proper distance between rectangle and numbers
	x = 0;																						// Compute the width placement of the Y-label
	y = plotEndHeight / 2 + yLabelWidth / 2;													// Compute the centre of the title
	dc.DrawRotatedText(yLabel, x, y, 90);														// Draw Y-label
	xStartRectangle += yLabelHeight + ticksWidth + 5;											// Strafe left the start of the rectangle
	widthRectangle -= yLabelHeight + ticksWidth + 10;											// Decrease the width of the rectangle

	// Update the size
	plotStartHeight = yStartRectangle;
	plotStartWidth = xStartRectangle;
	plotEndHeight = heightRectangle + yStartRectangle;
	plotEndWidth = widthRectangle + xStartRectangle;

	// Draw rectangle frame
	dc.DrawRectangle(xStartRectangle, yStartRectangle, widthRectangle, heightRectangle);

	// Nothing went wrong
	return true;
}

/*
 * This function draw the ticks.
 * Call this function after you have drawn the plot type.
 */
void Proportional::drawTicks(wxDC& dc) {
	if (ticks > 0) {
		const wxCoord yStartRectangle = plotStartHeight;
		const wxCoord xStartRectangle = plotStartWidth;
		const wxCoord heightRectangle = plotEndHeight - plotStartHeight;
		const wxCoord widthRectangle = plotEndWidth - plotStartWidth;

		// Set color - Black
		wxPen pen(plotColours.at(PLOT_COLOUR_BLACK));
		dc.SetPen(pen);

		// Compute the minimum and maximum value from the data for correct scaling
		double minX, maxX, minY, maxY;
		findMaxMin2Ddata(data, minX, maxX, minY, maxY);

		// Compute steps
		const unsigned int stepsX = (xStartRectangle + widthRectangle) / (ticks-1);
		const unsigned int stepsY = (yStartRectangle + heightRectangle) / (ticks-1);

		// Compute scalars
		const double scalarX = (maxX - minX) / (ticks-1);
		const double scalarY = (minY - maxY) / (ticks-1);

		// Counter
		double counter = 0;

		// Vertical ticks
		wxCoord textWidth, textHeight;
		char value[100];
		for (wxCoord x = xStartRectangle; x <= xStartRectangle + widthRectangle; x += stepsX) {
			std::snprintf(value, sizeof(value), "%0.2f", maxX + scalarX * counter);
			dc.GetTextExtent(value, &textWidth, &textHeight);
			dc.DrawText(value, x - textWidth / 2, yStartRectangle + heightRectangle);
			counter++;
		}
		std::snprintf(value, sizeof(value), "%0.2f", maxX + scalarX * counter);
		dc.GetTextExtent(value, &textWidth, &textHeight);
		dc.DrawText(value, xStartRectangle + widthRectangle - textWidth, yStartRectangle + heightRectangle);

		// Horizontal ticks
		counter = 0;
		for (wxCoord y = yStartRectangle; y <= yStartRectangle + heightRectangle; y += stepsY) {
			std::snprintf(value, sizeof(value), "%0.2f", maxY + scalarY * counter);
			dc.GetTextExtent(value, &textWidth, &textHeight);
			dc.DrawText(value, xStartRectangle - textWidth - 2, y - textHeight);  // 2 is only for make a proper distance from rectangle
			counter++;
		}
		std::snprintf(value, sizeof(value), "%0.2f", maxY + scalarY * counter);
		dc.GetTextExtent(value, &textWidth, &textHeight);
		dc.DrawText(value, xStartRectangle - textWidth - 2 , yStartRectangle + heightRectangle - textHeight); // 2 is only for make a proper distance from rectangle
	}
}

/*
 * This function draw the grid.
 * Call this function after you have drawn the plot type.
 */
void Proportional::drawGrid(wxDC& dc) {
	if (useGrid && ticks > 0) {
		const wxCoord yStartRectangle = plotStartHeight;
		const wxCoord xStartRectangle = plotStartWidth;
		const wxCoord heightRectangle = plotEndHeight - plotStartHeight;
		const wxCoord widthRectangle = plotEndWidth - plotStartWidth;

		// Set color - Black
		wxPen pen(plotColours.at(PLOT_COLOUR_BLACK));
		dc.SetPen(pen);

		// Compute steps
		const unsigned int stepsX = (xStartRectangle + widthRectangle) / (ticks-1);
		const unsigned int stepsY = (yStartRectangle + heightRectangle) / (ticks-1);

		// Vertical lines
		for (wxCoord x = xStartRectangle; x <= xStartRectangle + widthRectangle; x += stepsX) {
			dc.DrawLine(x, yStartRectangle, x, yStartRectangle + heightRectangle);
		}

		// Horizontal lines
		for (wxCoord y = yStartRectangle; y <= yStartRectangle + heightRectangle; y += stepsY) {
			dc.DrawLine(xStartRectangle, y, xStartRectangle + widthRectangle, y);
		}
	}
}

/*
 * This function writes the legend
 */
void Proportional::drawLegend(wxDC& dc) {
	if (useLegend) {
		const wxCoord yStartRectangle = plotStartHeight;
		const wxCoord xStartRectangle = plotStartWidth;
		const wxCoord heightRectangle = plotEndHeight - plotStartHeight;
		const wxCoord widthRectangle = plotEndWidth - plotStartWidth;

		// Get the size of the legend
		const size_t legendSize = legend.size();

		// Get the largest text width
		wxCoord textWidth, textHeight;
		wxCoord largestTextWidth = 0, largestTextHeight = 0;
		for (size_t i = 0; i < legendSize; i++) {
			dc.GetTextExtent(legend.at(i), &textWidth, &textHeight);
			if (i == 0) {
				largestTextWidth = textWidth;
				largestTextHeight = textHeight;
			}
			else {
				if (textWidth > largestTextWidth) {
					largestTextWidth = textWidth;
				}
				if (textHeight > largestTextHeight) {
					largestTextHeight = textHeight;
				}
			}
		}

		// Compute the coordinates where to place the legend - Add 15, 10, 5 and 2.5 to make a proper distance between rectangle and numbers
		wxCoord x = 0, y = 0;
		switch (legendPosition) {
		case PLACEMENT_NORTH_WEST:
			x = plotStartWidth + 5;
			y = plotStartHeight + 5;
			break;
		case PLACEMENT_NORTH_EAST:
			x = plotEndWidth - largestTextWidth - 15;
			y = plotStartHeight + 5;
			break;
		case PLACEMENT_SOUTH_WEST:
			x = plotStartWidth + 5;
			y = plotEndHeight - largestTextHeight * legendSize - 10;
			break;
		case PLACEMENT_SOUTH_EAST:
			x = plotEndWidth - largestTextWidth - 15;
			y = plotEndHeight - largestTextHeight * legendSize - 10;
			break;
		case PLACEMENT_CENTRE:
			x = widthRectangle / 2 + xStartRectangle - largestTextWidth / 2 - 5;
			y = heightRectangle / 2 + yStartRectangle - largestTextHeight * legendSize / 2 - 5 / 2;
			break;
		default:
			break;
		}

		// The legend should be a white box
		setColourBrush(dc, PLOT_COLOUR_WHITE);

		// Draw the legend now
		dc.DrawRoundedRectangle(x, y, largestTextWidth + 10, largestTextHeight * legendSize + 5, 2);
		for (size_t i = 0; i < legendSize; i++) {
			setColourText(dc, i, PLOT_COLOUR_WHITE);
			dc.DrawText(legend.at(i), x + 5, y + largestTextHeight * i);
		}

		// Restore to default
		setColourText(dc, PLOT_COLOUR_BLACK, PLOT_COLOUR_WHITE);
	}
}