#ifndef STATMODIFIER_H
#define STATMODIFIER_H

/**
 *@file
 *@brief StatModifer interface.
 **/

#include "gameStats.h"
#include "statBase.h"

/**
 *@brief Repesents stat modification.
 *
 *@note Holds reference to GameStats::GameStat so it should outlive it and not
 *be used standalone.
 * */
class StatModifier {
private:
  //! Id of stat that is modified
  const GameStats::GameStat &m_statModifed;
  //! Value by which stat is modified;
  int m_modifyValue;

public:
  StatModifier(const GameStats::GameStat &statModified, int modifyValue);
};

#endif // STATMODIFIER_H
