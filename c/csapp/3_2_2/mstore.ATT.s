multstore:
	endbr64
	pushq	%rbx
	movq %rdx, %rbx
	call mult2@PLT
	movq %rax, (%rbx)
	popq %rbx

	ret
