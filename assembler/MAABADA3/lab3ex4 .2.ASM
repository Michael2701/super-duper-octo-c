dseg segment
	  
dseg ends

sseg segment stack
        dw 100h dup(?)
sseg ends

cseg segment
assume  ds:dseg,cs:cseg,ss:sseg
start:  mov ax,dseg
        mov ds,ax

		mov ah, 25H
		mov ah, 1000H
		dec ah
		
        mov ah,4ch
        int 21h
cseg ends
end start

