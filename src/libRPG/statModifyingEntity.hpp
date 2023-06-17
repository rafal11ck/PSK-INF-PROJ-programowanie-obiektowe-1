
#ifndef STATMODYFINGENTITY_HPP_
#define STATMODYFINGENTITY_HPP_

/**
 *@file
 *@brief StatModifyingEntity interface.
 **/

#include "basicGamedata.hpp"
#include "gameMetadata.hpp"
#include "stat.hpp"
#include <vector>

/**
 *@brief Repesents collection of stat modifiers.
 *
 *It modifies Stats so it needs access to information about what stats do
 *exist.
 *Associtates instance with gameMetadata.
 * */
class StatModifyingEntity : public BasicGameData {
public:
  //! Repesents modification of stats <stat modyfied, value of modification>
  using modifier_t = std::pair<Stat::id_t, Stat::value_t>;
  //! Collection type used to store modifers.
  using modifersCollection_t = std::vector<modifier_t>;

private:
  //! Holds modifiers.
  modifersCollection_t m_modifiers;

  //! Game Metadata.
  const GameMetadata *const m_gameMetadata;

public:
  /**
   *@brief Constructor.
   *@param gameMetadata gameMetadata that instance is about.
   *@param name Name
   *@param description Description.
   *
   **/
  StatModifyingEntity(const GameMetadata *const gameMetadata, std::string name,
                      std::string description = "");

  /**
   *@brief Add modification of stats.
   *@param statModifed modified.
   *@param by Modify value.
   **/
  void addModifier(Stat::id_t, Stat::value_t by);

  /**
   *@brief Modifier value getter.
   *@param id Id of stat to get value of modifier of.
   *@return Modifier value or 0 if Instance does not modify stat asked.
   * */
  Stat::value_t getmodifierValue(Stat::id_t id);
  /**
   *@brief GameMeatadata getter.
   *@return GemeMetadata used by instance.
   **/
  const GameMetadata *const getGameMetadata() const;

  /**
   *@brief Modifiers getter.
   *@return ::m_modifiers
   * */
  const modifersCollection_t &getModifiers() const;
};
#endif // STATMODYFINGENTITY_HPP_
