.data
num: .word 0
prompt: .asciiz "Enter a number: "
result: .asciiz "Factors of the number: "

.text
.globl main
main:
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 4
    la $a0, result
    syscall

    li $t1, 1   

factor_loop:
    div $t0, $t1
    mfhi $t2

    beqz $t2, print_factor

    addiu $t1, $t1, 1
    blt $t1, $t0, factor_loop

    li $v0, 10
    syscall

print_factor:
    li $v0, 1
    move $a0, $t1
    syscall


    addiu $t1, $t1, 1
    blt $t1, $t0, factor_loop

    li $v0, 10
    syscall
