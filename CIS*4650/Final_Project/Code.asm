.data
test: .space 4
testArr: .space 44
floatTest: .space 4
dataType: .space 4
cyberSix: .space 4
.text
test_CharPrint:
#  &  //
	la $t0,4($sp) #c
	sw $t0,20($sp) #t6
#=====//
#  Literal Int/Char  //
	li $t0,'c' #'c'
	sw $t0,24($sp) #t7
#=====//
#  Assignment //
	lw $t0, 24($sp) #t7
	lw $t1, 20($sp) #t6
	sw $t0, ($t1) #t6
#=====//
#  &  //
	la $t0,8($sp) #a
	sw $t0,28($sp) #t10
#=====//
#  Literal Int/Char  //
	li $t0,'a' #'a'
	sw $t0,32($sp) #t11
#=====//
#  Assignment //
	lw $t0, 32($sp) #t11
	lw $t1, 28($sp) #t10
	sw $t0, ($t1) #t10
#=====//
#  &  //
	la $t0,12($sp) #t
	sw $t0,36($sp) #t14
#=====//
#  Literal Int/Char  //
	li $t0,'t' #'t'
	sw $t0,40($sp) #t15
#=====//
#  Assignment //
	lw $t0, 40($sp) #t15
	lw $t1, 36($sp) #t14
	sw $t0, ($t1) #t14
