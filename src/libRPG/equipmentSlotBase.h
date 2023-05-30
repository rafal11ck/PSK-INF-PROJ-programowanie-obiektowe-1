#ifndef EQUIPMENTSLOTBASE_H
#define EQUIPMENTSLOTBASE_H

#include <string>
/**
 *@brief Represents equipment slot eg. head, hand.
 **/
class EquiptmentSlotBase {
  //! Name
  std::string m_name;
  //! Description
  std::string m_description;

  EquiptmentSlotBase(std::string name, std::string description);
};

#endif // EQUIPMENTSLOTBASE_H
