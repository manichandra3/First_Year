.data
    num1: .word 0
    num2: .word 1
    result: .word 0
    count: .word 8

.text
.globl main

main:
    lw $t0, num1     
    lw $t1, num2     
    lw $t2, count    
    li $t3, 0
    
    li $v0, 1
    move $a0, $t0   
    syscall
         
    li $v0, 1
    move $a0, $t1    
    syscall

loop:
    add $t3, $t0, $t1    
    sw $t3, result       
    
    li $v0, 1
    lw $a0, result
    syscall
    
    add $t0, $t1, $zero  
    add $t1, $t3, $zero 
    
    addi $t2, $t2, -1    
    
    bgtz $t2, loop       
    
    li $v0, 10
    syscall