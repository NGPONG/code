         ;代码清单9-1
         ;文件名：c09_1.asm
         ;文件说明：用户程序 
         ;创建日期：2011-4-16 22:03
         
;===============================================================================
SECTION header vstart=0                     ;定义用户程序头部段 
    program_length  dd program_end          ;程序总长度[0x00]
    
    ;用户程序入口点
    code_entry      dw start                ;偏移地址[0x04]
                    dd section.code.start   ;段地址[0x06] 
    
    realloc_tbl_len dw (header_end-realloc_begin)/4
                                            ;段重定位表项个数[0x0a]
    
    realloc_begin:
    ;段重定位表           
    code_segment    dd section.code.start   ;[0x0c]
    data_segment    dd section.data.start   ;[0x14]
    stack_segment   dd section.stack.start  ;[0x1c]
    
header_end:                
    
;===============================================================================
SECTION code align=16 vstart=0           ;定义代码段（16字节对齐） 
new_int_0x70:
      push ax
      push bx
      push cx
      push dx
      push es
      
  .w0:                                    
      mov al,0x0a                        
      or al,0x80                          
      out 0x70,al                        ;写入 RTC 寄存器a 的索引，并且阻断 NMI 
      in al,0x71                         ;读寄存器A
      test al,0x80                       ;测试第7位UIP 
      jnz .w0                            ;if RTC RegA 7bit != 0

      xor al,al
      or al,0x80
      out 0x70,al
      in al,0x71                         ;读RTC当前时间(秒)
      push ax

      mov al,2
      or al,0x80
      out 0x70,al
      in al,0x71                         ;读RTC当前时间(分)
      push ax

      mov al,4
      or al,0x80
      out 0x70,al
      in al,0x71                         ;读RTC当前时间(时)
      push ax

      mov al,0x0c                       
      out 0x70,al                        ;写入 RTC 寄存器c 的索引，并且开放 NMI 
      in al,0x71                         ;重置 RTC 未决中断(此处不考虑闹钟和周期性中断的情况)

      mov ax,0xb800
      mov es,ax


      mov bx,12*160 + 36*2               ;从屏幕上的12行36列开始显示

      pop ax
      call bcd_to_ascii
      mov [es:bx],ah
      mov byte [es:bx+1],0x07
      mov [es:bx+2],al                   ;显示两位小时数字
      mov byte [es:bx+3],0x07

      mov al,':'
      mov [es:bx+4],al                   ;显示分隔符':'
      not byte [es:bx+5]                 ;反转显示属性 

      pop ax
      call bcd_to_ascii
      mov [es:bx+6],ah
      mov byte [es:bx+7],0x07
      mov [es:bx+8],al                   ;显示两位分钟数字
      mov byte [es:bx+9],0x07

      mov al,':'
      mov [es:bx+10],al                  ;显示分隔符':'
      not byte [es:bx+11]                ;反转显示属性

      pop ax
      call bcd_to_ascii
      mov [es:bx+12],ah
      mov byte [es:bx+13],0x07
      mov [es:bx+14],al                  ;显示两位小时数字
      mov byte [es:bx+15],0x07
      
      mov al,0x20                        ;中断结束命令EOI 
      out 0xa0,al                        ;向从片发送 
      out 0x20,al                        ;向主片发送 

      pop es
      pop dx
      pop cx
      pop bx
      pop ax

      iret

