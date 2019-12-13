
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AL, 0FH
MOV BL, 0F0H
MOV CL, 0ACH
ADD AL, BL
INC AL
DEC AL
SUB BL, AL
ADD CL, 59H
CMP AL, CL


ret




