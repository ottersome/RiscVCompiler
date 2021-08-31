	.file	"exfloat.c"
	.option nopic
	.text
	.globl	thisisweird
	.section	.rodata
	.align	3
.LC0:
	.string	"it really is\n"
	.section	.sdata,"aw"
	.align	3
	.type	thisisweird, @object
	.size	thisisweird, 8
thisisweird:
	.dword	.LC0
	.comm	staticFloat,4,4
	.text
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sd	s0,24(sp)
	addi	s0,sp,32
	lui	a5,%hi(.LC1)
	flw	fa5,%lo(.LC1)(a5)
	fsw	fa5,-20(s0)
	li	a5,0
	mv	a0,a5
	ld	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.section	.rodata
	.align	2
.LC1:
	.word	1094713344
	.ident	"GCC: (GNU) 9.2.0"
	.section	.note.GNU-stack,"",@progbits
