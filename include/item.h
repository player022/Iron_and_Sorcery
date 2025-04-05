#ifndef ITEM_H
#define ITEM_H

#include "bn_log.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_string_view.h"
#include "bn_sprite_text_generator.h"

#include "common_info.h"
#include "source_han_sans_jp_sprite_font.h"

#include "itemObserver.h"

#include <functional> // ���� std::function
#include <optional>
#include <vector>
#include <utility>

struct ItemInfo
{
	enum class Type { Tree, House, Door, Equipment };
	Type type;
	int id;
	int x;
	int y;
};

class Item
{
public:
	Item(int x, int y);
	virtual ~Item() {}  // �������������
	int x() const { return _x; }
	int y() const { return _y; }

	// ͳһ�� update_position ����
	void update_position(int x, int y);

	//��ȡ�Ƿ�ɽ�����Ϣ
	bool get_interactable() { return _interactable; }

	// ��ȡռ�ݵĸ��ӣ���������ȥʵ��
	virtual std::vector<std::pair<int, int>> get_occupied_cells() const {return {};}

	// ��ȡ��Ʒ�����ƣ��������������û��ʵ�֣�Ĭ�Ϸ��ؿ�
	virtual bn::string_view get_name() const { return ""; }

	//����ʱ�����Ķ���
	virtual void on_interact() {}

	//ע��۲���
	virtual void set_observer(ItemObserver* observer) {}

	//�������ȼ�
	virtual void update_priority(bool inside){}
protected:
	int _x, _y;
	bool _interactable;
	bn::string_view interact_message;

		// **���ඨ���ڵ���Χ**
	virtual std::optional<std::tuple<int, int, int, int>> get_occlusion_range() const { return std::nullopt; }

	// **����ҽ����ڵ���Χʱ����**
	virtual void on_occlusion(bool inside) {}

	// ������ʵ���Լ��ľ�����·�ʽ
	virtual void update_sprites(int new_x, int new_y) = 0;

};
#endif // !ITEM_H
