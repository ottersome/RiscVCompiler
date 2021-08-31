.text
.section .rodata
.align 3
.LC0: .string "%d\n"
.LC1: .string "%f\n"
.LC2: .string "%s\n"
.LC3: .word 3212836864#This ought to be -1

#Constant Pool:
.comm aa,4,4
.text
.align 1
.globl main
.type main, @function
main:
addi sp,sp,-1024
sd  ra,1016(sp)
sd  s0,1008(sp)
sd  s0,1000(sp)
addi s0,sp, 40
addi s1,sp,0

li t0,8
addi s0,s0,4
sw t0,0(s0)
	#LOADING STATIC VAR
lui t0,%hi(aa)
addi t0,t0,%lo(aa)
lw t1,0(s0)
add s0,s0,-4
sw t1,(t0)
	#END: LOADING STATIC VAR
ld  ra,1016(sp)
ld  s0,1008(sp)
ld  s0,1000(sp)
addi sp,sp,1024
jr ra
.size main, .-main
    # END of main function
