       jmp near start
  
  data dw 0,0
  msg  db '1 + 2 + 3 + ...... + 1000 = '

start:
       mov ax,0x7c0
       mov ds,ax

       mov ax,0xb800
       mov es,ax

       mov si,msg          
       mov di,0
       mov cx,start-msg
   @g:
       mov al,[si]
       mov [es:di],al
       inc di
       mov byte [es:di],0x07
       inc di
       inc si
       loop @g
       
       xor dx,dx
       mov ax,1
   @l: 
       add [data],ax
       adc [data+2],dx
       inc ax

       cmp ax,1001
       jle @l

    
       xor cx,cx 
       mov ss,cx
       mov sp,cx  
       mov bx,10
       xor cx,cx
   @d:
       inc cx
       xor dx,dx
       div bx
       or dl,0x30
       push dx
       cmp ax,0
       jne @d 
       
   @a:
       pop dx
       mov [es:di],dl
       inc di
       mov byte [es:di],0x07
       inc di
       loop @a
     

       jmp near $ ; delay

times 510-($-$$) db 0
                 db 0x55,0xaa