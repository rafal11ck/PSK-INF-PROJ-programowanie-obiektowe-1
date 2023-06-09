#include "statModifiers.h"

/**
 *@file
 *@brief implementation
 **/

/**
 *@brief Adds modifer.
 *@param modifier Modifier that will be added.
 **/
void StatModifiers::addModifier(StatModifier modifier) {
  m_modifiers.push_back(modifier);
  // std::sort(m_modifiers.front(), m_modifiers.back()); // IDK if it would
  // work.
}
