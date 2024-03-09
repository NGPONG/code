assume cs:codesg

codesg segment

start: mov ax,cs
       mov ds,ax
       mov si,offset lp

       mov ax,0
       mov es,ax
       mov di,0200H

       mov cx,offset lpend - offset lp
       cld
       rep movsb
        
       mov ax,0
       mov es,ax
       mov word ptr es:[7CH * 4],0200H
       mov word ptr es:[7CH * 4 + 2],0

       mov ax,4c00H
       int 21H

;---------------------------------------+
; @brief: Simulate the loop command     |
; @cx   : loop count                    |
; @bx   : address of the Restore offset |
;---------------------------------------+
   lp: push bp
       mov bp,sp
       dec cx
       jcxz lpret
       add [bp+2],bx

lpret: pop bp
       iret

lpend: nop

codesg ends
end start