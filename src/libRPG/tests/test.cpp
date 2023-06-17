/**
 * @file test.cpp
 * @example{lineno}
 * @brief GameData and related classes test.
 **/
#include "character.hpp"
#include "equipmentSlot.hpp"
#include "gameData.hpp"
#include "gameMetadata.hpp"
#include <algorithm>
#include <iostream>

/**
 *@param gameMetadata Where satas are added to.
 **/
void addStats(GameMetadata *gameMetadata) {
  std::cout << std::string(15, '-') << "addStats\n";
  //![Adding stats to GameMetadata]
  gameMetadata->addStat(new Stat("strength", "just strength"));
  gameMetadata->addStat(new Stat("chadness", "Only chads have this"));
  gameMetadata->addStat(new Stat("speed"));
  //![Adding stats to GameMetadata]

  for (const auto &it : gameMetadata->getStats()) {
    std::cout << it->getId() << '\t' << it->getName() << '\t'
              << it->getDescription() << '\n';
  }
}

/**
 *@param gameMetadata Where equipment slots are added to.
 **/
void addEqSlots(GameMetadata *gameMetadata) {
  std::cout << std::string(15, '-') << "addEqSlots\n";
  {
    //![Adding EquipmentSlot to GameMetadata]
    gameMetadata->addEquipmentSlot(new EquipmentSlot("Leg", "Leg is leg"));
    gameMetadata->addEquipmentSlot(new EquipmentSlot("Head"));
    gameMetadata->addEquipmentSlot(
        new EquipmentSlot("Hand", "For gloves or smth"));
    //![Adding EquipmentSlot to GameMetadata]

    for (const auto &it : gameMetadata->getEquipmentSlots()) {
      std::cout << it->getId() << '\t' << it->getName() << '\t'
                << it->getDescription() << '\n';
    }
  }
}

/**
 *@param gameData Where items are added to.
 **/
void addItems(GameData *gameData) {
  std::cout << std::string(15, '-') << "addItems\n";
  //![Adding Item to GameData]
  Item *item{new Item(gameData, "Stick")};
  item->addModifier(1, 3);
  item->setEquipableOn(3);

  Item *item2{new Item(gameData, "Sunglasses", "They protect from sun")};
  item2->addModifier(2, 100);
  item2->setEquipableOn(2);
  //![Adding Item to GameData]

  for (const Item *it : gameData->getItems()) {
    std::cout << it->getId() << '\t' << it->getName()
              << "\tDesc: " << it->getDescription() << '\t';
    for (const Item::modifier_t &mod : it->getModifiers()) {
      std::cout << "Mod:\t" << gameData->getStat(mod.first)->getName() << " by "
                << mod.second;
    }
    std::cout << "\tEquipable on: ";
    for (auto slot : it->getEquipableSlots())
      std::cout << it->getGameMetadata()->getEquipmentSlot(slot)->getName()
                << '\t';
    std::cout << '\n';
  }
}

/**
 *@param gd GameData that will be used by character.
 *@return character.
 **/
Character *testCharacter(GameData *gd) {
  std::cout << std::string(15, '-') << "testCharacter\n";
  //![Character]
  Character *character{new Character(gd)};
  character->setBaseStatValue(1, 4);
  //![Character]

  try {
    character->setBaseStatValue(1000, 64356);
  } catch (exceptionNonExistingId &e) {
    std::cerr << "Absurd thing thrown exception as it was supposed to.\n";
    std::cerr << e.what() << '\n';
  }

  for (auto stat : character->getGameData()->getStats()) {
    std::cout << stat->getName() << " =\t"
              << character->getBaseStatValue(stat->getId()) << '\n';
  }

  return character;
};

/**
 *@param character to whom items will be added.
 **/
void testInventory(Character *character) {
  std::cout << std::string(15, '-') << "testInventory\n";
  //![adding Item to Character inventory]
  // extract item from gamedata accessed from character.
  const Item *itemToAdd{character->getGameData()->getItem(1)};
  character->addItem(itemToAdd);
  character->addItem(itemToAdd);
  character->addItem(character->getGameData()->getItem(2));
  //![adding Item to Character inventory]

  for (const auto &it : character->getInventory()) {
    const Item *item{it.first};
    std::cout << "item id: " << item->getId() << " \tQuantity: " << it.second
              << '\t' << item->getName() << '\n';
  }
}

void testEquipment(Character *character) {
  std::cout << std::string(15, '-') << "testEquipment\n";
  {
    //![Item equiping]
    // Item to equip.
    const Item *item{character->getGameData()->getItem(2)};
    // Slot where to equip that item into.
    EquipmentSlot::id_t slot{*item->getEquipableSlots().begin()};
    // Optional checking if Character has that item in inventory should be here.
    character->equipItem(item, slot);
    // Optional removal of item from Inventory.
    //![Item equiping]
  }

  std::cout << "Equiped Items\n";
  for (const std::pair<const EquipmentSlot *const, const Item *const> &it :
       character->getEquipment()) {
    std::cout << it.first->getName() << ": \t" << it.second->getName() << '\n';
  }
}

int main() {
  GameData *gd{new GameData};
  addStats(gd);
  addEqSlots(gd);
  addItems(gd);

  Character *character{testCharacter(gd)};

  testInventory(character);
  testEquipment(character);

  delete character;

  delete gd;
}
