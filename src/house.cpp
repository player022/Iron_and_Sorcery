#include "house.h"
#include "bn_sprite_items_wood_house.h"

#include "bn_log.h"

House::House(int house_id, int x, int y) :
	Item(x, y), _id(house_id), sprites(create_sprite(house_id))
{
}

void House::update_sprites(int new_x, int new_y)
{
	sprites[0].set_position(new_x + offset_x, new_y + offset_y);
	sprites[1].set_position(new_x + offset_x, new_y + offset_y - 64);
}

bn::vector<bn::sprite_ptr, 2> House::create_sprite(int id)
{
	bn::vector<bn::sprite_ptr, 2> sprite;

	switch (id)
	{
	case 1: // 木屋（分成两个部分）
		height = 9;
		width = 6;
		anchor_x = 2;
		anchor_y = 8;
		offset_x = 8;
		offset_y = -24;
		sprites.push_back(bn::sprite_items::wood_house.create_sprite(0)); // 下半部分
		sprites.push_back(bn::sprite_items::wood_house.create_sprite(1)); // 上半部分
		break;

	default:
		height = 9;
		width = 6;
		anchor_x = 3;
		anchor_y = 8;
		offset_x = 0;
		offset_y = -24;
		sprites.push_back(bn::sprite_items::wood_house.create_sprite(0)); // 下半部分
		sprites.push_back(bn::sprite_items::wood_house.create_sprite(1)); // 上半部分
		break;
	}

	return sprite;
}

// 获取占据的格子
std::vector<std::pair<int, int>> House::get_occupied_cells() const
{
	std::vector<std::pair<int, int>> occupied;

	for (int dx = 0; dx < width; ++dx)
	{
		for (int dy = 0; dy < height; ++dy)
		{
			occupied.emplace_back(_x - anchor_x + dx, _y - anchor_y + dy);
		}
	}
	return occupied;
}