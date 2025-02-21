#include "item_map.h"
#include "map.h"

#include "bn_keypad.h"
#include "bn_sprite_items_little_cutlass.h"
#include "bn_sprite_items_shrub.h"
#include "bn_sprite_items_little_berry.h"

#include "bn_log.h"

// 根据 ID 生成对应的精灵
Item_map::Item_map(int id, int x, int y)
	: _id(id), _x(x), _y(y),
    _little_sprite(create_little_sprite(id, x, y))
{
	
}

void Item_map::set_visible(bool in_inventory)
{
	_little_sprite.set_visible(!in_inventory); // 只在地图上时显示
}

bool Item_map::update_position(int x, int y)
{
	_little_sprite.set_position((_x + x) * 8,(_y + y) * 8);

	// 检查是否靠近物品
	int dist_x = abs( -_x - x);
	int dist_y = abs( -_y - y);
	if (dist_x <= 1 && dist_y <= 1) // 站在物品周围一格内
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 根据 ID 生成地图上的小精灵
bn::sprite_ptr Item_map::create_little_sprite(int id, int x, int y)
{
	switch (id)
	{
	case 1:  // 小刀
		height = 3;
		width = 2;
		can_pickup = true;  // 可拾取
		pickup_message = "军刀";
		return bn::sprite_items::little_cutlass.create_sprite(0, 0);
	case 2:  // 树丛
		height = 1;
		width = 1;
		can_pickup = false; // 不能拾取
		pickup_message = ""; // 树丛不显示提示
		return bn::sprite_items::shrub.create_sprite(0, 0);
	case 3:  // 浆果
		height = 1;
		width = 1;
		can_pickup = true;  // 可拾取
		pickup_message = "浆果";
		return bn::sprite_items::little_berry.create_sprite(0, 0);
	default:
		height = 1;
		width = 1;
		can_pickup = false;
		pickup_message = "军刀";
		return bn::sprite_items::little_cutlass.create_sprite(0, 0);
	}
}

void Item_map::show_pickup_prompt(bool show)
{
	if (!can_pickup || pickup_message.empty()) {
		return; // 不能拾取的物品或没有提示信息的物品不显示提示
	}

	if (pickup_prompt_visible == show) {
		return; // 状态没有变化，不重复执行
	}

	pickup_prompt_visible = show;
	text_sprites.clear(); // 先清除之前的提示

	if (pickup_prompt_visible) {
		static bn::sprite_text_generator text_generator(source_han_sans_jp_sprite_font);
		text_generator.generate(-10, -50, pickup_message, text_sprites);
	}
}

