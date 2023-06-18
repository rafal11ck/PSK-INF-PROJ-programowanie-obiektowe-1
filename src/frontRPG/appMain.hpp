/***************************************************************
 * Name:      appMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-06-17
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef APLIKACJAMAIN_H
#define APLIKACJAMAIN_H

#include "appGM.hpp"
#include "appPlayer.hpp"
#include <wx/button.h>
#include <wx/notebook.h>
#include <wx/textctrl.h>
#include <wx/wx.h>

class appFrame : public wxFrame {
public:
  appFrame(const wxString &title);

private:
  wxNotebook *notebook;
  wxPanel *gmPanel;
  wxPanel *addCharPanel;
  wxTextCtrl *charNameTextCtrl;

  void OnAddCharacter(wxCommandEvent &event);
};

enum { ID_ADD_CHARACTER = 1 };

#endif // APLIKACJAMAIN_H
