	.option nopic
	.text
	.section 	.rodata
	.align 3
.LC0:
	.string "hello\n"

	.text
	.align 1
	.globl main
	.type main,@function
main:
	addi sp,sp,-16
	sd ra,16(sp)
	sd s0,0(sp)
	addi s0,sp,16
	lui t0,%hi(.LC0)
	addi a0,t0,%lo(.LC0)
	call printf
	ld ra,16(sp)
	ld s0,0(sp)
	addi sp,sp,16
	jr ra
	.size main, .-main
