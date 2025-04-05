#ifndef TREE_H
#define TREE_H

#include "item.h"

class Tree: public Item
{
public :
	Tree(int tree_id, int x, int y);
	virtual ~Tree() {}  // �������������

	//���徫����º���
	void update_sprites(int new_x, int new_y)override;

	// **���ඨ���Լ����ڵ���Χ**
	std::optional<std::tuple<int, int, int, int>> get_occlusion_range() const override {
		// ����ʼ���б��װ��һ�� tuple �У�Ȼ�󷵻� optional
		return std::optional<std::tuple<int, int, int, int>>{std::make_tuple(-3, 3, -8, -2)};
	}

	// **����ҽ����ڵ���Χʱ����,��ʵ��**
	void on_occlusion(bool inside) override {
		if (!sprites.empty()) {
			sprites[1].set_visible(!inside);
		}
	};

	//�������ȼ�
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

	// ��ȡռ�ݵĸ��ӣ���������ȥʵ��
	std::vector<std::pair<int, int>> get_occupied_cells() const override;
private:
	int _id;
	int width, height;   //��Ʒ�ĳ����
	int offset_x;   //��Ʒ�����ƫ����
	int offset_y;
	bn::vector<bn::sprite_ptr, 2> sprites;

	bn::vector<bn::sprite_ptr, 2> create_sprite(int id);
};

#endif // !TREE_H
