
MOV AX, 0
MOV BX, 0
MACRO ADD_VALUES
 ADD AX, #1
 ADD BX, #2
MEND
ADD_VALUES
ADD_VALUES
MOV CX, AX
MOV DX, BX
