
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h


MOV AX, 11
ADD AX, 0FFEFh
SUB AX, 2
MOV AH, 1
MOV AL, 07fh
ADD AH,  AL
CMP AH, 128

ret




