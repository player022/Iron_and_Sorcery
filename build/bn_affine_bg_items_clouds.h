#ifndef BN_AFFINE_BG_ITEMS_CLOUDS_H
#define BN_AFFINE_BG_ITEMS_CLOUDS_H

#include "bn_affine_bg_item.h"

//{{BLOCK(clouds_bn_gfx)

//======================================================================
//
//	clouds_bn_gfx, 256x256@8, 
//	+ palette 16 entries, not compressed
//	+ 120 tiles (t reduced) not compressed
//	+ affine map, not compressed, 32x32 
//	Total size: 32 + 7680 + 1024 = 8736
//
//	Time-stamp: 2025-04-02, 19:50:35
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CLOUDS_BN_GFX_H
#define GRIT_CLOUDS_BN_GFX_H

#define clouds_bn_gfxTilesLen 7680
extern const bn::tile clouds_bn_gfxTiles[240];

#define clouds_bn_gfxMapLen 1024
extern const bn::affine_bg_map_cell clouds_bn_gfxMap[1024];

#define clouds_bn_gfxPalLen 32
extern const bn::color clouds_bn_gfxPal[16];

#endif // GRIT_CLOUDS_BN_GFX_H

//}}BLOCK(clouds_bn_gfx)

namespace bn::affine_bg_items
{
    constexpr inline affine_bg_item clouds(
            affine_bg_tiles_item(span<const tile>(clouds_bn_gfxTiles, 240), compression_type::NONE), 
            bg_palette_item(span<const color>(clouds_bn_gfxPal, 16), bpp_mode::BPP_8, compression_type::NONE),
            affine_bg_map_item(clouds_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

