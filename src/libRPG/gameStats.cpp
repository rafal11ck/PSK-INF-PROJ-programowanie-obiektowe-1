/**
 *@file
 *@brief Implementation file.
 **/

#include "gameStats.h"
#include "statBase.h"

/**
 *@brief Constructor.
 *@param statB StatBase.
 *@param id of stat.
 **/
GameStats::GameStat::GameStat(const StatBase &statB, id_t id)
    : StatBase(statB), m_id(id){};

/**
 *@brief Print content of GameStat into stream.
 *@param out Where to print to.
 *@return out parameter.
 **/
std::ostream &GameStats::GameStat::print(std::ostream &out) const {
  out << "GameStat {id= \"" << m_id << "\", name=\"" << m_name << "\"}";
  return out;
}

/**
 *@brief Adds stat with given name.
 *@param name What name of new stat will be.
 **/
void GameStats::addStat(std::string name) {
  GameStat stat = GameStat(name, m_nextStatId);
  ++m_nextStatId;
  m_stats.push_back(stat);
}

/**
 *@brief GameMetadata::m_stats getter.
 *@return GameMetadata::m_stats.
 **/
const GameStats::gameStats_t &GameStats::getStats() { return m_stats; }
