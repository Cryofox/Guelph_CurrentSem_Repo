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
	lw $v0, 536($sp)
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
	lw $v0, 296($sp)
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
	sw $v0, 48($sp)  
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
	lw $v0, 124($sp)
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
	lw $v0, 64($sp)
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
	lw $v0, 64($sp)
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
	sw $v0, 0($sp)  
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
	lw $v0, 24($sp)
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
	sw $v0, 60($sp)  
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
	lw $v0, 72($sp)
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
	sw $v0, 148($sp)  
#=====//
Label_t256:
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,152($sp) #t293
#=====//
# Return Called
	lw $v0, 152($sp)
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
	sw $v0, 148($sp)  
#=====//
Label_t318:
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,152($sp) #t355
#=====//
# Return Called
	lw $v0, 152($sp)
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
	lw $v0, 360($sp)
	lw $fp, 372($sp)
	add $sp, $sp, 384
	jr $ra
#=====//
Return5:
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,0($sp) #t500
#=====//
# Return Called
	lw $v0, 0($sp)
	lw $fp, 12($sp)
	add $sp, $sp, 24
	jr $ra
#=====//
Return6:
#  &  //
	la $t0,0($sp) #x
	sw $t0,4($sp) #t506
#=====//
#  Literal Int/Char  //
	li $t0,6 #6
	sw $t0,8($sp) #t507
#=====//
#  Assignment //
	lw $t0, 8($sp) #t507
	lw $t1, 4($sp) #t506
	sw $t0, ($t1) #t506
#=====//
#  &  //
	la $t0,0($sp) #x
	sw $t0,12($sp) #t510
#=====//
# Return Called
	lw $v0, 12($sp)
	lw $v0, ($v0)
	lw $fp, 24($sp)
	add $sp, $sp, 36
	jr $ra
#=====//
main:
#  Stack Setup:main //
	sub $sp, $sp, 4780
	sw $fp, 4768($sp)
	add $fp,$sp, 4780
#=====//
#  &  //
	la $t0,344($sp) #nl
	sw $t0,356($sp) #t515
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,360($sp) #t516
#=====//
#  Assignment //
	lw $t0, 360($sp) #t516
	lw $t1, 356($sp) #t515
	sw $t0, ($t1) #t515
#=====//
#  &  //
	la $t0,356($sp) #retX
	sw $t0,364($sp) #t519
#=====//
#  Function Call:Return5 //
	sw $ra, 4772($sp)
	sub $sp, $sp, 24
	sw $fp, 12($sp)
	add $fp,$sp, 24
	jal Return5
	lw $ra, 4772($sp)
	sw $v0, 368($sp)  
#=====//
#  Assignment //
	lw $t0, 368($sp) #t520
	lw $t1, 364($sp) #t519
	sw $t0, ($t1) #t519
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,356($sp) #retX
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,356($sp) #retX
	sw $t0,388($sp) #t529
#=====//
#  Function Call:Return6 //
	sw $ra, 4772($sp)
	sub $sp, $sp, 36
	sw $fp, 24($sp)
	add $fp,$sp, 36
	jal Return6
	lw $ra, 4772($sp)
	sw $v0, 392($sp)  
#=====//
#  Assignment //
	lw $t0, 392($sp) #t530
	lw $t1, 388($sp) #t529
	sw $t0, ($t1) #t529
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,356($sp) #retX
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  Function Call:Loops //
	sw $ra, 4772($sp)
	sub $sp, $sp, 384
	sw $fp, 372($sp)
	add $fp,$sp, 384
	jal Loops
	lw $ra, 4772($sp)
	sw $v0, 412($sp)  
#=====//
#  &  //
	la $t0,352($sp) #q
	sw $t0,416($sp) #t541
#=====//
#  Literal Int/Char  //
	li $t0,'q' #'q'
	sw $t0,420($sp) #t542
