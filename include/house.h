#ifndef HOUSE_H
#define HOUSE_H

#include "item.h"

class House : public Item
{
public:
	House(int house_id, int x, int y, int columns, int rows);
	virtual ~House() {}  // �������������

	//���徫����º���
	void update_sprites(int new_x, int new_y)override;

	// ��ȡռ�ݵĸ���
	std::vector<std::pair<int, int>> get_occupied_cells() const override;

	//û����ʾ���֣���ʵ��
	void show_prompt(bool show) override {}

	//û�н�����������ʵ��
	virtual void on_interact() override {}
private:
	int _id;
	int width, height;   //��Ʒ�ĳ����
	int anchor_x;   // �������Ʒ���Ͻǵ�ƫ����
	int anchor_y;   // �������Ʒ���Ͻǵ�ƫ����
	int offset_x;   //��Ʒ�����ƫ����
	int offset_y;
	bn::vector<bn::sprite_ptr, 2> sprites;

	bn::vector<bn::sprite_ptr, 2> create_sprite(int id);
};

#endif // !HOUSE_H
