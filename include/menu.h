#ifndef MENU_H
#define MENU_H

#define MENU_ROWS 6
#define MENU_COLS 10

#include "bn_core.h"
#include "bn_regular_bg_ptr.h"

#include "item_map.h"
#include "item_bag.h"
#include <vector>  

class Menu
{
public:
	Menu();
	void toggle_visibility(); // 添加切换可见性的函数
	//void pickup_item(Item_map& item)
	//{
	//}
	bool check_space(int x, int y, const Item_map& item); //判断背包能否放的下物品
	//void place_item(int x, int y, const Item& item); //放置物品
	//void remove_item(int x, int y, const Item& item); //移动物品
	//bool add_item_to_inventory(const Item& item); // 添加物品到背包（实际背包管理）

	void add_item_to_bag(const Item_bag& item);

private:
	int bag[MENU_ROWS][MENU_COLS] = { 0 }; // 0 表示空格
	bn::regular_bg_ptr menu;
	//Item_bag item_bag(1, 5, 5);
	std::vector<Item_bag> items;

};

#endif // !MENU_H
