#ifndef GAMEMETADATA_HPP_
#define GAMEMETADATA_HPP_

/**
 *@file
 *@brief GameMetadata interface.
 **/

#include "equipmentSlot.hpp"
#include "stat.hpp"
#include <memory>
#include <vector>

/**
 *@brief Holds game metadata.
 *
 *It will deallocate Stat and EquipmentSlot added to it so those should not be
 *deallcated manually.
 * */
class GameMetadata {
public:
  //! Type used for stats collection.
  using statsCollection_t = std::vector<Stat *>;
  //! Type used for stroing equpment slots collection.
  using equiptmentSlotsCollection_t = std::vector<EquipmentSlot *>;

private:
  //! Collection of Stat added.
  statsCollection_t m_stats;
  //! Collection of EquipmentSlot added.
  equiptmentSlotsCollection_t m_equipmentSlots;

  /// Id that will be set to the next Stat added.
  BasicGameData::id_t m_nextStatId{1};
  /// Id that will be set to the next EquipmentSlot added.
  BasicGameData::id_t m_nextEquipmentSlotId{1};

public:
  /**
   *@brief Add given stat.
   *@param stat Stat to add.
   **/
  void addStat(Stat *stat);

  /**
   *@brief Add given EquipmentSlot.
   *@param eqSlot EquipmentSlot to add..
   **/
  void addEquipmentSlot(EquipmentSlot *eqSlot);

  /**
   *@brief Getter for Stat based on id.
   *@param id Id of Stat to fetch
   *@return Stat with given id, or nullptr if not found.
   **/
  Stat *getStat(Stat::id_t id) const;

  /**
   *@brief Getter for EquipmentSlot based on id.
   *@param id Id of EquipmentSlot to fetch
   *@return EquipmentSlot with given id, or nullptr if not found.
   **/
  EquipmentSlot *getEquipmentSlot(Stat::id_t id) const;
};

#endif // GAMEMETADATA_HPP_
