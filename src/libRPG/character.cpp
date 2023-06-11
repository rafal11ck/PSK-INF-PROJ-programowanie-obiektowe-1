#include "character.hpp"

void Character::setStatValue(Stat::id_t statId, Stat::value_t val) {
  if (val == Stat::INVALID_ID)
    return;

  m_baseStatValues[statId] = val;
}
