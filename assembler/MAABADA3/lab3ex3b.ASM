dseg segment
	  
dseg ends

sseg segment stack
        dw 100h dup(?)
sseg ends

cseg segment
assume  ds:dseg,cs:cseg,ss:sseg
start:  mov ax,dseg
        mov ds,ax

		mov ch, 3
		mov ax , 8
		L1:
		add ax, 2
		dec ch
		jnz L1
		
        mov ah,4ch
        int 21h
cseg ends
end start

