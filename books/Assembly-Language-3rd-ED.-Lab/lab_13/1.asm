assume cs:codesg

data segment
    db "welcome to asm!",0
data ends

codesg segment

start: mov dh,10
       mov dl,0
       mov cl,11001010b
       mov ax,data
       mov ds,ax
       mov si,0
       int 7ch

       mov ax,4c00h
       int 21h

codesg ends
end start