
@{{BLOCK(head1_bn_gfx)

@=======================================================================
@
@	head1_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2025-04-02, 19:50:38
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global head1_bn_gfxTiles		@ 128 unsigned chars
	.hidden head1_bn_gfxTiles
head1_bn_gfxTiles:
	.word 0x99000000,0x99900000,0x889C0000,0x989C0000,0x8A9C0000,0x99900000,0x99000000,0x90000000
	.word 0x00000A89,0x0000A98A,0x0000BB88,0x0000A9BA,0x0000BBB8,0x0000A9BA,0x0000A9BA,0x00000AB9
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global head1_bn_gfxPal		@ 32 unsigned chars
	.hidden head1_bn_gfxPal
head1_bn_gfxPal:
	.hword 0x7FFF,0x0C44,0x318C,0x25D7,0x3238,0x3A9C,0x6715,0x7B99
	.hword 0x7F79,0x38E7,0x1CA8,0x5AB3,0x294B,0x0000,0x0000,0x0000

@}}BLOCK(head1_bn_gfx)
