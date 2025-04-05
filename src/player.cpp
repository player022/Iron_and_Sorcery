#include "player.h"
#include "map.h"
#include "bn_sprite_items_head.h"
#include "bn_sprite_items_body.h"
#include "bn_sprite_items_foot.h"
#include "bn_sprite_items_head1.h"
#include "bn_sprite_items_body1.h"
#include "bn_sprite_items_foot1.h"

#include "bn_sprite_items_little_cutlass.h"
#include "bn_string.h"

Player::Player(int initial_x, int initial_y) :
	_x(initial_x), _y(initial_y),
	body_sprite(bn::sprite_items::body.create_sprite(initial_x, initial_y)),
	foot_sprite(bn::sprite_items::foot.create_sprite(initial_x, initial_y)),
	head_sprite(bn::sprite_items::head.create_sprite(initial_x, initial_y)),
	text_generator(source_han_sans_jp_sprite_font) // ��ʼ���ı�������
{
	update_hp_text(); // ��ʼ������ֵ�ı�
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
		if (_jump_timer < 2)  // �����׶�
		{
			_y -= bn::fixed(1);
		}
		else if (_jump_timer < 4)  // �½��׶�
		{
			_y += bn::fixed(1);
		}

		_jump_timer++;

		if (_jump_timer >= 4)  // ������Ծ
		{
			_jumping = false;
			_jump_timer = 0;
		}

		head_sprite.set_position(_x, _y);
		body_sprite.set_position(_x, _y);
		foot_sprite.set_position(_x, _y);
		if (left_weapon_sprite)
		{
			left_weapon_sprite->set_position(_x + 2, _y - 2);
		}
	}
}

void Player::horizontal_flip(bool direction)
{
	head_sprite.set_horizontal_flip(direction);
	body_sprite.set_horizontal_flip(direction);
	foot_sprite.set_horizontal_flip(direction);

	if (left_weapon_sprite)
	{
		left_weapon_sprite->set_horizontal_flip(direction);
		if (direction)
		{
			left_weapon_sprite->set_position(_x - 2, _y - 2); // �������
		}
		else
		{
			left_weapon_sprite->set_position(_x + 2, _y - 2); // �������
		}
	}
}

//�������ȶ�
void Player::update_priority(int y)
{
	foot_sprite.set_z_order(100-y);
	body_sprite.set_z_order(100-y);
	head_sprite.set_z_order(100-y);
}

void Player::change_equipment(int equipment_id)
{
	// ����װ�� ID �л�װ��
	switch (equipment_id)
	{
	case 0: // װ�� ID 0����ҵ�Ĭ��װ��
		head_sprite.set_item(bn::sprite_items::head);
		body_sprite.set_item(bn::sprite_items::body);
		foot_sprite.set_item(bn::sprite_items::foot);
		break;

	case 1: // װ�� ID 1���滻Ϊ��һ��װ��
		head_sprite.set_item(bn::sprite_items::head1);
		body_sprite.set_item(bn::sprite_items::body1);
		foot_sprite.set_item(bn::sprite_items::foot1);
		left_weapon_sprite = bn::sprite_items::little_cutlass.create_sprite(_x + 2, _y - 2);
		break;

		// ��Ӹ����װ�� ID ������Ҫ
	default:
		// ����ṩ�� ID ��Ч����ʹ��Ĭ��װ��
		head_sprite.set_item(bn::sprite_items::head);
		body_sprite.set_item(bn::sprite_items::body);
		foot_sprite.set_item(bn::sprite_items::foot);
		break;
	}

	// ���¾���λ��
	head_sprite.set_position(_x, _y);
	body_sprite.set_position(_x, _y);
	foot_sprite.set_position(_x, _y);
}

void Player::update_hp_text()
{
	text_sprites.clear(); // ������ı�
	bn::string<16> hp_text = "HP: " + bn::to_string<8>(_hp);
	text_generator.generate(-100, -60, hp_text, text_sprites);
}


void Player::take_damage(int damage) // �ܵ��˺�
{
	_hp -= damage;
	if (_hp < 0)
	{
		_hp = 0;  // ��ֹ����ֵ��ɸ���
	}
	update_hp_text(); // ���˺������ʾ
}

void Player::heal(int amount) // �ָ�����ֵ
{
	_hp += amount;
	if (_hp > 100)
	{
		_hp = 100;  // ����ֵ���ᳬ�� 100
	}
	update_hp_text(); // �ָ��������ʾ
}