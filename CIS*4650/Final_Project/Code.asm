.data
test: .space 4
testArr: .space 44
floatTest: .space 4
dataType: .space 208
cyberSix: .space 208
.text
test_CharPrint:
#  &  //
	la $t0,4($sp) #c
	sw $t0,228($sp) #t6
#=====//
#  Literal Int/Char  //
	li $t0,'c' #'c'
	sw $t0,232($sp) #t7
#=====//
#  Assignment //
	lw $t0, 232($sp) #t7
	lw $t1, 228($sp) #t6
	sw $t0, ($t1) #t6
#=====//
#  &  //
	la $t0,216($sp) #a
	sw $t0,236($sp) #t10
#=====//
#  Literal Int/Char  //
	li $t0,'a' #'a'
	sw $t0,240($sp) #t11
#=====//
#  Assignment //
	lw $t0, 240($sp) #t11
	lw $t1, 236($sp) #t10
	sw $t0, ($t1) #t10
#=====//
#  &  //
	la $t0,220($sp) #t
	sw $t0,244($sp) #t14
#=====//
#  Literal Int/Char  //
	li $t0,'t' #'t'
	sw $t0,248($sp) #t15
#=====//
#  Assignment //
	lw $t0, 248($sp) #t15
	lw $t1, 244($sp) #t14
	sw $t0, ($t1) #t14
