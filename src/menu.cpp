#include "menu.h"

#include "bn_regular_bg_items_menu.h"

#include "bn_log.h"

Menu::Menu() :
	menu(bn::regular_bg_items::menu.create_bg(0, 0))
{
	menu.set_priority(1);
    menu.set_visible(false);
}

void Menu::toggle_visibility()
{
	menu.set_visible(!menu.visible()); // 取反可见状态
}

// 检查在指定位置 (x, y) 是否有足够空间放置物品
bool Menu::check_space(int x, int y, const Item_map& item)
{
	if (x + item.width > MENU_COLS || y + item.height > MENU_ROWS)
		return false;  // 如果物品超出背包范围，返回 false

	// 检查每个格子是否为空
	for (int i = 0; i < item.width; ++i)
	{
		for (int j = 0; j < item.height; ++j)
		{
			if (bag[y + j][x + i] != 0) // 如果有格子已被占用，返回 false
				return false;
		}
	}
	Item_bag item_bag(item.id(), 5, 5); // 通过构造函数初始化对象
	//items.push_back(item_bag);
	return true;
}

void Menu::add_item_to_bag(const Item_bag& item)
{
	//items.push_back(item);
	//BN_LOG("id:", item.id());
}
