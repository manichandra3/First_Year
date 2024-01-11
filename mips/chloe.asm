.data
msg: .asciiz "Enter the number:"
newline: .asciiz "\n"
msg1: .asciiz "The factorial of the given number is: \n:"
.text
.globl main

main:
	li $v0, 4
	la $a0, msg
	syscall

	li $v0, 5
	syscall
	move $a0, $t0

	li $t1, 1
	li $t2, 1

while:
	mult $t2, $t1
	mflo $t2
	
	addi $t1, $t1, 1
	bge $t1, $t0, while

	li $v0, 4	
	la $a0, msg1
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall

	li $v0, 10	
	syscall