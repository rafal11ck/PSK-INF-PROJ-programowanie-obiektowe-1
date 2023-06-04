#ifndef EQUIPMENTSLOTS_H
#define EQUIPMENTSLOTS_H

#include "equipmentSlotBase.h"
#include <ostream>
#include <vector>

/**
 *@brief Holds equipment slots data, what equipment slots exist in the game.
 **/
class EquipmentSlots {
public:
  /**
   *@brief slot representation within collection.
   **/
  class EquipmentSlot : public EquiptmentSlotBase {
  public:
    //! Id type.
    using id_t = int;

  public:
    EquipmentSlot(const EquiptmentSlotBase &base, id_t id);
    virtual std::ostream &print(std::ostream &os) const;

  private:
    //! Locally unique id.
    id_t m_id;
  };

public:
  //! Collection type.
  using equipmentSlots_t = std::vector<EquipmentSlot>;

  void addEquipmentSlot(const EquiptmentSlotBase &base);
  const equipmentSlots_t getEquipmentSlots() const;

protected:
  //! ID given to next equipable item.
  EquipmentSlot::id_t m_nextEquipmentSlotId;
  //! container of EquipmentSlot
  equipmentSlots_t m_equipmentSlots;
};

#endif // EQUIPMENTSLOTS_H
