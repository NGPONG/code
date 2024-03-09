         ;�����嵥9-1
         ;�ļ�����c09_1.asm
         ;�ļ�˵�����û����� 
         ;�������ڣ�2011-4-16 22:03
         
;===============================================================================
SECTION header vstart=0                     ;�����û�����ͷ���� 
    program_length  dd program_end          ;�����ܳ���[0x00]
    
    ;�û�������ڵ�
    code_entry      dw start                ;ƫ�Ƶ�ַ[0x04]
                    dd section.code.start   ;�ε�ַ[0x06] 
    
    realloc_tbl_len dw (header_end-realloc_begin)/4
                                            ;���ض�λ�������[0x0a]
    
    realloc_begin:
    ;���ض�λ��           
    code_segment    dd section.code.start   ;[0x0c]
    data_segment    dd section.data.start   ;[0x14]
    stack_segment   dd section.stack.start  ;[0x1c]
    
header_end:                
    
;===============================================================================
SECTION code align=16 vstart=0           ;�������Σ�16�ֽڶ��룩 
new_int_0x70:
      push ax
      push bx
      push cx
      push dx
      push es
      
  .w0:                                    
      mov al,0x0a                        
      or al,0x80                          
      out 0x70,al                        ;д�� RTC �Ĵ���a ��������������� NMI 
      in al,0x71                         ;���Ĵ���A
      test al,0x80                       ;���Ե�7λUIP 
      jnz .w0                            ;if RTC RegA 7bit != 0

      xor al,al
      or al,0x80
      out 0x70,al
      in al,0x71                         ;��RTC��ǰʱ��(��)
      push ax

      mov al,2
      or al,0x80
      out 0x70,al
      in al,0x71                         ;��RTC��ǰʱ��(��)
      push ax

      mov al,4
      or al,0x80
      out 0x70,al
      in al,0x71                         ;��RTC��ǰʱ��(ʱ)
      push ax

      mov al,0x0c                       
      out 0x70,al                        ;д�� RTC �Ĵ���c �����������ҿ��� NMI 
      in al,0x71                         ;���� RTC δ���ж�(�˴����������Ӻ��������жϵ����)

      mov ax,0xb800
      mov es,ax


      mov bx,12*160 + 36*2               ;����Ļ�ϵ�12��36�п�ʼ��ʾ

      pop ax
      call bcd_to_ascii
      mov [es:bx],ah
      mov byte [es:bx+1],0x07
      mov [es:bx+2],al                   ;��ʾ��λСʱ����
      mov byte [es:bx+3],0x07

      mov al,':'
      mov [es:bx+4],al                   ;��ʾ�ָ���':'
      not byte [es:bx+5]                 ;��ת��ʾ���� 

      pop ax
      call bcd_to_ascii
      mov [es:bx+6],ah
      mov byte [es:bx+7],0x07
      mov [es:bx+8],al                   ;��ʾ��λ��������
      mov byte [es:bx+9],0x07

      mov al,':'
      mov [es:bx+10],al                  ;��ʾ�ָ���':'
      not byte [es:bx+11]                ;��ת��ʾ����

      pop ax
      call bcd_to_ascii
      mov [es:bx+12],ah
      mov byte [es:bx+13],0x07
      mov [es:bx+14],al                  ;��ʾ��λСʱ����
      mov byte [es:bx+15],0x07
      
      mov al,0x20                        ;�жϽ�������EOI 
      out 0xa0,al                        ;���Ƭ���� 
      out 0x20,al                        ;����Ƭ���� 

      pop es
      pop dx
      pop cx
      pop bx
      pop ax

      iret

;-------------------------------------------------------------------------------
bcd_to_ascii:                            ;BCD��תASCII
                                         ;���룺AL=bcd��
                                         ;�����AX=ascii
      mov ah,al                          ;�ֲ���������� 
      and al,0x0f                        ;��������4λ 
      add al,0x30                        ;ת����ASCII 

      shr ah,4                           ;�߼�����4λ 
      and ah,0x0f                        
      add ah,0x30

      ret

