main:
#  &  //
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
#=====//
#  = Literal F #
	li.s $f0,4.500000 #--t13
	s.s $f0,8($sp) #t12
#=====//
#  &  //
#=====//
#  = Literal C #
	li $t0,'
' #--t17
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
#=====//
#  &  //
#=====//
#  &  //
#=====//
#  +  //
	lw $t0,20($sp) #t31
	li $t1,1 #t32
	add $t0,$t0,$t1 ##=====//
	sw $t0,20($sp) #t29
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,20($sp) #t35
	syscall
#=====//
#  &  //
#=====//
#  = Literal I #
	li $t0,6 #--t39
	sw $t0,16($sp) #t38
#=====//
#  &  //
#=====//
#  &  //
#=====//
#  &  //
#=====//
#  +  //
	lw $t0,20($sp) #t44
	lw $t1,16($sp) #t45
	add $t0,$t0,$t1 ##=====//
#  *=  //
	lw $t0,36($sp)  #t43
	sw $t0,20($sp)  #t42
		#=====//
#  &  //
#=====//
	li $v0,10
	syscall
