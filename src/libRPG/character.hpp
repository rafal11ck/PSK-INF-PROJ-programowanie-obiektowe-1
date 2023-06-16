
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

/**
 *@file
 *@brief Character interface.
 **/

#include "gameData.hpp"
#include "item.hpp"
#include "stat.hpp"
#include <list>
#include <map>
#include <vector>

/**
 *@brief Represents character.
 *
 *Base character stats are stats that character has without any modifiers
 *applied.
 *If Base stat is not set it will be assumed to be 0;
 **/
class Character {
  //! Type used for repesentation of base character stats.
  using statValues_t = std::map<Stat::id_t, Stat::value_t>;

  //! Quantity of Items.
  using itemQuantity_t = long long;

  //! Used for inventory as <Item, qunatity possed by Character>
  using inventory_t = std::map<const Item *const, itemQuantity_t>;

  //! Game data used by character.
  const GameData *const m_gameData;
  //! Base values of stats.
  statValues_t m_baseStatValues;
  //! Inventorty
  inventory_t m_inventory;

private:
  /**
   * @brief Validate data integrty.
   * @param item Item to validate agints.
   * @throw excpetionGameDataMissmatch When Character and item do not use same
   * GameData.
   * */
  void validateDataIntegrity(const Item &item) const;

public:
  /**
   *@brief constructor
   *@param gameData Used by character.
   *@snippet test.cpp Character
   */
  Character(const GameData *const gameData);

  /**
   *@brief Sets base stat value.
   *@param statId Id to set value of.
   *@param val Value to set.
   **/
  void setBaseStatValue(Stat::id_t statId, Stat::value_t val);

  /**
   *@brief Base statistics value getter.
   *@param id of stat to get base value of.
   *@return Base value of stat with given id.
   *
   *If Character does not have base Stat value of given id 0 is returned as per
   *class invariant.
   **/
  Stat::value_t getBaseStatValue(Stat::id_t id) const;

  /**
   *@brief Gets game data  used by Character.
   *@return ::m_gameData.
   **/
  const GameData *const getGameData() const;

  /**
   *@brief Adds item to character inventory.
   *@param item Item to add.
   *@param quantity Qunatity of item to add.
   *
   *@snippet test.cpp adding Item to Character inventory
   **/
  void addItem(const Item *const item, itemQuantity_t quantity = 1);

  /**
   *@brief Purges Item from Character inventory.
   *@param id id of Item to purge.
   **/
  void purgeItem(Item::id_t id);

  /**
   *@copybrief purgeItem()
   *@param item Item to purge.
   **/
  void purgeItem(const Item *const item);
  /**
   *@copybrief purgeItem()
   *@param it Iteartor to Item in m_inventory that has to be purged.
   **/
  void purgeItem(inventory_t::iterator it);

  /**
   *@brief Inventory getter
   *@return m_inventory
   **/
  const inventory_t &getInventory() const;
};

#endif // CHARACTER_HPP_
