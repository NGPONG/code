assume cs:codesg

codesg segment

   start: mov ax,cs
          mov ds,ax
          mov si,offset schar

          mov ax,0
          mov es,ax
          mov di,0200H

          mov cx,offset scharend - offset schar
          cld
          rep movsb
          
          mov ax,0
          mov es,ax
          mov word ptr es:[7CH * 4],0200H
          mov word ptr es:[7CH * 4 + 2],0

          mov ax,4c00H
          int 21H

   ; @brief: Write character into display buf
   ; @dh   : row number
   ; @dl   : col number
   ; @cl   : char property
   ; @ds:si: point to first char
   schar: push es
          push si
          push di
          push bx
          push ax

          mov ax,0B800H
          mov es,ax

          push dx
          mov ax,0
          mov al,dh
          mov bx,160
          mul bx
          mov di,ax
          pop dx

          push dx
          mov ah,0
          mov al,dl
          mov bx,2
          mul bx
          add di,ax
          pop dx

          mov ax,0
       l: mov al,ds:[si]
          cmp al,0
          je return
          mov es:[di],al
          mov es:[di+1],cl
          inc si
          add di,2
          jmp short l

  return: pop ax
          pop bx
          pop di
          pop si
          pop es
          iret

scharend: nop

codesg ends
end start