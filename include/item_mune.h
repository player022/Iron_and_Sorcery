#ifndef ITEM_MUNE_H
#define ITEM_MUNE_H

#include "bn_string.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_keypad.h"

#include "item.h"

#include <vector>

class Item_mune
{
public:
	Item_mune(const bn::vector<Item*, 32>& items);

	void update();  // 处理菜单逻辑

private:
	void refresh_text();  // 刷新当前显示的菜单项

	bn::sprite_ptr menu_sprite;
	bn::sprite_ptr cursor_sprite;
	bn::sprite_text_generator text_generator;
	bn::vector<bn::sprite_ptr, 32> text_sprites;  // 存储多个文本精灵
	bn::vector<Item*, 32> items;   // 存储物品指针

	int start_index = 0;  // 当前显示的第一项索引
	int cursor_index = 0; // 当前光标在 0~3 之间移动
	static constexpr int max_visible_items = 4;  // 最多显示的菜单项数量
	static constexpr int item_spacing = 12; // 每个菜单项的间距
};

#endif // ITEM_MUNE_H
