#ifndef BN_SPRITE_ITEMS_WELL_H
#define BN_SPRITE_ITEMS_WELL_H

#include "bn_sprite_item.h"

//{{BLOCK(well_bn_gfx)

//======================================================================
//
//	well_bn_gfx, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2025-03-20, 18:39:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WELL_BN_GFX_H
#define GRIT_WELL_BN_GFX_H

#define well_bn_gfxTilesLen 512
extern const bn::tile well_bn_gfxTiles[16];

#define well_bn_gfxPalLen 32
extern const bn::color well_bn_gfxPal[16];

#endif // GRIT_WELL_BN_GFX_H

//}}BLOCK(well_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item well(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(well_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(well_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

