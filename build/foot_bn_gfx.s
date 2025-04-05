
@{{BLOCK(foot_bn_gfx)

@=======================================================================
@
@	foot_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2025-04-02, 19:50:35
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
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x44700000,0x13700000,0x13700000,0x73370000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000744,0x00000735,0x00000730,0x00007320

	.section .rodata
	.align	2
	.global foot_bn_gfxPal		@ 32 unsigned chars
	.hidden foot_bn_gfxPal
foot_bn_gfxPal:
	.hword 0x7FFF,0x25D7,0x3238,0x3A9C,0x6715,0x318C,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(foot_bn_gfx)
