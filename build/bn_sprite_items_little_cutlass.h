#ifndef BN_SPRITE_ITEMS_LITTLE_CUTLASS_H
#define BN_SPRITE_ITEMS_LITTLE_CUTLASS_H

#include "bn_sprite_item.h"

//{{BLOCK(little_cutlass_bn_gfx)

//======================================================================
//
//	little_cutlass_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2025-03-20, 18:39:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LITTLE_CUTLASS_BN_GFX_H
#define GRIT_LITTLE_CUTLASS_BN_GFX_H

#define little_cutlass_bn_gfxTilesLen 128
extern const bn::tile little_cutlass_bn_gfxTiles[4];

#define little_cutlass_bn_gfxPalLen 32
extern const bn::color little_cutlass_bn_gfxPal[16];

#endif // GRIT_LITTLE_CUTLASS_BN_GFX_H

//}}BLOCK(little_cutlass_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item little_cutlass(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(little_cutlass_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(little_cutlass_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

