assume cs:codesg

codesg segment

    mov ax,0
    mov ds,ax

    mov bx,200H

    mov cx,64

s:  mov ds:[bx],al
    inc al
    inc bx

    loop s

    mov ax,4c00H
    int 21H

codesg ends

end