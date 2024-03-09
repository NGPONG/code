assume cs:codesg

codesg segment
start: mov si,0

       ; year
       mov al,9
       out 70h,al
       in al,71h
       call show
       add si,4
       mov al,'/'
       call nshow
       add si,2

       ; month
       mov al,8
       out 70h,al
       in al,71h
       call show
       add si,4
       mov al,'/'
       call nshow
       add si,2

       ; day
       mov al,7
       out 70h,al
       in al,71h
       call show
       add si,4
       mov al,' '
       call nshow
       add si,2

       ; hour
       mov al,4
       out 70h,al
       in al,71h
       call show
       add si,4
       mov al,':'
       call nshow
       add si,2

       ; min
       mov al,2
       out 70h,al
       in al,71h
       call show
       add si,4
       mov al,':'
       call nshow
       add si,2

       ; sec
       mov al,0
       out 70h,al
       in al,71h
       call show

       mov ax,4c00h
       int 21h

nshow: push es
       push bx

       mov bx,0b800h
       mov es,bx
       mov byte ptr es:[160*2 + 40*2 + si],al

       pop bx
       pop es
       ret

 show: push es
       push bx
       push ax

       mov ah,al
       mov cl,4
       shr ah,cl
       and al,00001111b

       add ah,30h
       add al,30h

       mov bx,0b800h
       mov es,bx
       mov byte ptr es:[160*2 + 40*2 + si],ah
       mov byte ptr es:[160*2 + 40*2+2 + si],al

       pop ax
       pop bx
       pop es
       ret

codesg ends

end start