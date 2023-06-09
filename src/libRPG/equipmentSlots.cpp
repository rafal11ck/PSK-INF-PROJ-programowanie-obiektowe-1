
#include "equipmentSlots.h"
#include "equipmentSlotBase.h"
#include <ostream>

/**
 *@brief Constructor.
 *@param base Slot to add.
 *@param id id of created object sholud locally unque within collection.
 **/
EquipmentSlots::EquipmentSlot::EquipmentSlot(const EquiptmentSlotBase &base,
                                             id_t id)
    : EquiptmentSlotBase(base), m_id(id){};

/**
 *@brief Adds equipment slot.
 *@param base Slot to add.
 *
 * */
void EquipmentSlots::addEquipmentSlot(const EquiptmentSlotBase &base) {
  m_equipmentSlots.push_back({base, m_nextEquipmentSlotId});
  ++m_nextEquipmentSlotId;
}

std::ostream &EquipmentSlots::EquipmentSlot::print(std::ostream &os) const {
  os << "EquipmentSlot {id = \"" << m_id << "\", name: \"" << m_name
     << R"(", description: ")" << m_description << R"(" })";
  return os;
}

/**
 *@brief Getter.
 *@return m_equipmentSlots.
 **/
const EquipmentSlots::equipmentSlots_t
EquipmentSlots::getEquipmentSlots() const {
  return m_equipmentSlots;
}

std::ostream &EquipmentSlots::print(std::ostream &os) const {
  os << "EquipmentSlots {\n";
  for (auto it : m_equipmentSlots)
    os << it << '\n';
  os << "}\n";

  return os;
}
