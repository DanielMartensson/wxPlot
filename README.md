# wxPlot V1.5

This project is called `wxPlot`. The project was created due to the lack of visualization tools that can be used in real time. Historically, there have been older libraries for wxWidgets at SourceForge that can offer graphical visualization of data. I made the decision to create an additional data visualization tool - `wxPlot`. But with a different starting point. The goal of this project is to be able to offer a visualization tool together with a proper documentation for further development. The visualization tool for the data must not have any dependencies on other libraries and the visualization tool must always be able to run in real time. The code is written in the latest standard of modern C++.

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
plot->setYlim(-30, 50); // This must be added before every setData() function to recreate the limits

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

Bar plot

![a](https://github.com/DanielMartensson/wxPlot/blob/main/pictures/bar_plot_best.png?raw=true)

# TODO

- Histogram plot
- 3D plot
- More MATLAB inspired use

# Tutorial - Add your own plot

Go to [How to create your own plot](https://github.com/DanielMartensson/wxPlot/tree/main/wxPlot/README.md)