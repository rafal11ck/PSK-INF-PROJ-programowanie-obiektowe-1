
#ifndef BASICGAMEMETADATA_H
#define BASICGAMEMETADATA_H
/**
 *@file
 *@brief Implementation file
 **/

#include "equipmentSlots.h"
#include "gameStats.h"

/**
 *@brief Contains metadata about game.
 *
 *Stats and equipment slots.
 * */
class BasicGameMetadata : public GameStats, public EquipmentSlots {

public:
  virtual std::ostream &print(std::ostream &os) const;
  friend std::ostream &operator<<(std::ostream &os, BasicGameMetadata &data);
};

#endif // BASICGAMEMETADATA_H
