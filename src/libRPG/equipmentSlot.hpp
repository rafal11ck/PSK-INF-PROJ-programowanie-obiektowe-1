#ifndef EQUIPMENTSLOT_HPP_
#define EQUIPMENTSLOT_HPP_

/**
 * @file
 * @brief EquipmentSlot interface.
 * */

#include "basicGamedata.hpp"

/**
 *@brief Equipment slot repesentation.
 **/
class EquipmentSlot : public BasicGameData {

public:
  /**
   *@brief Constructor.
   *@param name Name.
   *@param description Optional description.
   **/
  EquipmentSlot(std::string name, std::string description = "");
};

#endif // EQUIPMENTSLOT_HPP_
