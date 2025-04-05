#ifndef BN_SPRITE_ITEMS_ITEM_MENU_CURSOR_H
#define BN_SPRITE_ITEMS_ITEM_MENU_CURSOR_H

#include "bn_sprite_item.h"

//{{BLOCK(item_menu_cursor_bn_gfx)

//======================================================================
//
//	item_menu_cursor_bn_gfx, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2025-04-02, 19:50:35
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ITEM_MENU_CURSOR_BN_GFX_H
#define GRIT_ITEM_MENU_CURSOR_BN_GFX_H

#define item_menu_cursor_bn_gfxTilesLen 2048
extern const bn::tile item_menu_cursor_bn_gfxTiles[64];

#define item_menu_cursor_bn_gfxPalLen 32
extern const bn::color item_menu_cursor_bn_gfxPal[16];

#endif // GRIT_ITEM_MENU_CURSOR_BN_GFX_H

//}}BLOCK(item_menu_cursor_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item item_menu_cursor(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(item_menu_cursor_bn_gfxTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(item_menu_cursor_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

