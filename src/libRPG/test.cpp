
#include "character.hpp"
#include "gameData.hpp"
#include "gameMetadata.hpp"
#include <iostream>

void addStats(GameMetadata *gameMetadata) {
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

void addEqSltos(GameMetadata *gameMetadata) {
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

void addItems(GameData *gameData) {
  //![Adding Item to GameData]
  Item *item{new Item(gameData, "Stick")};
  item->addModifier(1, 3);
  item->setEquipableOn(3);

  Item *item2{new Item(gameData, "Sunglasses", "They protect from sun")};
  item2->addModifier(2, 100);
  item2->setEquipableOn(2);
  //![Adding Item to GameData]

  for (const Item *it : gameData->getItems()) {
    std::cout << it->getId() << '\t' << it->getName() << '\t'
              << it->getDescription() << '\t';
    for (const Item::modifier_t &mod : it->getModifiers()) {
      std::cout << "Mod:\t" << gameData->getStat(mod.first)->getName() << " by "
                << mod.second;
    }
    std::cout << '\n';
  }
}

Character *testCharacter(const GameData *gd) {
  Character *character{new Character(gd)};

  character->setBaseStatValue(1, 4);

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

void testInventory(Character *character) {
  character->getGameData()->getItems()
}

int main() {
  GameData *gd{new GameData};
  addStats(gd);
  addEqSltos(gd);
  addItems(gd);

  Character *character{testCharacter(gd)};

  delete character;

  delete gd;
}
