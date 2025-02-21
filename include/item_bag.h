#ifndef ITEM_BAG_H
#define ITEM_BAG_H

#include "bn_sprite_ptr.h"

#include "bn_sprite_text_generator.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

class Item_bag
{
public:
	Item_bag(int id, int x, int y);
	int width, height;
	void set_visible(bool in_inventory);
	void update_position(int x, int y);

	int id() const { return _id; }


private:
	int _id;
	int _x, _y;
	bn::sprite_ptr _sprite; // 背包中的大物品

	bool _picked_up = false; // 记录物品是否已捡起

	// 根据 ID 生成背包中的大精灵
	bn::sprite_ptr create_sprite(int id, int x, int y);
};

#endif // ITEM_BAG_H
