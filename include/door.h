#ifndef DOOR_H
#define DOOR_H

#include "item.h"
#include "doorObserver.h"

class Door : public Item
{
public:
	Door(int door_id, int x, int y, int columns, int rows);
	virtual ~Door() {}  // 添加虚析构函数

	//具体精灵更新函数
	void update_sprites(int new_x, int new_y)override;

	// 获取占据的格子
	std::vector<std::pair<int, int>> get_occupied_cells() const override;

	//提示文字
	void show_prompt(bool show) override;

	//交互动作
	virtual void on_interact() override;

	// 设置观察者
	void set_observer(DoorObserver* observer) { _observer = observer; }
private:
	int _id;
	bn::sprite_ptr sprite;

	DoorObserver* _observer = nullptr;  // 观察者指针（不拥有）

	//bn::string_view interact_message;
	bn::vector<bn::sprite_ptr, 128> text_sprites;
	bn::sprite_text_generator text_generator;
	bool prompt_visible = false;

	bn::sprite_ptr create_sprite(int id);
};

#endif // !DOOR_H
