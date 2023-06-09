#ifndef STAT_H
#define STAT_H
#include <string>

/**
 *@file
 *@brief StatBase Interface.
 **/

/**
 *@brief Represents statistics (types like atack, defense) in game.
 **/
class StatBase {
private:
  //! Name of stat.
  std::string m_name;

public:
  StatBase(std::string name);

  virtual const std::string &getName() const;

  friend std::ostream &operator<<(std::ostream &os, const StatBase &data);

private:
  virtual std::ostream &print(std::ostream &out) const;
};

#endif // GAMESTAT_H