;-------------------------------------------------------------------------------
bcd_to_ascii:                            ;BCD码转ASCII
                                         ;输入：AL=bcd码
                                         ;输出：AX=ascii
      mov ah,al                          ;分拆成两个数字 
      and al,0x0f                        ;仅保留低4位 
      add al,0x30                        ;转换成ASCII 

      shr ah,4                           ;逻辑右移4位 
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
      
      mov bx,init_msg                    ;显示初始信息 
      call put_string

      mov bx,inst_msg                    ;显示安装信息 
      call put_string
      
      mov al,0x70
      mov bl,4
      mul bl                             ;计算0x70号中断在IVT中的偏移，每个中断向量占用4bytes
      mov bx,ax                          

      cli                                ;防止改动期间发生新的0x70号中断

      push es
      mov ax,0x0000
      mov es,ax
      mov word [es:bx],new_int_0x70      ;偏移地址。
                                          
      mov word [es:bx+2],cs              ;段地址
      pop es

      ;*******************************c_09_2**************************************
      mov al,0x0a                         
      or al,0x80
      out 0x70,al                        ;获取 RTC 寄存器a 并设置 NMI 中断
      in al,0x71
      or al,0x0f                         ;al = 0000 1111b, 500ms
      out 0x71,al       
      
      mov al,0x0b       
      or al,0x80
      out 0x70,al                        ;获取 RTC 寄存器b 并设置 NMI 中断
      mov al,0x42                        ;0x42 = 0100 0010b
      out 0x71,al       
      ;*******************************c_09_2**************************************

      mov al,0x0c
      out 0x70,al                        ;这一步除了写入索引寄存器即将要读取RTC寄存器C的值外，还复位了 NMI
      in al,0x71                         ;读RTC寄存器C，复位未决的中断状态
      
      ;*******************************c_09_1**************************************
      mov al,0xfe                        
      out 0xa1,al                        ;阻断 slave  除 IR2 外的所有电路引脚
      mov al,0xfb         
      out 0x21,al                        ;阻断 master 除 IR0 外的所有电路引脚
      ;*******************************c_09_1**************************************

      sti                                ;重新开放中断 

      mov bx,done_msg                    ;显示安装完成信息 
      call put_string

      mov bx,tips_msg                    ;显示提示信息
      call put_string
      
      mov cx,0xb800
      mov ds,cx
      mov byte [12*160 + 33*2],'@'       ;屏幕第12行，33列
       
 .idle:
      hlt                                ;使CPU进入低功耗状态，直到用中断唤醒
      not byte [12*160 + 33*2 + 1]       ;反转显示属性 
      jmp .idle

;-------------------------------------------------------------------------------
put_string:                              ;显示串(0结尾)。
                                         ;输入：DS:BX=串地址
         mov cl,[bx]
         or cl,cl                        ;cl=0 ?
         jz .exit                        ;是的，返回主程序 
         call put_char
         inc bx                          ;下一个字符 
         jmp put_string

   .exit:
         ret

;-------------------------------------------------------------------------------
put_char:                                ;显示一个字符
                                         ;输入：cl=字符ascii
         push ax
         push bx
         push cx
         push dx
         push ds
         push es

         ;以下取当前光标位置
         mov dx,0x3d4
         mov al,0x0e
         out dx,al
         mov dx,0x3d5
         in al,dx                        ;高8位 
         mov ah,al

         mov dx,0x3d4
         mov al,0x0f
         out dx,al
         mov dx,0x3d5
         in al,dx                        ;低8位 
         mov bx,ax                       ;BX=代表光标位置的16位数

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
         add bx,80                       ;因为换行符是紧随着回车符出现的，而回车符会先把 bx 置为当前行的行首，所以这时候加上 80 就等于下一行的行首了
         jmp .roll_screen

 .put_other:                             ;正常显示字符
         mov ax,0xb800
         mov es,ax
         shl bx,1
         mov [es:bx],cl
         mov byte [es:bx+1],0x07

         ;以下将光标位置推进一个字符
         shr bx,1
         add bx,1

 .roll_screen:
         cmp bx,2000                     ;光标超出屏幕？滚屏
         jl .set_cursor                  ;if bx < 2000(即到了一个页的右下角)

         mov ax,0xb800
         mov ds,ax
         mov es,ax
         cld
         mov si,0xa0
         mov di,0x00
         mov cx,1920
         rep movsw                       ;清除首行，并下一行依次往上移动一行
         mov bx,3840                     ;清除底行
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