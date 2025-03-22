#ifndef BN_SPRITE_ITEMS_CURSOR_H
#define BN_SPRITE_ITEMS_CURSOR_H

#include "bn_sprite_item.h"

//{{BLOCK(cursor_bn_gfx)

//======================================================================
//
//	cursor_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2025-03-20, 18:39:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CURSOR_BN_GFX_H
#define GRIT_CURSOR_BN_GFX_H

#define cursor_bn_gfxTilesLen 128
extern const bn::tile cursor_bn_gfxTiles[4];

#define cursor_bn_gfxPalLen 32
extern const bn::color cursor_bn_gfxPal[16];

#endif // GRIT_CURSOR_BN_GFX_H

//}}BLOCK(cursor_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cursor(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(cursor_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(cursor_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

