#ifndef DOOR_H
#define DOOR_H

#include "item.h"
#include "doorObserver.h"

class Door : public Item
{
public:
	Door(int door_id, int x, int y, int columns, int rows);
	virtual ~Door() {}  // �������������

	//���徫����º���
	void update_sprites(int new_x, int new_y)override;

	// ��ȡռ�ݵĸ���
	std::vector<std::pair<int, int>> get_occupied_cells() const override;

	//��ʾ����
	void show_prompt(bool show) override;

	//��������
	virtual void on_interact() override;

	// ���ù۲���
	void set_observer(DoorObserver* observer) { _observer = observer; }
private:
	int _id;
	bn::sprite_ptr sprite;

	DoorObserver* _observer = nullptr;  // �۲���ָ�루��ӵ�У�

	//bn::string_view interact_message;
	bn::vector<bn::sprite_ptr, 128> text_sprites;
	bn::sprite_text_generator text_generator;
	bool prompt_visible = false;

	bn::sprite_ptr create_sprite(int id);
};

#endif // !DOOR_H