#=====//
#  Assignment //
	lw $t0, 420($sp) #t542
	lw $t1, 416($sp) #t541
	sw $t0, ($t1) #t541
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,424($sp) #t546
#=====//
#  Literal Int/Char  //
	li $t0,212 #212
	sw $t0,640($sp) #t547
#=====//
#  Arithmet / Relation  //
	lw $t0,640($sp) #t547
	lw $t1,424($sp) #t547
	add $t0,$t0,$t1 #
	sw $t0,644($sp) #t545
#=====//
#  Literal Int/Char  //
	li $t0,1337 #1337
	sw $t0,648($sp) #t548
#=====//
#  Assignment //
	lw $t0, 648($sp) #t548
	lw $t1, 644($sp) #t545
	sw $t0, ($t1) #t545
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,652($sp) #t552
#=====//
#  Literal Int/Char  //
	li $t0,212 #212
	sw $t0,868($sp) #t553
#=====//
#  Arithmet / Relation  //
	lw $t0,868($sp) #t553
	lw $t1,652($sp) #t553
	add $t0,$t0,$t1 #
	sw $t0,872($sp) #t551
#=====//
#  Assignment //
	lw $t0, 872($sp) #t551
	lw $t1, 872($sp) #t551
	lw $t0, ($t0) #
	sw $t0, 872($sp) #t551
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,872($sp) #t551
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  Function Call:Pass_StructRef //
	sw $ra, 4772($sp)
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
	lw $ra, 4772($sp)
	sw $v0, 1112($sp)  
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1116($sp) #t565
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,1332($sp) #t567
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,1336($sp) #t569
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,1340($sp) #t570
#=====//
#  Arithmet / Relation  //
	lw $t0,1340($sp) #t570
	li $t1,4 #t570
	mul $t0,$t0,$t1 #
	sw $t0,1344($sp) #t571
#=====//
#  Arithmet / Relation  //
	lw $t0,1336($sp) #t569
	lw $t1,1344($sp) #t569
	add $t0,$t0,$t1 #
	sw $t0,1348($sp) #t568
#=====//
#  Arithmet / Relation  //
	lw $t0,1348($sp) #t568
	lw $t1,1332($sp) #t568
	add $t0,$t0,$t1 #
	sw $t0,1352($sp) #t566
#=====//
#  Arithmet / Relation  //
	lw $t0,1352($sp) #t566
	lw $t1,1116($sp) #t566
	add $t0,$t0,$t1 #
	sw $t0,1356($sp) #t564
#=====//
#  Literal Int/Char  //
	li $t0,2014 #2014
	sw $t0,1360($sp) #t572
#=====//
#  Assignment //
	lw $t0, 1360($sp) #t572
	lw $t1, 1356($sp) #t564
	sw $t0, ($t1) #t564
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1364($sp) #t576
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,1580($sp) #t578
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,1584($sp) #t580
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,1588($sp) #t581
#=====//
#  Arithmet / Relation  //
	lw $t0,1588($sp) #t581
	li $t1,4 #t581
	mul $t0,$t0,$t1 #
	sw $t0,1592($sp) #t582
#=====//
#  Arithmet / Relation  //
	lw $t0,1584($sp) #t580
	lw $t1,1592($sp) #t580
	add $t0,$t0,$t1 #
	sw $t0,1596($sp) #t579
#=====//
#  Arithmet / Relation  //
	lw $t0,1596($sp) #t579
	lw $t1,1580($sp) #t579
	add $t0,$t0,$t1 #
	sw $t0,1600($sp) #t577
#=====//
#  Arithmet / Relation  //
	lw $t0,1600($sp) #t577
	lw $t1,1364($sp) #t577
	add $t0,$t0,$t1 #
	sw $t0,1604($sp) #t575
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1608($sp) #t585
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,1824($sp) #t587
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,1828($sp) #t589
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,1832($sp) #t590
#=====//
#  Arithmet / Relation  //
	lw $t0,1832($sp) #t590
	li $t1,4 #t590
	mul $t0,$t0,$t1 #
	sw $t0,1836($sp) #t591