;-------------------------------------------------------------------------------
start:
      mov ax,[stack_segment]
      mov ss,ax
      mov sp,ss_pointer
      mov ax,[data_segment]
      mov ds,ax
      
      mov bx,init_msg                    ;��ʾ��ʼ��Ϣ 
      call put_string

      mov bx,inst_msg                    ;��ʾ��װ��Ϣ 
      call put_string
      
      mov al,0x70
      mov bl,4
      mul bl                             ;����0x70���ж���IVT�е�ƫ�ƣ�ÿ���ж�����ռ��4bytes
      mov bx,ax                          

      cli                                ;��ֹ�Ķ��ڼ䷢���µ�0x70���ж�

      push es
      mov ax,0x0000
      mov es,ax
      mov word [es:bx],new_int_0x70      ;ƫ�Ƶ�ַ��
                                          
      mov word [es:bx+2],cs              ;�ε�ַ
      pop es

      ;*******************************c_09_2**************************************
      mov al,0x0a                         
      or al,0x80
      out 0x70,al                        ;��ȡ RTC �Ĵ���a ������ NMI �ж�
      in al,0x71
      or al,0x0f                         ;al = 0000 1111b, 500ms
      out 0x71,al       
      
      mov al,0x0b       
      or al,0x80
      out 0x70,al                        ;��ȡ RTC �Ĵ���b ������ NMI �ж�
      mov al,0x42                        ;0x42 = 0100 0010b
      out 0x71,al       
      ;*******************************c_09_2**************************************

      mov al,0x0c
      out 0x70,al                        ;��һ������д�������Ĵ�������Ҫ��ȡRTC�Ĵ���C��ֵ�⣬����λ�� NMI
      in al,0x71                         ;��RTC�Ĵ���C����λδ�����ж�״̬
      
      ;*******************************c_09_1**************************************
      mov al,0xfe                        
      out 0xa1,al                        ;��� slave  �� IR2 ������е�·����
      mov al,0xfb         
      out 0x21,al                        ;��� master �� IR0 ������е�·����
      ;*******************************c_09_1**************************************

      sti                                ;���¿����ж� 

      mov bx,done_msg                    ;��ʾ��װ�����Ϣ 
      call put_string

      mov bx,tips_msg                    ;��ʾ��ʾ��Ϣ
      call put_string
      
      mov cx,0xb800
      mov ds,cx
      mov byte [12*160 + 33*2],'@'       ;��Ļ��12�У�33��
       
 .idle:
      hlt                                ;ʹCPU����͹���״̬��ֱ�����жϻ���
      not byte [12*160 + 33*2 + 1]       ;��ת��ʾ���� 
      jmp .idle

;-------------------------------------------------------------------------------
put_string:                              ;��ʾ��(0��β)��
                                         ;���룺DS:BX=����ַ
         mov cl,[bx]
         or cl,cl                        ;cl=0 ?
         jz .exit                        ;�ǵģ����������� 
         call put_char
         inc bx                          ;��һ���ַ� 
         jmp put_string

   .exit:
         ret

;-------------------------------------------------------------------------------
put_char:                                ;��ʾһ���ַ�
                                         ;���룺cl=�ַ�ascii
         push ax
         push bx
         push cx
         push dx
         push ds
         push es

         ;����ȡ��ǰ���λ��
         mov dx,0x3d4
         mov al,0x0e
         out dx,al
         mov dx,0x3d5
         in al,dx                        ;��8λ 
         mov ah,al

         mov dx,0x3d4
         mov al,0x0f
         out dx,al
         mov dx,0x3d5
         in al,dx                        ;��8λ 
         mov bx,ax                       ;BX=������λ�õ�16λ��

         cmp cl,0x0d
         jnz .put_0a                     ;if cl != \r
         mov ax,bx                       ; 
         mov bl,80                       
         div bl
         mul bl
         mov bx,ax
         jmp .set_cursor

 .put_0a:
         cmp cl,0x0a
         jnz .put_other                  ;if cl != \n
         add bx,80                       ;��Ϊ���з��ǽ����Żس������ֵģ����س������Ȱ� bx ��Ϊ��ǰ�е����ף�������ʱ����� 80 �͵�����һ�е�������
         jmp .roll_screen

 .put_other:                             ;������ʾ�ַ�
         mov ax,0xb800
         mov es,ax
         shl bx,1
         mov [es:bx],cl
         mov byte [es:bx+1],0x07

         ;���½����λ���ƽ�һ���ַ�
         shr bx,1
         add bx,1

 .roll_screen:
         cmp bx,2000                     ;��곬����Ļ������
         jl .set_cursor                  ;if bx < 2000(������һ��ҳ�����½�)

         mov ax,0xb800
         mov ds,ax
         mov es,ax
         cld
         mov si,0xa0
         mov di,0x00
         mov cx,1920
         rep movsw                       ;������У�����һ�����������ƶ�һ��
         mov bx,3840                     ;�������
         mov cx,80
 .cls:
         mov word[es:bx],0x0720
         add bx,2
         loop .cls

         mov bx,1920

 .set_cursor:
         mov dx,0x3d4
         mov al,0x0e
         out dx,al
         mov dx,0x3d5
         mov al,bh
         out dx,al
         mov dx,0x3d4
         mov al,0x0f
         out dx,al
         mov dx,0x3d5
         mov al,bl
         out dx,al

         pop es
         pop ds
         pop dx
         pop cx
         pop bx
         pop ax

         ret

;===============================================================================
SECTION data align=16 vstart=0

    init_msg       db 'Starting...',0x0d,0x0a,0
                   
    inst_msg       db 'Installing a new interrupt 70H...',0
    
    done_msg       db 'Done.',0x0d,0x0a,0

    tips_msg       db 'Clock is now working.',0
                   
;===============================================================================
SECTION stack align=16 vstart=0
           
                 resb 256
ss_pointer:
 
;===============================================================================
SECTION program_trail
program_end: