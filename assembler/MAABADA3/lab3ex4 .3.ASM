dseg segment
	  
dseg ends

sseg segment stack
        dw 100h dup(?)
sseg ends

cseg segment
assume  ds:dseg,cs:cseg,ss:sseg
start:  mov ax,dseg
        mov ds,ax

		mov ch, 2
		L1:
		mov ah, 40H
		dec ch
		jnz L1
		
		mov dx, 20h
		mov dx, dx
		
		mov ax, dx 
		mov ax, ax 
		
        mov ah,4ch
        int 21h
cseg ends
end start