#=====//
#  Arithmet / Relation  //
	lw $t0,1828($sp) #t589
	lw $t1,1836($sp) #t589
	add $t0,$t0,$t1 #
	sw $t0,1840($sp) #t588
#=====//
#  Arithmet / Relation  //
	lw $t0,1840($sp) #t588
	lw $t1,1824($sp) #t588
	add $t0,$t0,$t1 #
	sw $t0,1844($sp) #t586
#=====//
#  Arithmet / Relation  //
	lw $t0,1844($sp) #t586
	lw $t1,1608($sp) #t586
	add $t0,$t0,$t1 #
	sw $t0,1848($sp) #t584
#=====//
#  Literal Int/Char  //
	li $t0,2 #2
	sw $t0,1852($sp) #t592
#=====//
#  Arithmet / Relation  //
	lw $t0,1848($sp) #t584
	lw $t1,1852($sp) #t584
	lw $t0, ($t0) #LEEEEFT
	mul $t0,$t0,$t1 #
	sw $t0,1856($sp) #t583
#=====//
#  Assignment //
	lw $t0, 1856($sp) #t583
	lw $t1, 1604($sp) #t575
	sw $t0, ($t1) #t575
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,1860($sp) #t596
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,2076($sp) #t598
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,2080($sp) #t600
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,2084($sp) #t601
#=====//
#  Arithmet / Relation  //
	lw $t0,2084($sp) #t601
	li $t1,4 #t601
	mul $t0,$t0,$t1 #
	sw $t0,2088($sp) #t602
#=====//
#  Arithmet / Relation  //
	lw $t0,2080($sp) #t600
	lw $t1,2088($sp) #t600
	add $t0,$t0,$t1 #
	sw $t0,2092($sp) #t599
#=====//
#  Arithmet / Relation  //
	lw $t0,2092($sp) #t599
	lw $t1,2076($sp) #t599
	add $t0,$t0,$t1 #
	sw $t0,2096($sp) #t597
#=====//
#  Arithmet / Relation  //
	lw $t0,2096($sp) #t597
	lw $t1,1860($sp) #t597
	add $t0,$t0,$t1 #
	sw $t0,2100($sp) #t595
#=====//
#  Assignment //
	lw $t0, 2100($sp) #t595
	lw $t1, 2100($sp) #t595
	lw $t0, ($t0) #
	sw $t0, 2100($sp) #t595
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,2100($sp) #t595
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,2120($sp) #t608
#=====//
#  Literal Float  //
	li.s $f1,7.90000 #7.90000
	s.s $f1,2124($sp) #t610
#=====//
#  Literal Float  //
	li.s $f1,5.40000 #5.40000
	s.s $f1,2128($sp) #t611
#=====//
#  Arithmet / Relation  //
	l.s $f1,2124($sp) #t610
	l.s $f2,2128($sp) #t611
	add.s $f1,$f1,$f2 #
	s.s $f1,2132($sp) #t609
#=====//
#  Assignment //
	l.s $f1, 2132($sp) #t609
	lw $t1, 2120($sp) #t608
	s.s $f1, ($t1) #t608
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,2136($sp) #t615
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,2348($sp) #t616
#=====//
#  Arithmet / Relation  //
	lw $t0,2348($sp) #t616
	lw $t1,2136($sp) #t616
	add $t0,$t0,$t1 #
	sw $t0,2352($sp) #t614
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,2356($sp) #t617
#=====//
#  Assignment //
	lw $t0, 2356($sp) #t617
	lw $t1, 2352($sp) #t614
	sw $t0, ($t1) #t614
#=====//
#  &  //
	la $t0,344($sp) #nl
	sw $t0,2360($sp) #t620
#=====//
#  Literal Int/Char  //
	li $t0,'
