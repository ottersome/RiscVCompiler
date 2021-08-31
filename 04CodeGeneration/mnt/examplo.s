	.file	"examplo.c"
	.option nopic
	.text
	.comm	ejemplo,4,4
	.comm	xo,4,4
	.comm	ejemplero,4,4
	.comm	estero,48,8
	.align	2
	.globl	returno
	.type	returno, @function
returno:
	addi	sp,sp,-16
	sd	s0,8(sp)
	addi	s0,sp,16
	fmv.s.x	fa5,zero
	fmv.x.s	a0,fa5
	ld	s0,8(sp)
	addi	sp,sp,16
	jr	ra
	.size	returno, .-returno
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-16
	sd	ra,8(sp)
	sd	s0,0(sp)
	addi	s0,sp,16
	call	returno
	fmv.s.x	fa4,a0
	lui	a5,%hi(.LC0)
	flw	fa5,%lo(.LC0)(a5)
	fadd.s	fa5,fa4,fa5
	lui	a5,%hi(ejemplero)
	fsw	fa5,%lo(ejemplero)(a5)
	li	a5,0
	mv	a0,a5
	ld	ra,8(sp)
	ld	s0,0(sp)
	addi	sp,sp,16
	jr	ra
	.size	main, .-main
	.section	.rodata
	.align	2
.LC0:
	.word	1067030938
	.ident	"GCC: (GNU) 9.2.0"
	.section	.note.GNU-stack,"",@progbits
