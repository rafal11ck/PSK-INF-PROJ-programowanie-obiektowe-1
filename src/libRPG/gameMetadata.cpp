/**
 *@file gameData Class implementation.
 **/

#include "gameMetadata.h"
#include "gameStat.h"

void GameMetadata::addStat(std::string name) {
  GameStat statToAdd(name, m_nextStatId);
  ++m_nextStatId;
  m_stats.push_back(statToAdd);
}

const GameMetadata::gameStats_t GameMetadata::getStats() { return m_stats; }
