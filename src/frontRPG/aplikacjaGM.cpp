#include "aplikacjaGM.h"

wxBEGIN_EVENT_TABLE(aplikacjaGMPanel, wxPanel)
    EVT_BUTTON(ID_ADD_STAT, aplikacjaGMPanel::OnAddStat)
    EVT_BUTTON(ID_ADD_EQUIPMENT, aplikacjaGMPanel::OnAddEquipment)
    EVT_BUTTON(ID_ADD_STATE, aplikacjaGMPanel::OnAddState)
wxEND_EVENT_TABLE()

aplikacjaGMPanel::aplikacjaGMPanel(wxNotebook* parent)
    : wxPanel(parent, wxID_ANY)
{
    gmNotebook = new wxNotebook(this, wxID_ANY);

    addElementPanel = new wxPanel(gmNotebook, wxID_ANY);
    wxBoxSizer* addElementSizer = new wxBoxSizer(wxVERTICAL);

    wxButton* addStatButton = new wxButton(addElementPanel, ID_ADD_STAT, "Add stat");
    wxButton* addEquipmentButton = new wxButton(addElementPanel, ID_ADD_EQUIPMENT, "Add equipment");
    wxButton* addStateButton = new wxButton(addElementPanel, ID_ADD_STATE, "Add state");

    addElementSizer->Add(addStatButton, 0, wxALL, 5);
    addElementSizer->Add(addEquipmentButton, 0, wxALL, 5);
    addElementSizer->Add(addStateButton, 0, wxALL, 5);

    addElementPanel->SetSizer(addElementSizer);

    wxPanel* statsPanel = new wxPanel(gmNotebook, wxID_ANY);
    wxBoxSizer* statsSizer = new wxBoxSizer(wxVERTICAL);
    statsListCtrl = new wxListCtrl(statsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
    statsListCtrl->InsertColumn(0, "Name");
    statsListCtrl->InsertColumn(1, "Description");
    statsListCtrl->InsertColumn(2, "Value");
    statsListCtrl->SetColumnWidth(0, 150);
    statsListCtrl->SetColumnWidth(1, 400);
    statsListCtrl->SetColumnWidth(2, 50);
    statsSizer->Add(statsListCtrl, 1, wxEXPAND | wxALL, 5);
    statsPanel->SetSizer(statsSizer);

    wxPanel* eqPanel = new wxPanel(gmNotebook, wxID_ANY);
    wxBoxSizer* eqSizer = new wxBoxSizer(wxVERTICAL);
    eqListCtrl = new wxListCtrl(eqPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
    eqListCtrl->InsertColumn(0, "Name");
    eqListCtrl->InsertColumn(1, "Description");
    eqListCtrl->SetColumnWidth(0, 150);
    eqListCtrl->SetColumnWidth(1, 400);
    eqSizer->Add(eqListCtrl, 1, wxEXPAND | wxALL, 5);
    eqPanel->SetSizer(eqSizer);

    wxPanel* statePanel = new wxPanel(gmNotebook, wxID_ANY);
    wxBoxSizer* stateSizer = new wxBoxSizer(wxVERTICAL);
    stateListCtrl = new wxListCtrl(statePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL);
    stateListCtrl->InsertColumn(0, "Name");
    stateListCtrl->InsertColumn(1, "Description");
    stateListCtrl->SetColumnWidth(0, 150);
    stateListCtrl->SetColumnWidth(1, 400);
    stateSizer->Add(stateListCtrl, 1, wxEXPAND | wxALL, 5);
    statePanel->SetSizer(stateSizer);

    gmNotebook->AddPage(addElementPanel, "Add");
    gmNotebook->AddPage(statsPanel, "Stats");
    gmNotebook->AddPage(eqPanel, "EQ");
    gmNotebook->AddPage(statePanel, "States");

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(gmNotebook, 1, wxEXPAND | wxALL, 5);

    SetSizer(mainSizer);
}

void aplikacjaGMPanel::OnAddStat(wxCommandEvent& event)
{
    wxString name = wxGetTextFromUser("Enter name:", "Add Stat");
    wxString description = wxGetTextFromUser("Enter description:", "Add Stat");

    if (name.IsEmpty() || description.IsEmpty())
    {
        wxMessageBox("Name or description cannot be empty!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    statsCollection.AddStat(name, description);

    UpdateStatsListCtrl();
}

void aplikacjaGMPanel::OnAddEquipment(wxCommandEvent& event)
{
    wxString name = wxGetTextFromUser("Enter name:", "Add Equipment");
    wxString description = wxGetTextFromUser("Enter description:", "Add Equipment");

    if (name.IsEmpty() || description.IsEmpty())
    {
        wxMessageBox("Name or description cannot be empty!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    eqCollection.AddEquipment(name, description);

    UpdateEqListCtrl();
}

void aplikacjaGMPanel::OnAddState(wxCommandEvent& event)
{
    wxString name = wxGetTextFromUser("Enter name:", "Add State");
    wxString description = wxGetTextFromUser("Enter description:", "Add State");

    if (name.IsEmpty() || description.IsEmpty())
    {
        wxMessageBox("Name or description cannot be empty!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    stateCollection.AddState(name, description);

    UpdateStateListCtrl();
}

void aplikacjaGMPanel::UpdateStatsListCtrl()
{
    statsListCtrl->DeleteAllItems();

    std::vector<Stat*> stats = statsCollection.GetStats();
    for (size_t i = 0; i < stats.size(); i++)
    {
        Stat* stat = stats[i];
        long index = statsListCtrl->InsertItem(i, stat->GetName());
        statsListCtrl->SetItem(index, 1, stat->GetDescription());
        statsListCtrl->SetItem(index, 2, wxString::Format("%d", stat->GetValue()));
        statsListCtrl->SetItemData(index, reinterpret_cast<wxUIntPtr>(stat));
    }
}

void aplikacjaGMPanel::UpdateEqListCtrl()
{
    eqListCtrl->DeleteAllItems();

    std::vector<Equipment*> equipment = eqCollection.GetEquipment();
    for (size_t i = 0; i < equipment.size(); i++)
    {
        Equipment* eq = equipment[i];
        long index = eqListCtrl->InsertItem(i, eq->GetName());
        eqListCtrl->SetItem(index, 1, eq->GetDescription());
        eqListCtrl->SetItemData(index, reinterpret_cast<wxUIntPtr>(eq));
    }
}

void aplikacjaGMPanel::UpdateStateListCtrl()
{
    stateListCtrl->DeleteAllItems();

    std::vector<State*> states = stateCollection.GetStates();
    for (size_t i = 0; i < states.size(); i++)
    {
        State* state = states[i];
        long index = stateListCtrl->InsertItem(i, state->GetName());
        stateListCtrl->SetItem(index, 1, state->GetDescription());
        stateListCtrl->SetItemData(index, reinterpret_cast<wxUIntPtr>(state));
    }
}
