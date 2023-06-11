#include "basicGamedata.hpp"
#include <exception>
#include <string>

/**
 *@file
 *@brief BasicGameData implementation.
 **/

BasicGameData::BasicGameData(std::string name, std::string description)
    : m_name(name), m_description(description) {}

void BasicGameData::setId(id_t id) {
  if (id == INVALID_ID)
    return;
  m_id = id;
}

void BasicGameData::setName(std::string name) { m_name = name; }

void BasicGameData::setDescription(std::string description) {
  m_description = description;
}

std::string BasicGameData::getName() const { return m_name; }

std::string BasicGameData::getDescription() const { return m_description; };

BasicGameData::id_t BasicGameData::getId() const { return m_id; };
