#ifndef GAMEMETADATA_HPP_
#define GAMEMETADATA_HPP_

/**
 *@file
 *@brief GameMetadata interface.
 **/

#include "equipmentSlot.hpp"
#include "stat.hpp"
#include <exception>
#include <memory>
#include <stdexcept>
#include <vector>

/**
 *@brief Exception.
 */
class exceptionNonExistingId : std::exception {
public:
  /**
   *@brief What.
   *@returns message.
   */
  virtual std::string what();
};

/**
 *@brief Holds game metadata. That is what statistics exist and what equipable
 *slots exist.
 *
 *
 *It will deallocate Stat and EquipmentSlot added to it so those should not
 *be deallcated manually.
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
   * @brief Destructor
   *
   * Deallocates all added equipmentslots and stats.
   * */
  ~GameMetadata();

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
   *@return Stat with given id.
   *@throws exceptionNonExistingId When tried to fetch insance with id that
   *doesn't exist.
   **/
  Stat *getStat(Stat::id_t id) const;

  /**
   *@brief Stats getter.
   *@return m_stats.
   **/
  const statsCollection_t &getStats() const;

  /**
   *@brief Getter for EquipmentSlot based on id.
   *@param id Id of EquipmentSlot to fetch
   *@return EquipmentSlot with given id.
   *
   *@throws exceptionNonExistingId When tried to fetch insance with id that
   *doesn't exist.
   **/
  EquipmentSlot *getEquipmentSlot(Stat::id_t id) const;

  /**
   *@brief Equipmentslots getter.
   *@return Equipment slots
   **/
  const equiptmentSlotsCollection_t &getEquipmentSlots() const;
};

#endif // GAMEMETADATA_HPP_
