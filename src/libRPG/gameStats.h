#ifndef GAMESTATS_H
#define GAMESTATS_H

/**
 *@file
 *@brief GameMetadata interface.
 **/

#include "statBase.h"
#include <ostream>
#include <vector>

/**
 *@brief Holds collection of Stats. Maintains locally unique ids.
 */
class GameStats {
public:
  /**
   *@brief
   *Stat repestantion within infromation about game.
   **/
  class GameStat : public StatBase {
  public:
    //! type used for ids.
    using id_t = int;

    GameStat(const StatBase &statB, id_t id);

  private:
    virtual std::ostream &print(std::ostream &out) const;

  private:
    //! id of GameStat, should be unique within GameStats instance.
    const id_t m_id;
  };

public:
  //! Container which is used to store stats.
  using gameStats_t = std::vector<GameStat>;

  void addStat(std::string statName);
  const gameStats_t &getStats();

private:
  //! Id of next stat when it's added by addStat().
  GameStat::id_t m_nextStatId{};

protected:
  //! Stats that exist in the game.
  gameStats_t m_stats;
};

#endif // GAMESTATS_H
