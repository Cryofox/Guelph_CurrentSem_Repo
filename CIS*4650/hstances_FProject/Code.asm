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
Loops:
#  &  //
	la $t0,32($sp) #eq
	sw $t0,40($sp) #t361
#=====//
#  Literal Int/Char  //
	li $t0,'=' #'='
	sw $t0,44($sp) #t362
#=====//
#  Assignment //
	lw $t0, 44($sp) #t362
	lw $t1, 40($sp) #t361
	sw $t0, ($t1) #t361
#=====//
#  &  //
	la $t0,24($sp) #f
	sw $t0,48($sp) #t365
#=====//
#  Literal Int/Char  //
	li $t0,'F' #'F'
	sw $t0,52($sp) #t366
#=====//
#  Assignment //
	lw $t0, 52($sp) #t366
	lw $t1, 48($sp) #t365
	sw $t0, ($t1) #t365
#=====//
#  &  //
	la $t0,28($sp) #w
	sw $t0,56($sp) #t369
#=====//
#  Literal Int/Char  //
	li $t0,'W' #'W'
	sw $t0,60($sp) #t370
#=====//
#  Assignment //
	lw $t0, 60($sp) #t370
	lw $t1, 56($sp) #t369
	sw $t0, ($t1) #t369
#=====//
#  &  //
	la $t0,0($sp) #nl
	sw $t0,64($sp) #t373
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,68($sp) #t374
#=====//
#  Assignment //
	lw $t0, 68($sp) #t374
	lw $t1, 64($sp) #t373
	sw $t0, ($t1) #t373
#=====//
#  &  //
	la $t0,8($sp) #ascii_1
	sw $t0,72($sp) #t377
#=====//
#  Literal Int/Char  //
	li $t0,'(' #'('
	sw $t0,76($sp) #t378
#=====//
#  Assignment //
	lw $t0, 76($sp) #t378
	lw $t1, 72($sp) #t377
	sw $t0, ($t1) #t377
#=====//
#  &  //
	la $t0,12($sp) #ascii_2
	sw $t0,80($sp) #t381
#=====//
#  Literal Int/Char  //
	li $t0,'^' #'^'
	sw $t0,84($sp) #t382
#=====//
#  Assignment //
	lw $t0, 84($sp) #t382
	lw $t1, 80($sp) #t381
	sw $t0, ($t1) #t381
#=====//
#  &  //
	la $t0,16($sp) #ascii_3
	sw $t0,88($sp) #t385
#=====//
#  Literal Int/Char  //
	li $t0,'_' #'_'
	sw $t0,92($sp) #t386
#=====//
#  Assignment //
	lw $t0, 92($sp) #t386
	lw $t1, 88($sp) #t385
	sw $t0, ($t1) #t385
#=====//
#  &  //
	la $t0,20($sp) #ascii_4
	sw $t0,96($sp) #t389
#=====//
#  Literal Int/Char  //
	li $t0,')' #')'
	sw $t0,100($sp) #t390
#=====//
#  Assignment //
	lw $t0, 100($sp) #t390
	lw $t1, 96($sp) #t389
	sw $t0, ($t1) #t389
#=====//
#  &  //
	la $t0,4($sp) #space
	sw $t0,104($sp) #t393
#=====//
#  Literal Int/Char  //
	li $t0,' ' #' '
	sw $t0,108($sp) #t394
#=====//
#  Assignment //
	lw $t0, 108($sp) #t394
	lw $t1, 104($sp) #t393
	sw $t0, ($t1) #t393
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,24($sp) #f
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,32($sp) #eq
	syscall
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,128($sp) #t403
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,132($sp) #t404
#=====//
#  Assignment //
	lw $t0, 132($sp) #t404
	lw $t1, 128($sp) #t403
	sw $t0, ($t1) #t403
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,136($sp) #t408
#=====//
#  Literal Int/Char  //
	li $t0,3 #3
	sw $t0,140($sp) #t409
#=====//
#  Arithmet / Relation  //
	lw $t0,136($sp) #t408
	lw $t1,140($sp) #t408
	lw $t0, ($t0) #LEEEEFT
	bge $t0, $t1, SkipLabel_t409
	sw $t0,144($sp) #t407
