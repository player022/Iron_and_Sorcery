#include "equipment.h"
#include "bn_sprite_items_little_cutlass.h"
#include "bn_log.h"

Equipment::Equipment(int equipment_id, int x, int y) :
	Item(x, y), _id(equipment_id), sprite(create_sprite(equipment_id))
{
}

void Equipment::update_sprites(int new_x, int new_y)
{
	sprite.set_position(new_x, new_y);
}

bn::string_view Equipment::get_name() const {
	switch (_id)
	{
	case 1:  // 开门
		return "军刀"; // 使用图块创建精灵
		break;

	default:
		return "军刀"; // 使用图块创建精灵
		break;
	}
}

void Equipment::on_interact()
{
	// 通知观察者（如果有的话）
	if (_observer)
	{
		_observer->on_item_picked_up(*this);
	}
}

bn::sprite_ptr Equipment::create_sprite(int id)
{
	switch (id)
	{
	case 1:  // 开门
		return bn::sprite_items::little_cutlass.create_sprite(0); // 使用图块创建精灵
		break;

	default:
		return bn::sprite_items::little_cutlass.create_sprite(0); // 使用图块创建精灵
		break;
	}
}