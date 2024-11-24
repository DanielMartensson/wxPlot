#pragma once

#include "src/frames/mainframe/mainframe.hpp"

class Main : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(Main);