#=====//
Label_t406:
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #ascii_1
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #ascii_2
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,16($sp) #ascii_3
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #ascii_2
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,20($sp) #ascii_4
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #space
	syscall
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,196($sp) #t429
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,200($sp) #t433
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,204($sp) #t435
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,208($sp) #t436
#=====//
#  Arithmet / Relation  //
	lw $t0,204($sp) #t435
	lw $t1,208($sp) #t435
	lw $t0, ($t0) #LEEEEFT
	add $t0,$t0,$t1 #
	sw $t0,212($sp) #t434
#=====//
#  Assignment //
	lw $t0, 212($sp) #t434
	lw $t1, 200($sp) #t433
	sw $t0, ($t1) #t433
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,216($sp) #t438
#=====//
#  Literal Int/Char  //
	li $t0,3 #3
	sw $t0,220($sp) #t439
#=====//
#  Arithmet / Relation  //
	lw $t0,216($sp) #t438
	lw $t1,220($sp) #t438
	lw $t0, ($t0) #LEEEEFT
	blt $t0, $t1, Label_t406
	sw $t0,224($sp) #t437
#=====//
SkipLabel_t409:
#  SysCall Put_C //
	li $v0,4 #
	la $a0,0($sp) #nl
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,28($sp) #w
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,32($sp) #eq
	syscall
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,252($sp) #t451
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,256($sp) #t452
#=====//
#  Assignment //
	lw $t0, 256($sp) #t452
	lw $t1, 252($sp) #t451
	sw $t0, ($t1) #t451
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,260($sp) #t456
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,264($sp) #t457
#=====//
#  Arithmet / Relation  //
	lw $t0,260($sp) #t456
	lw $t1,264($sp) #t456
	lw $t0, ($t0) #LEEEEFT
	bge $t0, $t1, SkipLabel_t457
	sw $t0,268($sp) #t455
#=====//
Label_t454:
#  SysCall Put_C //
	li $v0,4 #
	la $a0,8($sp) #ascii_1
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #ascii_2
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,16($sp) #ascii_3
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,12($sp) #ascii_2
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,20($sp) #ascii_4
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,4($sp) #space
	syscall
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,320($sp) #t478
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,324($sp) #t482
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,328($sp) #t484
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,332($sp) #t485
#=====//
#  Arithmet / Relation  //
	lw $t0,328($sp) #t484
	lw $t1,332($sp) #t484
	lw $t0, ($t0) #LEEEEFT
	add $t0,$t0,$t1 #
	sw $t0,336($sp) #t483
#=====//
#  Assignment //
	lw $t0, 336($sp) #t483
	lw $t1, 324($sp) #t482
	sw $t0, ($t1) #t482
#=====//
#  &  //
	la $t0,36($sp) #i
	sw $t0,340($sp) #t487
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,344($sp) #t488
#=====//
#  Arithmet / Relation  //
	lw $t0,340($sp) #t487
	lw $t1,344($sp) #t487
	lw $t0, ($t0) #LEEEEFT
	blt $t0, $t1, Label_t454
	sw $t0,348($sp) #t486
