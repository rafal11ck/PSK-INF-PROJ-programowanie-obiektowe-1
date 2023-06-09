#include "gameMetadata.h"
#include "basicGameMetadata.h"
#include "stateBase.h"
#include <exception>
#include <list>

GameMetadata::GameState::GameState(StateBase base, id_t id)
    : StateBase(base), m_id(id){};

/**
 *@file
 *@brief GameMetadata impementation file.
 * */
void GameMetadata::addState(StateBase state) {
  for (const StateBase it : m_states) {
    if (it.getName() == state.getName())
      std::__throw_invalid_argument("State with such name already exists");
  }
  m_states.push_back(state);
}

std::ostream &GameMetadata::print(std::ostream &os) const {
  os << "GameMetadata {\n";
  BasicGameMetadata::print(os);
  for (const StateBase &it : m_states) {
    os << it;
  }

  os << "\n}";
  return os;
};
