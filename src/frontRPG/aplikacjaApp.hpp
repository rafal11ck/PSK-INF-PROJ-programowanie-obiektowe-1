/***************************************************************
 * Name:      aplikacjaApp.h
 * Purpose:   Defines Application Class
 * Author:     ()
 * Created:   2023-06-17
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef APLIKACJAAPP_H
#define APLIKACJAAPP_H

#include "aplikacjaMain.hpp"
#include <wx/wx.h>

class aplikacjaApp : public wxApp {
public:
  virtual bool OnInit();
};

#endif // APLIKACJAAPP_H
