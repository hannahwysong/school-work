.ORIG x4000
TRAP_INPUT
; callee saves
ST R1, INPUT_R1
ST R2, INPUT_R2
ST R3, INPUT_R3
ST R4, INPUT_R4
ST R7, INPUT_R7

AND R0, R0, #0
LD R3, ASCII_SUB

GETC 
OUT
ADD R0, R0, R3 ; convert ascii to int
ADD R1, R0, #0 ; store first digit

GETC
OUT

ADD R2, R0, R3 ; convert from ascii to int
AND R3, R3, #0 ; clear R3
AND R4, R4, #0 ; clear R4
ADD R3, R3, #9 ; multiply NUM1 by 10

ADD R4, R1, #0 ; value for loop 
LOOP 
ADD R1, R1, R4 ; stores R1 + R4 in R1
ADD R3, R3, #-1 ; decreases loop 
BRp LOOP

ADD R0, R1, R2 ; combine digit 
; callee loads
LD R1, INPUT_R1
LD R2, INPUT_R2
LD R3, INPUT_R3
LD R4, INPUT_R4
LD R7, INPUT_R7
RET
INPUT_R1 .BLKW #1
INPUT_R2 .BLKW #1
INPUT_R3 .BLKW #1
INPUT_R4 .BLKW #1
INPUT_R7 .BLKW #1
ASCII_SUB .FILL #-48
.END