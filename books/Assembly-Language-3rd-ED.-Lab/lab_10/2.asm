assume cs:codesg

codesg segment
start: ; 4 Bytes dividend, ax is low bit, dx is hight bit 
       mov ax,4240H
       mov dx,000FH

       ; 2 bytes divisor
       mov cx,000AH
       
       call divdw

       mov ax,4C00H
       int 21H

divdw: push dx
       push ax

       ; 先计算高 16 bit
       mov ax,dx
       mov dx,0000
       div cx
       mov bx,ax ; bx 存放着 H/N 的商
                 ; dx 存放着 H/N 的余

       ; 还原 ax 寄存器，ax寄存器存储着原来被除数的低16位
       pop ax

       ; 根据公式，dx此时为 H/N 的余，以下面的出发为基准，作为
       ; 高位存放在 dx 中，而弹出 ax 后其原始就作为被除数的低位
       ; 故可以直接使用
       div cx

       mov cx,dx 
       mov dx,bx

       ; 还原栈
       pop dx
       ret


codesg ends
end start