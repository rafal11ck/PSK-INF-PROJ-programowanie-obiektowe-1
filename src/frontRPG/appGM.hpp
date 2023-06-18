#ifndef APPGM_H
#define APPGM_H

#include <wx/button.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/textctrl.h>
#include <wx/wx.h>

enum { ID_ADD_STAT = wxID_HIGHEST + 1, ID_ADD_EQUIPMENT, ID_ADD_STATE };

class appGMPanel : public wxPanel {
public:
  appGMPanel(wxNotebook *parent);

private:
  wxNotebook *gmNotebook;
  wxPanel *addElementPanel;
  wxListCtrl *statsListCtrl;
  wxListCtrl *eqListCtrl;
  wxListCtrl *stateListCtrl;

  StatsCollection statsCollection;
  EqCollection eqCollection;
  StateCollection stateCollection;

  void OnAddStat(wxCommandEvent &event);
  void OnAddEquipment(wxCommandEvent &event);
  void OnAddState(wxCommandEvent &event);
  void UpdateStatsListCtrl();
  void UpdateEqListCtrl();
  void UpdateStateListCtrl();

  wxDECLARE_EVENT_TABLE();
};

#endif // APPGM_H
