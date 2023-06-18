#include "gameData.h"

Stat::Stat(const wxString& name, const wxString& description, int value)
    : name(name), description(description), value(value)
{
}

wxString Stat::GetName() const
{
    return name;
}

wxString Stat::GetDescription() const
{
    return description;
}

int Stat::GetValue() const
{
    return value;
}

Equipment::Equipment(const wxString& name, const wxString& description)
    : name(name), description(description)
{
}

wxString Equipment::GetName() const
{
    return name;
}

wxString Equipment::GetDescription() const
{
    return description;
}

State::State(const wxString& name, const wxString& description)
    : name(name), description(description)
{
}

wxString State::GetName() const
{
    return name;
}

wxString State::GetDescription() const
{
    return description;
}

void StatsCollection::AddStat(const wxString& name, const wxString& description, int value)
{
    Stat* stat = new Stat(name, description, value);
    stats.push_back(stat);
}

std::vector<Stat*> StatsCollection::GetStats() const
{
    return stats;
}

void EqCollection::AddEquipment(const wxString& name, const wxString& description)
{
    Equipment* equipment = new Equipment(name, description);
    this->equipment.push_back(equipment);
}

std::vector<Equipment*> EqCollection::GetEquipment() const
{
    return equipment;
}

void StateCollection::AddState(const wxString& name, const wxString& description)
{
    State* state = new State(name, description);
    states.push_back(state);
}

std::vector<State*> StateCollection::GetStates() const
{
    return states;
}
