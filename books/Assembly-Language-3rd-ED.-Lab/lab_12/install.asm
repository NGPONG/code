assume cs:code

code segment
   start: mov ax,cs
          mov ds,ax
          mov si,offset do0

          mov ax,0
          mov es,ax
          mov di,0200H

          ; 将 do0 中的内容写入 0:0200H 开始处的位置中
          mov cx,offset do0end - offset do0
          cld
          rep movsb
          
          ; 设置中断向量
          mov ax,0
          mov es,ax
          mov word ptr es:[0 * 4],0200H ; 低位写入偏移地址
          mov word ptr es:[0 * 4 + 2],0 ; 高位写入段地址

          mov ax,4c00H
          int 21H

     do0: jmp short do0start
          db 'divide error!'   ; 因为安装程序在执行完后内存会被回收
                               ; 如果表示 msg 的字符串并不常驻在内
                               ; 存区的话，那么可能字符串的数据会被
                               ; 覆盖掉，比较好的方案就是把需要写入
                               ; 的字符串和中断处理程序同处在同一个
                               ; 内存区中，依赖于中断处理程序所处内
                               ; 存段的保护特性，该字符串的数据将会
                               ; 得到保护
   
do0start: mov ax,cs            ; cs 在 cpu 执行终端处理程序时，从
                               ; 0号向量表中获取到 cs 的值为 0000
          mov ds,ax  
          mov si,0202H         ; ds:si 将指向字符串的首地址，由于
                               ; jmp 指令占用一个字，所以这里要偏移
                               ; 至 0202H
   
          mov ax,0b800H        ; 显存缓冲区的段地址
          mov es,ax
          mov di,12*160+30*2   ; 正中间位置

          mov cx,000DH
       s: mov al,ds:[si]
          mov es:[di],al
          inc si
          add di,2
          loop s   

          mov ax,4c00H
          int 21H
  do0end: nop

code ends
end start