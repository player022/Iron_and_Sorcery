#ifndef HOUSE_H
#define HOUSE_H

#include "item.h"

class House : public Item
{
public:
	House(int house_id, int x, int y, int columns, int rows);
	virtual ~House() {}  // 添加虚析构函数

	//具体精灵更新函数
	void update_sprites(int new_x, int new_y)override;

	// 获取占据的格子
	std::vector<std::pair<int, int>> get_occupied_cells() const override;

	//没有提示文字，不实现
	void show_prompt(bool show) override {}

	//没有交互动作，不实现
	virtual void on_interact() override {}
private:
	int _id;
	int width, height;   //物品的长宽高
	int anchor_x;   // 相对于物品左上角的偏移量
	int anchor_y;   // 相对于物品左上角的偏移量
	int offset_x;   //物品精灵的偏移量
	int offset_y;
	bn::vector<bn::sprite_ptr, 2> sprites;

	bn::vector<bn::sprite_ptr, 2> create_sprite(int id);
};

#endif // !HOUSE_H
