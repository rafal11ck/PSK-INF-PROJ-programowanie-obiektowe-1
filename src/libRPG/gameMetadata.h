#ifndef GAMEMETADATA_H
#define GAMEMETADATA_H

/**
 *@file
 *GameMetadata interface.
 **/

#include "basicGameMetadata.h"
#include "statModifiers.h"
#include "stateBase.h"

/**
 *@brief Holds game metadata
 *
 *- Stats
 **/
class GameMetadata : public BasicGameMetadata {
public:
  //! Colletion type of states.
  using statesCollecton_t = std::vector<StateBase *>;

private:
  //! States that exist in game. Those should be given to
  //! Player.
  statesCollecton_t m_states;

public:
  void addState(StateBase *state);
};

#endif // GAMEMETADATA_H
