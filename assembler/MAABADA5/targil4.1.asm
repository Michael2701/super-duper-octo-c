
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
              
              
mov ax, 1111h
mov bx, 8000h
   
cmp ax, bx
jl LL1
mov dx, 1
jmp SOF

LL1: 
    MOV dx, 0
SOF:        

ret




