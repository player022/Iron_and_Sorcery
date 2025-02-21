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
	void toggle_visibility(); // ����л��ɼ��Եĺ���
	//void pickup_item(Item_map& item)
	//{
	//}
	bool check_space(int x, int y, const Item_map& item); //�жϱ����ܷ�ŵ�����Ʒ
	//void place_item(int x, int y, const Item& item); //������Ʒ
	//void remove_item(int x, int y, const Item& item); //�ƶ���Ʒ
	//bool add_item_to_inventory(const Item& item); // �����Ʒ��������ʵ�ʱ�������

	void add_item_to_bag(const Item_bag& item);

private:
	int bag[MENU_ROWS][MENU_COLS] = { 0 }; // 0 ��ʾ�ո�
	bn::regular_bg_ptr menu;
	//Item_bag item_bag(1, 5, 5);
	std::vector<Item_bag> items;

};

#endif // !MENU_H
