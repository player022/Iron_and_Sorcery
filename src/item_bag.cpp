#include "item_bag.h"

#include "bn_keypad.h"
#include "bn_sprite_items_cutlass.h"

// 根据 ID 生成对应的精灵
Item_bag::Item_bag(int id, int x, int y) : _id(id), _x(x), _y(y),
_sprite(create_sprite(id, x, y))
{
	//_sprite.set_visible(false); // 默认隐藏背包中的精灵
}

void Item_bag::set_visible(bool in_inventory)
{
	_sprite.set_visible(in_inventory); // 只在背包界面显示
}

void Item_bag::update_position(int x, int y)
{
	//_sprite.set_position(sprite_x(_x) + (x - bg_map::columns / 2) * 8, sprite_x(_y) + (y - bg_map::columns / 2) * 8);
}

// 根据 ID 生成背包中的大精灵
bn::sprite_ptr Item_bag::create_sprite(int id, int x, int y)
{
	switch (id)
	{
	case 1:
		width = 2;
		height = 3;
		return bn::sprite_items::cutlass.create_sprite(x, y);
		//case 2: return bn::sprite_items::potion.create_sprite(x, y);
		//default: return bn::sprite_items::unknown.create_sprite(x, y);
	default:
		return bn::sprite_items::cutlass.create_sprite(x, y);
	}
}