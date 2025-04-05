#ifndef DOOR_H
#define DOOR_H

#include "item.h"

class Door : public Item
{
public:
	Door(int door_id, int x, int y);
	virtual ~Door() {}  // �������������

	//���徫����º���
	void update_sprites(int new_x, int new_y)override;

	// ��ȡռ�ݵĸ���
	std::vector<std::pair<int, int>> get_occupied_cells() const override;

	// ������Ʒ����
	bn::string_view get_name() const override;

	//��������
	void on_interact() override;

	//�������ȼ�
	void update_priority(bool inside) override { 
		if (inside) {
			sprite.set_z_order(100 - _y);
		}else{
			sprite.set_z_order(0);
		}
	}

	// ���ù۲���
	void set_observer(ItemObserver* observer)override { _observer = observer; }
private:
	int _id;
	bn::sprite_ptr sprite;

	ItemObserver* _observer = nullptr;  // �۲���ָ�루��ӵ�У�

	bn::sprite_ptr create_sprite(int id);
};

#endif // !DOOR_H
