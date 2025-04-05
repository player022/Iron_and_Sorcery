#ifndef BN_AFFINE_BG_ITEMS_INVENTORY_H
#define BN_AFFINE_BG_ITEMS_INVENTORY_H

#include "bn_affine_bg_item.h"

//{{BLOCK(inventory_bn_gfx)

//======================================================================
//
//	inventory_bn_gfx, 256x256@8, 
//	+ palette 16 entries, not compressed
//	+ 76 tiles (t reduced) not compressed
//	+ affine map, not compressed, 32x32 
//	Total size: 32 + 4864 + 1024 = 5920
//
//	Time-stamp: 2025-04-04, 16:30:23
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_INVENTORY_BN_GFX_H
#define GRIT_INVENTORY_BN_GFX_H

#define inventory_bn_gfxTilesLen 4864
extern const bn::tile inventory_bn_gfxTiles[152];

#define inventory_bn_gfxMapLen 1024
extern const bn::affine_bg_map_cell inventory_bn_gfxMap[1024];

#define inventory_bn_gfxPalLen 32
extern const bn::color inventory_bn_gfxPal[16];

#endif // GRIT_INVENTORY_BN_GFX_H

//}}BLOCK(inventory_bn_gfx)

namespace bn::affine_bg_items
{
    constexpr inline affine_bg_item inventory(
            affine_bg_tiles_item(span<const tile>(inventory_bn_gfxTiles, 152), compression_type::NONE), 
            bg_palette_item(span<const color>(inventory_bn_gfxPal, 16), bpp_mode::BPP_8, compression_type::NONE),
            affine_bg_map_item(inventory_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

