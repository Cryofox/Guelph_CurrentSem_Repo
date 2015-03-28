test_CharPrint:
#  &  //
	lw $t0,4($sp) #c
	sw $t0,20($sp) #t6
#=====//
#  Literal Int/Char  //
	li $t0,'c' #'c'
	sw $t0,24($sp) #t7
#=====//
#  Assignment //
	lw $t0,24($sp) #t7
	sw $t0,20($sp) #t6
	sw $t0,4($sp) #c
#=====//
#  &  //
	lw $t0,8($sp) #a
	sw $t0,28($sp) #t10
#=====//
#  Literal Int/Char  //
	li $t0,'a' #'a'
	sw $t0,32($sp) #t11
#=====//
#  Assignment //
	lw $t0,32($sp) #t11
	sw $t0,28($sp) #t10
	sw $t0,8($sp) #a
#=====//
#  &  //
	lw $t0,12($sp) #t
	sw $t0,36($sp) #t14
#=====//
#  Literal Int/Char  //
	li $t0,'t' #'t'
	sw $t0,40($sp) #t15
#=====//
#  Assignment //
	lw $t0,40($sp) #t15
	sw $t0,36($sp) #t14
	sw $t0,12($sp) #t
#=====//
#  &  //
	lw $t0,16($sp) #nl
	sw $t0,44($sp) #t18
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,48($sp) #t19
#=====//
#  Assignment //
	lw $t0,48($sp) #t19
	sw $t0,44($sp) #t18
	sw $t0,16($sp) #nl
#=====//
#  SysCall Put_I //
	li $v0,4 #
	la $a0,4($sp) #c
	syscall
#=====//
#  SysCall Put_I //
	li $v0,4 #
	la $a0,8($sp) #a
	syscall
#=====//
#  SysCall Put_I //
	li $v0,4 #
	la $a0,12($sp) #t
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,76($sp) #t31
#=====//
# Return Called
	lw $fp, 84($sp)
	add $sp, $sp, 96
	jr $ra
#=====//
arithmetic_Int:
#  &  //
	lw $t0,4($sp) #x
	sw $t0,16($sp) #t37
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,20($sp) #t38
#=====//
#  Assignment //
	lw $t0,20($sp) #t38
	sw $t0,16($sp) #t37
	sw $t0,4($sp) #x
#=====//
#  &  //
	lw $t0,8($sp) #y
	sw $t0,24($sp) #t41
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,28($sp) #t42
#=====//
#  Assignment //
	lw $t0,28($sp) #t42
	sw $t0,24($sp) #t41
	sw $t0,8($sp) #y
#=====//
#  &  //
	lw $t0,12($sp) #z
	sw $t0,32($sp) #t45
#=====//
#  &  //
	lw $t0,8($sp) #y
	sw $t0,36($sp) #t48
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,40($sp) #t49
#=====//
#  Arithmet / Relation  //
	lw $t0,36($sp) #t48
	lw $t1,40($sp) #t48
	mul $t0,$t0,$t1 #
	sw $t0,44($sp) #t47
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,48($sp) #t50
#=====//
#  Arithmet / Relation  //
	lw $t0,44($sp) #t47
	lw $t1,48($sp) #t47
	add $t0,$t0,$t1 #
	sw $t0,52($sp) #t46
#=====//
#  Assignment //
	lw $t0,52($sp) #t46
	sw $t0,32($sp) #t45
	sw $t0,12($sp) #z
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,12($sp) #z
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,64($sp) #t56
#=====//
# Return Called
	lw $fp, 72($sp)
	add $sp, $sp, 84
	jr $ra
#=====//
arithmetic_Float:
#  &  //
	l.s $f1,4($sp) #x
	s.s $f1,8($sp) #t62
#=====//
#  Literal Float  //
	li.s $f1,4.50000 #4.50000
	s.s $f1,12($sp) #t63
#=====//
#  Assignment //
	l.s $f1,12($sp) #t63
	s.s $f1,8($sp) #t62
	s.s $f1,4($sp) #x
#=====//
#  &  //
	l.s $f1,4($sp) #x
	s.s $f1,16($sp) #t66
#=====//
#  &  //
	l.s $f1,4($sp) #x
	s.s $f1,20($sp) #t68
#=====//
#  Literal Float  //
	li.s $f1,1.00000 #1.00000
	s.s $f1,24($sp) #t69
#=====//
#  Arithmet / Relation  //
	l.s $f1,20($sp) #t68
	l.s $f2,24($sp) #t68
	add.s $f1,$f1,$f2 #
	s.s $f1,28($sp) #t67
#=====//
#  Assignment //
	l.s $f1,28($sp) #t67
	s.s $f1,16($sp) #t66
	s.s $f1,4($sp) #x
#=====//
#  SysCall Put_I //
	li $v0,2 #
	l.s $f12,4($sp) #x
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,40($sp) #t75
#=====//
# Return Called
	lw $fp, 48($sp)
	add $sp, $sp, 60
	jr $ra
#=====//
main:
#  &  //
	lw $t0,4($sp) #x
	sw $t0,8($sp) #t80
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,12($sp) #t81
#=====//
#  Assignment //
	lw $t0,12($sp) #t81
	sw $t0,8($sp) #t80
	sw $t0,4($sp) #x
#=====//
#  Function Call:test_CharPrint //
	sw $ra, 92($sp)
	sub $sp, $sp, 96
	sw $fp, 84($sp)
	add $fp,$sp, 96
	jal test_CharPrint
	lw $ra, 92($sp)
#=====//
Label_t85:
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4($sp) #x
	syscall
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,28($sp) #t91
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,32($sp) #t95
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,36($sp) #t97
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,40($sp) #t98
#=====//
#  Arithmet / Relation  //
	lw $t0,36($sp) #t97
	lw $t1,40($sp) #t97
	add $t0,$t0,$t1 #
	sw $t0,44($sp) #t96
#=====//
#  Assignment //
	lw $t0,44($sp) #t96
	sw $t0,32($sp) #t95
	sw $t0,4($sp) #x
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,48($sp) #t101
#=====//
#  Literal Int/Char  //
	li $t0,10 #10
	sw $t0,52($sp) #t102
#=====//
#  Arithmet / Relation  //
	lw $t0,48($sp) #t101
	lw $t1,52($sp) #t101
	slt $t0, $t0, $t1
	sw $t0,56($sp) #t100
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,60($sp) #t104
#=====//
#  Literal Int/Char  //
	li $t0,20 #20
	sw $t0,64($sp) #t105
#=====//
#  Arithmet / Relation  //
	lw $t0,60($sp) #t104
	lw $t1,64($sp) #t104
	slt $t0, $t0, $t1
	sw $t0,68($sp) #t103
#=====//
#  Arithmet / Relation  //
	lw $t0,56($sp) #t100
	lw $t1,68($sp) #t100
	and $t0,$t0,$t1 #
	sw $t0,72($sp) #t99
#=====//
#  Arithmet / Relation  //
	lw $t0,72($sp) #t99
	li $t1,0 #t99
	bne $t0, $t1, Label_t85
	sw $t0,76($sp) #t106
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,80($sp) #t109
#=====//
# Return Called
	lw $fp, 88($sp)
	add $sp, $sp, 100
	jr $ra
#=====//
	li $v0,10
	syscall