#=====//
#  &  //
	la $t0,224($sp) #nl
	sw $t0,252($sp) #t18
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,256($sp) #t19
#=====//
#  Assignment //
	lw $t0, 256($sp) #t19
	lw $t1, 252($sp) #t18
	sw $t0, ($t1) #t18
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #c
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,216($sp) #a
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,220($sp) #t
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,224($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,292($sp) #t34
#=====//
# Return Called
	lw $fp, 300($sp)
	add $sp, $sp, 312
	jr $ra
#=====//
arithmetic_Int:
#  &  //
	la $t0,4($sp) #x
	sw $t0,16($sp) #t40
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,20($sp) #t41
#=====//
#  Assignment //
	lw $t0, 20($sp) #t41
	lw $t1, 16($sp) #t40
	sw $t0, ($t1) #t40
#=====//
#  &  //
	la $t0,8($sp) #y
	sw $t0,24($sp) #t44
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,28($sp) #t45
#=====//
#  Assignment //
	lw $t0, 28($sp) #t45
	lw $t1, 24($sp) #t44
	sw $t0, ($t1) #t44
#=====//
#  &  //
	la $t0,12($sp) #z
	sw $t0,32($sp) #t48
#=====//
#  &  //
	la $t0,8($sp) #y
	sw $t0,36($sp) #t51
#=====//
#  &  //
	la $t0,4($sp) #x
	sw $t0,40($sp) #t52
#=====//
#  Arithmet / Relation  //
	lw $t0,36($sp) #t51
	lw $t1,40($sp) #t51
	mul $t0,$t0,$t1 #
	sw $t0,44($sp) #t50
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,48($sp) #t53
#=====//
#  Arithmet / Relation  //
	lw $t0,44($sp) #t50
	lw $t1,48($sp) #t50
	add $t0,$t0,$t1 #
	sw $t0,52($sp) #t49
#=====//
#  Assignment //
	lw $t0, 52($sp) #t49
	lw $t1, 32($sp) #t48
	lw $t0, ($t0) #
	sw $t0, ($t1) #t48
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,12($sp) #z
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,64($sp) #t59
#=====//
# Return Called
	lw $fp, 72($sp)
	add $sp, $sp, 84
	jr $ra
#=====//
Test_Global:
#  &  //
	la  $t0,8($sp) #fifty
	sw $t0,12($sp) #t65
#=====//
#  Literal Float  //
	li.s $f1,50.5000 #50.5000
	s.s $f1,16($sp) #t66
#=====//
#  Assignment //
	l.s $f1, 16($sp) #t66
	lw $t1, 12($sp) #t65
	s.s $f1, ($t1) #t65
#=====//
#  &  //
	la $t0,4($sp) #nl
	sw $t0,20($sp) #t69
#=====//
#  Literal Int/Char  //
	li $t0,'n' #'n'
	sw $t0,24($sp) #t70
#=====//
#  Assignment //
	lw $t0, 24($sp) #t70
	lw $t1, 20($sp) #t69
	sw $t0, ($t1) #t69
#=====//
#  &  //
	la $t0,test #test
	sw $t0,28($sp) #t73
#=====//
#  Literal Int/Char  //
	li $t0,67 #67
	sw $t0,32($sp) #t74
#=====//
#  Assignment //
	lw $t0, 32($sp) #t74
	lw $t1, 28($sp) #t73
	sw $t0, ($t1) #t73
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
	sw $t0,60($sp) #t86
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
	sw $t0,8($sp) #t95
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,12($sp) #t96
#=====//
#  Arithmet / Relation  //
	lw $t0,12($sp) #t96
	li $t1,4 #t96
	mul $t0,$t0,$t1 #
	sw $t0,16($sp) #t97
#=====//
#  Arithmet / Relation  //
	lw $t0,8($sp) #t95
	lw $t1,16($sp) #t95
	add $t0,$t0,$t1 #
	sw $t0,20($sp) #t94
#=====//
#  Literal Int/Char  //
	li $t0,69 #69
	sw $t0,24($sp) #t98
#=====//
#  Assignment //
	lw $t0, 24($sp) #t98
	lw $t1, 20($sp) #t94
	sw $t0, ($t1) #t94
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,28($sp) #t101
#=====//
# Return Called
	lw $fp, 36($sp)
	add $sp, $sp, 48
	jr $ra
#=====//
RecursiveFunction:
#  &  //
	la $t0,4($sp) #i
	sw $t0,8($sp) #t108
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,12($sp) #t109
#=====//
#  Arithmet / Relation  //
	lw $t0,8($sp) #t108
	lw $t1,12($sp) #t108
	lw $t0, ($t0) #
	ble $t0, $t1, Label_t106
	sw $t0,16($sp) #t107
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4($sp) #i
	syscall
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,28($sp) #t115
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,32($sp) #t119
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,36($sp) #t121
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,40($sp) #t122
#=====//
#  Arithmet / Relation  //
	lw $t0,36($sp) #t121
	lw $t1,40($sp) #t121
	sub $t0,$t0,$t1 #
	sw $t0,44($sp) #t120
#=====//
#  Assignment //
	lw $t0, 44($sp) #t120
	lw $t1, 32($sp) #t119
	lw $t0, ($t0) #
	sw $t0, ($t1) #t119
#=====//
#  Function Call:RecursiveFunction //
	sw $ra, 68($sp)
	lw $t0, 4($sp)
	sub $sp, $sp, 76
	la $t1, 4($sp)
	add $sp, $sp, 76
	sw $t0, ($t1)
	sub $sp, $sp, 76
	sw $fp, 64($sp)
	add $fp,$sp, 76
	jal RecursiveFunction
	lw $ra, 68($sp)
#=====//
Label_t106:
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,56($sp) #t128
#=====//
# Return Called
	lw $fp, 64($sp)
	add $sp, $sp, 76
	jr $ra
#=====//
main:
#  &  //
	la $t0,116($sp) #y
	sw $t0,132($sp) #t133
#=====//
#  Literal Int/Char  //
	li $t0,6 #6
	sw $t0,136($sp) #t134
#=====//
#  Assignment //
	lw $t0, 136($sp) #t134
	lw $t1, 132($sp) #t133
	sw $t0, ($t1) #t133
#=====//
#  &  //
	la $t0,116($sp) #y
	sw $t0,140($sp) #t137
#=====//
#  &  //
	la $t0,116($sp) #y
	sw $t0,144($sp) #t139
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,148($sp) #t140
#=====//
#  Arithmet / Relation  //
	lw $t0,144($sp) #t139
	lw $t1,148($sp) #t139
	add $t0,$t0,$t1 #
	sw $t0,152($sp) #t138
#=====//
#  Assignment //
	lw $t0, 152($sp) #t138
	lw $t1, 140($sp) #t137
	lw $t0, ($t0) #
	sw $t0, ($t1) #t137
#=====//
#  Function Call:RecursiveFunction //
	sw $ra, 860($sp)
	lw $t0, 116($sp)
	sub $sp, $sp, 76
	la $t1, 4($sp)
	add $sp, $sp, 76
	sw $t0, ($t1)
	sub $sp, $sp, 76
	sw $fp, 64($sp)
	add $fp,$sp, 76
	jal RecursiveFunction
	lw $ra, 860($sp)
#=====//
#  Function Call:test_CharPrint //
	sw $ra, 860($sp)
	sub $sp, $sp, 312
	sw $fp, 300($sp)
	add $fp,$sp, 312
	jal test_CharPrint
	lw $ra, 860($sp)
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,168($sp) #t148
#=====//
#  Literal Float  //
	li.s $f1,999.900 #999.900
	s.s $f1,172($sp) #t149
#=====//
#  Assignment //
	l.s $f1, 172($sp) #t149
	lw $t1, 168($sp) #t148
	s.s $f1, ($t1) #t148
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,floatTest #floatTest
	syscall
#=====//
#  &  //
	la $t0,test #test
	sw $t0,184($sp) #t155
#=====//
#  Literal Int/Char  //
	li $t0,54 #54
	sw $t0,188($sp) #t156
#=====//
#  Assignment //
	lw $t0, 188($sp) #t156
	lw $t1, 184($sp) #t155
	sw $t0, ($t1) #t155
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,200($sp) #t160
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,204($sp) #t161
#=====//
#  Arithmet / Relation  //
	lw $t0,204($sp) #t161
	lw $t1,200($sp) #t161
	add $t0,$t0,$t1 #
	sw $t0,208($sp) #t159
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,212($sp) #t162
#=====//
#  Assignment //
	lw $t0, 212($sp) #t162
	lw $t1, 208($sp) #t159
	sw $t0, ($t1) #t159
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,224($sp) #t166
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,228($sp) #t167
#=====//
#  Arithmet / Relation  //
	lw $t0,228($sp) #t167
	lw $t1,224($sp) #t167
	add $t0,$t0,$t1 #
	sw $t0,232($sp) #t165
#=====//
#  Literal Float  //
	li.s $f1,24.6539 #24.6539
	s.s $f1,236($sp) #t168
#=====//
#  Assignment //
	l.s $f1, 236($sp) #t168
	lw $t1, 232($sp) #t165
	s.s $f1, ($t1) #t165
#=====//
#  &  //
	la $t0,108($sp) #array
	sw $t0,240($sp) #t172
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,244($sp) #t173
#=====//
#  Arithmet / Relation  //
	lw $t0,244($sp) #t173
	li $t1,4 #t173
	mul $t0,$t0,$t1 #
	sw $t0,248($sp) #t174
#=====//
#  Arithmet / Relation  //
	lw $t0,240($sp) #t172
	lw $t1,248($sp) #t172
	add $t0,$t0,$t1 #
	sw $t0,252($sp) #t171
#=====//
#  Literal Int/Char  //
	li $t0,65 #65
	sw $t0,256($sp) #t175
#=====//
#  Assignment //
	lw $t0, 256($sp) #t175
	lw $t1, 252($sp) #t171
	sw $t0, ($t1) #t171
#=====//
#  &  //
	la $t0,112($sp) #x
	sw $t0,260($sp) #t178
#=====//
#  &  //
	la $t0,108($sp) #array
	sw $t0,264($sp) #t180
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,268($sp) #t181
#=====//
#  Arithmet / Relation  //
	lw $t0,268($sp) #t181
	li $t1,4 #t181
	mul $t0,$t0,$t1 #
	sw $t0,272($sp) #t182
#=====//
#  Arithmet / Relation  //
	lw $t0,264($sp) #t180
	lw $t1,272($sp) #t180
	add $t0,$t0,$t1 #
	sw $t0,276($sp) #t179
#=====//
#  Assignment //
	lw $t0, 276($sp) #t179
	lw $t1, 260($sp) #t178
	lw $t0, ($t0) #
	sw $t0, ($t1) #t178
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
	sw $t0,296($sp) #t192
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,300($sp) #t193
#=====//
#  Arithmet / Relation  //
	lw $t0,300($sp) #t193
	li $t1,4 #t193
	mul $t0,$t0,$t1 #
	sw $t0,304($sp) #t194
#=====//
#  Arithmet / Relation  //
	lw $t0,296($sp) #t192
	lw $t1,304($sp) #t192
	add $t0,$t0,$t1 #
	sw $t0,308($sp) #t191
#=====//
#  Assignment //
	lw $t0, 308($sp) #t191
	lw $t1, 308($sp) #t191
	lw $t0, ($t0) #
	sw $t0, 308($sp) #t191
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,308($sp) #t191
	syscall
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,328($sp) #t198
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,332($sp) #t199
#=====//
#  Arithmet / Relation  //
	lw $t0,332($sp) #t199
	lw $t1,328($sp) #t199
	add $t0,$t0,$t1 #
	sw $t0,336($sp) #t197
#=====//
#  Assignment //
	lw $t0, 336($sp) #t197
	lw $t1, 336($sp) #t197
	lw $t0, ($t0) #
	sw $t0, 336($sp) #t197
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,336($sp) #t197
	syscall
#=====//
#  &  //
	la $t0,128($sp) #myTestStruct
	sw $t0,356($sp) #t203
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,360($sp) #t204
#=====//
#  Arithmet / Relation  //
	lw $t0,360($sp) #t204
	lw $t1,356($sp) #t204
	add $t0,$t0,$t1 #
	sw $t0,364($sp) #t202
#=====//
#  Assignment //
	lw $t0, 364($sp) #t202
	lw $t1, 364($sp) #t202
	lw $t0, ($t0) #
	sw $t0, 364($sp) #t202
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,364($sp) #t202
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,580($sp) #t208
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,584($sp) #t209
#=====//
#  Arithmet / Relation  //
	lw $t0,584($sp) #t209
	lw $t1,580($sp) #t209
	add $t0,$t0,$t1 #
	sw $t0,588($sp) #t207
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,592($sp) #t210
#=====//
#  Assignment //
	lw $t0, 592($sp) #t210
	lw $t1, 588($sp) #t207
	sw $t0, ($t1) #t207
#=====//
#  Function Call:ModifyTestArr //
	sw $ra, 860($sp)
	sub $sp, $sp, 48
	sw $fp, 36($sp)
	add $fp,$sp, 48
	jal ModifyTestArr
	lw $ra, 860($sp)
#=====//
#  &  //
	la $t0,testArr #testArr
	sw $t0,600($sp) #t216
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,604($sp) #t217
#=====//
#  Arithmet / Relation  //
	lw $t0,604($sp) #t217
	li $t1,4 #t217
	mul $t0,$t0,$t1 #
	sw $t0,608($sp) #t218
#=====//
#  Arithmet / Relation  //
	lw $t0,600($sp) #t216
	lw $t1,608($sp) #t216
	add $t0,$t0,$t1 #
	sw $t0,612($sp) #t215
#=====//
#  Assignment //
	lw $t0, 612($sp) #t215
	lw $t1, 612($sp) #t215
	lw $t0, ($t0) #
	sw $t0, 612($sp) #t215
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,612($sp) #t215
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,828($sp) #t222
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,832($sp) #t223
#=====//
#  Arithmet / Relation  //
	lw $t0,832($sp) #t223
	lw $t1,828($sp) #t223
	add $t0,$t0,$t1 #
	sw $t0,836($sp) #t221
#=====//
#  Assignment //
	lw $t0, 836($sp) #t221
	lw $t1, 836($sp) #t221
	lw $t0, ($t0) #
	sw $t0, 836($sp) #t221
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,836($sp) #t221
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,666 #666
	sw $t0,848($sp) #t226
#=====//
# Return Called
	lw $fp, 856($sp)
	add $sp, $sp, 868
	jr $ra
#=====//
	li $v0,10
	syscall
