dseg segment
	  
dseg ends

sseg segment stack
        dw 100h dup(?)
sseg ends

cseg segment
assume  ds:dseg,cs:cseg,ss:sseg
start:  mov ax,dseg
        mov ds,ax

		mov ch, 4
		mov ax , 0
		L1:
		add ax, 5
		dec ch
		jnz L1
		
        mov ah,4ch
        int 21h
cseg ends
end start

