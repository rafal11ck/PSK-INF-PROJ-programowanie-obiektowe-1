#ifndef ITEM_HPP_
#define ITEM_HPP_

/**
 *@file
 *@brief Item interface.
 * */

#include "equipmentSlot.hpp"
#include "statModifyingEntity.hpp"
#include <set>

class GameData;

/**
 *@brief Represents an item in game.
 *
 *Should be used in GameData.
 **/
class Item : public StatModifyingEntity {

public:
  //! Collection.
  using equipableSlots_t = std::set<EquipmentSlot::id_t>;

private:
  //! Which equipment slots given item can be put on.
  equipableSlots_t m_equipableOn;

public:
  /**
   *@brief Constructor.
   *@param gameData GameData to which item is added.
   *@param name Name of item.
   *@param description description.
   *
   *
   *@snippet test.cpp Adding Item to GameData
   */
  Item(GameData *gameData, std::string name, std::string description = "");

  /**
   *@brief Make item equipable on given equipment slot.
   *@param equipmentSlotId On which EquipmentSlot should it be equipable.
   *
   *If it is already equipable on that slot nothing will be done.
   **/
  void setEquipableOn(EquipmentSlot::id_t equipmentSlotId);

  /**
   *@brief Makes item no longer possible to equip onto given slot.
   *@param equipmentSlotId equipment slot id that item will be no longer
   *equipable on.
   *
   *If it is already not equipable on that slot nothing will happen.
   **/
  void unsetEquipableOn(EquipmentSlot::id_t equipmentSlotId);

  /**
   *@brief Checks whenever Item is equipable in given slot id.
   *@param equipmentSlotId Slot to check.
   *@returns True if Item is equipable in enquiered slot. False if it is not.
   **/
  bool isEquipableOn(EquipmentSlot::id_t equipmentSlotId) const;

  /**
   *@brief Get equipable slots.
   *@return m_equipableOn.
   **/
  const equipableSlots_t &getEquipableSlots() const;
};

#endif // ITEM_HPP_
