#ifndef GAMESTAT_H
#define GAMESTAT_H
#include <string>

class GameStat {
public:
  using id_t = int;

  GameStat(std::string name, id_t id);

  friend std::ostream &operator<<(std::ostream &os, const GameStat &data);

private:
  id_t m_id;
  std::string m_name;
};

#endif // GAMESTAT_H
