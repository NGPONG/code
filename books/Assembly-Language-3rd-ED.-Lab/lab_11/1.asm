assume cs:codesg

datasg segment 
    db "ABCDEFGH's IJK-LMNpose Symbolic Instruction Code.",0 ; 50 bytes  0 ~ 49
    db 50 dup (0)                                            ; 50 bytes 50 ~ 99
datasg ends

codesg segment

  begin: mov ax,datasg
         mov ds,ax

         mov si,0
  
         call letterc
  
         mov ax, 4c00H
         int 21H

letterc: push di
         push es

         mov ax,datasg
         mov es,ax
         mov di,50         ; point to buf
         
      s: mov al,ds:[si]

         cmp al,0
         je return
         
         ; Character must be converted in the range of [0041H,005AH] 
         cmp al,0041H      ; if (al < 0041H) goto nxt;
         jb nxt     
         cmp al,005AH      ; if (al > 005AH) goto nxt;
         ja nxt

         or al,00100000B   ; to lower

    nxt: mov es:[di],al
         inc di
         inc si
         jmp s

 return: pop es
         pop di
         ret
         

codesg ends
end begin