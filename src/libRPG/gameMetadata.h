#ifndef GAMEDATA_H
#define GAMEDATA_H

/**
 *@file
 *@brief GameMetadata interface.
 **/

#include "gameStat.h"
#include <vector>

/**
 *@brief Contains information about game metadata.
 */
class GameMetadata {
public:
  //! Container which is used to store stats.
  using gameStats_t = std::vector<GameStat>;

public:
  void addStat(std::string name);
  const gameStats_t &getStats();

private:
  //! Id of next stat when it's added by addStat().
  GameStat::id_t m_nextStatId{};
  //! Stats that exist in the game.
  gameStats_t m_stats{};
};

#endif // GAMEDATA_H
