#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_

/**
 *@file
 *@brief GameData interface.
 * */
#include "gameMetadata.hpp"
#include "item.hpp"
#include <map>
#include <set>

/**
 *@brief On top of what GameMetadata does. Holds items cataloge.
 *@see GameMetadata
 */
class GameData : public GameMetadata {
public:
  //! Collection type.
  using itemcollection_t = std::set<Item *>;

private:
  //! Collection of items that exist in game collection.
  itemcollection_t m_items;
  //! Id That will be given to next item added.
  Item::id_t m_nextItemId{1};

public:
  /**
   *@brief Adds item to collection.
   *@param item Item to add.
   **/
  void addItem(Item *item);

  /**
   *@brief Getter.
   *@return ::m_items.
   **/
  const itemcollection_t &getItems() const;
};

#endif // HAMEDATA_HPP_
