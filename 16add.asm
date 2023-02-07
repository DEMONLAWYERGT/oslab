assume cs:code,ds:data
data segment
x dw 123h
y dw 3456h
r dw 0h
rz db 0h
data ends
code segment
start: mov ax,data
mov ds,ax
mov bx,y
add ax,bx
mov r,ax
mov bl,0
jnc l1
mov bl,1
l1: mov rz,bl
int 21h
code ends
end start
