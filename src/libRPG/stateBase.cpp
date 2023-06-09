#include "stateBase.h"
#include "statBase.h"

/**
 * @brief
 * Implementation file
 * */

StateBase::StateBase(std::string name, std::string description)
    : m_name(name), m_description(description) {}

/**
 *@brief Name getter.
 *@return m_name.
 **/
std::string StateBase::getName() const { return m_name; }

std::ostream &StateBase::print(std::ostream &os) const {
  os << "StateBase {\n";
  for (const StatModifier &it : getModifiers()) {
    os << it;
  }
  os << "}\n";
  return os;
}
