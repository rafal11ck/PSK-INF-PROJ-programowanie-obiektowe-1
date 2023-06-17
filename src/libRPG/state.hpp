#ifndef STATE_HPP_
#define STATE_HPP_

/**
 *@file
 *@brief State interface.
 **/

#include "statModifyingEntity.hpp"

class GameData;

/**
 *@brief Reperesents State in game.
 **/
class State : public StatModifyingEntity {
public:
  /**
   *@brief Constructor
   *@param gameData Gamedata into which State will be added
   *@param name Name of state.
   *@param description Description of state.
   **/
  State(GameData *gameData, std::string name, std::string description = "");
};

#endif // STATE_HPP_
