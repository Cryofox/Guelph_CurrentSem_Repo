.data
test: .space 4
testArr: .space 44
floatTest: .space 4
dataType: .space 212
dataBase: .space 216
cyberSix: .space 212
.text
Pass_StructRef:
#  &  //
	la $t0,232($sp) #eq
	sw $t0,236($sp) #t6
#=====//
#  Literal Int/Char  //
	li $t0,'=' #'='
	sw $t0,240($sp) #t7
#=====//
#  Assignment //
	lw $t0, 240($sp) #t7
	lw $t1, 236($sp) #t6
	sw $t0, ($t1) #t6
#=====//
#  &  //
	la $t0,224($sp) #nl
	sw $t0,244($sp) #t10
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,248($sp) #t11
#=====//
#  Assignment //
	lw $t0, 248($sp) #t11
	lw $t1, 244($sp) #t10
	sw $t0, ($t1) #t10
#=====//
#  &  //
	la $t0,228($sp) #db
	sw $t0,252($sp) #t14
#=====//
#  Literal Int/Char  //
	li $t0,'d' #'d'
	sw $t0,256($sp) #t15
#=====//
#  Assignment //
	lw $t0, 256($sp) #t15
	lw $t1, 252($sp) #t14
	sw $t0, ($t1) #t14
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,224($sp) #nl
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,228($sp) #db
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,232($sp) #eq
	syscall
#=====//
#  &  //
	la $t0,220($sp) #db2
	sw $t0,496($sp) #t28
#=====//
#  Literal Int/Char  //
	li $t0,212 #212
	sw $t0,500($sp) #t29
#=====//
#  Arithmet / Relation  //
	lw $t0,500($sp) #t29
	lw $t1,496($sp) #t29
	add $t0,$t0,$t1 #
	sw $t0,504($sp) #t27
