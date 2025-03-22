#include "door.h"
#include "bn_sprite_items_door.h"
#include "bn_log.h"

Door::Door(int door_id, int x, int y, int columns, int rows) :
	Item(x, y,columns,rows), _id(door_id), sprite(create_sprite(door_id)),
	text_generator(source_han_sans_jp_sprite_font)
{
	sprite.set_z_order(y);
}

void Door::update_sprites(int new_x, int new_y)
{
	sprite.set_position(new_x, new_y);
}

void Door::show_prompt(bool show)
{
	if (prompt_visible == show)
	{
		return;
	}

	prompt_visible = show;
	text_sprites.clear();

	if (prompt_visible)
	{
		text_generator.generate(-10, -50, interact_message, text_sprites);
	}
}

void Door::on_interact()
{
	bool is_open = false;
	switch (_id)
	{
	case 1:
		text_sprites.clear();
		if (interact_message == "开门")
		{
			is_open = true;
			interact_message = "关门";
			sprite.set_tiles(bn::sprite_items::door.tiles_item(), 1); // 切换到第 1 帧（门打开）
		}
		else
		{
			interact_message = "开门";
			sprite.set_tiles(bn::sprite_items::door.tiles_item(), 0); // 切换到第 0 帧（门关闭）
		}
		text_generator.generate(-10, -50, interact_message, text_sprites);
		break;

	default:
		break;
	}

	// 通知观察者（如果有的话）
	if (_observer)
	{
		_observer->on_door_state_changed(64-_x, 64-_y, is_open);
	}
}

bn::sprite_ptr Door::create_sprite(int id)
{
	switch (id)
	{
	case 1:  // 开门
		interact_message = "开门";
		return bn::sprite_items::door.create_sprite(0); // 使用图块创建精灵
		break;

	default:
		interact_message = "开门";
		return bn::sprite_items::door.create_sprite(0); // 使用图块创建精灵
		break;
	}
}

// 获取占据的格子
std::vector<std::pair<int, int>> Door::get_occupied_cells() const
{
	std::vector<std::pair<int, int>> occupied;
	occupied.emplace_back(_x, _y);
	return occupied;
}