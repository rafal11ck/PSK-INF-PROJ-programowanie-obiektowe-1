#include "character.hpp"

/**
 *@file
 *@brief Character implementation.
 **/

Character::Character(const GameMetadata &gameMetadata)
    : m_gameMetadata(gameMetadata) {}

void Character::setBaseStatValue(Stat::id_t statId, Stat::value_t val) {
  m_gameMetadata.getStat(statId);

  m_baseStatValues[statId] = val;
}

Stat::value_t Character::getBaseStatValue(Stat::id_t id) const {
  auto res{m_baseStatValues.find(id)};
  if (res != m_baseStatValues.end())
    return res->second;
  return 0;
}

const GameMetadata &Character::getGameMetadata() const {
  return m_gameMetadata;
}
