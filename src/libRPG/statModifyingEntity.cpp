/**
 *@file
 *@brief StatModifyingEntity implementation.
 **/

#include "statModifyingEntity.hpp"

void StatModifyingEntity::addModifier(Stat::id_t statModifed,
                                      Stat::value_t by) {
  m_modifiers.push_back({statModifed, by});
}
