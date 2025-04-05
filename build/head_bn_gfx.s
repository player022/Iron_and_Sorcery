
@{{BLOCK(head_bn_gfx)

@=======================================================================
@
@	head_bn_gfx, 16x16@4, 
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
	.global head_bn_gfxTiles		@ 128 unsigned chars
	.hidden head_bn_gfxTiles
head_bn_gfxTiles:
	.word 0x32000000,0x23200000,0x11110000,0x41110000,0x22110000,0x32100000,0x32000000,0x20000000
	.word 0x00000333,0x00003333,0x00001131,0x00006436,0x00002232,0x00003333,0x00003322,0x00000333
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global head_bn_gfxPal		@ 32 unsigned chars
	.hidden head_bn_gfxPal
head_bn_gfxPal:
	.hword 0x7FFF,0x318C,0x3238,0x3A9C,0x7B99,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(head_bn_gfx)
