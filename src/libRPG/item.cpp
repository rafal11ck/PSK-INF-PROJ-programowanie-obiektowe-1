/**
 *@file
 *@brief Item implementation.
 **/

#include "item.hpp"
#include "gameData.hpp"

Item::Item(GameData *gameData, std::string name, std::string description)
    : StatModifyingEntity(gameData, name, description) {
  gameData->addItem(this);
}

void Item::setEquipableOn(EquipmentSlot::id_t equipmentSlotId) {
  getGameMetadata()->getEquipmentSlot(equipmentSlotId);
  m_equipableOn.insert(equipmentSlotId);
}

void Item::unsetEquipableOn(EquipmentSlot::id_t equipmentSlotId) {
  getGameMetadata()->getEquipmentSlot(equipmentSlotId);
  m_equipableOn.erase(equipmentSlotId);
}

bool Item::isEquipableOn(EquipmentSlot::id_t equipmentSlotId) const {
  auto it{m_equipableOn.find(equipmentSlotId)};
  const bool result{it != m_equipableOn.end()};
  return result;
}

const Item::equipableSlots_t &Item::getEquipableSlots() const {
  return m_equipableOn;
}
