.data

msg1: .asciiz "Enter a number to convert: "

msg2: .asciiz "Enter the number of floating points: "

msg3: .asciiz "\n"

msg4: .asciiz "\nIEEE format is: "

msg5: .asciiz " "

flp: .word 0	#decimal points

fln: .word 0	#decimal part as int

num: .word 0 #int part of num

cnum: .word 0 #number of digits in num

b0: .word 0 #num in binary bounded by 2

b1: .word 0 #num in binary bounded by 2

b2: .word 0 #fln in binary bounded by 2

b3: .word 0 #exp in binary bounded by 2

.text

.globl main



main:



input:

	li $v0, 4

	la $a0, msg1					#print string 1

	syscall

	

	li $v0, 6					#input Float Number

	syscall



	mov.s $f2, $f0					#f2 - Float Number



	li $v0, 4

	la $a0, msg2					#print string 2

	syscall

	

	li $v0, 5					#input int

	syscall



	move $t0, $v0					#t0 - Number of floating point



	mov.s $f0, $f2        				# Load the floating-point number into $f0

        li.s $f3, 0.0             			# Load immediate value 0 into $t0



        c.lt.s $f3, $f0	        			# Compare $f0 with 0

        bc1t greater_than_zero   			# Branch if $f0 is greater than 0

	

        li.s $f3, -1.0	          			# Move the value from $t0 to $f1 as a floating-point number

        mul.s $f2, $f2, $f3      			# Multiply $f0 by $f1 (-1)

	

	li $t1, 1

	sw $t1, b0



greater_than_zero:



	sw $t0, flp					#store floating point in memory



int_con:

	beq $t0, 0 cont

	addi $t0, $t0, -1

	

	li.s $f3, 10.0					#f3 = 10.0

	mul.s $f2, $f2, $f3				#to multiply floating point by 10



	j int_con



cont:

	cvt.w.s $f1, $f2				#Convert float to integer(f2 to int and stored in f1)	

	

   	mfc1 $t1, $f1					#Move converted integer to general-purpose register($t1 has full int)



	sw $t1, num

	

	lw $t2, flp



flpart:

	beq $t2, 0 cont1

	addi $t2, $t2, -1

	

	rem $t0, $t1, 10

	div $t1, $t1, 10				

	mul $t3, $t3, 10

	add $t3, $t3, $t0



	j flpart

	

cont1:

	sw $t1, num	



	li $t0, 0

	jal reverse_loop



cont2:

	sw $t0, fln



	li $t0, 2

binary1:

	beq $t1, 0 cont3

	rem $t2, $t1, 2

	div $t1, $t1, 2

	mul $t0, $t0, 10

	add $t0, $t0, $t2

	j binary1



cont3:

	div $t0, $t0, 10

	mul $t0, $t0, 10

	add $t0, $t0, 2	



	move $t3, $t0

	li $t0, 0

	jal reverse_loop	



	sw $t0, b1



	li $t0, 6

	lw $t1, fln

	li $t3, 2



binary2:

	beq $t0, 0 cont4

	addi $t0, $t0, -1



	mul $t1, $t1, 2

	

	lw $t4, flp

	move $t5, $t1

	check:

		div $t5, $t5, 10

		addi $t4, $t4, -1

		bne $t4, 0 check

	mul $t3, $t3, 10

	add $t3, $t3, $t5



	beq $t5, 1 sub1

	j binary2



cont4:

	mul $t3, $t3, 10

	addi $t3, $t3, 2

	

	sw $t3, b2



	lw $t0, b1



	div $t0, $t0, 10

	li $t1, 1



intcount:

	beq $t0, 0 cont5	

	div $t0, $t0, 10

	addi $t1, $t1, 1



	j intcount



cont5:

	addi $t1, $t1, -3

	sw $t1, cnum



	li $t0, 2

binary3:

	beq $t1, 0 cont6

	rem $t2, $t1, 2

	div $t1, $t1, 2

	mul $t0, $t0, 10

	add $t0, $t0, $t2

	j binary3	

	

cont6:	

	move $t3, $t0



	li $t0, 0

	jal reverse_loop

	

	div $t0, $t0, 10

	li $t1, 10000000

	add $t0, $t0, $t1

	

	sw $t0, b3

	

	#Print Sign and Exponent

	li $v0, 4

	la $a0, msg4					#print string 3

	syscall



	lw $t1, b0

	

	li $v0, 1					

    	move $a0, $t1					#Print the integer value

    	syscall



	li $v0, 1					

    	move $a0, $t0					#Print the integer value

    	syscall



	#Print int

	lw $t3, b1

	

	li $t0, 0

	jal reverse_loop



	li $v0, 4

	la $a0, msg5					#print string 3

	syscall

	

	div $t0, $t0, 10



loop1:

	beq $t0, 2 cont7

	rem $t1, $t0, 10

	div $t0, $t0, 10

	

	li $v0, 1					

    	move $a0, $t1					#Print the integer value

    	syscall		

	

	j loop1



cont7:	

	#Print float

	li $v0, 4

	la $a0, msg5					#print string 3

	syscall



	lw $t3, b2



	li $t0, 0

	jal reverse_loop



	div $t0, $t0, 10



	loop2:

		beq $t0,2 cont8

		rem $t1, $t0, 10

		div $t0, $t0, 10



		li $v0, 1					

    		move $a0, $t1				#Print the integer value

    		syscall		

	

		j loop2



cont8:

	li $v0, 10					#exit program

	syscall







#FUNTION ZONE

sub1:

	li $t7, 1

	lw $t6, flp

	loop:

		addi $t6, $t6, -1

		mul $t7, $t7, 10

		bnez $t6, loop



	sub $t1, $t1, $t7



	j binary2





reverse_loop:						#t3-number to reverse, $t0- output

	beq $t3, 0 conti

	

	rem $t2, $t3, 10

	div $t3, $t3, 10				

	mul $t0, $t0, 10

	add $t0, $t0, $t2



    	j reverse_loop   

conti: 

	jr $ra