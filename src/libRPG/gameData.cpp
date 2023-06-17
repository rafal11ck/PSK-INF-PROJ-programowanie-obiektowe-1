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
    //!@throw exceptionNonExistingId Tried to get item that does not exist.
    throw exceptionNonExistingId();
  return *lookup;
}

void GameData::validateDataIntegrity(const Item &item) const {
  if (this != item.getGameMetadata())
    //!@throw excpetionGameDataMissmatch When item does not use insnace on which
    //! this method is called as it's game metadata.
    throw excpetionGameDataMissmatch();
}
