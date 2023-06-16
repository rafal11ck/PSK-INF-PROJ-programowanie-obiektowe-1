#include "character.hpp"
#include "gameData.hpp"

/**
 *@file
 *@brief Character implementation.
 **/

void Character::validateDataIntegrity(const Item &item) const {
  getGameData()->validateDataIntegrity(item);
}

Character::Character(const GameData *const gameData) : m_gameData(gameData) {}

void Character::setBaseStatValue(Stat::id_t statId, Stat::value_t val) {
  m_gameData->getStat(statId);

  m_baseStatValues[statId] = val;
}

Stat::value_t Character::getBaseStatValue(Stat::id_t id) const {
  auto res{m_baseStatValues.find(id)};
  if (res != m_baseStatValues.end())
    return res->second;
  return 0;
}

const GameData *const Character::getGameData() const { return m_gameData; }

void Character::addItem(const Item *const item, itemQuantity_t quantity) {
  validateDataIntegrity(*item);
  auto temp{m_inventory.insert({item, quantity})};

  const bool didAdd{temp.second};
  // If not added, change item quantity.
  if (!didAdd) {
    // iterator to item
    auto itemIterator{temp.first};
    itemQuantity_t &itemQuantity{itemIterator->second};
    itemQuantity += quantity;
    //! @note If after alternation quantity would be 0 or negative it's
    //! purged from inventory.
    if (itemQuantity <= 0) {
      purgeItem(itemIterator->first);
    }
  }
}

void Character::purgeItem(Item::id_t id){};

void Character::purgeItem(const Item *const item) {}

void Character::purgeItem(inventory_t::iterator it) { m_inventory.erase(it); }

const Character::inventory_t &Character::getInventory() const {
  return m_inventory;
}
