dseg segment
	  
dseg ends

sseg segment stack
        dw 100h dup(?)
sseg ends

cseg segment
assume  ds:dseg,cs:cseg,ss:sseg
start:  mov ax,dseg
        mov ds,ax
		MOV AX , 125
		XCHG  AL,BL
		MOV	AH , AH
		MOV	CL , 0A2h
		MOV	CH , CH
		MOV	BX , CX
		ADD BX,AX
		INC BH	
        mov ah,4ch
        int 21h
cseg ends
end start

