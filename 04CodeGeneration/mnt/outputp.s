.text
.section .rodata
.align 3

.text
.align 1
.globl main
.type main, @function
main:
#Emitting Num Constant
addi sp,sp,-16
li t1,8
addi s0,sp,4
sw t1,0(s0)
#
#addi s0,s0,-4
#DONE Emitting Num Constant
