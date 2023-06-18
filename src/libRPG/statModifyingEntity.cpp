/**
 *@file
 *@brief StatModifyingEntity implementation.
 **/

#include "statModifyingEntity.hpp"
#include "basicGamedata.hpp"
#include <algorithm>

std::string exceptionInvalidGameMetadata::what() {
  return "Invalid Game metadata";
}

StatModifyingEntity::StatModifyingEntity(const GameMetadata *gameMetadata,
                                         std::string name,
                                         std::string description)
    : BasicGameData(name, description), m_gameMetadata(gameMetadata) {
  //!@throw exceptionInvalidGameMetadata
  if (gameMetadata == nullptr)
    throw exceptionInvalidGameMetadata();
}

//! @todo Check if entity has modifier of that Stat already.
void StatModifyingEntity::addModifier(Stat::id_t statModifed,
                                      Stat::value_t by) {

  getGameMetadata()->getStat(statModifed);
  m_modifiers.push_back({statModifed, by});
}

Stat::value_t StatModifyingEntity::getModifierValue(Stat::id_t id) const {
  auto lookup{
      std::find_if(m_modifiers.begin(), m_modifiers.end(),
                   [=](const modifier_t mod) { return mod.first == id; })};
  // If not found modifier of asked stat.
  if (lookup == m_modifiers.end())
    return 0;

  return lookup->second;
}

const GameMetadata *const StatModifyingEntity::getGameMetadata() const {
  return m_gameMetadata;
}

const StatModifyingEntity::modifersCollection_t &
StatModifyingEntity::getModifiers() const {
  return m_modifiers;
}
