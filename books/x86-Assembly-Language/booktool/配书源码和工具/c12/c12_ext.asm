;---------------------------------------------------------------    
; const
;---------------------------------------------------------------    
    MEMORY_START equ 0x100000 ;要检测的内存起始地址
    MEMORY_END   equ 0x500000 ;要检测的内存结束地址
;---------------------------------------------------------------    

    ;设置堆栈段和栈指针 
    mov eax,cs      
    mov ss,eax
    mov sp,0x7c00
      
    ;计算GDT所在的逻辑段地址
    mov eax,[cs:pgdt+0x7c00+0x02]      ;GDT的32位线性基地址 
    xor edx,edx
    mov ebx,16
    div ebx                            ;分解成16位逻辑地址 

    mov ds,eax                         ;令DS指向该段以进行操作
    mov ebx,edx                        ;段内起始偏移地址 

    ;创建0#描述符，它是空描述符，这是处理器的要求
    mov dword [ebx+0x00],0x00000000
    mov dword [ebx+0x04],0x00000000  

    ;创建1#描述符，这是一个数据段，对应0~4GB的线性地址空间
    mov dword [ebx+0x08],0x0000ffff    ;基地址为0，段界限为0xfffff
    mov dword [ebx+0x0c],0x00cf9200    ;粒度为4KB，存储器段描述符 

    ;创建保护模式下初始代码段描述符
    mov dword [ebx+0x10],0x7c0001ff    ;基地址为0x00007c00，512字节 
    mov dword [ebx+0x14],0x00409800    ;粒度为1个字节，代码段描述符 

    ;创建以上代码段的别名描述符
    mov dword [ebx+0x18],0x7c0001ff    ;基地址为0x00007c00，512字节
    mov dword [ebx+0x1c],0x00409200    ;粒度为1个字节，数据段描述符

    mov dword [ebx+0x20],0x7c00fffe
    mov dword [ebx+0x24],0x00cf9600
            
    ;初始化描述符表寄存器GDTR
    mov word [cs: pgdt+0x7c00],39      ;描述符表的界限   
    
    lgdt [cs: pgdt+0x7c00]
        
    in al,0x92                         ;南桥芯片内的端口 
    or al,0000_0010B
    out 0x92,al                        ;打开A20

    cli                                ;中断机制尚未工作

    mov eax,cr0
    or eax,1
    mov cr0,eax                        ;设置PE位
        
    jmp dword 0x0010:flush             ;16位的描述符选择子：32位偏移


; --------------------------------production------------------------------------

    [bits 32]                          
flush:                                     
    mov eax,0x0018                      
    mov ds,eax
        
    mov eax,0x0008                     ;加载数据段(0..4GB)选择子
    mov es,eax
    mov fs,eax
    mov gs,eax
        
    mov eax,0x0020                     ;0000 0000 0010 0000
    mov ss,eax
    xor esp,esp                        ;ESP <- 0
    

; --------------------------------c_12_ext---------------------------------------

    xor esi,esi ; offset of display buf

    xor ebx,ebx
@l_1:
    mov al,[str_title + ebx]
    or al,al
    jz nxt
    mov ah,0x07
    call show
    add esi,2
    inc ebx
    jmp near @l_1

nxt:
    mov eax,MEMORY_START
    call complute

    mov al,'/'
    mov ah,0x07
    call show
    add esi,2

    mov eax,MEMORY_END
    call complute

    call check

    hlt

check:
    push ebx
    push eax

    mov ebx,MEMORY_START

@check_l:
    mov esi,8

    mov dword [es:ebx],0x55aa_55aa
    cmp dword [es:ebx],0x55aa_55aa
    jnz err

    mov dword [es:ebx],0xaa55_aa55
    cmp dword [es:ebx],0xaa55_aa55
    jnz err

    add ebx,0x0000_0004

    mov eax,ebx
    call complute

    cmp ebx,MEMORY_END
    jnz @check_l

    pop eax
    pop ebx
    ret

err:
    hlt


complute:
    push edx
    push ecx
    push edi
    push eax
    push ebx

    xor ebx,ebx

    mov edi,16
    mov ecx,8
@l_set_mem:
    xor edx,edx ; set hight 16bit is zero
    div edi
    mov [mem_num + ebx],dl
    inc ebx
    loop @l_set_mem

    xor eax,eax
    xor ebx,ebx
    mov edi,7

    mov ecx,8
@l_get_mem:
    mov bl,[mem_num + edi]
    mov al,[number + ebx]
    mov ah,0x07
    call show
    add esi,2
    dec edi
    loop @l_get_mem

    pop ebx
    pop eax
    pop edi
    pop ecx
    pop edx
    ret

;  ah: char property
;  al: ASCII char
; esi: offset of display buf
show: 
    mov [es:0x000b_8000 + esi],ax
    ret

;-------------------------------------------------------------------------------
     str_title        db "HEX:",0
     mem_num          db 0,0,0,0,0,0,0,0
     number           db '0123456789ABCDEF'
;-------------------------------------------------------------------------------
     pgdt             dw 0
                      dd 0x00007e00
;-------------------------------------------------------------------------------                             
     times 510-($-$$) db 0
                      db 0x55,0xaa