
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

/**
 *@file
 *@brief Character interface.
 **/

#include "equipmentSlot.hpp"
#include "gameData.hpp"
#include "gameMetadata.hpp"
#include "item.hpp"
#include "stat.hpp"
#include "statModifyingEntity.hpp"
#include <exception>
#include <list>
#include <map>
#include <vector>

/**
 *@brief Tried to perform operation on occupied already slot.
 **/
class exceptionEquipmentSlotOccupied : public std::exception {
  /**
   *@brief What.
   *@returns Message.
   **/
  std::string what();
};

/**
 *@brief Tried to extract data from unused slot.
 */
class exceptionEquipmentSlotUnused : public std::exception {
  /**
   *@brief What.
   *@returns Message.
   **/
  std::string what();
};

/**
 * @brief Tried to put stuff where it is not suppsoed to go.
 */
class excpetionEquipmentSlotIllegalUsage : public std::exception {
  /**
   *@brief What.
   *@returns Message.
   **/
  std::string what();
};

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
  //! Stat value contrubitors collection.
  using statValueContrubitors_t = std::vector<const StatModifyingEntity *>;

  //! Quantity of Items.
  using itemQuantity_t = long long;

  //! Used for inventory as <Item, qunatity possed by Character>
  using inventory_t = std::map<const Item *const, itemQuantity_t>;

  //! Used to store equiped items of character.
  using equipment_t = std::map<const EquipmentSlot *const, const Item *const>;

  //! Game data used by character.
  const GameData *const m_gameData;
  //! Base values of stats.
  statValues_t m_baseStatValues;
  //! Inventorty
  inventory_t m_inventory;
  //! Equiped Items
  equipment_t m_equipment;

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
  Character(GameData *gameData);

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
   *@brief Gets collection of stat modyfiers
   *@param id Id of stat.
   *@return Contrubuitors to Stat value.
   **/
  statValueContrubitors_t getStatValueContrubitors(Stat::id_t id) const;

  /**
   *@brief Gets final stat value
   *@param id Id of stat to get value of.
   *@return Value of stat.
   **/
  Stat::value_t getStatValue(Stat::id_t id) const;
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
   *@brief Inventory getter
   *@return m_inventory
   **/
  const inventory_t &getInventory() const;

  /**
   *@brief equipment getter
   *@return m_equipment
   **/
  const equipment_t &getEquipment() const;

  /**
   *@brief Check if slot is used
   *@param eqSlotId id of eq slot to check.
   *@return True if slot is used. False if it is not used.
   * */
  bool isEquipmentSlotUsed(EquipmentSlot::id_t eqSlotId) const;

private:
  /**
   *@brief Get item equiped in given slot.
   *@param eqSlot EquipmentSlot to get equiped item of.
   *@throw exceptionEquipmentSlotUnused When trying to get equiped item of
   *unused slot.
   *@return Equiped item.
   **/
  const Item *const getEquipedItem(const EquipmentSlot *const eqSlot) const;

public:
  /**
   *@copybrief getEquipedItem()
   *@param slotId EquipmentSlot to get equiped item of.
   *@return Equiped item.
   **/
  const Item *const getEquipedItem(EquipmentSlot::id_t slotId) const;

  /**
   *@brief Equip item into eqSlot.
   *@param item Item to equip.
   *@param eqSlot Where to equip it to.
   *
   *@note It does not check whenever Character has item in invnetory.
   *
   *@throw excpetionEquipmentSlotIllegalUsage When attempting to equip item into
   *slot that it can not be equiped to.
   *@throw exceptionEquipmentSlotOccupied When attempting to equip item into
   *already occupied slot;
   *
   *@warning If moving Item from inventory to equipment(as if it was take out of
   *inventory and put on by Character). Removal of Item should be performed
   *after this method call. If it's removed before and exception is thrown Item
   *would have been removed from inventory and not be equiped.
   *
   *@snippet test.cpp Item equiping
   **/
  void equipItem(const Item *const item, EquipmentSlot::id_t eqSlot);
};

#endif // CHARACTER_HPP_
