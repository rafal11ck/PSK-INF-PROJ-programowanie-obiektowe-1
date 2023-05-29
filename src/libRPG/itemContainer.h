#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

// #include "gameMetadata.h"
// #include "itemBase.h"
// #include "vector"
// #include <memory>
// #include <sys/types.h>

// /**
//  *@brief Item container, holds items that exist in game.
//  *
//  *@note This is not to be used as inventory.
//  **/
// class ItemContainer {

// public:
//   //! Type used for id.
//   using itemId_t = int;

// private:
//   /**
//    *@brief Item repesentation.
//    **/
//   class Item : public ItemBase {
//     //! Should be locally unique id within ItemContainer.
//     itemId_t m_id;

//   public:
//     Item(const ItemBase &item, ItemContainer::itemId_t id);
//   };

// public:
//   ItemContainer(const GameStats &gameMetadata);

// protected:
//   //! GameMetadata that items refer to.
//   const GameStats &m_gameMetadata;
//   //! Value of Item::m_id that will be given to next added item.
//   itemId_t m_nextItemId{};
//   //! Colletion holding items.
//   std::vector<Item *> m_items;
//
//   void addItem(const ItemBase &item);
// };
#endif // ITEMCONTAINER_H