' #'\n'
	sw $t0,2364($sp) #t621
#=====//
#  Assignment //
	lw $t0, 2364($sp) #t621
	lw $t1, 2360($sp) #t620
	sw $t0, ($t1) #t620
#=====//
#  &  //
	la $t0,test #test
	sw $t0,2368($sp) #t624
#=====//
#  Literal Int/Char  //
	li $t0,54 #54
	sw $t0,2372($sp) #t625
#=====//
#  Assignment //
	lw $t0, 2372($sp) #t625
	lw $t1, 2368($sp) #t624
	sw $t0, ($t1) #t624
#=====//
#  &  //
	la $t0,252($sp) #array
	sw $t0,2376($sp) #t629
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2380($sp) #t630
#=====//
#  Arithmet / Relation  //
	lw $t0,2380($sp) #t630
	li $t1,4 #t630
	mul $t0,$t0,$t1 #
	sw $t0,2384($sp) #t631
#=====//
#  Arithmet / Relation  //
	lw $t0,2376($sp) #t629
	lw $t1,2384($sp) #t629
	add $t0,$t0,$t1 #
	sw $t0,2388($sp) #t628
#=====//
#  Literal Int/Char  //
	li $t0,65 #65
	sw $t0,2392($sp) #t632
#=====//
#  Assignment //
	lw $t0, 2392($sp) #t632
	lw $t1, 2388($sp) #t628
	sw $t0, ($t1) #t628
#=====//
#  Function Call:test_CharPrint //
	sw $ra, 4772($sp)
	sub $sp, $sp, 320
	sw $fp, 308($sp)
	add $fp,$sp, 320
	jal test_CharPrint
	lw $ra, 4772($sp)
	sw $v0, 2396($sp)  
#=====//
#  &  //
	la $t0,336($sp) #x
	sw $t0,2400($sp) #t637
#=====//
#  &  //
	la $t0,252($sp) #array
	sw $t0,2404($sp) #t639
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2408($sp) #t640
#=====//
#  Arithmet / Relation  //
	lw $t0,2408($sp) #t640
	li $t1,4 #t640
	mul $t0,$t0,$t1 #
	sw $t0,2412($sp) #t641
#=====//
#  Arithmet / Relation  //
	lw $t0,2404($sp) #t639
	lw $t1,2412($sp) #t639
	add $t0,$t0,$t1 #
	sw $t0,2416($sp) #t638
#=====//
#  Assignment //
	lw $t0, 2416($sp) #t638
	lw $t1, 2400($sp) #t637
	lw $t0, ($t0) #
	sw $t0, ($t1) #t637
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
	sw $t0,2452($sp) #t657
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2456($sp) #t658
#=====//
#  Arithmet / Relation  //
	lw $t0,2456($sp) #t658
	li $t1,4 #t658
	mul $t0,$t0,$t1 #
	sw $t0,2460($sp) #t659
#=====//
#  Arithmet / Relation  //
	lw $t0,2452($sp) #t657
	lw $t1,2460($sp) #t657
	add $t0,$t0,$t1 #
	sw $t0,2464($sp) #t656
#=====//
#  Assignment //
	lw $t0, 2464($sp) #t656
	lw $t1, 2464($sp) #t656
	lw $t0, ($t0) #
	sw $t0, 2464($sp) #t656
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,2464($sp) #t656
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,2484($sp) #t666
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,2496($sp) #t667
#=====//
#  Arithmet / Relation  //
	lw $t0,2496($sp) #t667
	lw $t1,2484($sp) #t667
	add $t0,$t0,$t1 #
	sw $t0,2500($sp) #t665
#=====//
#  Literal Float  //
	li.s $f1,4.56700 #4.56700
	s.s $f1,2504($sp) #t668
