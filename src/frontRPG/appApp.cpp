/***************************************************************
 * Name:      appApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-06-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "appApp.hpp"
#include "appMain.hpp"

wxIMPLEMENT_APP(appApp);

bool appApp::OnInit() {
  appFrame *frame = new appFrame("My Application");
  frame->Show(true);
  return true;
}
