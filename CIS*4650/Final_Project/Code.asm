main:
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t5
#=====//
#  = Literal  #
	li $t0,3 #--t6
	sw $t0,20($sp) #t5
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,20($sp) #t9
	syscall
#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t11
#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t15
#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t17
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,20($sp) #t21
	syscall
#=====//
#  &  //
	la $t0,16($sp) #z
	sw $t0,16($sp) #t24
#=====//
#  = Literal  #
	li $t0,6 #--t25
	sw $t0,16($sp) #t24
#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t28
#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t30
#=====//
#  &  //
	la $t0,16($sp) #z
	sw $t0,16($sp) #t31
#=====//
#  *=  //
	lw $t0,36($sp)  #t29
	sw $t0,20($sp)  #t28
		#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t34
#=====//
	li $v0,10
	syscall
