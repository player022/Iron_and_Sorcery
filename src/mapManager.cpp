#include "mapManager.h"
#include "bn_log.h"
#include "bn_blending.h"
#include "bn_affine_bg_items_clouds.h"

MapManager::MapManager()
	: my_map_data(64, std::vector<int>(64, 0)), map(std::nullopt)
{
}

void MapManager::load_map(int map_x, int map_y)
{
	if (map.has_value())
	{
		map.reset();
	}
	// 生成地图数据
	for (int y = 0; y < 64; ++y)
	{
		for (int x = 0; x < 64; ++x)
		{
			my_map_data[y][x] = map_data[y + 64 * map_y][x + 64 * map_x];
		}
	}
	std::vector<ItemInfo> all_items;

	if (item_data[map_x][map_y].item_count > 0) {
		for (int i = 0; i < item_data[map_x][map_y].item_count; ++i) {
			all_items.push_back(item_data[map_x][map_y].items[i]);
		}
	}
	// 创建地图对象
	map = std::make_shared<Map>(my_map_data, all_items);
}

void MapManager::update()
{
	int move_x = 0, move_y = 0;
	static int key_hold_counter = 0;
}

void MapManager::update(int player_x, int player_y)
{
	// 确保地图存在再更新
	if (map.has_value())
	{
		map.value()->update(player_x, player_y);
	}
}
