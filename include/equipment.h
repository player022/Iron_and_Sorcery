#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "item.h"

class Equipment : public Item
{
public:
	Equipment(int Equipment_id, int x, int y);
	virtual ~Equipment() {}  // �������������

	//���徫����º���
	void update_sprites(int new_x, int new_y)override;

	// ������Ʒ����
	bn::string_view get_name() const override;

	//��������
	virtual void on_interact() override;

	//�������ȼ�
	void update_priority(bool inside) override {
		if (inside) {
			sprite.set_z_order(100 - _y);
		}
		else {
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

#endif // !EQUIPMENT_H
