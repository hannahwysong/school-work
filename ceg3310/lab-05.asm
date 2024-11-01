
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.ORIG x3000
;    Your main() function starts here
LD R6, STACK_PTR            				; LOAD the pointer to the bottom of the stack in R6    (R6 = x6000)
LEA R4, GLOBAL_VARS            				; MAKE your global var pointer R4 point to globals    (R4 = ADDRESS(GLOBAL_VARS))

ADD R6, R6, #-1
STR R7, R6, #0						; push return address #5FFF

ADD R6, R6, #-1
STR R5, R6, #0						; push prev frame pointer #5FFE
ADD R5, R6, #0						; set frame pointer 

ADD R6, R6, #-1 					; #5FFD
AND R0, R0, #0 
STR R0, R6, #0						; push int n=0
ADD R6, R6, #-1						; #5FFC
ADD R0, R6, #0 						; push int result=0

ADD R0, R4, #0 
ADD R0, R0, #4						; loads prompt1 into R0
PUTS							; print prompt1 

AND R0, R0, #0
ADD R0, R4, #2 						; load neg ascii into R0
LDR R0, R0, #0 

ADD R6, R6, #-1 					; #5FFB push getnum return address

JSR GETNUM 

LDR R0, R6, #0
STR R0, R5, #-1 					; store getnum() into n

ADD R6, R6, #-1 					; pop getnum return value

ADD R6, R6, #-1
STR R0, R5, #-1 
STR R0, R6, #0 						; push factorials return address

ADD R6, R6, #-1

JSR FIBONACCI 

LDR R0, R6, #0
STR R0, R5, #2 						; store fibonacci into result

ADD R6, R6, #1 						; pop result
ADD R6, R6, #1 						; pop return value

ADD R0, R4, #15
ADD R0, R0, #15
ADD R0, R0, #13
PUTS							; print first part of response


HALT

GLOBAL_VARS                    		; Your global variables start here 
ASCII_OFFSET    .FILL x0030         ; MAX_ARRAY_SIZE is a global variable and predefined
STACK_PTR    .FILL x6000            ; STACK_PTR is a pointer to the bottom of the stack (x6000)
NEG_ASCII .FILL #-48 				; 0
ASCII .FILL x30 					; 1
PROMPT1 .STRINGZ "Please enter a number n: "	; 2
RESULT1 .STRINGZ "\nF(" 			; 28
RESULT2 .STRINGZ ") = "				; 32
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

FIBONACCI
;    Your fibonacci() function starts here
RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

GETNUM
;    Your getnum() function starts here
ADD R6, R6, #-1			; push previous return address x5FFA
STR R7, R6, #0

ADD R6, R6, #-1			;push previous frame pointer x5FF9
STR R5, R6, #0
ADD R5, R6, #0			; set frame pointer

ADD R6, R6, #-1 		; push input onto stack x5FF8

ADD R6, R6, #-1 
STR R0, R6, #0			; save R0 x5FF7

ADD R6, R6, #-1
STR R1, R6, #0 			; save R1

;; logic
AND R0, R0, #0 			; set R0 to zero
GETC
OUT 

LDR R1, R5, #-2			; load ascii offset into R1
ADD R0, R0, R1 			; convert to ascii to int

;; logic end 

STR R0, R5, #1			; store R0 in int input

LDR R1, R6, #0
ADD R6, R6, #1 			; pop R1

LDR R0, R6, #0
ADD R6, R6, #1 			; pop R0

LDR R5, R6, #0			; restore prev frame pointer 
ADD R6, R6, #1				

LDR R7, R6, #0			; restore prev return address 
ADD R6, R6, #1 	
RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

DISPLAY
;    Your display() function starts here
RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.END
