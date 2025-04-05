#ifndef BN_AFFINE_BG_TILES_ITEMS_TILES_H
#define BN_AFFINE_BG_TILES_ITEMS_TILES_H

#include "bn_affine_bg_tiles_item.h"

//{{BLOCK(tiles_bn_gfx)

//======================================================================
//
//	tiles_bn_gfx, 64x8@8, 
//	+ 8 tiles not compressed
//	Total size: 512 = 512
//
//	Time-stamp: 2025-04-02, 19:50:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TILES_BN_GFX_H
#define GRIT_TILES_BN_GFX_H

#define tiles_bn_gfxTilesLen 512
extern const bn::tile tiles_bn_gfxTiles[16];

#endif // GRIT_TILES_BN_GFX_H

//}}BLOCK(tiles_bn_gfx)

namespace bn::affine_bg_tiles_items
{
    constexpr inline affine_bg_tiles_item tiles(
            span<const tile>(tiles_bn_gfxTiles, 16), compression_type::NONE);
}

#endif