#=====//
#  Assignment //
	lw $t0, 504($sp) #t27
	lw $t1, 504($sp) #t27
	lw $t0, ($t0) #
	sw $t0, 504($sp) #t27
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,504($sp) #t27
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,224($sp) #nl
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #q
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,224($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,540($sp) #t41
#=====//
# Return Called
	lw $fp, 548($sp)
	add $sp, $sp, 560
	jr $ra
#=====//
test_CharPrint:
#  &  //
	la $t0,8($sp) #c
	sw $t0,236($sp) #t47
#=====//
#  Literal Int/Char  //
	li $t0,'c' #'c'
	sw $t0,240($sp) #t48
#=====//
#  Assignment //
	lw $t0, 240($sp) #t48
	lw $t1, 236($sp) #t47
	sw $t0, ($t1) #t47
#=====//
#  &  //
	la $t0,224($sp) #a
	sw $t0,244($sp) #t51
#=====//
#  Literal Int/Char  //
	li $t0,'a' #'a'
	sw $t0,248($sp) #t52
#=====//
#  Assignment //
	lw $t0, 248($sp) #t52
	lw $t1, 244($sp) #t51
	sw $t0, ($t1) #t51
#=====//
#  &  //
	la $t0,228($sp) #t
	sw $t0,252($sp) #t55
#=====//
#  Literal Int/Char  //
	li $t0,'t' #'t'
	sw $t0,256($sp) #t56
#=====//
#  Assignment //
	lw $t0, 256($sp) #t56
	lw $t1, 252($sp) #t55
	sw $t0, ($t1) #t55
#=====//
#  &  //
	la $t0,232($sp) #nl
	sw $t0,260($sp) #t59
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,264($sp) #t60
#=====//
#  Assignment //
	lw $t0, 264($sp) #t60
	lw $t1, 260($sp) #t59
	sw $t0, ($t1) #t59
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #c
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,224($sp) #a
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,228($sp) #t
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,232($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,300($sp) #t75
#=====//
# Return Called
	lw $fp, 308($sp)
	add $sp, $sp, 320
	jr $ra
#=====//
arithmetic_Int:
#  &  //
	la $t0,24($sp) #eq
	sw $t0,28($sp) #t81
#=====//
#  Literal Int/Char  //
	li $t0,'=' #'='
	sw $t0,32($sp) #t82
#=====//
#  Assignment //
	lw $t0, 32($sp) #t82
	lw $t1, 28($sp) #t81
	sw $t0, ($t1) #t81
#=====//
#  &  //
	la $t0,20($sp) #cz
	sw $t0,36($sp) #t85
#=====//
#  Literal Int/Char  //
	li $t0,'z' #'z'
	sw $t0,40($sp) #t86
#=====//
#  Assignment //
	lw $t0, 40($sp) #t86
	lw $t1, 36($sp) #t85
	sw $t0, ($t1) #t85
#=====//
#  &  //
	la $t0,16($sp) #nl
	sw $t0,44($sp) #t89
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,48($sp) #t90
#=====//
#  Assignment //
	lw $t0, 48($sp) #t90
	lw $t1, 44($sp) #t89
	sw $t0, ($t1) #t89
#=====//
#  Function Call:arithmetic_Float //
	sw $ra, 140($sp)
	sub $sp, $sp, 88
	sw $fp, 76($sp)
	add $fp,$sp, 88
	jal arithmetic_Float
	lw $ra, 140($sp)
#=====//
#  &  //
	la $t0,4($sp) #x
	sw $t0,56($sp) #t95
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,60($sp) #t96
#=====//
#  Assignment //
	lw $t0, 60($sp) #t96
	lw $t1, 56($sp) #t95
	sw $t0, ($t1) #t95
#=====//
#  &  //
	la $t0,8($sp) #y
	sw $t0,64($sp) #t99
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,68($sp) #t100
#=====//
#  Assignment //
	lw $t0, 68($sp) #t100
	lw $t1, 64($sp) #t99
	sw $t0, ($t1) #t99
#=====//
#  &  //
	la $t0,12($sp) #z
	sw $t0,72($sp) #t103
#=====//
#  &  //
	la $t0,8($sp) #y
	sw $t0,76($sp) #t106
#=====//
#  &  //
	la $t0,4($sp) #x
	sw $t0,80($sp) #t107
#=====//
#  Arithmet / Relation  //
	lw $t0,76($sp) #t106
	lw $t1,80($sp) #t106
	lw $t0, ($t0) #LEEEEFT
	lw $t1, ($t1) #RIIIIIIGHT
	mul $t0,$t0,$t1 #
	sw $t0,84($sp) #t105
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,88($sp) #t108
#=====//
#  Arithmet / Relation  //
	lw $t0,84($sp) #t105
	lw $t1,88($sp) #t105
	add $t0,$t0,$t1 #
	sw $t0,92($sp) #t104
#=====//
#  Assignment //
	lw $t0, 92($sp) #t104
	lw $t1, 72($sp) #t103
	sw $t0, ($t1) #t103
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,20($sp) #cz
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,24($sp) #eq
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,12($sp) #z
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,16($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,128($sp) #t123
#=====//
# Return Called
	lw $fp, 136($sp)
	add $sp, $sp, 148
	jr $ra
#=====//
arithmetic_Float:
#  &  //
	la $t0,8($sp) #nl
	sw $t0,12($sp) #t129
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,16($sp) #t130
#=====//
#  Assignment //
	lw $t0, 16($sp) #t130
	lw $t1, 12($sp) #t129
	sw $t0, ($t1) #t129
#=====//
#  &  //
	la  $t0,4($sp) #x
	sw $t0,20($sp) #t133
#=====//
#  Literal Float  //
	li.s $f1,4.50000 #4.50000
	s.s $f1,24($sp) #t134
#=====//
#  Assignment //
	l.s $f1, 24($sp) #t134
	lw $t1, 20($sp) #t133
	s.s $f1, ($t1) #t133
#=====//
#  &  //
	la  $t0,4($sp) #x
	sw $t0,28($sp) #t137
#=====//
#  &  //
	la  $t0,4($sp) #x
	sw $t0,32($sp) #t139
#=====//
#  Literal Float  //
	li.s $f1,1.00000 #1.00000
	s.s $f1,36($sp) #t140
#=====//
#  Arithmet / Relation  //
	l.s $f1,32($sp) #t139
	l.s $f2,36($sp) #t140
	lw $t0,32($sp) #LEEEEFTt139
	l.s $f1, ($t0) #LEEEEFT
	add.s $f1,$f1,$f2 #
	s.s $f1,40($sp) #t138
#=====//
#  Assignment //
	l.s $f1, 40($sp) #t138
	lw $t1, 28($sp) #t137
	s.s $f1, ($t1) #t137
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #nl
	syscall
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,4($sp) #x
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,68($sp) #t152
#=====//
# Return Called
	lw $fp, 76($sp)
	add $sp, $sp, 88
	jr $ra
#=====//
Test_Global:
#  &  //
	la  $t0,8($sp) #fifty
	sw $t0,12($sp) #t158
#=====//
#  Literal Float  //
	li.s $f1,50.5000 #50.5000
	s.s $f1,16($sp) #t159
#=====//
#  Assignment //
	l.s $f1, 16($sp) #t159
	lw $t1, 12($sp) #t158
	s.s $f1, ($t1) #t158
#=====//
#  &  //
	la $t0,4($sp) #nl
	sw $t0,20($sp) #t162
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,24($sp) #t163
#=====//
#  Assignment //
	lw $t0, 24($sp) #t163
	lw $t1, 20($sp) #t162
	sw $t0, ($t1) #t162
#=====//
#  &  //
	la $t0,test #test
	sw $t0,28($sp) #t166
#=====//
#  Literal Int/Char  //
	li $t0,67 #67
	sw $t0,32($sp) #t167
#=====//
#  Assignment //
	lw $t0, 32($sp) #t167
	lw $t1, 28($sp) #t166
	sw $t0, ($t1) #t166
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
	sw $t0,68($sp) #t182
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
	sw $t0,8($sp) #t191
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,12($sp) #t192
#=====//
#  Arithmet / Relation  //
	lw $t0,12($sp) #t192
	li $t1,4 #t192
	mul $t0,$t0,$t1 #
	sw $t0,16($sp) #t193
#=====//
#  Arithmet / Relation  //
	lw $t0,8($sp) #t191
	lw $t1,16($sp) #t191
	add $t0,$t0,$t1 #
	sw $t0,20($sp) #t190
#=====//
#  Literal Int/Char  //
	li $t0,69 #69
	sw $t0,24($sp) #t194
#=====//
#  Assignment //
	lw $t0, 24($sp) #t194
	lw $t1, 20($sp) #t190
	sw $t0, ($t1) #t190
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,28($sp) #t197
#=====//
# Return Called
	lw $fp, 36($sp)
	add $sp, $sp, 48
	jr $ra
#=====//
RecursiveFunction:
#  &  //
	la $t0,8($sp) #nl
	sw $t0,12($sp) #t203
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,16($sp) #t204
#=====//
#  Assignment //
	lw $t0, 16($sp) #t204
	lw $t1, 12($sp) #t203
	sw $t0, ($t1) #t203
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,20($sp) #t208
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,24($sp) #t209
#=====//
#  Arithmet / Relation  //
	lw $t0,20($sp) #t208
	lw $t1,24($sp) #t208
	lw $t0, ($t0) #LEEEEFT
	ble $t0, $t1, Label_t206
	sw $t0,28($sp) #t207
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4($sp) #i
	syscall
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,40($sp) #t215
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,44($sp) #t219
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,48($sp) #t221
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,52($sp) #t222
#=====//
#  Arithmet / Relation  //
	lw $t0,48($sp) #t221
	lw $t1,52($sp) #t221
	lw $t0, ($t0) #LEEEEFT
	sub $t0,$t0,$t1 #
	sw $t0,56($sp) #t220
#=====//
#  Assignment //
	lw $t0, 56($sp) #t220
	lw $t1, 44($sp) #t219
	sw $t0, ($t1) #t219
#=====//
#  Function Call:RecursiveFunction //
	sw $ra, 88($sp)
	lw $t0, 4($sp)
	sub $sp, $sp, 96
	la $t1, 4($sp)
	add $sp, $sp, 96
	sw $t0, ($t1)
	sub $sp, $sp, 96
	sw $fp, 84($sp)
	add $fp,$sp, 96
	jal RecursiveFunction
	lw $ra, 88($sp)
#=====//
Label_t206:
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,76($sp) #t231
#=====//
# Return Called
	lw $fp, 84($sp)
	add $sp, $sp, 96
	jr $ra
#=====//
MutualRecursion_One:
#  &  //
	la $t0,8($sp) #m
	sw $t0,28($sp) #t237
#=====//
#  Literal Int/Char  //
	li $t0,'m' #'m'
	sw $t0,32($sp) #t238
#=====//
#  Assignment //
	lw $t0, 32($sp) #t238
	lw $t1, 28($sp) #t237
	sw $t0, ($t1) #t237
#=====//
#  &  //
	la $t0,12($sp) #r
	sw $t0,36($sp) #t241
#=====//
#  Literal Int/Char  //
	li $t0,'r' #'r'
	sw $t0,40($sp) #t242
#=====//
#  Assignment //
	lw $t0, 40($sp) #t242
	lw $t1, 36($sp) #t241
	sw $t0, ($t1) #t241
#=====//
#  &  //
	la $t0,16($sp) #v
	sw $t0,44($sp) #t245
#=====//
#  Literal Int/Char  //
	li $t0,'1' #'1'
	sw $t0,48($sp) #t246
#=====//
#  Assignment //
	lw $t0, 48($sp) #t246
	lw $t1, 44($sp) #t245
	sw $t0, ($t1) #t245
#=====//
#  &  //
	la $t0,24($sp) #nl
	sw $t0,52($sp) #t249
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,56($sp) #t250
#=====//
#  Assignment //
	lw $t0, 56($sp) #t250
	lw $t1, 52($sp) #t249
	sw $t0, ($t1) #t249
#=====//
#  &  //
	la $t0,20($sp) #space
	sw $t0,60($sp) #t253
#=====//
#  Literal Int/Char  //
	li $t0,' ' #' '
	sw $t0,64($sp) #t254
#=====//
#  Assignment //
	lw $t0, 64($sp) #t254
	lw $t1, 60($sp) #t253
	sw $t0, ($t1) #t253
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,68($sp) #t258
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,72($sp) #t259
#=====//
#  Arithmet / Relation  //
	lw $t0,68($sp) #t258
	lw $t1,72($sp) #t258
	lw $t0, ($t0) #LEEEEFT
	ble $t0, $t1, Label_t256
	sw $t0,76($sp) #t257
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #m
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #r
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,16($sp) #v
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,20($sp) #space
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4($sp) #i
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,24($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,128($sp) #t280
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,132($sp) #t284
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,136($sp) #t286
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,140($sp) #t287
#=====//
#  Arithmet / Relation  //
	lw $t0,136($sp) #t286
	lw $t1,140($sp) #t286
	lw $t0, ($t0) #LEEEEFT
	sub $t0,$t0,$t1 #
	sw $t0,144($sp) #t285
#=====//
#  Assignment //
	lw $t0, 144($sp) #t285
	lw $t1, 132($sp) #t284
	sw $t0, ($t1) #t284
#=====//
#  Function Call:MutualRecursion_Two //
	sw $ra, 168($sp)
	lw $t0, 4($sp)
	sub $sp, $sp, 176
	la $t1, 4($sp)
	add $sp, $sp, 176
	sw $t0, ($t1)
	sub $sp, $sp, 176
	sw $fp, 164($sp)
	add $fp,$sp, 176
	jal MutualRecursion_Two
	lw $ra, 168($sp)
#=====//
Label_t256:
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,156($sp) #t293
#=====//
# Return Called
	lw $fp, 164($sp)
	add $sp, $sp, 176
	jr $ra
#=====//
MutualRecursion_Two:
#  &  //
	la $t0,8($sp) #m
	sw $t0,28($sp) #t299
#=====//
#  Literal Int/Char  //
	li $t0,'m' #'m'
	sw $t0,32($sp) #t300
#=====//
#  Assignment //
	lw $t0, 32($sp) #t300
	lw $t1, 28($sp) #t299
	sw $t0, ($t1) #t299
#=====//
#  &  //
	la $t0,12($sp) #r
	sw $t0,36($sp) #t303
#=====//
#  Literal Int/Char  //
	li $t0,'r' #'r'
	sw $t0,40($sp) #t304
#=====//
#  Assignment //
	lw $t0, 40($sp) #t304
	lw $t1, 36($sp) #t303
	sw $t0, ($t1) #t303
#=====//
#  &  //
	la $t0,16($sp) #v
	sw $t0,44($sp) #t307
#=====//
#  Literal Int/Char  //
	li $t0,'2' #'2'
	sw $t0,48($sp) #t308
#=====//
#  Assignment //
	lw $t0, 48($sp) #t308
	lw $t1, 44($sp) #t307
	sw $t0, ($t1) #t307
#=====//
#  &  //
	la $t0,24($sp) #nl
	sw $t0,52($sp) #t311
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,56($sp) #t312
#=====//
#  Assignment //
	lw $t0, 56($sp) #t312
	lw $t1, 52($sp) #t311
	sw $t0, ($t1) #t311
#=====//
#  &  //
	la $t0,20($sp) #space
	sw $t0,60($sp) #t315
#=====//
#  Literal Int/Char  //
	li $t0,' ' #' '
	sw $t0,64($sp) #t316
#=====//
#  Assignment //
	lw $t0, 64($sp) #t316
	lw $t1, 60($sp) #t315
	sw $t0, ($t1) #t315
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,68($sp) #t320
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,72($sp) #t321
#=====//
#  Arithmet / Relation  //
	lw $t0,68($sp) #t320
	lw $t1,72($sp) #t320
	lw $t0, ($t0) #LEEEEFT
	ble $t0, $t1, Label_t318
	sw $t0,76($sp) #t319
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #m
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #r
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,16($sp) #v
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,20($sp) #space
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4($sp) #i
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,24($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,128($sp) #t342
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,132($sp) #t346
#=====//
#  &  //
	la $t0,4($sp) #i
	sw $t0,136($sp) #t348
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,140($sp) #t349
#=====//
#  Arithmet / Relation  //
	lw $t0,136($sp) #t348
	lw $t1,140($sp) #t348
	lw $t0, ($t0) #LEEEEFT
	sub $t0,$t0,$t1 #
	sw $t0,144($sp) #t347
#=====//
#  Assignment //
	lw $t0, 144($sp) #t347
	lw $t1, 132($sp) #t346
	sw $t0, ($t1) #t346
#=====//
#  Function Call:MutualRecursion_One //
	sw $ra, 168($sp)
	lw $t0, 4($sp)
	sub $sp, $sp, 176
	la $t1, 4($sp)
	add $sp, $sp, 176
	sw $t0, ($t1)
	sub $sp, $sp, 176
	sw $fp, 164($sp)
	add $fp,$sp, 176
	jal MutualRecursion_One
	lw $ra, 168($sp)
#=====//
Label_t318:
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,156($sp) #t355
#=====//
# Return Called
	lw $fp, 164($sp)
	add $sp, $sp, 176
	jr $ra
#=====//
main:
#  Stack Setup:main //
	sub $sp, $sp, 956
	sw $fp, 944($sp)
	add $fp,$sp, 956
#=====//
#  &  //
	la $t0,336($sp) #nl
	sw $t0,360($sp) #t360
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,364($sp) #t361
#=====//
#  Assignment //
	lw $t0, 364($sp) #t361
	lw $t1, 360($sp) #t360
	sw $t0, ($t1) #t360
#=====//
#  &  //
	la $t0,356($sp) #myTestStruct
	sw $t0,376($sp) #t365
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,380($sp) #t366
#=====//
#  Arithmet / Relation  //
	lw $t0,380($sp) #t366
	lw $t1,376($sp) #t366
	add $t0,$t0,$t1 #
	sw $t0,384($sp) #t364
#=====//
#  Literal Float  //
	li.s $f1,4.56700 #4.56700
	s.s $f1,388($sp) #t367
#=====//
#  Assignment //
	l.s $f1, 388($sp) #t367
	lw $t1, 384($sp) #t364
	s.s $f1, ($t1) #t364
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,600($sp) #t371
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,604($sp) #t372
#=====//
#  Arithmet / Relation  //
	lw $t0,604($sp) #t372
	lw $t1,600($sp) #t372
	add $t0,$t0,$t1 #
	sw $t0,608($sp) #t370
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,612($sp) #t373
#=====//
#  Assignment //
	lw $t0, 612($sp) #t373
	lw $t1, 608($sp) #t370
	sw $t0, ($t1) #t370
#=====//
#  &  //
	la $t0,356($sp) #myTestStruct
	sw $t0,624($sp) #t377
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,628($sp) #t378
#=====//
#  Arithmet / Relation  //
	lw $t0,628($sp) #t378
	lw $t1,624($sp) #t378
	add $t0,$t0,$t1 #
	sw $t0,632($sp) #t376
#=====//
#  Assignment //
	lw $t0, 632($sp) #t376
	lw $t1, 632($sp) #t376
	lw $t0, ($t0) #
	sw $t0, 632($sp) #t376
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,632($sp) #t376
	syscall
#=====//
#  &  //
	la $t0,216($sp) #db
	sw $t0,856($sp) #t382
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,860($sp) #t384
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,864($sp) #t386
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,868($sp) #t387
#=====//
#  Arithmet / Relation  //
	lw $t0,868($sp) #t387
	li $t1,4 #t387
	mul $t0,$t0,$t1 #
	sw $t0,872($sp) #t388
#=====//
#  Arithmet / Relation  //
	lw $t0,864($sp) #t386
	lw $t1,872($sp) #t386
	add $t0,$t0,$t1 #
	sw $t0,876($sp) #t385
#=====//
#  Arithmet / Relation  //
	lw $t0,876($sp) #t385
	lw $t1,860($sp) #t385
	add $t0,$t0,$t1 #
	sw $t0,880($sp) #t383
#=====//
#  Arithmet / Relation  //
	lw $t0,880($sp) #t383
	lw $t1,856($sp) #t383
	add $t0,$t0,$t1 #
	sw $t0,884($sp) #t381
#=====//
#  Literal Int/Char  //
	li $t0,2014 #2014
	sw $t0,888($sp) #t389
#=====//
#  Assignment //
	lw $t0, 888($sp) #t389
	lw $t1, 884($sp) #t381
	sw $t0, ($t1) #t381
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,336($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,356($sp) #myTestStruct
	sw $t0,908($sp) #t396
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,912($sp) #t397
#=====//
#  Arithmet / Relation  //
	lw $t0,912($sp) #t397
	lw $t1,908($sp) #t397
	add $t0,$t0,$t1 #
	sw $t0,916($sp) #t395
#=====//
#  Assignment //
	lw $t0, 916($sp) #t395
	lw $t1, 916($sp) #t395
	lw $t0, ($t0) #
	sw $t0, 916($sp) #t395
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,916($sp) #t395
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,336($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,936($sp) #t403
#=====//
# Return Called
	lw $fp, 944($sp)
	add $sp, $sp, 956
	jr $ra
#=====//
	li $v0,10
	syscall
