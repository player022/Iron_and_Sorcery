#include "player.h"
#include "map.h"
#include "bn_sprite_items_head.h"
#include "bn_sprite_items_body.h"
#include "bn_sprite_items_foot.h"
#include "bn_sprite_items_head1.h"
#include "bn_sprite_items_body1.h"
#include "bn_sprite_items_foot1.h"

Player::Player(int initial_x, int initial_y) :
	_x(initial_x), _y(initial_y),
	body_sprite(bn::sprite_items::body.create_sprite(initial_x, initial_y)),
	foot_sprite(bn::sprite_items::foot.create_sprite(initial_x, initial_y)),
	head_sprite(bn::sprite_items::head.create_sprite(initial_x, initial_y))
{
}

void Player::start_jump()
{
	_jumping = true;
	_jump_timer = 0;
}

void Player::update_jump_effect()
{
	if (_jumping)
	{
		if (_jump_timer < 2)  // 上升阶段
		{
			_y -= bn::fixed(1);
		}
		else if (_jump_timer < 4)  // 下降阶段
		{
			_y += bn::fixed(1);
		}

		_jump_timer++;

		if (_jump_timer >= 4)  // 结束跳跃
		{
			_jumping = false;
			_jump_timer = 0;
		}

		head_sprite.set_position(_x, _y);
		body_sprite.set_position(_x, _y);
		foot_sprite.set_position(_x, _y);
	}
}

void Player::horizontal_flip(bool direction)
{
	head_sprite.set_horizontal_flip(direction);
	body_sprite.set_horizontal_flip(direction);
	foot_sprite.set_horizontal_flip(direction);
}

void Player::change_equipment(int equipment_id)
{
	// 根据装备 ID 切换装备
	switch (equipment_id)
	{
	case 0: // 装备 ID 0，玩家的默认装备
		head_sprite.set_item(bn::sprite_items::head);
		body_sprite.set_item(bn::sprite_items::body);
		foot_sprite.set_item(bn::sprite_items::foot);
		break;

	case 1: // 装备 ID 1，替换为另一种装备
		head_sprite.set_item(bn::sprite_items::head1);
		body_sprite.set_item(bn::sprite_items::body1);
		foot_sprite.set_item(bn::sprite_items::foot1);
		break;

		// 添加更多的装备 ID 根据需要
	default:
		// 如果提供的 ID 无效，则使用默认装备
		head_sprite.set_item(bn::sprite_items::head);
		body_sprite.set_item(bn::sprite_items::body);
		foot_sprite.set_item(bn::sprite_items::foot);
		break;
	}

	// 更新精灵位置
	head_sprite.set_position(_x, _y);
	body_sprite.set_position(_x, _y);
	foot_sprite.set_position(_x, _y);
}