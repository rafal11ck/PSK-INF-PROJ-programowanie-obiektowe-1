#ifndef STAT_HPP
#define STAT_HPP

/**
 *@file
 *@brief Stat interface.
 **/

#include "basicGamedata.hpp"

/**
 *@brief Statistics.
 * */
class Stat : public BasicGameData {
public:
  //! Type of stat value.
  using value_t = long long;

  /**
   *@brief Constructor
   *@param name Name of statistics.
   *@param description Optional description of statistics;
   **/
  Stat(std::string name, std::string description = "");
};

#endif // STAT_HPP
