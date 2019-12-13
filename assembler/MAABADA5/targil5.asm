
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
              
              
mov dl, -9h
mov cl, -6h         

LL1:
    inc cl  
    cmp cl, 0
    jl LL1
LL2:
    inc dl
    cmp dl, 0
    jl   LL2

SOF:        

ret




