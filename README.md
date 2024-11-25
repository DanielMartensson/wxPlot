# wxPlot V1.8

This project is called `wxPlot`. The project was created due to the lack of visualization tools that can be used in real time. Historically, there have been older libraries for wxWidgets at SourceForge that can offer graphical visualization of data. I made the decision to create an additional data visualization tool - `wxPlot`. But with a different starting point. The goal of this project is to be able to offer a visualization tool together with a proper documentation for further development. The visualization tool for the data must not have any dependencies on other libraries and the visualization tool must always be able to run in real time. The code is written in the latest standard of modern C++.

wxPlot does not require any use of GPU.

# Features and goals

- Dynamic resizing
- No dependencies at all
- Real-time plotting
- 2D plots and 3D plots
- MATLAB inspired
- Documentation about how to add your own plot into the library

# Usage

The `wxPlot` library make its data visualization once `plot->Refresh();` is called.

```cpp
// Create plot
wxPlot* plot = new wxPlot(this, WXPLOT_FIGURE_2D, WXPLOT_TYPE_SPLINE_SCATTER);
    
// Create data for line, scatter and spline - 2D
std::vector<std::vector<double>> data1 = { {0, 100, 200, 300, 400, 500}, {-10, -15 , -30, 20, 25, 30},  // Temperature (X, Y)
                                          { 0, 200, 300, 400, 500, 600 }, {0, 20 , 30, 35, 40, 42} };   // Speed (X, Y)

// Create data for bar - 1D
std::vector<double> data2 = {-15.6, 20, 10, 50, 10, -80, 20 };

// Create data for hist - 1D
std::vector<double> data3 = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 20, 20, 30, 30, 30, 40, 50, 50, 50, 50, 50, 50, 5, 5, 5, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};

// Legend
std::vector<wxString> legend = { "Temperature", "Speed", "Velocity", "Pressure", "Acceleration", "Lumination", "Distance"};

// Settings
plot->setFontSize(13);
plot->setTitle("Measurement");
plot->setYlabel("Placement for units e.g [m/s]");
plot->setXlabel("Time e.g [s] or [h]");
plot->setTicks(5);
plot->legendOn(false);
plot->gridOn(true);
plot->setRadius(5);
plot->fillCircles(true);
plot->setBinCount(8);

// Set data 
plot->setData(data3);
plot->setYlim(0, 15); // Put this directly after setData() for tuning the Y-axis

// Set legend
plot->setLegend(legend, PLACEMENT_SOUTH_WEST);

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

Bar plot

![a](https://github.com/DanielMartensson/wxPlot/blob/main/pictures/bar_plot_ready.png?raw=true)

Histogram plot

![a](https://github.com/DanielMartensson/wxPlot/blob/main/pictures/histogram.png?raw=true)

# Build & Installation
Example on building with CMake and Ninja.
Before building make sure wxWidgets is installed and can be found on the system. Navigate to the folder wxPlot and run the following to build the project:
```
> pwd
(your path to repo)/wxPlot/wxPlot
> mkdir build
> cmake -DCMAKE_BUILD_TYPE=Release -G Ninja -S . -B ./build
> ninja -C ./build
> ./build/wxPlot
```

# TODO

- 3D plot
- More MATLAB inspired use

# Tutorial - Add your own plot

Go to [How to create your own plot](https://github.com/DanielMartensson/wxPlot/tree/main/wxPlot/README.md)