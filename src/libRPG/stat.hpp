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
};

#endif // STAT_HPP
