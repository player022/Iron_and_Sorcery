#ifndef TREE_H
#define TREE_H

#include "item.h"

class Tree: public Item
{
public :
	Tree(int tree_id, int x, int y, int columns, int rows);
	virtual ~Tree() {}  // �������������

	//���徫����º���
	void update_sprites(int new_x, int new_y)override;

	// ��ȡռ�ݵĸ��ӣ���������ȥʵ��
	std::vector<std::pair<int, int>> get_occupied_cells() const override;

	//û����ʾ���֣���ʵ��
	void show_prompt(bool show) override {}

	//û�н�����������ʵ��
	virtual void on_interact() override {}
private:
	int _id;
	int width, height;   //��Ʒ�ĳ����
	int offset_x;   //��Ʒ�����ƫ����
	int offset_y;
	bn::vector<bn::sprite_ptr, 2> sprites;

	bn::vector<bn::sprite_ptr, 2> create_sprite(int id);
};

#endif // !TREE_H
