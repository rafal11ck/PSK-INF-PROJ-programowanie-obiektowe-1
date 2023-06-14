
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

/**
 *@file
 *@brief Character interface.
 **/

#include "gameData.hpp"
#include "item.hpp"
#include "stat.hpp"
#include <list>
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

  //! Used for inventory as <Item, qunatity possed by Character>
  using inventory_t = std::map<Item *, long long>;

  //! Game data used by character.
  const GameData &m_gameData;

  //! Base values of stats.
  statValues_t m_baseStatValues;

public:
  /**
   *@brief constructor
   *@param gameData Used by character.
   **/
  Character(const GameData &gameData);

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
   *@brief Gets game data  used by Character.
   *@return ::m_gameData.
   **/
  const GameData &getGameData() const;
};

#endif // CHARACTER_HPP_