#=====//
#  Assignment //
	l.s $f1, 2504($sp) #t668
	lw $t1, 2500($sp) #t665
	s.s $f1, ($t1) #t665
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
	sw $ra, 4772($sp)
	sub $sp, $sp, 48
	sw $fp, 36($sp)
	add $fp,$sp, 48
	jal ModifyTestArr
	lw $ra, 4772($sp)
	sw $v0, 2524($sp)  
#=====//
#  &  //
	la $t0,testArr #testArr
	sw $t0,2528($sp) #t680
#=====//
#  Literal Int/Char  //
	li $t0,5 #5
	sw $t0,2532($sp) #t681
#=====//
#  Arithmet / Relation  //
	lw $t0,2532($sp) #t681
	li $t1,4 #t681
	mul $t0,$t0,$t1 #
	sw $t0,2536($sp) #t682
#=====//
#  Arithmet / Relation  //
	lw $t0,2528($sp) #t680
	lw $t1,2536($sp) #t680
	add $t0,$t0,$t1 #
	sw $t0,2540($sp) #t679
#=====//
#  Assignment //
	lw $t0, 2540($sp) #t679
	lw $t1, 2540($sp) #t679
	lw $t0, ($t0) #
	sw $t0, 2540($sp) #t679
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,2540($sp) #t679
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
	sw $ra, 4772($sp)
	sub $sp, $sp, 148
	sw $fp, 136($sp)
	add $fp,$sp, 148
	jal arithmetic_Int
	lw $ra, 4772($sp)
	sw $v0, 2584($sp)  
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,2588($sp) #t700
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,2800($sp) #t701
#=====//
#  Arithmet / Relation  //
	lw $t0,2800($sp) #t701
	lw $t1,2588($sp) #t701
	add $t0,$t0,$t1 #
	sw $t0,2804($sp) #t699
#=====//
#  Literal Int/Char  //
	li $t0,2224 #2224
	sw $t0,2808($sp) #t702
#=====//
#  Assignment //
	lw $t0, 2808($sp) #t702
	lw $t1, 2804($sp) #t699
	sw $t0, ($t1) #t699
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,2812($sp) #t706
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,2824($sp) #t707
#=====//
#  Arithmet / Relation  //
	lw $t0,2824($sp) #t707
	lw $t1,2812($sp) #t707
	add $t0,$t0,$t1 #
	sw $t0,2828($sp) #t705
#=====//
#  Assignment //
	lw $t0, 2828($sp) #t705
	lw $t1, 2828($sp) #t705
	lw $t0, ($t0) #
	sw $t0, 2828($sp) #t705
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,2828($sp) #t705
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2848($sp) #t713
#=====//
#  Literal Int/Char  //
	li $t0,6 #6
	sw $t0,2852($sp) #t714
#=====//
#  Assignment //
	lw $t0, 2852($sp) #t714
	lw $t1, 2848($sp) #t713
	sw $t0, ($t1) #t713
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2856($sp) #t717
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2860($sp) #t719
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2864($sp) #t720
#=====//
#  Arithmet / Relation  //
	lw $t0,2860($sp) #t719
	lw $t1,2864($sp) #t719
	lw $t0, ($t0) #LEEEEFT
	add $t0,$t0,$t1 #
	sw $t0,2868($sp) #t718
#=====//
#  Assignment //
	lw $t0, 2868($sp) #t718
	lw $t1, 2856($sp) #t717
	sw $t0, ($t1) #t717
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2872($sp) #t722
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2876($sp) #t726
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2880($sp) #t728
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2884($sp) #t729
#=====//
#  Arithmet / Relation  //
	lw $t0,2880($sp) #t728
	lw $t1,2884($sp) #t728
	lw $t0, ($t0) #LEEEEFT
	add $t0,$t0,$t1 #
	sw $t0,2888($sp) #t727
#=====//
#  Assignment //
	lw $t0, 2888($sp) #t727
	lw $t1, 2876($sp) #t726
	sw $t0, ($t1) #t726
