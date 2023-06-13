/**
 *@file
 *@brief GameData implementation.
 **/

#include "gameData.hpp"
#include "gameMetadata.hpp"

void GameData::addItem(Item *item) { item->setId(m_nextItemId); }
