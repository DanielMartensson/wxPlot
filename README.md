# wxPlot V1.1

This project is called `wxPlot`. The project was created due to the lack of visualization tools that can be used in real time. Historically, there have been older libraries for wxWidgets at SourceForge that can offer graphical visualization of data. I made the decision to create an additional data visualization tool - `wxPlot`. But with a different starting point. The goal of this project is to be able to offer a visualization tool together with a proper documentation for further development. The visualization tool for the data must not have any dependencies on other libraries and the visualization tool must always be able to run in real time. The code is written in the latest standard of modern C++.

# Features and goals

- Dynamic resizing
- No dependencies
- Real-time plotting
- 2D plots and 3D plots
- MATLAB inspired
- Documentation about how to add your own plot into the library

# Usage

The `wxPlot` library make its data visualization once `plot->Refresh();` is called.

```cpp
// Create plot
wxPlot* plot = new wxPlot(this, WXPLOT_FIGURE_2D, WXPLOT_TYPE_SPLINE_SCATTER);

// Create data
std::vector<std::vector<double>> data = { {0, 100, 200, 300, 400, 500}, {-10, -15 , -30, 20, 25, 30}, // Temperature (X, Y)
                                          { 0, 200, 300, 400, 500, 600 }, {0, 20 , 30, 35, 40, 42} }; // Speed (X, Y)

// Legend
std::vector<wxString> legend = { "Temperature", "Speed" };

// Settings
plot->setFontSize(13);
plot->setTitle("Measurement");
plot->setYlabel("Placement for units e.g [m/s]");
plot->setXlabel("Time e.g [s] or [h]");
plot->setTicks(5);
plot->legendOn(true);
plot->gridOn(true);
plot->setRadius(5);
plot->fillCircles(true);

// Set data
plot->setData(data);

// Set legend
plot->setLegend(legend, PLACEMENT_NORTH_EAST);

// Set sizes
plot->setPlotStartWidth(5);     // x1
plot->setPlotStartHeight(5);    // y1
plot->setPlotEndWidth(500);     // x2
plot->setPlotEndHeight(500);    // y2

// Render the plot
plot->Refresh();
```

To render the plot on size:

```cpp
void MainFrame::OnSize(wxSizeEvent& event) {
    // If we don't use this, then refresh won't work
    event.Skip();

    // Get window size
    wxCoord startWidth = 0, startHeight = 0, endWidth, endHeight;
    GetClientSize(&endWidth, &endHeight);

    // Redraw plot
    plot->setPlotStartWidth(startWidth);
    plot->setPlotStartHeight(startHeight);
    plot->setPlotEndWidth(endWidth);
    plot->setPlotEndHeight(endHeight);
    plot->Refresh();
}
```

To render the plot on command:

```cpp
void MainFrame::OnCommand(wxCommandEvent& event){
    // If we don't use this, then refresh won't work
    event.Skip();

    // Get window size
    wxCoord startWidth = 0, startHeight = 0, endWidth, endHeight;
    GetClientSize(&endWidth, &endHeight);

    // Redraw plot
    plot->setPlotStartWidth(startWidth);
    plot->setPlotStartHeight(startHeight);
    plot->setPlotEndWidth(endWidth);
    plot->setPlotEndHeight(endHeight);
    plot->Refresh();
}
```

# Pictures

Line plot with no filled scatters

