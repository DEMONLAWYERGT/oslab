ASSUME CS:CODE, DS:DATA
DATA SEGMENT
LIST DW 2357H,0a57H,0c23H,0c91H,0c00H,0957H
COUNT EQU 006h
DATA ENDS
CODE SEGMENT
START: XOR BX,BX
XOR DX,DX
MOV AX,DATA
MOV DS,AX
MOV CL,COUNT
MOV SI, OFFSET LIST
AGAIN: MOV AX,[SI]
RCR AX,0001
JC ODD
INC BX
JMP NEXT
ODD: INC DX
NEXT: ADD SI,0002
DEC CL
JNZ AGAIN
MOV AH,4CH
INT 21H
CODE ENDS
END START