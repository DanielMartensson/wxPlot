#pragma once

#include "src/frames/mainframe/mainframe.hpp"

/**
 * @class Main
 * @brief Main application class for the wxWidgets application.
 *
 * The `Main` class is the entry point for the wxWidgets application. It inherits from
 * `wxApp` and overrides the `OnInit()` method to initialize the application and
 * create the main window or frame.
 *
 * The `OnInit()` method is responsible for setting up the application's initial state,
 * including creating and displaying the main window.
 */
class Main : public wxApp
{
public:
    /**
     * @brief Initializes the application and creates the main window.
     *
     * This method is called when the application starts. It is responsible for setting
     * up the application, initializing necessary components, and creating the main
     * window (or frame) that the user will interact with.
     *
     * @return `true` if the application initialization is successful, `false` otherwise.
     */
    bool OnInit() override;
};

/**
 * @brief Macro to implement the `wxApp` application class.
 *
 * This macro is required to implement the application class in wxWidgets. It creates
 * an instance of the `Main` class and starts the application's event loop.
 */
wxIMPLEMENT_APP(Main);