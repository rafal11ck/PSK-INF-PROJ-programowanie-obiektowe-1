/**
 *@file
 *@brief GameData implementation.
 **/

#include "gameData.hpp"
#include <list>

void GameData::addItem(Item *item) {
  item->setId(m_nextItemId);
  ++m_nextItemId;
  auto res{m_items.insert(item)};
  if (!res.second)
    std::__throw_runtime_error("Item was not added to GameData");
}

const GameData::itemcollection_t &GameData::getItems() const { return m_items; }
