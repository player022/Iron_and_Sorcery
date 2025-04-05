#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "bn_keypad.h"

#include "map.h"
#include "item_mune.h"
#include "mapData.h"

#include <map> 
#include <optional>

class MapManager
{
public:
	MapManager();

	void load_map(int map_x, int map_y);

	/*
	无参更新，每帧更新，用于背景，检测输入这些
	*/
	void update();

	/*
	接收玩家的位置参数，之所以设置两个不同的更新方法，
	是因为这里的更新资源开销比较大，没有必要每帧更新
	*/
	void update(int player_x, int player_y);

	std::shared_ptr<Map> get_map() { return map.value_or(nullptr); }  // 获取地图，若为空返回 nullptr

private:
	// 64x64 的地图数据示例，每个值对应一个地形索引
	std::vector<std::vector<int>> my_map_data;

	std::optional<std::shared_ptr<Map>> map; // 使用 optional 包装 shared_ptr

};

#endif // MAPMANAGER_H
