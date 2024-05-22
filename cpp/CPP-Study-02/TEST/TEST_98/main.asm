
main:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 72 2f 00 00    	push   0x2f72(%rip)        # 3f98 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 73 2f 00 00 	bnd jmp *0x2f73(%rip)        # 3fa0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	push   $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	push   $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	push   $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    106f:	90                   	nop

Disassembly of section .plt.got:

0000000000001070 <__cxa_finalize@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 4d 2f 00 00 	bnd jmp *0x2f4d(%rip)        # 3fc8 <__cxa_finalize@GLIBC_2.2.5>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001080 <__cxa_atexit@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 1d 2f 00 00 	bnd jmp *0x2f1d(%rip)        # 3fa8 <__cxa_atexit@GLIBC_2.2.5>
    108b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001090 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 15 2f 00 00 	bnd jmp *0x2f15(%rip)        # 3fb0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GLIBCXX_3.4>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010a0 <_ZNSolsEPFRSoS_E@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 0d 2f 00 00 	bnd jmp *0x2f0d(%rip)        # 3fb8 <_ZNSolsEPFRSoS_E@GLIBCXX_3.4>
    10ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010b0 <_ZNSt8ios_base4InitC1Ev@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 05 2f 00 00 	bnd jmp *0x2f05(%rip)        # 3fc0 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    10bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000010c0 <_start>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	31 ed                	xor    %ebp,%ebp
    10c6:	49 89 d1             	mov    %rdx,%r9
    10c9:	5e                   	pop    %rsi
    10ca:	48 89 e2             	mov    %rsp,%rdx
    10cd:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10d1:	50                   	push   %rax
    10d2:	54                   	push   %rsp
    10d3:	45 31 c0             	xor    %r8d,%r8d
    10d6:	31 c9                	xor    %ecx,%ecx
    10d8:	48 8d 3d ca 00 00 00 	lea    0xca(%rip),%rdi        # 11a9 <main>
    10df:	ff 15 f3 2e 00 00    	call   *0x2ef3(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    10e5:	f4                   	hlt    
    10e6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    10ed:	00 00 00 

00000000000010f0 <deregister_tm_clones>:
    10f0:	48 8d 3d 19 2f 00 00 	lea    0x2f19(%rip),%rdi        # 4010 <__TMC_END__>
    10f7:	48 8d 05 12 2f 00 00 	lea    0x2f12(%rip),%rax        # 4010 <__TMC_END__>
    10fe:	48 39 f8             	cmp    %rdi,%rax
    1101:	74 15                	je     1118 <deregister_tm_clones+0x28>
    1103:	48 8b 05 d6 2e 00 00 	mov    0x2ed6(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    110a:	48 85 c0             	test   %rax,%rax
    110d:	74 09                	je     1118 <deregister_tm_clones+0x28>
    110f:	ff e0                	jmp    *%rax
    1111:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1118:	c3                   	ret    
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <register_tm_clones>:
    1120:	48 8d 3d e9 2e 00 00 	lea    0x2ee9(%rip),%rdi        # 4010 <__TMC_END__>
    1127:	48 8d 35 e2 2e 00 00 	lea    0x2ee2(%rip),%rsi        # 4010 <__TMC_END__>
    112e:	48 29 fe             	sub    %rdi,%rsi
    1131:	48 89 f0             	mov    %rsi,%rax
    1134:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1138:	48 c1 f8 03          	sar    $0x3,%rax
    113c:	48 01 c6             	add    %rax,%rsi
    113f:	48 d1 fe             	sar    %rsi
    1142:	74 14                	je     1158 <register_tm_clones+0x38>
    1144:	48 8b 05 a5 2e 00 00 	mov    0x2ea5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    114b:	48 85 c0             	test   %rax,%rax
    114e:	74 08                	je     1158 <register_tm_clones+0x38>
    1150:	ff e0                	jmp    *%rax
    1152:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1158:	c3                   	ret    
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <__do_global_dtors_aux>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	80 3d e5 2f 00 00 00 	cmpb   $0x0,0x2fe5(%rip)        # 4150 <completed.0>
    116b:	75 2b                	jne    1198 <__do_global_dtors_aux+0x38>
    116d:	55                   	push   %rbp
    116e:	48 83 3d 52 2e 00 00 	cmpq   $0x0,0x2e52(%rip)        # 3fc8 <__cxa_finalize@GLIBC_2.2.5>
    1175:	00 
    1176:	48 89 e5             	mov    %rsp,%rbp
    1179:	74 0c                	je     1187 <__do_global_dtors_aux+0x27>
    117b:	48 8b 3d 86 2e 00 00 	mov    0x2e86(%rip),%rdi        # 4008 <__dso_handle>
    1182:	e8 e9 fe ff ff       	call   1070 <__cxa_finalize@plt>
    1187:	e8 64 ff ff ff       	call   10f0 <deregister_tm_clones>
    118c:	c6 05 bd 2f 00 00 01 	movb   $0x1,0x2fbd(%rip)        # 4150 <completed.0>
    1193:	5d                   	pop    %rbp
    1194:	c3                   	ret    
    1195:	0f 1f 00             	nopl   (%rax)
    1198:	c3                   	ret    
    1199:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011a0 <frame_dummy>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	e9 77 ff ff ff       	jmp    1120 <register_tm_clones>

00000000000011a9 <main>:
    11a9:	f3 0f 1e fa          	endbr64 
    11ad:	55                   	push   %rbp
    11ae:	48 89 e5             	mov    %rsp,%rbp
    11b1:	48 83 ec 20          	sub    $0x20,%rsp
    11b5:	89 7d ec             	mov    %edi,-0x14(%rbp)
    11b8:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    11bc:	48 8d 05 41 0e 00 00 	lea    0xe41(%rip),%rax        # 2004 <_IO_stdin_used+0x4>
    11c3:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    11c7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    11cb:	48 89 c6             	mov    %rax,%rsi
    11ce:	48 8d 05 6b 2e 00 00 	lea    0x2e6b(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    11d5:	48 89 c7             	mov    %rax,%rdi
    11d8:	e8 b3 fe ff ff       	call   1090 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    11dd:	48 8b 15 ec 2d 00 00 	mov    0x2dec(%rip),%rdx        # 3fd0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    11e4:	48 89 d6             	mov    %rdx,%rsi
    11e7:	48 89 c7             	mov    %rax,%rdi
    11ea:	e8 b1 fe ff ff       	call   10a0 <_ZNSolsEPFRSoS_E@plt>
    11ef:	b8 00 00 00 00       	mov    $0x0,%eax
    11f4:	c9                   	leave  
    11f5:	c3                   	ret    

00000000000011f6 <_Z41__static_initialization_and_destruction_0ii>:
    11f6:	f3 0f 1e fa          	endbr64 
    11fa:	55                   	push   %rbp
    11fb:	48 89 e5             	mov    %rsp,%rbp
    11fe:	48 83 ec 10          	sub    $0x10,%rsp
    1202:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1205:	89 75 f8             	mov    %esi,-0x8(%rbp)
    1208:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    120c:	75 3b                	jne    1249 <_Z41__static_initialization_and_destruction_0ii+0x53>
    120e:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    1215:	75 32                	jne    1249 <_Z41__static_initialization_and_destruction_0ii+0x53>
    1217:	48 8d 05 33 2f 00 00 	lea    0x2f33(%rip),%rax        # 4151 <_ZStL8__ioinit>
    121e:	48 89 c7             	mov    %rax,%rdi
    1221:	e8 8a fe ff ff       	call   10b0 <_ZNSt8ios_base4InitC1Ev@plt>
    1226:	48 8d 05 db 2d 00 00 	lea    0x2ddb(%rip),%rax        # 4008 <__dso_handle>
    122d:	48 89 c2             	mov    %rax,%rdx
    1230:	48 8d 05 1a 2f 00 00 	lea    0x2f1a(%rip),%rax        # 4151 <_ZStL8__ioinit>
    1237:	48 89 c6             	mov    %rax,%rsi
    123a:	48 8b 05 b7 2d 00 00 	mov    0x2db7(%rip),%rax        # 3ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    1241:	48 89 c7             	mov    %rax,%rdi
    1244:	e8 37 fe ff ff       	call   1080 <__cxa_atexit@plt>
    1249:	90                   	nop
    124a:	c9                   	leave  
    124b:	c3                   	ret    

000000000000124c <_GLOBAL__sub_I_main>:
    124c:	f3 0f 1e fa          	endbr64 
    1250:	55                   	push   %rbp
    1251:	48 89 e5             	mov    %rsp,%rbp
    1254:	be ff ff 00 00       	mov    $0xffff,%esi
    1259:	bf 01 00 00 00       	mov    $0x1,%edi
    125e:	e8 93 ff ff ff       	call   11f6 <_Z41__static_initialization_and_destruction_0ii>
    1263:	5d                   	pop    %rbp
    1264:	c3                   	ret    

Disassembly of section .fini:

0000000000001268 <_fini>:
    1268:	f3 0f 1e fa          	endbr64 
    126c:	48 83 ec 08          	sub    $0x8,%rsp
    1270:	48 83 c4 08          	add    $0x8,%rsp
    1274:	c3                   	ret    

main:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 72 2f 00 00    	push   0x2f72(%rip)        # 3f98 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 73 2f 00 00 	bnd jmp *0x2f73(%rip)        # 3fa0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	push   $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	push   $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	push   $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    106f:	90                   	nop

Disassembly of section .plt.got:

0000000000001070 <__cxa_finalize@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 4d 2f 00 00 	bnd jmp *0x2f4d(%rip)        # 3fc8 <__cxa_finalize@GLIBC_2.2.5>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001080 <__cxa_atexit@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 1d 2f 00 00 	bnd jmp *0x2f1d(%rip)        # 3fa8 <__cxa_atexit@GLIBC_2.2.5>
    108b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001090 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 15 2f 00 00 	bnd jmp *0x2f15(%rip)        # 3fb0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GLIBCXX_3.4>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010a0 <_ZNSolsEPFRSoS_E@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 0d 2f 00 00 	bnd jmp *0x2f0d(%rip)        # 3fb8 <_ZNSolsEPFRSoS_E@GLIBCXX_3.4>
    10ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010b0 <_ZNSt8ios_base4InitC1Ev@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 05 2f 00 00 	bnd jmp *0x2f05(%rip)        # 3fc0 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    10bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000010c0 <_start>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	31 ed                	xor    %ebp,%ebp
    10c6:	49 89 d1             	mov    %rdx,%r9
    10c9:	5e                   	pop    %rsi
    10ca:	48 89 e2             	mov    %rsp,%rdx
    10cd:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10d1:	50                   	push   %rax
    10d2:	54                   	push   %rsp
    10d3:	45 31 c0             	xor    %r8d,%r8d
    10d6:	31 c9                	xor    %ecx,%ecx
    10d8:	48 8d 3d ca 00 00 00 	lea    0xca(%rip),%rdi        # 11a9 <main>
    10df:	ff 15 f3 2e 00 00    	call   *0x2ef3(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    10e5:	f4                   	hlt    
    10e6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    10ed:	00 00 00 

00000000000010f0 <deregister_tm_clones>:
    10f0:	48 8d 3d 19 2f 00 00 	lea    0x2f19(%rip),%rdi        # 4010 <__TMC_END__>
    10f7:	48 8d 05 12 2f 00 00 	lea    0x2f12(%rip),%rax        # 4010 <__TMC_END__>
    10fe:	48 39 f8             	cmp    %rdi,%rax
    1101:	74 15                	je     1118 <deregister_tm_clones+0x28>
    1103:	48 8b 05 d6 2e 00 00 	mov    0x2ed6(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    110a:	48 85 c0             	test   %rax,%rax
    110d:	74 09                	je     1118 <deregister_tm_clones+0x28>
    110f:	ff e0                	jmp    *%rax
    1111:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1118:	c3                   	ret    
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <register_tm_clones>:
    1120:	48 8d 3d e9 2e 00 00 	lea    0x2ee9(%rip),%rdi        # 4010 <__TMC_END__>
    1127:	48 8d 35 e2 2e 00 00 	lea    0x2ee2(%rip),%rsi        # 4010 <__TMC_END__>
    112e:	48 29 fe             	sub    %rdi,%rsi
    1131:	48 89 f0             	mov    %rsi,%rax
    1134:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1138:	48 c1 f8 03          	sar    $0x3,%rax
    113c:	48 01 c6             	add    %rax,%rsi
    113f:	48 d1 fe             	sar    %rsi
    1142:	74 14                	je     1158 <register_tm_clones+0x38>
    1144:	48 8b 05 a5 2e 00 00 	mov    0x2ea5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    114b:	48 85 c0             	test   %rax,%rax
    114e:	74 08                	je     1158 <register_tm_clones+0x38>
    1150:	ff e0                	jmp    *%rax
    1152:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1158:	c3                   	ret    
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <__do_global_dtors_aux>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	80 3d e5 2f 00 00 00 	cmpb   $0x0,0x2fe5(%rip)        # 4150 <completed.0>
    116b:	75 2b                	jne    1198 <__do_global_dtors_aux+0x38>
    116d:	55                   	push   %rbp
    116e:	48 83 3d 52 2e 00 00 	cmpq   $0x0,0x2e52(%rip)        # 3fc8 <__cxa_finalize@GLIBC_2.2.5>
    1175:	00 
    1176:	48 89 e5             	mov    %rsp,%rbp
    1179:	74 0c                	je     1187 <__do_global_dtors_aux+0x27>
    117b:	48 8b 3d 86 2e 00 00 	mov    0x2e86(%rip),%rdi        # 4008 <__dso_handle>
    1182:	e8 e9 fe ff ff       	call   1070 <__cxa_finalize@plt>
    1187:	e8 64 ff ff ff       	call   10f0 <deregister_tm_clones>
    118c:	c6 05 bd 2f 00 00 01 	movb   $0x1,0x2fbd(%rip)        # 4150 <completed.0>
    1193:	5d                   	pop    %rbp
    1194:	c3                   	ret    
    1195:	0f 1f 00             	nopl   (%rax)
    1198:	c3                   	ret    
    1199:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011a0 <frame_dummy>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	e9 77 ff ff ff       	jmp    1120 <register_tm_clones>

00000000000011a9 <main>:
    11a9:	f3 0f 1e fa          	endbr64 
    11ad:	55                   	push   %rbp
    11ae:	48 89 e5             	mov    %rsp,%rbp
    11b1:	48 83 ec 20          	sub    $0x20,%rsp
    11b5:	89 7d ec             	mov    %edi,-0x14(%rbp)
    11b8:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    11bc:	48 8d 05 41 0e 00 00 	lea    0xe41(%rip),%rax        # 2004 <_IO_stdin_used+0x4>
    11c3:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    11c7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    11cb:	48 89 c6             	mov    %rax,%rsi
    11ce:	48 8d 05 6b 2e 00 00 	lea    0x2e6b(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    11d5:	48 89 c7             	mov    %rax,%rdi
    11d8:	e8 b3 fe ff ff       	call   1090 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    11dd:	48 8b 15 ec 2d 00 00 	mov    0x2dec(%rip),%rdx        # 3fd0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    11e4:	48 89 d6             	mov    %rdx,%rsi
    11e7:	48 89 c7             	mov    %rax,%rdi
    11ea:	e8 b1 fe ff ff       	call   10a0 <_ZNSolsEPFRSoS_E@plt>
    11ef:	b8 00 00 00 00       	mov    $0x0,%eax
    11f4:	c9                   	leave  
    11f5:	c3                   	ret    

00000000000011f6 <_Z41__static_initialization_and_destruction_0ii>:
    11f6:	f3 0f 1e fa          	endbr64 
    11fa:	55                   	push   %rbp
    11fb:	48 89 e5             	mov    %rsp,%rbp
    11fe:	48 83 ec 10          	sub    $0x10,%rsp
    1202:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1205:	89 75 f8             	mov    %esi,-0x8(%rbp)
    1208:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    120c:	75 3b                	jne    1249 <_Z41__static_initialization_and_destruction_0ii+0x53>
    120e:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    1215:	75 32                	jne    1249 <_Z41__static_initialization_and_destruction_0ii+0x53>
    1217:	48 8d 05 33 2f 00 00 	lea    0x2f33(%rip),%rax        # 4151 <_ZStL8__ioinit>
    121e:	48 89 c7             	mov    %rax,%rdi
    1221:	e8 8a fe ff ff       	call   10b0 <_ZNSt8ios_base4InitC1Ev@plt>
    1226:	48 8d 05 db 2d 00 00 	lea    0x2ddb(%rip),%rax        # 4008 <__dso_handle>
    122d:	48 89 c2             	mov    %rax,%rdx
    1230:	48 8d 05 1a 2f 00 00 	lea    0x2f1a(%rip),%rax        # 4151 <_ZStL8__ioinit>
    1237:	48 89 c6             	mov    %rax,%rsi
    123a:	48 8b 05 b7 2d 00 00 	mov    0x2db7(%rip),%rax        # 3ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    1241:	48 89 c7             	mov    %rax,%rdi
    1244:	e8 37 fe ff ff       	call   1080 <__cxa_atexit@plt>
    1249:	90                   	nop
    124a:	c9                   	leave  
    124b:	c3                   	ret    

000000000000124c <_GLOBAL__sub_I_main>:
    124c:	f3 0f 1e fa          	endbr64 
    1250:	55                   	push   %rbp
    1251:	48 89 e5             	mov    %rsp,%rbp
    1254:	be ff ff 00 00       	mov    $0xffff,%esi
    1259:	bf 01 00 00 00       	mov    $0x1,%edi
    125e:	e8 93 ff ff ff       	call   11f6 <_Z41__static_initialization_and_destruction_0ii>
    1263:	5d                   	pop    %rbp
    1264:	c3                   	ret    

Disassembly of section .fini:

0000000000001268 <_fini>:
    1268:	f3 0f 1e fa          	endbr64 
    126c:	48 83 ec 08          	sub    $0x8,%rsp
    1270:	48 83 c4 08          	add    $0x8,%rsp
    1274:	c3                   	ret    
