#ifndef GAMEDATA_H
#define GAMEDATA_H

/**
 *@file
 *@brief GameMetadata interface.
 **/

#include "stat.h"
#include <ostream>
#include <vector>

/**
 *@brief Contains information about game metadata.
 */
class GameMetadata {
public:
  /**
   *@breif
   *Stat repestantion within infromation about game.
   **/
  class GameStat : public Stat {
  public:
    //! type used for ids.
    using id_t = int;

    GameStat(std::string name, id_t id);

    virtual std::ostream &print(std::ostream &out);

  private:
    const id_t m_id;
  };

public:
  //! Container which is used to store stats.
  using gameStats_t = std::vector<GameStat>;

public:
  void addStat(std::string statName);
  void addEquipableSlot(std::string name);
  const gameStats_t &getStats();

private:
  //! Id of next stat when it's added by addStat().
  GameStat::id_t m_nextStatId{};
  //! Stats that exist in the game.
  gameStats_t m_stats;
};

#endif // GAMEDATA_H
