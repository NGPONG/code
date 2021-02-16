multstore:
	endbr64
	push rbx
	mov	rbx, rdx
	call mult2@PLT
	mov	QWORD PTR [rbx], rax
	pop	rbx

	ret