#=====//
#  Function Call:RecursiveFunction //
	sw $ra, 4772($sp)
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
	lw $ra, 4772($sp)
	sw $v0, 2896($sp)  
#=====//
#  Function Call:MutualRecursion_One //
	sw $ra, 4772($sp)
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
	lw $ra, 4772($sp)
	sw $v0, 2904($sp)  
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,2908($sp) #t739
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,2920($sp) #t740
#=====//
#  Arithmet / Relation  //
	lw $t0,2920($sp) #t740
	lw $t1,2908($sp) #t740
	add $t0,$t0,$t1 #
	sw $t0,2924($sp) #t738
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,2928($sp) #t741
#=====//
#  Assignment //
	lw $t0, 2928($sp) #t741
	lw $t1, 2924($sp) #t738
	sw $t0, ($t1) #t738
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2932($sp) #t744
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2936($sp) #t745
#=====//
#  Assignment //
	lw $t0, 2936($sp) #t745
	lw $t1, 2932($sp) #t744
	sw $t0, ($t1) #t744
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2940($sp) #t748
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2944($sp) #t754
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2948($sp) #t755
#=====//
#  Arithmet / Relation  //
	lw $t0,2944($sp) #t754
	lw $t1,2948($sp) #t754
	lw $t0, ($t0) #LEEEEFT
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2952($sp) #t753
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2956($sp) #t756
#=====//
#  Arithmet / Relation  //
	lw $t0,2952($sp) #t753
	lw $t1,2956($sp) #t753
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2960($sp) #t752
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2964($sp) #t757
#=====//
#  Arithmet / Relation  //
	lw $t0,2960($sp) #t752
	lw $t1,2964($sp) #t752
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2968($sp) #t751
#=====//
#  &  //
	la $t0,340($sp) #y
	sw $t0,2972($sp) #t758
#=====//
#  Arithmet / Relation  //
	lw $t0,2968($sp) #t751
	lw $t1,2972($sp) #t751
	lw $t1, ($t1) #RIIIIIIGHT
	add $t0,$t0,$t1 #
	sw $t0,2976($sp) #t750
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,2980($sp) #t759
#=====//
#  Arithmet / Relation  //
	lw $t0,2976($sp) #t750
	lw $t1,2980($sp) #t750
	add $t0,$t0,$t1 #
	sw $t0,2984($sp) #t749
#=====//
#  Assignment //
	lw $t0, 2984($sp) #t749
	lw $t1, 2940($sp) #t748
	sw $t0, ($t1) #t748
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,340($sp) #y
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,2996($sp) #t766
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3208($sp) #t768
#=====//
#  Literal Int/Char  //
	li $t0,34 #34
	sw $t0,3212($sp) #t769
#=====//
#  Arithmet / Relation  //
	lw $t0,3212($sp) #t769
	li $t1,4 #t769
	mul $t0,$t0,$t1 #
	sw $t0,3216($sp) #t770
#=====//
#  Arithmet / Relation  //
	lw $t0,3208($sp) #t768
	lw $t1,3216($sp) #t768
	add $t0,$t0,$t1 #
	sw $t0,3220($sp) #t767
#=====//
#  Arithmet / Relation  //
	lw $t0,3220($sp) #t767
	lw $t1,2996($sp) #t767
	add $t0,$t0,$t1 #
	sw $t0,3224($sp) #t765
#=====//
#  Literal Int/Char  //
	li $t0,77 #77
	sw $t0,3228($sp) #t771
#=====//
#  Assignment //
	lw $t0, 3228($sp) #t771
	lw $t1, 3224($sp) #t765
	sw $t0, ($t1) #t765
#=====//
#  &  //
	la $t0,floatTest #floatTest
	sw $t0,3232($sp) #t774
#=====//
#  Literal Float  //
	li.s $f1,999.900 #999.900
	s.s $f1,3236($sp) #t775
