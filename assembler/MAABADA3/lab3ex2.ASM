dseg segment
	  
dseg ends

sseg segment stack
        dw 100h dup(?)
sseg ends

cseg segment
assume  ds:dseg,cs:cseg,ss:sseg
start:  mov ax,dseg
        mov ds,ax
		
		MOV  AX,0
		MOV  DX,5
		ADD  AX,DX
		ADD  AX,DX
		ADD  AX,DX
		ADD  AX,DX

        mov ah,4ch
        int 21h
cseg ends
end start

