#ifndef APLIKACJAPLAYER_H
#define APLIKACJAPLAYER_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/textctrl.h>

class appPlayerPanel : public wxPanel
{
public:
    appPlayerPanel(wxNotebook* parent, const wxString& playerName);

private:
    wxNotebook* playerNotebook;
};

#endif // APLIKACJAPLAYER_H