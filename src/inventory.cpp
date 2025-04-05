#include "inventory.h"
#include "bn_regular_bg_items_inventory.h"

Inventory::Inventory():
	inventory_bg(bn::regular_bg_items::inventory.create_bg(0, 0))
{
	inventory_bg.set_priority(2);
}