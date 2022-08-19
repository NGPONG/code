	.file	"main.cpp"
	.text
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.align 8
	.type	_ZNSt8__detailL25__platform_wait_alignmentE, @object
	.size	_ZNSt8__detailL25__platform_wait_alignmentE, 8
_ZNSt8__detailL25__platform_wait_alignmentE:
	.quad	4
	.align 4
	.type	_ZNSt8__detailL21__atomic_spin_count_1E, @object
	.size	_ZNSt8__detailL21__atomic_spin_count_1E, 4
_ZNSt8__detailL21__atomic_spin_count_1E:
	.long	12
	.align 4
	.type	_ZNSt8__detailL21__atomic_spin_count_2E, @object
	.size	_ZNSt8__detailL21__atomic_spin_count_2E, 4
_ZNSt8__detailL21__atomic_spin_count_2E:
	.long	4
.LC0:
	.string	"BASE constructor"
	.section	.text._ZN4BASEC2Ev,"axG",@progbits,_ZN4BASEC5Ev,comdat
	.align 2
	.weak	_ZN4BASEC2Ev
	.type	_ZN4BASEC2Ev, @function
_ZN4BASEC2Ev:
.LFB3954:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3954:
	.size	_ZN4BASEC2Ev, .-_ZN4BASEC2Ev
	.weak	_ZN4BASEC1Ev
	.set	_ZN4BASEC1Ev,_ZN4BASEC2Ev
	.section	.rodata
.LC1:
	.string	"BASE destructor"
	.section	.text._ZN4BASED2Ev,"axG",@progbits,_ZN4BASED5Ev,comdat
	.align 2
	.weak	_ZN4BASED2Ev
	.type	_ZN4BASED2Ev, @function
_ZN4BASED2Ev:
.LFB3960:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3960
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3960:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZN4BASED2Ev,"aG",@progbits,_ZN4BASED5Ev,comdat
.LLSDA3960:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3960-.LLSDACSB3960
.LLSDACSB3960:
.LLSDACSE3960:
	.section	.text._ZN4BASED2Ev,"axG",@progbits,_ZN4BASED5Ev,comdat
	.size	_ZN4BASED2Ev, .-_ZN4BASED2Ev
	.weak	_ZN4BASED1Ev
	.set	_ZN4BASED1Ev,_ZN4BASED2Ev
	.section	.rodata
.LC2:
	.string	"BASE move constructor"
	.section	.text._ZN4BASEC2EOS_,"axG",@progbits,_ZN4BASEC5EOS_,comdat
	.align 2
	.weak	_ZN4BASEC2EOS_
	.type	_ZN4BASEC2EOS_, @function
_ZN4BASEC2EOS_:
.LFB3966:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3966:
	.size	_ZN4BASEC2EOS_, .-_ZN4BASEC2EOS_
	.weak	_ZN4BASEC1EOS_
	.set	_ZN4BASEC1EOS_,_ZN4BASEC2EOS_
	.globl	gb
	.bss
	.type	gb, @object
	.size	gb, 1
gb:
	.zero	1
	.text
	.globl	_Z4TESTv
	.type	_Z4TESTv, @function
_Z4TESTv:
.LFB3970:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	gb(%rip), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIR4BASEEONSt16remove_referenceIT_E4typeEOS3_
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN4BASEC1EOS_
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3970:
	.size	_Z4TESTv, .-_Z4TESTv
	.globl	_Z3foov
	.type	_Z3foov, @function
_Z3foov:
.LFB3971:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_Z4TESTv
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	movq	-24(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3971:
	.size	_Z3foov, .-_Z3foov
	.globl	main
	.type	main, @function
main:
.LFB3972:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3972
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-25(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_Z3foov
.LEHE0:
	movl	$2000, %edi
.LEHB1:
	call	sleep@PLT
.LEHE1:
	movl	$0, %ebx
	leaq	-25(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4BASED1Ev
	movl	%ebx, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L12
	jmp	.L14
.L13:
	endbr64
	movq	%rax, %rbx
	leaq	-25(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4BASED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume@PLT
.LEHE2:
.L14:
	call	__stack_chk_fail@PLT
.L12:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3972:
	.section	.gcc_except_table,"a",@progbits
.LLSDA3972:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3972-.LLSDACSB3972
.LLSDACSB3972:
	.uleb128 .LEHB0-.LFB3972
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB3972
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L13-.LFB3972
	.uleb128 0
	.uleb128 .LEHB2-.LFB3972
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE3972:
	.text
	.size	main, .-main
	.section	.text._ZSt4moveIR4BASEEONSt16remove_referenceIT_E4typeEOS3_,"axG",@progbits,_ZSt4moveIR4BASEEONSt16remove_referenceIT_E4typeEOS3_,comdat
	.weak	_ZSt4moveIR4BASEEONSt16remove_referenceIT_E4typeEOS3_
	.type	_ZSt4moveIR4BASEEONSt16remove_referenceIT_E4typeEOS3_, @function
_ZSt4moveIR4BASEEONSt16remove_referenceIT_E4typeEOS3_:
.LFB4466:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4466:
	.size	_ZSt4moveIR4BASEEONSt16remove_referenceIT_E4typeEOS3_, .-_ZSt4moveIR4BASEEONSt16remove_referenceIT_E4typeEOS3_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB4938:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L19
	cmpl	$65535, -8(%rbp)
	jne	.L19
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
	leaq	gb(%rip), %rax
	movq	%rax, %rdi
	call	_ZN4BASEC1Ev
	leaq	__dso_handle(%rip), %rax
	movq	%rax, %rdx
	leaq	gb(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZN4BASED1Ev(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L19:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4938:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_gb, @function
_GLOBAL__sub_I_gb:
.LFB4939:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4939:
	.size	_GLOBAL__sub_I_gb, .-_GLOBAL__sub_I_gb
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_gb
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
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
