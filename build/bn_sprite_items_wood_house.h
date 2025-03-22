#ifndef BN_SPRITE_ITEMS_WOOD_HOUSE_H
#define BN_SPRITE_ITEMS_WOOD_HOUSE_H

#include "bn_sprite_item.h"

//{{BLOCK(wood_house_bn_gfx)

//======================================================================
//
//	wood_house_bn_gfx, 128x64@4, 
//	+ palette 16 entries, not compressed
//	+ 128 tiles Metatiled by 8x8 not compressed
//	Total size: 32 + 4096 = 4128
//
//	Time-stamp: 2025-03-20, 18:39:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WOOD_HOUSE_BN_GFX_H
#define GRIT_WOOD_HOUSE_BN_GFX_H

#define wood_house_bn_gfxTilesLen 4096
extern const bn::tile wood_house_bn_gfxTiles[128];

#define wood_house_bn_gfxPalLen 32
extern const bn::color wood_house_bn_gfxPal[16];

#endif // GRIT_WOOD_HOUSE_BN_GFX_H

//}}BLOCK(wood_house_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item wood_house(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(wood_house_bn_gfxTiles, 128), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(wood_house_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

