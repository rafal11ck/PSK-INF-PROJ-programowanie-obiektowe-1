
#include "stat.h"
#include <ostream>
#include <string>

/**
 *@file
 *@brief GameStat implementation.
 * */

/**
 *@brief Constructor.
 **/
Stat::Stat(std::string name) : m_name(name){};

/**
 *@brief data extraction to stream.
 **/
std::ostream &Stat::print(std::ostream &out) const {
  out << "{" << m_name << "}";
  return out;
}

std::ostream &operator<<(std::ostream &os, const Stat &data) {
  data.print(os);
  return os;
}
