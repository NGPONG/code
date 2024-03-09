assume cs:codesg,ds:dataesg

dataesg segment
       db 'welcome to masm!',0
dataesg ends

codesg segment
   start: mov dh, 8           ;屏幕的行数
          mov dl, 3           ;所在行的列数
          mov ch, 0           ;ch清零，防止高8位不为零。
          mov cl, 2           ;颜色属性（此处应是二进制数0000 0010）

          mov ax, data
          mov ds, ax
          mov si, 0           ;将ds：si指向字符串

          call show_str

          mov ax, 4c00H
          int 21H

show_str: push dx
          push cx
          push si             ;将子程序用到的寄存器入栈
          
          mov ax, 0b800H
          mov es, ax

          mov ax, 0
          mov al, 160
          mul dh
          mov bx, ax
          mov ax, 0
          mov al, 2
          mul dl
          add bx, ax
          mov di,0
          mov al, cl
          mov ch, 0

    show: mov cl, ds:[si]
          jcxz ok
          mov es:[bx+di+0], cl
          mov es:[bx+di+1], al
          add di, 2
          inc si
          jmp short show
          pop si
          pop dx
          pop cx
          ret

codesg ends
end start