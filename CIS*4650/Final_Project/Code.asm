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
	lw $t0, ($t0) #LEEEEFT
	lw $t1, ($t1) #RIIIIIIGHT
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
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #nl
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
	sw $t0,68($sp) #t89
#=====//
# Return Called
	lw $fp, 76($sp)
	add $sp, $sp, 88
	jr $ra
#=====//
ModifyTestArr:
#  Function Call:Test_Global //
	sw $ra, 40($sp)
	sub $sp, $sp, 88
	sw $fp, 76($sp)
	add $fp,$sp, 88
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
RecursiveFunction:
#  &  //
	la $t0,4($sp) #i
	sw $t0,8($sp) #t111
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,12($sp) #t112
#=====//
#  Arithmet / Relation  //
	lw $t0,8($sp) #t111
	lw $t1,12($sp) #t111
	lw $t0, ($t0) #LEEEEFT
	ble $t0, $t1, Label_t109
	sw $t0,16($sp) #t110
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4($sp) #i
	syscall
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,28($sp) #t118
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,32($sp) #t122
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,36($sp) #t124
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,40($sp) #t125
#=====//
#  Arithmet / Relation  //
	lw $t0,36($sp) #t124
	lw $t1,40($sp) #t124
	lw $t0, ($t0) #LEEEEFT
	sub $t0,$t0,$t1 #
	sw $t0,44($sp) #t123
#=====//
#  Assignment //
	lw $t0, 44($sp) #t123
	lw $t1, 32($sp) #t122
	sw $t0, ($t1) #t122
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
Label_t109:
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,56($sp) #t131
#=====//
# Return Called
	lw $fp, 64($sp)
	add $sp, $sp, 76
	jr $ra
#=====//
main:
#  &  //
	la $t0,120($sp) #nl
	sw $t0,136($sp) #t136
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,140($sp) #t137
#=====//
#  Assignment //
	lw $t0, 140($sp) #t137
	lw $t1, 136($sp) #t136
	sw $t0, ($t1) #t136
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,144($sp) #t140
#=====//
#  Literal Float  //
	li.s $f1,999.900 #999.900
	s.s $f1,148($sp) #t141
#=====//
#  Assignment //
	l.s $f1, 148($sp) #t141
	lw $t1, 144($sp) #t140
	s.s $f1, ($t1) #t140
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,152($sp) #t144
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,156($sp) #t146
#=====//
#  Literal Float  //
	li.s $f1,5.40000 #5.40000
	s.s $f1,160($sp) #t147
#=====//
#  Arithmet / Relation  //
	l.s $f1,156($sp) #t146
	l.s $f2,160($sp) #t147
	lw $t0,156($sp) #LEEEEFTt146
	l.s $f1, ($t0) #LEEEEFT
	add.s $f1,$f1,$f2 #
	s.s $f1,164($sp) #t145
#=====//
#  Assignment //
	l.s $f1, 164($sp) #t145
	lw $t1, 152($sp) #t144
	s.s $f1, ($t1) #t144
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,floatTest #floatTest
	syscall
#=====//
#  &  //
	la $t0,test #test
	sw $t0,176($sp) #t153
#=====//
#  Literal Int/Char  //
	li $t0,54 #54
	sw $t0,180($sp) #t154
#=====//
#  Assignment //
	lw $t0, 180($sp) #t154
	lw $t1, 176($sp) #t153
	sw $t0, ($t1) #t153
#=====//
#  &  //
	la $t0,132($sp) #myTestStruct
	sw $t0,192($sp) #t158
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,196($sp) #t159
#=====//
#  Arithmet / Relation  //
	lw $t0,196($sp) #t159
	lw $t1,192($sp) #t159
	add $t0,$t0,$t1 #
	sw $t0,200($sp) #t157
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,204($sp) #t160
#=====//
#  Assignment //
	lw $t0, 204($sp) #t160
	lw $t1, 200($sp) #t157
	sw $t0, ($t1) #t157
#=====//
#  &  //
	la $t0,132($sp) #myTestStruct
	sw $t0,216($sp) #t164
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,220($sp) #t165
#=====//
#  Arithmet / Relation  //
	lw $t0,220($sp) #t165
	lw $t1,216($sp) #t165
	add $t0,$t0,$t1 #
	sw $t0,224($sp) #t163
#=====//
#  Literal Float  //
	li.s $f1,24.6539 #24.6539
	s.s $f1,228($sp) #t166
#=====//
#  Assignment //
	l.s $f1, 228($sp) #t166
	lw $t1, 224($sp) #t163
	s.s $f1, ($t1) #t163
#=====//
#  &  //
	la $t0,108($sp) #array
	sw $t0,232($sp) #t170
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,236($sp) #t171
#=====//
#  Arithmet / Relation  //
	lw $t0,236($sp) #t171
	li $t1,4 #t171
	mul $t0,$t0,$t1 #
	sw $t0,240($sp) #t172
#=====//
#  Arithmet / Relation  //
	lw $t0,232($sp) #t170
	lw $t1,240($sp) #t170
	add $t0,$t0,$t1 #
	sw $t0,244($sp) #t169
