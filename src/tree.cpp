#include "tree.h"
#include "bn_sprite_items_tree1.h"

Tree::Tree(int tree_id, int x, int y, int columns, int rows):
	Item(x,y,columns,rows), _id(tree_id), sprites(create_sprite(tree_id))
{
	for (auto& sprite : sprites)
	{
		sprite.set_z_order(y);
	}
}

void Tree::update_sprites(int new_x, int new_y)
{
	sprites[0].set_position(new_x + offset_x, new_y + offset_y);
	sprites[1].set_position(new_x + offset_x, new_y + offset_y-64);
}

bn::vector<bn::sprite_ptr, 2> Tree::create_sprite(int id)
{
	bn::vector<bn::sprite_ptr, 2> sprite;

	switch (id)
	{
	case 1: // 树（分成两个部分）
		height = 1;
		width = 1;
		offset_x = 5;
		offset_y = 23;
		sprites.push_back(bn::sprite_items::tree1.create_sprite(0)); // 下半部分
		sprites.push_back(bn::sprite_items::tree1.create_sprite(1)); // 上半部分
		break;

	case 2: // 树（分成两个部分）
		height = 1;
		width = 1;
		offset_x = 5;
		offset_y = 21;
		sprites.push_back(bn::sprite_items::tree1.create_sprite(2)); // 下半部分
		sprites.push_back(bn::sprite_items::tree1.create_sprite(3)); // 上半部分
		break;

	default:
		height = 1;
		width = 1;
		offset_x = 5;
		offset_y = 23;
		sprites.push_back(bn::sprite_items::tree1.create_sprite(0)); // 下半部分
		sprites.push_back(bn::sprite_items::tree1.create_sprite(1)); // 上半部分
		break;
	}

	return sprite;
}

// 获取占据的格子
std::vector<std::pair<int, int>> Tree::get_occupied_cells() const
{
	std::vector<std::pair<int, int>> occupied;
	occupied.emplace_back(_x, _y);
	return occupied;
}