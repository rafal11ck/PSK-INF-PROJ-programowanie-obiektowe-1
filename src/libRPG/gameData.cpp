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
    //! @todo change excpetion to it's own exception class
    //!@throws std::__throw_runtime_error "Item was not added to GameData"
    //! When item was not added to the game some reason.
    std::__throw_runtime_error("Item was not added to GameData");
}

GameData::itemcollection_t &GameData::getItems() { return m_items; }

const GameData::itemcollection_t &GameData::getItems() const {
  return getItems();
}
