
main:	
	sw $t0, 4($sp)
	la $t0, 4($sp) #Load address at 4 into 0
	lw $t0, ($t0)  #load Value at 4 into 0
	sw $t0, ($t1)
	li $v0, 10
	syscall
