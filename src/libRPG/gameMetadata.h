
#ifndef GAMEDATA_H
#define GAMEDATA_H
#include "gameStat.h"
#include <vector>

class GameMetadata {
public:
  using gameStats_t = std::vector<GameStat>;

  void addStat(std::string name);
  const gameStats_t getStats();

private:
  GameStat::id_t m_nextStatId{};

  gameStats_t m_stats{};
};

#endif // GAMEDATA_H
