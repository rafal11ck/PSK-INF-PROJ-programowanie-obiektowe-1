#include "gameMetadata.h"
#include <iostream>
#include <ostream>

constexpr std::ostream &os{std::cout};

int main() {

  GameMetadata game{};
  game.addStat("życie");
  game.addStat("mana");

  os << "Game stats\n";
  for (GameStat it : game.getStats()) {
    os << it;
  }
}
