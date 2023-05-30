#ifndef EQUIPMENTSLOTBASE_H
#define EQUIPMENTSLOTBASE_H

#include <ostream>
#include <string>
/**
 *@brief Represents equipment slot eg. head, hand.
 **/
class EquiptmentSlotBase {
  //! Name
  std::string m_name;
  //! Description
  std::string m_description;

public:
  EquiptmentSlotBase(std::string name, std::string description);

  friend std::ostream &operator<<(std::ostream &os, EquiptmentSlotBase data);
};

#endif // EQUIPMENTSLOTBASE_H
