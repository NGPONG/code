	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"hello,world!"
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB39:
	.cfi_startproc
	endbr64
	leaq	.LC0(%rip), %rax
	ret
	.cfi_endproc
.LFE39:
	.size	foo, .-foo
	.globl	main
	.type	main, @function
main:
	endbr64
	subq	$8, %rsp
	movl	$0, %ecx
	movl	$256, %edx
	movl	$0, %esi
	movl	$1024, %edi
	call	foo
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE40:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.1.0-1ubuntu1~20.04) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
