#include "character.hpp"
#include "equipmentSlot.hpp"
#include "gameData.hpp"
#include "item.hpp"
#include <algorithm>

/**
 *@file
 *@brief Character implementation.
 **/

std::string exceptionEquipmentSlotOccupied::what() {
  return "tried to perform operation on occupied equipment slot";
}

std::string exceptionEquipmentSlotUnused::what() {
  return "Tried to extract data from unused slot";
}

std::string excpetionEquipmentSlotIllegalUsage ::what() {
  return "Illegal equipment slot usage";
}

void Character::validateDataIntegrity(const Item &item) const {
  getGameData()->validateDataIntegrity(item);
}

Character::Character(GameData *gameData) : m_gameData(gameData) {}

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

const Character::equipment_t &Character::getEquipment() const {
  return m_equipment;
}

bool Character::isEquipmentSlotUsed(EquipmentSlot::id_t eqSlotId) const {
  bool result{m_equipment.find(getGameData()->getEquipmentSlot(eqSlotId)) !=
              m_equipment.end()};
  return result;
}

const Item *const
Character::getEquipedItem(const EquipmentSlot *const eqSlot) const {
  equipment_t::const_iterator r{getEquipment().find(eqSlot)};
  if (r == getEquipment().end())
    throw exceptionEquipmentSlotUnused();
  return r->second;
}

const Item *const Character::getEquipedItem(EquipmentSlot::id_t slotId) const {
  const EquipmentSlot *const eqSlot{getGameData()->getEquipmentSlot(slotId)};
  return getEquipedItem(eqSlot);
}

void Character::equipItem(const Item *const item, EquipmentSlot::id_t eqSlot) {
  validateDataIntegrity(*item);
  // check if item can even be equiped into that slot.
  if (!item->isEquipableOn(eqSlot))
    throw excpetionEquipmentSlotIllegalUsage();

  // check if desired slot is occupied.
  if (isEquipmentSlotUsed(eqSlot))
    throw exceptionEquipmentSlotOccupied();

  // get slot pointer as it's used for internal equipment infromation.
  const EquipmentSlot *const eqSlotPtr{getGameData()->getEquipmentSlot(eqSlot)};

  m_equipment.insert({eqSlotPtr, item});
}
