#include "map.h"
#include "bn_log.h"

// 构造函数，接受地图数据
Map::Map(const std::vector<std::vector<int>>& map_data, const std::vector<ItemInfo>& item_data) :
	columns(map_data[0].size()), // 动态设置列数
	rows(map_data.size()),       // 动态设置行数
	_map_item(_cells[0], bn::size(columns, rows)),
	_bg(_initialize(map_data)),
	item_data(item_data)
{
	_bg.set_blending_enabled(false);
	_bg.set_wrapping_enabled(false);
	_bg.set_priority(3);

	initialize_items();
}

// 初始化地图（使用输入的地图数据）
bn::affine_bg_ptr Map::_initialize(const std::vector<std::vector<int>>& map_data)
{
	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < columns; ++x)
		{
			bn::affine_bg_map_cell& current_cell = _cells[_map_item.cell_index(x, y)];
			bn::affine_bg_map_cell_info current_cell_info(current_cell);

			int tile_index = map_data[y][x];
			current_cell_info.set_tile_index(tile_index);
			current_cell = current_cell_info.cell();

			if (tile_index == 4) {
				_walkable_cells[y][x] = false;
			}
			else {
				_walkable_cells[y][x] = true;
			}
		}
	}

	// 初始化背景
	bn::affine_bg_item bg_item(
		bn::affine_bg_tiles_items::tiles, bn::bg_palette_items::palette, _map_item);
	return bg_item.create_bg(0, 0);
}

void Map::update(int x, int y)
{
	_bg.set_position(sprite_x(x), sprite_y(y));
	update_items(x, y);
}

bool Map::can_move(int x, int y)
{
	if (x < 0 || x > columns || y < 0 || y > rows)
	{
		return false;
	}
	return _walkable_cells[y][x];
}

void Map::add_item(std::shared_ptr<Item> item)
{
	items.push_back(item);
	for (const auto&[cell_x, cell_y] : item->get_occupied_cells())
	{
		if (cell_x >= 0 && cell_x < columns && cell_y >= 0 && cell_y < rows)
		{
			_walkable_cells[cell_y][cell_x] = false;
		}
	}
}

void Map::update_items(int x, int y)
{
	for (auto& item : items)
	{
		item->update_position(x, y);
	}
}

void Map::initialize_items()
{
	for (const auto& info : item_data)
	{
		std::shared_ptr<Item> item;
		switch (info.type)
		{
		case ItemInfo::Type::Tree:
			item = std::make_shared<Tree>(info.id, info.x, info.y);
			break;
		case ItemInfo::Type::House:
			item = std::make_shared<House>(info.id, info.x, info.y);
			break;
		case ItemInfo::Type::Door:
			item = std::make_shared<Door>(info.id, info.x, info.y);
			break;
		case ItemInfo::Type::Equipment:
			item = std::make_shared<Equipment>(info.id, info.x, info.y);
			break;
		}

		BN_LOG("add itemName:", item->get_name());

		item->set_observer(this);

		if (item)
		{
			add_item(item);
		}
	}
}
