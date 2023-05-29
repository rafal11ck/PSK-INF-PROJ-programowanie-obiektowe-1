#ifndef ITEMBASE_H
#define ITEMBASE_H

/**
 *@file
 *@brief ItemBase interface.
 * */

#include <string>
/**
 *@brief Base class for items.
 **/
class ItemBase {
  //! Name of item.
  std::string m_name;
  //! Description of item.
  std::string m_description;

public:
  ItemBase(std::string name, std::string description);
};

#endif // ITEMBASE_H
