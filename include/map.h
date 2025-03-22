#ifndef MAP_H
#define MAP_H

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
#include "doorObserver.h"

#include <vector>

class Map : public DoorObserver
{
public:
	int columns;  // 动态列数
	int rows;     // 动态行数
	static constexpr int cells_count = 64 * 64; // 最多64*64的单元数，但会根据实际大小调整

	bool _walkable_cells[64 + 1][64 + 1]; // 使用最大64的数组，超出部分需要动态调整

	// 构造函数，接受地图数据
	Map(const std::vector<std::vector<int>>& map_data);

	void add_item(std::shared_ptr<Item> item);
	void update(int x, int y);
	bool can_move(int x, int y);

	bn::affine_bg_map_item get_map_item() const { return _map_item; }

	void on_door_state_changed(int x, int y, bool is_open) override
	{
		_walkable_cells[x][y] = is_open;
	}

	int sprite_x(int cursor_x)
	{
		return (cursor_x * 8) - (columns * 4);
	}

	int sprite_y(int cursor_y)
	{
		return (cursor_y * 8) - (rows * 4);
	}

private:
	std::vector<std::shared_ptr<Item>> items;
	alignas(int) bn::affine_bg_map_cell _cells[cells_count];
	bn::affine_bg_map_item _map_item;
	bn::affine_bg_ptr _bg;

	bn::affine_bg_ptr _initialize(const std::vector<std::vector<int>>& map_data);
	void update_items(int x, int y);
};

#endif // MAP_H
