
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

/**
 *@file
 *@brief Character interface.
 **/

#include "gameMetadata.hpp"
#include "stat.hpp"
#include <map>
#include <vector>

/**
 *@brief Represents character.
 *
 *Base character stats are stats that character has without any modifiers
 *applied.
 *If Base stat is not set it will be assumed to be 0;
 **/
class Character {
  //! Type used for repesentation of base character stats.
  using statValues_t = std::map<Stat::id_t, Stat::value_t>;

  //! GameMetadata used by character.
  const GameMetadata &m_gameMetadata;

  //! Base values of stats.
  statValues_t m_baseStatValues;

public:
  /**
   *@brief constructor
   *@param gameMetadata GameMetadata that Character should use.
   **/
  Character(const GameMetadata &gameMetadata);

  /**
   *@brief Sets base stat value.
   *@param statId Id to set value of.
   *@param val Value to set.
   **/
  void setBaseStatValue(Stat::id_t statId, Stat::value_t val);

  /**
   *@brief Base statistics value getter.
   *@param id of stat to get base value of.
   *@return Base value of stat with given id.
   *
   *If Character does not have base Stat value of given id 0 is returned as per
   *class invariant.
   **/
  Stat::value_t getBaseStatValue(Stat::id_t id) const;

  /**
   *@brief Gets GameMetadata used by Character.
   *@return GameMetadata used by Character.
   **/
  const GameMetadata &getGameMetadata() const;
};

#endif // CHARACTER_HPP_
