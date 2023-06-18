/***************************************************************
 * Name:      aplikacjaApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-06-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "aplikacjaApp.h"
#include "aplikacjaMain.h"

wxIMPLEMENT_APP(aplikacjaApp);

bool aplikacjaApp::OnInit()
{
    aplikacjaFrame* frame = new aplikacjaFrame("My Application");
    frame->Show(true);
    return true;
}
