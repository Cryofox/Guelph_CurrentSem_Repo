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
	la $t0,228($sp) #eq
	sw $t0,232($sp) #t6
#=====//
#  Literal Int/Char  //
	li $t0,'=' #'='
	sw $t0,236($sp) #t7
#=====//
#  Assignment //
	lw $t0, 236($sp) #t7
	lw $t1, 232($sp) #t6
	sw $t0, ($t1) #t6
#=====//
#  &  //
	la $t0,220($sp) #nl
	sw $t0,240($sp) #t10
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,244($sp) #t11
#=====//
#  Assignment //
	lw $t0, 244($sp) #t11
	lw $t1, 240($sp) #t10
	sw $t0, ($t1) #t10
#=====//
#  &  //
	la $t0,224($sp) #db
	sw $t0,248($sp) #t14
#=====//
#  Literal Int/Char  //
	li $t0,'d' #'d'
	sw $t0,252($sp) #t15
#=====//
#  Assignment //
	lw $t0, 252($sp) #t15
	lw $t1, 248($sp) #t14
	sw $t0, ($t1) #t14
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,220($sp) #nl
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,224($sp) #db
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,228($sp) #eq
	syscall
#=====//
#  &  //
	la $t0,4($sp) #db2
	sw $t0,280($sp) #t28
#=====//
#  Literal Int/Char  //
	li $t0,212 #212
	sw $t0,496($sp) #t29
#=====//
#  Arithmet / Relation  //
	lw $t0,496($sp) #t29
	lw $t1,280($sp) #t29
	add $t0,$t0,$t1 #
	sw $t0,500($sp) #t27
