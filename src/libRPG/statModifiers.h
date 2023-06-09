#ifndef STATMODIFIERS_H
#define STATMODIFIERS_H

/**
 *@file
 *@brief StatModifers interface.
 **/

#include "statModifier.h"
#include <vector>

/**
 *@brief Holds collection of StatModifier.
 *
 **/
class StatModifiers {
public:
  //! Colletion type.
  using collection_t = std::vector<StatModifier>;

private:
  //! Collection of modifiers.
  collection_t m_modifiers;

public:
  virtual void addModifier(StatModifier modifier);
};

#endif // STATMODIFIERS_H
