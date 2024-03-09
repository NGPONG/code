assume cs:codesg, ss:stack


data segment
  ; 0 ~ 83   bytes
  db '1975', '1976', '1977', '1978', '1979', '1980', '1981', '1982', '1983'
  db '1984', '1985', '1986', '1987', '1988', '1989', '1990', '1991', '1992'
  db '1993', '1994', '1995'

  ; 84 ~ 167 bytes
  dd 16, 22, 382, 1356, 2390, 8000, 16000, 24486, 50065, 97479, 140417, 197514
  dd 345980, 590827, 803530, 1183000, 1843000, 2759000, 3753000, 4649000, 5937000

  ; 168 ~ 208 bytes
  dw 3, 7, 9, 13, 28, 38, 130, 220, 476, 778, 1001, 1442, 2258, 2793, 4037, 5635, 8226
  dw 11542, 14430, 15257, 17800
data ends

table segment
  ; 0 ~ 13B bytes
  db 21 dup ('year summ ne ?? ') ; 每一段为 16 bytes
table ends

codesg segment
start:  

  ; 初始化数据段
  mov ax,data
  mov ds,ax

  ; 初始化目标存储段
  mov cx,table
  mov es,cx

  mov bx,0 ; 4字节的偏移，针对年份和收入属性的偏移
  mov di,0 ; 2字节的偏移，针对雇员的偏移
  mov si,0 ; 目标存储段一整个实例的偏移，即每一个实例占用 16 bytes
  mov dl,20H ; 空格

  mov cx,0015h

  s:
  ; 年份
  mov ax,[bx].0
  mov es:[si].0,ax
  mov ax,[bx].2
  mov es:[si].2,ax

  ; 空格mov 
  es:[si].4,dl

  ; 收入
  mov ax,[bx].84
  mov es:[si].5,ax
  mov ax,[bx].86
  mov es:[si].7,ax

  ; 空格
  mov es:[si].9,dl

  ; 雇员数
  mov ax,[di].168
  mov es:[si].A,ax

  ; 空格
  mov es:[si].C,dl

  ; 人均收入
  mov ax,[bx].84  ; 低8位
  mov dx,[bx].86  ; 高8位
  mov bp,[bx].168 ; 除数
  div bp
  mov es:[si].D,ax

  ; 空格
  mov es:[si].F,dl

  add bx,0004H
  add di,0002H
  add si,0010H

  loop s

  mov ax,4c00H
  int 21H

codesg ends
end start