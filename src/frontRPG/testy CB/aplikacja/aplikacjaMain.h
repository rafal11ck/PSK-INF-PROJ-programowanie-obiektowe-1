/***************************************************************
 * Name:      aplikacjaMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-06-17
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef APLIKACJAMAIN_H
#define APLIKACJAMAIN_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include "aplikacjaGM.h"
#include "aplikacjaPlayer.h"

class aplikacjaFrame : public wxFrame
{
public:
    aplikacjaFrame(const wxString& title);

private:
    wxNotebook* notebook;
    wxPanel* gmPanel;
    wxPanel* addCharPanel;
    wxTextCtrl* charNameTextCtrl;

    void OnAddCharacter(wxCommandEvent& event);
};

enum
{
    ID_ADD_CHARACTER = 1
};

#endif // APLIKACJAMAIN_H
