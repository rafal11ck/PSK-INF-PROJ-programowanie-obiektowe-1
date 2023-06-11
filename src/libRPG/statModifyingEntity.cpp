/**
 *@file
 *@brief StatModifyingEntity implementation.
 **/

#include "statModifyingEntity.hpp"

void StatModifyingEntity::addModifier(const Stat *const statModifed,
                                      Stat::value_t by) {
  m_modifiers.push_back({statModifed, by});
}
