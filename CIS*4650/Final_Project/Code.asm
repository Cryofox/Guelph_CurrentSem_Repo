main:
#  &  //
	la $t0,84($sp) #array
	sw $t0,96($sp) #t6
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,100($sp) #t7
#=====//
#  Arithmet / Relation  //
	lw $t0,100($sp) #t7
	li $t1,4 #t7
	mul $t0,$t0,$t1 #
	sw $t0,104($sp) #t8
#=====//
#  Arithmet / Relation  //
	lw $t0,96($sp) #t6
	lw $t1,104($sp) #t6
	add $t0,$t0,$t1 #
	sw $t0,108($sp) #t5
#=====//
#  Literal Int/Char  //
	li $t0,65 #65
	sw $t0,112($sp) #t9
#=====//
#  Assignment //
	lw $t0, 112($sp) #t9
	lw $t1, 108($sp) #t5
	sw $t0, ($t1) #t5
#=====//
#  &  //
	la $t0,92($sp) #y
	sw $t0,116($sp) #t12
#=====//
#  Literal Int/Char  //
	li $t0,6 #6
	sw $t0,120($sp) #t13
#=====//
#  Assignment //
	lw $t0, 120($sp) #t13
	lw $t1, 116($sp) #t12
	sw $t0, ($t1) #t12
#=====//
#  &  //
	la $t0,88($sp) #x
	sw $t0,124($sp) #t16
#=====//
#  &  //
	la $t0,84($sp) #array
	sw $t0,128($sp) #t18
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,132($sp) #t19
#=====//
#  Arithmet / Relation  //
	lw $t0,132($sp) #t19
	li $t1,4 #t19
	mul $t0,$t0,$t1 #
	sw $t0,136($sp) #t20
#=====//
#  Arithmet / Relation  //
	lw $t0,128($sp) #t18
	lw $t1,136($sp) #t18
	add $t0,$t0,$t1 #
	sw $t0,140($sp) #t17
#=====//
#  Assignment //
	lw $t0, 140($sp) #t17
	lw $t1, 124($sp) #t16
	lw $t0, ($t0) #
	sw $t0, ($t1) #t16
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,88($sp) #x
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,92($sp) #y
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,160($sp) #t29
#=====//
# Return Called
	lw $fp, 168($sp)
	add $sp, $sp, 180
	jr $ra
#=====//
	li $v0,10
	syscall
