.text
.section .rodata
.align 3
.LC0: .string "%d\n"
.LC1: .string "%f\n"
.LC2: .string "%s\n"

#Constant Pool:
.LC3: .word 1082340147
.LC4: .word 1101592527
.LC5: .word 1065353216
.LC6: .word 1094818202
.LC7: .word 0
.LC8: .word 1082130432
.LC9: .word 1094818202
.LC10: .word 1066192077
.LC11: .word 1036831949
.LC12: .string "Calling add them"
.LC13: .word 1095866778
.LC14: .word 1094818202
.LC15: .word 1101529088
.LC16: .string "Value of x is :"
.LC17: .word 1085276160
.comm aa,4,4
.comm bb,4,4
.comm resulto,4,4
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

	#Start: Loading FP Value to Stack
lui t0,%hi(.LC3)
flw ft0,%lo(.LC3)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
	#LOADING STATIC Float VAR
lui t0,%hi(aa)
addi t0,t0,%lo(aa)
flw ft0,0(s0)
add s0,s0,-4
fsw ft0,(t0)
	#END: LOADING STATIC Float VAR
	#START: EMIT PROC
	#START: Load Static Float Var RHS
lui t0, %hi(aa)
addi t0,t0, %lo(aa)
flw ft0,(t0)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Static Float Var RHS
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
	#START: EMIT PROC
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC4)
flw ft0,%lo(.LC4)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
	#START: Load Static Float Var RHS
lui t0, %hi(aa)
addi t0,t0, %lo(aa)
flw ft0,(t0)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Static Float Var RHS
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC5)
flw ft0,%lo(.LC5)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
flw ft1, 0(s0)        #pop from the top of stack
addi s0,s0,-4       #move the pointer of stack 
flw ft2, 0(s0) 
addi s0,s0,-4   
#Start: FSUBB
fsub.s ft3, ft2, ft1 
#END: FSUBB
addi s0,s0,4
fsw ft3, 0(s0)        #store the result to stack 
	#LOADING STATIC Float VAR
lui t0,%hi(aa)
addi t0,t0,%lo(aa)
flw ft0,0(s0)
add s0,s0,-4
fsw ft0,(t0)
	#END: LOADING STATIC Float VAR
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC6)
flw ft0,%lo(.LC6)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
	#LOADING STATIC Float VAR
lui t0,%hi(bb)
addi t0,t0,%lo(bb)
flw ft0,0(s0)
add s0,s0,-4
fsw ft0,(t0)
	#END: LOADING STATIC Float VAR
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC7)
flw ft0,%lo(.LC7)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
	#LOADING STATIC Float VAR
lui t0,%hi(resulto)
addi t0,t0,%lo(resulto)
flw ft0,0(s0)
add s0,s0,-4
fsw ft0,(t0)
	#END: LOADING STATIC Float VAR
	#START: EMIT PROC
	#START: Load Static Float Var RHS
lui t0, %hi(aa)
addi t0,t0, %lo(aa)
flw ft0,(t0)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Static Float Var RHS
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
	#START: EMIT PROC
	#START: Load Static Float Var RHS
lui t0, %hi(bb)
addi t0,t0, %lo(bb)
flw ft0,(t0)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Static Float Var RHS
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
	#START: Load Static Float Var RHS
lui t0, %hi(aa)
addi t0,t0, %lo(aa)
flw ft0,(t0)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Static Float Var RHS
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC8)
flw ft0,%lo(.LC8)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
lw t0, 0(s0)        #pop from the top of stack
addi s0,s0,-4       #move the pointer of stack 
lw t1, 0(s0) 
addi s0,s0,-4   
slt t2,t1,t0
seqz t2,t2
addi s0,s0,4
sw t2,0(s0)
	#START: Load Static Float Var RHS
lui t0, %hi(bb)
addi t0,t0, %lo(bb)
flw ft0,(t0)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Static Float Var RHS
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC9)
flw ft0,%lo(.LC9)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
lw t0, 0(s0)        #pop from the top of stack
addi s0,s0,-4       #move the pointer of stack 
lw t1, 0(s0) 
addi s0,s0,-4   
#Start: Testing equality
sub t2,t0,t1
seqz t2,t2
#End: Testing equality
addi s0,s0,4
sw t2,0(s0)
lw t0, 0(s0)        #pop from the top of stack
addi s0,s0,-4       #move the pointer of stack 
lw t1, 0(s0) 
addi s0,s0,-4   
OR t2,t0,t1
snez t2,t2
addi s0,s0,4
sw t2,0(s0)
	#Start: IFEV
