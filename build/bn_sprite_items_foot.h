#ifndef BN_SPRITE_ITEMS_FOOT_H
#define BN_SPRITE_ITEMS_FOOT_H

#include "bn_sprite_item.h"

//{{BLOCK(foot_bn_gfx)

//======================================================================
//
//	foot_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2025-02-21, 16:27:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FOOT_BN_GFX_H
#define GRIT_FOOT_BN_GFX_H

#define foot_bn_gfxTilesLen 128
extern const bn::tile foot_bn_gfxTiles[4];

#define foot_bn_gfxPalLen 32
extern const bn::color foot_bn_gfxPal[16];

#endif // GRIT_FOOT_BN_GFX_H

//}}BLOCK(foot_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item foot(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(foot_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(foot_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

