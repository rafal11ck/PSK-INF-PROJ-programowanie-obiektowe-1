/***************************************************************
 * Name:      aplikacjaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-06-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "aplikacjaMain.h"

aplikacjaFrame::aplikacjaFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    notebook = new wxNotebook(this, wxID_ANY);

    gmPanel = new aplikacjaGMPanel(notebook);
    notebook->AddPage(gmPanel, "gamemaster");

    addCharPanel = new wxPanel(notebook, wxID_ANY);
    wxBoxSizer* addCharSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText* charNameLabel = new wxStaticText(addCharPanel, wxID_ANY, "Character's Name:");
    charNameTextCtrl = new wxTextCtrl(addCharPanel, wxID_ANY);
    wxButton* addButton = new wxButton(addCharPanel, ID_ADD_CHARACTER, "Add");

    addCharSizer->Add(charNameLabel, 0, wxALIGN_LEFT | wxALL, 5);
    addCharSizer->Add(charNameTextCtrl, 0, wxEXPAND | wxALL, 5);
    addCharSizer->Add(addButton, 0, wxALIGN_LEFT | wxALL, 5);
    addCharPanel->SetSizer(addCharSizer);

    notebook->AddPage(addCharPanel, "Add character");

    sizer->Add(notebook, 1, wxEXPAND);
    SetSizer(sizer);

    addButton->Bind(wxEVT_BUTTON, &aplikacjaFrame::OnAddCharacter, this);
}

void aplikacjaFrame::OnAddCharacter(wxCommandEvent& event)
{
    wxString charName = charNameTextCtrl->GetValue();

    if (charName.IsEmpty())
    {
        wxMessageBox("Character's Name is empty", "Error", wxOK | wxICON_ERROR);
        return;
    }

    wxPanel* newCharPanel = new aplikacjaPlayerPanel(notebook, charName);
    notebook->AddPage(newCharPanel, charName);

    charNameTextCtrl->Clear();
}
