#ifndef MAP_DATA_H
#define MAP_DATA_H

#include "item.h"

#include <cstdint>

struct ItemList {
	std::array<ItemInfo, 64> items;
	uint8_t item_count; // 记录有效物品数量
};

extern const uint8_t map_data[256][256];

extern const ItemList item_data[4][4];
#endif
