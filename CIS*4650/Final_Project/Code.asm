func:
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,4($sp) #t6
#=====//
main:
#  &  //
	lw $t0,4($sp) #x
	sw $t0,16($sp) #t11
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,20($sp) #t12
#=====//
#  Assignment //
	lw $t0,20($sp) #t12
	sw $t0,16($sp) #t11
	sw $t0,4($sp) #x
#=====//
#  &  //
	lw $t0,8($sp) #y
	sw $t0,24($sp) #t15
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,28($sp) #t16
#=====//
#  Assignment //
	lw $t0,28($sp) #t16
	sw $t0,24($sp) #t15
	sw $t0,8($sp) #y
#=====//
#  &  //
	lw $t0,12($sp) #z
	sw $t0,32($sp) #t19
#=====//
#  &  //
	lw $t0,8($sp) #y
	sw $t0,36($sp) #t22
#=====//
#  &  //
	lw $t0,4($sp) #x
	sw $t0,40($sp) #t23
#=====//
#  Arithmet / Relation  //
	lw $t0,36($sp) #t22
	lw $t1,40($sp) #t22
	mul $t0,$t0,$t1 #
	sw $t0,44($sp) #t21
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,48($sp) #t24
#=====//
#  Arithmet / Relation  //
	lw $t0,44($sp) #t21
	lw $t1,48($sp) #t21
	add $t0,$t0,$t1 #
	sw $t0,52($sp) #t20
#=====//
#  Assignment //
	lw $t0,52($sp) #t20
	sw $t0,32($sp) #t19
	sw $t0,12($sp) #z
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,12($sp) #z
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,64($sp) #t30
#=====//
	li $v0,10
	syscall
