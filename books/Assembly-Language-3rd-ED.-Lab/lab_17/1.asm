assume cs:code

code segment

  start: ; ds:si: src
         mov ax,cs
         mov ds,ax
         mov si,offset int9
         
         ; es:di: des
         mov ax,0
         mov es,ax
         mov di,200h

         mov cx,offset int9end - offset int9
         cld
         rep movsb
  
         mov ax,0
         mov es,ax
         mov word ptr es:[7ch*4],200h
         mov word ptr es:[7ch*4 + 2],0

         mov ax,4c00h
         int 21h
         
         ; Reset the compiler to calculate the offset of the label
         org 200h


; ----------------------------------------------------------------------------+
; @brief Read and write to the disk(The floppy disk is used in the course, but 
; the simulation method is used here) through the logical sector number.
; 
; @parm
;  * ah    function number; 0:read, 1:write
;  * dx    logic sector number
; ----------------------------------------------------------------------------+
   int9: jmp istart

         mem db 128 dup (0)
         cop dw 1440,18

 istart: push ax
         
         ; es:bs point to read & write memory area
         mov ax,cs
         mov es,ax
         mov bx,mem

         
         
         pop ax
         mov cl,4
         shr ah,cl
         cmp ax,0   ; if(ax == 0)
         je read
         cmp ax,1   ; else if (ax == 1)
         je write   
         jmp return ; else

   read: 

  write: 

 return: iret

int9end: nop

code ends
end start