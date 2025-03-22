#ifndef BN_REGULAR_BG_ITEMS_MENU_H
#define BN_REGULAR_BG_ITEMS_MENU_H

#include "bn_regular_bg_item.h"

//{{BLOCK(menu_bn_gfx)

//======================================================================
//
//	menu_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 79 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 2528 + 2048 = 4608
//
//	Time-stamp: 2025-03-20, 18:39:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENU_BN_GFX_H
#define GRIT_MENU_BN_GFX_H

#define menu_bn_gfxTilesLen 2528
extern const bn::tile menu_bn_gfxTiles[79];

#define menu_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell menu_bn_gfxMap[1024];

#define menu_bn_gfxPalLen 32
extern const bn::color menu_bn_gfxPal[16];

#endif // GRIT_MENU_BN_GFX_H

//}}BLOCK(menu_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item menu(
            regular_bg_tiles_item(span<const tile>(menu_bn_gfxTiles, 79), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(menu_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(menu_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