#=====//
#  &  //
	la $t0,16($sp) #nl
	sw $t0,44($sp) #t18
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,48($sp) #t19
#=====//
#  Assignment //
	lw $t0, 48($sp) #t19
	lw $t1, 44($sp) #t18
	sw $t0, ($t1) #t18
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #c
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #a
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #t
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,16($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,'t' #'t'
	sw $t0,84($sp) #t34
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,-666($sp) #'t'
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,92($sp) #t37
#=====//
# Return Called
	lw $fp, 100($sp)
	add $sp, $sp, 112
	jr $ra
#=====//
arithmetic_Int:
#  &  //
	la $t0,4($sp) #x
	sw $t0,16($sp) #t43
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,20($sp) #t44
#=====//
#  Assignment //
	lw $t0, 20($sp) #t44
	lw $t1, 16($sp) #t43
	sw $t0, ($t1) #t43
#=====//
#  &  //
	la $t0,8($sp) #y
	sw $t0,24($sp) #t47
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,28($sp) #t48
#=====//
#  Assignment //
	lw $t0, 28($sp) #t48
	lw $t1, 24($sp) #t47
	sw $t0, ($t1) #t47
#=====//
#  &  //
	la $t0,12($sp) #z
	sw $t0,32($sp) #t51
#=====//
#  &  //
	la $t0,8($sp) #y
	sw $t0,36($sp) #t54
#=====//
#  &  //
	la $t0,4($sp) #x
	sw $t0,40($sp) #t55
#=====//
#  Arithmet / Relation  //
	lw $t0,36($sp) #t54
	lw $t1,40($sp) #t54
	mul $t0,$t0,$t1 #
	sw $t0,44($sp) #t53
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,48($sp) #t56
#=====//
#  Arithmet / Relation  //
	lw $t0,44($sp) #t53
	lw $t1,48($sp) #t53
	add $t0,$t0,$t1 #
	sw $t0,52($sp) #t52
#=====//
#  Assignment //
	lw $t0, 52($sp) #t52
	lw $t1, 32($sp) #t51
	lw $t0, ($t0) #
	sw $t0, ($t1) #t51
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,12($sp) #z
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,64($sp) #t62
#=====//
# Return Called
	lw $fp, 72($sp)
	add $sp, $sp, 84
	jr $ra
#=====//
Test_Global:
#  &  //
	la  $t0,8($sp) #fifty
	sw $t0,12($sp) #t68
#=====//
#  Literal Float  //
	li.s $f1,50.5000 #50.5000
	s.s $f1,16($sp) #t69
#=====//
#  Assignment //
	l.s $f1, 16($sp) #t69
	lw $t1, 12($sp) #t68
	s.s $f1, ($t1) #t68
#=====//
#  &  //
	la $t0,4($sp) #nl
	sw $t0,20($sp) #t72
#=====//
#  Literal Int/Char  //
	li $t0,'n' #'n'
	sw $t0,24($sp) #t73
#=====//
#  Assignment //
	lw $t0, 24($sp) #t73
	lw $t1, 20($sp) #t72
	sw $t0, ($t1) #t72
#=====//
#  &  //
	la $t0,test #test
	sw $t0,28($sp) #t76
#=====//
#  Literal Int/Char  //
	li $t0,67 #67
	sw $t0,32($sp) #t77
#=====//
#  Assignment //
	lw $t0, 32($sp) #t77
	lw $t1, 28($sp) #t76
	sw $t0, ($t1) #t76
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,8($sp) #fifty
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,test #test
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,60($sp) #t89
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
	sw $t0,8($sp) #t98
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,12($sp) #t99
#=====//
#  Arithmet / Relation  //
	lw $t0,12($sp) #t99
	li $t1,4 #t99
	mul $t0,$t0,$t1 #
	sw $t0,16($sp) #t100
#=====//
#  Arithmet / Relation  //
	lw $t0,8($sp) #t98
	lw $t1,16($sp) #t98
	add $t0,$t0,$t1 #
	sw $t0,20($sp) #t97
#=====//
#  Literal Int/Char  //
	li $t0,69 #69
	sw $t0,24($sp) #t101
#=====//
#  Assignment //
	lw $t0, 24($sp) #t101
	lw $t1, 20($sp) #t97
	sw $t0, ($t1) #t97
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,28($sp) #t104
#=====//
# Return Called
	lw $fp, 36($sp)
	add $sp, $sp, 48
	jr $ra
#=====//
main:
#  Function Call:test_CharPrint //
	sw $ra, 428($sp)
	sub $sp, $sp, 112
	sw $fp, 100($sp)
	add $fp,$sp, 112
	jal test_CharPrint
	lw $ra, 428($sp)
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,136($sp) #t111
#=====//
#  Literal Float  //
	li.s $f1,999.900 #999.900
	s.s $f1,140($sp) #t112
#=====//
#  Assignment //
	l.s $f1, 140($sp) #t112
	lw $t1, 136($sp) #t111
	s.s $f1, ($t1) #t111
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,floatTest #floatTest
	syscall
#=====//
#  &  //
	la $t0,test #test
	sw $t0,152($sp) #t118
#=====//
#  Literal Int/Char  //
	li $t0,54 #54
	sw $t0,156($sp) #t119
#=====//
#  Assignment //
	lw $t0, 156($sp) #t119
	lw $t1, 152($sp) #t118
	sw $t0, ($t1) #t118
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,168($sp) #t123
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,172($sp) #t124
#=====//
#  Arithmet / Relation  //
	lw $t0,172($sp) #t124
	lw $t1,168($sp) #t124
	add $t0,$t0,$t1 #
	sw $t0,176($sp) #t122
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,180($sp) #t125
#=====//
#  Assignment //
	lw $t0, 180($sp) #t125
	lw $t1, 176($sp) #t122
	sw $t0, ($t1) #t122
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,192($sp) #t129
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,196($sp) #t130
#=====//
#  Arithmet / Relation  //
	lw $t0,196($sp) #t130
	lw $t1,192($sp) #t130
	add $t0,$t0,$t1 #
	sw $t0,200($sp) #t128
#=====//
#  Literal Float  //
	li.s $f1,24.6539 #24.6539
	s.s $f1,204($sp) #t131
#=====//
#  Assignment //
	l.s $f1, 204($sp) #t131
	lw $t1, 200($sp) #t128
	s.s $f1, ($t1) #t128
#=====//
#  &  //
	la $t0,108($sp) #array
	sw $t0,208($sp) #t135
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,212($sp) #t136
#=====//
#  Arithmet / Relation  //
	lw $t0,212($sp) #t136
	li $t1,4 #t136
	mul $t0,$t0,$t1 #
	sw $t0,216($sp) #t137
#=====//
#  Arithmet / Relation  //
	lw $t0,208($sp) #t135
	lw $t1,216($sp) #t135
	add $t0,$t0,$t1 #
	sw $t0,220($sp) #t134
#=====//
#  Literal Int/Char  //
	li $t0,65 #65
	sw $t0,224($sp) #t138
#=====//
#  Assignment //
	lw $t0, 224($sp) #t138
	lw $t1, 220($sp) #t134
	sw $t0, ($t1) #t134
#=====//
#  &  //
	la $t0,116($sp) #y
	sw $t0,228($sp) #t141
#=====//
#  Literal Int/Char  //
	li $t0,6 #6
	sw $t0,232($sp) #t142
#=====//
#  Assignment //
	lw $t0, 232($sp) #t142
	lw $t1, 228($sp) #t141
	sw $t0, ($t1) #t141
#=====//
#  &  //
	la $t0,112($sp) #x
	sw $t0,236($sp) #t145
#=====//
#  &  //
	la $t0,108($sp) #array
	sw $t0,240($sp) #t147
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,244($sp) #t148
#=====//
#  Arithmet / Relation  //
	lw $t0,244($sp) #t148
	li $t1,4 #t148
	mul $t0,$t0,$t1 #
	sw $t0,248($sp) #t149
#=====//
#  Arithmet / Relation  //
	lw $t0,240($sp) #t147
	lw $t1,248($sp) #t147
	add $t0,$t0,$t1 #
	sw $t0,252($sp) #t146
#=====//
#  Assignment //
	lw $t0, 252($sp) #t146
	lw $t1, 236($sp) #t145
	lw $t0, ($t0) #
	sw $t0, ($t1) #t145
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
	sw $t0,272($sp) #t159
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,276($sp) #t160
#=====//
#  Arithmet / Relation  //
	lw $t0,276($sp) #t160
	li $t1,4 #t160
	mul $t0,$t0,$t1 #
	sw $t0,280($sp) #t161
#=====//
#  Arithmet / Relation  //
	lw $t0,272($sp) #t159
	lw $t1,280($sp) #t159
	add $t0,$t0,$t1 #
	sw $t0,284($sp) #t158
#=====//
#  Assignment //
	lw $t0, 284($sp) #t158
	lw $t1, 284($sp) #t158
	lw $t0, ($t0) #
	sw $t0, 284($sp) #t158
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,284($sp) #t158
	syscall
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,304($sp) #t165
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,308($sp) #t166
#=====//
#  Arithmet / Relation  //
	lw $t0,308($sp) #t166
	lw $t1,304($sp) #t166
	add $t0,$t0,$t1 #
	sw $t0,312($sp) #t164
#=====//
#  Assignment //
	lw $t0, 312($sp) #t164
	lw $t1, 312($sp) #t164
	lw $t0, ($t0) #
	sw $t0, 312($sp) #t164
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,312($sp) #t164
	syscall
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,332($sp) #t170
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,336($sp) #t171
#=====//
#  Arithmet / Relation  //
	lw $t0,336($sp) #t171
	lw $t1,332($sp) #t171
	add $t0,$t0,$t1 #
	sw $t0,340($sp) #t169
#=====//
#  Assignment //
	lw $t0, 340($sp) #t169
	lw $t1, 340($sp) #t169
	lw $t0, ($t0) #
	sw $t0, 340($sp) #t169
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,340($sp) #t169
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,352($sp) #t175
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,356($sp) #t176
#=====//
#  Arithmet / Relation  //
	lw $t0,356($sp) #t176
	lw $t1,352($sp) #t176
	add $t0,$t0,$t1 #
	sw $t0,360($sp) #t174
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,364($sp) #t177
#=====//
#  Assignment //
	lw $t0, 364($sp) #t177
	lw $t1, 360($sp) #t174
	sw $t0, ($t1) #t174
#=====//
#  Function Call:ModifyTestArr //
	sw $ra, 428($sp)
	sub $sp, $sp, 48
	sw $fp, 36($sp)
	add $fp,$sp, 48
	jal ModifyTestArr
	lw $ra, 428($sp)
#=====//
#  &  //
	la $t0,testArr #testArr
	sw $t0,372($sp) #t183
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,376($sp) #t184
#=====//
#  Arithmet / Relation  //
	lw $t0,376($sp) #t184
	li $t1,4 #t184
	mul $t0,$t0,$t1 #
	sw $t0,380($sp) #t185
#=====//
#  Arithmet / Relation  //
	lw $t0,372($sp) #t183
	lw $t1,380($sp) #t183
	add $t0,$t0,$t1 #
	sw $t0,384($sp) #t182
#=====//
#  Assignment //
	lw $t0, 384($sp) #t182
	lw $t1, 384($sp) #t182
	lw $t0, ($t0) #
	sw $t0, 384($sp) #t182
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,384($sp) #t182
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,396($sp) #t189
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,400($sp) #t190
#=====//
#  Arithmet / Relation  //
	lw $t0,400($sp) #t190
	lw $t1,396($sp) #t190
	add $t0,$t0,$t1 #
	sw $t0,404($sp) #t188
#=====//
#  Assignment //
	lw $t0, 404($sp) #t188
	lw $t1, 404($sp) #t188
	lw $t0, ($t0) #
	sw $t0, 404($sp) #t188
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,404($sp) #t188
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,666 #666
	sw $t0,416($sp) #t193
#=====//
# Return Called
	lw $fp, 424($sp)
	add $sp, $sp, 436
	jr $ra
#=====//
	li $v0,10
	syscall