lw t0, 0(s0)
addi s0,s0,-4
beq t0, zero, .L0
	#End: IFEV
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC10)
flw ft0,%lo(.LC10)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
	#LOADING STATIC Float VAR
lui t0,%hi(resulto)
addi t0,t0,%lo(resulto)
flw ft0,0(s0)
add s0,s0,-4
fsw ft0,(t0)
	#END: LOADING STATIC Float VAR
j .L1
.L0:
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC11)
flw ft0,%lo(.LC11)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
	#LOADING STATIC Float VAR
lui t0,%hi(resulto)
addi t0,t0,%lo(resulto)
flw ft0,0(s0)
add s0,s0,-4
fsw ft0,(t0)
	#END: LOADING STATIC Float VAR
.L1:
	#START: EMIT PROC
	#START: Load Static Float Var RHS
lui t0, %hi(aa)
addi t0,t0, %lo(aa)
flw ft0,(t0)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Static Float Var RHS
	#START: Load Static Float Var RHS
lui t0, %hi(bb)
addi t0,t0, %lo(bb)
flw ft0,(t0)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Static Float Var RHS
flw ft1, 0(s0)        #pop from the top of stack
addi s0,s0,-4       #move the pointer of stack 
flw ft2, 0(s0) 
addi s0,s0,-4   
#Start of float addition
fadd.s ft3, ft1, ft2 
#End of addition
addi s0,s0,4
fsw ft3, 0(s0)        #store the result to stack 
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
	#START: EMIT PROC
	#START: EMIT PROC
#Emitting Num Constant
li t1,5
addi s0,s0,4
sw t1,0(s0)
#DONE Emitting Num Constant
#Emitting Num Constant
li t1,2
addi s0,s0,4
sw t1,0(s0)
#DONE Emitting Num Constant
lw a0, 0(s0)
addi s0,s0, -4
lw a1, 0(s0)
addi s0,s0, -4
call addInt
addi s0,s0,4
sw a0,0(s0)
	#END: EMIT PROC
lui a0,%hi(.LC0)
addi a0,a0,%lo(.LC0)
lw a1, 0(s0)
addi s0,s0, -4
call printf
	#END: EMIT PROC
	#START: EMIT PROC
	#START: Load Static Float Var RHS
lui t0, %hi(resulto)
addi t0,t0, %lo(resulto)
flw ft0,(t0)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Static Float Var RHS
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
	#START: EMIT PROC
	#Start: Loading String Address Value to Stack
lui t0,%hi(.LC12)
addi t0,t0,%lo(.LC12)
addi s0,s0,4
sw t0,0(s0)
	#End: Loading String Address Value to Stack
lui a0,%hi(.LC2)
addi a0,a0,%lo(.LC2)
lw a1, 0(s0)
addi s0,s0,-4
call printf
	#END: EMIT PROC
	#START: EMIT PROC
	#START: EMIT PROC
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC13)
flw ft0,%lo(.LC13)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC14)
flw ft0,%lo(.LC14)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a0, ft0
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call addthem
addi s0,s0,4
sw a0,0(s0)
	#END: EMIT PROC
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
ld  ra,1016(sp)
ld  s0,1008(sp)
ld  s0,1000(sp)
addi sp,sp,1024
jr ra
.size main, .-main
    # END of main function
.text
.align 1
.globl addthem
.type addthem, @function
addthem:

addi sp,sp,-976
sd ra,968(sp)
sd s0,960(sp)
sd s1,952(sp)
addi s0,sp,12
addi s1,sp,0
    	# Start: Offloading argumnets
#Offloading x
#Offloading y
fmv.d.x ft0,a1
fcvt.s.d ft0,ft0#Turns back to word
fsw ft0,4(s1)

lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
fcvt.d.s ft0,ft0
li a1,21
fmv.x.d a1,ft0
call printf
	# End: Offloading argumnets
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC15)
flw ft0,%lo(.LC15)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
	#Start: Store Local Var
