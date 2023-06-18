#ifndef APPPLAYER_H
#define APPPLAYER_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/listctrl.h>

enum
{
    ID_CHAR_ADD_STAT = wxID_HIGHEST + 1,
    ID_CHAR_ADD_EQUIPMENT,
    ID_CHAR_ADD_STATE,
    ID_CHAR_EQUIP_EQUIPMENT,
    ID_CHAR_UNEQUIP_EQUIPMENT
};

class appPlayerPanel : public wxPanel
{
public:
    appPlayerPanel(wxNotebook* parent, const wxString& playerName);

private:
    wxNotebook* playerNotebook;

    wxPanel* statsPanel;
    wxPanel* equippedEQPanel;
    wxPanel* eqPanel;
    wxPanel* statesPanel;
    wxPanel* addPanel;

    wxBoxSizer* statsSizer;
    wxBoxSizer* equippedEQSizer;
    wxBoxSizer* eqSizer;
    wxBoxSizer* statesSizer;
    wxBoxSizer* addPanelSizer;
    wxBoxSizer* mainSizer;

    wxListCtrl* statsListCtrl;
    wxListCtrl* equippedEQListCtrl;
    wxListCtrl* eqListCtrl;
    wxListCtrl* statesListCtrl;

    wxButton* addStatButton;
    wxButton* addEquipmentButton;
    wxButton* addStateButton;
    wxButton* equipEquipmentButton;
    wxButton* unequipEquipmentButton;

    void OnAddStat(wxCommandEvent& event);
    void OnAddEquipment(wxCommandEvent& event);
    void OnAddState(wxCommandEvent& event);
    void OnEquipEquipment(wxCommandEvent& event);
    void OnUnequipEquipment(wxCommandEvent& event);
    void UpdateStatsListCtrl();
    void UpdateEquippedEQListCtrl();
    void UpdateEQListCtrl();
    void UpdateStatesListCtrl();

    wxDECLARE_EVENT_TABLE();
};

#endif // APPPLAYER_H
