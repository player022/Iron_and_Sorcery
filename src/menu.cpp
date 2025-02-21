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
	menu.set_visible(!menu.visible()); // ȡ���ɼ�״̬
}

// �����ָ��λ�� (x, y) �Ƿ����㹻�ռ������Ʒ
bool Menu::check_space(int x, int y, const Item_map& item)
{
	if (x + item.width > MENU_COLS || y + item.height > MENU_ROWS)
		return false;  // �����Ʒ����������Χ������ false

	// ���ÿ�������Ƿ�Ϊ��
	for (int i = 0; i < item.width; ++i)
	{
		for (int j = 0; j < item.height; ++j)
		{
			if (bag[y + j][x + i] != 0) // ����и����ѱ�ռ�ã����� false
				return false;
		}
	}
	Item_bag item_bag(item.id(), 5, 5); // ͨ�����캯����ʼ������
	//items.push_back(item_bag);
	return true;
}

void Menu::add_item_to_bag(const Item_bag& item)
{
	//items.push_back(item);
	//BN_LOG("id:", item.id());
}
