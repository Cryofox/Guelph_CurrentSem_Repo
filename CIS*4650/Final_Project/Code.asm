Fire2:
		//  *=  //
	lw $t0,4($sp) //x
	sw $t0,24($sp) //t6
ArrayAccess:
		//  *=  //
	sw 0,-85($sp) //t23
		//  *=  //
	lw $t0,-41($sp) //t33
	sw $t0,64($sp) //t32
WhileLoop:
		//  *=  //
	sw 0,4($sp) //t55
Label_t58:
IfCall:
		//  *=  //
	sw 0,8($sp) //t80
		//  *=  //
	sw 0,4($sp) //t84
Label_t87:
Label_t109:
RecursiveFunction:
Label_t124:
Label_t130:
ForLoop:
		//  *=  //
	sw 0,4($sp) //t156
Label_t159:
main:
	li $v0,10
	syscall
