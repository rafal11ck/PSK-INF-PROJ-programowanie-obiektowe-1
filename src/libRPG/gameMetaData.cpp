#include "gameMetaData.hpp"
#include "equipmentSlot.hpp"
#include <memory>

void GameMetadata::addStat(Stat *stat) {
  m_stats.push_back(stat);
  stat->setId(m_nextStatId);
  ++m_nextStatId;
}

void GameMetadata::addEquipmentSlot(EquipmentSlot *eqSlot) {
  m_equipmentSlots.push_back(eqSlot);
  eqSlot->setId(m_nextEquipmentSlotId);
  ++m_nextEquipmentSlotId;
}

Stat *GameMetadata::getStat(Stat::id_t id) const {
  for (Stat *st : m_stats) {
    if (st->m_id == id)
      return st;
  }
  return nullptr;
}

EquipmentSlot *GameMetadata::getEquipmentSlot(Stat::id_t id) const {
  for (EquipmentSlot *eq : m_equipmentSlots) {
    if (eq->m_id == id)
      return eq;
  }
  return nullptr;
}
