#include "gameStats.h"
#include <iostream>
#include <ostream>
#include <string>

constexpr std::ostream &os{std::cout};

GameStats gameStats{};

void addStats() {

  for (std::string it : std::vector<std::string>{
           "wytrzymałość", "zręczność", "inteligencja", "wiedza", "szybkość"}) {
    gameStats.addStat(it);
  }

  os << "Game stats\n";
  for (const Stat &it : gameStats.getStats()) {
    os << it << '\n';
  }
}

int main() { addStats(); }
