#ifndef PLAYER_H
#define PLAYER_H

#include "bn_sprite_ptr.h"

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

	// ����װ�� ID �л�װ��
	void change_equipment(int equipment_id);

private:
	bn::sprite_ptr body_sprite;
	bn::sprite_ptr foot_sprite;
	bn::sprite_ptr head_sprite;

	bn::fixed _x;
	bn::fixed _y;
	bool _jumping = false;
	int _jump_timer = 0; // ������Ծ�����ļ�ʱ��
};

#endif // PLAYER_H
