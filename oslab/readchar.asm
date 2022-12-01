assume cs:code,ds:code
data segment
msg1 db 0dh,0ah,"Enter the Character : $"
msg2 db 0dh,0ah," Enter character is : $"
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
lea dx,msg2
mov ah,09h
int 21h
mov dl,bl
mov ah,02h
int 21h
mov ah,4ch
int 21h
code ends
end start
