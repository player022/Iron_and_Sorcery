#ifndef HUMAN_H
#define HUMAN_H

#include "bn_sprite_ptr.h"

class Human
{
public:
	Human(int initial_x, int initial_y);

	void update_position(int x, int y);

	// ������Ծ����
	void start_jump();

	// ������ԾЧ��
	void update_jump_effect();


private:
	bn::sprite_ptr body_sprite;
	bn::sprite_ptr foot_sprite;
	bn::sprite_ptr head_sprite;

	bn::fixed _x;
	bn::fixed _y;

	bool _jumping = false;
	int _jump_timer = 0; // ������Ծ�����ļ�ʱ��
};

#endif // !HUMAN_H
