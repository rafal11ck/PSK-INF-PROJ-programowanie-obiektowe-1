/**
 *@file
 *@brief GameMetadata class implementation.
 **/

#include "gameMetadata.h"
#include "gameStat.h"

/**
 *@brief Adds stat with given name.
 *@param name What name of new stat will be.
 **/
void GameMetadata::addStat(std::string name) {
  GameStat statToAdd(name, m_nextStatId);
  ++m_nextStatId;
  m_stats.push_back(statToAdd);
}

/**
 *@brief GameMetadata::m_stats getter.
 *@return GameMetadata::m_stats.
 **/
const GameMetadata::gameStats_t &GameMetadata::getStats() { return m_stats; }