![a](https://github.com/DanielMartensson/wxPlot/blob/main/pictures/2D_line_scatter_no_fill.png?raw=true)

Line plot with filled scatters

![a](https://github.com/DanielMartensson/wxPlot/blob/main/pictures/2d_line_scatter_fill_large.png?raw=true)

Spline plot

![a](https://github.com/DanielMartensson/wxPlot/blob/main/pictures/2D_spline_no_scatter.png?raw=true)

Spline plot with filled scatters

![a](https://github.com/DanielMartensson/wxPlot/blob/main/pictures/2D_spline_with_scatter_fill.png?raw=true)


# TODO

- Histogram plot
- 3D plot
- More MATLAB inspired use

# Tutorial - Add your own plot

To make an own plot you need to first make sure that type of figure you want to use. Head over to the `plotfigures.h` file. In this case
we can se that `WXPLOT_FIGURE_2D` is available at this moment. It's planned for 3D as well. We decided to use 2D in this tutorial. 

```cpp
#pragma once

typedef enum {
	WXPLOT_FIGURE_2D
	// Add more here
}WXPLOT_FIGURE;
```

The next step is to go to the file `plottypes.h` and see what it can offer. Let's say we want to add a `bar` plot to `wxPlot`.

```cpp
#pragma once

typedef enum {
	WXPLOT_TYPE_LINE,
	WXPLOT_TYPE_SCATTER,
	WXPLOT_TYPE_LINE_SCATTER,
	WXPLOT_TYPE_SPLINE,
	WXPLOT_TYPE_SPLINE_SCATTER
	// Add more here
}WXPLOT_TYPE;
```
Just add in `WXPLOT_TYPE_BAR` 

```cpp
#pragma once

typedef enum {
	WXPLOT_TYPE_LINE,
	WXPLOT_TYPE_SCATTER,
	WXPLOT_TYPE_LINE_SCATTER,
	WXPLOT_TYPE_SPLINE,
	WXPLOT_TYPE_SPLINE_SCATTER,
	WXPLOT_TYPE_BAR
	// Add more here
}WXPLOT_TYPE;
```

Further, go to the `2Dfigure.cpp` and add new code to all `draw`-functions and `get`-functions, e.g this.

```cpp
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
	case WXPLOT_TYPE_BAR:
		return proportional.getPlotEndWidth(); <--- NEW
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
	case WXPLOT_TYPE_BAR:
		proportional.drawFigure(dc); <--- NEW
		break;
	default:
		proportional.drawFigure(dc);
		break;
	}
}
``` 

The object `proportional` is from the class `Proportional` inside the class `_2DFigure`. That class writes the following:

* Rectangle
* Grid
* Legend
* Ticks
* X, Y, title labels
* Fonts

Consider the use of `proportional` when you want to have a proportional plot in both X-axis and Y-axis. If you want to use a logarithmic plot, then you need to use another object rather than `proportional`, that can draw the rectangle, grid, legend, ticks, labels and fonts.
Most of the time, you can just inherit most of the code from the class `Proportional`. The rectangle, legend, labels, fonts would be the same for a logarithmic plot. Only the grid and the ticks would differ.

After you have done the configuration for the `figure`. Now it's time for add code for the actuall plot - drawing on the rectangle!
In this case, we are focusing on `2D` plots. Head over to the `2Dtype.h` file and add new new object `Bar bar;` under private. Don't forget to add `#include "bar/bar.h"` as well!

```cpp
#pragma once

#include "line/line.h"
#include "scatter/scatter.h"
#include "spline/spline.h"
#include "bar/bar.h" <--- NEW
#include "../../plottools/plottools.h"

class _2DType {

private:
	// Type select
	WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE;

	// The data
	std::vector<std::vector<double>> data;

	// Charts
	Line line;
	Scatter scatter;
	Spline spline;
        Bar bar; <--- NEW

public:
	// Constructor
	_2DType() { }

	// Setters
	void setWxPlotType(const WXPLOT_TYPE wxPlotType);
	void setRadius(const wxCoord radius);
	void fillCircles(const bool fillCircle);
	void setData(const std::vector<std::vector<double>>& data);
	void setPlotStartWidth(const wxCoord plotStartWidth);
	void setPlotStartHeight(const wxCoord plotStartHeight);
	void setPlotEndWidth(const wxCoord plotEndWidth);
	void setPlotEndHeight(const wxCoord plotEndHeight);

	// Functions
	bool drawType(wxDC& dc);
};
```

Create a folder called `bar` inside `plots/plottypes/2D` where `line`, `scatter` and `spline` are. Inside the `bar` folder. Add `bar.h` and `bar.cpp`

Inside `bar.h`, paste this. Here we are inherit most of the protected fields and public functions from the `Line` class. You don't need to do anything more here. 

```cpp
#pragma once

#include <vector>
#include <wx/wx.h>
#include "../line/line.h"

class Bar : public Line {
private:

public:
	// Functions
	bool draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const int colourIndex) override;
};
```

Head over to `2Dtype.cpp` file and add code to all `set`-functions.

```cpp
void _2DType::setData(const std::vector<std::vector<double>>& data) {
	this->data = data;

	// Find max and min for the complete data, or else, we will get very weird scaling inside the plot
	double minX, maxX, minY, maxY;
	findMaxMin2Ddata(data, minX, maxX, minY, maxY);

	// Set the limits
	line.setLimits(minX, maxX, minY, maxY);
	scatter.setLimits(minX, maxX, minY, maxY);
	spline.setLimits(minX, maxX, minY, maxY);
	bar.setLimits(minX, maxX, minY, maxY); <--- NEW
}

void _2DType::setPlotStartWidth(const wxCoord plotStartWidth) {
	line.setPlotStartWidth(plotStartWidth);
	scatter.setPlotStartWidth(plotStartWidth);
	spline.setPlotStartWidth(plotStartWidth);
	bar.setPlotStartWidth(plotStartWidth); <--- NEW
}
```

Some functions have only a unique functionality e.g `scatter`-plot. If you want to have a unique functionality to the `bar`-plot, then you need to write a specific `set`-function for that. Here is just one example how I can set the radius and fill circles for the `scatter`-plot. These won't effect the `bar`-plot.

```cpp
void _2DType::setRadius(const wxCoord radius) {
	scatter.setRadius(radius);
}

void _2DType::fillCircles(const bool fillCircle) {
	scatter.fillCircles(fillCircle);
}
``` 

The second last thing you need to do is to add code inside the `bool _2DType::drawType(wxDC& dc)` function. Same `2Dtype.cpp` file. Add the new `bar.draw(dc, xData, yData, colourIndex)` as a new case.

```cpp
// Draw type now
switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		line.draw(dc, xData, yData, colourIndex);
		break;
	case WXPLOT_TYPE_SCATTER:
		scatter.draw(dc, xData, yData, colourIndex);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		line.draw(dc, xData, yData, colourIndex);
		scatter.draw(dc, xData, yData, colourIndex);
		break;
	case WXPLOT_TYPE_SPLINE:
		spline.draw(dc, xData, yData, colourIndex);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		spline.draw(dc, xData, yData, colourIndex);
		scatter.draw(dc, xData, yData, colourIndex);
		break;
	case WXPLOT_TYPE_BAR:
		bar.draw(dc, xData, yData, colourIndex); <--- NEW
		break;
	default:
		break;
}
```

The last thing you need to do is to add code to `bar.cpp`. The one you just created above, but did not wrote anyting in to it.
Let's try out this code. It won't be Beautiful, but it can give us some suggestions about what should to fixed.

```cpp
#include "bar.h"
#include "../../../plottools/plottools.h"

bool Bar::draw(wxDC& dc, const std::vector<double>& xData, const std::vector<double>& yData, const int colourIndex) {
	// Set rectangle colour
	setColourPen(dc, colourIndex);
	setColourBrush(dc, colourIndex);

	// Draw rectangles
	const size_t dataLength = xData.size();
	const wxCoord width = (plotEndWidth - plotStartHeight) / dataLength;
	for (size_t j = 0; j < dataLength; j++) {
		const wxCoord x = linearScalarXaxis(xData.at(j), minX, plotStartWidth, maxX, plotEndWidth);
		const wxCoord y = linearScalarYaxis(yData.at(j), minY, plotStartHeight, maxY, plotEndHeight);
		const wxCoord height = plotEndHeight - y;
		dc.DrawRectangle(x, y, width, height);
	}

	// Nothing went wrong
	return true;
}
```

With this data:

```cpp
// Create data for bar
std::vector<std::vector<double>> data = { {0}, {15}, 
                                          {1}, {20}, 
                                          {2}, {10}, 
                                          {3}, {50}, 
                                          {4}, {10}, 
                                          {5}, {-10} };

plot->setData(data);
```

It would look something like this. Here we can see that the Y-ticks are placed after max and minimum of `2D` vector. The minimum data of `data` 2D vector above, is `-10` and maximum value is `50`.

![a](https://github.com/DanielMartensson/wxPlot/blob/main/pictures/bad_bar_plot.png?raw=true)

If we are using this data, that not contains any negative numbers, we can confirm that the Y-ticks are placed wrong.

```cpp
// Create data for bar
std::vector<std::vector<double>> data = { {0}, {15}, 
                                          {1}, {20}, 
                                          {2}, {10}, 
                                          {3}, {50}, 
                                          {4}, {10}, 
                                          {5}, {-10} };

plot->setData(data);
```

![a](https://github.com/DanielMartensson/wxPlot/blob/main/pictures/bad_bar_plot2.png?raw=true)

To solve this issue, we need to change the `minY` so the `Y`-ticks are displayed correctly. One good option is to head over
to `proportional.cpp` and add this. So if `minY` is positive, turn it to `0`, only for `bar` or other column charts.

```cpp
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

		// Only for column charts such as bar, histogram etc. <--- NEW
		switch (wxPlotType) {
		case WXPLOT_TYPE_BAR:
			if (minY > 0) {
				minY = 0;
			}
			break;
		}
```

After few hours of figure how to make a proper column setup as a bar plot. This results this code. As you can see, there was no use of `X`-data for displaying the `X`-axis.

```cpp
#include "bar.h"
#include "../../../plottools/plottools.h"

bool Bar::draw(wxDC& dc, const double yData, const int colourIndex, const size_t dataSize, const size_t i) {
	// Set rectangle colour
	setColourPen(dc, colourIndex);
	setColourBrush(dc, colourIndex);

	// Some parameter
	const wxCoord width = (plotEndWidth - plotStartWidth) / dataSize;

	// Draw rectangle
	const wxCoord x = plotStartWidth + width * i;
	const wxCoord y = linearScalarYaxis(yData, minY, plotStartHeight, maxY, plotEndHeight);
	const wxCoord y0 = linearScalarYaxis(0, minY, plotStartHeight, maxY, plotEndHeight);
	const wxCoord yMin = linearScalarYaxis(minY, minY, plotStartHeight, maxY, plotEndHeight);
	const wxCoord delta = yMin - y0;
	const wxCoord height = plotEndHeight - y - delta;
	dc.DrawRectangle(x, y, width, height);
	
	// Nothing went wrong
	return true;
}

```

![a](https://github.com/DanielMartensson/wxPlot/blob/main/pictures/bar_plot.png?raw=true)

