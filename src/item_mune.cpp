#include "item_mune.h"

#include "bn_sprite_items_item_menu.h"
#include "bn_sprite_items_item_menu_cursor.h"
#include "source_han_sans_jp_sprite_font.h"

#include "bn_log.h"

Item_mune::Item_mune(const bn::vector<Item*, 32>& items) :
	menu_sprite(bn::sprite_items::item_menu.create_sprite(-25, -20)),
	cursor_sprite(bn::sprite_items::item_menu_cursor.create_sprite(-25, -37)), // 光标起始位置
	text_generator(source_han_sans_jp_sprite_font),
	items(items)  // 存储物品指针
{
	refresh_text();  // 初始显示
}

void Item_mune::refresh_text()
{
	text_sprites.clear();  // 清空旧的文本精灵

	for (int i = 0; i < max_visible_items; i++)
	{
		int item_index = start_index + i;
		if (item_index < items.size())  // 防止越界
		{
			// 获取物品的名称并显示
			text_generator.generate(-43, -37 + (i * item_spacing), items[item_index]->get_name(), text_sprites);
		}
	}
}

void Item_mune::update()
{
	if (bn::keypad::up_pressed())
	{
		if (cursor_index > 0)
		{
			cursor_index--;  // 在可见范围内移动
		}
		else if (start_index > 0)
		{
			start_index--;  // 上滚菜单
		}
	}

	if (bn::keypad::down_pressed())
	{
		if (cursor_index < max_visible_items - 1 && start_index + cursor_index + 1 < items.size())
		{
			cursor_index++;  // 在可见范围内移动
		}
		else if (start_index + max_visible_items < items.size())
		{
			start_index++;  // 下滚菜单
		}
	}

	// **按 A 键与选中物品交互**
	if (bn::keypad::a_pressed())
	{
		int selected_index = start_index + cursor_index;  // 计算全局索引
		if (selected_index < items.size())  // 确保索引有效
		{
			Item* selected_item = items[selected_index];
			if (selected_item)
			{
				selected_item->on_interact();  // 调用物品的交互逻辑
			}
		}
	}
	// 更新光标位置
	cursor_sprite.set_y(-37 + cursor_index * item_spacing);
	refresh_text(); // 重新绘制菜单
}
