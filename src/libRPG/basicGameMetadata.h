
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
class BasicGameMetadata : public GameStats, public EquipmentSlots {};

#endif // BASICGAMEMETADATA_H
