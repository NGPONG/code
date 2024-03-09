assume cs:code

code segment

           start: push cs
                  pop ds
                  mov si, offset int7ch_setscreen
      
                  mov ax, 0000H
                  mov es, ax
                  mov di, 204H ; 0 ~ 1 bytes: 存储默认 7CH 的中断例程的 段地址:偏移地址
                               ; 2 ~ 3 bytes: 存储新的 7CH 的中断例程的 段地址:偏移地址
      
                  mov cx, offset int7ch_end - offset int7ch_setscreen
      
                  cld      
                  rep movsb
      
                  mov ax, 0000H
                  mov es, ax
                  push es:[7cH*4]  
                  pop es:[200H]    
                  push es:[7cH*4+2]
                  pop es:[202H]    
      
                  cli
                  mov word ptr es:[7cH*4], 204H
                  mov word ptr es:[7cH*4+2], 0000H
                  sti
      
                  mov ax, 4c00H
                  int 21H
      
                  ; org 为伪指令，其作用于通知编译器，该指令往下所使用的 [标号] 由 [204H] 开始重新计算
                  ; 
                  ; 因为这是安装程序，也就是说以下的中断例程中的机器码在该安装程序执行时，仅存在于安装程序
                  ; 所在内存段中，并且中断例程中，直接定址表所计算出来的偏移也仅是以当前整个安装程序的所有
                  ; 为基准所计算出来的偏移，并且以下的中断例程中所存储在内存的机器码最终是要写到另一块内存
                  ; 常量区的，但是在写入的过程中，直接定址表中所计算出来的 [以整个安装程序为基准所计算出来
                  ; 的偏移] 是不会改变的，也就是说，如果不通知编译器去重新核算以下标号的偏移，则以下标号的
                  ; 偏移都是错误的，这时候我们就需要手动的重新计算中断例程中所使用的子程序在这个中断例程中
                  ; 所保有的偏移，当然更直接的做法则为使用 org 指令，并且指定重新计算的范围为中断例程写入
                  ; 新内存段的首地址即可解决
                  org 204H   


int7ch_setscreen: jmp short set

                  table dw cls, frontcolor, backcolor, roll 

             set: push bx
                  cmp ah,3
                  ja sret
      
                  mov bl,ah  
                  mov bh,0
                  add bx,bx
                  call word ptr table[bx]
      
            sret: pop bx
                  iret
      

; @brief: 清空屏幕
             cls: push bx
                  push cx
                  push es
          
                  mov bx, 0b800h
                  mov es, bx
          
                  mov bx, 0
                  mov cx, 2000
         clsloop: mov byte ptr es:[bx], ' '  
                  add bx, 2
                  loop clsloop
      
                  pop es
                  pop cx
                  pop bx
                  ret
      
      
; @brief: 改变显示字符的背景色
      frontcolor: push bx
                  push cx
                  push es
      
                  mov bx, 0b800h
                  mov es, bx
      
                  mov bx,1
                  mov cx,2000
         f_color: and byte ptr es:[bx], 11111000b
                  or es:[bx], al
                  add bx, 2
                  loop f_color
      
                  pop es
                  pop cx
                  pop bx
                  ret
      
      
; @brief: 改变显示字符的前景色
       backcolor: push bx
                  push cx
                  push es
      
                  mov bx, 0b800h
                  mov es, bx
      
                  mov bx,1
                  mov cx,2000
         b_color: and byte ptr es:[bx], 10001111b
                  or es:[bx], al
                  add bx, 2
                  loop b_color
      
                  pop es
                  pop cx
                  pop bx
                  ret
      
      
; @brief: 向上滚动一行
            roll: push cx
                  push si
                  push di
                  push es
                  push ds
          
                  mov si,0b800h
                  mov es, si
                  mov ds, si
          
                  mov si,160
                  mov di,0  
          
                  cld       
                  mov cx,24 
        copy_row: push cx
                  mov cx,160
                  rep movsb
                  pop cx
                  loop copy_row
          
                  ; 最后一行清空，写入空格
                  mov cx,80  
                  mov si,0
         cls_row: mov byte ptr es:[160*24+si],' '
                  add si,2
                  loop cls_row
          
                  pop ds
                  pop es
                  pop di
                  pop si
                  pop cx
                  ret
      
      int7ch_end: nop    

code ends

end start