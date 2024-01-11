.data
nums: .space 40
prompt: .asciiz "Enter any number: "
prompt1: .asciiz "Palindrome\n"
prompt2: .asciiz "Not a palindrome\n"

.text
.globl main

main:
	li $v0, 4
	la $a0, prompt
	syscall

	li $t1, 0
	la $t0, nums

	input_loop:
		li $v0, 5
		syscall
		sw $v0, ($t0)

		addi $t1, $t1, 1
		addi $t0, $t0, 4
		blt $t1, 10, input_loop

	la $t0, nums

	palindrome_check:
		li $t1, 0
		li $t2, 9
		add $t3, $t0, $t2

		palindrome_loop:
			lw $t4, ($t0)
			lw $t5, ($t3)
			bne $t4, $t5, palindrome_fail

			addi $t0, $t0, 4
			addi $t3, $t3, -4
			addi $t1, $t1, 1
			bgt $t1, $t2, palindrome_pass

			j palindrome_loop

	palindrome_fail:
		li $v0, 4
		la $a0, prompt2
		syscall
		j end

	palindrome_pass:
		li $v0, 4
		la $a0, prompt1
		syscall

	end:
		li $v0, 10
		syscall
