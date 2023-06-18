/***************************************************************
 * Name:      appApp.h
 * Purpose:   Defines Application Class
 * Author:     ()
 * Created:   2023-06-17
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef APPAPP_H
#define APPAPP_H

#include "appMain.hpp"
#include <wx/wx.h>

class appApp : public wxApp {
public:
  virtual bool OnInit();
};

#endif // APPAPP_H
