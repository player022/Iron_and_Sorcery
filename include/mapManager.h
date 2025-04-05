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
	�޲θ��£�ÿ֡���£����ڱ��������������Щ
	*/
	void update();

	/*
	������ҵ�λ�ò�����֮��������������ͬ�ĸ��·�����
	����Ϊ����ĸ�����Դ�����Ƚϴ�û�б�Ҫÿ֡����
	*/
	void update(int player_x, int player_y);

	std::shared_ptr<Map> get_map() { return map.value_or(nullptr); }  // ��ȡ��ͼ����Ϊ�շ��� nullptr

private:
	// 64x64 �ĵ�ͼ����ʾ����ÿ��ֵ��Ӧһ����������
	std::vector<std::vector<int>> my_map_data;

	std::optional<std::shared_ptr<Map>> map; // ʹ�� optional ��װ shared_ptr

};

#endif // MAPMANAGER_H
