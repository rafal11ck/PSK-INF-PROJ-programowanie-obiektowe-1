#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include "gameMetadata.h"
#include "itemBase.h"
#include "vector"
#include <memory>

class ItemContainer {

public:
  using itemId_t = int;

  class Item : public ItemBase {
    itemId_t m_id;

  public:
    Item(const ItemBase &item);
  };

private:
  //! GameMetadata that items refer to.
  const GameMetadata &m_gameMetadata;
  itemId_t m_nextItemId{};

  std::vector<Item *> m_items;

  void addItem(ItemBase &item);
};
#endif // ITEMCONTAINER_H
