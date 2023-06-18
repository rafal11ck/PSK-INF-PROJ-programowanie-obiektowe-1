#ifndef APPGM_H
#define APPGM_H

#include <wx/button.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/textctrl.h>
#include <wx/wx.h>
#include "gameData.hpp"

enum { ID_ADD_STAT = wxID_HIGHEST + 1, ID_ADD_EQUIPMENT, ID_ADD_SLOT, ID_ADD_STATE };

class appGMPanel : public wxPanel {
public:
  appGMPanel(wxNotebook *parent);

private:
  wxNotebook *gmNotebook;

  wxPanel *addElementPanel;
  wxPanel *statsPanel;
  wxPanel *eqPanel;
  wxPanel *slotPanel;
  wxPanel *statePanel;

  wxBoxSizer *addElementSizer;
  wxBoxSizer *statsSizer;
  wxBoxSizer *eqSizer;
  wxBoxSizer *slotSizer;
  wxBoxSizer *stateSizer;

  wxListCtrl *statsListCtrl;
  wxListCtrl *eqListCtrl;
  wxListCtrl *slotListCtrl;
  wxListCtrl *stateListCtrl;

  wxButton *addStatButton;
  wxButton *addEquipmentButton;
  wxButton *addSlotButton;
  wxButton *addStateButton;

  GameData* m_gamedata{nullptr};

  void OnAddStat(wxCommandEvent &event);
  void OnAddEquipment(wxCommandEvent &event);
  void OnAddSlot(wxCommandEvent &event);
  void OnAddState(wxCommandEvent &event);
  void UpdateStatsListCtrl();
  void UpdateEqListCtrl();
  void UpdateSlotListCtrl();
  void UpdateStateListCtrl();

  wxDECLARE_EVENT_TABLE();
};

#endif // APPGM_H
