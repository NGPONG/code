assume cs:codesg,ds:dataesg

dataesg segment
       ; 需要写入显存的数据，占用 16 bytes
       db 'welcome to masm!'

       ; 字符的属性
       db 8AH,24H,71H
dataesg ends

codesg segment
start: mov ax,dataesg ; 初始化数据段
       mov ds,ax

       mov ax,0B800H  ; 显示缓冲区起始段地址，B8000H ~ BFFFFH
       mov es,ax

       mov bx,1920    ; 第一行的起始偏移量
       add bx,50      ; 取中间列的起始偏移量，正中间按理来说应该是 80，但是80不太好看，故取 50

       mov si,0       ; 字符组的偏移
       mov bp,0       ; 颜色组的偏移
       mov di,0       ; 写入显示缓冲区的偏移
       
       mov cx,3       ; 写入三行
  row: push cx
       
       mov cx,16      ; 内循环16次以写入每一个字符
  col: ; 写入字符
       mov al,[si]
       mov es:[bx+di],al

       ; 写入字符的属性
       mov al,[bp+16]
       mov es:[bx+di+1],al
       
       inc si
       add di,2
       loop col

       ; Reset offset register.
       mov si,0
       mov di,0
       inc bp
       add bx,160
       pop cx
       loop row

       mov ax,4c00H
       int 21H

codesg ends
end start