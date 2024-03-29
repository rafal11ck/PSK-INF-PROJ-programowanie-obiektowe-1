/**
 *@file
 *@brief GameData implementation.
 **/

#include "gameData.hpp"
#include "basicGamedata.hpp"
#include "gameMetadata.hpp"
#include <algorithm>

std::string excpetionGameDataMissmatch::what() { return "Game data missmatch"; }

GameData::~GameData() {
  for (auto it : m_items) {
    delete it;
  }

  for (auto it : m_states) {
    delete it;
  }
}

void GameData::addItem(Item *item) {
  validateDataIntegrity(*item);
  item->setId(m_nextItemId);
  ++m_nextItemId;
  auto res{m_items.insert(item)};
  if (!res.second)
    //!@todo LOW change excpetion to it's own exception class
    //!@throws std::__throw_runtime_error "Item was not added to GameData"
    //! When item was not added to the game some reason.
    std::__throw_runtime_error("Item was not added to GameData");
}

const GameData::itemcollection_t &GameData::getItems() const { return m_items; }

const Item *const GameData::getItem(Item::id_t id) const {
  auto lookup{std::find_if(getItems().begin(), getItems().end(),
                           [=](const Item *const it) { return it->isId(id); })};

  if (lookup == getItems().end())
    throw exceptionNonExistingId();
  return *lookup;
}

void GameData::validateDataIntegrity(const StatModifyingEntity &entity) const {
  if (this != entity.getGameMetadata())
    //!@throw excpetionGameDataMissmatch When entity does not use this as it's
    //! game data.
    throw excpetionGameDataMissmatch();
}

void GameData::addState(State *state) {
  validateDataIntegrity(*state);
  m_states.insert(state);
  state->setId(m_nextStateId);
  ++m_nextStateId;
}

const GameData::stateCollcetion_t &GameData::getStates() const {
  return m_states;
}

const State *const GameData::getState(State::id_t id) const {
  auto lookup{
      std::find_if(m_states.begin(), m_states.end(),
                   [=](const State *const state) { return state->isId(id); })};

  if (lookup == m_states.end()) {
    throw exceptionNonExistingId();
  }

  return *lookup;
}
