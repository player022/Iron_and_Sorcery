#include "map.h"
#include "bn_keypad.h"

#include "bn_log.h"

// ���캯�������ܵ�ͼ����
Map::Map(const std::vector<std::vector<int>>& map_data) :
	columns(map_data[0].size()), // ��̬��������
	rows(map_data.size()),       // ��̬��������
	_map_item(_cells[0], bn::size(columns, rows)),
	_bg(_initialize(map_data))
{
	_bg.set_blending_enabled(false);
	_bg.set_wrapping_enabled(false);
	_bg.set_priority(3);
}

// ��ʼ����ͼ��ʹ������ĵ�ͼ���ݣ�
bn::affine_bg_ptr Map::_initialize(const std::vector<std::vector<int>>& map_data)
{
	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < columns; ++x)
		{
			bn::affine_bg_map_cell& current_cell = _cells[_map_item.cell_index(x, y)];
			bn::affine_bg_map_cell_info current_cell_info(current_cell);

			// ʹ������ĵ�ͼ����
			int tile_index = map_data[x][y];
			current_cell_info.set_tile_index(tile_index);
			current_cell = current_cell_info.cell();

			int mirror_y = rows - y;  // ��ת Y ����
			int mirror_x = columns - x;  // ��ת X ����

			if (tile_index == 4) {
				_walkable_cells[mirror_x][mirror_y] = false;
			}
			else {
				_walkable_cells[mirror_x][mirror_y] = true;
			}
		}
	}

	// ��ʼ������
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
	if (x < 1 || x > columns || y < 1 || y > rows)
	{
		return false;
	}
	return _walkable_cells[x][y];
}

void Map::add_item(std::shared_ptr<Item> item)
{
	items.push_back(item);
	for (const auto&[cell_x, cell_y] : item->get_occupied_cells())
	{
		if (cell_x >= 1 && cell_x <= columns && cell_y >= 1 && cell_y <= rows)
		{
			_walkable_cells[columns - cell_x][rows - cell_y] = false;
		}
	}
}

void Map::update_items(int x, int y)
{
	for (auto& item : items)
	{
		if (item)
		{
			if (item->update_position(x - columns, y - rows))
			{
				item->show_prompt(true);
				if (bn::keypad::a_pressed())
				{
					item->on_interact();
				}
			}
			else
			{
				item->show_prompt(false);
			}
		}
	}
}
