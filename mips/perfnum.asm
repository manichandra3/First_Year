.data
num: .word 0
prompt: .asciiz "Enter your number: "
prompt_success: .asciiz "The number is a Perfect Number"
prompt_fail: .asciiz "The number is not a  Perfect Number"
sum: .word 0

.text
.globl main
main:
	li $v0, 4
    	la $a0, prompt
    	syscall                 

    	li $v0, 5
    	syscall
    	move $t1, $v0 
    	
    	add $t2, $t1, -1
    	li $t0, 1
    	
loop:
	div $t0, $t1
  	mfhi $t2

   	beqz $t2, ADD

   	addiu $t1, $t1, 1
   	blt $t1, $t0, loop
ADD:
	add $t3,$t3,$t1
	b loop
	
	beq $t4,$t1,success
	bne $t4,$1,fail
success:
	li $v0, 4
	la $a0, prompt_success
	syscall
	li $v0, 10
	syscall
fail:
	li $v0, 4
	la $a0,prompt_fail
	syscall
	li $v0, 10
	syscall