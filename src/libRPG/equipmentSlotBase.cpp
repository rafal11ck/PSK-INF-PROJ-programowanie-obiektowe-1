
#include "equipmentSlotBase.h"

/**
 *Insttanitates object with given data.
 *@param name will become m_name.
 *@param description will become m_description. By default empty string.
 * */
EquiptmentSlotBase::EquiptmentSlotBase(std::string name,
                                       std::string description)
    : m_name(name), m_description(description) {}

/**
 *@brief Print to stream.
 *@param os Stream to print to.
 *@return os param stream.
 **/
std::ostream &EquiptmentSlotBase::print(std::ostream &os) const {
  os << "EquipmentSlotBase {name: \"" << m_name << R"(", description: ")"
     << m_description << R"(" })";
  return os;
}

std::ostream &operator<<(std::ostream &os, const EquiptmentSlotBase &data) {
  return data.print(os);
}
