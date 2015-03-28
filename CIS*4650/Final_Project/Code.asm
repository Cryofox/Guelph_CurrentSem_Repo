func:
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,4($sp) #t6
#=====//
main:
#  &  //
	l.s $f1,4($sp) #f
	s.s $f1,8($sp) #t12
#=====//
#  Literal Float  //
	li.s $f1,4.50000 #4.50000
	s.s $f1,12($sp) #t13
#=====//
#  Assignment //
	l.s $f1,12($sp) #t13
	s.s $f1,8($sp) #t12
	s.s $f1,4($sp) #f
#=====//
#  &  //
	l.s $f1,4($sp) #f
	s.s $f1,16($sp) #t16
#=====//
#  Literal Float  //
	li.s $f1,4.50000 #4.50000
	s.s $f1,20($sp) #t18
#=====//
#  Literal Float  //
	li.s $f1,1.00000 #1.00000
	s.s $f1,24($sp) #t19
#=====//
#  Arithmet / Relation  //
	l.s $f1,20($sp) #t18
	l.s $f2,24($sp) #t18
	add.s $f1,$f1,$f2 #
	s.s $f1,28($sp) #t17
#=====//
#  Assignment //
	l.s $f1,28($sp) #t17
	s.s $f1,16($sp) #t16
	s.s $f1,4($sp) #f
#=====//
#  SysCall Put_I //
	li $v0,2 #
	l.s $f12,4($sp) #f
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,40($sp) #t25
#=====//
arithmetic_Int:
#  &  //
	lw $t0,4($sp) #x
	sw $t0,16($sp) #t30
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,20($sp) #t31
#=====//
#  Assignment //
	lw $t0,20($sp) #t31
	sw $t0,16($sp) #t30
	sw $t0,4($sp) #x
#=====//
#  &  //
	lw $t0,8($sp) #y
	sw $t0,24($sp) #t34
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,28($sp) #t35
#=====//
#  Assignment //
	lw $t0,28($sp) #t35
	sw $t0,24($sp) #t34
	sw $t0,8($sp) #y
#=====//
#  &  //
	lw $t0,12($sp) #z
	sw $t0,32($sp) #t38
#=====//
#  &  //
	lw $t0,8($sp) #y
	sw $t0,36($sp) #t41
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,40($sp) #t42
#=====//
#  Arithmet / Relation  //
	lw $t0,36($sp) #t41
	lw $t1,40($sp) #t41
	mul $t0,$t0,$t1 #
	sw $t0,44($sp) #t40
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,48($sp) #t43
#=====//
#  Arithmet / Relation  //
	lw $t0,44($sp) #t40
	lw $t1,48($sp) #t40
	add $t0,$t0,$t1 #
	sw $t0,52($sp) #t39
#=====//
#  Assignment //
	lw $t0,52($sp) #t39
	sw $t0,32($sp) #t38
	sw $t0,12($sp) #z
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,12($sp) #z
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,64($sp) #t49
#=====//
	li $v0,10
	syscall
