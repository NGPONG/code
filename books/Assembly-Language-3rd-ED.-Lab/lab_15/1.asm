assume cs:codesg

stack segment
       db 128 dup (0)
stack ends

codesg segment
  start: ; init stack
         mov ax,stack
         mov ss,ax
         mov sp,80h

         push cs
         pop ds

         mov ax,0
         mov es,ax
         
         ; Write the new int9 interrupt process into memory constant space
         mov si,offset int9
         mov di,204h
         mov cx,offset int9end - offset int9
         cld
         rep movsb

         ; Storage the default int9 interrupt process into 0:200 ~ 0:203 (2 world)
         push es:[9*4]
         pop es:[200h]
         push es:[9*4+2]
         pop es:[202h]

         cli
         mov word ptr es:[9*4],204h
         mov word ptr es:[9*4+2],0
         sti
         
         mov ax,4c00h
         int 21h
  
   int9: push ax
         push bx
         push es
         push cx
  
         in al,60h
         
         ; Simulate the default int9 keyboard interrupt
         pushf
         call dword ptr cs:[200h]
  
         cmp al,9eh
         jne int9ret
  
  showa: mov ax,0b800h
         mov es,ax
  
         mov bx,0
         mov cx,2000
      s: mov byte ptr es:[bx],'a'
         add bx,2
         loop s

int9ret: pop cx
         pop es
         pop bx
         pop ax
         iret

int9end: nop

codesg ends
end start