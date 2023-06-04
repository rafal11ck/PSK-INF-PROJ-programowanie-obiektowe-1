#include "equipmentSlots.h"
#include "gameStats.h"
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

void testEqupmenSlots() {
  os << "EquipmentSlots\n";

  EquipmentSlots eqSlots{};
  eqSlots.addEquipmentSlot({"noga", "noga a co"});
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

int main() {
  testStats();
  testEqupmenSlots();
}
