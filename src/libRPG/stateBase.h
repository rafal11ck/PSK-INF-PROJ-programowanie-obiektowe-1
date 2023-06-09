#ifndef STATEBASE_H
#define STATEBASE_H
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

public:
  std::string getName() const;
};

#endif // STATEBASE_H
