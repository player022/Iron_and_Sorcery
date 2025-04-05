#ifndef BN_SPRITE_ITEMS_TREE1_H
#define BN_SPRITE_ITEMS_TREE1_H

#include "bn_sprite_item.h"

//{{BLOCK(tree1_bn_gfx)

//======================================================================
//
//	tree1_bn_gfx, 384x64@4, 
//	+ palette 16 entries, not compressed
//	+ 384 tiles Metatiled by 8x8 not compressed
//	Total size: 32 + 12288 = 12320
//
//	Time-stamp: 2025-04-05, 16:28:37
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TREE1_BN_GFX_H
#define GRIT_TREE1_BN_GFX_H

#define tree1_bn_gfxTilesLen 12288
extern const bn::tile tree1_bn_gfxTiles[384];

#define tree1_bn_gfxPalLen 32
extern const bn::color tree1_bn_gfxPal[16];

#endif // GRIT_TREE1_BN_GFX_H

//}}BLOCK(tree1_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item tree1(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(tree1_bn_gfxTiles, 384), bpp_mode::BPP_4, compression_type::NONE, 6), 
            sprite_palette_item(span<const color>(tree1_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

