#pragma once

#include <wx/wx.h>
#include "../../wxplot.hpp"

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    wxPlot* plot;
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnSize(wxSizeEvent& event);
};

