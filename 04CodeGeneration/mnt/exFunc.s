	.file	"exFunc.c"
	.option nopic
	.text
	.comm	x,4,4
	.align	2
	.globl	desta
	.type	desta, @function
desta:
	addi	sp,sp,-16
	sd	s0,8(sp)
	addi	s0,sp,16
	nop
	mv	a0,a5
	ld	s0,8(sp)
	addi	sp,sp,16
	jr	ra
	.size	desta, .-desta
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sd	s0,24(sp)
	addi	s0,sp,32
	sw	zero,-20(s0)
	li	a5,0
	mv	a0,a5
	ld	s0,24(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (GNU) 9.2.0"
	.section	.note.GNU-stack,"",@progbits
