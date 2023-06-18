#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <wx/wx.h>
#include <vector>

class Stat
{
public:
    Stat(const wxString& name, const wxString& description, int value = 0);

    wxString GetName() const;
    wxString GetDescription() const;
    int GetValue() const;

private:
    wxString name;
    wxString description;
    int value;
};

class Equipment
{
public:
    Equipment(const wxString& name, const wxString& description);

    wxString GetName() const;
    wxString GetDescription() const;

private:
    wxString name;
    wxString description;
};

class State
{
public:
    State(const wxString& name, const wxString& description);

    wxString GetName() const;
    wxString GetDescription() const;

private:
    wxString name;
    wxString description;
};

class StatsCollection
{
public:
    void AddStat(const wxString& name, const wxString& description, int value = 0);
    std::vector<Stat*> GetStats() const;

private:
    std::vector<Stat*> stats;
};

class EqCollection
{
public:
    void AddEquipment(const wxString& name, const wxString& description);
    std::vector<Equipment*> GetEquipment() const;

private:
    std::vector<Equipment*> equipment;
};

class StateCollection
{
public:
    void AddState(const wxString& name, const wxString& description);
    std::vector<State*> GetStates() const;

private:
    std::vector<State*> states;
};

#endif // GAMEDATA_H
