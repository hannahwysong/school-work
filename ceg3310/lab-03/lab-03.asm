.ORIG x3000
START
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
LEA R0, PROMPT1		; Load the first number prompt and display to the user
PUTS

JSR GETNUM
ST R0, NUM1

LD R0, NEWLINE
OUT

LEA R0, PROMPT2		; Load the operation prompt and display to the user
PUTS

JSR GETOP

LD R0, NEWLINE
OUT

LEA R0, PROMPT3		; Load the second number prompt and display to the user
PUTS

JSR GETNUM
ST R0, NUM2

LD R0, NEWLINE
OUT

LD R0, NUM1
LD R1, NUM2
LD R2, OP
JSR CALC
ST R0, RESULT 

LEA R0, PROMPT4		; Load the results prompt and display to the user
PUTS

LD R0, RESULT
JSR DISPLAY

LD R0, NEWLINE
OUT

BR START
HALT
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PROMPT1 .STRINGZ "Enter first number (00 - 99): "
PROMPT2 .STRINGZ "Enter an operation (+, -, *): "
PROMPT3 .STRINGZ "Enter second number (00 - 99): "
PROMPT4 .STRINGZ "Result: "
NEWLINE .FILL x000A

NUM1 .BLKW #1
NUM2 .BLKW #1
RESULT .BLKW #1
OP .BLKW #1
STRING .BLKW #4
OPADD .FILL #43
OPSUB .FILL #45
OPMULT .FILL #42

ASCII_SUB .FILL #-48
ASCII_ADD .FILL #48
ASCII_ZERO .FILL x0030

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Input: none
; Output: R0 = number
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
GETNUM
; callee saves
ST R7, GETNUM_R7

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
LD R7, GETNUM_R7
RET
GETNUM_R7 .BLKW #1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Input: none
; Output: R0 = OP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
GETOP
; callee saves
ST R7, GETOP_R7

LD R3, ASCII_SUB

GETC
OUT
ST R0, OP ; stores OP 

; callee loads
LD R7, GETOP_R7
RET
GETOP_R7 .FILL #0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Input: R0 = NUM1, R1 = NUM2, R2 = OP
; Output: R0 = RESULT
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CALC
; calle saves
ST R7, CALC_R7

LD R2, OP ; loads OP into R2
NOT R2, R2 ; ones 
ADD R2, R2, #1 ; twos

; Addition
LD R3, OPADD
ADD R4, R3, R2
BRz CALCADD

; Subtraction
LD R3, OPSUB
ADD R4, R3, R2
BRz CALCSUB

; Multiplication
LD R3, OPMULT
ADD R4, R3, R2
BRz CALCMULT

CALCADD
    ADD R0, R0, R1
BR CALCDONE

CALCSUB
    NOT R1, R1
    ADD R1, R1, #1
    ADD R0, R0, R1
BR CALCDONE

CALCMULT
    JSR MULTIPLY
BR CALCDONE

CALCDONE
; callee loads
LD R7, CALC_R7
RET
CALC_R7 .FILL #0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Input: R0 = NUM1, R1 = NUM2
; Output: R0 = RESULT
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
MULTIPLY
; callee saves
ST R7, MULTI_R7
LD R2, NUM1
ADD R1, R1, #-1 ; decrease NUM2 for Loop
BRn NEGATIVE
BRz ZERO 
MULTI_LOOP
    ADD R0, R0, R2 ; increase
    ADD R1, R1, #-1 ; decrease NUM2 
    BRp MULTI_LOOP
LD R7, MULTI_R7
RET

ZERO 
LD R0, NUM1
LD R7, MULTI_R7
RET 

NEGATIVE
AND R0, R0, #0
LD R7, MULTI_R7
RET
; callee loads
MULTI_R7 .FILL #0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Input: R0 = number to display
; Output: none
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
DISPLAY
ST R7, DIS_R7
ST R0, DIS_R0 ; stores result 

ADD R0, R0, #0 ; check if result is neg or pos
BRzp SKIP_NEG_RESULT 
LD R0, NEG_SYMBOL ; loads - into R0
OUT ; prints R0 to console
LD R0, DIS_R0 ; reloads result
NOT R0, R0 
ADD R0, R0, #1 ; twos
SKIP_NEG_RESULT
AND R3, R3, #0 

LD R1, NEG_1000 ; R1 holds -1000
AND R2, R2, #0
LOOP_1000
    ADD R2, R2, #1 ; adds one to count
    ADD R0, R0, R1 ; subtract 1000
Brzp LOOP_1000 ; loops until 0 or neg

; subtract 1 from R2 to account for off for 1 errors
ADD R2, R2, #-1
NOT R1, R1
ADD R1, R1, #1 ; twos 
ADD R0, R1, R0 ; add 1000 back to result to restore result

ST R0, NUM_RESULT 
ADD R2, R2, #0
BRz SKIP_1000
LD R0, NUM_TO_ASCII
ADD R0, R0, R2
ADD R3, R3, #1 ; R3 should be 1 if there is a thousands digit
OUT ; print thousands digit

SKIP_1000
LD R0, NUM_RESULT
LD R1, NEG_100
AND R2, R2, #0
LOOP_100 
    ADD R2, R2, #1
    ADD R0, R0, R1
BRzp LOOP_100

ADD R2, R2, #-1 
NOT R1, R1
ADD R1, R1, #1
ADD R0, R1, R0

ST R0, NUM_RESULT 
ADD R2, R2, #0
BRnp SKIP_100CHECK_R3
ADD R3, R3, #0 
BRz SKIP_100
SKIP_100CHECK_R3
LD R0, NUM_TO_ASCII
ADD R0, R0, R2
ADD R3, R3, #1
OUT ; print hundreds digit 

SKIP_100
LD R0, NUM_RESULT
LD R1, NEG_10
AND R2, R2, #0
LOOP_10 
    ADD R2, R2, #1
    ADD R0, R0, R1
BRzp LOOP_10

ADD R2, R2, #-1 
NOT R1, R1 
ADD R1, R1, #1
ADD R0, R1, R0

ST R0, NUM_RESULT 
ADD R2, R2, #0
BRnp SKIP_10CHECK_R3
ADD R3, R3, #0 
BRz SKIP_10
SKIP_10CHECK_R3
LD R0, NUM_TO_ASCII
ADD R0, R0, R2
ADD R3, R3, #1
OUT ; print tens digit

SKIP_10
LD R0, NUM_RESULT
LD R1, NEG_1
AND R2, R2, #0
LOOP_1 
    ADD R2, R2, #1
    ADD R0, R0, R1
BRzp LOOP_1

ADD R2, R2, #-1 
NOT R1, R1
ADD R1, R1, #1
ADD R0, R1, R0

ST R0, NUM_RESULT 
ADD R2, R2, #0
BRnp SKIP_CHECK_R3
ADD R3, R3, #0 
BRz SKIP_100
SKIP_CHECK_R3
LD R0, NUM_TO_ASCII
ADD R0, R0, R2
ADD R3, R3, #1
OUT ; print ones digit 


LD R7, DIS_R7
RET
DIS_R7 .FILL #0 
DIS_R0 .FILL #0

NEG_1000 .FILL #-1000
NEG_100 .FILL #-100 
NEG_10 .FILL #-10 
NEG_1 .FILL #-1
NUM_TO_ASCII .FILL x30 
NEG_SYMBOL .FILL x2D
NUM_RESULT .BLKW #1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.END
