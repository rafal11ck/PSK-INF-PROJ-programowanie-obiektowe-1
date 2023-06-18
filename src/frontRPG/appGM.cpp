#include "appGM.hpp"

wxBEGIN_EVENT_TABLE(appGMPanel, wxPanel)
    EVT_BUTTON(ID_ADD_STAT, appGMPanel::OnAddStat)
    EVT_BUTTON(ID_ADD_EQUIPMENT, appGMPanel::OnAddEquipment)
    EVT_BUTTON(ID_ADD_SLOT, appGMPanel::OnAddSlot)
    EVT_BUTTON(ID_ADD_STATE, appGMPanel::OnAddState)
wxEND_EVENT_TABLE()

appGMPanel::appGMPanel(wxNotebook *parent): wxPanel(parent, wxID_ANY), m_gamedata(new GameData){
  gmNotebook = new wxNotebook(this, wxID_ANY);

  addElementPanel = new wxPanel(gmNotebook, wxID_ANY);
  addElementSizer = new wxBoxSizer(wxVERTICAL);

  addStatButton = new wxButton(addElementPanel, ID_ADD_STAT, "Add stat");
  addEquipmentButton = new wxButton(addElementPanel, ID_ADD_EQUIPMENT, "Add item");
  addSlotButton = new wxButton(addElementPanel, ID_ADD_SLOT, "Add slot");
  addStateButton = new wxButton(addElementPanel, ID_ADD_STATE, "Add state");

  addElementSizer->Add(addStatButton, 0, wxALL, 5);
  addElementSizer->Add(addEquipmentButton, 0, wxALL, 5);
  addElementSizer->Add(addSlotButton, 0, wxALL, 5);
  addElementSizer->Add(addStateButton, 0, wxALL, 5);

  addElementPanel->SetSizer(addElementSizer);

  statsPanel = new wxPanel(gmNotebook, wxID_ANY);
  statsSizer = new wxBoxSizer(wxVERTICAL);
  statsListCtrl = new wxListCtrl(statsPanel, wxID_ANY, wxDefaultPosition,
                                 wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
  statsListCtrl->InsertColumn(0, "Name");
  statsListCtrl->InsertColumn(1, "Description");
  statsListCtrl->InsertColumn(2, "Value");
  statsListCtrl->SetColumnWidth(0, 150);
  statsListCtrl->SetColumnWidth(1, 400);
  statsListCtrl->SetColumnWidth(2, 50);
  statsSizer->Add(statsListCtrl, 1, wxEXPAND | wxALL, 5);
  statsPanel->SetSizer(statsSizer);

  eqPanel = new wxPanel(gmNotebook, wxID_ANY);
  eqSizer = new wxBoxSizer(wxVERTICAL);
  eqListCtrl = new wxListCtrl(eqPanel, wxID_ANY, wxDefaultPosition,
                              wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
  eqListCtrl->InsertColumn(0, "Name");
  eqListCtrl->SetColumnWidth(0, 150);
  eqSizer->Add(eqListCtrl, 1, wxEXPAND | wxALL, 5);
  eqPanel->SetSizer(eqSizer);

  slotPanel = new wxPanel(gmNotebook, wxID_ANY);
  slotSizer = new wxBoxSizer(wxVERTICAL);
  slotListCtrl = new wxListCtrl(slotPanel, wxID_ANY, wxDefaultPosition,
                                 wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
  slotListCtrl->InsertColumn(0, "Name");
  slotListCtrl->SetColumnWidth(0, 150);
  slotSizer->Add(slotListCtrl, 1, wxEXPAND | wxALL, 5);
  slotPanel->SetSizer(slotSizer);

  statePanel = new wxPanel(gmNotebook, wxID_ANY);
  stateSizer = new wxBoxSizer(wxVERTICAL);
  stateListCtrl = new wxListCtrl(statePanel, wxID_ANY, wxDefaultPosition,
                                 wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
  stateListCtrl->InsertColumn(0, "Name");
  stateListCtrl->SetColumnWidth(0, 150);
  stateSizer->Add(stateListCtrl, 1, wxEXPAND | wxALL, 5);
  statePanel->SetSizer(stateSizer);

  gmNotebook->AddPage(addElementPanel, "Add");
  gmNotebook->AddPage(statsPanel, "Stats");
  gmNotebook->AddPage(eqPanel, "Items");
  gmNotebook->AddPage(slotPanel, "Slots");
  gmNotebook->AddPage(statePanel, "States");

  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
  mainSizer->Add(gmNotebook, 1, wxEXPAND | wxALL, 5);

  SetSizer(mainSizer);
}

void appGMPanel::OnAddStat(wxCommandEvent &event) {
  wxString name = wxGetTextFromUser("Enter name:", "Add Stat");
  wxString description = wxGetTextFromUser("Enter description:", "Add Stat");

  if (name.IsEmpty()) {
    wxMessageBox("Name or description cannot be empty!", "Error",
                 wxOK | wxICON_ERROR);
    return;
  }

  m_gamedata->addStat(new Stat(name.ToStdString(), description.ToStdString()));

  //UpdateStatsListCtrl();
}

void appGMPanel::OnAddEquipment(wxCommandEvent &event) {
  /*wxString name = wxGetTextFromUser("Enter name:", "Add Item");
  wxString description = wxGetTextFromUser("Enter description:", "Add Item");

  if (name.IsEmpty()) {
    wxMessageBox("Name or description cannot be empty!", "Error",
                 wxOK | wxICON_ERROR);
    return;
  }

  Item* item{new Item(m_gamedata, name.ToStdString(), description.ToStdString())};

  if(m_gamedata == nullptr){
        std::cerr<<"you are fucking dumb\n";
        std::abort();
  }
  m_gamedata->addItem(item);*/

  //UpdateEqListCtrl();
}

void appGMPanel::OnAddSlot(wxCommandEvent &event) {
    //!@todo add implementation
}

void appGMPanel::OnAddState(wxCommandEvent &event) {
  /*wxString name = wxGetTextFromUser("Enter name:", "Add State");
  wxString description = wxGetTextFromUser("Enter description:", "Add State");

  if (name.IsEmpty() || description.IsEmpty()) {
    wxMessageBox("Name or description cannot be empty!", "Error",
                 wxOK | wxICON_ERROR);
    return;
  }

  stateCollection.AddState(name, description);

  UpdateStateListCtrl();*/
}

void appGMPanel::UpdateStatsListCtrl() {
  /*statsListCtrl->DeleteAllItems();

  std::vector<Stat *> stats = statsCollection.GetStats();
  for (size_t i = 0; i < stats.size(); i++) {
    Stat *stat = stats[i];
    long index = statsListCtrl->InsertItem(i, stat->GetName());
    statsListCtrl->SetItem(index, 1, stat->GetDescription());
    statsListCtrl->SetItem(index, 2, wxString::Format("%d", stat->GetValue()));
    statsListCtrl->SetItemData(index, reinterpret_cast<wxUIntPtr>(stat));
  }*/
}

void appGMPanel::UpdateEqListCtrl() {
  /*eqListCtrl->DeleteAllItems();

  GameData::
  for (size_t i = 0; i < equipment.size(); i++) {
    Equipment *eq = equipment[i];
    long index = eqListCtrl->InsertItem(i, eq->GetName());
    eqListCtrl->SetItem(index, 1, eq->GetDescription());
    eqListCtrl->SetItemData(index, reinterpret_cast<wxUIntPtr>(eq));
  }*/
}

void appGMPanel::UpdateSlotListCtrl() {
    //!@todo add implementation
}

void appGMPanel::UpdateStateListCtrl() {
  /*stateListCtrl->DeleteAllItems();

  std::vector<State *> states = stateCollection.GetStates();
  for (size_t i = 0; i < states.size(); i++) {
    State *state = states[i];
    long index = stateListCtrl->InsertItem(i, state->GetName());
    stateListCtrl->SetItem(index, 1, state->GetDescription());
    stateListCtrl->SetItemData(index, reinterpret_cast<wxUIntPtr>(state));
  }*/
}
