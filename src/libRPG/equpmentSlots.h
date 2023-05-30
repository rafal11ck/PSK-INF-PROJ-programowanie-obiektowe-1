#include "equipmentSlotBase.h"
#include <vector>

/**
 *@brief Holds equipment slots data, what equipment slots exist in the game.
 **/
class EquipmentSlots {
protected:
  /**
   *@brief slot representation within collection.
   **/
  class EquipmentSlot : EquiptmentSlotBase {
  public:
    //! Id type.
    using id_t = int;

  public:
    //! @todo make it take slotBase and extend it(give it id);
    EquipmentSlot(EquiptmentSlotBase base, id_t id);

  private:
    //! Locally unique id.
    id_t m_id;
  };

public:
  using equipmentSlots_t = std::vector<EquipmentSlot>;

  void addEquipmentSlot(EquiptmentSlotBase);

protected:
  //! ID given to next equipable item.
  EquipmentSlot::id_t m_nextEqupmentSlotId;
  //! container of EquipmentSlot
  equipmentSlots_t m_equipmentSlots;
};
