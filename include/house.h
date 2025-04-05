#ifndef HOUSE_H
#define HOUSE_H

#include "item.h"

class House : public Item
{
public:
	House(int house_id, int x, int y);
	virtual ~House() {}  // �������������

	//���徫����º���
	void update_sprites(int new_x, int new_y)override;

	// ��ȡռ�ݵĸ���
	std::vector<std::pair<int, int>> get_occupied_cells() const override;

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
