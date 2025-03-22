#ifndef BN_SPRITE_ITEMS_TREE1_H
#define BN_SPRITE_ITEMS_TREE1_H

#include "bn_sprite_item.h"

//{{BLOCK(tree1_bn_gfx)

//======================================================================
//
//	tree1_bn_gfx, 256x64@8, 
//	+ palette 48 entries, not compressed
//	+ 256 tiles Metatiled by 8x8 not compressed
//	Total size: 96 + 16384 = 16480
//
//	Time-stamp: 2025-03-20, 18:39:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TREE1_BN_GFX_H
#define GRIT_TREE1_BN_GFX_H

#define tree1_bn_gfxTilesLen 16384
extern const bn::tile tree1_bn_gfxTiles[512];

#define tree1_bn_gfxPalLen 96
extern const bn::color tree1_bn_gfxPal[48];

#endif // GRIT_TREE1_BN_GFX_H

//}}BLOCK(tree1_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item tree1(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(tree1_bn_gfxTiles, 512), bpp_mode::BPP_8, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(tree1_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

