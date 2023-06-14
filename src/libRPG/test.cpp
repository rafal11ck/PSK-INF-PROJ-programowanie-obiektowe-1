
#include "character.hpp"
#include "gameData.hpp"
#include "item.hpp"
#include <iostream>

GameData *testGameData() {
  GameData *gmd{new GameData()};
  // adding stats
  {
    gmd->addStat(new Stat("strength", "just strength"));
    //![Adding stats to GameMetadata]
    gmd->addStat(new Stat("chadness", "Only chads have this"));
    gmd->addStat(new Stat("speed"));
    //![Adding stats to GameMetadata]

    for (const auto &it : gmd->getStats()) {
      std::cout << it->getId() << '\t' << it->getName() << '\t'
                << it->getDescription() << '\n';
    }
  }

  // adding eq slots
  {
    //![Adding EquipmentSlot to GameMetadata]
    gmd->addEquipmentSlot(new EquipmentSlot("Leg", "Leg is leg"));
    gmd->addEquipmentSlot(new EquipmentSlot("Head"));
    gmd->addEquipmentSlot(new EquipmentSlot("Hand", "For gloves or smth"));
    //![Adding EquipmentSlot to GameMetadata]

    for (const auto &it : gmd->getEquipmentSlots()) {
      std::cout << it->getId() << '\t' << it->getName() << '\t'
                << it->getDescription() << '\n';
    }
  }

  // adding items.
  {
    //![Adding Item to GameData]
    Item *item{new Item(gmd, "Stick")};
    item->addModifier(1, 3);
    item->setEquipableOn(3);

    Item *item2{new Item(gmd, "Sunglasses", "They protect from sun")};
    item2->addModifier(2, 100);
    item2->setEquipableOn(3);
    //![Adding Item to GameData]

    for (const Item *it : gmd->getItems()) {
      std::cout << it->getId() << '\t' << it->getName() << '\t'
                << it->getDescription() << '\t';
      for (const Item::modifier_t &mod : it->getModifiers()) {
        std::cout << "Mod:\t" << gmd->getStat(mod.first)->getName() << " by "
                  << mod.second;
      }
      std::cout << '\n';
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
