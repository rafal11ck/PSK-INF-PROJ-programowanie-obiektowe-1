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
  /**
   *@brief StateBase with id used for indetyfing it.
   **/
  class GameState : StateBase {
  public:
    using id_t = int;
    GameState(StateBase base, id_t id);

  private:
    //! Locally unique id withing GameMetadata.
    id_t m_id;
  };

  //! Colletion type of states.
  using statesCollecton_t = std::vector<StateBase>;

private:
  //! Next id that will be given to state.
  GameState::id_t m_nextGameStateId{};

  //! States that exist in game. Those should be given to
  //! Player.
  statesCollecton_t m_states{};

public:
  void addState(StateBase state);
  virtual std::ostream &print(std::ostream &os) const;
};

#endif // GAMEMETADATA_H
