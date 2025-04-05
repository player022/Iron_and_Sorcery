#ifndef ITEMOBSERVER_H
#define ITEMOBSERVER_H

class Item;  // 前向声明 Item 类

class ItemObserver
{
public:
	virtual ~ItemObserver() = default;

	//开门，后续可以拓展所有状态变化
	virtual void on_door_state_changed(int x, int y, bool is_open) = 0;  // 纯虚函数

	// 物品被拾取
	virtual void on_item_picked_up(const Item& item) = 0;
};


#endif // !ITEMOBSERVER_H