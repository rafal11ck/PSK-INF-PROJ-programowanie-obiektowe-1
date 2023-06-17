#include "character.hpp"
#include "equipmentSlot.hpp"
#include "gameData.hpp"
#include "item.hpp"
#include "stat.hpp"
#include "statModifyingEntity.hpp"
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

void Character::validateDataIntegrity(const StatModifyingEntity &entity) const {
  getGameData()->validateDataIntegrity(entity);
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

Character::statValueContrubitors_t
Character::getStatValueStatesContrubitors(Stat::id_t id) const {
  statValueContrubitors_t result{};
  for (auto it : m_states) {
    Stat::value_t modv{it->getModifierValue(id)};
    // if it modifies stat add it to result.
    if (modv != 0)
      result.push_back(it);
  }
  return result;
}

Character::statValueContrubitors_t
Character::getStatValueEquipmentContrubitors(Stat::id_t id) const {
  statValueContrubitors_t result{};
  // For each equipment piece
  for (auto it : m_equipment) {
    const StatModifyingEntity *modifier{it.second};
    // Get modifier of stat caused by that piece.
    Stat::value_t modv{modifier->getModifierValue(id)};
    // if it modifies stat add it to result.
    if (modv != 0)
      result.push_back(modifier);
  }
  return result;
}

Character::statValueContrubitors_t
Character::getStatValueContrubitors(Stat::id_t id) const {
  statValueContrubitors_t result{};
  auto temp{getStatValueEquipmentContrubitors(id)};
  // equipment contribs.
  result.insert(result.end(), temp.begin(), temp.end());
  temp = getStatValueStatesContrubitors(id);
  // states contribs.
  result.insert(result.end(), temp.begin(), temp.end());

  return result;
}

Stat::value_t Character::getStatValue(Stat::id_t id) const {
  statValueContrubitors_t contrubitors{getStatValueContrubitors(id)};

  Stat::value_t result{getBaseStatValue(id)};

  for (const StatModifyingEntity *contr : contrubitors) {
    result += contr->getModifierValue(id);
  }
  return result;
}

const GameData *const Character::getGameData() const { return m_gameData; }

void Character::addItem(const Item *const item, itemQuantity_t quantity) {
  validateDataIntegrity(*item);
  if (quantity == 0)
    return;

  auto temp{m_inventory.insert({item, quantity})};

  const bool didAdd{temp.second};
  // If not added, change item quantity.
  if (!didAdd) {
    // iterator to item
    auto itemIterator{temp.first};
    itemQuantity_t &itemQuantity{itemIterator->second};
    itemQuantity += quantity;
    //! @todo make it remove item from inventory if quantity would go below or
    //! equal 0.
  }
}

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

void Character::addState(const State *state) {
  validateDataIntegrity(*state);
  m_states.insert(state);
}

const Character::states_t &Character::getStates() const { return m_states; }
