#include "gameMetadata.h"
#include <iostream>
#include <ostream>
#include <string>

constexpr std::ostream &os{std::cout};

GameMetadata game{};

void addStats() {

  for (std::string it : std::vector<std::string>{
           "wytrzymałość", "zręczność", "inteligencja", "wiedza", "szybkość"}) {
    game.addStat(it);
  }

  os << "Game stats\n";
  for (const Stat &it : game.getStats()) {
    os << it << '\n';
  }
}

int main() { addStats(); }
