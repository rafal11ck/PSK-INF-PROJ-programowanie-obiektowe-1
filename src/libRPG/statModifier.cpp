
#include "statModifier.h"

/**
 *@brief Instatitates object with given values.
 *@param statModified Intializes m_statModified.
 *@param modifyValue Initializes m_modifyValue.
 **/
StatModifier::StatModifier(const GameStats::GameStat &statModified,
                           int modifyValue)
    : m_statModifed(statModified), m_modifyValue(modifyValue) {}
