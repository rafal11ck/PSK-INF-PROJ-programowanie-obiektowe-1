#ifndef STATEBASE_H
#define STATEBASE_H
#include "statModifier.h"
#include "statModifiers.h"
#include <string>

/**
 *@brief
 *Represents state.
 * */
class StateBase : public StatModifiers {
private:
  //! Name of state
  std::string m_name;
  //! Description of state
  std::string m_description;
  StatModifiers m_statModifers;

public:
  StateBase(std::string name, std::string description = "");
  std::string getName() const;
};

#endif // STATEBASE_H
