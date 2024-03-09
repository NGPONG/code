assume cs:codesg,ds:dataesg

dataesg segment
  db 'welcome to masm!',0
  db 10 dup(0)
dataesg ends

codesg segment
   start: mov ax,dataesg
          mov ds,ax
   
          mov ax,317AH
          call dtoc
   
          mov dh,8            ; row
          mov dl,1            ; col
          mov cx,2            ; color
          mov si,17           ; 字符串在内存段中的偏移量
          call show_str       
       
          mov ax,4c00H       
          int 21H       
       
    dtoc: push bx       
          push cx       
          push si       
          push ax       
          push dx       
                 
          mov dx,0            ; 被除数的高六位初始化为 0
          mov bx,000AH        ; 初始化除数，指定除法为 16 位除法
          mov si,4            ; 写入内存段中的偏移量
       
       s: div bx       
          mov cx,dx           ; 获取余数
          jcxz d_ret        
          add cl,30H          ; 计算余数所映射的 ASCII 码
          mov ds:[si+17],cl   ; 写入内存
          sub si,1
          mov dx,0
          jmp short s

   d_ret: pop dx
          pop ax
          pop si
          pop cx
          pop bx
          ret

show_str: push dx
          push cx
          push si             ;将子程序用到的寄存器入栈

          mov ax,0b800H
          mov es,ax

          mov ax,0
          mov al,160
          mul dh
          mov bx,ax
          mov ax,0
          mov al,2
          mul dl
          add bx,ax
          mov di,0
          mov al,cl
          mov ch,0

    show: mov cl,ds:[si]
          jcxz return
          mov es:[bx+di+0],cl
          mov es:[bx+di+1],al
          add di,2
          inc si
          jmp short show
  return: pop si
          pop dx
          pop cx
          ret

codesg ends
end start