.text
.comm ex,4,4
.section .rodata
.align 3
.LC0: .string "%d\n"

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

#Emitting Num Constant
li t1,33
addi s0,s0,4
sw t1,0(s0)
#DONE Emitting Num Constant
#Emitting Num Constant
li t1,1
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
addi s0,s0,4
#End of addition

#Load static variable

li a3, 231
lui a5,%hi(ex)
addi a5,a5,%lo(ex)
sw a3,(a5)


lui a0,%hi(.LC0)
addi a0,a0,%lo(.LC0)
lw a1,(a5)
call printf


ld  ra,1016(sp)
ld  s0,1008(sp)
ld  s0,1000(sp)
addi sp,sp,1024
jr ra
.size main, .-main
    # END of main function
