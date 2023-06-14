/**
 *@file
 *@brief GameData implementation.
 **/

#include "gameData.hpp"
#include <list>

GameData::~GameData() {
  for (auto it : m_items) {
    delete it;
  }
}

void GameData::addItem(Item *item) {
  item->setId(m_nextItemId);
  ++m_nextItemId;
  auto res{m_items.insert(item)};
  if (!res.second)
    //! @todo change excpetion class
    std::__throw_runtime_error("Item was not added to GameData");
}

const GameData::itemcollection_t &GameData::getItems() const { return m_items; }
