
@{{BLOCK(foot1_bn_gfx)

@=======================================================================
@
@	foot1_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2025-03-02, 18:00:56
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global foot1_bn_gfxTiles		@ 128 unsigned chars
	.hidden foot1_bn_gfxTiles
foot1_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0xBBC00000,0xBBC00000,0xB9A00000,0x9A880000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000CBB,0x00000CBC,0x00000AB0,0x00008A90

	.section .rodata
	.align	2
	.global foot1_bn_gfxPal		@ 32 unsigned chars
	.hidden foot1_bn_gfxPal
foot1_bn_gfxPal:
	.hword 0x7FFF,0x0C44,0x318C,0x25D7,0x3238,0x3A9C,0x6715,0x7B99
	.hword 0x41F0,0x18EC,0x38E7,0x29F9,0x252E,0x0000,0x0000,0x0000

@}}BLOCK(foot1_bn_gfx)
