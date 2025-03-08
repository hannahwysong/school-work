.ORIG x3000

LD R5, ARRAY_SIZE ; load array side into R3
LEA R1, ARRAY ; load array into R1


FORLOOP 
BRz ENDLOOP
    LEA R0 PROMPT ; load address of prompt
    PUTS ; echos prompt 

    GETC ; get character from user
    OUT ; echo character to user

    LD R0, NEWLINE
    OUT

    LD R4, ASCII_ZERO ; load x0030 into R4
    NOT R4, R4 ; ones complement
    ADD R4, R4, #1 ; twos complement
    ADD R3, R0, R4 ; Add R0 and R4

    STR R3, R1, #0 ; store R1 in R3

    ADD R1, R1, #1 ; 
    ADD R5, R5, #-1 ; decrease loop
    BRnzp FORLOOP
ENDLOOP

HALT
PROMPT .STRINGZ "Enter a numnber between 0 - 9: "
ARRAY .BlKW #5 ; array
ARRAY_SIZE .FILL #5 ; array size
NEWLINE .FILL x000A ; newline
ASCII_ZERO .FILL x0030 ; 
.END