#=====//
#  Assignment //
	lw $t0, 500($sp) #t27
	lw $t1, 500($sp) #t27
	lw $t0, ($t0) #
	sw $t0, 500($sp) #t27
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,500($sp) #t27
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,220($sp) #nl
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,0($sp) #q
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,220($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,536($sp) #t41
#=====//
# Return Called
	lw $fp, 548($sp)
	add $sp, $sp, 560
	jr $ra
#=====//
test_CharPrint:
#  &  //
	la $t0,4($sp) #c
	sw $t0,232($sp) #t47
#=====//
#  Literal Int/Char  //
	li $t0,'c' #'c'
	sw $t0,236($sp) #t48
#=====//
#  Assignment //
	lw $t0, 236($sp) #t48
	lw $t1, 232($sp) #t47
	sw $t0, ($t1) #t47
#=====//
#  &  //
	la $t0,220($sp) #a
	sw $t0,240($sp) #t51
#=====//
#  Literal Int/Char  //
	li $t0,'a' #'a'
	sw $t0,244($sp) #t52
#=====//
#  Assignment //
	lw $t0, 244($sp) #t52
	lw $t1, 240($sp) #t51
	sw $t0, ($t1) #t51
#=====//
#  &  //
	la $t0,224($sp) #t
	sw $t0,248($sp) #t55
#=====//
#  Literal Int/Char  //
	li $t0,'t' #'t'
	sw $t0,252($sp) #t56
#=====//
#  Assignment //
	lw $t0, 252($sp) #t56
	lw $t1, 248($sp) #t55
	sw $t0, ($t1) #t55
#=====//
#  &  //
	la $t0,228($sp) #nl
	sw $t0,256($sp) #t59
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,260($sp) #t60
#=====//
#  Assignment //
	lw $t0, 260($sp) #t60
	lw $t1, 256($sp) #t59
	sw $t0, ($t1) #t59
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #c
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,220($sp) #a
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,224($sp) #t
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,228($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,296($sp) #t75
#=====//
# Return Called
	lw $fp, 308($sp)
	add $sp, $sp, 320
	jr $ra
#=====//
arithmetic_Int:
#  &  //
	la $t0,20($sp) #eq
	sw $t0,24($sp) #t81
#=====//
#  Literal Int/Char  //
	li $t0,'=' #'='
	sw $t0,28($sp) #t82
#=====//
#  Assignment //
	lw $t0, 28($sp) #t82
	lw $t1, 24($sp) #t81
	sw $t0, ($t1) #t81
#=====//
#  &  //
	la $t0,16($sp) #cz
	sw $t0,32($sp) #t85
#=====//
#  Literal Int/Char  //
	li $t0,'z' #'z'
	sw $t0,36($sp) #t86
#=====//
#  Assignment //
	lw $t0, 36($sp) #t86
	lw $t1, 32($sp) #t85
	sw $t0, ($t1) #t85
#=====//
#  &  //
	la $t0,12($sp) #nl
	sw $t0,40($sp) #t89
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,44($sp) #t90
#=====//
#  Assignment //
	lw $t0, 44($sp) #t90
	lw $t1, 40($sp) #t89
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
	la $t0,0($sp) #x
	sw $t0,52($sp) #t95
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,56($sp) #t96
#=====//
#  Assignment //
	lw $t0, 56($sp) #t96
	lw $t1, 52($sp) #t95
	sw $t0, ($t1) #t95
#=====//
#  &  //
	la $t0,4($sp) #y
	sw $t0,60($sp) #t99
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,64($sp) #t100
#=====//
#  Assignment //
	lw $t0, 64($sp) #t100
	lw $t1, 60($sp) #t99
	sw $t0, ($t1) #t99
#=====//
#  &  //
	la $t0,8($sp) #z
	sw $t0,68($sp) #t103
#=====//
#  &  //
	la $t0,4($sp) #y
	sw $t0,72($sp) #t106
#=====//
#  &  //
	la $t0,0($sp) #x
	sw $t0,76($sp) #t107
#=====//
#  Arithmet / Relation  //
	lw $t0,72($sp) #t106
	lw $t1,76($sp) #t106
	lw $t0, ($t0) #LEEEEFT
	lw $t1, ($t1) #RIIIIIIGHT
	mul $t0,$t0,$t1 #
	sw $t0,80($sp) #t105
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,84($sp) #t108
#=====//
#  Arithmet / Relation  //
	lw $t0,80($sp) #t105
	lw $t1,84($sp) #t105
	add $t0,$t0,$t1 #
	sw $t0,88($sp) #t104
#=====//
#  Assignment //
	lw $t0, 88($sp) #t104
	lw $t1, 68($sp) #t103
	sw $t0, ($t1) #t103
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,16($sp) #cz
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,20($sp) #eq
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,8($sp) #z
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,124($sp) #t123
#=====//
# Return Called
	lw $fp, 136($sp)
	add $sp, $sp, 148
	jr $ra
#=====//
arithmetic_Float:
#  &  //
	la $t0,4($sp) #nl
	sw $t0,8($sp) #t129
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,12($sp) #t130
#=====//
#  Assignment //
	lw $t0, 12($sp) #t130
	lw $t1, 8($sp) #t129
	sw $t0, ($t1) #t129
#=====//
#  &  //
	la  $t0,0($sp) #x
	sw $t0,16($sp) #t133
#=====//
#  Literal Float  //
	li.s $f1,4.50000 #4.50000
	s.s $f1,20($sp) #t134
#=====//
#  Assignment //
	l.s $f1, 20($sp) #t134
	lw $t1, 16($sp) #t133
	s.s $f1, ($t1) #t133
#=====//
#  &  //
	la  $t0,0($sp) #x
	sw $t0,24($sp) #t137
#=====//
#  &  //
	la  $t0,0($sp) #x
	sw $t0,28($sp) #t139
#=====//
#  Literal Float  //
	li.s $f1,1.00000 #1.00000
	s.s $f1,32($sp) #t140
#=====//
#  Arithmet / Relation  //
	l.s $f1,28($sp) #t139
	l.s $f2,32($sp) #t140
	lw $t0,28($sp) #LEEEEFTt139
	l.s $f1, ($t0) #LEEEEFT
	add.s $f1,$f1,$f2 #
	s.s $f1,36($sp) #t138
#=====//
#  Assignment //
	l.s $f1, 36($sp) #t138
	lw $t1, 24($sp) #t137
	s.s $f1, ($t1) #t137
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #nl
	syscall
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,0($sp) #x
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,64($sp) #t152
#=====//
# Return Called
	lw $fp, 76($sp)
	add $sp, $sp, 88
	jr $ra
#=====//
Test_Global:
#  &  //
	la  $t0,4($sp) #fifty
	sw $t0,8($sp) #t158
#=====//
#  Literal Float  //
	li.s $f1,50.5000 #50.5000
	s.s $f1,12($sp) #t159
#=====//
#  Assignment //
	l.s $f1, 12($sp) #t159
	lw $t1, 8($sp) #t158
	s.s $f1, ($t1) #t158
#=====//
#  &  //
	la $t0,0($sp) #nl
	sw $t0,16($sp) #t162
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,20($sp) #t163
#=====//
#  Assignment //
	lw $t0, 20($sp) #t163
	lw $t1, 16($sp) #t162
	sw $t0, ($t1) #t162
#=====//
#  &  //
	la $t0,test #test
	sw $t0,24($sp) #t166
#=====//
#  Literal Int/Char  //
	li $t0,67 #67
	sw $t0,28($sp) #t167
#=====//
#  Assignment //
	lw $t0, 28($sp) #t167
	lw $t1, 24($sp) #t166
	sw $t0, ($t1) #t166
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,4($sp) #fifty
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,0($sp) #nl
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,test #test
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,0($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,64($sp) #t182
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
	sw $t0,4($sp) #t191
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,8($sp) #t192
#=====//
#  Arithmet / Relation  //
	lw $t0,8($sp) #t192
	li $t1,4 #t192
	mul $t0,$t0,$t1 #
	sw $t0,12($sp) #t193
#=====//
#  Arithmet / Relation  //
	lw $t0,4($sp) #t191
	lw $t1,12($sp) #t191
	add $t0,$t0,$t1 #
	sw $t0,16($sp) #t190
#=====//
#  Literal Int/Char  //
	li $t0,69 #69
	sw $t0,20($sp) #t194
#=====//
#  Assignment //
	lw $t0, 20($sp) #t194
	lw $t1, 16($sp) #t190
	sw $t0, ($t1) #t190
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,24($sp) #t197
#=====//
# Return Called
	lw $fp, 36($sp)
	add $sp, $sp, 48
	jr $ra
#=====//
RecursiveFunction:
#  &  //
	la $t0,4($sp) #nl
	sw $t0,8($sp) #t203
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,12($sp) #t204
#=====//
#  Assignment //
	lw $t0, 12($sp) #t204
	lw $t1, 8($sp) #t203
	sw $t0, ($t1) #t203
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,16($sp) #t208
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,20($sp) #t209
#=====//
#  Arithmet / Relation  //
	lw $t0,16($sp) #t208
	lw $t1,20($sp) #t208
	lw $t0, ($t0) #LEEEEFT
	ble $t0, $t1, Label_t206
	sw $t0,24($sp) #t207
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,0($sp) #i
	syscall
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,36($sp) #t215
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,40($sp) #t219
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,44($sp) #t221
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,48($sp) #t222
#=====//
#  Arithmet / Relation  //
	lw $t0,44($sp) #t221
	lw $t1,48($sp) #t221
	lw $t0, ($t0) #LEEEEFT
	sub $t0,$t0,$t1 #
	sw $t0,52($sp) #t220
#=====//
#  Assignment //
	lw $t0, 52($sp) #t220
	lw $t1, 40($sp) #t219
	sw $t0, ($t1) #t219
#=====//
#  Function Call:RecursiveFunction //
	sw $ra, 88($sp)
	la $t0, 0($sp)
	li  $t2,  0
	add $t0, $t0, $t2
	sub $sp, $sp, 96
	la $t1, 0($sp)
	li  $t2,  0
	add $t1, $t1, $t2
	add $sp, $sp, 96
	lw $t0, ($t0)
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
	la $a0,4($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,72($sp) #t231
#=====//
# Return Called
	lw $fp, 84($sp)
	add $sp, $sp, 96
	jr $ra
#=====//
MutualRecursion_One:
#  &  //
	la $t0,4($sp) #m
	sw $t0,24($sp) #t237
#=====//
#  Literal Int/Char  //
	li $t0,'m' #'m'
	sw $t0,28($sp) #t238
#=====//
#  Assignment //
	lw $t0, 28($sp) #t238
	lw $t1, 24($sp) #t237
	sw $t0, ($t1) #t237
#=====//
#  &  //
	la $t0,8($sp) #r
	sw $t0,32($sp) #t241
#=====//
#  Literal Int/Char  //
	li $t0,'r' #'r'
	sw $t0,36($sp) #t242
#=====//
#  Assignment //
	lw $t0, 36($sp) #t242
	lw $t1, 32($sp) #t241
	sw $t0, ($t1) #t241
#=====//
#  &  //
	la $t0,12($sp) #v
	sw $t0,40($sp) #t245
#=====//
#  Literal Int/Char  //
	li $t0,'1' #'1'
	sw $t0,44($sp) #t246
#=====//
#  Assignment //
	lw $t0, 44($sp) #t246
	lw $t1, 40($sp) #t245
	sw $t0, ($t1) #t245
#=====//
#  &  //
	la $t0,20($sp) #nl
	sw $t0,48($sp) #t249
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,52($sp) #t250
#=====//
#  Assignment //
	lw $t0, 52($sp) #t250
	lw $t1, 48($sp) #t249
	sw $t0, ($t1) #t249
#=====//
#  &  //
	la $t0,16($sp) #space
	sw $t0,56($sp) #t253
#=====//
#  Literal Int/Char  //
	li $t0,' ' #' '
	sw $t0,60($sp) #t254
#=====//
#  Assignment //
	lw $t0, 60($sp) #t254
	lw $t1, 56($sp) #t253
	sw $t0, ($t1) #t253
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,64($sp) #t258
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,68($sp) #t259
#=====//
#  Arithmet / Relation  //
	lw $t0,64($sp) #t258
	lw $t1,68($sp) #t258
	lw $t0, ($t0) #LEEEEFT
	ble $t0, $t1, Label_t256
	sw $t0,72($sp) #t257
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #m
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #r
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #v
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,16($sp) #space
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,0($sp) #i
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,20($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,124($sp) #t280
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,128($sp) #t284
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,132($sp) #t286
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,136($sp) #t287
#=====//
#  Arithmet / Relation  //
	lw $t0,132($sp) #t286
	lw $t1,136($sp) #t286
	lw $t0, ($t0) #LEEEEFT
	sub $t0,$t0,$t1 #
	sw $t0,140($sp) #t285
#=====//
#  Assignment //
	lw $t0, 140($sp) #t285
	lw $t1, 128($sp) #t284
	sw $t0, ($t1) #t284
#=====//
#  Function Call:MutualRecursion_Two //
	sw $ra, 168($sp)
	la $t0, 0($sp)
	li  $t2,  0
	add $t0, $t0, $t2
	sub $sp, $sp, 176
	la $t1, 0($sp)
	li  $t2,  0
	add $t1, $t1, $t2
	add $sp, $sp, 176
	lw $t0, ($t0)
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
	sw $t0,152($sp) #t293
#=====//
# Return Called
	lw $fp, 164($sp)
	add $sp, $sp, 176
	jr $ra
#=====//
MutualRecursion_Two:
#  &  //
	la $t0,4($sp) #m
	sw $t0,24($sp) #t299
#=====//
#  Literal Int/Char  //
	li $t0,'m' #'m'
	sw $t0,28($sp) #t300
#=====//
#  Assignment //
	lw $t0, 28($sp) #t300
	lw $t1, 24($sp) #t299
	sw $t0, ($t1) #t299
#=====//
#  &  //
	la $t0,8($sp) #r
	sw $t0,32($sp) #t303
#=====//
#  Literal Int/Char  //
	li $t0,'r' #'r'
	sw $t0,36($sp) #t304
#=====//
#  Assignment //
	lw $t0, 36($sp) #t304
	lw $t1, 32($sp) #t303
	sw $t0, ($t1) #t303
#=====//
#  &  //
	la $t0,12($sp) #v
	sw $t0,40($sp) #t307
#=====//
#  Literal Int/Char  //
	li $t0,'2' #'2'
	sw $t0,44($sp) #t308
#=====//
#  Assignment //
	lw $t0, 44($sp) #t308
	lw $t1, 40($sp) #t307
	sw $t0, ($t1) #t307
#=====//
#  &  //
	la $t0,20($sp) #nl
	sw $t0,48($sp) #t311
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,52($sp) #t312
#=====//
#  Assignment //
	lw $t0, 52($sp) #t312
	lw $t1, 48($sp) #t311
	sw $t0, ($t1) #t311
#=====//
#  &  //
	la $t0,16($sp) #space
	sw $t0,56($sp) #t315
#=====//
#  Literal Int/Char  //
	li $t0,' ' #' '
	sw $t0,60($sp) #t316
#=====//
#  Assignment //
	lw $t0, 60($sp) #t316
	lw $t1, 56($sp) #t315
	sw $t0, ($t1) #t315
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,64($sp) #t320
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,68($sp) #t321
#=====//
#  Arithmet / Relation  //
	lw $t0,64($sp) #t320
	lw $t1,68($sp) #t320
	lw $t0, ($t0) #LEEEEFT
	ble $t0, $t1, Label_t318
	sw $t0,72($sp) #t319
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #m
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #r
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #v
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,16($sp) #space
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,0($sp) #i
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,20($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,124($sp) #t342
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,128($sp) #t346
#=====//
#  &  //
	la $t0,0($sp) #i
	sw $t0,132($sp) #t348
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,136($sp) #t349
#=====//
#  Arithmet / Relation  //
	lw $t0,132($sp) #t348
	lw $t1,136($sp) #t348
	lw $t0, ($t0) #LEEEEFT
	sub $t0,$t0,$t1 #
	sw $t0,140($sp) #t347
#=====//
#  Assignment //
	lw $t0, 140($sp) #t347
	lw $t1, 128($sp) #t346
	sw $t0, ($t1) #t346
#=====//
#  Function Call:MutualRecursion_One //
	sw $ra, 168($sp)
	la $t0, 0($sp)
	li  $t2,  0
	add $t0, $t0, $t2
	sub $sp, $sp, 176
	la $t1, 0($sp)
	li  $t2,  0
	add $t1, $t1, $t2
	add $sp, $sp, 176
	lw $t0, ($t0)
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
	sw $t0,152($sp) #t355
#=====//
# Return Called
	lw $fp, 164($sp)
	add $sp, $sp, 176
	jr $ra
#=====//
main:
#  Stack Setup:main //
	sub $sp, $sp, 4728
	sw $fp, 4716($sp)
	add $fp,$sp, 4728
#=====//
#  &  //
	la $t0,344($sp) #nl
	sw $t0,356($sp) #t360
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,360($sp) #t361
#=====//
#  Assignment //
	lw $t0, 360($sp) #t361
	lw $t1, 356($sp) #t360
	sw $t0, ($t1) #t360
#=====//
#  &  //
	la $t0,352($sp) #q
	sw $t0,364($sp) #t364
#=====//
#  Literal Int/Char  //
	li $t0,'q' #'q'
	sw $t0,368($sp) #t365
#=====//
#  Assignment //
	lw $t0, 368($sp) #t365
	lw $t1, 364($sp) #t364
	sw $t0, ($t1) #t364
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,372($sp) #t369
#=====//
#  Literal Int/Char  //
	li $t0,212 #212
	sw $t0,588($sp) #t370
#=====//
#  Arithmet / Relation  //
	lw $t0,588($sp) #t370
	lw $t1,372($sp) #t370
	add $t0,$t0,$t1 #
	sw $t0,592($sp) #t368
#=====//
#  Literal Int/Char  //
	li $t0,1337 #1337
	sw $t0,596($sp) #t371
#=====//
#  Assignment //
	lw $t0, 596($sp) #t371
	lw $t1, 592($sp) #t368
	sw $t0, ($t1) #t368
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,600($sp) #t375
#=====//
#  Literal Int/Char  //
	li $t0,212 #212
	sw $t0,816($sp) #t376
#=====//
#  Arithmet / Relation  //
	lw $t0,816($sp) #t376
	lw $t1,600($sp) #t376
	add $t0,$t0,$t1 #
	sw $t0,820($sp) #t374
#=====//
#  Assignment //
	lw $t0, 820($sp) #t374
	lw $t1, 820($sp) #t374
	lw $t0, ($t0) #
	sw $t0, 820($sp) #t374
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,820($sp) #t374
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  Function Call:Pass_StructRef //
	sw $ra, 4720($sp)
	la $t0, 352($sp)
	li  $t2,  0
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 0($sp)
	li  $t2,  0
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  0
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  0
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  4
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  4
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  8
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  8
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  12
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  12
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  16
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  16
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  20
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  20
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  24
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  24
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  28
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  28
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  32
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  32
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  36
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  36
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  40
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  40
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  44
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  44
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  48
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  48
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  52
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  52
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  56
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  56
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  60
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  60
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  64
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  64
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  68
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  68
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  72
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  72
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  76
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  76
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  80
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  80
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  84
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  84
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  88
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  88
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  92
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  92
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  96
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  96
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  100
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  100
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  104
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  104
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  108
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  108
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  112
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  112
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  116
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  116
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  120
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  120
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  124
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  124
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  128
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  128
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  132
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  132
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  136
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  136
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  140
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  140
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  144
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  144
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  148
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  148
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  152
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  152
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  156
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  156
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  160
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  160
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  164
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  164
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  168
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  168
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  172
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  172
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  176
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  176
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  180
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  180
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  184
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  184
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  188
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  188
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  192
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  192
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  196
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  196
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  200
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  200
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  204
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  204
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  208
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  208
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	la $t0, 0($sp)
	li  $t2,  212
	add $t0, $t0, $t2
	sub $sp, $sp, 560
	la $t1, 4($sp)
	li  $t2,  212
	add $t1, $t1, $t2
	add $sp, $sp, 560
	lw $t0, ($t0)
	sw $t0, ($t1)
	sub $sp, $sp, 560
	sw $fp, 548($sp)
	add $fp,$sp, 560
	jal Pass_StructRef
	lw $ra, 4720($sp)
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1064($sp) #t388
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,1280($sp) #t390
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,1284($sp) #t392
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,1288($sp) #t393
#=====//
#  Arithmet / Relation  //
	lw $t0,1288($sp) #t393
	li $t1,4 #t393
	mul $t0,$t0,$t1 #
	sw $t0,1292($sp) #t394
#=====//
#  Arithmet / Relation  //
	lw $t0,1284($sp) #t392
	lw $t1,1292($sp) #t392
	add $t0,$t0,$t1 #
	sw $t0,1296($sp) #t391
#=====//
#  Arithmet / Relation  //
	lw $t0,1296($sp) #t391
	lw $t1,1280($sp) #t391
	add $t0,$t0,$t1 #
	sw $t0,1300($sp) #t389
#=====//
#  Arithmet / Relation  //
	lw $t0,1300($sp) #t389
	lw $t1,1064($sp) #t389
	add $t0,$t0,$t1 #
	sw $t0,1304($sp) #t387
#=====//
#  Literal Int/Char  //
	li $t0,2014 #2014
	sw $t0,1308($sp) #t395
#=====//
#  Assignment //
	lw $t0, 1308($sp) #t395
	lw $t1, 1304($sp) #t387
	sw $t0, ($t1) #t387
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1312($sp) #t399
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,1528($sp) #t401
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,1532($sp) #t403
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,1536($sp) #t404
#=====//
#  Arithmet / Relation  //
	lw $t0,1536($sp) #t404
	li $t1,4 #t404
	mul $t0,$t0,$t1 #
	sw $t0,1540($sp) #t405
#=====//
#  Arithmet / Relation  //
	lw $t0,1532($sp) #t403
	lw $t1,1540($sp) #t403
	add $t0,$t0,$t1 #
	sw $t0,1544($sp) #t402
#=====//
#  Arithmet / Relation  //
	lw $t0,1544($sp) #t402
	lw $t1,1528($sp) #t402
	add $t0,$t0,$t1 #
	sw $t0,1548($sp) #t400
#=====//
#  Arithmet / Relation  //
	lw $t0,1548($sp) #t400
	lw $t1,1312($sp) #t400
	add $t0,$t0,$t1 #
	sw $t0,1552($sp) #t398
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1556($sp) #t408
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,1772($sp) #t410
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,1776($sp) #t412
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,1780($sp) #t413
#=====//
#  Arithmet / Relation  //
	lw $t0,1780($sp) #t413
	li $t1,4 #t413
	mul $t0,$t0,$t1 #
	sw $t0,1784($sp) #t414
#=====//
#  Arithmet / Relation  //
	lw $t0,1776($sp) #t412
	lw $t1,1784($sp) #t412
	add $t0,$t0,$t1 #
	sw $t0,1788($sp) #t411
#=====//
#  Arithmet / Relation  //
	lw $t0,1788($sp) #t411
	lw $t1,1772($sp) #t411
	add $t0,$t0,$t1 #
	sw $t0,1792($sp) #t409
#=====//
#  Arithmet / Relation  //
	lw $t0,1792($sp) #t409
	lw $t1,1556($sp) #t409
	add $t0,$t0,$t1 #
	sw $t0,1796($sp) #t407
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,1800($sp) #t415
#=====//
#  Arithmet / Relation  //
	lw $t0,1796($sp) #t407
	lw $t1,1800($sp) #t407
	lw $t0, ($t0) #LEEEEFT
	mul $t0,$t0,$t1 #
	sw $t0,1804($sp) #t406
#=====//
#  Assignment //
	lw $t0, 1804($sp) #t406
	lw $t1, 1552($sp) #t398
	sw $t0, ($t1) #t398
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1808($sp) #t419
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,2024($sp) #t421
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,2028($sp) #t423
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,2032($sp) #t424
#=====//
#  Arithmet / Relation  //
	lw $t0,2032($sp) #t424
	li $t1,4 #t424
	mul $t0,$t0,$t1 #
	sw $t0,2036($sp) #t425
#=====//
#  Arithmet / Relation  //
	lw $t0,2028($sp) #t423
	lw $t1,2036($sp) #t423
	add $t0,$t0,$t1 #
	sw $t0,2040($sp) #t422
#=====//
#  Arithmet / Relation  //
	lw $t0,2040($sp) #t422
	lw $t1,2024($sp) #t422
	add $t0,$t0,$t1 #
	sw $t0,2044($sp) #t420
#=====//
#  Arithmet / Relation  //
	lw $t0,2044($sp) #t420
	lw $t1,1808($sp) #t420
	add $t0,$t0,$t1 #
	sw $t0,2048($sp) #t418
#=====//
#  Assignment //
	lw $t0, 2048($sp) #t418
	lw $t1, 2048($sp) #t418
	lw $t0, ($t0) #
	sw $t0, 2048($sp) #t418
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,2048($sp) #t418
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,2068($sp) #t431
#=====//
#  Literal Float  //
	li.s $f1,7.90000 #7.90000
	s.s $f1,2072($sp) #t433
#=====//
#  Literal Float  //
	li.s $f1,5.40000 #5.40000
	s.s $f1,2076($sp) #t434
#=====//
#  Arithmet / Relation  //
	l.s $f1,2072($sp) #t433
	l.s $f2,2076($sp) #t434
	add.s $f1,$f1,$f2 #
	s.s $f1,2080($sp) #t432
#=====//
#  Assignment //
	l.s $f1, 2080($sp) #t432
	lw $t1, 2068($sp) #t431
	s.s $f1, ($t1) #t431
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,2084($sp) #t438
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,2296($sp) #t439
#=====//
#  Arithmet / Relation  //
	lw $t0,2296($sp) #t439
	lw $t1,2084($sp) #t439
	add $t0,$t0,$t1 #
	sw $t0,2300($sp) #t437
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,2304($sp) #t440
#=====//
#  Assignment //
	lw $t0, 2304($sp) #t440
	lw $t1, 2300($sp) #t437
	sw $t0, ($t1) #t437
#=====//
#  &  //
	la $t0,344($sp) #nl
	sw $t0,2308($sp) #t443
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,2312($sp) #t444
#=====//
#  Assignment //
	lw $t0, 2312($sp) #t444
	lw $t1, 2308($sp) #t443
	sw $t0, ($t1) #t443
#=====//
#  &  //
	la $t0,test #test
	sw $t0,2316($sp) #t447
#=====//
#  Literal Int/Char  //
	li $t0,54 #54
	sw $t0,2320($sp) #t448
#=====//
#  Assignment //
	lw $t0, 2320($sp) #t448
	lw $t1, 2316($sp) #t447
	sw $t0, ($t1) #t447
#=====//
#  &  //
	la $t0,252($sp) #array
	sw $t0,2324($sp) #t452
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2328($sp) #t453
#=====//
#  Arithmet / Relation  //
	lw $t0,2328($sp) #t453
	li $t1,4 #t453
	mul $t0,$t0,$t1 #
	sw $t0,2332($sp) #t454
#=====//
#  Arithmet / Relation  //
	lw $t0,2324($sp) #t452
	lw $t1,2332($sp) #t452
	add $t0,$t0,$t1 #
	sw $t0,2336($sp) #t451
#=====//
#  Literal Int/Char  //
	li $t0,65 #65
	sw $t0,2340($sp) #t455
#=====//
#  Assignment //
	lw $t0, 2340($sp) #t455
	lw $t1, 2336($sp) #t451
	sw $t0, ($t1) #t451
#=====//
#  Function Call:test_CharPrint //
	sw $ra, 4720($sp)
	sub $sp, $sp, 320
	sw $fp, 308($sp)
	add $fp,$sp, 320
	jal test_CharPrint
	lw $ra, 4720($sp)
#=====//
#  &  //
	la $t0,336($sp) #x
	sw $t0,2348($sp) #t460
#=====//
#  &  //
	la $t0,252($sp) #array
	sw $t0,2352($sp) #t462
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2356($sp) #t463
#=====//
#  Arithmet / Relation  //
	lw $t0,2356($sp) #t463
	li $t1,4 #t463
	mul $t0,$t0,$t1 #
	sw $t0,2360($sp) #t464
#=====//
#  Arithmet / Relation  //
	lw $t0,2352($sp) #t462
	lw $t1,2360($sp) #t462
	add $t0,$t0,$t1 #
	sw $t0,2364($sp) #t461
#=====//
#  Assignment //
	lw $t0, 2364($sp) #t461
	lw $t1, 2348($sp) #t460
	lw $t0, ($t0) #
	sw $t0, ($t1) #t460
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,336($sp) #x
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,340($sp) #y
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,252($sp) #array
	sw $t0,2400($sp) #t480
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2404($sp) #t481
#=====//
#  Arithmet / Relation  //
	lw $t0,2404($sp) #t481
	li $t1,4 #t481
	mul $t0,$t0,$t1 #
	sw $t0,2408($sp) #t482
#=====//
#  Arithmet / Relation  //
	lw $t0,2400($sp) #t480
	lw $t1,2408($sp) #t480
	add $t0,$t0,$t1 #
	sw $t0,2412($sp) #t479
#=====//
#  Assignment //
	lw $t0, 2412($sp) #t479
	lw $t1, 2412($sp) #t479
	lw $t0, ($t0) #
	sw $t0, 2412($sp) #t479
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,2412($sp) #t479
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,2432($sp) #t489
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,2444($sp) #t490
#=====//
#  Arithmet / Relation  //
	lw $t0,2444($sp) #t490
	lw $t1,2432($sp) #t490
	add $t0,$t0,$t1 #
	sw $t0,2448($sp) #t488
#=====//
#  Literal Float  //
	li.s $f1,4.56700 #4.56700
	s.s $f1,2452($sp) #t491
#=====//
#  Assignment //
	l.s $f1, 2452($sp) #t491
	lw $t1, 2448($sp) #t488
	s.s $f1, ($t1) #t488
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  Function Call:ModifyTestArr //
	sw $ra, 4720($sp)
	sub $sp, $sp, 48
	sw $fp, 36($sp)
	add $fp,$sp, 48
	jal ModifyTestArr
	lw $ra, 4720($sp)
#=====//
#  &  //
	la $t0,testArr #testArr
	sw $t0,2476($sp) #t503
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2480($sp) #t504
#=====//
#  Arithmet / Relation  //
	lw $t0,2480($sp) #t504
	li $t1,4 #t504
	mul $t0,$t0,$t1 #
	sw $t0,2484($sp) #t505
#=====//
#  Arithmet / Relation  //
	lw $t0,2476($sp) #t503
	lw $t1,2484($sp) #t503
	add $t0,$t0,$t1 #
	sw $t0,2488($sp) #t502
#=====//
#  Assignment //
	lw $t0, 2488($sp) #t502
	lw $t1, 2488($sp) #t502
	lw $t0, ($t0) #
	sw $t0, 2488($sp) #t502
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,2488($sp) #t502
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  Function Call:arithmetic_Int //
	sw $ra, 4720($sp)
	sub $sp, $sp, 148
	sw $fp, 136($sp)
	add $fp,$sp, 148
	jal arithmetic_Int
	lw $ra, 4720($sp)
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,2536($sp) #t523
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,2748($sp) #t524
#=====//
#  Arithmet / Relation  //
	lw $t0,2748($sp) #t524
	lw $t1,2536($sp) #t524
	add $t0,$t0,$t1 #
	sw $t0,2752($sp) #t522
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,2756($sp) #t525
#=====//
#  Assignment //
	lw $t0, 2756($sp) #t525
	lw $t1, 2752($sp) #t522
	sw $t0, ($t1) #t522
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,2760($sp) #t529
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,2772($sp) #t530
#=====//
#  Arithmet / Relation  //
	lw $t0,2772($sp) #t530
	lw $t1,2760($sp) #t530
	add $t0,$t0,$t1 #
	sw $t0,2776($sp) #t528
#=====//
#  Assignment //
	lw $t0, 2776($sp) #t528
	lw $t1, 2776($sp) #t528
	lw $t0, ($t0) #
	sw $t0, 2776($sp) #t528
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,2776($sp) #t528
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2796($sp) #t536
#=====//
#  Literal Int/Char  //
	li $t0,6 #6
	sw $t0,2800($sp) #t537
#=====//
#  Assignment //
	lw $t0, 2800($sp) #t537
	lw $t1, 2796($sp) #t536
	sw $t0, ($t1) #t536
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2804($sp) #t540
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2808($sp) #t542
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2812($sp) #t543
#=====//
#  Arithmet / Relation  //
	lw $t0,2808($sp) #t542
	lw $t1,2812($sp) #t542
	lw $t0, ($t0) #LEEEEFT
	add $t0,$t0,$t1 #
	sw $t0,2816($sp) #t541
#=====//
#  Assignment //
	lw $t0, 2816($sp) #t541
	lw $t1, 2804($sp) #t540
	sw $t0, ($t1) #t540
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2820($sp) #t545
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2824($sp) #t549
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2828($sp) #t551
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2832($sp) #t552
#=====//
#  Arithmet / Relation  //
	lw $t0,2828($sp) #t551
	lw $t1,2832($sp) #t551
	lw $t0, ($t0) #LEEEEFT
	add $t0,$t0,$t1 #
	sw $t0,2836($sp) #t550
#=====//
#  Assignment //
	lw $t0, 2836($sp) #t550
	lw $t1, 2824($sp) #t549
	sw $t0, ($t1) #t549
#=====//
#  Function Call:RecursiveFunction //
	sw $ra, 4720($sp)
	la $t0, 340($sp)
	li  $t2,  0
	add $t0, $t0, $t2
	sub $sp, $sp, 96
	la $t1, 0($sp)
	li  $t2,  0
	add $t1, $t1, $t2
	add $sp, $sp, 96
	lw $t0, ($t0)
	sw $t0, ($t1)
	sub $sp, $sp, 96
	sw $fp, 84($sp)
	add $fp,$sp, 96
	jal RecursiveFunction
	lw $ra, 4720($sp)
#=====//
#  Function Call:MutualRecursion_One //
	sw $ra, 4720($sp)
	la $t0, 340($sp)
	li  $t2,  0
	add $t0, $t0, $t2
	sub $sp, $sp, 176
	la $t1, 0($sp)
	li  $t2,  0
	add $t1, $t1, $t2
	add $sp, $sp, 176
	lw $t0, ($t0)
	sw $t0, ($t1)
	sub $sp, $sp, 176
	sw $fp, 164($sp)
	add $fp,$sp, 176
	jal MutualRecursion_One
	lw $ra, 4720($sp)
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,2856($sp) #t562
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,2868($sp) #t563
#=====//
#  Arithmet / Relation  //
	lw $t0,2868($sp) #t563
	lw $t1,2856($sp) #t563
	add $t0,$t0,$t1 #
	sw $t0,2872($sp) #t561
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,2876($sp) #t564
#=====//
#  Assignment //
	lw $t0, 2876($sp) #t564
	lw $t1, 2872($sp) #t561
	sw $t0, ($t1) #t561
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2880($sp) #t567
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2884($sp) #t568
#=====//
#  Assignment //
	lw $t0, 2884($sp) #t568
	lw $t1, 2880($sp) #t567
	sw $t0, ($t1) #t567
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2888($sp) #t571
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2892($sp) #t577
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2896($sp) #t578
#=====//
#  Arithmet / Relation  //
	lw $t0,2892($sp) #t577
	lw $t1,2896($sp) #t577
	lw $t0, ($t0) #LEEEEFT
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2900($sp) #t576
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2904($sp) #t579
#=====//
#  Arithmet / Relation  //
	lw $t0,2900($sp) #t576
	lw $t1,2904($sp) #t576
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2908($sp) #t575
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2912($sp) #t580
#=====//
#  Arithmet / Relation  //
	lw $t0,2908($sp) #t575
	lw $t1,2912($sp) #t575
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2916($sp) #t574
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2920($sp) #t581
#=====//
#  Arithmet / Relation  //
	lw $t0,2916($sp) #t574
	lw $t1,2920($sp) #t574
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2924($sp) #t573
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2928($sp) #t582
#=====//
#  Arithmet / Relation  //
	lw $t0,2924($sp) #t573
	lw $t1,2928($sp) #t573
	add $t0,$t0,$t1 #
	sw $t0,2932($sp) #t572
#=====//
#  Assignment //
	lw $t0, 2932($sp) #t572
	lw $t1, 2888($sp) #t571
	sw $t0, ($t1) #t571
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,340($sp) #y
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,2944($sp) #t589
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3156($sp) #t591
#=====//
#  Literal Int/Char  //
	li $t0,34 #34
	sw $t0,3160($sp) #t592
#=====//
#  Arithmet / Relation  //
	lw $t0,3160($sp) #t592
	li $t1,4 #t592
	mul $t0,$t0,$t1 #
	sw $t0,3164($sp) #t593
#=====//
#  Arithmet / Relation  //
	lw $t0,3156($sp) #t591
	lw $t1,3164($sp) #t591
	add $t0,$t0,$t1 #
	sw $t0,3168($sp) #t590
#=====//
#  Arithmet / Relation  //
	lw $t0,3168($sp) #t590
	lw $t1,2944($sp) #t590
	add $t0,$t0,$t1 #
	sw $t0,3172($sp) #t588
#=====//
#  Literal Int/Char  //
	li $t0,77 #77
	sw $t0,3176($sp) #t594
#=====//
#  Assignment //
	lw $t0, 3176($sp) #t594
	lw $t1, 3172($sp) #t588
	sw $t0, ($t1) #t588
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,3180($sp) #t597
#=====//
#  Literal Float  //
	li.s $f1,999.900 #999.900
	s.s $f1,3184($sp) #t598
#=====//
#  Assignment //
	l.s $f1, 3184($sp) #t598
	lw $t1, 3180($sp) #t597
	s.s $f1, ($t1) #t597
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,3188($sp) #t602
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3400($sp) #t604
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,3404($sp) #t605
#=====//
#  Arithmet / Relation  //
	lw $t0,3404($sp) #t605
	li $t1,4 #t605
	mul $t0,$t0,$t1 #
	sw $t0,3408($sp) #t606
#=====//
#  Arithmet / Relation  //
	lw $t0,3400($sp) #t604
	lw $t1,3408($sp) #t604
	add $t0,$t0,$t1 #
	sw $t0,3412($sp) #t603
#=====//
#  Arithmet / Relation  //
	lw $t0,3412($sp) #t603
	lw $t1,3188($sp) #t603
	add $t0,$t0,$t1 #
	sw $t0,3416($sp) #t601
#=====//
#  Literal Int/Char  //
	li $t0,2014 #2014
	sw $t0,3420($sp) #t608
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,3424($sp) #t609
#=====//
#  Arithmet / Relation  //
	lw $t0,3420($sp) #t608
	lw $t1,3424($sp) #t608
	add $t0,$t0,$t1 #
	sw $t0,3428($sp) #t607
#=====//
#  Assignment //
	lw $t0, 3428($sp) #t607
	lw $t1, 3416($sp) #t601
	sw $t0, ($t1) #t601
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,3432($sp) #t613
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,3648($sp) #t615
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3652($sp) #t617
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,3656($sp) #t618
#=====//
#  Arithmet / Relation  //
	lw $t0,3656($sp) #t618
	li $t1,4 #t618
	mul $t0,$t0,$t1 #
	sw $t0,3660($sp) #t619
#=====//
#  Arithmet / Relation  //
	lw $t0,3652($sp) #t617
	lw $t1,3660($sp) #t617
	add $t0,$t0,$t1 #
	sw $t0,3664($sp) #t616
#=====//
#  Arithmet / Relation  //
	lw $t0,3664($sp) #t616
	lw $t1,3648($sp) #t616
	add $t0,$t0,$t1 #
	sw $t0,3668($sp) #t614
#=====//
#  Arithmet / Relation  //
	lw $t0,3668($sp) #t614
	lw $t1,3432($sp) #t614
	add $t0,$t0,$t1 #
	sw $t0,3672($sp) #t612
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,3676($sp) #t621
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3888($sp) #t623
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,3892($sp) #t624
#=====//
#  Arithmet / Relation  //
	lw $t0,3892($sp) #t624
	li $t1,4 #t624
	mul $t0,$t0,$t1 #
	sw $t0,3896($sp) #t625
#=====//
#  Arithmet / Relation  //
	lw $t0,3888($sp) #t623
	lw $t1,3896($sp) #t623
	add $t0,$t0,$t1 #
	sw $t0,3900($sp) #t622
#=====//
#  Arithmet / Relation  //
	lw $t0,3900($sp) #t622
	lw $t1,3676($sp) #t622
	add $t0,$t0,$t1 #
	sw $t0,3904($sp) #t620
#=====//
#  Assignment //
	lw $t0, 3904($sp) #t620
	lw $t1, 3672($sp) #t612
	lw $t0, ($t0) #
	sw $t0, ($t1) #t612
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,3908($sp) #t629
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,4120($sp) #t631
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,4124($sp) #t632
#=====//
#  Arithmet / Relation  //
	lw $t0,4124($sp) #t632
	li $t1,4 #t632
	mul $t0,$t0,$t1 #
	sw $t0,4128($sp) #t633
#=====//
#  Arithmet / Relation  //
	lw $t0,4120($sp) #t631
	lw $t1,4128($sp) #t631
	add $t0,$t0,$t1 #
	sw $t0,4132($sp) #t630
#=====//
#  Arithmet / Relation  //
	lw $t0,4132($sp) #t630
	lw $t1,3908($sp) #t630
	add $t0,$t0,$t1 #
	sw $t0,4136($sp) #t628
#=====//
#  Assignment //
	lw $t0, 4136($sp) #t628
	lw $t1, 4136($sp) #t628
	lw $t0, ($t0) #
	sw $t0, 4136($sp) #t628
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4136($sp) #t628
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,floatTest #floatTest
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,4172($sp) #t646
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,4388($sp) #t648
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,4392($sp) #t650
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,4396($sp) #t651
#=====//
#  Arithmet / Relation  //
	lw $t0,4396($sp) #t651
	li $t1,4 #t651
	mul $t0,$t0,$t1 #
	sw $t0,4400($sp) #t652
#=====//
#  Arithmet / Relation  //
	lw $t0,4392($sp) #t650
	lw $t1,4400($sp) #t650
	add $t0,$t0,$t1 #
	sw $t0,4404($sp) #t649
#=====//
#  Arithmet / Relation  //
	lw $t0,4404($sp) #t649
	lw $t1,4388($sp) #t649
	add $t0,$t0,$t1 #
	sw $t0,4408($sp) #t647
#=====//
#  Arithmet / Relation  //
	lw $t0,4408($sp) #t647
	lw $t1,4172($sp) #t647
	add $t0,$t0,$t1 #
	sw $t0,4412($sp) #t645
#=====//
#  Assignment //
	lw $t0, 4412($sp) #t645
	lw $t1, 4412($sp) #t645
	lw $t0, ($t0) #
	sw $t0, 4412($sp) #t645
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4412($sp) #t645
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,4432($sp) #t659
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,4644($sp) #t660
#=====//
#  Arithmet / Relation  //
	lw $t0,4644($sp) #t660
	lw $t1,4432($sp) #t660
	add $t0,$t0,$t1 #
	sw $t0,4648($sp) #t658
#=====//
#  Assignment //
	lw $t0, 4648($sp) #t658
	lw $t1, 4648($sp) #t658
	lw $t0, ($t0) #
	sw $t0, 4648($sp) #t658
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4648($sp) #t658
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,4668($sp) #t667
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,4680($sp) #t668
#=====//
#  Arithmet / Relation  //
	lw $t0,4680($sp) #t668
	lw $t1,4668($sp) #t668
	add $t0,$t0,$t1 #
	sw $t0,4684($sp) #t666
#=====//
#  Assignment //
	lw $t0, 4684($sp) #t666
	lw $t1, 4684($sp) #t666
	lw $t0, ($t0) #
	sw $t0, 4684($sp) #t666
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,4684($sp) #t666
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,4704($sp) #t674
#=====//
# Return Called
	lw $fp, 4716($sp)
	add $sp, $sp, 4728
	jr $ra
#=====//
	li $v0,10
	syscall
