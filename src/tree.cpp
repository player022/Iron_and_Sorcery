#include "tree.h"
#include "bn_sprite_items_tree1.h"

Tree::Tree(int tree_id, int x, int y):
	Item(x,y), _id(tree_id), sprites(create_sprite(tree_id))
{
	BN_LOG("tree init");
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
	case 1: // �����ֳ��������֣�
		height = 1;
		width = 1;
		offset_x = 5;
		offset_y = 23;
		sprites.push_back(bn::sprite_items::tree1.create_sprite(0)); // �°벿��
		sprites.push_back(bn::sprite_items::tree1.create_sprite(1)); // �ϰ벿��
		break;

	case 2: // �����ֳ��������֣�
		height = 1;
		width = 1;
		offset_x = 5;
		offset_y = 21;
		sprites.push_back(bn::sprite_items::tree1.create_sprite(2)); // �°벿��
		sprites.push_back(bn::sprite_items::tree1.create_sprite(3)); // �ϰ벿��
		break;

	case 3:
		height = 1;
		width = 1;
		offset_x = 5;
		offset_y = 21;
		sprites.push_back(bn::sprite_items::tree1.create_sprite(4)); // �°벿��
		sprites.push_back(bn::sprite_items::tree1.create_sprite(5)); // �ϰ벿��
		break;

	default:
		height = 1;
		width = 1;
		offset_x = 5;
		offset_y = 23;
		sprites.push_back(bn::sprite_items::tree1.create_sprite(0)); // �°벿��
		sprites.push_back(bn::sprite_items::tree1.create_sprite(1)); // �ϰ벿��
		break;
	}

	return sprite;
}

// ��ȡռ�ݵĸ���
std::vector<std::pair<int, int>> Tree::get_occupied_cells() const
{
	std::vector<std::pair<int, int>> occupied;
	occupied.emplace_back(_x, _y);
	return occupied;
}