assume cs:codesg,ds:datasg

;-----------------------------------------------------------------------------------------
datasg segment
  ; 全局变量,16 bytes
  db 16 dup(0)

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
datasg ends
;-----------------------------------------------------------------------------------------

;-----------------------------------------------------------------------------------------
codesg segment
   start: mov ax,datasg
          mov ds,ax

          mov ax,0b800H
          mov es,ax

          mov word ptr ds:[0],0       ; 0 ~ 1  bytes: 4字节的偏移，针对年份和收入属性的偏移   
          mov word ptr ds:[2],0       ; 2 ~ 3  bytes: 2字节的偏移，针对雇员的偏移
          mov word ptr ds:[4],2       ; 4 ~ 5  bytes: 记录行数，16 位乘法的默认乘数     
          mov word ptr ds:[6],160     ; 6 ~ 7  bytes: 显示缓冲区中每一行的偏移，每一行由 160 bytes
          
          mov cx,0015h                ; 一共有 21 组数据，故需要循环 21 次

       l: ; 计算本次循环对应行数在显示缓冲区的起始偏移量
          mov ax,ds:[4]               ; 取出缓冲区中所保存的行数  
          mul word ptr ds:[6]         ; 计算此行(此次循环)所依赖的偏移
          mov bx,ax                   ; bx 存储全局的在显示缓冲区中写入的偏移量，要注意保护好该寄存器
          
          mov di,ds:[0]               ; 取出缓冲区所保存的针对4字节成员数据的偏移

          ; 写入年份() 4 bytes {
          mov bp,0
          push cx
          mov cx,4
   syear: mov dl,ds:[di+bp+16]
          mov es:[bx+0+0],dl           ; char
          mov byte ptr es:[bx+0+1],2   ; color
          add bx,2
          inc bp
          loop syear
          pop cx
          ; }

          add bx,10                   ; to next property

          ; 写入收入() {
          mov ax,ds:[di+84+16]        ; low  16 bit
          mov dx,ds:[di+86+16]        ; high 16 bit
          call ddtoc
          add bx,0014H                ; 补全函数调用后写入的最终偏移
          ; }

          add bx,10                   ; to next property

          ; 写入雇员数() {
          mov di,ds:[2]               ; 取出缓冲区所保存的针对2字节成员数据的偏移
          mov ax,ds:[di+168+16]
          mov dx,0
          call dtoc
          add bx,000EH                ; 补全函数调用后写入的最终偏移
          ; }

          add bx,10
          
          ; 写入平均数() {
          push cx

          mov di,ds:[0]               ; 取出缓冲区所保存的针对4字节成员数据的偏移
          mov ax,ds:[di+84+16]        ; low  16 bit
          mov dx,ds:[di+86+16]        ; high 16 bit

          mov di,ds:[2]               ; 取出缓冲区所保存的针对2字节成员数据的偏移
          mov cx,ds:[di+168+16]       ; 除数

          call divdw                  ; 该函数调用完毕后
                                      ; (ax) = low 16 bit ret
                                      ; (dx) = hig 16 bit ret
                                      ; (cx) = remainder

          call ddtoc
          add bx,0014H                ; 补全函数调用后写入的最终偏移

          pop cx
          ; }
          
          call nxt_l

          loop l

          mov ax,4c00H
          int 21H

nxt_l: ; 4字节偏移每一行遍历结束后 + 4
       mov ax,ds:[0]
       add ax,4
       mov ds:[0],ax

       ; 2 字节偏移每一行边里结束后 + 2
       mov ax,ds:[2]
       add ax,2
       mov ds:[2],ax

       ; 行数 + 1
       mov ax,ds:[4]
       add ax,1
       mov ds:[4],ax

       ret


divdw: push bx
       push ax

       ; (ax) = low 16 bit ret
       ; (dx) = hig 16 bit ret
       ; (cx) = division

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

       ; (ax) = low 16 bit ret
       ; (dx) = hig 16 bit ret
       ; (cx) = remainder

       pop bx
       ret


; void dtoc(ax num, bx idx) {
    dtoc: push cx       
          push di
          push bp
          
          mov bp,000AH                ; 初始化除数，指定除法为 16 位除法
          mov di,000EH                ; 写入内存段中的偏移量
             
   dsmon: div bp             
          
          ; 依据余数写入显示缓冲区
          mov cx,dx        
          add cl,30H                  ; 计算余数所映射的 ASCII 码
          mov es:[bx+di],cl           ; 字符写入显存，从偶数开始，并在下一行机器码中开始递减偏移位以写入颜色属性至显存
          mov byte ptr es:[bx+di+1],2 ; 颜色写入显存
          
          ; 判断商是否为 0
          mov cx,ax                   ; 获取商
          jcxz d_ret

          sub di,2
          mov dx,0
          jmp short dsmon

   d_ret: pop bp
          pop di
          pop cx
          ret
; }

; void ddtoc(ax low,dx high, bx idx) {
   ddtoc: push cx       
          push di
          
          mov di,0014H                ; 写入内存段中的偏移量
  ddsmon: mov cx,10
          call divdw

          push cx
          mov cx,ax
          jcxz ifz                    ; 判断低六位是否为 0
                                      ; 如果不为 0，那证明 divdw 后的商一定不为 0，即还需要进行下一次循环的除法运算，那么指令则继续往下执行
                                      ; 如果低6位为0，则跳转去判断高六位是否为 0
ddtoc_re: pop cx

          mov ch,0    
          add cl,30H                  ; 计算余数所映射的 ASCII 码
          mov es:[bx+di],cl           ; char
          mov byte ptr es:[bx+di+1],2 ; color
          sub di,2
          jmp short ddsmon

     ifz: mov cx,dx                   ; 判断高6位是否为0
          jcxz ifz2
          jmp short ddtoc_re

    ifz2: pop cx
          mov ch,0    
          add cl,30H                  ; 计算余数所映射的 ASCII 码
          mov es:[bx+di],cl           ; char
          mov byte ptr es:[bx+di+1],2 ; color
          jmp short dd_ret

  dd_ret: pop di
          pop cx
          ret
; }

codesg ends
;-----------------------------------------------------------------------------------------

end start