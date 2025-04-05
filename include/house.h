#ifndef HOUSE_H
#define HOUSE_H

#include "item.h"

class House : public Item
{
public:
	House(int house_id, int x, int y);
	virtual ~House() {}  // 添加虚析构函数

	//具体精灵更新函数
	void update_sprites(int new_x, int new_y)override;

	// 获取占据的格子
	std::vector<std::pair<int, int>> get_occupied_cells() const override;

	//设置优先级
	void update_priority(bool inside) override {
		if (inside) {
			for (auto& sprite : sprites)
			{
				sprite.set_z_order(100 - _y);
			}
		}
		else {
			for (auto& sprite : sprites)
			{
				sprite.set_z_order(0);
			}
		}
	}
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
