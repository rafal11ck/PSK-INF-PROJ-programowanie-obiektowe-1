#ifndef STAT_H
#define STAT_H
#include <string>

/**
 *@file
 *Interface.
 **/

/**
 *@brief
 *Represents statistics (types like atack, defense) in game.
 **/
class StatBase {
public:
  StatBase(std::string name);
  friend std::ostream &operator<<(std::ostream &os, const StatBase &data);

private:
  virtual std::ostream &print(std::ostream &out) const;

protected:
  //! Name of stat.
  std::string m_name;
};

#endif // GAMESTAT_H
