assume cs:code,ds:data
data segment
   msg1 db 0dh,0ah, "Enter a character: $"
   msg2 db 0dh,0ah, "Entered character is : $"
   msg3 db 0dh,0ah, "ASCII code : $"
   asc1 db ?
   asc2 db ?
data ends
code segment
start:
      mov ax,data
      mov ds,ax
      
      lea dx,msg1
      mov ah,09h
      int 21h
      
      mov ah,01h
      int 21h
      mov bl,al
      and al,0fh
      or al,30h
      mov asc1,al
      mov al,bl
      mov cx,0004h
      shr al,cl
      and al,0fh
      or al,30h
      mov asc2,al
      lea dx,msg2
      mov ah,09h
      int 21h 
      mov dl,bl
      mov ah,02h
      int 21h 
      lea dx,msg3
      mov ah,09h
      int 21h
      mov dl,asc2
      mov ah,02h
      int 21h
      mov dl,asc1
      mov ah,02h
      int 21h 
      mov ah,4ch
      int 21h
      code ends
      end start
      
