#ifndef GAMEMETADATA_HPP_
#define GAMEMETADATA_HPP_

#include <limits>
#include <string>
#include <vector>

class GameMetadata;

class BasicGameData {
  friend GameMetadata;

public:
  using id_t = long long;
  static constexpr id_t INVALID_ID{std::numeric_limits<id_t>::min()};

private:
  id_t m_id{INVALID_ID};
  std::string m_name;
  std::string m_description;

public:
  BasicGameData(std::string name, std::string description = "");

protected:
  void setId(id_t id);

public:
  void setName(std::string newName);
  void setDescription(std::string newDescription);

  std::string getName() const;
  std::string getDescription() const;
  id_t getId() const;
};

class Stat : public BasicGameData {};

class EquipmentSlot : public BasicGameData {
private:
};

class GameMetadata {
public:
  using statsCollection_t = std::vector<Stat *>;
  using equiptmentSlotsCollection_t = std::vector<EquipmentSlot *>;

  statsCollection_t m_stats;
  equiptmentSlotsCollection_t m_equipmentSlots;

  BasicGameData::id_t m_nextStatId;
  BasicGameData::id_t m_nextEquipmentSlotId;

  void addStat(Stat *stat);
  void addEquipmentSlot(Stat *stat);
};

#endif // GAMEMETADATA_HPP_