#=====//
#  Literal Int/Char  //
	li $t0,65 #65
	sw $t0,248($sp) #t173
#=====//
#  Assignment //
	lw $t0, 248($sp) #t173
	lw $t1, 244($sp) #t169
	sw $t0, ($t1) #t169
#=====//
#  &  //
	la $t0,112($sp) #x
	sw $t0,252($sp) #t176
#=====//
#  &  //
	la $t0,108($sp) #array
	sw $t0,256($sp) #t178
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,260($sp) #t179
#=====//
#  Arithmet / Relation  //
	lw $t0,260($sp) #t179
	li $t1,4 #t179
	mul $t0,$t0,$t1 #
	sw $t0,264($sp) #t180
#=====//
#  Arithmet / Relation  //
	lw $t0,256($sp) #t178
	lw $t1,264($sp) #t178
	add $t0,$t0,$t1 #
	sw $t0,268($sp) #t177
#=====//
#  Assignment //
	lw $t0, 268($sp) #t177
	lw $t1, 252($sp) #t176
	lw $t0, ($t0) #
	sw $t0, ($t1) #t176
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,112($sp) #x
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,120($sp) #nl
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,116($sp) #y
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,120($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,108($sp) #array
	sw $t0,304($sp) #t196
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,308($sp) #t197
#=====//
#  Arithmet / Relation  //
	lw $t0,308($sp) #t197
	li $t1,4 #t197
	mul $t0,$t0,$t1 #
	sw $t0,312($sp) #t198
#=====//
#  Arithmet / Relation  //
	lw $t0,304($sp) #t196
	lw $t1,312($sp) #t196
	add $t0,$t0,$t1 #
	sw $t0,316($sp) #t195
#=====//
#  Assignment //
	lw $t0, 316($sp) #t195
	lw $t1, 316($sp) #t195
	lw $t0, ($t0) #
	sw $t0, 316($sp) #t195
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,316($sp) #t195
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,120($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,132($sp) #myTestStruct
	sw $t0,344($sp) #t205
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,348($sp) #t206
#=====//
#  Arithmet / Relation  //
	lw $t0,348($sp) #t206
	lw $t1,344($sp) #t206
	add $t0,$t0,$t1 #
	sw $t0,352($sp) #t204
#=====//
#  Assignment //
	lw $t0, 352($sp) #t204
	lw $t1, 352($sp) #t204
	lw $t0, ($t0) #
	sw $t0, 352($sp) #t204
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,352($sp) #t204
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,120($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,132($sp) #myTestStruct
	sw $t0,380($sp) #t213
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,384($sp) #t214
#=====//
#  Arithmet / Relation  //
	lw $t0,384($sp) #t214
	lw $t1,380($sp) #t214
	add $t0,$t0,$t1 #
	sw $t0,388($sp) #t212
#=====//
#  Assignment //
	lw $t0, 388($sp) #t212
	lw $t1, 388($sp) #t212
	lw $t0, ($t0) #
	sw $t0, 388($sp) #t212
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,388($sp) #t212
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,120($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,612($sp) #t221
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,616($sp) #t222
#=====//
#  Arithmet / Relation  //
	lw $t0,616($sp) #t222
	lw $t1,612($sp) #t222
	add $t0,$t0,$t1 #
	sw $t0,620($sp) #t220
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,624($sp) #t223
#=====//
#  Assignment //
	lw $t0, 624($sp) #t223
	lw $t1, 620($sp) #t220
	sw $t0, ($t1) #t220
#=====//
#  Function Call:ModifyTestArr //
	sw $ra, 892($sp)
	sub $sp, $sp, 48
	sw $fp, 36($sp)
	add $fp,$sp, 48
	jal ModifyTestArr
	lw $ra, 892($sp)
#=====//
#  &  //
	la $t0,testArr #testArr
	sw $t0,632($sp) #t229
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,636($sp) #t230
#=====//
#  Arithmet / Relation  //
	lw $t0,636($sp) #t230
	li $t1,4 #t230
	mul $t0,$t0,$t1 #
	sw $t0,640($sp) #t231
#=====//
#  Arithmet / Relation  //
	lw $t0,632($sp) #t229
	lw $t1,640($sp) #t229
	add $t0,$t0,$t1 #
	sw $t0,644($sp) #t228
#=====//
#  Assignment //
	lw $t0, 644($sp) #t228
	lw $t1, 644($sp) #t228
	lw $t0, ($t0) #
	sw $t0, 644($sp) #t228
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,644($sp) #t228
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,860($sp) #t235
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,864($sp) #t236
#=====//
#  Arithmet / Relation  //
	lw $t0,864($sp) #t236
	lw $t1,860($sp) #t236
	add $t0,$t0,$t1 #
	sw $t0,868($sp) #t234
#=====//
#  Assignment //
	lw $t0, 868($sp) #t234
	lw $t1, 868($sp) #t234
	lw $t0, ($t0) #
	sw $t0, 868($sp) #t234
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,868($sp) #t234
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,666 #666
	sw $t0,880($sp) #t239
#=====//
# Return Called
	lw $fp, 888($sp)
	add $sp, $sp, 900
	jr $ra
#=====//
	li $v0,10
	syscall
