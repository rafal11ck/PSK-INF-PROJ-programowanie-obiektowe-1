#ifndef ITEMBASE_H
#define ITEMBASE_H

#include <string>

class ItemBase {
  std::string m_name;
  std::string m_description;

public:
  ItemBase(std::string name, std::string description);
};

#endif // ITEMBASE_H
