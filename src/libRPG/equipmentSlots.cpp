
#include "equipmentSlots.h"
#include "equipmentSlotBase.h"

/**
 *@brief Constructor.
 *@param base Slot to add.
 *@param id id of created object sholud locally unque within collection.
 **/
EquipmentSlots::EquipmentSlot::EquipmentSlot(const EquiptmentSlotBase &base,
                                             id_t id)
    : EquiptmentSlotBase(base), m_id(id){};

void EquipmentSlots::addEquipmentSlot(const EquiptmentSlotBase &base) {
  m_equipmentSlots.push_back({base, m_nextEqupmentSlotId});
}
