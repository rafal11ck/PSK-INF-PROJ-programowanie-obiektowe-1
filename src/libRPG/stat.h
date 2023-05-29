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
class Stat {
public:
  Stat(std::string name);
  friend std::ostream &operator<<(std::ostream &os, const Stat &data);

private:
  virtual std::ostream &print(std::ostream &out) const;

protected:
  //! Name of stat.
  std::string m_name;
};

#endif // GAMESTAT_H