#=====//
#  Assignment //
	l.s $f1, 3236($sp) #t775
	lw $t1, 3232($sp) #t774
	s.s $f1, ($t1) #t774
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,3240($sp) #t779
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3452($sp) #t781
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,3456($sp) #t782
#=====//
#  Arithmet / Relation  //
	lw $t0,3456($sp) #t782
	li $t1,4 #t782
	mul $t0,$t0,$t1 #
	sw $t0,3460($sp) #t783
#=====//
#  Arithmet / Relation  //
	lw $t0,3452($sp) #t781
	lw $t1,3460($sp) #t781
	add $t0,$t0,$t1 #
	sw $t0,3464($sp) #t780
#=====//
#  Arithmet / Relation  //
	lw $t0,3464($sp) #t780
	lw $t1,3240($sp) #t780
	add $t0,$t0,$t1 #
	sw $t0,3468($sp) #t778
#=====//
#  Literal Int/Char  //
	li $t0,2014 #2014
	sw $t0,3472($sp) #t785
#=====//
#  Literal Int/Char  //
	li $t0,1 #1
	sw $t0,3476($sp) #t786
#=====//
#  Arithmet / Relation  //
	lw $t0,3472($sp) #t785
	lw $t1,3476($sp) #t785
	add $t0,$t0,$t1 #
	sw $t0,3480($sp) #t784
#=====//
#  Assignment //
	lw $t0, 3480($sp) #t784
	lw $t1, 3468($sp) #t778
	sw $t0, ($t1) #t778
#=====//
#  &  //
	la $t0,0($sp) #db
	sw $t0,3484($sp) #t790
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,3700($sp) #t792
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3704($sp) #t794
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,3708($sp) #t795
#=====//
#  Arithmet / Relation  //
	lw $t0,3708($sp) #t795
	li $t1,4 #t795
	mul $t0,$t0,$t1 #
	sw $t0,3712($sp) #t796
#=====//
#  Arithmet / Relation  //
	lw $t0,3704($sp) #t794
	lw $t1,3712($sp) #t794
	add $t0,$t0,$t1 #
	sw $t0,3716($sp) #t793
#=====//
#  Arithmet / Relation  //
	lw $t0,3716($sp) #t793
	lw $t1,3700($sp) #t793
	add $t0,$t0,$t1 #
	sw $t0,3720($sp) #t791
#=====//
#  Arithmet / Relation  //
	lw $t0,3720($sp) #t791
	lw $t1,3484($sp) #t791
	add $t0,$t0,$t1 #
	sw $t0,3724($sp) #t789
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,3728($sp) #t798
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,3940($sp) #t800
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,3944($sp) #t801
#=====//
#  Arithmet / Relation  //
	lw $t0,3944($sp) #t801
	li $t1,4 #t801
	mul $t0,$t0,$t1 #
	sw $t0,3948($sp) #t802
#=====//
#  Arithmet / Relation  //
	lw $t0,3940($sp) #t800
	lw $t1,3948($sp) #t800
	add $t0,$t0,$t1 #
	sw $t0,3952($sp) #t799
#=====//
#  Arithmet / Relation  //
	lw $t0,3952($sp) #t799
	lw $t1,3728($sp) #t799
	add $t0,$t0,$t1 #
	sw $t0,3956($sp) #t797
#=====//
#  Assignment //
	lw $t0, 3956($sp) #t797
	lw $t1, 3724($sp) #t789
	lw $t0, ($t0) #
	sw $t0, ($t1) #t789
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,3960($sp) #t806
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,4172($sp) #t808
#=====//
#  Literal Int/Char  //
	li $t0,35 #35
	sw $t0,4176($sp) #t809
#=====//
#  Arithmet / Relation  //
	lw $t0,4176($sp) #t809
	li $t1,4 #t809
	mul $t0,$t0,$t1 #
	sw $t0,4180($sp) #t810
