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
	bool can_pickup; // �Ƿ��ʰȡ
	bn::string_view pickup_message; // ʰȡ��ʾ��Ϣ


	Item_map(int id, int x, int y);

	void set_visible(bool in_inventory);
	bool update_position(int x, int y); //����λ��
	void show_pickup_prompt(bool show); // ��ʾʰȡ��ʾ

	int id() const { return _id; }

private:
	int _id;
	int _x, _y;
	bn::sprite_ptr _little_sprite; // ��ͼ�ϵ�С��Ʒ

	bn::vector<bn::sprite_ptr, 128>text_sprites;

	bn::optional<common::info> pickup_info; // ����ʾ��������������ڳ�������
	bool pickup_prompt_visible = false;

	//std::function<void(Item_map&)> on_pickup;  // �ص�����������Ʒ������ʱ����

	// ���� ID ���ɵ�ͼ�ϵ�С����
	bn::sprite_ptr create_little_sprite(int id, int x, int y);

};

#endif // ITEM_MAP_H
