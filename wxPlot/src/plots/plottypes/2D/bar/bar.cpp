#include "bar.h"
#include "../../../plottools/plottools.h"

bool Bar::draw(wxDC& dc, const std::vector<double>& data) {

	// Create counter for colour
	int colourIndex = 0;

	// Get the size of the data
	const size_t dataSize = data.size();

	// Some parameters
	const unsigned int gap = 5;
	const wxCoord width = (plotEndWidth - plotStartWidth) / dataSize - gap;
	wxCoord y0 = linearScalarYaxis(0, minY, plotStartHeight, maxY, plotEndHeight) - 1;

	// Limit on y0
	if (y0 > plotEndHeight) {
		y0 = plotEndHeight;
	}
	if (y0 < plotStartHeight) {
		y0 = plotStartHeight;
	}

	// Iterate all
	for (size_t i = 0; i < dataSize; i++) {

		// Head of the column
		wxCoord y = linearScalarYaxis(data.at(i), minY, plotStartHeight, maxY, plotEndHeight);

		// Position of the column
		const wxCoord x = plotStartWidth + (width + gap) * i;

		// If we are under the data
		if (y <= plotStartHeight && y0 < plotStartHeight) {
			return true;
		}

		// If we cut inside the data
		if (y < plotStartHeight) {
			y = plotStartHeight;
		}

		// If we are above the data
		if (y >= plotEndHeight && y0 > plotEndHeight) {
			return true;
		}

		// If we cut inside the data
		if (y >= plotEndHeight) {
			y = plotEndHeight - 1;
		}

		// Create the height
		const wxCoord height = y0 - y;

		// Set rectangle colour
		setColourPen(dc, colourIndex);
		setColourBrush(dc, colourIndex);

		// Draw the rectangle now
		dc.DrawRectangle(x + gap, y, width, height);

		// Next colour
		colourIndex++;
	}

	// Nothing went wrong
	return true;
}