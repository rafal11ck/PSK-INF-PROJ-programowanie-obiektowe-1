#include "basicGamedata.hpp"
#include <exception>
#include <list>
#include <string>
#include <sys/types.h>

/**
 *@file
 *@brief BasicGameData implementation.
 **/

std::string exceptionIllegalId::what() {
  return "Tried to perform operations on instance with invalid id";
}

BasicGameData::BasicGameData(std::string name, std::string description)
    : m_name(name), m_description(description) {}

void BasicGameData::setId(id_t id) {
  if (id == INVALID_ID)
    return;
  m_id = id;
}

void BasicGameData::validateIntegrity() const {
  //! Checks if id is INVALID_ID.
  if (m_id == INVALID_ID) {
    //! @throw exceptionIllegalId id is illegal.
    throw exceptionIllegalId();
  }
}

void BasicGameData::setName(std::string name) { m_name = name; }

void BasicGameData::setDescription(std::string description) {
  m_description = description;
}

std::string BasicGameData::getName() const { return m_name; }

std::string BasicGameData::getDescription() const { return m_description; };

//! @todo Change exception type
BasicGameData::id_t BasicGameData::getId() const {
  if (m_id == INVALID_ID)
    std::__throw_runtime_error("Illegal id");
  return m_id;
};

bool BasicGameData::isId(id_t id) const {
  validateIntegrity();
  bool res{m_id == id};
  return res;
}
