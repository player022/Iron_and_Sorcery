#ifndef BN_SPRITE_ITEMS_SOURCE_HAN_SANS_JP_H
#define BN_SPRITE_ITEMS_SOURCE_HAN_SANS_JP_H

#include "bn_sprite_item.h"

//{{BLOCK(source_han_sans_jp_bn_gfx)

//======================================================================
//
//	source_han_sans_jp_bn_gfx, 16x1584@4, 
//	+ palette 16 entries, not compressed
//	+ 396 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 12672 = 12704
//
//	Time-stamp: 2025-04-02, 19:50:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SOURCE_HAN_SANS_JP_BN_GFX_H
#define GRIT_SOURCE_HAN_SANS_JP_BN_GFX_H

#define source_han_sans_jp_bn_gfxTilesLen 12672
extern const bn::tile source_han_sans_jp_bn_gfxTiles[396];

#define source_han_sans_jp_bn_gfxPalLen 32
extern const bn::color source_han_sans_jp_bn_gfxPal[16];

#endif // GRIT_SOURCE_HAN_SANS_JP_BN_GFX_H

//}}BLOCK(source_han_sans_jp_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item source_han_sans_jp(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(source_han_sans_jp_bn_gfxTiles, 396), bpp_mode::BPP_4, compression_type::NONE, 99), 
            sprite_palette_item(span<const color>(source_han_sans_jp_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

