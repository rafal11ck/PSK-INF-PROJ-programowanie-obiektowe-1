#ifndef APLIKACJAGM_H
#define APLIKACJAGM_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/listctrl.h>
#include "gameData.h"

enum
{
    ID_ADD_STAT = wxID_HIGHEST + 1,
    ID_ADD_EQUIPMENT,
    ID_ADD_STATE
};

class aplikacjaGMPanel : public wxPanel
{
public:
    aplikacjaGMPanel(wxNotebook* parent);

private:
    wxNotebook* gmNotebook;
    wxPanel* addElementPanel;
    wxListCtrl* statsListCtrl;
    wxListCtrl* eqListCtrl;
    wxListCtrl* stateListCtrl;

    StatsCollection statsCollection;
    EqCollection eqCollection;
    StateCollection stateCollection;

    void OnAddStat(wxCommandEvent& event);
    void OnAddEquipment(wxCommandEvent& event);
    void OnAddState(wxCommandEvent& event);
    void UpdateStatsListCtrl();
    void UpdateEqListCtrl();
    void UpdateStateListCtrl();

    wxDECLARE_EVENT_TABLE();
};

#endif // APLIKACJAGM_H
