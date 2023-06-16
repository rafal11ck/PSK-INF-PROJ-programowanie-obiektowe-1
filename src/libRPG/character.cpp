#include "character.hpp"

/**
 *@file
 *@brief Character implementation.
 **/

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
