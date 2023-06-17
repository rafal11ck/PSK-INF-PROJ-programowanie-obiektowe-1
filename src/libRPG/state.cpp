#include "state.hpp"
#include "gameData.hpp"
#include "statModifyingEntity.hpp"
/**
 *@file
 *@brief State implementation
 **/

State::State(GameData *gameData, std::string name, std::string description)
    : StatModifyingEntity(gameData, name, description) {
  gameData->addState(this);
}
