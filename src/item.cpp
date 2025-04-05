#include "item.h"
#include "bn_keypad.h"

Item::Item(int x, int y) :
	_x(x), _y(y), _interactable(false)
{

}

// 统一的 update_position 方法
void Item::update_position(int x, int y)
{
	int new_x = (_x - x) * 8;
	int new_y = (_y - y) * 8;

	// 交由子类具体更新精灵
	update_sprites(new_x, new_y);

	// 检查是否靠近物品
	int dist_x = x - _x;
	int dist_y = y - _y;
	int abs_dist_x = abs(dist_x);
	int abs_dist_y = abs(dist_y);

	//优先度更新
	if (abs_dist_x <= 15 && abs_dist_y <= 10) {
		update_priority(true);
	}
	else {
		update_priority(false);
	}

	// 交互检测
	_interactable = (abs_dist_x <= 1 && abs_dist_y <= 1); // 在交互范围内

	auto occlusion = get_occlusion_range();
	if (!occlusion) return;  // 没有遮挡范围，不进行检测

	auto[left, right, top, bottom] = *occlusion;

	bool inside = (dist_x >= left && dist_x <= right) && (dist_y >= top && dist_y <= bottom);

	on_occlusion(inside);
}