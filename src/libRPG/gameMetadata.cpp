#include "gameMetadata.h"
#include "stateBase.h"
#include <exception>
#include <list>

/**
 *@file
 *@brief GameMetadata impementation file.
 * */
void GameMetadata::addState(StateBase *state) {
  for (const StateBase *it : m_states) {
    if (it->getName() == state->getName())
      std::__throw_invalid_argument("State with such name already exists");
  }
  m_states.push_back(state);
}
