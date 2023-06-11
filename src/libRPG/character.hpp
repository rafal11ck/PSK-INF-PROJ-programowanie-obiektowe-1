
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

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

  //! gameMetadata used by character.
  const GameMetadata &m_gameData;

  statValues_t m_baseStatValues;

public:
  /**
   *@brief constructor
   *@param gameMetaData GameMetadata that Character should use.
   **/
  Character(GameMetadata &gameMetadata);

  /**
   *@brief Base statistics value getter.
   *@param id of stat to get base value of.
   **/
  Stat::value_t getBaseStatValue(Stat::id_t id) const;

  /**
   *@brief Sets base stat value.
   *@param statId Id to set value of.
   *@param val Value to set.
   **/
  void setStatValue(Stat::id_t statId, Stat::value_t val);
};

#endif // CHARACTER_HPP_
