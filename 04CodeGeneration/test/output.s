.text
.section .rodata
.align 3

.text
.align 1
.globl main
.type main, @function
#Emitting Num Constant
li t1,#8
addi s0,s0,4
sw t1,0(s0)
#DONE Emitting Num Constant
.text
.align 1
.globl func0
.type func0, @function

#Emitting Num Constant
li t1,#1
addi s0,s0,4
sw t1,0(s0)
#DONE Emitting Num Constant
#Start of addition
lw a1, 0(s0)        #pop from the top of stack
addi s0,s0,-4       #move the pointer of stack 
lw a2, 0(s0) 
addi s0,s0,-4   
add a3, a1, a2 
sw a3, 0(s0)        #store the result to stack 
addi s0,4
#End of addition
