/**
 *@file
 *@brief StatModifyingEntity implementation.
 **/

#include "statModifyingEntity.hpp"

StatModifyingEntity::StatModifyingEntity(const GameMetadata *gameMetadata)
    : m_gameMetadata(gameMetadata) {}

//! @todo Check if entity has modifier of that Stat already.
void StatModifyingEntity::addModifier(Stat::id_t statModifed,
                                      Stat::value_t by) {

  getGameMetadata()->getStat(statModifed);
  m_modifiers.push_back({statModifed, by});
}

const GameMetadata *const StatModifyingEntity::getGameMetadata() const {
  return m_gameMetadata;
}

const StatModifyingEntity::modifersCollection_t &
StatModifyingEntity::getModifiers() const {
  return m_modifiers;
}
