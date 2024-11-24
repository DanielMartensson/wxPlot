#pragma once

#include <wx/wx.h>
#include "../../wxplot.hpp"

/**
 * @class MainFrame
 * @brief This class represents the main example window for the application.
 *
 * The `MainFrame` class is a wxWidgets frame that acts as the main user interface
 * for the application. It contains wxPlot, and provides event handlers
 * for various events such as menu actions and window resizing.
 *
 * This frame is just an example responsible for setting up the UI, handling user interaction,
 * and managing the overall plot display.
 */
class MainFrame : public wxFrame
{
private:

    wxPlot* plot;    ///< This is the pointer of the wxPlot. It contains both plot type and plot figure.

    /**
     * @brief Event handler for the "Hello" menu action.
     *
     * This method is invoked when the user selects the "Hello" option from the menu.
     * It can be used to display a greeting or perform a specific action.
     *
     * @param event The event triggered by the menu action.
     * @return void
     */
    void OnHello(wxCommandEvent& event);

    /**
     * @brief Event handler for the "Exit" menu action.
     *
     * This method is invoked when the user selects the "Exit" option from the menu.
     * It closes the application or the current window.
     *
     * @param event The event triggered by the menu action.
     * @return void
     */
    void OnExit(wxCommandEvent& event);

    /**
     * @brief Event handler for window resizing.
     *
     * This method is invoked when the window is resized. It allows you to adjust
     * the layout or update any visual elements according to the new window size.
     *
     * @param event The event triggered by the window resizing action.
     * @return void
     */
    void OnSize(wxSizeEvent& event);

public:
    /**
     * @brief Constructor for the MainFrame class.
     *
     * Initializes the main window, sets up the plot area, and binds event handlers
     * to various user interactions such as clicking the "Hello" button and resizing
     * the window.
     */
    MainFrame();
};