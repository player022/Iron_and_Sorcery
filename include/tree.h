#ifndef TREE_H
#define TREE_H

#include "item.h"

class Tree: public Item
{
public :
	Tree(int tree_id, int x, int y, int columns, int rows);
	virtual ~Tree() {}  // 添加虚析构函数

	//具体精灵更新函数
	void update_sprites(int new_x, int new_y)override;

	// 获取占据的格子，交给子类去实现
	std::vector<std::pair<int, int>> get_occupied_cells() const override;

	//没有提示文字，不实现
	void show_prompt(bool show) override {}

	//没有交互动作，不实现
	virtual void on_interact() override {}
private:
	int _id;
	int width, height;   //物品的长宽高
	int offset_x;   //物品精灵的偏移量
	int offset_y;
	bn::vector<bn::sprite_ptr, 2> sprites;

	bn::vector<bn::sprite_ptr, 2> create_sprite(int id);
};

#endif // !TREE_H
