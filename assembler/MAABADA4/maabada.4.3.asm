
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AX,10FFH
ADD  AL,1
MOV  BH,0BH
MOV  BL,0A4H
ADD  AX,0FFH
ADD  AX,2
ADD  BL,AH   
XCHG  AX,BX 
ADD  AH,1
ADD  BX,7000H   
ADD  BH,BL
ADD  BH,0AH
MOV  BL,0FEH
ADD  BX,2  
MOV AH,BH
ADD AH,1
ADD  AX,BX

ret