lw t1,0(s0)
add s0,s0,-4
sw t1,0(s1)#Get from local variable
	#End: Store Local Var
	#START: EMIT PROC
	#START: Load Local Float Var RHS
flw ft0,0(s1)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Local Float Var RHS
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
	#START: EMIT PROC
	#Start: Loading String Address Value to Stack
lui t0,%hi(.LC16)
addi t0,t0,%lo(.LC16)
addi s0,s0,4
sw t0,0(s0)
	#End: Loading String Address Value to Stack
lui a0,%hi(.LC2)
addi a0,a0,%lo(.LC2)
lw a1, 0(s0)
addi s0,s0,-4
call printf
	#END: EMIT PROC
	#START: EMIT PROC
	#START: Load Local Float Var RHS
flw ft0,0(s1)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Local Float Var RHS
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
	#START: EMIT PROC
	#START: Load Local Float Var RHS
flw ft0,0(s1)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Local Float Var RHS
	#START: Load Local Float Var RHS
flw ft0,0(s1)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Local Float Var RHS
flw ft1, 0(s0)        #pop from the top of stack
addi s0,s0,-4       #move the pointer of stack 
flw ft2, 0(s0) 
addi s0,s0,-4   
#Start of float addition
fadd.s ft3, ft1, ft2 
#End of addition
addi s0,s0,4
fsw ft3, 0(s0)        #store the result to stack 
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
	#START: EMIT PROC
	#Start: Loading FP Value to Stack
lui t0,%hi(.LC17)
flw ft0,%lo(.LC17)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
#Take Proper Steps to Move float to argument register
flw ft0,0(s0)
addi s0,s0, -4
fcvt.d.s ft0,ft0
fmv.x.d a1, ft0
call printf
	#END: EMIT PROC
	#START: Load Local Float Var RHS
flw ft0,0(s1)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Local Float Var RHS
	#START: Load Local Float Var RHS
flw ft0,0(s1)
addi s0,s0,4
fsw ft0, 0(s0)
	#END: Load Local Float Var RHS
flw ft1, 0(s0)        #pop from the top of stack
addi s0,s0,-4       #move the pointer of stack 
flw ft2, 0(s0) 
addi s0,s0,-4   
#Start of float addition
fadd.s ft3, ft1, ft2 
#End of addition
addi s0,s0,4
fsw ft3, 0(s0)        #store the result to stack 
flw ft0,0(s0)
addi s0,s0, -4
fmv.x.d a0, ft0
ld ra,968(sp)
ld s0,960(sp)
ld s1,952(sp)
addi sp,sp,976
jr ra
.size addthem, .-addthem
.text
.align 1
.globl addInt
.type addInt, @function
addInt:

addi sp,sp,-976
sd ra,968(sp)
sd s0,960(sp)
sd s1,952(sp)
addi s0,sp,12
addi s1,sp,0
    	# Start: Offloading argumnets
#Offloading x
sw a0,0(s1)
#Offloading y
sw a1,4(s1)
	# End: Offloading argumnets
	#START: EMIT PROC
	#START: Load Local Var RHS
lw t1,0(s1)
addi s0,s0,4
sw t1, 0(s0)
	#END: Load Local Var RHS
	#START: Load Local Var RHS
lw t1,4(s1)
addi s0,s0,4
sw t1, 0(s0)
	#END: Load Local Var RHS
#Start of addition
lw a1, 0(s0)        #pop from the top of stack
addi s0,s0,-4       #move the pointer of stack 
lw a2, 0(s0) 
addi s0,s0,-4   
add a3, a1, a2 
addi s0,s0,4
sw a3, 0(s0)        #store the result to stack 
#End of addition
lui a0,%hi(.LC0)
addi a0,a0,%lo(.LC0)
lw a1, 0(s0)
addi s0,s0, -4
call printf
	#END: EMIT PROC
#Emitting Num Constant
li t1,214
addi s0,s0,4
sw t1,0(s0)
#DONE Emitting Num Constant
lw a0,0(s0)
addi s0,s0,-4
ld ra,968(sp)
ld s0,960(sp)
ld s1,952(sp)
addi sp,sp,976
jr ra
.size addInt, .-addInt
