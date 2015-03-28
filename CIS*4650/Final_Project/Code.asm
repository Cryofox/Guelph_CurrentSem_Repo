func:
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,4($sp) #t6
#=====//
main:
#  &  //
	lw $t0,4($sp) #x
	sw $t0,8($sp) #t12
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,12($sp) #t13
#=====//
#  Assignment //
	lw $t0,12($sp) #t13
	sw $t0,8($sp) #t12
	sw $t0,4($sp) #x
#=====//
Label_t15:
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4($sp) #x
	syscall
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,24($sp) #t21
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,28($sp) #t25
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,32($sp) #t27
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,36($sp) #t28
#=====//
#  Arithmet / Relation  //
	lw $t0,32($sp) #t27
	lw $t1,36($sp) #t27
	add $t0,$t0,$t1 #
	sw $t0,40($sp) #t26
#=====//
#  Assignment //
	lw $t0,40($sp) #t26
	sw $t0,28($sp) #t25
	sw $t0,4($sp) #x
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,44($sp) #t31
#=====//
#  Literal Int/Char  //
	li $t0,10 #10
	sw $t0,48($sp) #t32
#=====//
#  Arithmet / Relation  //
	lw $t0,44($sp) #t31
	lw $t1,48($sp) #t31
	slt $t0, $t0, $t1
	sw $t0,52($sp) #t30
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,56($sp) #t34
#=====//
#  Literal Int/Char  //
	li $t0,20 #20
	sw $t0,60($sp) #t35
#=====//
#  Arithmet / Relation  //
	lw $t0,56($sp) #t34
	lw $t1,60($sp) #t34
	slt $t0, $t0, $t1
	sw $t0,64($sp) #t33
#=====//
#  Arithmet / Relation  //
	lw $t0,52($sp) #t30
	lw $t1,64($sp) #t30
	and $t0,$t0,$t1 #
	sw $t0,68($sp) #t29
#=====//
#  Arithmet / Relation  //
	lw $t0,68($sp) #t29
	li $t1,0 #t29
	bne $t0, $t1, Label_t15
	sw $t0,72($sp) #t36
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,76($sp) #t39
#=====//
arithmetic_Float:
#  &  //
	l.s $f1,4($sp) #f
	s.s $f1,8($sp) #t45
#=====//
#  Literal Float  //
	li.s $f1,4.50000 #4.50000
	s.s $f1,12($sp) #t46
#=====//
#  Assignment //
	l.s $f1,12($sp) #t46
	s.s $f1,8($sp) #t45
	s.s $f1,4($sp) #f
#=====//
#  &  //
	l.s $f1,4($sp) #f
	s.s $f1,16($sp) #t49
#=====//
#  Literal Float  //
	li.s $f1,4.50000 #4.50000
	s.s $f1,20($sp) #t51
#=====//
#  Literal Float  //
	li.s $f1,1.00000 #1.00000
	s.s $f1,24($sp) #t52
#=====//
#  Arithmet / Relation  //
	l.s $f1,20($sp) #t51
	l.s $f2,24($sp) #t51
	add.s $f1,$f1,$f2 #
	s.s $f1,28($sp) #t50
#=====//
#  Assignment //
	l.s $f1,28($sp) #t50
	s.s $f1,16($sp) #t49
	s.s $f1,4($sp) #f
#=====//
#  SysCall Put_I //
	li $v0,2 #
	l.s $f12,4($sp) #f
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,40($sp) #t58
#=====//
arithmetic_Int:
#  &  //
	lw $t0,4($sp) #x
	sw $t0,16($sp) #t63
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,20($sp) #t64
#=====//
#  Assignment //
	lw $t0,20($sp) #t64
	sw $t0,16($sp) #t63
	sw $t0,4($sp) #x
#=====//
#  &  //
	lw $t0,8($sp) #y
	sw $t0,24($sp) #t67
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,28($sp) #t68
#=====//
#  Assignment //
	lw $t0,28($sp) #t68
	sw $t0,24($sp) #t67
	sw $t0,8($sp) #y
#=====//
#  &  //
	lw $t0,12($sp) #z
	sw $t0,32($sp) #t71
#=====//
#  &  //
	lw $t0,8($sp) #y
	sw $t0,36($sp) #t74
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,40($sp) #t75
#=====//
#  Arithmet / Relation  //
	lw $t0,36($sp) #t74
	lw $t1,40($sp) #t74
	mul $t0,$t0,$t1 #
	sw $t0,44($sp) #t73
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,48($sp) #t76
#=====//
#  Arithmet / Relation  //
	lw $t0,44($sp) #t73
	lw $t1,48($sp) #t73
	add $t0,$t0,$t1 #
	sw $t0,52($sp) #t72
#=====//
#  Assignment //
	lw $t0,52($sp) #t72
	sw $t0,32($sp) #t71
	sw $t0,12($sp) #z
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,12($sp) #z
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,64($sp) #t82
#=====//
	li $v0,10
	syscall
