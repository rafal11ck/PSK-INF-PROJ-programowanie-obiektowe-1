
#ifndef STATMODYFINGENTITY_HPP_
#define STATMODYFINGENTITY_HPP_

/**
 *@file
 *@brief StatModifyingEntity interface.
 **/

#include "stat.hpp"
#include <utility>
#include <vector>

/**
 *@brief Repesents collection of stat modifiers.
 * */
class StatModifyingEntity {
public:
  //! Repesents modification of stats <stat modyfied, value of modification>
  using modifier_t = std::pair<const Stat *const, Stat::value_t>;
  //! Collection type used to store modifers.
  using modifersCollection_t = std::vector<modifier_t>;

private:
  //! Holds modifiers.
  modifersCollection_t m_modifiers;

public:
  /**
   *@brief Add modification of stats.
   *@param statModifed modified.
   *@param by Modify value.
   **/
  void addModifier(const Stat *const statModifed, Stat::value_t by);
};
#endif // STATMODYFINGENTITY_HPP_
