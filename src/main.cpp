/*
 * Copyright (c) 2020-2025 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_memory.h"

#include "bn_sprite_items_cutlass.h"
#include "bn_sprite_items_little_cutlass.h"

#include "map.h"
#include "menu.h"
#include "player.h"
#include "item_map.h"
#include "item_bag.h"

#include "bn_log.h"

enum class GameState
{
	Playing,   // ������Ϸ״̬
	Inventory, // ������״̬
};

GameState game_state = GameState::Playing; // Ĭ�ϴ�����Ϸ״̬


int main()
{
	bn::core::init();

	bn::bg_tiles::set_allow_offset(false);

	Map map;

	//������������
	Menu menu;

	bn::bg_tiles::set_allow_offset(true);

	//int cursor_x = bg_map::columns / 2;
	//int cursor_y = bg_map::rows / 2;
	int cursor_x = 32;
	int cursor_y = 32;

	// ��������
	Player player(Map::sprite_x(cursor_x), Map::sprite_y(cursor_y));

    //bg_map.reload_cells_ref();

	int key_hold_counter = 0; // ��¼������סʱ��
	const int long_press_threshold = 20; // 20 ֡����������ƶ�ģʽ
	const int move_interval = 5; // ������ÿ 5 ֡�ƶ�һ��
	bool is_moving = false; // ��¼�Ƿ������ƶ�������״̬��

	while (true)
	{
		bool moved = false;
		int move_x = 0, move_y = 0;

		if (bn::keypad::start_pressed())
		{
			if (game_state == GameState::Playing)
			{
				game_state = GameState::Inventory;
				menu.toggle_visibility();
			}
			else
			{
				game_state = GameState::Playing;
				menu.toggle_visibility();
			}
		}

		if (game_state == GameState::Playing)
		{
			if (bn::keypad::select_pressed()) {
				//player.change_equipment(1);
				//player.take_damage(10);
				map.change_tile_color(32, 32);
			}
			// ֻ���ڲ�������Ծ״̬ʱ���ܽ����ƶ�����
			if (player.can_move())
			{
				if (bn::keypad::left_held()) {
					player.horizontal_flip(true);
					move_x += 1;
				}
				if (bn::keypad::right_held()) {
					player.horizontal_flip(false);
					move_x -= 1;
				}
				if (bn::keypad::up_held()) { move_y += 1; }
				if (bn::keypad::down_held()) { move_y -= 1; }

				if (move_x != 0 || move_y != 0)
				{
					if (key_hold_counter == 0 || (key_hold_counter >= long_press_threshold && key_hold_counter % move_interval == 0))
					{
						/* �ȼ���Ƿ��ͨ�� */
						if (map.can_move(cursor_x + move_x, cursor_y + move_y)) {
							cursor_x += move_x;
							cursor_y += move_y;
						}
						moved = true;
					}
					key_hold_counter++;
				}
				else
				{
					key_hold_counter = 0;
				}
			}

			if (moved)
			{
				player.start_jump();  // ������ԾЧ��
			}
			//BN_LOG("cursor_x", cursor_x, "cursor_y", cursor_y);
			player.update_priority(cursor_y);
			map.update(cursor_x, cursor_y);
		}

		player.update_jump_effect();  // ÿ֡������Ծ����
		bn::core::update();
	}
}
