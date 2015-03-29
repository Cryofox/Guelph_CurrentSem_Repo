.data
test: .space 4
testArr: .space 44
dataType: .space 4
cyberSix: .space 4
.text
Test_Global:
#  &  //
	la  $t0,8($sp) #fifty
	sw $t0,12($sp) #t6
#=====//
#  Literal Float  //
	li.s $f1,50.5000 #50.5000
	s.s $f1,16($sp) #t7
#=====//
#  Assignment //
	l.s $f1, 16($sp) #t7
	lw $t1, 12($sp) #t6
	s.s $f1, ($t1) #t6
#=====//
#  &  //
	la $t0,4($sp) #nl
	sw $t0,20($sp) #t10
#=====//
#  Literal Int/Char  //
	li $t0,'n' #'n'
	sw $t0,24($sp) #t11
#=====//
#  Assignment //
	lw $t0, 24($sp) #t11
	lw $t1, 20($sp) #t10
	sw $t0, ($t1) #t10
#=====//
#  &  //
	la $t0,test #test
	sw $t0,28($sp) #t14
#=====//
#  Literal Int/Char  //
	li $t0,67 #67
	sw $t0,32($sp) #t15
#=====//
#  Assignment //
	lw $t0, 32($sp) #t15
	lw $t1, 28($sp) #t14
	sw $t0, ($t1) #t14
#=====//
#  SysCall Put_I //
	li $v0,2 #
	l.s $f12,8($sp) #fifty
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,test #test
	syscall
