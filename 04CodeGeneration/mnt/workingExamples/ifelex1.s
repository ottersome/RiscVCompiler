	.file	"ifex.c"
	.option nopic
	.text
	.comm	x,4,4
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-16
	sd	s0,8(sp)
	addi	s0,sp,16

	##Load X Into a5
	lui	a5,%hi(x)
	lw	a5,%lo(x)(a5)
	mv	a4,a5
	## Address of x now in A4

	## Load 248 into A5
	li	a5,248
	beq	a4,a5,.L2 ## Test For Equality Between X and 248

	## Load X Again
	lui	a5,%hi(x)
	lw	a5,%lo(x)(a5)
	mv	a4,a5
	li	a5,789
	ble	a4,a5,.L3//COmpare x with 789

	## Load X again and copmpare with 123
	lui	a5,%hi(x)
	lw	a5,%lo(x)(a5)
	mv	a4,a5
	li	a5,122
	bgt	a4,a5,.L3
.L2:
	lui	a5,%hi(x)
	li	a4,45
	sw	a4,%lo(x)(a5)
	j	.L4
.L3:
	lui	a5,%hi(x)
	li	a4,54
	sw	a4,%lo(x)(a5)
.L4:
	li	a5,0
	mv	a0,a5
	ld	s0,8(sp)
	addi	sp,sp,16
	jr	ra
	.size	main, .-main
	.ident	"GCC: (GNU) 9.2.0"
	.section	.note.GNU-stack,"",@progbits
