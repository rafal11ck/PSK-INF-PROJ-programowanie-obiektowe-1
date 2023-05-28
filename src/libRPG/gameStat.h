#ifndef GAMESTAT_H
#define GAMESTAT_H
#include <string>

/**
 *@file
 *GameStat interface.
 **/

/**
 *@brief
 *Gamestat, represents statistics (types like atack, defense) in game.
 **/
class GameStat {
public:
  //! type used for GameStat::m_id.
  using id_t = int;

  GameStat(std::string name, id_t id);

  friend std::ostream &operator<<(std::ostream &os, const GameStat &data);

private:
  //! See GameMetadata.
  id_t m_id;
  //! Name of stat.
  std::string m_name;
};

#endif // GAMESTAT_H
