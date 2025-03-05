#include "map.h"

#include "bn_keypad.h"
#include "bn_log.h"

// 构造函数
Map::Map() :
	_map_item(_cells[0], bn::size(Map::columns, Map::rows)),
	_bg(_initialize())
{
	_bg.set_blending_enabled(false);
    _bg.set_wrapping_enabled(false);
    _bg.set_priority(3);
	_initialize_items();
}

void Map::update(int x, int y)
{
    _bg.set_position(sprite_x(x) - 4, sprite_y(y) + 2);
    update_items(x, y);
}

bool Map::can_move(int x, int y)
{
	if (x < 1 || x > columns || y < 1 || y > rows)
	{
		return false; // 超出边界，不能移动
	}

	return _walkable_cells[x][y]; // 返回是否可通行
}


// 生成随机地形
int Map::_generate_random_tile()
{
	constexpr int tile_types[] = {
		grassland_tile_index1, grassland_tile_index2, grassland_tile_index3,  // 草地
		grassland_stoneroad_tile_index1, grassland_stoneroad_tile_index2,     // 石头路
		grassland_stoneroad_tile_index3, grassland_stoneroad_tile_index4,
		grassland_stoneroad_tile_index5
	};

	constexpr int tile_weights[] = {
		30, 2, 10,  // 草地
		1, 1, 1, 1, 1  // 石头路
	};

	constexpr int total_weight = 42 + 5;

	int random_value = _random.get_int(total_weight);
	int cumulative_weight = 0;

	for (int i = 0; i < sizeof(tile_types) / sizeof(tile_types[0]); ++i)
	{
		cumulative_weight += tile_weights[i];
		if (random_value < cumulative_weight)
		{
			return tile_types[i];
		}
	}

	return grassland_tile_index1; // 默认草地
}

// 初始化地图
bn::affine_bg_ptr Map::_initialize()
{
	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < columns; ++x)
		{
			bn::affine_bg_map_cell& current_cell = _cells[_map_item.cell_index(x, y)];
			bn::affine_bg_map_cell_info current_cell_info(current_cell);

			int tile_index = _generate_random_tile();
			current_cell_info.set_tile_index(tile_index);

			current_cell = current_cell_info.cell();
			// 默认所有格子可通行
			_walkable_cells[y+1][x+1] = true;
		}
	}
	// 初始化背景
	bn::affine_bg_item bg_item(
		bn::affine_bg_tiles_items::tiles,bn::bg_palette_items::palette,_map_item);
	return bg_item.create_bg(0, 0);
}

// 初始化地图中的物品
void Map::_initialize_items()
{
	std::optional<Item_map> item1;
	item1.emplace(1, 34, 29);
	items.push_back(item1);
	std::optional<Item_map> item2;
	item2.emplace(2, 34, 27);
	_walkable_cells[34][27] = false;
	items.push_back(item2);
	std::optional<Item_map> item3;
	item3.emplace(3, 34, 27);
	items.push_back(item3);
	std::optional<Human> human1;
	human1.emplace(35, 35);
	humans.push_back(human1);
}

void Map::update_items(int x, int y)
{
	// 使用 erase_if 
	std::erase_if(items, [&](std::optional<Item_map>& item)
	{
		if (item) // 确保 item 存在
		{
			if (item->update_position(x- columns, y-rows))
			{
				item->show_pickup_prompt(true);
				if (bn::keypad::a_pressed() && item->can_pickup) // 按下 A 键拾取
				{
					return true; // 从 items 中移除该物品
				}
			}
			else
			{
				item->show_pickup_prompt(false);
			}
		}
		return false; // 保留此物品
	});
	// 使用 erase_if 
	std::erase_if(humans, [&](std::optional<Human>& human)
	{
		if (human) // 确保 item 存在
		{
			human->start_jump();
			human->update_position(x - columns, y - rows);
		}
		return false; // 保留此物品
	});
}


void Map::change_tile_color(int x, int y)
{
	// 检查坐标是否在有效范围内
	if (x < 0 || x >= columns || y < 0 || y >= rows)
	{
		return; // 超出范围，返回
	}

	// 获取指定坐标的地图单元格
	bn::affine_bg_map_cell& current_cell = _cells[_map_item.cell_index(x, y)];
	bn::affine_bg_map_cell_info current_cell_info(current_cell);

	// 修改该单元格的调色板 ID（改变颜色）
	current_cell_info.set_tile_index(5);

	// 更新地图单元格
	current_cell = current_cell_info.cell();
}


