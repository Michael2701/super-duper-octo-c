
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax, 8080h
mov bx, 1000h
mov cx, 2000h
mov dx, 3h
mov si, 0ffffh
mov di, 0h

;mov ah, 0h
;sub cx, dx
;dec bl
add si, 1h
;xchg al, dl

ret




