#ifndef ITEM_H
#define ITEM_H

#include "bn_log.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_string_view.h"
#include "bn_sprite_text_generator.h"

#include "common_info.h"
#include "source_han_sans_jp_sprite_font.h"

#include <functional> // 包含 std::function
#include <optional>
#include <vector>
#include <utility>

class Item
{
public:
	Item(int x, int y, int columns, int rows);
	virtual ~Item() {}  // 添加虚析构函数
	int x() const { return _x; }
	int y() const { return _y; }

	// 统一的 update_position 方法
	bool update_position(int x, int y);

	// 让子类实现自己的精灵更新方式
	virtual void update_sprites(int new_x, int new_y) = 0;

	// 获取占据的格子，交给子类去实现
	virtual std::vector<std::pair<int, int>> get_occupied_cells() const = 0;

	//显示提示文字
	virtual void show_prompt(bool show) = 0;

	//交互时发生的动作
	virtual void on_interact() = 0;

protected:
	int _x, _y;
	bn::string_view interact_message;
	//bn::vector<bn::sprite_ptr, 128> text_sprites;
};
#endif // !ITEM_H
