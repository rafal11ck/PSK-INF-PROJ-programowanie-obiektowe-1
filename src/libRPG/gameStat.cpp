
#include "gameStat.h"
#include <ostream>
#include <string>

GameStat::GameStat(std::string name, id_t id) : m_name(name), m_id(id){};

std::ostream &operator<<(std::ostream &os, const GameStat &data) {
  os << "{ m_name=" << data.m_name << ", m_id=" << data.m_id << " }";
  return os;
}