#=====//
SkipLabel_t457:
#  SysCall Put_C //
	li $v0,4 #
	la $a0,0($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,360($sp) #t494
#=====//
# Return Called
	lw $fp, 372($sp)
	add $sp, $sp, 384
	jr $ra
#=====//
main:
#  Stack Setup:main //
	sub $sp, $sp, 4732
	sw $fp, 4720($sp)
	add $fp,$sp, 4732
#=====//
#  Function Call:Loops //
	sw $ra, 4724($sp)
	sub $sp, $sp, 384
	sw $fp, 372($sp)
	add $fp,$sp, 384
	jal Loops
	lw $ra, 4724($sp)
#=====//
#  &  //
	la $t0,344($sp) #nl
	sw $t0,360($sp) #t501
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,364($sp) #t502
#=====//
#  Assignment //
	lw $t0, 364($sp) #t502
	lw $t1, 360($sp) #t501
	sw $t0, ($t1) #t501
#=====//
#  &  //
	la $t0,352($sp) #q
	sw $t0,368($sp) #t505
#=====//
#  Literal Int/Char  //
	li $t0,'q' #'q'
	sw $t0,372($sp) #t506
#=====//
#  Assignment //
	lw $t0, 372($sp) #t506
	lw $t1, 368($sp) #t505
	sw $t0, ($t1) #t505
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,376($sp) #t510
#=====//
#  Literal Int/Char  //
	li $t0,212 #212
	sw $t0,592($sp) #t511
#=====//
#  Arithmet / Relation  //
	lw $t0,592($sp) #t511
	lw $t1,376($sp) #t511
	add $t0,$t0,$t1 #
	sw $t0,596($sp) #t509
#=====//
#  Literal Int/Char  //
	li $t0,1337 #1337
	sw $t0,600($sp) #t512
#=====//
#  Assignment //
	lw $t0, 600($sp) #t512
	lw $t1, 596($sp) #t509
	sw $t0, ($t1) #t509
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,604($sp) #t516
#=====//
#  Literal Int/Char  //
	li $t0,212 #212
	sw $t0,820($sp) #t517
#=====//
#  Arithmet / Relation  //
	lw $t0,820($sp) #t517
	lw $t1,604($sp) #t517
	add $t0,$t0,$t1 #
	sw $t0,824($sp) #t515
#=====//
#  Assignment //
	lw $t0, 824($sp) #t515
	lw $t1, 824($sp) #t515
	lw $t0, ($t0) #
	sw $t0, 824($sp) #t515
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,824($sp) #t515
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  Function Call:Pass_StructRef //
	sw $ra, 4724($sp)
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
	lw $ra, 4724($sp)
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1068($sp) #t529
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,1284($sp) #t531
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,1288($sp) #t533
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,1292($sp) #t534
#=====//
#  Arithmet / Relation  //
	lw $t0,1292($sp) #t534
	li $t1,4 #t534
	mul $t0,$t0,$t1 #
	sw $t0,1296($sp) #t535
#=====//
#  Arithmet / Relation  //
	lw $t0,1288($sp) #t533
	lw $t1,1296($sp) #t533
	add $t0,$t0,$t1 #
	sw $t0,1300($sp) #t532
#=====//
#  Arithmet / Relation  //
	lw $t0,1300($sp) #t532
	lw $t1,1284($sp) #t532
	add $t0,$t0,$t1 #
	sw $t0,1304($sp) #t530
#=====//
#  Arithmet / Relation  //
	lw $t0,1304($sp) #t530
	lw $t1,1068($sp) #t530
	add $t0,$t0,$t1 #
	sw $t0,1308($sp) #t528
#=====//
#  Literal Int/Char  //
	li $t0,2014 #2014
	sw $t0,1312($sp) #t536
#=====//
#  Assignment //
	lw $t0, 1312($sp) #t536
	lw $t1, 1308($sp) #t528
	sw $t0, ($t1) #t528
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1316($sp) #t540
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,1532($sp) #t542
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,1536($sp) #t544
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,1540($sp) #t545
#=====//
#  Arithmet / Relation  //
	lw $t0,1540($sp) #t545
	li $t1,4 #t545
	mul $t0,$t0,$t1 #
	sw $t0,1544($sp) #t546
#=====//
#  Arithmet / Relation  //
	lw $t0,1536($sp) #t544
	lw $t1,1544($sp) #t544
	add $t0,$t0,$t1 #
	sw $t0,1548($sp) #t543
#=====//
#  Arithmet / Relation  //
	lw $t0,1548($sp) #t543
	lw $t1,1532($sp) #t543
	add $t0,$t0,$t1 #
	sw $t0,1552($sp) #t541
#=====//
#  Arithmet / Relation  //
	lw $t0,1552($sp) #t541
	lw $t1,1316($sp) #t541
	add $t0,$t0,$t1 #
	sw $t0,1556($sp) #t539
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1560($sp) #t549
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,1776($sp) #t551
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,1780($sp) #t553
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,1784($sp) #t554
#=====//
#  Arithmet / Relation  //
	lw $t0,1784($sp) #t554
	li $t1,4 #t554
	mul $t0,$t0,$t1 #
	sw $t0,1788($sp) #t555
#=====//
#  Arithmet / Relation  //
	lw $t0,1780($sp) #t553
	lw $t1,1788($sp) #t553
	add $t0,$t0,$t1 #
	sw $t0,1792($sp) #t552
#=====//
#  Arithmet / Relation  //
	lw $t0,1792($sp) #t552
	lw $t1,1776($sp) #t552
	add $t0,$t0,$t1 #
	sw $t0,1796($sp) #t550
#=====//
#  Arithmet / Relation  //
	lw $t0,1796($sp) #t550
	lw $t1,1560($sp) #t550
	add $t0,$t0,$t1 #
	sw $t0,1800($sp) #t548
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,1804($sp) #t556
#=====//
#  Arithmet / Relation  //
	lw $t0,1800($sp) #t548
	lw $t1,1804($sp) #t548
	lw $t0, ($t0) #LEEEEFT
	mul $t0,$t0,$t1 #
	sw $t0,1808($sp) #t547
#=====//
#  Assignment //
	lw $t0, 1808($sp) #t547
	lw $t1, 1556($sp) #t539
	sw $t0, ($t1) #t539
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1812($sp) #t560
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,2028($sp) #t562
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,2032($sp) #t564
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,2036($sp) #t565
#=====//
#  Arithmet / Relation  //
	lw $t0,2036($sp) #t565
	li $t1,4 #t565
	mul $t0,$t0,$t1 #
	sw $t0,2040($sp) #t566
#=====//
#  Arithmet / Relation  //
	lw $t0,2032($sp) #t564
	lw $t1,2040($sp) #t564
	add $t0,$t0,$t1 #
	sw $t0,2044($sp) #t563
#=====//
#  Arithmet / Relation  //
	lw $t0,2044($sp) #t563
	lw $t1,2028($sp) #t563
	add $t0,$t0,$t1 #
	sw $t0,2048($sp) #t561
#=====//
#  Arithmet / Relation  //
	lw $t0,2048($sp) #t561
	lw $t1,1812($sp) #t561
	add $t0,$t0,$t1 #
	sw $t0,2052($sp) #t559
#=====//
#  Assignment //
	lw $t0, 2052($sp) #t559
	lw $t1, 2052($sp) #t559
	lw $t0, ($t0) #
	sw $t0, 2052($sp) #t559
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,2052($sp) #t559
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,2072($sp) #t572
#=====//
#  Literal Float  //
	li.s $f1,7.90000 #7.90000
	s.s $f1,2076($sp) #t574
#=====//
#  Literal Float  //
	li.s $f1,5.40000 #5.40000
	s.s $f1,2080($sp) #t575
#=====//
#  Arithmet / Relation  //
	l.s $f1,2076($sp) #t574
	l.s $f2,2080($sp) #t575
	add.s $f1,$f1,$f2 #
	s.s $f1,2084($sp) #t573
#=====//
#  Assignment //
	l.s $f1, 2084($sp) #t573
	lw $t1, 2072($sp) #t572
	s.s $f1, ($t1) #t572
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,2088($sp) #t579
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,2300($sp) #t580
#=====//
#  Arithmet / Relation  //
	lw $t0,2300($sp) #t580
	lw $t1,2088($sp) #t580
	add $t0,$t0,$t1 #
	sw $t0,2304($sp) #t578
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,2308($sp) #t581
#=====//
#  Assignment //
	lw $t0, 2308($sp) #t581
	lw $t1, 2304($sp) #t578
	sw $t0, ($t1) #t578
#=====//
#  &  //
	la $t0,344($sp) #nl
	sw $t0,2312($sp) #t584
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,2316($sp) #t585
#=====//
#  Assignment //
	lw $t0, 2316($sp) #t585
	lw $t1, 2312($sp) #t584
	sw $t0, ($t1) #t584
#=====//
#  &  //
	la $t0,test #test
	sw $t0,2320($sp) #t588
#=====//
#  Literal Int/Char  //
	li $t0,54 #54
	sw $t0,2324($sp) #t589
#=====//
#  Assignment //
	lw $t0, 2324($sp) #t589
	lw $t1, 2320($sp) #t588
	sw $t0, ($t1) #t588
#=====//
#  &  //
	la $t0,252($sp) #array
	sw $t0,2328($sp) #t593
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2332($sp) #t594
#=====//
#  Arithmet / Relation  //
	lw $t0,2332($sp) #t594
	li $t1,4 #t594
	mul $t0,$t0,$t1 #
	sw $t0,2336($sp) #t595
#=====//
#  Arithmet / Relation  //
	lw $t0,2328($sp) #t593
	lw $t1,2336($sp) #t593
	add $t0,$t0,$t1 #
	sw $t0,2340($sp) #t592
#=====//
#  Literal Int/Char  //
	li $t0,65 #65
	sw $t0,2344($sp) #t596
#=====//
#  Assignment //
	lw $t0, 2344($sp) #t596
	lw $t1, 2340($sp) #t592
	sw $t0, ($t1) #t592
#=====//
#  Function Call:test_CharPrint //
	sw $ra, 4724($sp)
	sub $sp, $sp, 320
	sw $fp, 308($sp)
	add $fp,$sp, 320
	jal test_CharPrint
	lw $ra, 4724($sp)
#=====//
#  &  //
	la $t0,336($sp) #x
	sw $t0,2352($sp) #t601
#=====//
#  &  //
	la $t0,252($sp) #array
	sw $t0,2356($sp) #t603
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2360($sp) #t604
#=====//
#  Arithmet / Relation  //
	lw $t0,2360($sp) #t604
	li $t1,4 #t604
	mul $t0,$t0,$t1 #
	sw $t0,2364($sp) #t605
#=====//
#  Arithmet / Relation  //
	lw $t0,2356($sp) #t603
	lw $t1,2364($sp) #t603
	add $t0,$t0,$t1 #
	sw $t0,2368($sp) #t602
#=====//
#  Assignment //
	lw $t0, 2368($sp) #t602
	lw $t1, 2352($sp) #t601
	lw $t0, ($t0) #
	sw $t0, ($t1) #t601
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
	sw $t0,2404($sp) #t621
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2408($sp) #t622
#=====//
#  Arithmet / Relation  //
	lw $t0,2408($sp) #t622
	li $t1,4 #t622
	mul $t0,$t0,$t1 #
	sw $t0,2412($sp) #t623
#=====//
#  Arithmet / Relation  //
	lw $t0,2404($sp) #t621
	lw $t1,2412($sp) #t621
	add $t0,$t0,$t1 #
	sw $t0,2416($sp) #t620
#=====//
#  Assignment //
	lw $t0, 2416($sp) #t620
	lw $t1, 2416($sp) #t620
	lw $t0, ($t0) #
	sw $t0, 2416($sp) #t620
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,2416($sp) #t620
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,2436($sp) #t630
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,2448($sp) #t631
#=====//
#  Arithmet / Relation  //
	lw $t0,2448($sp) #t631
	lw $t1,2436($sp) #t631
	add $t0,$t0,$t1 #
	sw $t0,2452($sp) #t629
#=====//
#  Literal Float  //
	li.s $f1,4.56700 #4.56700
	s.s $f1,2456($sp) #t632
#=====//
#  Assignment //
	l.s $f1, 2456($sp) #t632
	lw $t1, 2452($sp) #t629
	s.s $f1, ($t1) #t629
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
	sw $ra, 4724($sp)
	sub $sp, $sp, 48
	sw $fp, 36($sp)
	add $fp,$sp, 48
	jal ModifyTestArr
	lw $ra, 4724($sp)
#=====//
#  &  //
	la $t0,testArr #testArr
	sw $t0,2480($sp) #t644
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2484($sp) #t645
#=====//
#  Arithmet / Relation  //
	lw $t0,2484($sp) #t645
	li $t1,4 #t645
	mul $t0,$t0,$t1 #
	sw $t0,2488($sp) #t646
#=====//
#  Arithmet / Relation  //
	lw $t0,2480($sp) #t644
	lw $t1,2488($sp) #t644
	add $t0,$t0,$t1 #
	sw $t0,2492($sp) #t643
#=====//
#  Assignment //
	lw $t0, 2492($sp) #t643
	lw $t1, 2492($sp) #t643
	lw $t0, ($t0) #
	sw $t0, 2492($sp) #t643
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,2492($sp) #t643
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
	sw $ra, 4724($sp)
	sub $sp, $sp, 148
	sw $fp, 136($sp)
	add $fp,$sp, 148
	jal arithmetic_Int
	lw $ra, 4724($sp)
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,2540($sp) #t664
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,2752($sp) #t665
#=====//
#  Arithmet / Relation  //
	lw $t0,2752($sp) #t665
	lw $t1,2540($sp) #t665
	add $t0,$t0,$t1 #
	sw $t0,2756($sp) #t663
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,2760($sp) #t666
#=====//
#  Assignment //
	lw $t0, 2760($sp) #t666
	lw $t1, 2756($sp) #t663
	sw $t0, ($t1) #t663
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,2764($sp) #t670
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,2776($sp) #t671
#=====//
#  Arithmet / Relation  //
	lw $t0,2776($sp) #t671
	lw $t1,2764($sp) #t671
	add $t0,$t0,$t1 #
	sw $t0,2780($sp) #t669
#=====//
#  Assignment //
	lw $t0, 2780($sp) #t669
	lw $t1, 2780($sp) #t669
	lw $t0, ($t0) #
	sw $t0, 2780($sp) #t669
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,2780($sp) #t669
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2800($sp) #t677
#=====//
#  Literal Int/Char  //
	li $t0,6 #6
	sw $t0,2804($sp) #t678
#=====//
#  Assignment //
	lw $t0, 2804($sp) #t678
	lw $t1, 2800($sp) #t677
	sw $t0, ($t1) #t677
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2808($sp) #t681
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2812($sp) #t683
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2816($sp) #t684
#=====//
#  Arithmet / Relation  //
	lw $t0,2812($sp) #t683
	lw $t1,2816($sp) #t683
	lw $t0, ($t0) #LEEEEFT
	add $t0,$t0,$t1 #
	sw $t0,2820($sp) #t682
#=====//
#  Assignment //
	lw $t0, 2820($sp) #t682
	lw $t1, 2808($sp) #t681
	sw $t0, ($t1) #t681
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2824($sp) #t686
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2828($sp) #t690
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2832($sp) #t692
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2836($sp) #t693
#=====//
#  Arithmet / Relation  //
	lw $t0,2832($sp) #t692
	lw $t1,2836($sp) #t692
	lw $t0, ($t0) #LEEEEFT
	add $t0,$t0,$t1 #
	sw $t0,2840($sp) #t691
#=====//
#  Assignment //
	lw $t0, 2840($sp) #t691
	lw $t1, 2828($sp) #t690
	sw $t0, ($t1) #t690
#=====//
#  Function Call:RecursiveFunction //
	sw $ra, 4724($sp)
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
	lw $ra, 4724($sp)
#=====//
#  Function Call:MutualRecursion_One //
	sw $ra, 4724($sp)
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
	lw $ra, 4724($sp)
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,2860($sp) #t703
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,2872($sp) #t704
#=====//
#  Arithmet / Relation  //
	lw $t0,2872($sp) #t704
	lw $t1,2860($sp) #t704
	add $t0,$t0,$t1 #
	sw $t0,2876($sp) #t702
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,2880($sp) #t705
#=====//
#  Assignment //
	lw $t0, 2880($sp) #t705
	lw $t1, 2876($sp) #t702
	sw $t0, ($t1) #t702
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2884($sp) #t708
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2888($sp) #t709
#=====//
#  Assignment //
	lw $t0, 2888($sp) #t709
	lw $t1, 2884($sp) #t708
	sw $t0, ($t1) #t708
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2892($sp) #t712
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2896($sp) #t718
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2900($sp) #t719
#=====//
#  Arithmet / Relation  //
	lw $t0,2896($sp) #t718
	lw $t1,2900($sp) #t718
	lw $t0, ($t0) #LEEEEFT
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2904($sp) #t717
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2908($sp) #t720
#=====//
#  Arithmet / Relation  //
	lw $t0,2904($sp) #t717
	lw $t1,2908($sp) #t717
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2912($sp) #t716
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2916($sp) #t721
#=====//
#  Arithmet / Relation  //
	lw $t0,2912($sp) #t716
	lw $t1,2916($sp) #t716
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2920($sp) #t715
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2924($sp) #t722
#=====//
#  Arithmet / Relation  //
	lw $t0,2920($sp) #t715
	lw $t1,2924($sp) #t715
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2928($sp) #t714
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2932($sp) #t723
#=====//
#  Arithmet / Relation  //
	lw $t0,2928($sp) #t714
	lw $t1,2932($sp) #t714
	add $t0,$t0,$t1 #
	sw $t0,2936($sp) #t713
#=====//
#  Assignment //
	lw $t0, 2936($sp) #t713
	lw $t1, 2892($sp) #t712
	sw $t0, ($t1) #t712
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,340($sp) #y
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,2948($sp) #t730
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3160($sp) #t732
#=====//
#  Literal Int/Char  //
	li $t0,34 #34
	sw $t0,3164($sp) #t733
#=====//
#  Arithmet / Relation  //
	lw $t0,3164($sp) #t733
	li $t1,4 #t733
	mul $t0,$t0,$t1 #
	sw $t0,3168($sp) #t734
#=====//
#  Arithmet / Relation  //
	lw $t0,3160($sp) #t732
	lw $t1,3168($sp) #t732
	add $t0,$t0,$t1 #
	sw $t0,3172($sp) #t731
#=====//
#  Arithmet / Relation  //
	lw $t0,3172($sp) #t731
	lw $t1,2948($sp) #t731
	add $t0,$t0,$t1 #
	sw $t0,3176($sp) #t729
#=====//
#  Literal Int/Char  //
	li $t0,77 #77
	sw $t0,3180($sp) #t735
#=====//
#  Assignment //
	lw $t0, 3180($sp) #t735
	lw $t1, 3176($sp) #t729
	sw $t0, ($t1) #t729
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,3184($sp) #t738
#=====//
#  Literal Float  //
	li.s $f1,999.900 #999.900
	s.s $f1,3188($sp) #t739
#=====//
#  Assignment //
	l.s $f1, 3188($sp) #t739
	lw $t1, 3184($sp) #t738
	s.s $f1, ($t1) #t738
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,3192($sp) #t743
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3404($sp) #t745
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,3408($sp) #t746
#=====//
#  Arithmet / Relation  //
	lw $t0,3408($sp) #t746
	li $t1,4 #t746
	mul $t0,$t0,$t1 #
	sw $t0,3412($sp) #t747
#=====//
#  Arithmet / Relation  //
	lw $t0,3404($sp) #t745
	lw $t1,3412($sp) #t745
	add $t0,$t0,$t1 #
	sw $t0,3416($sp) #t744
#=====//
#  Arithmet / Relation  //
	lw $t0,3416($sp) #t744
	lw $t1,3192($sp) #t744
	add $t0,$t0,$t1 #
	sw $t0,3420($sp) #t742
#=====//
#  Literal Int/Char  //
	li $t0,2014 #2014
	sw $t0,3424($sp) #t749
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,3428($sp) #t750
#=====//
#  Arithmet / Relation  //
	lw $t0,3424($sp) #t749
	lw $t1,3428($sp) #t749
	add $t0,$t0,$t1 #
	sw $t0,3432($sp) #t748
#=====//
#  Assignment //
	lw $t0, 3432($sp) #t748
	lw $t1, 3420($sp) #t742
	sw $t0, ($t1) #t742
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,3436($sp) #t754
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,3652($sp) #t756
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3656($sp) #t758
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,3660($sp) #t759
#=====//
#  Arithmet / Relation  //
	lw $t0,3660($sp) #t759
	li $t1,4 #t759
	mul $t0,$t0,$t1 #
	sw $t0,3664($sp) #t760
#=====//
#  Arithmet / Relation  //
	lw $t0,3656($sp) #t758
	lw $t1,3664($sp) #t758
	add $t0,$t0,$t1 #
	sw $t0,3668($sp) #t757
#=====//
#  Arithmet / Relation  //
	lw $t0,3668($sp) #t757
	lw $t1,3652($sp) #t757
	add $t0,$t0,$t1 #
	sw $t0,3672($sp) #t755
#=====//
#  Arithmet / Relation  //
	lw $t0,3672($sp) #t755
	lw $t1,3436($sp) #t755
	add $t0,$t0,$t1 #
	sw $t0,3676($sp) #t753
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,3680($sp) #t762
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3892($sp) #t764
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,3896($sp) #t765
#=====//
#  Arithmet / Relation  //
	lw $t0,3896($sp) #t765
	li $t1,4 #t765
	mul $t0,$t0,$t1 #
	sw $t0,3900($sp) #t766
#=====//
#  Arithmet / Relation  //
	lw $t0,3892($sp) #t764
	lw $t1,3900($sp) #t764
	add $t0,$t0,$t1 #
	sw $t0,3904($sp) #t763
#=====//
#  Arithmet / Relation  //
	lw $t0,3904($sp) #t763
	lw $t1,3680($sp) #t763
	add $t0,$t0,$t1 #
	sw $t0,3908($sp) #t761
#=====//
#  Assignment //
	lw $t0, 3908($sp) #t761
	lw $t1, 3676($sp) #t753
	lw $t0, ($t0) #
	sw $t0, ($t1) #t753
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,3912($sp) #t770
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,4124($sp) #t772
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,4128($sp) #t773
#=====//
#  Arithmet / Relation  //
	lw $t0,4128($sp) #t773
	li $t1,4 #t773
	mul $t0,$t0,$t1 #
	sw $t0,4132($sp) #t774
#=====//
#  Arithmet / Relation  //
	lw $t0,4124($sp) #t772
	lw $t1,4132($sp) #t772
	add $t0,$t0,$t1 #
	sw $t0,4136($sp) #t771
#=====//
#  Arithmet / Relation  //
	lw $t0,4136($sp) #t771
	lw $t1,3912($sp) #t771
	add $t0,$t0,$t1 #
	sw $t0,4140($sp) #t769
#=====//
#  Assignment //
	lw $t0, 4140($sp) #t769
	lw $t1, 4140($sp) #t769
	lw $t0, ($t0) #
	sw $t0, 4140($sp) #t769
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4140($sp) #t769
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
	sw $t0,4176($sp) #t787
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,4392($sp) #t789
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,4396($sp) #t791
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,4400($sp) #t792
#=====//
#  Arithmet / Relation  //
	lw $t0,4400($sp) #t792
	li $t1,4 #t792
	mul $t0,$t0,$t1 #
	sw $t0,4404($sp) #t793
#=====//
#  Arithmet / Relation  //
	lw $t0,4396($sp) #t791
	lw $t1,4404($sp) #t791
	add $t0,$t0,$t1 #
	sw $t0,4408($sp) #t790
#=====//
#  Arithmet / Relation  //
	lw $t0,4408($sp) #t790
	lw $t1,4392($sp) #t790
	add $t0,$t0,$t1 #
	sw $t0,4412($sp) #t788
#=====//
#  Arithmet / Relation  //
	lw $t0,4412($sp) #t788
	lw $t1,4176($sp) #t788
	add $t0,$t0,$t1 #
	sw $t0,4416($sp) #t786
#=====//
#  Assignment //
	lw $t0, 4416($sp) #t786
	lw $t1, 4416($sp) #t786
	lw $t0, ($t0) #
	sw $t0, 4416($sp) #t786
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4416($sp) #t786
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,4436($sp) #t800
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,4648($sp) #t801
#=====//
#  Arithmet / Relation  //
	lw $t0,4648($sp) #t801
	lw $t1,4436($sp) #t801
	add $t0,$t0,$t1 #
	sw $t0,4652($sp) #t799
#=====//
#  Assignment //
	lw $t0, 4652($sp) #t799
	lw $t1, 4652($sp) #t799
	lw $t0, ($t0) #
	sw $t0, 4652($sp) #t799
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4652($sp) #t799
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,4672($sp) #t808
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,4684($sp) #t809
#=====//
#  Arithmet / Relation  //
	lw $t0,4684($sp) #t809
	lw $t1,4672($sp) #t809
	add $t0,$t0,$t1 #
	sw $t0,4688($sp) #t807
#=====//
#  Assignment //
	lw $t0, 4688($sp) #t807
	lw $t1, 4688($sp) #t807
	lw $t0, ($t0) #
	sw $t0, 4688($sp) #t807
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,4688($sp) #t807
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,4708($sp) #t815
#=====//
# Return Called
	lw $fp, 4720($sp)
	add $sp, $sp, 4732
	jr $ra
#=====//
	li $v0,10
	syscall
