#ifndef MAP_H
#define MAP_H

#include "bn_log.h"
#include "bn_core.h"
#include "bn_bg_tiles.h"
#include "bn_affine_bg_ptr.h"
#include "bn_affine_bg_item.h"
#include "bn_affine_bg_map_ptr.h"
#include "bn_affine_bg_map_cell_info.h"
#include "bn_random.h"

#include "bn_bg_palette_items_palette.h"
#include "bn_affine_bg_tiles_items_tiles.h"

#include "item.h"
#include "house.h"
#include "tree.h"
#include "door.h"
#include "equipment.h"

#include <vector>

class Map : public ItemObserver
{
public:
	int columns;  // 动态列数
	int rows;     // 动态行数
	static constexpr int cells_count = 64 * 64; // 最多64*64的单元数，但会根据实际大小调整

	bool _walkable_cells[64][64]; // 使用最大64的数组，超出部分需要动态调整

	// 构造函数，接受地图数据
	Map(const std::vector<std::vector<int>>& map_data, const std::vector<ItemInfo>& item_data);

	void add_item(std::shared_ptr<Item> item);
	void update(int x, int y);
	bool can_move(int x, int y);

	bn::affine_bg_map_item get_map_item() const { return _map_item; }

	void get_interactable_items(bn::vector<Item*, 32>& interactable_items)
	{
		interactable_items.clear();  // 清空原有列表
		for (auto& item : items)
		{
			if (item->get_interactable() && !item->get_name().empty())  // 判断是否可交互且名称不为空
			{
				interactable_items.push_back(item.get());  // 添加到交互物品列表中
			}
		}
	}

	void on_door_state_changed(int x, int y, bool is_open) override
	{
		_walkable_cells[y][x] = is_open;
	}

	void on_item_picked_up(const Item& item) override
	{
		// 从地图中移除物品
		items.erase(std::remove_if(items.begin(), items.end(), [&item](const std::shared_ptr<Item>& i) {
			return i.get() == &item;  // 比较物品的指针
		}), items.end());
	}

	int sprite_x(int cursor_x)
	{
		return (columns * 4) - (cursor_x * 8);
	}

	int sprite_y(int cursor_y)
	{
		return (rows * 4) - (cursor_y * 8) ;
	}

private:
	std::vector<std::shared_ptr<Item>> items;
	alignas(int) bn::affine_bg_map_cell _cells[cells_count];
	bn::affine_bg_map_item _map_item;
	bn::affine_bg_ptr _bg;
	std::vector<ItemInfo> item_data; // 物品数据列表

	void initialize_items();

	bn::affine_bg_ptr _initialize(const std::vector<std::vector<int>>& map_data);
	void update_items(int x, int y);
};

#endif // MAP_H