#=====//
#  Arithmet / Relation  //
	lw $t0,4172($sp) #t808
	lw $t1,4180($sp) #t808
	add $t0,$t0,$t1 #
	sw $t0,4184($sp) #t807
#=====//
#  Arithmet / Relation  //
	lw $t0,4184($sp) #t807
	lw $t1,3960($sp) #t807
	add $t0,$t0,$t1 #
	sw $t0,4188($sp) #t805
#=====//
#  Assignment //
	lw $t0, 4188($sp) #t805
	lw $t1, 4188($sp) #t805
	lw $t0, ($t0) #
	sw $t0, 4188($sp) #t805
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4188($sp) #t805
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
	sw $t0,4224($sp) #t823
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,4440($sp) #t825
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,4444($sp) #t827
#=====//
#  Literal Int/Char  //
	li $t0,21 #21
	sw $t0,4448($sp) #t828
#=====//
#  Arithmet / Relation  //
	lw $t0,4448($sp) #t828
	li $t1,4 #t828
	mul $t0,$t0,$t1 #
	sw $t0,4452($sp) #t829
#=====//
#  Arithmet / Relation  //
	lw $t0,4444($sp) #t827
	lw $t1,4452($sp) #t827
	add $t0,$t0,$t1 #
	sw $t0,4456($sp) #t826
#=====//
#  Arithmet / Relation  //
	lw $t0,4456($sp) #t826
	lw $t1,4440($sp) #t826
	add $t0,$t0,$t1 #
	sw $t0,4460($sp) #t824
#=====//
#  Arithmet / Relation  //
	lw $t0,4460($sp) #t824
	lw $t1,4224($sp) #t824
	add $t0,$t0,$t1 #
	sw $t0,4464($sp) #t822
#=====//
#  Assignment //
	lw $t0, 4464($sp) #t822
	lw $t1, 4464($sp) #t822
	lw $t0, ($t0) #
	sw $t0, 4464($sp) #t822
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4464($sp) #t822
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,cyberSix #cyberSix
	sw $t0,4484($sp) #t836
#=====//
#  Literal Int/Char  //
	li $t0,4 #4
	sw $t0,4696($sp) #t837
#=====//
#  Arithmet / Relation  //
	lw $t0,4696($sp) #t837
	lw $t1,4484($sp) #t837
	add $t0,$t0,$t1 #
	sw $t0,4700($sp) #t835
#=====//
#  Assignment //
	lw $t0, 4700($sp) #t835
	lw $t1, 4700($sp) #t835
	lw $t0, ($t0) #
	sw $t0, 4700($sp) #t835
#=====//
#  SysCall Put_I //
	li $v0,1 #
	lw $a0,4700($sp) #t835
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  &  //
	la $t0,240($sp) #myTestStruct
	sw $t0,4720($sp) #t844
#=====//
#  Literal Int/Char  //
	li $t0,8 #8
	sw $t0,4732($sp) #t845
#=====//
#  Arithmet / Relation  //
	lw $t0,4732($sp) #t845
	lw $t1,4720($sp) #t845
	add $t0,$t0,$t1 #
	sw $t0,4736($sp) #t843
#=====//
#  Assignment //
	lw $t0, 4736($sp) #t843
	lw $t1, 4736($sp) #t843
	lw $t0, ($t0) #
	sw $t0, 4736($sp) #t843
#=====//
#  SysCall Put_F //
	li $v0,2 #
	l.s $f12,4736($sp) #t843
	syscall
#=====//
#  SysCall Put_C //
	li $v0,4 #
	la $a0,344($sp) #nl
	syscall
#=====//
#  Literal Int/Char  //
	li $t0,0 #0
	sw $t0,4756($sp) #t851
#=====//
# Return Called
	lw $v0, 4756($sp)
	lw $fp, 4768($sp)
	add $sp, $sp, 4780
	jr $ra
#=====//
	li $v0,10
	syscall
