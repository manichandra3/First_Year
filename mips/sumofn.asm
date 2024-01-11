.data
    myarray: .space 40
    size: .word 0
    result: .word 0
    prompt: .asciiz "Enter the size of the array (<=10): "
    newline: .asciiz "\n"
    st: .asciiz "Enter the 10 Elements: "

.text
    # Input for size of the array
    li $v0, 4                # Load immediate: set $v0 to 4 (print string)
    la $a0, prompt           # Load address: load the address of the prompt string
    syscall                 

    li $v0, 5                # Load immediate: set $v0 to 5 (read integer)
    syscall
    move $t2, $v0            # Move the size of the array to $t2

    # Print newline
    li $v0, 4                # Load immediate: set $v0 to 4 (print string)
    la $a0, newline          # Load address: load the address of the newline string
    syscall                 

    # Input for the elements of the array
    li $v0, 4                # Load immediate: set $v0 to 4 (print string)
    la $a0, st               # Load address: load the address of the prompt string
    syscall                 

    lw $t1, size             # Load the value of 'size' into $t1
    li $t3, 4                # Load immediate: set $t3 to 4
    mult $t1, $t3            # Multiply 'size' by 4
    mflo $t1                 # Move the low 32 bits of the result into $t1

    addi $t3, $t0, 1         # Initialize $t3 for sum calculation
    lw $t4, result           # Load initial result value

    jal fun                  # Jump and link: jump to the function fun
    jal sum                  # Jump and link: jump to the function sum

    li $v0, 10               # Load immediate: set $v0 to 10 (exit program)
    syscall

fun:
    li $v0, 5                # Load immediate: set $v0 to 5 (read integer)
    syscall                 

    beq $t0, $t1, exit       # Branch if equal: if $t0 is equal to $t1, jump to exit
    sw $v0, myarray($t0)     # Store word: store the value of $v0 in myarray[$t0]
    addi $t0, $t0, 4         # Add immediate: add 4 to $t0 (array index increment)
    j fun                    # Jump: jump back to the beginning of the function

sum:
    lw $t0, result           # Load initial result value
    add $t3, $t0, $t3        # Add $t0 and $t3, storing the result in $t3 (sum calculation)
    sll $t3, $t3, 2          # Shift left logical: Multiply $t3 by 4 (word size)
    la $t4, myarray          # Load address: load the address of the myarray label
    add $t3, $t3, $t4        # Add the base address of myarray to $t3
    lw $t4, 0($t3)           # Load word: load the value from memory at the calculated address
    add $t4, $t4, $t0        # Add $t4 and $t0, storing the result in $t4
    sw $t4, result           # Store word: store the result in the result variable
    addi $t0, $t0, 1         # Add immediate: increment $t0 by 1
    bne $t0, $t1, sum        # Branch if not equal: if $t0 is not equal to $t1, jump to sum

exit:
    jr $ra                  # Jump register: jump back to the return address
