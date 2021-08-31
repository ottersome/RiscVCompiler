.text
.section .rodata
.align 3
.LC0: .string "%d\n"
.LC1: .string "%f\n"

#Constant Pool:
.LC2: .word 1090833613
.comm abc,4,4
.comm v,4,4
.comm sval,4,4

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
lui t0,%hi(.LC2)
flw ft0,%lo(.LC2)(t0)
addi s0,s0,4
fsw ft0,0(s0)
	#End: Loading FP Value to Stack
	#LOADING STATIC Float VAR
lui t0,%hi(abc)
addi t0,t0,%lo(abc)
flw ft0,0(s0)
add s0,s0,-4
fsw ft0,(t0)
	#END: LOADING STATIC Float VAR
# Try to print it then
lui t0,%hi(abc)
addi t0,t0,%lo(abc)
flw ft0,(t0)
fcvt.d.s ft0,ft0
fmv.x.d a1,ft0

lui a0,%hi(.LC1)
addi a0,a0,%lo(.LC1)
call printf





ld  ra,1016(sp)
ld  s0,1008(sp)
ld  s0,1000(sp)
addi sp,sp,1024
jr ra
.size main, .-main
    # END of main function
