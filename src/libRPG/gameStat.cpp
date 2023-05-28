
#include "gameStat.h"
#include <ostream>
#include <string>

/**
 *@file
 *@brief GameStat implementation.
 * */

/**
 *@brief Constructor.
 **/
GameStat::GameStat(std::string name, id_t id) : m_name(name), m_id(id){};

/**
 *@brief data extraction to stream.
 **/
std::ostream &operator<<(std::ostream &os, const GameStat &data) {
  os << "{m_id=" << data.m_id << "\tname=" << data.m_name << "}";
  return os;
}
