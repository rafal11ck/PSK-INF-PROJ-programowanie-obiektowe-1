#include "basicGameMetadata.h"
#include "equipmentSlots.h"
#include "gameStats.h"

std::ostream &BasicGameMetadata::print(std::ostream &os) const {
  os << "BasicGameMetadata {\n";
  GameStats::print(os);
  EquipmentSlots::print(os);
  os << "}";
  return os;
};

/**
 *@brief extraction operator overload.
 *@param os Output stream.
 *@param data Data to extract.
 * */
std::ostream &operator<<(std::ostream &os, BasicGameMetadata &data) {
  return data.print(os);
}
