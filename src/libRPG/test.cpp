
#include "basicGamedata.hpp"
#include "character.hpp"
#include "equipmentSlot.hpp"
#include "gameData.hpp"
#include "gameMetadata.hpp"
#include "item.hpp"
#include <iostream>

GameData *testGameData() {
  GameData *gmd{new GameData()};
  // adding stats
  {
    gmd->addStat(new Stat("strength", "just strength"));
    gmd->addStat(new Stat("chadness", "Only chads have this"));
    gmd->addStat(new Stat("speed"));

    for (const auto &it : gmd->getStats()) {
      std::cout << it->getId() << '\t' << it->getName() << '\t'
                << it->getDescription() << '\n';
    }
  }

  // adding eq slots
  {
    gmd->addEquipmentSlot(new EquipmentSlot("Leg", "Leg is leg"));
    gmd->addEquipmentSlot(new EquipmentSlot("Head"));
    gmd->addEquipmentSlot(new EquipmentSlot("Hand", "For gloves or smth"));

    for (const auto &it : gmd->getEquipmentSlots()) {
      std::cout << it->getId() << '\t' << it->getName() << '\t'
                << it->getDescription() << '\n';
    }
  }

  // adding items.
  {
    Item *item{new Item(*gmd, "Stick")};
    item->addModifier(1, 3);
    item->setEquipableOn(3);
    gmd->addItem(item);

    for (const auto &it : gmd->getItems()) {
      // HERE
      std::cout << it;
    }
  }

  return gmd;
}

Character *testCharacter(const GameData *gd) {
  Character *character{new Character(*gd)};

  character->setBaseStatValue(1, 4);

  try {
    character->setBaseStatValue(1000, 64356);
  } catch (exceptionNonExistingId &e) {
    std::cerr << "Absurd thing thrown exception as it was supposed to.\n";
    std::cerr << e.what() << '\n';
  }

  for (auto stat : character->getGameData().getStats()) {
    std::cout << stat->getName() << " =\t"
              << character->getBaseStatValue(stat->getId()) << '\n';
  }

  return character;
};

int main() {
  GameData *gmd{testGameData()};

  delete testCharacter(gmd);

  delete gmd;
}
