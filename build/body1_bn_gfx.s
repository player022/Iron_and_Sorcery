
@{{BLOCK(body1_bn_gfx)

@=======================================================================
@
@	body1_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2025-02-21, 16:27:53
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global body1_bn_gfxTiles		@ 128 unsigned chars
	.hidden body1_bn_gfxTiles
body1_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x9AA00000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000BB9
	.word 0x88AA0000,0x888A0000,0xBB8AA000,0x9B08A000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x0000BBB8,0x00008CCC,0x000B8C99,0x0008C099,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global body1_bn_gfxPal		@ 32 unsigned chars
	.hidden body1_bn_gfxPal
body1_bn_gfxPal:
	.hword 0x7FFF,0x0C44,0x318C,0x25D7,0x3238,0x3A9C,0x6715,0x7B99
	.hword 0x35AD,0x38E7,0x5AB3,0x1CE6,0x294B,0x0000,0x0000,0x0000

@}}BLOCK(body1_bn_gfx)
