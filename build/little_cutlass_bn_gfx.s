
@{{BLOCK(little_cutlass_bn_gfx)

@=======================================================================
@
@	little_cutlass_bn_gfx, 16x16@4, 
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
	.global little_cutlass_bn_gfxTiles		@ 128 unsigned chars
	.hidden little_cutlass_bn_gfxTiles
little_cutlass_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x60000000,0x68000000,0x18800000,0x01780000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00178000,0x00017750,0x00001410,0x00003150,0x00003015,0x00000322,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global little_cutlass_bn_gfxPal		@ 32 unsigned chars
	.hidden little_cutlass_bn_gfxPal
little_cutlass_bn_gfxPal:
	.hword 0x7FFF,0x0C42,0x1D51,0x11DB,0x1BDF,0x3BDF,0x5AB3,0x5EF3
	.hword 0x6F54,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(little_cutlass_bn_gfx)
