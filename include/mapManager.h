#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "map.h"

class MapManager
{
public:
	MapManager();

	void load_map(int map_x, int map_y);

	void update(int player_x, int player_y);

	std::shared_ptr<Map> get_current_map() { return _current_map; }
private:
	std::vector<std::vector<int>> world_map;
	std::shared_ptr<Map> _current_map;

	int _current_map_x = 0;
	int _current_map_y = 0;
};

#endif // !MAPMANAGER_H
