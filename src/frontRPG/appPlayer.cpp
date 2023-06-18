#include "appPlayer.hpp"

wxBEGIN_EVENT_TABLE(appPlayerPanel, wxPanel)
    EVT_BUTTON(ID_CHAR_ADD_STAT, appPlayerPanel::OnAddStat)
    EVT_BUTTON(ID_CHAR_ADD_EQUIPMENT, appPlayerPanel::OnAddEquipment)
    EVT_BUTTON(ID_CHAR_ADD_STATE, appPlayerPanel::OnAddState)
    EVT_BUTTON(ID_CHAR_EQUIP_EQUIPMENT, appPlayerPanel::OnEquipEquipment)
    EVT_BUTTON(ID_CHAR_UNEQUIP_EQUIPMENT, appPlayerPanel::OnUnequipEquipment)
wxEND_EVENT_TABLE()

appPlayerPanel::appPlayerPanel(wxNotebook* parent, const wxString& playerName)
    : wxPanel(parent, wxID_ANY)
{
    playerNotebook = new wxNotebook(this, wxID_ANY);

    statsPanel = new wxPanel(playerNotebook, wxID_ANY);
    statsSizer = new wxBoxSizer(wxVERTICAL);
    statsListCtrl = new wxListCtrl(statsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
    statsListCtrl->InsertColumn(0, "Name");
    statsListCtrl->InsertColumn(1, "Description");
    statsListCtrl->InsertColumn(2, "Value");
    statsListCtrl->SetColumnWidth(0, 150);
    statsListCtrl->SetColumnWidth(1, 400);
    statsListCtrl->SetColumnWidth(2, 50);
    statsSizer->Add(statsListCtrl, 1, wxEXPAND | wxALL, 5);
    statsPanel->SetSizer(statsSizer);

    equippedEQPanel = new wxPanel(playerNotebook, wxID_ANY);
    equippedEQSizer = new wxBoxSizer(wxVERTICAL);
    equippedEQListCtrl = new wxListCtrl(equippedEQPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
    equippedEQListCtrl->InsertColumn(0, "Name");
    equippedEQListCtrl->InsertColumn(1, "Description");
    equippedEQListCtrl->SetColumnWidth(0, 150);
    equippedEQListCtrl->SetColumnWidth(1, 400);
    equippedEQSizer->Add(equippedEQListCtrl, 1, wxEXPAND | wxALL, 5);

    // Dodajemy przycisk do panelu equippedEQPanel
    unequipEquipmentButton = new wxButton(equippedEQPanel, ID_CHAR_UNEQUIP_EQUIPMENT, "Unequip");
    equippedEQSizer->Add(unequipEquipmentButton, 0, wxALIGN_RIGHT | wxALL, 5);

    equippedEQPanel->SetSizer(equippedEQSizer);

    eqPanel = new wxPanel(playerNotebook, wxID_ANY);
    eqSizer = new wxBoxSizer(wxVERTICAL);
    eqListCtrl = new wxListCtrl(eqPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
    eqListCtrl->InsertColumn(0, "Name");
    eqListCtrl->InsertColumn(1, "Description");
    eqListCtrl->SetColumnWidth(0, 150);
    eqListCtrl->SetColumnWidth(1, 400);
    eqSizer->Add(eqListCtrl, 1, wxEXPAND | wxALL, 5);

    // Dodajemy przycisk do panelu eqPanel
    equipEquipmentButton = new wxButton(eqPanel, ID_CHAR_EQUIP_EQUIPMENT, "Equip");
    eqSizer->Add(equipEquipmentButton, 0, wxALIGN_RIGHT | wxALL, 5);

    eqPanel->SetSizer(eqSizer);

    statesPanel = new wxPanel(playerNotebook, wxID_ANY);
    statesSizer = new wxBoxSizer(wxVERTICAL);
    statesListCtrl = new wxListCtrl(statesPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
    statesListCtrl->InsertColumn(0, "Name");
    statesListCtrl->InsertColumn(1, "Description");
    statesListCtrl->SetColumnWidth(0, 150);
    statesListCtrl->SetColumnWidth(1, 400);
    statesSizer->Add(statesListCtrl, 1, wxEXPAND | wxALL, 5);
    statesPanel->SetSizer(statesSizer);

    addPanel = new wxPanel(playerNotebook, wxID_ANY);
    addPanelSizer = new wxBoxSizer(wxVERTICAL);
    addStatButton = new wxButton(addPanel, ID_CHAR_ADD_STAT, "Add Stat");
    addEquipmentButton = new wxButton(addPanel, ID_CHAR_ADD_EQUIPMENT, "Add Equipment");
    addStateButton = new wxButton(addPanel, ID_CHAR_ADD_STATE, "Add State");
    addPanelSizer->Add(addStatButton, 0, wxALIGN_LEFT | wxALL, 5);
    addPanelSizer->Add(addEquipmentButton, 0, wxALIGN_LEFT | wxALL, 5);
    addPanelSizer->Add(addStateButton, 0, wxALIGN_LEFT | wxALL, 5);
    addPanel->SetSizer(addPanelSizer);

    playerNotebook->AddPage(statsPanel, "Stats");
    playerNotebook->AddPage(equippedEQPanel, "Equipped EQ");
    playerNotebook->AddPage(eqPanel, "EQ");
    playerNotebook->AddPage(statesPanel, "States");
    playerNotebook->AddPage(addPanel, "Add");

    mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(playerNotebook, 1, wxEXPAND | wxALL, 5);
    SetSizerAndFit(mainSizer);
}

void appPlayerPanel::OnAddStat(wxCommandEvent& event)
{
    // TODO: Implement adding a stat
}

void appPlayerPanel::OnAddEquipment(wxCommandEvent& event)
{
    // TODO: Implement adding an equipment
}

void appPlayerPanel::OnAddState(wxCommandEvent& event)
{
    // TODO: Implement adding a state
}

void appPlayerPanel::OnEquipEquipment(wxCommandEvent& event)
{
    // TODO: Implement equipping an equipment
}

void appPlayerPanel::OnUnequipEquipment(wxCommandEvent& event)
{
    // TODO: Implement unequipping an equipment
}

void appPlayerPanel::UpdateStatsListCtrl()
{
    // TODO: Update the stats list control with data from statsCollection
}

void appPlayerPanel::UpdateEquippedEQListCtrl()
{
    // TODO: Update the equipped equipment list control with data from eqCollection
}

void appPlayerPanel::UpdateEQListCtrl()
{
    // TODO: Update the equipment list control with data from eqCollection
}

void appPlayerPanel::UpdateStatesListCtrl()
{
    // TODO: Update the states list control with data from stateCollection
}
