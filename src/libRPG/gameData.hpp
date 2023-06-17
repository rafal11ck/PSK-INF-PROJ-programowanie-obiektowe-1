#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_

/**
 *@file
 *@brief GameData interface.
 * */
#include "gameMetadata.hpp"
#include "item.hpp"
#include "state.hpp"
#include <exception>
#include <map>
#include <set>

/**
 *@brief Thrown when attempted to do operation that requires 2 objects to use
 *common GameData but different were used.
 * */
class excpetionGameDataMissmatch : public std::exception {
  /**
   *@brief what
   *@returns message
   **/
  std::string what();
};

/**
 *@brief On top of what GameMetadata does. Holds items cataloge.
 *@see GameMetadata
 */
class GameData : public GameMetadata {
public:
  //! Collection used to hold items.
  using itemcollection_t = std::set<Item *>;

  //! Colection used to hold states.
  using stateCollcetion_t = std::set<State *>;

private:
  //! Collection of items that exist in game collection.
  itemcollection_t m_items;
  //! Id that will be given to next item added.
  Item::id_t m_nextItemId{1};

  //! Collection of states that exist in game.
  stateCollcetion_t m_states;
  //! Id that will be given to next state added.
  State::id_t m_nextStateId{1};

public:
  /**
   *@brief Desctructor
   **/
  ~GameData();

  /**
   *@brief Adds item to collection and sets it's id.
   *@param item Item to add.
   *
   *@note It does not validate item.
   **/
  void addItem(Item *item);

  /**
   *@brief Getter.
   *@return ::m_items.
   */
  const itemcollection_t &getItems() const;

  /**
   *@brief Get Item.
   *@param id Id of Item to fetch.
   *@return Item with given id.
   *
   *@throw exceptionNonExistingId Tried to get item that does not exist.
   **/
  const Item *const getItem(Item::id_t id) const;

  /**
   *@brief Checks if Item uses this GameData insnace as it's metadata.
   *@param entity Entity to check.
   **/
  void validateDataIntegrity(const StatModifyingEntity &entity) const;

  /**
   *@brief Adds State to collection and sets it's id.
   *@param state State to add.
   *@snippet test.cpp Adding State to GameData
   * */
  void addState(State *state);

  /**
   *@brief States getter
   *@return m_states
   **/
  const stateCollcetion_t &getStates() const;

  /**
   *@brief State getter.
   *@param id Id of State to get.
   *@return state with id asked.
   *
   *@throw exceptionNonExistingId Tried to get State that does not exist.
   */
  const State *const getState(State::id_t id) const;
};
#endif // GAMEDATA_HPP_
