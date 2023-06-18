#include "appPlayer.hpp"

appPlayerPanel::appPlayerPanel(wxNotebook *parent,
                                           const wxString &playerName)
    : wxPanel(parent, wxID_ANY) {
  playerNotebook = new wxNotebook(this, wxID_ANY);

  wxPanel *statsPanel = new wxPanel(playerNotebook, wxID_ANY);
  playerNotebook->AddPage(statsPanel, "Stats");

  wxPanel *equippedEQPanel = new wxPanel(playerNotebook, wxID_ANY);
  playerNotebook->AddPage(equippedEQPanel, "Equipped EQ");

  wxPanel *eqPanel = new wxPanel(playerNotebook, wxID_ANY);
  playerNotebook->AddPage(eqPanel, "EQ");

  wxPanel *statesPanel = new wxPanel(playerNotebook, wxID_ANY);
  playerNotebook->AddPage(statesPanel, "States");

  wxPanel *addPanel = new wxPanel(playerNotebook, wxID_ANY);
  playerNotebook->AddPage(addPanel, "Add");

  wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
  sizer->Add(playerNotebook, 1, wxEXPAND);
  SetSizer(sizer);
}
