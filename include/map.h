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

#include "item_map.h"

#include <vector>

// 地形索引常量
namespace
{
	constexpr int grassland_tile_index1 = 0;
	constexpr int grassland_tile_index2 = 1;
	constexpr int grassland_tile_index3 = 2;
	constexpr int grassland_stoneroad_tile_index1 = 3;
	constexpr int grassland_stoneroad_tile_index2 = 4;
	constexpr int grassland_stoneroad_tile_index3 = 5;
	constexpr int grassland_stoneroad_tile_index4 = 6;
	constexpr int grassland_stoneroad_tile_index5 = 7;
}

class Map
{
public:
	std::vector<std::optional<Item_map>> items;

	static constexpr int columns = 64;
	static constexpr int rows = 64;
	static constexpr int cells_count = columns * rows;

	Map(); // 构造函数

	void update(int x, int y);

	bn::affine_bg_map_item get_map_item() const { return _map_item; }

	static int sprite_x(int cursor_x)
	{
		return (cursor_x * 8) - (columns * 4) + 4;
	}

	static int sprite_y(int cursor_y)
	{
		return (cursor_y * 8) - (rows * 4) - 2;
	}

private:
	alignas(int) bn::affine_bg_map_cell _cells[cells_count]; // 地图格子
	bn::affine_bg_map_item _map_item;
	bn::affine_bg_ptr _bg; // 背景
	bn::random _random;

	bn::affine_bg_ptr _initialize(); // 初始化地图
	void _initialize_items();
	void update_items(int x, int y);
	int _generate_random_tile(); // 生成随机地形
};

#endif // MAP_H
