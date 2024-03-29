#ifndef BASICGAMEMETADATA_HPP_
#define BASICGAMEMETADATA_HPP_

#include <exception>
#include <limits>
#include <string>

/**
 *@file
 *@brief BasicGameData interface.
 **/

/**
 *@brief Illegal id exception
 *@see BasicGameData::INVALID_ID
 * */
class exceptionIllegalId : public std::exception {
  /**@brief What.
   *@return Info string.
   */
  std::string what();
};

/**
 *@brief Basic information about game.
 * */
class BasicGameData {
  friend class GameMetadata;
  friend class GameData;

public:
  //! Type used for ids.
  using id_t = long long;
  //! Value indicating that id is invalid.
  static constexpr id_t INVALID_ID{std::numeric_limits<id_t>::min()};

private:
  //! id.
  id_t m_id{INVALID_ID};
  //! name.
  std::string m_name;
  //! description.
  std::string m_description;

public:
  /**
   *@brief Constructor creating object with given name and optional
   *description.
   *@param name Name.
   *@param description optional description.
   * */
  BasicGameData(std::string name, std::string description = "");

protected:
  /**
   *@brief id setter.
   *@param id Id to set.
   *If id to be set is INVALID_ID this will not be set.
   */
  void setId(id_t id);

  /**
   *@brief Check itegrity of data.
   **/
  void validateIntegrity() const;

public:
  /**
   *@brief Sets name.
   *@param name name to be set.
   */
  void setName(std::string name);

  /**
   *@brief Sets description.
   *@param description Description to be set.
   */
  void setDescription(std::string description);

  /**
   *@brief name getter.
   *@return name
   **/
  std::string getName() const;

  /**
   *@brief Description getter.
   *@return Description.
   **/
  std::string getDescription() const;

  /**
   *@brief id getter.
   *@return id.
   **/
  id_t getId() const;

  /**
   *@brief Check if id is equal.
   *@param id Id to check.
   *@return True if id is same as parameter.
   **/
  bool isId(id_t id) const;
};

#endif // BASICGAMEMETADATA_HPP_
