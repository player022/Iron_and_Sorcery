
@{{BLOCK(foot_bn_gfx)

@=======================================================================
@
@	foot_bn_gfx, 16x16@4, 
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
	.global foot_bn_gfxTiles		@ 128 unsigned chars
	.hidden foot_bn_gfxTiles
foot_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x66100000,0x35100000,0x35100000,0x15510000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000166,0x00000150,0x00000150,0x00001540

	.section .rodata
	.align	2
	.global foot_bn_gfxPal		@ 32 unsigned chars
	.hidden foot_bn_gfxPal
foot_bn_gfxPal:
	.hword 0x7FFF,0x0C44,0x318C,0x25D7,0x3238,0x3A9C,0x6715,0x7B99
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(foot_bn_gfx)
