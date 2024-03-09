assume cs:codesg

codesg segment

  ; 初始化段寄存器
  mov ax,0020H
  mov ds,ax
  mov bx,0     ; 用于存放偏移地址和叠加数
  
  mov cx,0040H ; 存放循环的次数，0040 == 64

s:mov ds:[bx],bx
  inc bx

  loop s
  
  mov ax,4c00H
  int 21H

codesg ends

end