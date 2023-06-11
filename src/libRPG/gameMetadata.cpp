#include "gameMetadata.hpp"
#include "equipmentSlot.hpp"
#include <list>
#include <memory>

/**
 *@file
 *@brief GameMetadata implementation.
 **/

std::string exceptionNonExistingId::what() { return "Not found with given ID"; }

GameMetadata::~GameMetadata() {
  for (Stat *&it : m_stats)
    delete it;
  for (EquipmentSlot *&it : m_equipmentSlots)
    delete it;
}

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
  throw exceptionNonExistingId();
}

const GameMetadata::statsCollection_t &GameMetadata::getStats() const {
  return m_stats;
}

EquipmentSlot *GameMetadata::getEquipmentSlot(Stat::id_t id) const {
  for (EquipmentSlot *eq : m_equipmentSlots) {
    if (eq->m_id == id)
      return eq;
  }
  throw exceptionNonExistingId();
}

const GameMetadata::equiptmentSlotsCollection_t &
GameMetadata::getEquipmentSlots() const {
  return m_equipmentSlots;
}