#=====//
#  SysCall Put_I //
	li $v0,4 #
	lw $a0,4($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,60($sp) #t27
#=====//
# Return Called
	lw $fp, 68($sp)
	add $sp, $sp, 80
	jr $ra
#=====//
ModifyTestArr:
#  Function Call:Test_Global //
	sw $ra, 40($sp)
	sub $sp, $sp, 80
	sw $fp, 68($sp)
	add $fp,$sp, 80
	jal Test_Global
	lw $ra, 40($sp)
#=====//
#  &  //
	la $t0,testArr #testArr
	sw $t0,8($sp) #t36
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,12($sp) #t37
#=====//
#  Arithmet / Relation  //
	lw $t0,12($sp) #t37
	li $t1,4 #t37
	mul $t0,$t0,$t1 #
	sw $t0,16($sp) #t38
#=====//
#  Arithmet / Relation  //
	lw $t0,8($sp) #t36
	lw $t1,16($sp) #t36
	add $t0,$t0,$t1 #
	sw $t0,20($sp) #t35
#=====//
#  Literal Int/Char  //
	li $t0,69 #69
	sw $t0,24($sp) #t39
#=====//
#  Assignment //
	lw $t0, 24($sp) #t39
	lw $t1, 20($sp) #t35
	sw $t0, ($t1) #t35
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,28($sp) #t42
#=====//
# Return Called
	lw $fp, 36($sp)
	add $sp, $sp, 48
	jr $ra
#=====//
main:
#  &  //
	la $t0,test #test
	sw $t0,132($sp) #t47
#=====//
#  Literal Int/Char  //
	li $t0,54 #54
	sw $t0,136($sp) #t48
#=====//
#  Assignment //
	lw $t0, 136($sp) #t48
	lw $t1, 132($sp) #t47
	sw $t0, ($t1) #t47
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,148($sp) #t52
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,152($sp) #t53
#=====//
#  Arithmet / Relation  //
	lw $t0,152($sp) #t53
	lw $t1,148($sp) #t53
	add $t0,$t0,$t1 #
	sw $t0,156($sp) #t51
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,160($sp) #t54
#=====//
#  Assignment //
	lw $t0, 160($sp) #t54
	lw $t1, 156($sp) #t51
	sw $t0, ($t1) #t51
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,172($sp) #t58
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,176($sp) #t59
#=====//
#  Arithmet / Relation  //
	lw $t0,176($sp) #t59
	lw $t1,172($sp) #t59
	add $t0,$t0,$t1 #
	sw $t0,180($sp) #t57
#=====//
#  Literal Float  //
	li.s $f1,24.6539 #24.6539
	s.s $f1,184($sp) #t60
#=====//
#  Assignment //
	l.s $f1, 184($sp) #t60
	lw $t1, 180($sp) #t57
	s.s $f1, ($t1) #t57
#=====//
#  &  //
	la $t0,108($sp) #array
	sw $t0,188($sp) #t64
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,192($sp) #t65
#=====//
#  Arithmet / Relation  //
	lw $t0,192($sp) #t65
	li $t1,4 #t65
	mul $t0,$t0,$t1 #
	sw $t0,196($sp) #t66
#=====//
#  Arithmet / Relation  //
	lw $t0,188($sp) #t64
	lw $t1,196($sp) #t64
	add $t0,$t0,$t1 #
	sw $t0,200($sp) #t63
#=====//
#  Literal Int/Char  //
	li $t0,65 #65
	sw $t0,204($sp) #t67
#=====//
#  Assignment //
	lw $t0, 204($sp) #t67
	lw $t1, 200($sp) #t63
	sw $t0, ($t1) #t63
#=====//
#  &  //
	la $t0,116($sp) #y
	sw $t0,208($sp) #t70
#=====//
#  Literal Int/Char  //
	li $t0,6 #6
	sw $t0,212($sp) #t71
#=====//
#  Assignment //
	lw $t0, 212($sp) #t71
	lw $t1, 208($sp) #t70
	sw $t0, ($t1) #t70
#=====//
#  &  //
	la $t0,112($sp) #x
	sw $t0,216($sp) #t74
#=====//
#  &  //
	la $t0,108($sp) #array
	sw $t0,220($sp) #t76
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,224($sp) #t77
#=====//
#  Arithmet / Relation  //
	lw $t0,224($sp) #t77
	li $t1,4 #t77
	mul $t0,$t0,$t1 #
	sw $t0,228($sp) #t78
#=====//
#  Arithmet / Relation  //
	lw $t0,220($sp) #t76
	lw $t1,228($sp) #t76
	add $t0,$t0,$t1 #
	sw $t0,232($sp) #t75
#=====//
#  Assignment //
	lw $t0, 232($sp) #t75
	lw $t1, 216($sp) #t74
	lw $t0, ($t0) #
	sw $t0, ($t1) #t74
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,112($sp) #x
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,116($sp) #y
	syscall
#=====//
#  &  //
	la $t0,108($sp) #array
	sw $t0,252($sp) #t88
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,256($sp) #t89
#=====//
#  Arithmet / Relation  //
	lw $t0,256($sp) #t89
	li $t1,4 #t89
	mul $t0,$t0,$t1 #
	sw $t0,260($sp) #t90
#=====//
#  Arithmet / Relation  //
	lw $t0,252($sp) #t88
	lw $t1,260($sp) #t88
	add $t0,$t0,$t1 #
	sw $t0,264($sp) #t87
#=====//
#  Assignment //
	lw $t0, 264($sp) #t87
	lw $t1, 264($sp) #t87
	lw $t0, ($t0) #
	sw $t0, 264($sp) #t87
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,264($sp) #t87
	syscall
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,284($sp) #t94
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,288($sp) #t95
#=====//
#  Arithmet / Relation  //
	lw $t0,288($sp) #t95
	lw $t1,284($sp) #t95
	add $t0,$t0,$t1 #
	sw $t0,292($sp) #t93
#=====//
#  Assignment //
	lw $t0, 292($sp) #t93
	lw $t1, 292($sp) #t93
	lw $t0, ($t0) #
	sw $t0, 292($sp) #t93
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,292($sp) #t93
	syscall
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,312($sp) #t99
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,316($sp) #t100
#=====//
#  Arithmet / Relation  //
	lw $t0,316($sp) #t100
	lw $t1,312($sp) #t100
	add $t0,$t0,$t1 #
	sw $t0,320($sp) #t98
#=====//
#  Assignment //
	lw $t0, 320($sp) #t98
	lw $t1, 320($sp) #t98
	lw $t0, ($t0) #
	sw $t0, 320($sp) #t98
#=====//
#  SysCall Put_I //
	li $v0,2 #
	l.s $f12,320($sp) #t98
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,332($sp) #t104
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,336($sp) #t105
#=====//
#  Arithmet / Relation  //
	lw $t0,336($sp) #t105
	lw $t1,332($sp) #t105
	add $t0,$t0,$t1 #
	sw $t0,340($sp) #t103
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,344($sp) #t106
#=====//
#  Assignment //
	lw $t0, 344($sp) #t106
	lw $t1, 340($sp) #t103
	sw $t0, ($t1) #t103
#=====//
#  Function Call:ModifyTestArr //
	sw $ra, 408($sp)
	sub $sp, $sp, 48
	sw $fp, 36($sp)
	add $fp,$sp, 48
	jal ModifyTestArr
	lw $ra, 408($sp)
#=====//
#  &  //
	la $t0,testArr #testArr
	sw $t0,352($sp) #t112
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,356($sp) #t113
#=====//
#  Arithmet / Relation  //
	lw $t0,356($sp) #t113
	li $t1,4 #t113
	mul $t0,$t0,$t1 #
	sw $t0,360($sp) #t114
#=====//
#  Arithmet / Relation  //
	lw $t0,352($sp) #t112
	lw $t1,360($sp) #t112
	add $t0,$t0,$t1 #
	sw $t0,364($sp) #t111
#=====//
#  Assignment //
	lw $t0, 364($sp) #t111
	lw $t1, 364($sp) #t111
	lw $t0, ($t0) #
	sw $t0, 364($sp) #t111
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,364($sp) #t111
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,376($sp) #t118
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,380($sp) #t119
#=====//
#  Arithmet / Relation  //
	lw $t0,380($sp) #t119
	lw $t1,376($sp) #t119
	add $t0,$t0,$t1 #
	sw $t0,384($sp) #t117
#=====//
#  Assignment //
	lw $t0, 384($sp) #t117
	lw $t1, 384($sp) #t117
	lw $t0, ($t0) #
	sw $t0, 384($sp) #t117
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,384($sp) #t117
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,666 #666
	sw $t0,396($sp) #t122
#=====//
# Return Called
	lw $fp, 404($sp)
	add $sp, $sp, 416
	jr $ra
#=====//
	li $v0,10
	syscall
