#ifndef HUMAN_H
#define HUMAN_H

#include "bn_sprite_ptr.h"

class Human
{
public:
	Human(int initial_x, int initial_y);

	void update_position(int x, int y);

	// 触发跳跃动画
	void start_jump();

	// 更新跳跃效果
	void update_jump_effect();


private:
	bn::sprite_ptr body_sprite;
	bn::sprite_ptr foot_sprite;
	bn::sprite_ptr head_sprite;

	bn::fixed _x;
	bn::fixed _y;

	bool _jumping = false;
	int _jump_timer = 0; // 控制跳跃动画的计时器
};

#endif // !HUMAN_H
