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

#include "mapManager.h"
#include "item_mune.h"
#include "inventory.h"
#include "player.h"
#include "debug.h"

#include "bn_log.h"

enum class GameState
{
	Playing,   // ������Ϸ״̬
	Interact,  // ��Ʒ����״̬
	Inventory, // ������״̬
};

GameState game_state = GameState::Playing; // Ĭ�ϴ�����Ϸ״̬


int main()
{
	bn::core::init();

	std::unique_ptr<Item_mune> item_mune = nullptr; // Ĭ�ϲ���ʼ��
	std::unique_ptr<Inventory> inventory = nullptr;
	bn::vector<Item*, 32> interactable_items;  // �洢������������Ʒָ��

	int map_x = 1;
	int map_y = 1;
	int cursor_x = 32;
	int cursor_y = 32;

	MapManager mapManager;
	mapManager.load_map(map_x, map_y);

	// ��������
	Player player(4, -2);

	//bg_map.reload_cells_ref();

	int _time = 0;

	// �� main ����� DebugDisplay ʵ��
	Debug debug(_time, cursor_x, cursor_y);

	int key_hold_counter = 0; // ��¼������סʱ��

	while (true)
	{
		bool moved = false;
		int move_x = 0, move_y = 0;
		if (bn::keypad::start_released())
		{
			if (game_state == GameState::Playing)
			{
				if (!inventory) // ֻ����δ����ʱ�Ŵ���
				{
					game_state = GameState::Inventory;
					inventory = std::make_unique<Inventory>();
				}
			}
		}
		if (bn::keypad::a_released())
		{
			if (game_state == GameState::Playing)
			{
				if (!item_mune) // ֻ����δ����ʱ�Ŵ���
				{
					mapManager.get_map()->get_interactable_items(interactable_items);
					if (!interactable_items.empty()) {
						game_state = GameState::Interact;
						item_mune = std::make_unique<Item_mune>(interactable_items);
					}
				}
			}
		}
		if (game_state == GameState::Inventory)
		{
			if (bn::keypad::b_pressed()|| bn::keypad::start_pressed())
			{
				game_state = GameState::Playing;
				inventory.reset(); // �ͷ�ָ�룬���ٶ���
			}
		}
		if (game_state == GameState::Interact)
		{
			item_mune->update();
			if (bn::keypad::b_pressed())
			{
				game_state = GameState::Playing;
				item_mune.reset(); // �ͷ�ָ�룬���ٶ���
			}
		}

		if (game_state == GameState::Playing)
		{
			if (bn::keypad::select_pressed()) {
				player.take_damage(10);
			}

			if (bn::keypad::left_held()) {
				player.horizontal_flip(true);
				move_x -= 1;
			}
			if (bn::keypad::right_held()) {
				player.horizontal_flip(false);
				move_x += 1;
			}
			if (bn::keypad::up_held()) { move_y -= 1; }
			if (bn::keypad::down_held()) { move_y += 1; }

			if (move_x != 0 || move_y != 0)
			{
				if (key_hold_counter == 0 || (key_hold_counter >= 20 && key_hold_counter % 10 == 0))
				{
					int new_x = cursor_x + move_x;
					int new_y = cursor_y + move_y;
					/* �ȼ���Ƿ��ͨ�� */
					if (mapManager.get_map()->can_move(new_x, new_y)) {
						cursor_x = new_x;
						cursor_y = new_y;
					}
					// ����Ƿ���Ҫ�����µĵ�ͼ
					if (new_x < 0 && map_x > 0) {
						// �������µ�ͼ
						cursor_x = 63;
						map_x -= 1;
						mapManager.load_map(map_x, map_y);
					}
					else if (new_y < 0 && map_y > 0) {
						// �������µ�ͼ
						cursor_y = 63;
						map_y -= 1;
						mapManager.load_map(map_x, map_y);
					}
					else if (new_x >= mapManager.get_map()->columns && map_x < 4) {
						// ����û�е�ͼ
						cursor_x = 0;
						map_x += 1;
						mapManager.load_map(map_x, map_y);
					}
					else if (new_y >= mapManager.get_map()->rows && map_y < 4) {
						// ����û�е�ͼ
						cursor_y = 0;
						map_y += 1;
						mapManager.load_map(map_x, map_y);
					}
					if (cursor_x == 35 && cursor_y == 20) {
						mapManager.load_map(0, 0);
					}
					_time++;
					if (_time == 2880) {
						_time = 0;
					}
					player.update_priority(cursor_y);
					mapManager.update(cursor_x, cursor_y);

					debug.update(_time, cursor_x, cursor_y);

					moved = true;
				}
				key_hold_counter++;
			}
			else
			{
				key_hold_counter = 0;
			}

			if (moved)
			{
				player.start_jump();  // ������ԾЧ��
			}
		}
		player.update_jump_effect();  // ÿ֡������Ծ����
		bn::core::update();
	}
}
