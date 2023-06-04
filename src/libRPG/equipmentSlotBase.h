#ifndef EQUIPMENTSLOTBASE_H
#define EQUIPMENTSLOTBASE_H

#include <ostream>
#include <string>
/**
 *@brief Represents equipment slot eg. head, hand.
 **/
class EquiptmentSlotBase {
protected:
  //! Name
  std::string m_name;
  //! Description
  std::string m_description;

public:
  EquiptmentSlotBase(std::string name, std::string description = "");

  virtual std::ostream &print(std::ostream &os) const;
  friend std::ostream &operator<<(std::ostream &os,
                                  const EquiptmentSlotBase &data);
};

#endif // EQUIPMENTSLOTBASE_H
