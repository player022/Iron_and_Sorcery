#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "item.h"

class Equipment : public Item
{
public:
	Equipment(int Equipment_id, int x, int y);
	virtual ~Equipment() {}  // 添加虚析构函数

	//具体精灵更新函数
	void update_sprites(int new_x, int new_y)override;

	// 返回物品名称
	bn::string_view get_name() const override;

	//交互动作
	virtual void on_interact() override;

	//设置优先级
	void update_priority(bool inside) override {
		if (inside) {
			sprite.set_z_order(100 - _y);
		}
		else {
			sprite.set_z_order(0);
		}
	}

	// 设置观察者
	void set_observer(ItemObserver* observer)override { _observer = observer; }
private:
	int _id;
	bn::sprite_ptr sprite;

	ItemObserver* _observer = nullptr;  // 观察者指针（不拥有）

	bn::sprite_ptr create_sprite(int id);

};

#endif // !EQUIPMENT_H
