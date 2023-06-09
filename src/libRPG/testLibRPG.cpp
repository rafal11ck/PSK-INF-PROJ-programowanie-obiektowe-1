#include "equipmentSlotBase.h"
#include "equipmentSlots.h"
#include "gameMetadata.h"
#include "gameStats.h"
#include "statBase.h"
#include "statModifier.h"
#include "stateBase.h"
#include <iostream>
#include <ostream>
#include <string>

constexpr std::ostream &os{std::cout};

void testStats() {
  GameStats gameStats{};
  os << "gameStats\n";
  for (std::string it : std::vector<std::string>{
           "wytrzymałość", "zręczność", "inteligencja", "wiedza", "szybkość"}) {
    gameStats.addStat(it);
  }

  for (const StatBase &it : gameStats.getStats()) {
    os << it << '\n';
  }
}

void testEquipmenSlots() {
  os << "EquipmentSlots\n";

  EquipmentSlots eqSlots{};
  eqSlots.addEquipmentSlot({"noga", "noga ..."});
  eqSlots.addEquipmentSlot({"ręka"});
  eqSlots.addEquipmentSlot({"głowa"});
  eqSlots.addEquipmentSlot({"dłoń"});
  eqSlots.addEquipmentSlot({"klata"});
  for (const EquipmentSlots::EquipmentSlot &eqSlot :
       eqSlots.getEquipmentSlots()) {
    os << eqSlot << '\n';
  }
  os << '\n';
}

void testGameMetadata() {
  os << std::string(40, '-') << '\n';
  GameMetadata gdat;
  // add stats
  gdat.addStat("poczytalność");
  gdat.addStat("siła");
  gdat.addStat("maxHealth");

  // add equipment slots
  gdat.addEquipmentSlot(EquiptmentSlotBase("noga", "Normalana noga"));
  gdat.addEquipmentSlot(EquiptmentSlotBase("ręka", "Normalna ręka"));
  gdat.addEquipmentSlot(EquiptmentSlotBase("głowa", "Jak sklep"));

  StateBase state("Chad", "Is chad");
  state.addModifier({gdat.getStats().at(0), 5});
  gdat.addState(state);

  os << gdat;
}

int main() {
  testStats();
  testEquipmenSlots();
  testGameMetadata();
}
