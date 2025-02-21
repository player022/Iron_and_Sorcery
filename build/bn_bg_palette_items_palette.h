#ifndef BN_BG_PALETTE_ITEMS_PALETTE_H
#define BN_BG_PALETTE_ITEMS_PALETTE_H

#include "bn_bg_palette_item.h"

//{{BLOCK(palette_bn_gfx)

//======================================================================
//
//	palette_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2025-02-21, 16:27:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PALETTE_BN_GFX_H
#define GRIT_PALETTE_BN_GFX_H

#define palette_bn_gfxPalLen 32
extern const bn::color palette_bn_gfxPal[32];

#endif // GRIT_PALETTE_BN_GFX_H

//}}BLOCK(palette_bn_gfx)

namespace bn::bg_palette_items
{
    constexpr inline bg_palette_item palette(span<const color>(palette_bn_gfxPal, 32), 
            bpp_mode::BPP_8, compression_type::NONE);
}

#endif

