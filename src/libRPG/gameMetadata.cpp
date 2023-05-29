/**
 *@file
 *@brief GameMetadata class implementation.
 **/

#include "gameMetadata.h"
#include "stat.h"

/**
 *@brief Constructor.
 *@param name Name of stat.
 *@param id of stat.
 **/
GameMetadata::GameStat::GameStat(std::string name, id_t id)
    : Stat(name), m_id(id){};

/**
 *@brief Print content of GameStat into stream.
 *@param out Where to print to.
 **/
std::ostream &GameMetadata::GameStat::print(std::ostream &out) {
  out << "{id=" << m_id << ", name=" << m_name << "}";
  return out;
}

/**
 *@brief Adds stat with given name.
 *@param name What name of new stat will be.
 **/
void GameMetadata::addStat(std::string statName) {
  GameStat stat = GameStat(statName, m_nextStatId);
  ++m_nextStatId;
  m_stats.push_back(stat);
}

/**
 *@brief GameMetadata::m_stats getter.
 *@return GameMetadata::m_stats.
 **/
const GameMetadata::gameStats_t &GameMetadata::getStats() { return m_stats; }
