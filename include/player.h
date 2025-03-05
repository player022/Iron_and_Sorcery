#ifndef PLAYER_H
#define PLAYER_H

#include "bn_sprite_ptr.h"

#include "common_info.h"
#include "source_han_sans_jp_sprite_font.h"

#include "bn_sprite_text_generator.h"

class Player
{
public:
	Player(int initial_x, int initial_y);

	bn::fixed get_x() const { return _x; }
	bn::fixed get_y() const { return _y; }

	// ������Ծ����
	void start_jump();

	// ������ԾЧ��
	void update_jump_effect();

	// �Ƿ�����ƶ�
	bool can_move() const { return !_jumping; }

	// ��ת
	void horizontal_flip(bool direction);

	//�������ȶ�
	void update_priority(int y);

	// ����װ�� ID �л�װ��
	void change_equipment(int equipment_id);

	int get_hp() const { return _hp; }  // ��ȡ��ǰ����ֵ

	void take_damage(int damage); // �ܵ��˺�

	void heal(int amount); // �ָ�����ֵ

private:
	bn::sprite_ptr body_sprite;
	bn::sprite_ptr foot_sprite;
	bn::sprite_ptr head_sprite;

	bn::optional<bn::sprite_ptr> left_weapon_sprite;
	bn::optional<bn::sprite_ptr> right_weapon_sprite;

	int _hp = 100;

	bn::vector<bn::sprite_ptr, 128>text_sprites;
	bn::sprite_text_generator text_generator;
	void update_hp_text(); // ����ֵ���·���

	bn::fixed _x;
	bn::fixed _y;
	bool _jumping = false;
	int _jump_timer = 0; // ������Ծ�����ļ�ʱ��
};

#endif // PLAYER_H