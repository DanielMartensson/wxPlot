
#include "mainframe.h"

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "wxPlot")
{
    // File menu
    wxMenu* menuFile = new wxMenu();
    menuFile->Append(wxID_FILE, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    // Edit manu
    wxMenu* menuEdit = new wxMenu;
    menuEdit->Append(wxID_OPEN, "&Connect");

    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuEdit, "&Edit");
    SetMenuBar(menuBar);

    // Statusbar
    CreateStatusBar();
    SetStatusText("Welcome to wxPlot!");

    // Create plot
    plot = new wxPlot(this, WXPLOT_FIGURE_2D, WXPLOT_TYPE_SPLINE_SCATTER);

    // Create data for line, scatter and spline - 2D
    std::vector<std::vector<double>> data1 = { {0, 100, 200, 300, 400, 500}, {-10, -15 , -30, 20, 25, 30},  // Temperature (X, Y)
                                              { 0, 200, 300, 400, 500, 600 }, {0, 20 , 30, 35, 40, 42} };   // Speed (X, Y)

    // Create data for bar - 1D
    std::vector<double> data2 = {-15.6, 20, 10, 50, 10, -80, 20 };

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
    plot->setData(data1);
    //plot->setYlim(-25, 30);

    // Set legend
    plot->setLegend(legend, PLACEMENT_NORTH_EAST);

    // Set sizes
    plot->setPlotStartWidth(5);     // x1
    plot->setPlotStartHeight(5);    // y1
    plot->setPlotEndWidth(500);     // x2
    plot->setPlotEndHeight(500);    // y2

    // Render the plot
    plot->Refresh();

    // Events
    Bind(wxEVT_MENU, &MainFrame::OnHello, this, wxID_FILE);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_SIZE, &MainFrame::OnSize, this);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}


void MainFrame::OnHello(wxCommandEvent& event){
    // If we don't use this, then refresh won't work
    event.Skip();

    // Get window size
    wxCoord startWidth = 0, startHeight = 0, endWidth, endHeight;
    GetClientSize(&endWidth, &endHeight);

    // Redraw figure
    plot->setPlotStartWidth(startWidth);
    plot->setPlotStartHeight(startHeight);
    plot->setPlotEndWidth(endWidth);
    plot->setPlotEndHeight(endHeight);
    plot->Refresh();
}

void MainFrame::OnSize(wxSizeEvent& event) {
    // If we don't use this, then refresh won't work
    event.Skip();

    // Get window size
    wxCoord startWidth = 0, startHeight = 0, endWidth, endHeight;
    GetClientSize(&endWidth, &endHeight);

    // Redraw figure
    plot->setPlotStartWidth(startWidth);
    plot->setPlotStartHeight(startHeight);
    plot->setPlotEndWidth(endWidth);
    plot->setPlotEndHeight(endHeight);
    plot->Refresh();

}