#ifndef ITEM_HPP_
#define ITEM_HPP_

/**
 *@file
 *@brief Item interface.
 * */

#include "basicGamedata.hpp"
#include "equipmentSlot.hpp"
#include "stat.hpp"
#include "statModifyingEntity.hpp"
#include <set>
#include <sys/types.h>

/**
 *@brief Represents an item in game.
 *
 *
 *Should be used in GameData.
 **/
class Item : public StatModifyingEntity, public BasicGameData {
public:
  //! Collection.
  using equipableSlots_t = std::set<EquipmentSlot::id_t>;

private:
  //! Which equipment slots given item can be put on.
  equipableSlots_t m_equipableOn;

  /**
   *@brief Make item equipable.
   *@param equipmentSlotId On which EquipmentSlot should it be equipable.
   **/
  void setEquipableOn(EquipmentSlot::id_t equipmentSlotId) {
    m_equipableOn.insert(equipmentSlotId);
  }
};

#endif // ITEM_HPP_
