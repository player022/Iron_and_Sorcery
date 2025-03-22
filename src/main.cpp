/*
 * Copyright (c) 2020-2025 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_memory.h"
#include "bn_string.h"

#include "bn_sprite_items_cutlass.h"
#include "bn_sprite_items_little_cutlass.h"

#include "map.h"
#include "menu.h"
#include "player.h"
#include "item_bag.h"

#include "house.h"
#include "tree.h"
#include "door.h"

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

	// 64x64 �ĵ�ͼ����ʾ����ÿ��ֵ��Ӧһ����������
	std::vector<std::vector<int>> my_map_data(32, std::vector<int>(32, 0));

	// ������ (10,10) �� (20,20) ֮�����ʯͷ·
	for (int x = 14; x < 23; ++x)
	{
		for (int y = 8; y < 13; ++y)
		{
			my_map_data[x][y] = 4;  // ʯͷ·����
		}
	}

	// ���ɵ�ͼ
	Map map(my_map_data);


	// ����һЩ��Ʒ����������
	auto tree1 = std::make_shared<Tree>(1, 20, 27, 32, 32);
	map.add_item(tree1);
	auto tree2 = std::make_shared<Tree>(2, 25, 27, 32, 32);
	map.add_item(tree2);
	auto house1 = std::make_shared<House>(1, 34, 34, 32, 32);
	map.add_item(house1);
	auto door1 = std::make_shared<Door>(1, 35, 34, 32, 32);
	map.add_item(door1);
	door1->set_observer(&map); // ���� Door �¼�


	//������������
	Menu menu;

	bn::bg_tiles::set_allow_offset(true);

	//int cursor_x = bg_map::columns / 2;
	//int cursor_y = bg_map::rows / 2;
	int cursor_x = 1;
	int cursor_y = 1;

	// ��������
	Player player(4, -2);

    //bg_map.reload_cells_ref();

	int _time = 0;
	bn::vector<bn::sprite_ptr, 128> text_sprites0;
	bn::sprite_text_generator text_generator0(source_han_sans_jp_sprite_font);
	bn::string time_text = "TIME: " + bn::to_string<16>(_time);
	text_generator0.generate(45, -70, time_text, text_sprites0);

	bn::vector<bn::sprite_ptr, 128> text_sprites1;
	bn::sprite_text_generator text_generator1(source_han_sans_jp_sprite_font);
	bn::string cursor_x_text = "cursor_x: " + bn::to_string<16>(cursor_x);
	text_generator1.generate(45, -60, cursor_x_text, text_sprites1);

	bn::vector<bn::sprite_ptr, 128> text_sprites2;
	bn::sprite_text_generator text_generator2(source_han_sans_jp_sprite_font);
	bn::string cursor_y_text = "cursor_y: " + bn::to_string<16>(cursor_y);
	text_generator2.generate(45, -50, cursor_y_text, text_sprites2);

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
				player.take_damage(10);
				//map.change_tile_color(32, 32);
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
						_time++;
						if (_time == 2880) {
							_time = 0;
						}
						text_sprites0.clear(); // ������ı�
						bn::string time_text = "TIME: " + bn::to_string<16>(_time);
						text_generator0.generate(45, -70, time_text, text_sprites0);

						text_sprites1.clear(); // ������ı�
						bn::string cursor_x_text = "cursor_x: " + bn::to_string<16>(cursor_x);
						text_generator1.generate(45, -60, cursor_x_text, text_sprites1);

						text_sprites2.clear(); // ������ı�
						bn::string cursor_y_text = "cursor_y: " + bn::to_string<16>(cursor_y);
						text_generator2.generate(45, -50, cursor_y_text, text_sprites2);
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
			player.update_priority(cursor_y);
			map.update(cursor_x, cursor_y);
			if (cursor_x == 35 && cursor_y == 34) {

			}
		}

		player.update_jump_effect();  // ÿ֡������Ծ����
		bn::core::update();
	}
}
