#ifndef BN_SPRITE_ITEMS_DOOR_H
#define BN_SPRITE_ITEMS_DOOR_H

#include "bn_sprite_item.h"

//{{BLOCK(door_bn_gfx)

//======================================================================
//
//	door_bn_gfx, 64x32@4, 
//	+ palette 16 entries, not compressed
//	+ 32 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 1024 = 1056
//
//	Time-stamp: 2025-04-02, 19:50:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DOOR_BN_GFX_H
#define GRIT_DOOR_BN_GFX_H

#define door_bn_gfxTilesLen 1024
extern const bn::tile door_bn_gfxTiles[32];

#define door_bn_gfxPalLen 32
extern const bn::color door_bn_gfxPal[16];

#endif // GRIT_DOOR_BN_GFX_H

//}}BLOCK(door_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item door(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(door_bn_gfxTiles, 32), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(door_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

