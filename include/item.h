#ifndef ITEM_H
#define ITEM_H

#include "bn_log.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_string_view.h"
#include "bn_sprite_text_generator.h"

#include "common_info.h"
#include "source_han_sans_jp_sprite_font.h"

#include <functional> // ���� std::function
#include <optional>
#include <vector>
#include <utility>

class Item
{
public:
	Item(int x, int y, int columns, int rows);
	virtual ~Item() {}  // �������������
	int x() const { return _x; }
	int y() const { return _y; }

	// ͳһ�� update_position ����
	bool update_position(int x, int y);

	// ������ʵ���Լ��ľ�����·�ʽ
	virtual void update_sprites(int new_x, int new_y) = 0;

	// ��ȡռ�ݵĸ��ӣ���������ȥʵ��
	virtual std::vector<std::pair<int, int>> get_occupied_cells() const = 0;

	//��ʾ��ʾ����
	virtual void show_prompt(bool show) = 0;

	//����ʱ�����Ķ���
	virtual void on_interact() = 0;

protected:
	int _x, _y;
	bn::string_view interact_message;
	//bn::vector<bn::sprite_ptr, 128> text_sprites;
};
#endif // !ITEM_H
