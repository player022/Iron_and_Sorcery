
@{{BLOCK(body_bn_gfx)

@=======================================================================
@
@	body_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2025-03-20, 18:39:50
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global body_bn_gfxTiles		@ 128 unsigned chars
	.hidden body_bn_gfxTiles
body_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x33000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000033
	.word 0x44100000,0x54410000,0x44151000,0x44111000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000144,0x00001555,0x00015155,0x00011154,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global body_bn_gfxPal		@ 32 unsigned chars
	.hidden body_bn_gfxPal
body_bn_gfxPal:
	.hword 0x7FFF,0x0C44,0x318C,0x25D7,0x3238,0x3A9C,0x6715,0x7B99
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(body_bn_gfx)
