
#include "equipmentSlotBase.h"

/**
 *Insttanitates object with given data.
 *@param name will become m_name.
 *@param description will become m_description.
 * */
EquiptmentSlotBase::EquiptmentSlotBase(std::string name,
                                       std::string description)
    : m_name(name), m_description(description) {}
