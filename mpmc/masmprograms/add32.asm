	
assume cs:code,ds:data
data segment
     str1 db 0ah, "Enter the first number: $"
     str2 db 0ah, "Enter the second number: $"
     str3 db 0ah, "Result= $"
     num1 db 08 dup(?)
     num2 db 08 dup(?)
     num3 db 08 dup(9)

data ends

code segment
		
	start:	mov ax,data
			mov ds,ax
			
			
			;displaying str1
			mov ah,09h
			lea dx,str1
			int 21h
			
			;reading num1 8 digits
			mov cl,08h
			lea si,num1	
	readnum1:  mov ah,01h
	  		int 21h
	  		mov [si],al
	  		inc si
	  		loop readnum1
	  		dec si
	  		
	  		;displaying str2
	  		lea dx,str2
	  		mov ah,09h
	  		int 21h
	  		
	  		;reading num2 8 digits
	  		lea di,num2
	  		mov cl,08h
	readnum2:  mov ah,01h
	   		int 21h
	   		mov [di],al
	   		inc di
	   		loop readnum2
	   		dec di

;adding the numbers   		
	   		mov cl,08h
	   		clc
	adding:  mov bh,[si]
	 		mov bl,[di]
	 		adc bh,bl
	 		mov al,bh
	 		mov ah,00h
	 		aaa
	 		mov [si],al
	 		dec si
	 		dec di
	 		loop adding
	 		
	 		;displaying str3
	 		lea dx,str3
	 		mov ah,09h
	 		int 21h
	 		
	 		jnc next
	 		
	        mov dl,31h
	        mov ah,02h
	        int 21h
	 		
	next:  lea si,num1
           mov cl,08h
	display:  mov ah,02h
		    mov dl,[si]
		    add dl,30h
		    int 21h
		    inc si 			
            loop display
            mov ah,4ch
            int 21h
 code ends
 end start
	

Output

	
Enter the first number: 98461324
Enter the second number: 23456534
Result= 121917858
	
