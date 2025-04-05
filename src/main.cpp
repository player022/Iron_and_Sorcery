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
	Playing,   // 正常游戏状态
	Interact,  // 物品交互状态
	Inventory, // 背包打开状态
};

GameState game_state = GameState::Playing; // 默认处于游戏状态


int main()
{
	bn::core::init();

	std::unique_ptr<Item_mune> item_mune = nullptr; // 默认不初始化
	std::unique_ptr<Inventory> inventory = nullptr;
	bn::vector<Item*, 32> interactable_items;  // 存储符合条件的物品指针

	int map_x = 1;
	int map_y = 1;
	int cursor_x = 32;
	int cursor_y = 32;

	MapManager mapManager;
	mapManager.load_map(map_x, map_y);

	// 创建主角
	Player player(4, -2);

	//bg_map.reload_cells_ref();

	int _time = 0;

	// 在 main 中添加 DebugDisplay 实例
	Debug debug(_time, cursor_x, cursor_y);

	int key_hold_counter = 0; // 记录按键按住时间

	while (true)
	{
		bool moved = false;
		int move_x = 0, move_y = 0;
		if (bn::keypad::start_released())
		{
			if (game_state == GameState::Playing)
			{
				if (!inventory) // 只有在未创建时才创建
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
				if (!item_mune) // 只有在未创建时才创建
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
				inventory.reset(); // 释放指针，销毁对象
			}
		}
		if (game_state == GameState::Interact)
		{
			item_mune->update();
			if (bn::keypad::b_pressed())
			{
				game_state = GameState::Playing;
				item_mune.reset(); // 释放指针，销毁对象
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
					/* 先检查是否可通行 */
					if (mapManager.get_map()->can_move(new_x, new_y)) {
						cursor_x = new_x;
						cursor_y = new_y;
					}
					// 检查是否需要加载新的地图
					if (new_x < 0 && map_x > 0) {
						// 向左有新地图
						cursor_x = 63;
						map_x -= 1;
						mapManager.load_map(map_x, map_y);
					}
					else if (new_y < 0 && map_y > 0) {
						// 向上有新地图
						cursor_y = 63;
						map_y -= 1;
						mapManager.load_map(map_x, map_y);
					}
					else if (new_x >= mapManager.get_map()->columns && map_x < 4) {
						// 向右没有地图
						cursor_x = 0;
						map_x += 1;
						mapManager.load_map(map_x, map_y);
					}
					else if (new_y >= mapManager.get_map()->rows && map_y < 4) {
						// 向下没有地图
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
				player.start_jump();  // 触发跳跃效果
			}
		}
		player.update_jump_effect();  // 每帧更新跳跃动画
		bn::core::update();
	}
}
