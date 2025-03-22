#include "item.h"

Item::Item(int x, int y, int columns, int rows) :
	_x(columns - x), _y(rows - y)
{

}

// 统一的 update_position 方法
bool Item::update_position(int x, int y)
{
	int new_x = (_x + x) * 8;
	int new_y = (_y + y) * 8;

	// 交由子类具体更新精灵
	update_sprites(new_x, new_y);

	// 检查是否靠近物品
	int dist_x = abs(-_x - x);
	int dist_y = abs(-_y - y);
	return (dist_x <= 1 && dist_y <= 1);
}