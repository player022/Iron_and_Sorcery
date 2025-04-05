#ifndef BN_SPRITE_ITEMS_SHRUB_H
#define BN_SPRITE_ITEMS_SHRUB_H

#include "bn_sprite_item.h"

//{{BLOCK(shrub_bn_gfx)

//======================================================================
//
//	shrub_bn_gfx, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2025-04-02, 19:50:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SHRUB_BN_GFX_H
#define GRIT_SHRUB_BN_GFX_H

#define shrub_bn_gfxTilesLen 512
extern const bn::tile shrub_bn_gfxTiles[16];

#define shrub_bn_gfxPalLen 32
extern const bn::color shrub_bn_gfxPal[16];

#endif // GRIT_SHRUB_BN_GFX_H

//}}BLOCK(shrub_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item shrub(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(shrub_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(shrub_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

