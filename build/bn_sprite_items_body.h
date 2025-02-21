#ifndef BN_SPRITE_ITEMS_BODY_H
#define BN_SPRITE_ITEMS_BODY_H

#include "bn_sprite_item.h"

//{{BLOCK(body_bn_gfx)

//======================================================================
//
//	body_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2025-02-21, 16:27:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BODY_BN_GFX_H
#define GRIT_BODY_BN_GFX_H

#define body_bn_gfxTilesLen 128
extern const bn::tile body_bn_gfxTiles[4];

#define body_bn_gfxPalLen 32
extern const bn::color body_bn_gfxPal[16];

#endif // GRIT_BODY_BN_GFX_H

//}}BLOCK(body_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item body(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(body_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(body_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

