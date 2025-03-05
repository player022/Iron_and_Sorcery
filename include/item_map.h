#ifndef ITEM_MAP_H
#define ITEM_MAP_H

#include "bn_sprite_ptr.h"
#include "bn_string_view.h"
#include "bn_sprite_text_generator.h"

#include "common_info.h"
#include "source_han_sans_jp_sprite_font.h"
#include <functional>

class Item_map
{
public:
	int width, height;
	bool can_pickup; // 是否可拾取
	bn::string_view pickup_message; // 拾取提示消息


	Item_map(int id, int x, int y);

	void set_visible(bool in_inventory);
	bool update_position(int x, int y); //更新位置
	void show_pickup_prompt(bool show); // 显示拾取提示

	int id() const { return _id; }

private:
	int _id;
	int _x, _y;
	bn::sprite_ptr _little_sprite; // 地图上的小物品

	bn::vector<bn::sprite_ptr, 128>text_sprites;

	bn::optional<common::info> pickup_info; // 让提示在类的生命周期内持续存在
	bool pickup_prompt_visible = false;

	//std::function<void(Item_map&)> on_pickup;  // 回调函数，当物品被捡起时触发

	// 根据 ID 生成地图上的小精灵
	bn::sprite_ptr create_little_sprite(int id);

};

#endif // ITEM_MAP_H
