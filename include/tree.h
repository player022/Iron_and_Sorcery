#ifndef TREE_H
#define TREE_H

#include "item.h"

class Tree: public Item
{
public :
	Tree(int tree_id, int x, int y);
	virtual ~Tree() {}  // 添加虚析构函数

	//具体精灵更新函数
	void update_sprites(int new_x, int new_y)override;

	// **子类定义自己的遮挡范围**
	std::optional<std::tuple<int, int, int, int>> get_occlusion_range() const override {
		// 将初始化列表包装到一个 tuple 中，然后返回 optional
		return std::optional<std::tuple<int, int, int, int>>{std::make_tuple(-3, 3, -8, -2)};
	}

	// **当玩家进入遮挡范围时触发,树实现**
	void on_occlusion(bool inside) override {
		if (!sprites.empty()) {
			sprites[1].set_visible(!inside);
		}
	};

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

	// 获取占据的格子，交给子类去实现
	std::vector<std::pair<int, int>> get_occupied_cells() const override;
private:
	int _id;
	int width, height;   //物品的长宽高
	int offset_x;   //物品精灵的偏移量
	int offset_y;
	bn::vector<bn::sprite_ptr, 2> sprites;

	bn::vector<bn::sprite_ptr, 2> create_sprite(int id);
};

#endif // !TREE_H
