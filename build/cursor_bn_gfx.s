
@{{BLOCK(cursor_bn_gfx)

@=======================================================================
@
@	cursor_bn_gfx, 16x16@4, 
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
	.global cursor_bn_gfxTiles		@ 128 unsigned chars
	.hidden cursor_bn_gfxTiles
cursor_bn_gfxTiles:
	.word 0x76000000,0x67600000,0x33330000,0x63330000,0x66330000,0x76300000,0x66000000,0x65000000
	.word 0x00000777,0x00007777,0x00003373,0x0000A67A,0x00006676,0x00007777,0x00007777,0x00000777
	.word 0x66100000,0x76610000,0x66171000,0x66111000,0x99100000,0x57100000,0x17710000,0x00000000
	.word 0x00000166,0x00001777,0x00017177,0x00011176,0x00000199,0x00000170,0x00001760,0x00000000

	.section .rodata
	.align	2
	.global cursor_bn_gfxPal		@ 32 unsigned chars
	.hidden cursor_bn_gfxPal
cursor_bn_gfxPal:
	.hword 0x0000,0x0C44,0x18C6,0x318C,0x2171,0x25D7,0x3238,0x3A9C
	.hword 0x4E52,0x6715,0x7B99,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(cursor_bn_gfx)
