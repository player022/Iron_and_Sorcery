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

	// 触发跳跃动画
	void start_jump();

	// 更新跳跃效果
	void update_jump_effect();

	// 是否可以移动
	bool can_move() const { return !_jumping; }

	// 翻转
	void horizontal_flip(bool direction);

	//更新优先度
	void update_priority(int y);

	// 根据装备 ID 切换装备
	void change_equipment(int equipment_id);

	int get_hp() const { return _hp; }  // 获取当前生命值

	void take_damage(int damage); // 受到伤害

	void heal(int amount); // 恢复生命值

private:
	bn::sprite_ptr body_sprite;
	bn::sprite_ptr foot_sprite;
	bn::sprite_ptr head_sprite;

	bn::optional<bn::sprite_ptr> left_weapon_sprite;
	bn::optional<bn::sprite_ptr> right_weapon_sprite;

	int _hp = 100;

	bn::vector<bn::sprite_ptr, 128>text_sprites;
	bn::sprite_text_generator text_generator;
	void update_hp_text(); // 生命值更新方法

	bn::fixed _x;
	bn::fixed _y;
	bool _jumping = false;
	int _jump_timer = 0; // 控制跳跃动画的计时器
};

#endif // PLAYER_H