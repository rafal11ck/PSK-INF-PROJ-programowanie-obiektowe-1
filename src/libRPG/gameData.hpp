#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_

/**
 *@file
 *@brief GameData interface.
 * */
#include "gameMetadata.hpp"
#include "item.hpp"
#include <exception>
#include <map>
#include <set>

/**
 *@brief Thrown when attempted to do operation that requires 2 objects to use
 *common GameData but different were used.
 * */
class excpetionGameDataMissmatch : public std::exception {
  /**
   *@brief what
   *@returns message
   **/
  std::string what();
};

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
   *@brief Desctructor
   **/
  ~GameData();

  /**
   *@brief Adds item to collection and sets it's id.
   *@param item Item to add.
   *
   *@note It does not validate item.
   **/
  void addItem(Item *item);

  /**
   *@brief Getter.
   *@return ::m_items.
   */
  const itemcollection_t &getItems() const;

  /**
   *@brief Get Item.
   *@param id Id of Item to fetch.
   *@return Item with given id.
   **/
  const Item *const getItem(Item::id_t id) const;

  /**
   *@brief Checks if Item uses this GameData insnace as it's metadata.
   *@param item Item to check.
   **/
  void validateDataIntegrity(const Item &item) const;
};

#endif // GAMEDATA_HPP_
