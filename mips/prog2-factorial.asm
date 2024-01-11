.data
    prompt: .asciiz "Enter the number: "
    result: .asciiz "The factorial is: "
    
.text
.globl main

main:
    li $v0, 4
    la $a0, prompt
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0
    
    li $t1, 1 
    li $t2, 1 
    
loop:
    mult $t2, $t1
    mflo $t2
    
    addi $t1, $t1, 1
    ble $t1, $t0, loop
    
    li $v0, 4
    la $a0, result
    syscall
    
    li $v0, 1
    move $a0, $t2
    syscall
    
    li $v0, 10
    syscall
