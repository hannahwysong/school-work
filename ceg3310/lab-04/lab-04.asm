;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.ORIG x3000
;	Your main() function starts here
LD R6, STACK_PTR			;	LOAD the pointer to the bottom of the stack in R6	(R6 = x6000)
LEA R4, GLOBAL_VARS			;	MAKE your global var pointer R4 point to globals	(R4 = ADDRESS(GLOBAL_VARS))


ADD R6, R6, #-1				; mains return address = x5FFF	
STR R7, R6, #0 				

ADD R6, R6, #-1 			; previous frame pointe	= x5FFE	
STR R5, R6, #0
ADD R5, R6, #0				

ADD R6, R6, #-1				
LEA R0, ARRAY_POINTER 			; *array = 5FFD
STR R0, R6, #0

ADD R6, R6, #-1 			 ; initalize total to 0 = x5FFC
AND R0, R0, #0
STR R0, R6, #0

ADD R6, R6, #-1				; sum of squares array = x5FFB
LEA R0, ARRAY_POINTER
STR R0, R6, #0

ADD R6, R6, #-1				; array size = x5FFA
LDR R0, R4, #0
STR R0, R6, #0

ADD R6, R6, #-1				; sum of squares return value = x5FF9

JSR SUMOFSQUARES			;	CALL sumOfSquares() function

LDR R0, R6, #0 				; load return value
STR R0, R5, #-2				; total = sum of squares return value

ADD R6, R6, #-1 			; pop sum of squares return value
ADD R6, R6, #1				; pop array size
ADD R6, R6, #1				; pop a[]

; printf 

LDR R0, R5, #-2				; R0 = total
STR R0, R5, #2				; mains return value = total

ADD R6, R6, #1				; pop total 
ADD R6, R6, #1				; pop *array

LDR R5, R6, #0				; restore previous frame pointer
ADD R6, R6, #1

LDR R7, R6, #0				; restore prev return address
ADD R6, R6, #1

HALT

GLOBAL_VARS					;	Your global variables start here
MAX_ARRAY_SIZE	.FILL x0005	;	MAX_ARRAY_SIZE is a global variable and predefined
ARRAY_POINTER	.FILL x0002	;	ARRAY_POINTER points to the top of your array (5 elements)
				.FILL x0003
				.FILL x0005
				.FILL x0000
				.FILL x0001
STACK_PTR		.FILL x6000	;	STACK_PTR is a pointer to the bottom of the stack (x6000)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SUMOFSQUARES
;	Your sumOfSquares() function starts here
ADD R6, R6, #-1 			; push return address = x5FF8
STR R7, R6, #0

ADD R6, R6, #-1				; push previous frame pointer = x5FF7
STR R5, R6, #0
ADD R5, R6, #0 

ADD R6, R6, #-1
STR R0, R6, #0				; push R0 = x5FF6

ADD R6, R6, #-1 
STR R1, R6, #0				; push R1 = x5FF5

ADD R6, R6, #-1 
STR R2, R6, #0 				; push R2 = x5FF4

ADD R6, R6, #-1 
STR R3, R6, #0				; push R3 = x5FF3

ADD R6, R6, #-1
AND R0, R0, #0 
STR R0, R6, #0				; push counter = x5FF2

ADD R6, R6, #-1 		
STR R0, R6, #0				; push sum = x5FF1

;logic
LDR R0, R5, #4 				; R0 = a[] 
LDR R1, R5, #3				; R1 = array size
NOT R1, R1
ADD R1, R1, #1 				; twos 
	
SUM_LOOP
	ADD R6, R6, #-1 		; push x = x5FF0
	LDR R2, R0, #0			; a[counter]
	STR R2, R6, #0          ; x = a[counter]
	ADD R6, R6, #-1 		; push square return value
	
	JSR SQUARE
	
	LDR R2, R6, #2 			; R2 = sum 
	LDR R3, R6, #0 			; R3 = sim of squares return value
	ADD R2, R2, R3
	STR R2, R6, #2			
	
	ADD R6, R6, #1 			; pop squares return value
	ADD R6, R6, #1 			; pop x 
	ADD R0, R0, #1			; next array item 
	ADD R1, R1, #1
BRnp SUM_LOOP
; end logic 

LDR R0, R6, #0 				; load sum into R0
STR R0, R5, #2 				; sum of squares return value 

ADD R6, R6, #1				; pop sum
ADD R6, R6, #1				; pop counter 

LDR R3, R6, #0
ADD R6, R6, #1 				; pop R3

LDR R2, R6, #0
ADD R6, R6, #1 				; pop R2

LDR R1, R6, #0
ADD R6, R6, #1 				; pop R1

LDR R0, R6, #0
ADD R6, R6, #1 				; pop R0

LDR R5, R6, #0				; restore prev frame pointer 
ADD R6, R6, #1				

LDR R7, R6, #0				; restore prev return address 
ADD R6, R6, #1 				
RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SQUARE
ADD R6, R6, #-1 
STR R7, R6, #0 				; push return address = x5FEE

ADD R6, R6, #-1 			; push previous frame pointer = x5FED
STR R5, R6, #0				; prev frame pointer
ADD R5, R6, #0				; new frame pointer 

ADD R6, R6, #-1
STR R0, R6, #0				; store R0 = x5FEC

ADD R6, R6, #-1 
STR R1, R6, #0				; store R1 = x5FEB

ADD R6, R6, #-1 
STR R2, R6, #0 				; store R2 = x5FEA

;logic 
ADD R6, R6, #-1 			; push product = x5FE9
AND R0, R0, #0
STR R0, R6, #0 				; product = 0

LDR R0, R5, #3 				; R0 = int x
ADD R1, R0, #0

AND R2, R2, #0
SQR_LOOP
	ADD R2, R2, R0 			; R2 += R0
	ADD R1, R1, #-1 
BRnp SQR_LOOP
STR R2, R6, #0 				; product = R2

LDR R0, R6, #0
STR R0, R5, #2				; return value = product
ADD R6, R6, #1				; pop product
;logic end

LDR R2, R6, #0
ADD R6, R6, #1 				; pop R2

LDR R1, R6, #0
ADD R6, R6, #1 				; pop R1

LDR R0, R6, #0
ADD R6, R6, #1 				; pop R0

LDR R5, R6, #0				; restore prev frame pointer 
ADD R6, R6, #1				

LDR R7, R6, #0				; restore prev return address 
ADD R6, R6, #1 	
RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.END
