
#include "basicGamedata.hpp"
#include "character.hpp"
#include "equipmentSlot.hpp"
#include "gameMetadata.hpp"
#include <iostream>

GameMetadata *testGameMetadata() {
  GameMetadata *gmd{new GameMetadata()};
  gmd->addStat(new Stat("strength", "just strength"));
  gmd->addStat(new Stat("chadness", "Only chads have this"));
  gmd->addStat(new Stat("speed"));

  for (const auto &it : gmd->getStats()) {
    std::cout << it->getId() << '\t' << it->getName() << '\t'
              << it->getDescription() << '\n';
  }

  gmd->addEquipmentSlot(new EquipmentSlot("Leg", "Leg is leg"));
  gmd->addEquipmentSlot(new EquipmentSlot("Head"));
  gmd->addEquipmentSlot(new EquipmentSlot("Hand", "For gloves or smth"));

  for (const auto &it : gmd->getEquipmentSlots()) {
    std::cout << it->getId() << '\t' << it->getName() << '\t'
              << it->getDescription() << '\n';
  }
  return gmd;
}

Character *testCharacter(const GameMetadata *gmd) {
  Character *character{new Character(*gmd)};

  character->setBaseStatValue(1, 4);

  try {
    character->setBaseStatValue(1000, 64356);
  } catch (exceptionNonExistingId &e) {
    std::cerr << "Absurd thing thrown exception as it was supposed to.\n";
    std::cerr << e.what() << '\n';
  }

  for (auto stat : character->getGameMetadata().getStats()) {
    std::cout << stat->getName() << " =\t"
              << character->getBaseStatValue(stat->getId()) << '\n';
  }

  return character;
};

int main() {
  GameMetadata *gmd{testGameMetadata()};

  delete testCharacter(gmd);

  delete gmd;
}
