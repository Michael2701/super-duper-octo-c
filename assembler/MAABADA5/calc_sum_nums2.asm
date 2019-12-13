
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax, 0
mov cx, 5  
LL:

add ax, cx
dec cx
jnz LL
cmp cx, 0
jl CON
mov dx , 0
CON:


ret




