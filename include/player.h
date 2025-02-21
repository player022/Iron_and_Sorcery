#ifndef PLAYER_H
#define PLAYER_H

#include "bn_sprite_ptr.h"

class Player
{
public:
	Player(int initial_x, int initial_y);

	bn::fixed get_x() const { return _x; }
	bn::fixed get_y() const { return _y; }

	// 触发跳跃动画
	void start_jump();

	// 更新跳跃效果
	void update_jump_effect();

	// 是否可以移动
	bool can_move() const { return !_jumping; }

	// 翻转
	void horizontal_flip(bool direction);

	// 根据装备 ID 切换装备
	void change_equipment(int equipment_id);

private:
	bn::sprite_ptr body_sprite;
	bn::sprite_ptr foot_sprite;
	bn::sprite_ptr head_sprite;

	bn::fixed _x;
	bn::fixed _y;
	bool _jumping = false;
	int _jump_timer = 0; // 控制跳跃动画的计时器
};

#endif // PLAYER_H
