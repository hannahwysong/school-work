.ORIG x3000 
AND R4, R4, #0 ; R4 = 0
AND R2, R2, #0 ; R2 = 0
AND R3, R3, #0 ; R3 = 0

LD R0, MAXITERATIONS ; R0 = MAXITERATIONS
ADD R2, R2, R0 ; R2 = MAXITERATIONS 
NOT R2, R2 ; Ones Complement
ADD R2, R2, #1 ; Two's Complement

FORLOOP
    ADD R3, R3, #5 ; R3 = R3 + 5
    ADD R4, R4, #1 ; R4 = R4 + 1
    ADD R2, R2, #1 ; R2 = (-MAXITERATIONS) + 1
    BRz LOOPDONE 
BRnzp FORLOOP 

LOOPDONE
STI R3, RESULT 
HALT 
MAXITERATIONS .FILL #10 
RESULT .Fill x8002 
.END 