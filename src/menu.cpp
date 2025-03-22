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

void Menu::add_item_to_bag(const Item_bag& item)
{
	//items.push_back(item);
	//BN_LOG("id:", item.id());
}
