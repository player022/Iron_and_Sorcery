#ifndef BN_SPRITE_ITEMS_CUTLASS_H
#define BN_SPRITE_ITEMS_CUTLASS_H

#include "bn_sprite_item.h"

//{{BLOCK(cutlass_bn_gfx)

//======================================================================
//
//	cutlass_bn_gfx, 32x32@8, 
//	+ palette 48 entries, not compressed
//	+ 16 tiles Metatiled by 4x4 not compressed
//	Total size: 96 + 1024 = 1120
//
//	Time-stamp: 2025-02-21, 16:27:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CUTLASS_BN_GFX_H
#define GRIT_CUTLASS_BN_GFX_H

#define cutlass_bn_gfxTilesLen 1024
extern const bn::tile cutlass_bn_gfxTiles[32];

#define cutlass_bn_gfxPalLen 96
extern const bn::color cutlass_bn_gfxPal[48];

#endif // GRIT_CUTLASS_BN_GFX_H

//}}BLOCK(cutlass_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cutlass(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(cutlass_bn_gfxTiles, 32), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(cutlass_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

