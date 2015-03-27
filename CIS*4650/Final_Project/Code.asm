Fire2:
		//  *=  //
	lw $t0,0($sp) //x
	sw $t0,0($sp) //t6
		//  *=  //
	sw 0,0($sp) //t11
ArrayAccess:
		//  *=  //
	sw 0,-101($sp) //t23
		//  *=  //
	lw $t0,-101($sp) //t33
	sw $t0,0($sp) //t32
WhileLoop:
		//  *=  //
	sw 0,0($sp) //t55
Label_t58:
		//  *=  //
	sw 0,0($sp) //t65
IfCall:
		//  *=  //
	sw 0,0($sp) //t80
		//  *=  //
	sw 0,0($sp) //t84
		//  *=  //
	sw 0,0($sp) //t104
Label_t87:
Label_t109:
RecursiveFunction:
Label_t124:
		//  *=  //
	sw 0,0($sp) //t141
Label_t130:
ForLoop:
		//  *=  //
	sw 0,0($sp) //t156
Label_t159:
		//  *=  //
	sw 0,0($sp) //t165
main:
	li $v0,10
	syscall
