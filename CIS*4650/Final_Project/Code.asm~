main:
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t5
#=====//
#  = Literal I #
	li $t0,3 #--t6
	sw $t0,20($sp) #t5
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,20($sp) #t9
	syscall
#=====//
#  &  //
	la $t0,8($sp) #y
	sw $t0,8($sp) #t12
#=====//
#  = Literal F #
	li.s $f0,4.500000 #--t13
	s.s $f0,8($sp) #t12
#=====//
#  &  //
	la $t0,12($sp) #v
	sw $t0,12($sp) #t16
#=====//
#  = Literal C #
	li $t0,'c' #--t17
	sw $t0,12($sp) #t16
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #t20
	syscall
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,8($sp) #t23
	syscall
#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t25
#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t29
#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t31
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,20($sp) #t35
	syscall
#=====//
#  &  //
	la $t0,16($sp) #z
	sw $t0,16($sp) #t38
#=====//
#  = Literal I #
	li $t0,6 #--t39
	sw $t0,16($sp) #t38
#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t42
#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t44
#=====//
#  &  //
	la $t0,16($sp) #z
	sw $t0,16($sp) #t45
#=====//
#  *=  //
	lw $t0,36($sp)  #t43
	sw $t0,20($sp)  #t42
		#=====//
#  &  //
	la $t0,20($sp) #x
	sw $t0,20($sp) #t48
#=====//
	li $v0,10
	syscall
