#include "human.h"

#include "bn_sprite_items_head1.h"
#include "bn_sprite_items_body1.h"
#include "bn_sprite_items_foot1.h"

Human::Human(int initial_x, int initial_y) :
	_x(initial_x), _y(initial_y),
	body_sprite(bn::sprite_items::body1.create_sprite(initial_x, initial_y)),
	foot_sprite(bn::sprite_items::foot1.create_sprite(initial_x, initial_y)),
	head_sprite(bn::sprite_items::head1.create_sprite(initial_x, initial_y))
{
}

void Human::update_position(int x, int y)
{
	body_sprite.set_position((_x + x) * 8 + 4, (_y + y) * 8 - 2);
	foot_sprite.set_position((_x + x) * 8 + 4, (_y + y) * 8 - 2);
	head_sprite.set_position((_x + x) * 8 + 4, (_y + y) * 8 - 2);
}

void Human::start_jump()
{
	_jumping = true;
	_jump_timer = 0;
}

void Human::update_jump_effect()
{
	if (_jumping)
	{
		if (_jump_timer < 2)  // …œ…˝Ω◊∂Œ
		{
			_y -= bn::fixed(1);
		}
		else if (_jump_timer < 4)  // œ¬ΩµΩ◊∂Œ
		{
			_y += bn::fixed(1);
		}

		_jump_timer++;

		if (_jump_timer >= 4)  // Ω· ¯Ã¯‘æ
		{
			_jumping = false;
			_jump_timer = 0;
		}

		head_sprite.set_position(_x, _y);
		body_sprite.set_position(_x, _y);
		foot_sprite.set_position(_x, _y);
	}
}