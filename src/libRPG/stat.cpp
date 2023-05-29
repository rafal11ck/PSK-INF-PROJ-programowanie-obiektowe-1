
#include "stat.h"
#include <ostream>
#include <string>

/**
 *@file
 *@brief GameStat implementation.
 * */

/**
 *@brief Constructor.
 *@param name Name of Stat.
 **/
Stat::Stat(std::string name) : m_name(name){};

/**
 *@brief Data extraction to stream.
 *@param out Where to print to.
 *@return out parameter.
 **/
std::ostream &Stat::print(std::ostream &out) const {
  out << "Stat{name=\"" << m_name << "\"}";
  return out;
}

/**
 *@brief Stream extraction.
 *@param os Stream to which extract to.
 *@param data what to extract.
 *@return os paramater.
 *Calls  Stat::print() internally;
 * */
std::ostream &operator<<(std::ostream &os, const Stat &data) {
  return data.print(os);
}
