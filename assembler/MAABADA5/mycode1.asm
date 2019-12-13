
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov al, 7
mov cx, 8  
LL:

inc al
dec cx
jnz LL
cmp al, 0
jl CON
mov dx , 0
CON:


ret




