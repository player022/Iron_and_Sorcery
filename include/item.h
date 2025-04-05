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

#include <functional> // 包含 std::function
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
	virtual ~Item() {}  // 添加虚析构函数
	int x() const { return _x; }
	int y() const { return _y; }

	// 统一的 update_position 方法
	void update_position(int x, int y);

	//获取是否可交互信息
	bool get_interactable() { return _interactable; }

	// 获取占据的格子，交给子类去实现
	virtual std::vector<std::pair<int, int>> get_occupied_cells() const {return {};}

	// 获取物品的名称（或描述），如果没有实现，默认返回空
	virtual bn::string_view get_name() const { return ""; }

	//交互时发生的动作
	virtual void on_interact() {}

	//注册观察者
	virtual void set_observer(ItemObserver* observer) {}

	//设置优先级
	virtual void update_priority(bool inside){}
protected:
	int _x, _y;
	bool _interactable;
	bn::string_view interact_message;

		// **子类定义遮挡范围**
	virtual std::optional<std::tuple<int, int, int, int>> get_occlusion_range() const { return std::nullopt; }

	// **当玩家进入遮挡范围时触发**
	virtual void on_occlusion(bool inside) {}

	// 让子类实现自己的精灵更新方式
	virtual void update_sprites(int new_x, int new_y) = 0;

};
#endif // !ITEM_H
