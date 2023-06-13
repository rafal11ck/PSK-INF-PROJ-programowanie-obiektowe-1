#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_

#include "gameMetadata.hpp"

/**
 *@brief Holds data about game and game metadata.
 *
 *@see GameMetadata
 */
class GameData {
private:
  //! Game metadata.
  GameMetadata m_gameMetadata;

public:
  /**
   *@brief Game metadata getter.
   *@return ::m_gameMetadata.
   **/
  GameMetadata &getMetadata();

  /**
   *@copydoc getMetadata()
   **/
  const GameMetadata &getMetadata() const;
};

#endif // HAMEDATA_HPP_
